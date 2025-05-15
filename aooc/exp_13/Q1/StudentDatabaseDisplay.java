import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class StudentDatabaseDisplay {
    public static void main(String[] args) {
        // MySQL connection parameters
        String url = "jdbc:mysql://localhost:3306/school"; // Replace 'school' with your DB name
        String user = "root"; // Replace with your MySQL username
        String password = "qwerty@12345"; // Replace with your MySQL password

        try {
            // Load JDBC driver (not always required in modern Java)
            Class.forName("com.mysql.cj.jdbc.Driver");

            // Establish connection
            Connection conn = DriverManager.getConnection(url, user, password);

            // Create statement and execute query
            Statement stmt = conn.createStatement();
            ResultSet rs = stmt.executeQuery("SELECT * FROM student");

            // Display result set
            System.out.println("ID\tName\t\tGrade");
            System.out.println("---------------------------------");
            while (rs.next()) {
                int id = rs.getInt("id");
                String name = rs.getString("name");
                String grade = rs.getString("grade");

                System.out.println(id + "\t" + name + "\t\t" + grade);
            }

            // Close connection
            rs.close();
            stmt.close();
            conn.close();

        } catch (ClassNotFoundException e) {
            System.out.println("JDBC Driver not found!");
            e.printStackTrace();
        } catch (SQLException e) {
            System.out.println("Database error!");
            e.printStackTrace();
        }
    }
}
