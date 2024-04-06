//https://www.acmicpc.net/problem/1926 그림
//왜 방문표시 후 푸쉬하지
#include <iostream>
#include <utility>
#include <queue>
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

int arr[501][501];
int vis[501][501];
int xarr[4] = {0,1,0,-1};
int yarr[4] = {1,0,-1,0};
int total,maxcnt;

int main(){
ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int N,M;cin>>N>>M;
for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
        cin>>arr[i][j];
    }
}
//입력끝

//탐색하다가 그림이 보이면 찾은그림으로 표시 cnt+=1;
queue<pair<int,int>> Q;//좌표를 저장하는 큐

for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
        if( arr[i][j]==1 && vis[i][j]==0 ){//안찾았던 그림이라면 그림찾기 시작

            total += 1;
            vis[i][j] = 1;//방문표시하고
            Q.push({i,j});//큐에 시작지점 푸시
            int cnt = 0;//시작점 포함
            //큐가 빌때까지 그림모두탐색
            while( !Q.empty() ){

                pair<int,int> cur = Q.front();
                Q.pop();

                cnt += 1;
                if( maxcnt < cnt )
                maxcnt = cnt;

                for( int dir=0; dir<4; dir++ ){
                    int x = cur.first + xarr[dir];
                    int y = cur.second + yarr[dir];
                    if( x<0 || y<0 || x>=N || y>=M ) //범위밖컨티뉴
                    continue;
                    if( arr[x][y]==0 || vis[x][y]==1 )//방문or그림아니면 컨티뉴
                    continue;

                    vis[x][y] = 1;
                    Q.push({x,y});
                    //이 자리에서 카운트하면 안됐음

                }
            }
        
        
        }
    }
}

cout<<total<<"\n"<<maxcnt;

    return 0;
}