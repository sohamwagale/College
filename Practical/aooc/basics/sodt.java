import java.util.Scanner;

public class sodt{
	public static void main(String [] args){
		int num =0;
		System.out.print("Enter a number : ");
		Scanner scen =new Scanner(System.in);
		num = scen.nextInt();
		int sum=0;
		for(int i = 1;i<=num;i++){
			sum+=i;
		}
		System.out.println(sum);
		scen.close();
	}
}
