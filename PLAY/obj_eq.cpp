#include <iostream>
using namespace std;
class Test{
    public:
    string name;
    int *p;
};
int main(){

int hello = 369;
int hi = 123;
Test t1;
Test t2;

t1.name = "t1";
t1.p = &hello;
t2.name = "t2";
t2.p = &hi;

cout<<t1.name<<' '<<*t1.p<<'\n';
cout<<t2.name<<' '<<*t2.p<<'\n';
t2 = t1;
cout<<t1.name<<' '<<*t1.p<<'\n';
cout<<t2.name<<' '<<*t2.p<<'\n';
t2.name = "im t2";
t2.p = &hi;
cout<<t1.name<<' '<<*t1.p<<'\n';
cout<<t2.name<<' '<<*t2.p<<'\n';

    return 0;
}