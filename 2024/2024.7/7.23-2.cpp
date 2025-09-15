//https://www.acmicpc.net/problem/1238 파티
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define X first
#define Y second
using namespace std;
const int INF = 0x3f3f3f3f;

int main(){
fastio

int V,E,start; cin>>V>>E>>start;
vector<pair<int,int>> gr[V+1];
for( int i=0; i<E; i++ ){
    int a,b,w; cin>>a>>b>>w;
    gr[a].push_back({w,b});
}

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int d[V+1]; for( int& x : d ) x = INF;

d[start] = 0;
pq.push({d[start],start});
while(!pq.empty()){
    pair<int,int> cur = pq.top(); pq.pop();
    
    for( auto next : gr[cur.Y] )
    if( d[next.Y] > d[cur.Y]+next.X ){
        d[next.Y] = d[cur.Y]+next.X;
        pq.push({d[next.Y],next.Y});
    }
}
//돌아가는 길

int res[V+1];
for(int i=0; i<=V; i++) res[i] = d[i];

//오는길 d,gr,pq는 그대로 다시씀
for( int i=1; i<=V; i++ ){
    for( int& x : d ) x = INF;
    d[i] = 0;
    pq.push({d[i],i});

    while( !pq.empty() ){
        auto cur = pq.top(); pq.pop();

        for( auto next : gr[cur.Y] )
        if( d[next.Y] > d[cur.Y]+next.X ){
            d[next.Y] = d[cur.Y]+next.X;
            pq.push({d[next.Y],next.Y});
        }
    }

    res[i] += d[start];    
} 

int max = 0;
for( int i=1; i<=V; i++ )
if( max < res[i] ) max = res[i];

cout<<max;

    return 0;
}