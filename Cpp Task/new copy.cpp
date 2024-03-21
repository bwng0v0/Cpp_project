#include <iostream>
using namespace std;

class Person{
    string name;
    int old;
    public:
    Person(string n, int o): name{n}, old{o}{
        cout<<"Person 생성됨 이름:"<<name<<"연령 :"<<old<<"\n";
    }
    Person(): name{}, old{}{
        cout<<"Person 생성됨 이름:"<<name<<"연령 :"<<old<<"\n";
    }
};
int main(){

    string tmpname = "K0";
    Person *arr = new Person[10];

    for( int i=0; i<10; i++ ){
        arr[i].name = "K"+
    }

    return 0;
}