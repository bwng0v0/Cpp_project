//https://www.acmicpc.net/problem/2210 숫자판 점프
#include <bits/stdc++.h>
#define X first
#define Y second
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main(){
fastio

set<string> S;
queue<pair<string,pair<int,int>>> Q;
int arr[5][5];
for( int i=0; i<5; i++ ){
    for( int j=0; j<5; j++ ){
        cin>>arr[i][j];
        Q.push( {to_string(arr[i][j]),{i,j}} );
    }
}

while( !Q.empty() ){
    auto cur = Q.front();
    Q.pop();

    if( cur.X.size() >= 6 ){ S.insert(cur.X); continue; }
    
    for( int dir=0; dir<4; dir++ ){
        int x = cur.Y.X + dx[dir];
        int y = cur.Y.Y + dy[dir];
        if( x<0|| y<0|| x>=5|| y>=5 ) continue;

        Q.push( {cur.X + to_string(arr[x][y]),{x,y}} );
    }
}

cout<<S.size();

//이게 한번에 통과네
//사실 DFS로 풀어야 정석이지만 DFS 안익숙해서 BFS로 풀음
//풀이는 브루트포싱으로 모든경우를 탐색하며 나온 문자열을 중복을 방지해 set에 넣고 set.size()를 출력함
//일단 5*5칸의 모든 칸을 시작점으로 큐에 넣고 BFS를 시작함
//큐는 <문자열,좌표>를 저장하도록 만듦
//BFS while문은 <문자열,좌표>하나를 뽑으면 인접좌표의 숫자를 문자열에 더하고, 좌표를 인접좌표로 바꾸고 다시 큐에넣음
//방문한 칸에 다시 방문할수도 있다는 부분때문에 무한루프를 조금 걱정했지만 문자열 길이가 6일때 제대로 빼주기만한다면 괜찮다


    return 0;
}