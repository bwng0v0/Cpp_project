//https://www.acmicpc.net/problem/2206 벽 부수고 이동하기
#include <iostream>
#include <queue>
#include <tuple>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

queue<tuple<int,int,int>> Q;
tuple<int,int,int> cur;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

// char arr[1001][1001];
// int vis[1001][1001];
// int bvis[1001][1001];//찬스없는

int main(){
fastio

int n,m; cin>>n>>m;
char arr[n][m] {};
int vis[n][m] {};
int bvis[n][m] {};//찬스없는

for( int i=0; i<n; i++ ){
    for( int j=0; j<m; j++ ){
        cin>>arr[i][j];
    }
}

vis[0][0] = 1;
Q.push({0,0,1});

//도착점이 채워질때까지
while( !vis[n-1][m-1] && !Q.empty() ){
    cur = Q.front();
    auto [X,Y,chance] = cur;
    Q.pop();
    for( int dir=0; dir<4; dir++ ){
        int x = X + dx[dir];
        int y = Y + dy[dir];
        if( x<0|| y<0|| x>=n|| y>=m ) continue;//범위밖
        if( chance && vis[x][y] > 0 ) continue;//벽 안부숨
        if( !chance && bvis[x][y] > 0 ) continue;//벽부수기 씀
        if( arr[x][y] == '1' ){
            if( !chance ) continue;
            bvis[x][y] = vis[X][Y] + 1;//벽넘을떄 vis에서 +1해야힘
            Q.push({x,y,0});
            continue;
        }
        
        if(chance) vis[x][y] = vis[X][Y] + 1;
        else bvis[x][y] = bvis[X][Y] + 1;
        Q.push({x,y,chance});
    }

}

//0이 아닌 최소값
//둘다 0이면 -1

if(vis[n-1][m-1] || bvis[n-1][m-1]){
if( vis[n-1][m-1] == 0 ){ cout<<bvis[n-1][m-1]; return 0;}
if( bvis[n-1][m-1]== 0 ){ cout<<vis[n-1][m-1]; return 0;}
cout<<(vis[n-1][m-1] > bvis[n-1][m-1]?bvis[n-1][m-1] : vis[n-1][m-1]);
}else
cout<<-1;

    return 0;
}