//https://www.acmicpc.net/problem/1260 DFS와 BFS
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int v,e,start; cin>>v>>e>>start;
vector<vector<int>> vec;
for( int i=0; i<=v; i++ )
    vec.push_back({});

int a,b;
for( int i=0; i<e; i++ ){
    cin>>a>>b;
    vec[a].push_back(b);
    vec[b].push_back(a);
}

//정렬
for( int i=1; i<=v; i++ ) sort(vec[i].begin(),vec[i].end());

int vis[v+1] {}; 
stack<int> st;
st.push(start);
//DFS
while( !st.empty() ){
    int cur = st.top();
    if( !vis[cur] ){ cout<<cur<<" "; vis[cur] = 1;}
    st.pop();
    for( int i=vec[cur].size()-1; i>=0; i-- ){
        int x = vec[cur][i];
        if( vis[x] ) continue;
        st.push(x);
    }
}
cout<<"\n";



for( int i=0; i<v+1; i++ ) vis[i]=0;
queue<int> Q;
Q.push(start);
//BFS
while( !Q.empty() ){
    int cur = Q.front();
    if( !vis[cur] ){ cout<<cur<<" "; vis[cur] = 1;}
    Q.pop();
    for( int i=0; i<vec[cur].size(); i++ ){
        int x = vec[cur][i];
        if( vis[x] ) continue;
        Q.push(x);
    }
}

    return 0;
}