#include <iostream>
using namespace std;


int main(){
cin >> boolalpha;
cout << boolalpha;
cout<<"Hello world!!\n";

string name; cout<<"name? "; getline(cin,name);
cout<<"name: "<<name<<"\n";
int id; cout<<"id? "; cin>>id;
cout<<"id: "<<id<<"\n";
double weight; cout<<"weight? "; cin>>weight;
cout<<"weight: "<<weight<<"\n";
bool married; cout<<"married? "; cin>>married;
cout<<"married: "<<married<<"\n";
string s; cout<<"name to find? "; getline(cin,s);getline(cin,s);
if( s == name ){
    //name:Hong gil dong, id:12345, weight:72.5, married:false
    cout<<"name:"<<name<<", "<<"id:"<<id<<", "<<"weight:"<<weight<<", "<<"married:"<<married;
}else{
    cout<<s<<": not found";
}

    return 0;
}