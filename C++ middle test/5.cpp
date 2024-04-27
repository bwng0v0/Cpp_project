#include <iostream>
using namespace std;

/*=======================소=스=코=드====================*/

class Player {
private:
    string name;
    int hp;
    int wp;
public:
    Player(string name,int hp, int wp = 10): name{name},hp{hp},wp{wp} {

    }
   //멤버 함수
   void getInfo();
   string getname(){
	   return name;
   }
   void sethp( int set ){
	   hp += set;
   }
   int getwp(){
	   return wp;
   }
};

void Player::getInfo() {
    cout << "-----플레이어 정보-----" << endl;
    cout << "플레이어 이름 : " <<name<< endl;
    cout << "체력 : " <<hp<< endl;
    cout << "무기 : " << wp << endl;
}


class Monster {
private:
	string name;
	    int hp;
	    int wp;
public:
   //멤버 함수
Monster(string name,int hp = 100, int wp = 1): name{name},hp{hp},wp{wp} {

}
void getInfo();
string getname(){
	   return name;
   }
void sethp( int set ){
	   hp += set;
   }
int getwp(){
	   return wp;
   }
};
void Monster::getInfo() {
    cout << "-----몬스터 정보-----" << endl;
    cout << "몬스터 이름 : " <<name<< endl;
    cout << "체력 : " <<hp<< endl;
    cout << "무기 : " << wp << endl;
}

void Attack(Player& A, Monster& B) {
  cout <<A.getname()<< "(이)가 " << B.getname() << "을 공격했다!" << endl;
  B.sethp(-A.getwp());
}
void Attack(Monster& A,Player& B) {
  cout << A.getname() << "(이)가 " << B.getname() << "을 공격했다!" << endl;
  B.sethp(-A.getwp());
}
void Attack(Player& A, Player& B) {
  cout <<A.getname() << "(이)가 " <<B.getname()  << "을 공격했다!" << endl;
  B.sethp(-A.getwp());
}

int main() {

    Player player_1("홍길동", 100);
    Player player_2("손오공", 100, 5);
    Monster monster_A("몬스터 A"), monster_B("몬스터 B", 200);

    int i;
    cin >> i;
    switch (i)
    {
    case 1: //플레이어가 몬스터 공격
        Attack(player_2, monster_A);
        player_2.getInfo();
        monster_A.getInfo();
        break;
    case 2: //몬스터가 플레이어 공격
        Attack(monster_B, player_1);
        player_1.getInfo();
        monster_B.getInfo();
        break;
    case 3: //플레이어가 플레이어 공격
        Attack(player_1, player_2);
        player_1.getInfo();
        player_2.getInfo();
        break;
    }
    return 0;
}
