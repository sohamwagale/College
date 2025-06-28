import java.util.Scanner;

public class rev{
	public static void main(String [] args){
		int num = 0;
		Scanner scen = new Scanner(System.in);
		System.out.print("Enter a large number : ");
		num = scen.nextInt();
		int rem =0;
		int rev = 0;
		while(num>0){
			rem=num%10;
			num/=10;
			rev= rev*10 + rem;
		}
		System.out.println(rev);
		scen.close();
	}
}
		

