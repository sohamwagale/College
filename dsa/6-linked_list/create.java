class Node{
    int data;
    Node next;

    Node(int data){
        this.data = data;
        this.next = null;
    }

    Node(int data, Node next){
        this.data = data;
        this.next = next;
    }
}

public class create {

    static Node Create (int[] arr){
        Node head = new Node(arr[0]);
        Node mover = head;
        for(int i= 1;i < arr.length;i++){
            Node temp = new Node(arr[i]);
            mover.next = temp;
            mover =temp;
        }
        return head;
    }

    static void traverse(Node head){
        Node header = head;
        Node trav = header;  
        while(trav != null){
            System.out.print(trav.data + " ");
            trav = trav.next;
        }
    }

    static int count(Node head){
        Node header = head;
        Node trav = header;
        int cnt =0;
        while(trav!=null){
            cnt++;
            trav = trav.next;
        }
        return cnt;
    }

    static boolean find(Node head,int elem){
        Node trav= head;
        while(trav.next!=null){
            if(trav.data == elem){
                return true;
            }
            trav = trav.next; 
        }
        return false;
    }

    public static void main(String[] args) {
        int[] arr = {5,6,7,8,9};
        Node head = Create(arr);
        System.out.println(head.data);   
        traverse(head);//Prints the elems
        System.out.println("\n"+count(head));
        System.out.println(find(head, 7));
    }
}
