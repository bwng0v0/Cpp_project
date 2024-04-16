#include <iostream>
using namespace std;

int main(){

int a{3};
cout<<(++a+2);

// (a+1) + 2
// return by ref
a = 3;
cout<<(a++ +2);
// (tmp) + 2
// return by val

//자동(묵시적) 형변환도 연산자오버로딩
//객체 형변환도 연산자 오버로딩으로 가능

    return 0;
}