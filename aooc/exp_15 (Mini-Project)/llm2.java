import javax.swing.*;
import java.awt.*;
import java.io.*;
import java.net.URI;
import java.net.http.*;

public class llm2 extends JFrame {
    // API settings
    private static final String OLLAMA_API_URL = "http://localhost:11434/api/chat";
    private static final String MODEL_NAME = "llama3.2";
    
    // Colors
    private static final Color USER_COLOR = new Color(200, 220, 255);
    private static final Color BOT_COLOR = new Color(230, 230, 230);
    
    // UI components
    private JPanel chatPanel;
    private JScrollPane scrollPane;
    private JTextField inputField;
    private JButton sendButton;
    private JLabel statusLabel;
    private boolean busy = false;

    public llm2() {
        // Basic setup
        super("Ollama Chat");
        setSize(500, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout(5, 5));
        
        // Chat area
        chatPanel = new JPanel();
        chatPanel.setLayout(new BoxLayout(chatPanel, BoxLayout.Y_AXIS));
        chatPanel.setBackground(Color.WHITE);
        
        scrollPane = new JScrollPane(chatPanel);
        add(scrollPane, BorderLayout.CENTER);
        
        // Bottom panel
        JPanel bottomPanel = new JPanel(new BorderLayout());
        
        inputField = new JTextField();
        inputField.addActionListener(e -> sendMessage());
        
        sendButton = new JButton("Send");
        sendButton.addActionListener(e -> sendMessage());
        
        statusLabel = new JLabel(" ");
        statusLabel.setForeground(Color.GRAY);
        
        bottomPanel.add(statusLabel, BorderLayout.NORTH);
        bottomPanel.add(inputField, BorderLayout.CENTER);
        bottomPanel.add(sendButton, BorderLayout.EAST);
        
        add(bottomPanel, BorderLayout.SOUTH);
        
        // Welcome message
        addBotMessage("Hi! I'm a simple Ollama chatbot. What would you like to talk about?");
        
        // Show window
        setLocationRelativeTo(null);
        setVisible(true);
    }
    
    private void sendMessage() {
        String message = inputField.getText().trim();
        
        if (message.isEmpty()) {
            return;
        }
        
        if (busy) {
            JOptionPane.showMessageDialog(this, "Please wait...", "Busy", JOptionPane.INFORMATION_MESSAGE);
            return;
        }
        
        // Clear input field
        inputField.setText("");
        
        // Show user message
        addUserMessage(message);
        
        // Disable controls
        busy = true;
        sendButton.setEnabled(false);
        inputField.setEnabled(false);
        statusLabel.setText("Thinking...");
        
        // Call API in background
        new Thread(() -> {
            try {
                // Get response from API
                String response = callAPI(message);
                
                // Update UI
                SwingUtilities.invokeLater(() -> {
                    addBotMessage(response);
                    busy = false;
                    sendButton.setEnabled(true);
                    inputField.setEnabled(true);
                    statusLabel.setText(" ");
                    inputField.requestFocus();
                });
            } catch (Exception e) {
                SwingUtilities.invokeLater(() -> {
                    addBotMessage("Error: " + e.getMessage());
                    busy = false;
                    sendButton.setEnabled(true);
                    inputField.setEnabled(true);
                    statusLabel.setText("Error");
                });
            }
        }).start();
    }
    
    private void addUserMessage(String message) {
        // Create message bubble
        JPanel panel = new JPanel();
        panel.setLayout(new BorderLayout());
        panel.setMaximumSize(new Dimension(400, Integer.MAX_VALUE));
        
        // Message text
        JTextArea textArea = new JTextArea(message);
        textArea.setEditable(false);
        textArea.setLineWrap(true);
        textArea.setWrapStyleWord(true);
        textArea.setBackground(USER_COLOR);
        textArea.setBorder(BorderFactory.createEmptyBorder(8, 8, 8, 8));
        
        // Add to chat with right alignment
        panel.add(textArea);
        
        JPanel wrapper = new JPanel(new FlowLayout(FlowLayout.RIGHT));
        wrapper.setBackground(Color.WHITE);
        wrapper.add(panel);
        
        chatPanel.add(wrapper);
        scrollToBottom();
    }
    
    private void addBotMessage(String message) {
        // Create message bubble
        JPanel panel = new JPanel();
        panel.setLayout(new BorderLayout());
        panel.setMaximumSize(new Dimension(400, Integer.MAX_VALUE));
        
        // Message text
        JTextArea textArea = new JTextArea(message);
        textArea.setEditable(false);
        textArea.setLineWrap(true);
        textArea.setWrapStyleWord(true);
        textArea.setBackground(BOT_COLOR);
        textArea.setBorder(BorderFactory.createEmptyBorder(8, 8, 8, 8));
        
        // Add to chat with left alignment
        panel.add(textArea);
        
        JPanel wrapper = new JPanel(new FlowLayout(FlowLayout.LEFT));
        wrapper.setBackground(Color.WHITE);
        wrapper.add(panel);
        
        chatPanel.add(wrapper);
        scrollToBottom();
    }
    
    private void scrollToBottom() {
        chatPanel.revalidate();
        chatPanel.repaint();
        
        SwingUtilities.invokeLater(() -> {
            JScrollBar vertical = scrollPane.getVerticalScrollBar();
            vertical.setValue(vertical.getMaximum());
        });
    }
    
    private String callAPI(String userMessage) throws IOException, InterruptedException {
        StringBuilder response = new StringBuilder();
        
        // Create JSON request
        String json = "{" +
            "\"model\":\"" + MODEL_NAME + "\"," +
            "\"messages\":[{" +
            "\"role\":\"user\"," +
            "\"content\":\"" + escape(userMessage) + "\"" +
            "}]," +
            "\"stream\":true" +
            "}";
        
        // Create HTTP request
        HttpClient client = HttpClient.newHttpClient();
        HttpRequest request = HttpRequest.newBuilder()
            .uri(URI.create(OLLAMA_API_URL))
            .header("Content-Type", "application/json")
            .POST(HttpRequest.BodyPublishers.ofString(json))
            .build();
        
        // Send request
        HttpResponse<InputStream> httpResponse = client.send(
            request, HttpResponse.BodyHandlers.ofInputStream());
        
        // Check response code
        if (httpResponse.statusCode() != 200) {
            throw new IOException("API error: " + httpResponse.statusCode());
        }
        
        // Process streaming response
        try (BufferedReader reader = new BufferedReader(
                new InputStreamReader(httpResponse.body()))) {
            
            String line;
            while ((line = reader.readLine()) != null) {
                // Simple JSON parsing
                if (line.contains("\"content\"")) {
                    int start = line.indexOf("\"content\"");
                    int valueStart = line.indexOf(":", start) + 1;
                    int firstQuote = line.indexOf("\"", valueStart);
                    int lastQuote = line.indexOf("\"", firstQuote + 1);
                    
                    if (firstQuote >= 0 && lastQuote >= 0) {
                        String content = line.substring(firstQuote + 1, lastQuote);
                        // Fix escaping
                        content = content.replace("\\\"", "\"").replace("\\\\", "\\");
                        response.append(content);
                    }
                }
            }
        }
        
        return response.toString();
    }
    
    // Escape quotes and backslashes for JSON
    private String escape(String text) {
        return text.replace("\\", "\\\\").replace("\"", "\\\"").replace("\n", "\\n");
    }
    
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new SimplifiedOllamaChatBot());
    }
}