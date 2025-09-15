//https://www.acmicpc.net/problem/15095 Nine Knights
#include <bits/stdc++.h>
#define X first
#define Y second
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int dx[8] = {-2,-2,-1,-1,1,1,2,2};
int dy[8] = {-1,1,-2,2,-2,2,-1,1};
vector<pair<int,int>> vec;
int n = 5;
char arr[5][5];
for( int i=0; i<5; i++ ){
    for( int j=0; j<5; j++ ){
        cin>>arr[i][j];
        if( arr[i][j] == 'k' ) vec.push_back({i,j});
    }
}

if( vec.size() != 9 ){ cout<<"invalid"; return 0; };
for( int i=0; i<vec.size(); i++ ){
    for( int dir=0; dir<8; dir++ ){
        int x = vec[i].X + dx[dir];
        int y = vec[i].Y + dy[dir];
        if( x<0|| y<0|| x>=5|| y>=5 ) continue;
        if( arr[x][y] == 'k' ){ cout<<"invalid"; return 0; }
    }
}

cout<<"valid";
    return 0;
}