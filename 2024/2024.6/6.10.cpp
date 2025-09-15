//https://www.acmicpc.net/problem/14467 소가 길을 건너간 이유 1
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;


int main(){
fastio

int cow[11];
for( int i=1; i<=10; i++ ) cow[i] = -1;
int n; cin>>n;
int res = 0;
for( int i; i<n; i++ ){
    int num,dir;
    cin>>num>>dir;
    if( cow[num] == -1 ){
        cow[num] = dir;
    }else if( cow[num] != dir ){
        cow[num] = dir;
        res += 1;
    }
}
cout<<res;

    return 0;
}