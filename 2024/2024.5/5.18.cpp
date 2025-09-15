//https://www.acmicpc.net/problem/24479 알고리즘 수업 - 깊이 우선 탐색 1
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int v,e,start; cin>>v>>e>>start;
vector<vector<int>> vec;
for( int i=0; i<v+1; i++ ) vec.push_back({});
for( int i=0; i<e; i++ ){
    int a,b; cin>>a>>b;
    vec[a].push_back(b);
    vec[b].push_back(a);
}
for( int i=0; i<v+1; i++ ) sort(vec[i].rbegin(),vec[i].rend());
//입력

stack<int> st;
int cur;
int vis[v+1] {};
st.push(start);
int cnt = 1;

while( !st.empty() ){
    cur = st.top();
    if(vis[cur]==0){ vis[cur] = cnt; cnt+=1;}
    st.pop();
    for( int i=0; i<vec[cur].size(); i++ ){
        if( vis[vec[cur][i]] ) continue;
        st.push(vec[cur][i]);
    }
}

for( int i=1; i<=v; i++ )
cout<<vis[i]<<"\n";



    return 0;
}