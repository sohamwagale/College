#include<iostream>
using namespace std;

int main(){

    int i =2;
    int j= 2;
    int k =2;
    int l=2;


//input matrix one
    int a[i][j];

    for(int row = 0;row<i;row++){
        for(int col=0;col<j;col++){
            cin>>a[row][col];            
        }
    }

//input matrix two

    cout<<endl;
    int b[k][l];

    for(int row = 0;row<i;row++){
        for(int col=0;col<j;col++){
            cin>>b[row][col];
        }
    }


//Addition
if(i==k && j ==l){

    int add[i][j];

    for(int row = 0;row<i;row++){
        for(int col=0;col<j;col++){
            add[row][col] = a[row][col] + b[row][col];
        }
    }

  
//Printing the addditon

    cout<<endl<<endl;

    for(int row = 0;row<i;row++){
        for(int col =0;col<j;col++){
            cout<<add[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

//Substraction
    int sub[i][j];

    for(int row = 0;row<i;row++){
        for(int col=0;col<j;col++){
            sub[row][col] = a[row][col] - b[row][col];
        }
    }

  
//Printing the substraction

    cout<<endl<<endl;

    for(int row = 0;row<i;row++){
        for(int col =0;col<j;col++){
            cout<<sub[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;


//multiplication
if(j==k){
    int mul[i][l];
    int prod =0;
    int m1_col =0;
    int m2_row=0;
    int m1_row =0;
    int m2_col =0;

    for(;m2_col<l;m2_col++){
        for(;m1_row<i;m1_row++){
            prod =0;
            for(; m1_col<j;m1_col++,m2_row++){
                prod = prod + m1_col*m2_row;    
            }
            mul[m1_row][m2_col] = prod;
        }
    }

    cout<<endl<<endl;

    for(int row = 0;row<i;row++){
        for(int col =0;col<l;col++){
            cout<<mul[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;






}

    return 0;

}