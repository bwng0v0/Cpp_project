//https://www.acmicpc.net/problem/10282 해킹
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define X first
#define Y second
using namespace std;
using ll = long long;

const ll INF = 0x3f3f3f3f;
ll d[10001];
priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;

int main(){
fastio



int T; cin>>T;
for( int t=0; t<T; t++ ){
    vector<pair<ll,ll>> gr[10001];
    
    int V,E,st; cin>>V>>E>>st;
    for( int i=0; i<E; i++ ){
        int a,b,s; cin>>a>>b>>s;
        gr[b].push_back({s,a});
    }
    //입력

    fill(d,d+10001,INF);
    d[st] = 0;
    pq.push({d[st],st});

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();

        for( auto next : gr[cur.Y] )
        if( d[next.Y] > d[cur.Y] + next.X ){
            d[next.Y] = d[cur.Y] + next.X;
            pq.push({d[next.Y],next.Y});
        }
    }
    //d 구하기(다익스트라)

    //d중에 INF아닌 최대값
    ll max = -1, cnt = 0;
    for( int i=1; i<=V; i++ )
    if( d[i] != INF ){ cnt += 1;
    if( max < d[i] ) max = d[i];
    }

    cout<<cnt<<" "<<max<<"\n";
}

    return 0;
}