#include <iostream>
using namespace std;

int& retu(int &a){
    return a;
}

int main(){

int a{3};

int b = retu(a);


cout<<b;
b = 5;
cout<<a;
    return 0;
}