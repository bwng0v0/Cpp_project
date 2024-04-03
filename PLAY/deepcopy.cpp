#include <iostream>
using namespace std;

class TEST{
    public:
    int a;
    int *b;
    char* name;
};
int main(){

int c = 999;
TEST t1;
t1.a = 3;
t1.b = &c;
char nm[100] = "hello";
t1.name = nm;
cout<<*t1.b;
cout<<t1.name;

TEST t2;
t2 = t1;
cout<<*t2.b;
cout<<t2.name;

    return 0;
}