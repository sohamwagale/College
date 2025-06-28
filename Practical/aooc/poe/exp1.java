//import java.util.Scanner;

public class exp1 {

    public static int fact(int a){
        int fac = 1;
        while(a>0){
            fac*=a--;
        }
        return fac;
    }

    public static boolean prime(int a){
        for(int i =2;i<a;i++){
            if(a%i == 0){
                return false;
            }
        }
        return true;
    }

    public static int[] sort(int[] arr){
        for(int i = arr.length-1;i>0;i--){
            for(int j= 0; j<i;j++){
                if(arr[j]>arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.out.println();
        return arr;
    }

    public static int[] merge(int[] arr1,int[] arr2){
        int i = 0,j = 0;
        int[] mer = new int[arr1.length + arr2.length];
        while(i<arr1.length && j<arr2.length){
            if(arr1[i]<=arr2[j]){
                mer[i+j] = arr1[i];
                i++;
            }
            else{
                mer[i+j] = arr2[j];
                j++;
            }
        }

        while(i<arr1.length){
            mer[i+j] = arr1[i];
            i++;
        }

        while (j<arr2.length) {
            mer[i+j] = arr2[j];
            j++;
        }

        for (int k : mer) {
            System.out.print(k + " ");
        }

        return mer;
    }

    public static void main(String[] args) {
        System.out.println(fact(5));
        System.out.println(prime(72));
        int[] arr1 = {54,43,3,234,544,343,34,32,34,24};
        int[] sa1 = sort(arr1);
        int[] arr2  = {1234,543,3243,34,387,7,52};
        int[] sa2 = sort(arr2);
        merge(sa1,sa2);
    }
}