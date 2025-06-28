import java.util.Scanner;

public class fac{
	public static int fact(int n){
		if(n<2){
			return n;
		}
		return n*fact(n-1);
	}


	public static void main (String [] args){
		int n =1;
		Scanner scan = new Scanner(System.in);
		System.out.print("Enter a number : ");
		n = scan.nextInt();
		System.out.println("The factorial is : " + fact(n));
		scan.close();
		}
	}


