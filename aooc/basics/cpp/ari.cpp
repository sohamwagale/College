#include<iostream>
#include<math.h>
using namespace std;

int main(){
    char opr ;
    char brek = 'y';
    float a,b = 0;
   
   
    cout<<"Enter a : ";
    cin>>a;
    cout<<endl<<"Enter b : ";
    cin>>b;
    cout<<endl;


    do{ 
        cout<<"Enter the operator(+,-,/,*,%) : ";
        cin>>opr;
        cout<<endl;

        switch (opr){
            case '+':
                cout<<"The addition is : "<<a+b;
                break;

            case '-':
                cout<<"The diffrence is : "<<a-b;
                break;

            case '*':
                cout<<"The product is : "<<a*b;
                break;

            case '/':
                cout<<"The division is : "<<a/b;
                break;

            case '%':
                cout<<"The Modulus is : "<<fmod(a,b);
                break;

            default:
                cout<<"Enter an ARITHMETIC OPERATOR!!!";
                break;
        }

        cout<<"\n\nWanna continue ??\nPress(y/n)";
        cin>>brek;
        cout<<endl;



    }while(brek!='n' && brek!= 'N');


    return 0;

}