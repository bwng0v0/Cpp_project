//https://www.acmicpc.net/problem/11722 가장 긴 감소하는 부분 수열
#include <iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int n; cin>>n;
int num[n+1] {};
int len[n+1] {};
for( int i=1; i<n+1; i++ ) cin>>num[i];


int max {0};
for( int i=1; i<n+1; i++ ){
    for( int j=0; j<i; j++ ){
        if( num[j] > num[i] && len[j] > len[i] )
        len[i] = len[j];
    }
    
    len[i] += 1;
    if( max < len[i] ) max = len[i];
}

cout<<max;

    return 0;
}