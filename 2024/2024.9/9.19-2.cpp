//
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define X first
#define Y second
using namespace std;

int main(){
fastio

int n,a,max=0;
cin>>n;
for( int i=0; i<n; i++ ){
    cin>>a;
    if( a > max ) max = a;
}
cout<<max;

    return 0;
}