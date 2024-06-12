//https://www.acmicpc.net/problem/24417 알고리즘 수업 - 피보나치 수 2
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int n; cin>>n;
int a,b;
a = 1;
b = 1;
for( int i=3; i<=n; i++ ){
    int cur = (a + b) % 1000000007;
    a = b;
    b = cur;
}
cout<<b<<" "<<n-2;

    return 0;
}