//https://www.acmicpc.net/problem/27965 N결수
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

long long int n,k; cin>>n>>k;
long long int num = 0;
for( long long int i=1; i<=n; i++ ){
    int size = 1;
    int x = i;
    while( x > 9 ){
        x /= 10; size += 1;
    }
    while(--size){
        num *= 10;
    }
    num += i; num %= k;
    // if( num < 0 ){ cout<<"over "<<i; return 0; }
}
cout<<num;

    return 0;
}