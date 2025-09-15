#include <bits/stdc++.h>
using namespace std;

class newstring;

class newint{
    int data;

    public:
    operator newstring ();
    newint(int a) : data{a} {}
    void out(){
        cout<<data<<endl;
    }
};

class newstring{
    string data;

    public:
    newstring(string s) : data{s} {}
    void out(){
        cout<<data<<endl;
    }
    operator newint ();
};

newint::operator newstring (){
        return newstring(to_string(data));
}
newstring::operator newint (){
    return newint(stoi(data));
}

int main(){

newint a(123);

newstring s("678");

a = s;

a.out();

    return 0;
}