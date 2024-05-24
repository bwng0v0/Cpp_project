//https://www.acmicpc.net/problem/2638 치즈
#include <iostream>
#include <queue>
#define X first
#define Y second
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

queue<pair<int,int>> Q,E;
pair<int,int> cur;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
fastio

int r,c; cin>>r>>c;
int arr[r][c];
int vis[r][c] {};
for( int i=0; i<r; i++ ){
    for( int j=0; j<c; j++ ){
        cin>>arr[i][j];
    }
}
//입력

int res = 0;
while(1){

//녹이기
while( !E.empty() ){
    cur = E.front();
    E.pop();
    arr[cur.X][cur.Y] = 0;
}

int sum=0;
for( int i=0; i<r; i++ ){
    for( int j=0; j<c; j++ )
        sum += arr[i][j];
}
if( sum==0 )break;

res += 1;
vis[0][0] = 1;
Q.push({0,0});

while( !Q.empty() ){
    cur = Q.front();
    Q.pop();
    for( int dir=0; dir<4; dir++ ){
        int x = cur.X + dx[dir];
        int y = cur.Y + dy[dir];
        if( x<0|| y<0|| x>=r|| y>=c ) continue;
        if( arr[x][y] == 1 ){
            vis[x][y] += 1;
            if( vis[x][y] == 2 ){ E.push({x,y}); }
        }
        if( vis[x][y] ) continue;

        vis[x][y] = 1;
        Q.push({x,y});
    }
}

for( int i=0; i<r; i++ ){
    for( int j=0; j<c; j++ )
        vis[i][j] = 0;
}
// cout<<"arr\n";
// for( int i=0; i<r; i++ ){
//     for( int j=0; j<c; j++ )
//     cout<<arr[i][j]<<" ";
//     cout<<"\n";
// }
// cout<<"\n";

}

cout<<res;

    return 0;
}