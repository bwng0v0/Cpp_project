//https://www.acmicpc.net/problem/31962 등교
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int n,x,b,e,res=-1; cin>>n>>x;
for( int i=0; i<n; i++ ){
    cin>>b>>e;
    if( b+e <= x && b >= res ) res = b;
}
cout<<res;

    return 0;
}