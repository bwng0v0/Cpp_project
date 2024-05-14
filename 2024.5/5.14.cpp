//https://www.acmicpc.net/problem/3197 백조의 호수
#include <iostream>
#include <queue>
#define X first
#define Y second
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

// char map[1500][1500];
// int vis[1500][1500];
queue<pair<int,int>> Q,nextQ;
pair<int,int> cur;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
fastio 

int r,c; cin>>r>>c;

char map[r][c];
int vis[r][c] {};
pair<int,int> Lpos;//백조위치

for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
        cin>>map[i][j];
        if( map[i][j] == '.' ){ vis[i][j]=1; Q.push({i,j}); }
        else if( map[i][j] == 'L' ){ vis[i][j]=1; Lpos={i,j}; Q.push({i,j}); }
    }
}
//입력


while( !Q.empty() ){//얼음녹이면서 녹는 날 저장
    cur = Q.front();
    Q.pop();
    for( int dir=0; dir<4; dir++ ){
        int x = cur.X + dx[dir];
        int y = cur.Y + dy[dir];
        if( x<0|| y<0|| x>=r|| y>=c || vis[x][y] ) continue;
        vis[x][y] = vis[cur.X][cur.Y] + 1;
        Q.push({x,y});
    }
}


int day = 1;
//vis는 얼음이 녹는시간이 저장되어있음
int dvis[r][c] {};//dvis는 현재의 시간으로 BFS하기위한 배열

// 아래 while문 과정
// day는 1부터 시작함
//1. vis의 얼음이 녹는 시간보다 day가 작다면(아직 얼음이 안녹았다면) 못지나감
//2. 만약 탐색 도중 다른 백조(L)을 찾으면 day를 출력하고 종료

//3. 탐색결과 백조를 못찾았다면 day += 1후 다시 탐색

dvis[Lpos.X][Lpos.Y] = day;
Q.push(Lpos);

while(true){
    
    //이번에 녹일거 Q에 nextQ 장전
    while( !nextQ.empty() ){
        cur = nextQ.front();
        Q.push(cur);
        nextQ.pop();
    }

    while( !Q.empty() ){
        cur = Q.front();
        Q.pop();
    for( int dir=0; dir<4; dir++ ){
        int x = cur.X + dx[dir];
        int y = cur.Y + dy[dir];
        if( x<0|| y<0|| x>=r|| y>=c ) continue;
        if( dvis[x][y] ) continue;// vis
        if( map[x][y] == 'L' ){ cout<<day-1; return 0; }
        if( vis[x][y] > day ){//만약 아직 안얼었다면 이번이 지나고 녹일거에 넣음(테두리!!!!!)
            dvis[x][y] = 1;
            nextQ.push({x,y});
            continue;
        }
        dvis[x][y] = 1;//표기하고 push
        Q.push({x,y});
        }
    }

    day += 1;
}

//서로 구역이 만나는 기준
//BFS해서 다른 L을 찾으면!

//얼음이 녹는 과정 & 걸린 날 수
//물은 1로 다 푸시해놓고 시작
// Q.push(Lpos);
// while( !Q.empty() ){
//     cur = Q.front();
//     Q.pop();
//     for( int dir=0; dir<4; dir++ ){
//         int x = cur.X + dx[dir];
//         int y = cur.Y + dy[dir];
//         if( x<0 || y<0|| x>=r|| y>=c ) continue;
//         if( dvis[x][y]>0 ) continue;

//         dvis[x][y] = dvis[cur.X][cur.Y] + 1;
//         Q.push({x,y});
//     }
// }




    return 0;
}