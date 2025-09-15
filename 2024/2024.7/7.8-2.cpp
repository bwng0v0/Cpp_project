//https://www.acmicpc.net/problem/2606 바이러스
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int a,b,n; cin>>n;
vector<vector<int>> vec(n+1);
for( int i=0; i<n+1; i++ ) vec[0].push_back(0);


cin>>n;
for( int i=0; i<n; i++ ){
    cin>>a>>b;
    vec[a].push_back(b);
    vec[b].push_back(a);
}


queue<int> Q;
Q.push(1);
while( !Q.empty() ){
    int cur = Q.front();
    Q.pop();
    vec[0][cur] = 1;

    for( int x : vec[cur] )
    Q.push(x);

    vec[cur].clear();
}

int sum = 0;
for( int x : vec[0] ) sum += x;
cout<<sum-1;


    return 0;
}