//https://www.acmicpc.net/problem/1697 숨바꼭질
#include <iostream>
#include <queue>
#define X first
#define Y second
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

queue<pair<int,int>> Q;
pair<int,int> cur;
int vis[100001];
int dy[] = {1,-1,2};


int main(){
fastio

int n,k; cin>>n>>k;

Q.push({0,n});
if( n==k ){ cout<<0; return 0; }

while(true){
    cur = Q.front();
    Q.pop();
    int x = cur.X + 1;

    for( int dir=0; dir<3; dir++ ){
        int y = cur.Y + dy[dir]; if( dir==2 ) y = cur.Y * 2;
        if( y == k ){ cout<<x; return 0; }
        if( y>100000 || vis[y] ) continue;
        vis[y] = 1;
        Q.push({x, y});
    }

}

    return 0;
}