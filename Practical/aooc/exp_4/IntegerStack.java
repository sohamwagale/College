interface Stack{
    void pop();
    void push(int elem);
    int top();
    int size();
    boolean isEmpty();
    void display();
}

class Node{
    int data;
    Node next;

    Node(int data){
        this.data = data;
        this.next = null;
    }
}

public class IntegerStack implements Stack{
    Node head = null;
    int size = 0;
    public void push(int elem){
        Node temp = new Node(elem);
        temp.next = head;
        head = temp;
        ++size;
    }

    public void pop(){
        Node temp = head;
        head = head.next;
        temp = null;
        size--;
    }

    public int top(){
        return head.data;
    }

    public int size(){
        return size;
    }
    public boolean isEmpty(){
        if(head==null)
            return true;
        return false;
    }

    public void display(){
        Node trav = head;
        while(trav!= null){
            System.out.println(trav.data + " ");
            trav = trav.next;
        }
    }


    public static void main(String[] args) {
        IntegerStack s1 = new IntegerStack();
        s1.push(2);
        s1.push(3);
        s1.push(6);
        s1.push(4);
        System.out.println("Topmost Element is : "+ s1.top());
        System.out.println("PoppedElement is : " + s1.top());
        s1.pop();
        System.out.println("Topmost Element is : "+ s1.top());
        System.out.println("Total Size is :"+ s1.size());
        System.out.println("Displaying all the Elements : ");
        s1.display();
    }
}