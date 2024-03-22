#include <iostream>
using namespace std;

class Player{
    string name;
    int level; 

    public:
    Player(): Player("") {
        cout<<"위임생성자 코드입니다.\n";
    }
    Player(string nm): name{nm}, level{} {
        cout<<"플레이어 "<<name<<" lv."<<level<<"이(가) 생성되었습니다.\n";
    }
};
int main(){

Player p1;

    return 0;
}