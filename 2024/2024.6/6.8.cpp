//https://www.acmicpc.net/problem/2523 별 찍기 - 13
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int n; cin>>n;
for( int i=1; i<=n; i++ ){
    for( int j=1; j<=i; j++ )
    cout<<"*";
    cout<<"\n";
}
for( int i=n-1; i>0; i-- ){
    for( int j=i; j>0; j-- )
    cout<<"*";
    cout<<"\n";
}

    return 0;
}