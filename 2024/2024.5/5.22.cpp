//https://www.acmicpc.net/problem/17144 미세먼지 안녕!
#include <iostream>
#include <queue>
#define X first
#define Y second
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

queue<pair<int,int>> Q;
pair<int,int> cur;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void swap(int& a,int& b){
    int ta,tb;
    ta = a;
    tb = b;
    a = tb;
    b = ta;
}



int main(){
fastio

int r,c,t; cin>>r>>c>>t;
int arr[r][c];
pair<int,int> top,bot;

for( int i=0; i<r; i++ ){
    for( int j=0; j<c; j++ )
        cin>>arr[i][j];
}

for( int i=0; i<r; i++ ){
    if( arr[i][0] == -1 ){
        top = {i,0}; bot = {i+1,0};
        break;
    }
}

//입력

/*
1초 동안 아래 적힌 일이 순서대로 일어난다.

1.미세먼지가 확산된다. 확산은 미세먼지가 있는 모든 칸에서 동시에 일어난다.(r, c)에 있는 미세먼지는 인접한 네 방향으로 확산된다.
인접한 방향에 공기청정기가 있거나, 칸이 없으면 그 방향으로는 확산이 일어나지 않는다.
확산되는 양은 Ar,c/5이고 소수점은 버린다. 즉, ⌊Ar,c/5⌋이다.(r, c)에 남은 미세먼지의 양은 Ar,c - ⌊Ar,c/5⌋×(확산된 방향의 개수) 이다.

2.공기청정기가 작동한다.
공기청정기에서는 바람이 나온다.위쪽 공기청정기의 바람은 반시계방향으로 순환하고, 아래쪽 공기청정기의 바람은 시계방향으로 순환한다.
바람이 불면 미세먼지가 바람의 방향대로 모두 한 칸씩 이동한다.
공기청정기에서 부는 바람은 미세먼지가 없는 바람이고, 공기청정기로 들어간 미세먼지는 모두 정화된다.
*/


for( int time=0; time<t; time++ ){

int add[r][c] {};

//확산
for( int i=0; i<r; i++ ){
    for( int j=0; j<c; j++ ){
        if( arr[i][j] > 4 ) Q.push({i,j});
    }
}

while( !Q.empty() ){
    cur = Q.front();
    Q.pop();
    int val = arr[cur.X][cur.Y];
    int cnt = 0;

    for( int dir=0; dir<4; dir++ ){
        int x = cur.X + dx[dir];
        int y = cur.Y + dy[dir];
        if( x<0|| y<0|| x>=r|| y>=c ) continue;
        if( arr[x][y] == -1 ) continue;
        
        add[x][y] += val/5;
        cnt+=1;
    }
    arr[cur.X][cur.Y] -= val/5 * cnt;
}

// cout<<"\n";//
for( int i=0; i<r; i++ ){
    for( int j=0; j<c; j++ ){
    arr[i][j] += add[i][j];
    // cout<<arr[i][j]<<" ";//
    }
    // cout<<"\n";//
}


//top
arr[top.X-1][0] = 0;
for( int i=top.X-1; i>0; i-- ){
    swap(arr[i][0],arr[i-1][0]);
}
for( int i=0; i<c-1; i++ ){
    swap(arr[0][i],arr[0][i+1]);
}
for( int i=0; i<top.X; i++ ){
    swap(arr[i][c-1],arr[i+1][c-1]);
}
for( int i=c-1; i>1; i-- ){
    swap(arr[top.X][i],arr[top.X][i-1]);
}
//bot
arr[bot.X+1][0] = 0;
for( int i=bot.X+1; i<r-1; i++ ){
    swap(arr[i][0],arr[i+1][0]);
}
for( int i=0; i<c-1; i++ ){
    swap(arr[r-1][i],arr[r-1][i+1]);
}
for( int i=r-1; i>bot.X; i-- ){
    swap(arr[i][c-1],arr[i-1][c-1]);
}
for( int i=c-1; i>1; i-- ){
    swap(arr[bot.X][i],arr[bot.X][i-1]);
}

}

// cout<<"\n";
// for( int i=0; i<r; i++ ){
//     for( int j=0; j<c; j++ )
//     cout<<arr[i][j]<<" ";
//     cout<<"\n";
// }
// cout<<"\n";

int res = 0;
for( int i=0; i<r; i++ ){
    for( int j=0; j<c; j++ )
        res += arr[i][j];
}
cout<<res+2;


    return 0;
}