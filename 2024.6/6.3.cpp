//https://www.acmicpc.net/problem/1292 쉽게 푸는 문제
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int sum = 0, cnt = 0;
int from,to; cin>>from>>to;
for( int i=1; ; i++ ){
    for( int j=0; j<i; j++ ){
        sum += i;
        cnt += 1;
        if( cnt == from-1 ){ sum = 0; }
        if( cnt == to )  { cout<<sum; return 0; }
    }
}



    return 0;
}