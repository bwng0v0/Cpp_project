//연산자 오버로딩 매개변수 타입을 const로 해야된다고
//임시객체가 const라서
// "asdf"같은 리터럴 문자열도 const?

//리턴 레퍼런스는 아직 모르겠다

#include <iostream>
using namespace std;

class Person{
    public:
    string name;
    int old;
    public:
    Person(string n, int o):name{n}, old{o} {}

     

    Person operator + (Person& p2){
        this->name = p2.name;
        this->old += p2.old;
        return *this;
    }


};

int main(){


Person p1("p1",10);
Person p2("p2",20);

p1 = p1+p2;

cout<<p1.name<<p1.old;


    return 0;
}