//https://www.acmicpc.net/problem/3258 컴포트
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int n,z,m; cin>>n>>z>>m;
z %= n;
int arr[n] {};
for( int i=0; i<m; i++ ){
    int x; cin>>x;
    x %= n;
    arr[x] = 1;
}

int pos,cnt;
for( int k=1; k<n; k++ ){
pos = 1; cnt = 1;
while(true){
    //k만큼 점프하고
    pos += k; cnt += 1;
    pos %= n;
    //z라면
    if( pos == z ){ cout<<k; return 0; }
    //장애물이라면 (배열값이 1)
    if( arr[pos] ) break;
    if( cnt > 100000 ) break;
}
}

    return 0;
}