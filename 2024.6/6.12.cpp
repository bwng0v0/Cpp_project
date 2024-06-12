//https://www.acmicpc.net/problem/11971 속도 위반
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int max = 0;
int road[100];
int n,m; cin>>n>>m;
int cnt = 0;
for( int i=0; i<n; i++ ){
    int len,limit; cin>>len>>limit;
    for( int j=0; j<len; j++ ){
        road[cnt++] = limit;
    }
}
cnt = 0;
for( int i=0; i<m; i++ ){
    int len,speed; cin>>len>>speed;
    for( int j=0; j<len; j++ ){
        if( speed - road[cnt] > max ) max = speed - road[cnt];
        cnt += 1;
    }
}
cout<<max;
    return 0;
}