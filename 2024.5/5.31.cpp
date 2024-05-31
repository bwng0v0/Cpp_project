//https://www.acmicpc.net/problem/1100 하얀 칸
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int res = 0;
string arr[8];
for( int i=0; i<8; i++ ){
    cin>>arr[i];

    if(i%2==0)
    for( int j=0; j<8; j++ ){
        if( j%2==0 && arr[i][j] == 'F' ) res += 1;
    }
    else
    for( int j=0; j<8; j++ ){
        if( j%2==1 && arr[i][j] == 'F' ) res += 1;
    }
}
cout<<res;
    return 0;
}