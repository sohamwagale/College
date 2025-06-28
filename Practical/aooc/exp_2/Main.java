//import java.util.Scanner;


public class Main    {

    public class Employee{

        String first;
        String last;
        double sal;

        Employee(String fname,String lname, double salary){
            this.first = fname;
            this.last = lname;
            this.sal = salary;
        }

        public void getName(){
            System.out.println(first);
            System.out.println(last);
        }
        public void getSalary(){
            System.out.println(sal);
        }

        public void setName(String fn,String ln){
            this.first = fn;
            this.last = ln;
            getName();
        }

        public void setSalary(double pagar){
            if(pagar<0){
                pagar = 0;
            }
            this.sal = pagar;
            getSalary();
        }

        public void increment(double inc){
            this.sal = this.sal*(1+(inc/100));
            getSalary();
        }

    }

    public class TestEmployee {
        public static void main(String[] args) {
            Main    outer = new Main();
            Employee em1 = outer.new Employee ("Soham" ,"Wagale", 2100000);
            Employee em2 = outer.new Employee("Om", "Joahi", 100);
            em1.getName();
            em1.getSalary();
            em2.getName();
            em2.getSalary();
            em2.setName("Gnandar", "Kamble");
            em2.increment(20);
        }
    }

    public static void main(String[] args) {
        TestEmployee.main(args);
    }

}

