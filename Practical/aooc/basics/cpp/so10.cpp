#include<iostream>
using namespace std;

int main(){
    int sum =0;
    int n = 10;
//    for(int i =1;i<=10;i++){
//        sum+=i;
//    }
    sum = (n*(n+1))/2;
    cout<<"The sum of digits from 1 to 10 is : "<<sum;
    return 0;
}