//https://www.acmicpc.net/problem/1916 최소비용 구하기
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define X first
#define Y second
#define INF 987654321
using namespace std;

int main(){
fastio

//도시개수 버스개수
int N,M;
cin>>N>>M;

//gr[i] 는 i번째 도시에서 갈수있는 {도시, 비용}
vector<vector<pair<int,int>>> gr(N+1);

for(int i=0; i<M; i++){
    //출발 도착 비용
    int a,b,x;
    cin>>a>>b>>x;
    gr[a].push_back({x,b});
}
//시작, 도착
int start,end; cin>>start>>end;
//입력 끝

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int map[N+1]; for(int i=1; i<=N; i++) map[i] = INF; //배열 생성/초기화


map[start] = 0;
pq.push({0,start});//start로 0거리 가는걸로 시작

while(!pq.empty()){
    //가장 가까운거 뽑아서
    pair<int,int> cur = pq.top();
    pq.pop();
    
    //######### 이거때문이라고?
    if (cur.X > map[cur.Y]) continue;//시간개선 - 현재 cur까지 오는길 자체가 기존보다 느린경우 컨티뉴

    //cur과 이어진곳 모두 추가
    for(pair<int,int> p : gr[cur.Y]){
        if(map[p.Y] > cur.X+p.X){//cur로부터 이어진 길 p.Y들에 대해, 여기서부터 가는 길이 빠르다면 갱신
            map[p.Y] = cur.X+p.X;
            pq.push({(cur.X+p.X), p.Y});//cur까지 오는길 + p.Y로 가는길 만큼 걸려서 p.Y로 가는길 추가
        }
        
    }
}

cout<<map[end];

    return 0;
}