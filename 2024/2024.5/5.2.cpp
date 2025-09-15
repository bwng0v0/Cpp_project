//https://www.acmicpc.net/problem/5427 불
/*
1. 불이 안지난곳도 지나야함
2. 불이 지나간 시간 == 사람이 지날시간 이면 못지나감
*/
#include <iostream>
#include <queue>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define X first
#define Y second
using namespace std;

queue<pair<int,int>> Q,fire;
pair<int,int> cur;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main(){
fastio

int T; cin>>T;
for( int t=0; t<T; t++ ){

int w,h; cin>>w>>h;
char arr[h][w];
int time[h][w] {};
int firetime[h][w] {};
for( int i=0; i<h; i++ ){//이거 안쓰고싶은데
    for( int j=0; j<w; j++ ){
        time[i][j] = -1;
        firetime[i][j] = -1;
    }
}
//테이블 세팅


for( int i=0; i<h; i++ ){
    for( int j=0; j<w; j++ ){
        cin>>arr[i][j];
        if( arr[i][j] == '@' ){
            Q.push({i,j});
            time[i][j] = 0;
        }else if ( arr[i][j] == '*' ){
            fire.push({i,j});
            firetime[i][j] = 0;
        }
    }
}
//입력


//불 BFS
while( !fire.empty() ){
    cur = fire.front();
    fire.pop();
    for( int dir=0; dir<4; dir++ ){
        int x = cur.X + dx[dir];
        int y = cur.Y + dy[dir];
        if( x<0|| y<0|| x>=h|| y>=w ) continue;
        if( firetime[x][y] > -1 || arr[x][y] == '#' ) continue;// vis,벽

        firetime[x][y] = firetime[cur.X][cur.Y] + 1;
        fire.push({x,y});
    }
}

//사람 BFS
int end = -1;

while( !Q.empty() ){
    cur = Q.front();
    Q.pop();
    for( int dir=0; dir<4; dir++ ){
        int x = cur.X + dx[dir];
        int y = cur.Y + dy[dir];
        if( x<0|| y<0|| x>=h|| y>=w ){
            end = time[cur.X][cur.Y]+1;
            break;
        }
        //디버거 없이 여기 어케만들지
        //불이 안지난곳은 못지나감
        //이번에 xy로 이동하는 시간이 firetime보다 느리면
        if( (firetime[x][y] != -1 && time[cur.X][cur.Y]+1 >= firetime[x][y]) 
        //                                               ~~^
        || time[x][y] > -1 || arr[x][y] == '#' ) continue;// vis,벽

        time[x][y] = time[cur.X][cur.Y] + 1;
        Q.push({x,y});
    }
    //출구 찾았으면 while문 브레이크
    if( end != -1 ) break;
}


//출력
if( end == -1 )
cout<<"IMPOSSIBLE\n";
else
cout<<end<<"\n";



//다음탐색을 위해 큐비우기
while( !Q.empty() ) Q.pop();
while( !fire.empty() ) fire.pop();

}

    return 0;
}