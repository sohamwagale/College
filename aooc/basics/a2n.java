import java.util.Scanner;

public class a2n{
	public static void main (String [] args){
		int x,y=0;
		Scanner scen =new Scanner(System.in);
		System.out.print("Enter 2 numbers : ");
		x = scen.nextInt();
		y = scen.nextInt();
		System.out.println("Addtion is = "+(x+y));
		scen.close();
	}
}

