import java.sql.*;

public class StudentDatabaseDisplay {
    public static void main(String[] args) {
        // Database credentials and URL
        String url = "jdbc:mysql://localhost:3306/student_db"; // Replace 'school' with your DB name
        String user = "root"; // Replace with your DB username
        String password = "qwerty@12345"; // Replace with your DB password

        // JDBC objects
        Connection conn = null;
        Statement stmt = null;
        ResultSet rs = null;

        try {
            // Load JDBC driver
            Class.forName("com.mysql.cj.jdbc.Driver");

            // Connect to database
            conn = DriverManager.getConnection(url, user, password);

            // Create a statement
            stmt = conn.createStatement();

            // Execute query
            String sql = "SELECT * FROM student";
            rs = stmt.executeQuery(sql);

            // Print results
            System.out.println("ID\tName\tGrade");
            System.out.println("------------------------");
            while (rs.next()) {
                int id = rs.getInt("id");
                String name = rs.getString("name");
                String grade = rs.getString("grade");
                System.out.println(id + "\t" + name + "\t" + grade);
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            // Clean up resources
            try { if (rs != null) rs.close(); } catch (Exception e) {}
            try { if (stmt != null) stmt.close(); } catch (Exception e) {}
            try { if (conn != null) conn.close(); } catch (Exception e) {}
}
}
}