//https://www.acmicpc.net/problem/7569 토마토
#include <iostream>
#include <queue>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int xa[] = {0,0,0,0,1,-1};
int ya[] = {1,0,-1,0,0,0};
int za[] = {0,1,0,-1,0,0};

int main(){
fastio

int n,m,h; cin>>m>>n>>h;//와 이런거는
int arr[h][n][m] {};
int vis[h][n][m] {};

queue<int> Qx;
queue<int> Qy;
queue<int> Qz;
int size = 0;
int zero = 0;

for( int i=0; i<h; i++ ){
    for( int j=0; j<n; j++ ){
        for( int k=0; k<m; k++ ){
            cin>>arr[i][j][k];
            if( arr[i][j][k] == 1 ){
                Qx.push(i); Qy.push(j); Qz.push(k);
                vis[i][j][k] = 1;
                size += 1;
            }
            if( arr[i][j][k] == 0 ) zero += 1;
        }
    }
}

if( zero == 0 ){
    cout<<0;
    return 0;
}
//하루 단위로 어떻게 카운팅하지
//하루 = while 시작전에 넣어놓은게 다 빠지면
// x=h y=n z=m
int cur[3];

int res = 0;
int time = 0;

while( !Qx.empty() ){
    cur[0] = Qx.front();
    cur[1] = Qy.front();
    cur[2] = Qz.front();
    Qx.pop(); Qy.pop(); Qz.pop();
    
    for( int dir=0; dir<6; dir++ ){
        int x = cur[0] + xa[dir];
        int y = cur[1] + ya[dir];
        int z = cur[2] + za[dir];
        if( x<0|| y<0 || z<0|| x>=h|| y>=n|| z>=m ) continue;
        if( vis[x][y][z] == 1 || arr[x][y][z] == -1 ) continue;
    
        vis[x][y][z] = 1;
        arr[x][y][z] = 1;
        Qx.push(x); Qy.push(y); Qz.push(z);
    }

    size -= 1;
    if( size == 0 ){
        size = Qx.size();
        res += 1;
    }

}


for( int i=0; i<h; i++ ){
    for( int j=0; j<n; j++ ){
        for( int k=0; k<m; k++ ){
            if( arr[i][j][k] == 0 ){
                cout<<-1;
                return 0;
            }
        }
    }
}


cout<<res-1;

    return 0;
}