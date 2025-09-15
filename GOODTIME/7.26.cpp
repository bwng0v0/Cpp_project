//https://www.acmicpc.net/problem/14699 관악산 등산
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define X first
#define Y second
using namespace std;

int main(){
fastio

int N,M; cin>>N>>M;
int h[N+1];
vector<int> gr[N+1];
for( int i=1; i<=N; i++ ) cin>>h[i];
for( int i=0; i<M; i++ ){
    int a,b; cin>>a>>b;
    gr[a].push_back(b);
    gr[b].push_back(a);
}

queue<int> Q;
bool vis[N+1];

for( int i=1; i<=N; i++ ){
    Q.push(i);
    int cnt = 1;
    fill(vis,vis+N+1,false);

    while( !Q.empty() ){
        int cur = Q.front(); Q.pop();

        for( int next : gr[cur] ){
            if( h[next] <= h[cur] ) continue;
            if( vis[next] ) continue;
            
            vis[next] = 1;
            cnt += 1;
            Q.push(next);
        }
    }

    cout<<cnt<<"\n";
}

    return 0;
}