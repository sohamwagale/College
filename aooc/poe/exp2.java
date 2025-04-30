class Employee {
    String name;
    int salary;
    Employee(String n){
        this.name = n;
    }

    public void setSal(int sal){
        if(sal>0){
            this.salary = sal;
        }
        else {
            this.salary = 0;
        }
    }

    public void getInfo(){
        System.out.println("Name : " + this.name + "\nSalary: " + this.salary);
    }
    
}

class Area {
    int l,b;

    void setDim(int len, int bre){
        this.l = len;
        this.b = bre;
    }

    int getArea(){
        return this.l * this.b;
    }
    
}

class StaticDemo {

    // Static variable
    static int count;

    // Static block - runs only once when the class is loaded
    static {
        count = 10;
        System.out.println("Static block executed. Initial count = " + count);
    }

    // Static method - can access static variables directly
    static void incrementCount() {
        count++;
        System.out.println("Static method called. Updated count = " + count);
    }

    void showCount() {
        System.out.println("Non-static method. Current count = " + ++count);
    }
}

class Node{
    int data;
    Node next;
    Node(int data, Node next){
        this.next = next;
        this.data = data;
    }
    Node(int data){
        this.data = data;
        this.next = null;
    }
}

class Steck{
    Node top = null;

    void push(int data){
        top = new Node(data, top);
    }

    int pop(){
        if(top == null){
            System.out.println("Empty!!");
            return -1;
        } 
        Node temp = top;
        top = top.next;
        return temp.data;
    }

    void display(){
        Node trav = top;
        while(trav != null){
            System.out.print(trav.data + " ");
            trav = trav.next;
        }
    }
}


public class exp2 {
    public static void main(String[] args) {
        /*Employee soham = new Employee("Soham");
        soham.setSal(500);
        soham.getInfo();

        Area rect = new Area();
        rect.setDim(5, 6);
        System.out.println("Area : "+rect.getArea());

        System.out.println("Main method starts.");

        // Calling static method without creating an object
        StaticDemo.incrementCount();

        // Creating objects
        StaticDemo obj1 = new StaticDemo();
        StaticDemo obj2 = new StaticDemo();

        // Using non-static method to access static variable
        obj1.showCount();
        obj2.showCount();

        // Incrementing count again
        StaticDemo.incrementCount();

        obj1.showCount(); */

        Steck st = new Steck();
        st.push(4);
        st.push(5);
        st.push(7);
        st.display();
        st.pop();
        st.pop();
        st.pop();
        st.display();
        st.pop();

    }
    
}
