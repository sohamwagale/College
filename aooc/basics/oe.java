import java.util.Scanner;

public class oe {
	public static void main (String [] args){
		int n=0;
		Scanner scen = new Scanner(System.in);
		System.out.print("Enter a number : ");
		n = scen.nextInt();
		if(n%2 == 0){
			System.out.println("Even");
		}
		else{
			System.out.println("Odd");
		}
		scen.close();
	}
}

