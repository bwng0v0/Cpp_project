//https://www.acmicpc.net/problem/1012 유기농 배추
#include <bits/stdc++.h>
using namespace std;

int arr[51][51];
int vis[51][51];
queue<pair<int,int>> Q;
pair<int,int> cur;
int xarr[4] = {1,0,-1,0};
int yarr[4] = {0,1,0,-1};


int main(){
ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int T;cin>>T;
for( int t=0; t<T; t++ ){

int m,n,k; cin>>m>>n>>k;
for( int i=0; i<k; i++ ){
    int x,y; cin>>x>>y;
    arr[y][x] = 1;
    //!!입력이 n,m이 아니라 m,n이었음
}

int cnt = 0;

for( int i=0; i<n; i++ ){
    for( int j=0; j<m; j++ ){
        if( arr[i][j] == 1 && vis[i][j]== 0 ){
            //탐색시작
            cnt += 1;
            vis[i][j] = 1;
            Q.push({i,j});

            while( !Q.empty() ){

                cur = Q.front();
                Q.pop();

                for( int dir=0; dir<4; dir++ ){
                    int x = cur.first + xarr[dir];
                    int y = cur.second + yarr[dir];
                    if( x<0 || y<0 || x>=n || y>=m )continue; //3 2가 왜 패스지
                    if( arr[x][y]==0  || vis[x][y]==1 )continue;
                    
                    vis[x][y] = 1;
                    Q.push({x,y});
                }
            }


        }
    }
}

cout<<cnt<<"\n";


//끝내고 arr,vis초기화
for( int i=0; i<n; i++ ){
    for( int j=0; j<m; j++ ){
        arr[i][j] = 0;
        vis[i][j] = 0;
    }
}

}



    return 0;
}