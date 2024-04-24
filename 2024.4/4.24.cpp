//https://www.acmicpc.net/problem/2583 영역 구하기
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int n,m,k; cin>>n>>m>>k;
//int arr[n][m] {};
int vis[n][m] {};
for( int K=0; K<k; K++ ){
    int x1,y1,x2,y2; cin>>y1>>x1>>y2>>x2;
    for( int i=x1; i<x2; i++ ){
        for( int j=y1; j<y2; j++ ){
            //arr[i][j] = 1;
            vis[i][j] = 1;
        }
    }
}

queue<pair<int,int>> Q;
int xarr[4] = {1,0,-1,0};
int yarr[4] = {0,1,0,-1};
int cnt = 0;
vector<int> vec;

for( int i=0; i<n; i++ ){
for( int j=0; j<m; j++ ){
    //찾으면 탐색 시작
    if( vis[i][j] == 0 ){
        vis[i][j] = 1;
        Q.push({i,j});
        int size = 0;
        while( !Q.empty() ){
            pair<int,int> cur = Q.front();
            Q.pop(); size += 1;
            for( int dir=0; dir<4; dir++ ){
                int x = cur.first + xarr[dir];
                int y = cur.second + yarr[dir];
                if( x < 0 || y<0 || x>=n || y>=m )continue;
                if( vis[x][y] == 1 )continue;
                vis[x][y] = 1;
                Q.push({x,y});
            }
        }

        cnt += 1;
        vec.push_back(size);
    }
}
}

cout<<cnt<<"\n";
sort(vec.begin(),vec.end());
for( int tmp : vec )
cout<<tmp<<" ";

    return 0;
}