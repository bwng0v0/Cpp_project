//https://www.acmicpc.net/problem/23323 황소 다마고치
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int T; cin>>T;
for( int t=0; t<T; t++ ){

long long int n,m,day=0; cin>>n>>m;

while(n != 0){
    // if( m > 0 ){ m -= 1; n += 1; }
    n /= 2;
    day += 1;
}
cout<<day+m<<"\n";


}

    return 0;
}