import java.util.Scanner;

public class Area {

    Scanner scen = new Scanner(System.in);
    int Length;
    int Breadth;

    public void setDim(){
        System.out.println("Enter the Length and Breadth of the Rectangle");
        Length = scen.nextInt();
        Breadth = scen.nextInt();
    }

    public void getArea(){
        System.out.println("Area of the rectangle is " + (Length*Breadth));
    }


    public static void main(String[] args) {
        Area r1 = new Area();
        r1.setDim();
        r1.getArea();
    }
}