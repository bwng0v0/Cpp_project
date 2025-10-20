//https://www.acmicpc.net/problem/14699 관악산 등산
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define X first
#define Y second
typedef long long ll;
using namespace std;


int main(){
fastio

int N,M;
cin>>N>>M;
int H[N+1];
vector<pair<int,int>> vec;
for(int i=1; i<=N; i++){
    cin>>H[i];
    vec.push_back({H[i], i});//높이, 인덱스
}
vector<vector<int>> gr(N+1);
for(int i=0; i<M; i++){
    int a,b;
    cin>>a>>b;
    //오르막길로 생성 -> 나중에 dp할때 이어진 윗길만 볼거임
    if( H[a] > H[b] ){
        gr[b].push_back(a);
    }else{
        gr[a].push_back(b);
    }
}
//입력 끝

//모두 1로 시작
int res[N+1];
fill(res, res+N+1, 1);

sort(vec.begin(), vec.end(), greater<>());

for(auto cur : vec){//cur.X는 높이, cur.Y는 인덱스
    for(int top : gr[cur.Y]){//top은 cur과 이어진 모든 윗 노드들
        if(res[cur.Y] < res[top]+1){
            res[cur.Y] = res[top]+1;
        }
    }
}

for(int i=1; i<=N; i++){
    cout<<res[i]<<"\n";
}


    return 0;
}