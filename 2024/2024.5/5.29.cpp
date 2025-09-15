//https://www.acmicpc.net/problem/28224 Final Price
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int n; cin>>n;
int x = 0;
for( int i=0; i<n; i++ ){
    int a;
    cin>>a; x += a;
}
cout<<x;

    return 0;
}