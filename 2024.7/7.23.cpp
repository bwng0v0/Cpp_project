//https://www.acmicpc.net/problem/14938 서강그라운드
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define X first
#define Y second
using namespace std;
const int INF = 0x3f3f3f3f;

int main(){
fastio

int V,M,E; cin>>V>>M>>E;
int item[V+1];
for( int i=1; i<=V; i++ ) cin>>item[i];
vector<pair<int,int>> gr[V+1];
for( int i=0; i<E; i++ ){
    int a,b,w; cin>>a>>b>>w;
    gr[a].push_back({w,b});
    gr[b].push_back({w,a});
}


int d[V+1];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int max = 0;

for( int i=1; i<=V; i++ ){//모든 정점에서 다익스트라 돌려봄
    int sum = 0;
    for( int& x : d ) x = INF;
    d[i] = 0;
    pq.push({d[i],i});

    while(!pq.empty()){
        pair<int,int> cur = pq.top(); pq.pop();

        for( pair<int,int> next : gr[cur.Y] ){
            if( d[next.Y] > d[cur.Y] + next.X ){//d[next.Y] > cur.X + next.X랑 헷갈리지 말것
                d[next.Y] = d[cur.Y] + next.X;
                pq.push({d[next.Y],next.Y});
            }
        }
    }

    for( int j=1; j<=V; j++ )
    if( M >= d[j] ) sum += item[j];

    if( max < sum ) max = sum;
}
cout<<max;

    return 0;
}