#include <iostream>
using namespace std;

int& plus100( int &num ){
    num += 100;
    return num;
}


int main(){

int n = 5;

int &ref = plus100(n);


cout<<"n: "<<n<<'\n';
cout<<"ref: "<<ref<<'\n';

ref -= 50;

cout<<"n: "<<n<<'\n';
cout<<"ref: "<<ref<<'\n';


    return 0;
}