//https://www.acmicpc.net/problem/2468 안전 영역
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

int n,maxheight{0}; cin>>n;
for( int i=0; i<n; i++ ){
    for( int j=0; j<n; j++ ){
        cin>>arr[i][j];
        if( arr[i][j] > maxheight )
        maxheight = arr[i][j];
    }
}
//입력끝



//안잠기면 1 다잠기면 0
int maxsize{1}, rain{1}, safesize{0};

while( rain < maxheight ){//다 잠기기 직전까지 (다잠기면 0임 어차피)

for( int i=0; i<n; i++ ){
    for( int j=0; j<n; j++ ){
        //물에 안잠기면 주변에 안잠기는구역다 포함
        if( arr[i][j] > rain && vis[i][j]==0 ){

            safesize += 1;//안전구역 카운트+1
            vis[i][j] = 1;
            Q.push({i,j});

            while( !Q.empty() ){//주변안전지역 모두 색칠
                cur = Q.front();
                Q.pop();
                for( int dir = 0; dir<4; dir++ ){
                    int x = cur.first + xarr[dir];
                    int y = cur.second + yarr[dir];
                    if( x<0 || y<0 || x>=n || y>=n )continue;//범위체크
                    if( arr[x][y] <= rain || vis[x][y]==1 )continue;//안전지대가 아니면 or 이미 방문했으면
                    vis[x][y] = 1;
                    Q.push({x,y});
                }
            }
        }


    }
}



//vis초기화
for( int i=0; i<n; i++ ){
    for( int j=0; j<n; j++ ){
        vis[i][j] = 0;
    }
}
//잠기는높이를 올리면서 최대치 저장
rain += 1;
if( safesize > maxsize ){
    maxsize = safesize;
}   
safesize = 0;//아 ㅋㅋㅋㅋ
}


cout<<maxsize;

    return 0;
}