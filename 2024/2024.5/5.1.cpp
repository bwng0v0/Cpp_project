//https://www.acmicpc.net/problem/6593 상범 빌딩
#include <iostream>
#include <queue>
#include <tuple>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;


int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int main(){
fastio

while(1){

int L,R,C; cin>>L>>R>>C;
if( C == 0 ) return 0;
string arr[L][R];
int vis[L][R][C] {};
string s;

queue<tuple<int,int,int>> Q;
tuple<int,int,int> cur;
tuple<int,int,int> esc;

getline(cin,s);
for( int i=0; i<L; i++ ){
    for( int j=0; j<R; j++ ){
        getline(cin,arr[i][j]);//char로 받아도 됨 -------
    }
    if(!(i==L-1))getline(cin,s);
}

//S,E좌표저장
for( int i=0; i<L; i++ ){
    for( int j=0; j<R; j++ ){
        for( int k=0; k<C; k++ ){
            vis[i][j][k] = -1;// 0 ~ 탐색한곳
            if( arr[i][j][k] == 'S' ){
                vis[i][j][k] = 0;
                Q.push({i,j,k});
            }
            else if( arr[i][j][k] == 'E' ){
                esc = {i,j,k};
            }
        }
    }
}

//탐색시작
while( !Q.empty() ){
    cur = Q.front();
    Q.pop();
    for( int dir=0; dir<6; dir++ ){
        int x = get<0>(cur) + dx[dir];
        int y = get<1>(cur) + dy[dir];
        int z = get<2>(cur) + dz[dir];
        if( x<0|| y<0|| z<0|| x>=L|| y>=R|| z>=C ) continue;
        if( vis[x][y][z] > -1 || arr[x][y][z] == '#' ) continue;

        vis[x][y][z] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
        Q.push({x,y,z});
    }
}
//esc 좌표값으로 탈출여부 출력
int end = vis[get<0>(esc)][get<1>(esc)][get<2>(esc)];
if( end > -1 )
    cout<<"Escaped in "<<end<<" minute(s).\n";
else{
    cout<<"Trapped!\n";
}


}
    return 0;
}