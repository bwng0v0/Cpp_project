//https://www.acmicpc.net/problem/1753 최단경로
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define X first
#define Y second
const int INF = 0x3f3f3f3f;

int main(){
fastio

int V,E,start; cin>>V>>E>>start;
vector<vector<pair<int,int>>> gr(V+1);
for( int i=0; i<E; i++ ){
    int u,v,w; cin>>u>>v>>w;
    gr[u].push_back({w,v});
}
//입력

vector<int> d(V+1);
for( int i=1; i<=V; i++ ) d[i] = INF;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

d[start] = 0;
pq.push({d[start],start});

while( !pq.empty() ){
    pair<int,int> cur = pq.top(); pq.pop();
    
    for( pair<int,int> next : gr[cur.Y] ){
        if( d[next.Y] > d[cur.Y]+next.X ){
            d[next.Y] = d[cur.Y]+next.X;
            pq.push({d[next.Y],next.Y});
        }
    }
}

for( int i=1; i<=V; i++ )
if( d[i] == INF ) cout<<"INF\n";
else cout<<d[i]<<"\n";

    return 0;
}