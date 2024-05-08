//https://www.acmicpc.net/problem/7562 나이트의 이동
#include <iostream>
#include <queue>
#define X first
#define Y second
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

// int arr[300][300];
// int vis[300][300];
queue<pair<int,int>> Q;
pair<int,int> cur;
int dx[] = {2,2,-2,-2, 1,-1,1,-1};
int dy[] = {1,-1,1,-1, 2,2,-2,-2};


int main(){
fastio

int T; cin>>T;
for( int t=0; t<T; t++ ){

int n; cin>>n;
int arr[n][n] {};
int vis[n][n] {};

cin>>cur.X>>cur.Y;
vis[cur.X][cur.Y] = 1;
Q.push(cur);

while( !Q.empty() ){
    cur = Q.front();
    Q.pop();
    for( int dir=0; dir<8; dir++ ){
        int x = cur.X + dx[dir];
        int y = cur.Y + dy[dir];
        if( x<0|| y<0|| x>=n|| y>=n ) continue;
        if( vis[x][y] ) continue;
        
        vis[x][y] = 1;
        arr[x][y] = arr[cur.X][cur.Y] + 1;
        Q.push({x,y});
    }
}

cin>>cur.X>>cur.Y;
cout<<arr[cur.X][cur.Y]<<"\n";

}

    return 0;
}