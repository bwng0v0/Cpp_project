//https://www.acmicpc.net/problem/4179 불
//보고풀었음
//테이블 여러개 쓰기가 생각이안났음
//BFS + 큐에 대한 이해도가 부족했음 어떻게 채워질지 순서를 몰랐음
//
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int xarr[4] = {1,0,-1,0};
int yarr[4] = {0,1,0,-1};


int main(){

int r,c; cin>>r>>c;
int dist[r][c] {};
int firedist[r][c] {};
for( int i=0; i<r; i++ ){
    fill(dist[i],dist[i]+c,-1);
    fill(firedist[i],firedist[i]+c,-1);
}
string board[r];
queue<pair<int,int>> Q;
queue<pair<int,int>> fireQ;
pair<int,int> cur;

for( int i=0; i<r; i++ ){
    cin>>board[i];
}
for( int i=0; i<r; i++ ){
    for( int j=0; j<c; j++ ){
        if( board[i][j] == 'J' ){
        Q.push({i,j});
        dist[i][j] = 0;}
        if( board[i][j] == 'F' ){
        fireQ.push({i,j});
        firedist[i][j] = 0;}
    }
}

// firedist 채우기
// firedist 각 인덱스는 해당위치까지 오는데 걸리는 시간
while( !fireQ.empty() ){
    cur = fireQ.front();
    fireQ.pop();
    for( int dir=0; dir<4; dir++ ){
        int x = cur.X + xarr[dir];
        int y = cur.Y + yarr[dir];
        if( x<0 || y<0 || x>=r || y>=c ) continue;
        if( board[x][y] == '#' || firedist[x][y] >=0  ) continue; //0보다크거나같다면 == vis역할
        firedist[x][y] = firedist[cur.X][cur.Y] + 1;
        fireQ.push({x,y});
    }
}

int can = 0;
int mindist = r*c;
while( !Q.empty() ){
    cur = Q.front();
    Q.pop();
    for( int dir=0; dir<4; dir++ ){
        int x = cur.X + xarr[dir];
        int y = cur.Y + yarr[dir];
        if( x<0 || y<0 || x>=r || y>=c ){
            can = 1;
            if( dist[cur.X][cur.Y] + 1 < mindist ) mindist = dist[cur.X][cur.Y] + 1;
            continue;
        }
        //제일중요한부분
        if( firedist[x][y] != -1 && dist[cur.X][cur.Y] + 1 >= firedist[x][y] ) continue;
        if( board[x][y] == '#' || dist[x][y] >= 0 ) continue;
        dist[x][y] = dist[cur.X][cur.Y] + 1;
        Q.push({x,y});
    }
}


if( can )
cout<<mindist;
else
cout<<"IMPOSSIBLE";



    return 0;
}