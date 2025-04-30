import java.util.Scanner;

public class prime{
	public static void main(String [] args){
		int num=0;
		int cnt = 0;
		Scanner scen = new Scanner(System.in);
		System.out.print("Enter a number : ");
		num = scen.nextInt();
		if(num==1){
			System.out.println("Not odd nor even");
		}
		for(int i =2;i*i<=num;i++){
			if(num%i==0){
			       cnt++;
			}
	 	}
		if(cnt>0){
			System.out.println("Not prime");
		}
		else{
			System.out.println("Prime");
		}
		scen.close();
	}
}
