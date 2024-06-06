//https://www.acmicpc.net/problem/21613 Silent Auction
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int n; cin>>n;
string name,s; int max=0,x;
for( int i=0; i<n; i++ ){
    cin>>s>>x;
    if( x > max ){ name = s; max = x; }
}
cout<<name;

    return 0;
}