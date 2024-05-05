//https://www.acmicpc.net/problem/17081 RPG Extreme
/*
디버깅한것들
이동할때 dx 원소 {0,0,1,-1}로 씀
이미있는 장신구를 먹어서 카운팅올림
싸울때 공격력-방어도+방어구로 썼음
HU 장신구 없어도 보스첫타 회피
몬스터 set 매개변수 순서 헷갈림
*/
#include <iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define X first
#define Y second
using namespace std;

inline int max( int a,int b){ return a>b?a:b; }

string Oarr[7] = {"HR", "RE", "CO", "EX", "DX", "HU", "CU"};
char dir[4] = {'L', 'R', 'U', 'D'};
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
string cmd;
int n,m;
char map[101][101];
int obmap[101][101];
int turn;

class Box{
    public:
    int W;
    int A;
    int O;//ex) HR = 0;

    Box(): W{0}, A{0}, O{-1} {}
    void set(int num, int x ){// 0 = W, 1 = A
        if( num ){A += x;}else{W += x;}
    }
    void set(string name){
        for( int i=0; i<7; i++ ){
            if( name == Oarr[i] )
            O = i;
        }
    }
};

class Monster{
    public:
    string name;
    int HP;
    int MAXHP;
    int AD;
    int DEF;
    int EXP;

    
    //Monster(string name, int hp, int ad, int def, int exp): name{name}, HP{hp}, AD{ad}, DEF{def}, EXP{exp} {}
    void set(string n, int a, int d, int h, int e){
        name = n;
        HP = h;
        MAXHP = h;
        AD = a;
        DEF = d;
        EXP = e;
    }
};

class Player{
    public:
    int LV;
    int HP;
    int MAXHP;
    int AD;
    int DEF;
    int EXP;
    
    int WP;
    int AM;
    
    int Ocnt;
    
    
    int O[7];
    pair<int,int> start;
    pair<int,int> pos;

    Player(): LV{1}, HP{20}, MAXHP{20}, AD{2}, DEF{2}, EXP{}, WP{},AM{}, O{}, Ocnt{} {}
    void xy(int x, int y){ start={x,y}; pos={x,y}; }
    

    void getexp(int exp){
        if( O[3] ){
            EXP += exp*1.2;
        }else{
            EXP += exp;
        }

        //레벨업
        if( EXP >= LV*5 ){
            LV += 1;
            MAXHP += 5;
            AD += 2;
            DEF += 2;
            HP = MAXHP;
            EXP = 0;
        }
    }
    bool dem(int demage,string atker){
        HP -= demage;
        if( HP<1 ){
            HP = 0;
            if(die(atker)) return true;
        }
        return false;
    }
    void end(){
        if( HP>=1 ) map[pos.X][pos.Y] = '@';

        for( int i=0; i<n; i++ ){
            for( int j=0; j<m; j++ ){
                cout<<map[i][j];
            }
            cout<<"\n";
        }
        cout<<"Passed Turns : "<<turn+1<<"\n";
        cout<<"LV : "<<LV<<"\n";
        cout<<"HP : "<<HP<<"/"<<MAXHP<<"\n";
        cout<<"ATT : "<<AD<<"+"<<WP<<"\n";
        cout<<"DEF : "<<DEF<<"+"<<AM<<"\n";
        cout<<"EXP : "<<EXP<<"/"<<LV*5<<"\n";
    }
    bool die(string killer){
        if( O[1] ){//반지 있으면 부활
            O[1] = 0;
            Ocnt -= 1;
            pos = start;
            HP = MAXHP;
            return true;
        }

        end();
        cout<<"YOU HAVE BEEN KILLED BY "<<killer<<"..\n";
        exit(0);
    }
    void move(int index){
        for( int i=0; i<4; i++ ){
            if( dir[i] == cmd[index] ){
                int x = pos.X + dx[i];
                int y = pos.Y + dy[i];
                if( x<0|| y<0|| x>=n|| y>=m ) return;
                if( map[x][y] == '#' ) return;
                pos.X += dx[i];
                pos.Y += dy[i];
            }
        }
    }
    bool fight(Monster& mob){
        int i=0,power;

        while(true){
            power = AD+WP;
            if( i==0 && O[2] ){
                if( O[4] )
                power*=3;
                else
                power*=2;
            }
            //때리고
            mob.HP -= max(1,power-mob.DEF);
            //죽었으면
            if( mob.HP<1 ){
                getexp(mob.EXP);
                if( O[0] ){HP += 3; if( HP>MAXHP )HP = MAXHP;}
                return false;
            }
            //맞고 죽었으면
            if(dem(max(1,mob.AD -(DEF+AM)),mob.name)){
                //부활
                mob.HP = mob.MAXHP;
                return true;
            }
            
            i+=1;
        }

        
    }
    void openbox(Box& box){
        if( box.W > 0 ){ WP=0; WP+=box.W; }
        else if( box.A > 0 ){ AM=0; AM+=box.A; }
        else if( box.O != -1 && Ocnt < 4 && !O[box.O] ){ O[box.O] = 1; Ocnt += 1; }
    }

    bool last(Monster& boss){
        if( O[5] )HP=MAXHP;

        int i=0;
        while(true){
            int power = AD+WP;
            if( i==0 && O[2] ){
                if( O[4] )
                power*=3;
                else
                power*=2;
            }

            boss.HP -= max(1,power-boss.DEF);
            if( boss.HP<1 ){
                getexp(boss.EXP);
                if( O[0] ){HP += 3; if( HP>MAXHP )HP = MAXHP;}
                return false;
            }

            if( O[5] && i==0 ){
                i += 1; continue;
            }

            if(dem(max(1,boss.AD-(DEF+AM)),boss.name)){
                //부활했다면
                boss.HP = boss.MAXHP;
                return true;
            }
            
            i+= 1;
        }
    }
};


int main(){
fastio

cin>>n>>m;
int boxcnt{0}, moncnt{0};
Player P;

for( int i=0; i<n; i++ ){
    for( int j=0; j<m; j++ ){
        cin>>map[i][j];
        if( map[i][j] == 'B' ){
            boxcnt += 1;
        }else if( map[i][j] == '&'){
            moncnt += 1;
        }else if( map[i][j] == '@' ){
            map[i][j] = '.';
            P.xy(i,j);
        }else if( map[i][j] == 'M' ){
            moncnt += 1;

        }
    }
}
cin>>cmd;

Monster Marr[moncnt+1];
for( int i=1; i<moncnt+1; i++ ){
    int x,y;
    string name;
    int ad,def,hp,exp;
    cin>>x>>y>>name>>ad>>def>>hp>>exp;

    obmap[x-1][y-1] = i;
    Marr[i].set(name,ad,def,hp,exp);
}

Box Barr[boxcnt+1];
for( int i=1; i<boxcnt+1; i++ ){
    int x,y;
    char O;
    cin>>x>>y>>O;
    obmap[x-1][y-1] = i;

    if( O == 'O' ){
        string s; cin>>s;
        Barr[i].set(s);
    }else{
        int tmp; cin>>tmp;
        Barr[i].set((O=='W'?0:1),tmp);
    }
}
//입력끝


//게임시작
for(; turn<cmd.size(); turn++ ){

    //이동
    P.move(turn);

    //가시함정
    if( map[P.pos.X][P.pos.Y] == '^' ){
        P.dem(P.O[4]?1:5,"SPIKE TRAP");
    }
    //몬스터
    else if( map[P.pos.X][P.pos.Y] == '&' ){
        int who = obmap[P.pos.X][P.pos.Y];
        if(P.fight(Marr[who])) continue;
        map[P.pos.X][P.pos.Y] = '.';
    }
    //박스
    else if( map[P.pos.X][P.pos.Y] == 'B' ){
        int what = obmap[P.pos.X][P.pos.Y];
        P.openbox(Barr[what]);
        map[P.pos.X][P.pos.Y] = '.';
    }

    //보스몬스터
    else if( map[P.pos.X][P.pos.Y] == 'M' ){
        int who = obmap[P.pos.X][P.pos.Y];

        if(P.last(Marr[who])) continue;
        //살아서 나오면 이긴거임
        P.end();
        cout<<"YOU WIN!\n";
        exit(0);
    }

}

turn-=1;
P.end();
cout<<"Press any key to continue.\n";

    return 0;
}