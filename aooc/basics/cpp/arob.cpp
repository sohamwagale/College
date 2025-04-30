#include<iostream>
#include<string>
using namespace std;

class Students
{
private:
    /* data */
public:
    string name;
    int roll_no;
    char div;

    void display(){
        cout<<"\n\nName : "<<name<<endl<<"\nRoll No. : "<<roll_no<<endl<<"\nDiv : "<<div;
    }
};

int main(){
    cout<<"Enter No. of students : ";
    int n;
    cin>>n;

    Students s[n] ;

    for(int i =0;i<n;i++){
        cout<<"\nEnter name : ";
        cin>>s[i].name;
        cout<<"\nEnter Roll No. : ";
        cin>>s[i].roll_no;
        cout<<"\nEnter Div : ";
        cin>>s[i].div;

    }
    cout<<endl;
    for(int i =0;i<n;i++){
        s[i].display();
    }
}