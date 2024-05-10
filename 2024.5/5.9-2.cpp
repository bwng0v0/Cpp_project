//https://www.acmicpc.net/problem/5014 스타트링크
#include <iostream>
#include <queue>
#define X first
#define Y second
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int vis[10000001];
queue<pair<int,int>> Q;
pair<int,int> cur;

int main(){
fastio

int f,n,k,u,d; cin>>f>>n>>k>>u>>d;
int dy[] = {u,-d};

vis[n] = 1;
Q.push({0,n});

while( !Q.empty() ){

cur = Q.front();
Q.pop();

if( cur.Y==k ){ cout<<cur.X; return 0; }

for( int dir=0; dir<2; dir++ ){
    int y = cur.Y + dy[dir];
    if( y<1 || y>f || vis[y] ) continue;//조건식 순서
    vis[y] = 1;
    Q.push({cur.X+1, y});
    }

}

cout<<"use the stairs";
    return 0;
}