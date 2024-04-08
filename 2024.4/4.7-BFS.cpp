 //https://www.acmicpc.net/problem/7576 토마토
#include <bits/stdc++.h>
using namespace std;

int arr[1001][1001];
int vis[1001][1001];
int xarr[4] = {1,0,-1,0};
int yarr[4] = {0,1,0,-1};
pair<int,int> cur;
int daycnt;

int main(){
ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

queue<pair<int,int>> Q;
queue<pair<int,int>> next;

int M,N;cin>>M>>N;
for( int i=0; i<N; i++ ){
    for( int j=0; j<M; j++ ){
        cin>>arr[i][j];//입력과 동시에 인접을 큐에 넣을까 했는데 토마토없는칸일수있음
    }
}

//익은토마토의 인접을 모두 큐에 넣고 카운트 (첫날익을것들)
for( int i=0; i<N; i++ ){
    for( int j=0;  j<M; j++ ){

        if( arr[i][j]==1 ){//익은토마토라면 인접한 토마토를 모두 큐에넣음
        vis[i][j] = 1;
        for( int dir=0; dir<4; dir++ ){
            int x = i + xarr[dir];
            int y = j + yarr[dir];
            if( x<0 || y<0 || x>=N || y>=M )continue;//범위밖이면
            if( arr[x][y] == -1 || vis[x][y]==1 || arr[x][y]==1 )continue;//토마토없는칸,방문한칸이면 !!!!!!!이미 익었다면 넣지 않아야함
            vis[x][y] = 1;
            next.push({x,y});
        }
        }
    }
}

while( !next.empty() ){//전날에 큐에 뭔가 들어갔다면 == 익어야할게있다면

    daycnt += 1;//하루가 지났으니 +1일
    
    Q = next;
    while( !next.empty() )
    next.pop();

    while( !Q.empty() ){//오늘 익어야할걸 다 익히면서 인접한 내일익을걸 next에 넣음
        cur = Q.front();
        Q.pop();//아니 팝을 안했네
        
        arr[cur.first][cur.second] = 1;//물들이고
        //인접을 넣어
        for( int dir=0; dir<4; dir++ ){
            int x = cur.first + xarr[dir];
            int y = cur.second + yarr[dir];
            if( x<0 || y<0 || x>=N || y>=M )continue;//범위밖이면
            if( arr[x][y] == -1 || vis[x][y]==1 )continue;//토마토없는칸,방문한칸이면
            vis[x][y] = 1;
            next.push({x,y});
        }

    }
}


for( int i=0; i<N; i++ ){
    for( int j=0; j<M; j++ ){
        if( arr[i][j] == 0 ){//0이 있으면 모두익힐수가 없었다는거임
            cout<<-1;
            return 0;
        }
    }
}

cout<<daycnt;

    return 0;
}