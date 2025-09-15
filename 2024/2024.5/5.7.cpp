//https://www.acmicpc.net/problem/2667 단지번호붙이기
#include <iostream>
#include <queue>
#include <algorithm>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define X first
#define Y second
using namespace std;

queue<pair<int,int>> Q;
pair<int,int> cur;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
fastio

int n; cin>>n;
char arr[n][n] {};
int vis[n][n] {};

for( int i=0; i<n; i++ ){
    for( int j=0; j<n; j++ ){
        cin>>arr[i][j];
    }
}
//입력

vector<int> vec;
vec.push_back(0);

for( int i=0; i<n; i++ ){
    for( int j=0; j<n; j++ ){
        if( arr[i][j] == '1' && vis[i][j]==0 ){

            vis[i][j] = 1;
            Q.push({i,j});
            vec[0] += 1;

            int cnt = 0;

            while( !Q.empty() ){
                cur = Q.front();
                Q.pop();
                cnt += 1;
                for( int dir=0; dir<4; dir++ ){
                    int x = cur.X + dx[dir];
                    int y = cur.Y + dy[dir];
                    if( x<0|| y<0|| x>=n|| y>=n ) continue;
                    if( vis[x][y]==1 || arr[x][y]=='0' ) continue;
                    vis[x][y] = 1;
                    Q.push({x,y});
                }
            }
            vec.push_back(cnt);
        }
    }
}

cout<<vec[0]<<"\n";
vec.erase(vec.begin());
//정렬 빼먹음
sort(vec.begin(),vec.end());

for( int i: vec ) cout<<i<<"\n";

    return 0;
}