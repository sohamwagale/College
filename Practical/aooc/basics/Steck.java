import java.util.Scanner;
public class Steck{
    int size;
    int top =-1;
    int stk[];
    Steck(int size){
        this.size = size;
        this.stk = new int[size];
    }
    void push(int elem){
        if(top == size-1){
            System.out.println("The Stack is Full!!");
        }
        else{
            top++;
            stk[top]= elem;
        }    
    }
    int pop(){
        if(top!=-1)
            return stk[top--];
        else{
            System.out.println("Error...Stack is Empty");
            return -1;
        }
    }
    boolean isEmpty(){
        return (top==-1);
    }
    boolean isFull(){
        return (top==size-1);
    }
    int top(){
        if(top!=-1){
            return stk[top];
        }
        else{
            System.out.println("Stack is empty");
            return -1;
        }
    }
    void display_all(){
        for(int i=top;i>=0;i--){
            System.out.print(stk[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scen = new Scanner(System.in);
        int size;
        System.out.println("Enter Size of the Stack : ");
        size = scen.nextInt();
        Steck stck = new Steck(size);

        
        while (true) {
            System.out.println("\nChoose an operation:");
            System.out.println("1. Push");
            System.out.println("2. Pop");
            System.out.println("3. Display");
            System.out.println("4. Top");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            
            int choice = scen.nextInt();
    
            switch (choice) {
                case 1:
                    System.out.print("Enter value to push: ");
                    int val = scen.nextInt();
                    stck.push(val);
                    break;
                case 2:
                    stck.pop();
                    break;
                case 3:
                    stck.display_all();
                    break;
                case 4:
                    System.out.println("The topmost element is: "+stck.top());
                case 5:
                    System.out.println("Exiting...");
                    scen.close();
                    return;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}