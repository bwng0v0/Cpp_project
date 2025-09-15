//https://www.acmicpc.net/problem/2178 미로 탐색
#include <bits/stdc++.h>
using namespace std;

int arr[101][101];
int vis[101][101];
queue<pair<int,int>> Q;
pair<int,int> cur;
int xarr[4] = {1,0,-1,0};
int yarr[4] = {0,1,0,-1};

int main(){
ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int n,m; cin>>n>>m;
for( int i=0; i<n; i++ ){
    string tmp; cin>>tmp;
    for( int j=0; j<m; j++ ){
        arr[i][j] = tmp[j]-48;//다른방법있나
    }
}

vis[0][0] = 1;
Q.push({0,0});

int cnt = 1;
int Qcnt = 1;

while( Qcnt > 0 ){

    int now = Qcnt;
    Qcnt = 0;
    cnt += 1;

    for( int i=0; i<now; i++ ){
        cur = Q.front();
        Q.pop();

    for( int dir=0; dir<4; dir++ ){
        int x = cur.first + xarr[dir];
        int y = cur.second + yarr[dir];
        if( x<0 || y<0 || x>=n || y>=m )continue;
        if( arr[x][y] == 0 || vis[x][y] == 1 )continue;

        //방문한칸은 다시방문하지않아도 됨
        arr[x][y] = cnt;
        vis[x][y] = 1;

        Q.push({x,y});
        Qcnt += 1;
        }
    }
}

cout<<arr[n-1][m-1];

    return 0;
}