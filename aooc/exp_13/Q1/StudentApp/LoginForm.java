import java.awt.*;
import java.awt.event.*;
import java.sql.*;
import javax.swing.*;

public class LoginForm extends JFrame implements ActionListener {
    // GUI components
    JTextField txtUser;
    JPasswordField txtPass;
    JButton btnLogin, btnRegister;

    // DB credentials
    final String DB_URL = "jdbc:mysql://localhost:3306/login_db";
    final String DB_USER = "root";
    final String DB_PASS = "qwerty@12345"; // Replace with your MySQL password

    public LoginForm() {
        setTitle("Login Form");
        setSize(300, 200);
        setLayout(new GridLayout(4, 2));
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        // Labels and Fields
        add(new JLabel("Username:"));
        txtUser = new JTextField();
        add(txtUser);

        add(new JLabel("Password:"));
        txtPass = new JPasswordField();
        add(txtPass);

        // Buttons
        btnLogin = new JButton("Login");
        btnRegister = new JButton("Register");

        add(btnLogin);
        add(btnRegister);

        btnLogin.addActionListener(this);
        btnRegister.addActionListener(this);

        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        String username = txtUser.getText();
        String password = new String(txtPass.getPassword());

        if (username.isEmpty() || password.isEmpty()) {
            JOptionPane.showMessageDialog(this, "Please fill all fields.");
            return;
        }

        try {
            // Connect to DB
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection conn = DriverManager.getConnection(DB_URL, DB_USER, DB_PASS);

            if (e.getSource() == btnRegister) {
                // Register user
                String sql = "INSERT INTO users (username, password) VALUES (?, ?)";
                PreparedStatement ps = conn.prepareStatement(sql);
                ps.setString(1, username);
                ps.setString(2, password);
                ps.executeUpdate();
                JOptionPane.showMessageDialog(this, "Registration successful!");
                ps.close();
            } else if (e.getSource() == btnLogin) {
                // Login
                String sql = "SELECT * FROM users WHERE username = ? AND password = ?";
                PreparedStatement ps = conn.prepareStatement(sql);
                ps.setString(1, username);
                ps.setString(2, password);
                ResultSet rs = ps.executeQuery();
                if (rs.next()) {
                    JOptionPane.showMessageDialog(this, "Login successful!");
                } else {
                    JOptionPane.showMessageDialog(this, "Invalid credentials!");
                }
                rs.close();
                ps.close();
            }
            conn.close();
        } catch (SQLIntegrityConstraintViolationException ex) {
            JOptionPane.showMessageDialog(this, "Username already exists!");
        } catch (Exception ex) {
            ex.printStackTrace();
            JOptionPane.showMessageDialog(this, "Error: " + ex.getMessage());
        }
    }

    public static void main(String[] args) {
        new LoginForm();
}
}