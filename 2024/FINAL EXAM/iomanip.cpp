#include <iostream>
#include <iomanip>
using namespace std;

class person{
    string name;
    int age;
    public:
    void set(string n, int a){
        name = n; age = a;
    }
    friend ostream& operator << (ostream& out, person& per);
};

ostream& operator << (ostream& out, person& per){
    per.age += 1;
    out<<per.name<<" "<<per.age<<"\n";
    return out;
}
ostream& hello(ostream& out){
    out<<"hello";
    return out;
}

int main(){

person p;
p.set("um",24);

cout<<p<<p<<hello;

    return 0;
}