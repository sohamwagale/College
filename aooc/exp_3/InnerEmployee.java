abstract class Employee {
    String name;
    String address;
    int Salary;
    String jobTitle;

    Employee(String name, String address, int Salary, String job){
        this.name = name;
        this.address = address;
        this.Salary = Salary;
        this.jobTitle = job;
        System.out.println("Employee created : " +name+" Address: "+address+" Salary: "+Salary+" Job:"+job );
    }

    void bonus(int amt){
        if(amt<0){
            System.out.println("Bonus must be positive!!");
            return;
        }
        Salary += amt;
        System.out.println("Bonus of " + amt + " added. The CurrentSalary is : " + Salary);
    };
    void per_rep(){
        System.out.println("Performance reoprt created.");
    };
    void managa_pro(){
        System.out.println("Project Managed");
    };
}

class Manager extends Employee{
    Manager(String name, String address, int Salary, String job){
        super(name,address,Salary,job);
    }
}
class Developer extends Employee{
    Developer(String name, String address, int Salary, String job){
        super(name,address,Salary,job);
    }

}
class Programmer extends Employee{
    Programmer(String name, String address, int Salary, String job){
        super(name,address,Salary,job);
    }
}

public class InnerEmployee {
    public static void main(String[] args) {
        Programmer p1 = new Programmer("Soham","Kolhapur",50000,"Programmer");
        p1.bonus(5000);
        Developer d1 = new Developer("Soham","Kolhapur",50000,"Developer");
        d1.per_rep();
        Manager m1 = new Manager("Soham","Kolhapur",50000,"Manager");
        m1.managa_pro();
    }
    
}