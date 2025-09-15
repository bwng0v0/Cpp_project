//https://www.acmicpc.net/problem/17835 면접보는 승범이네
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define X first
#define Y second
using namespace std;
const unsigned long long int INF = 9223372036854775807;


unsigned long long int d[100010];
vector<pair<long long,long long>> gr[100010];
int arr[100010];
bool vis[100010];
priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;

int main(){
fastio

int V,E,K; cin>>V>>E>>K;
for( int i=0; i<E; i++ ){
    int a,b,w; cin>>a>>b>>w;
    gr[b].push_back({w,a});
}
 for( int i=0; i<K; i++ ) cin>>arr[i]; //면접장
//입력



 for( int i=1; i<=V; i++ ) d[i] = INF; 


for( int start=0; start<K ; start++ ){
    int st = arr[start];
    d[st] = 0 ;
    pq.push({d[st],st});
}
    while( !pq.empty() ){
        auto cur = pq.top(); pq.pop();
        if( vis[cur.Y] ) continue;
        vis[cur.Y] = true;
        
        for( auto next : gr[cur.Y] )
        if( d[next.Y] > d[cur.Y] + next.X ){
            d[next.Y] = d[cur.Y] + next.X;
            pq.push({d[next.Y],next.Y});
        }
    }

long long max=0, maxi=0;
for( int i=1; i<=V; i++ )
if( d[i] > max ){ max = d[i]; maxi = i; }

cout<<maxi<<"\n"<<max;
//도시
//거리

    return 0;
}