#include <iostream>
using namespace std;

class player{
public:
    string name; 
    int hp;
    int ad;
public:
    player(string nm,int h, int a) : name(nm),hp(h),ad(a){

    }
    int info() const{
        cout<<name<<' '<<hp<<','<<ad<<'\n';
        return hp;
    }
    void atk(player target) {
        cout<< name<<"-attack->"<<target.name<<'\n';
        cout<< target.hp;
        target.hp -= ad;
        cout<< " -> "<<target.hp<<'\n';
    }
};

int main(){

string name;
int hp,ad;

cin>>name>>hp>>ad;
player p1(name,hp,ad);
cin>>name>>hp>>ad;
player p2(name,hp,ad);

p1.info();
p2.info();
p1.atk(p2);

    return 0;
}