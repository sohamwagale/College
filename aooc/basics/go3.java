import java.util.Scanner;

public class go3{
	public static void main(String [] args){
		int x,y,z=0;
		Scanner scen = new Scanner(System.in);
		System.out.print("Enter 3 Numbers: ");
		x=scen.nextInt();
		y=scen.nextInt();
		z=scen.nextInt();
		if(x>y && x>z){
			System.out.println("Largest is : " + x);
		}
		else if(y>z && y>x){
			System.out.println("Largest is : "+ y);
		}
		else{
			System.out.println("Largset is : "+z);
		}
		scen.close();
	}
}


