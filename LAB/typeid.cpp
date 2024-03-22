#include <iostream>
using namespace std;

class Player00{
    string name;
    int level;

    public:
    Player00(): Player00("") {
        cout<<"위임생성자 코드입니다.\n";
    }
    Player00(string nm): name{nm}, level{} {
        cout<<"플레이어 "<<name<<" lv."<<level<<"이(가) 생성되었습니다.\n";
    }
};
int main(){

int arr[10];
string s = "hello";
Player00 p1("123456");


cout<<(typeid(p1).name());

    return 0;
}