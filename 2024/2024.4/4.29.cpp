//https://www.acmicpc.net/problem/10026 적록색약
#include <iostream>
#include <queue>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define X first
#define Y second
using namespace std;

int xarr[4] = {1,0,-1,0};
int yarr[4] = {0,1,0,-1};

int main(){
fastio

int n; cin>>n;
string arr[n];
for( int i=0; i<n; i++ ) cin>>arr[i];

//탐색시작
int res1=0, res2=0; //res1이 일반인 res2가 색약

//일반인으로 탐색
int vis[n][n] {};
queue<pair<int,int>> Q;
pair<int,int> cur;
for( int i=0; i<n; i++ ){
    for( int j=0; j<n; j++ ){
        if( vis[i][j] == 0 ){
            //탐색시작
            res1 += 1;

            char color = arr[i][j];
            vis[i][j] = 1;
            Q.push({i,j});
            while( !Q.empty() ){
                cur = Q.front();
                Q.pop();

                for( int dir=0; dir<4; dir++ ){
                    int x = cur.X + xarr[dir];
                    int y = cur.Y + yarr[dir];
                    if( x<0 || y<0 || x>=n || y >=n ) continue;
                    if( vis[x][y] == 1/*실수한곳*/ || color != arr[x][y]/*실수한곳*/ ) continue;

                    vis[x][y] = 1;
                    Q.push({x,y});//실수한곳
                }        
            }
        }

    }
}

//vis 초기화
for( int i=0; i<n; i++ ){
    for( int j=0; j<n; j++ )
    vis[i][j] = 0;
}
//색약으로 탐색
for( int i=0; i<n; i++ ){
    for( int j=0; j<n; j++ ){
        if( vis[i][j] == 0 ){
            //탐색시작
            res2 += 1;

            char color = arr[i][j];
            vis[i][j] = 1;
            Q.push({i,j});
            while( !Q.empty() ){
                cur = Q.front();
                Q.pop();

                for( int dir=0; dir<4; dir++ ){
                    int x = cur.X + xarr[dir];
                    int y = cur.Y + yarr[dir];
                    if( x<0 || y<0 || x>=n || y >=n ) continue;
                    if( vis[x][y] == 1 ) continue;
                    // R이면 G까지 포함, G면 R까지 포함
                    if( (color == 'R' || color == 'G') && arr[x][y] == 'B' ) continue;
                    if( color == 'B' && 'B' != arr[x][y] ) continue;

                    vis[x][y] = 1;
                    Q.push({x,y});
                }        
            }
        }

    }
}





cout<<res1<<" "<<res2;

    return 0;
}