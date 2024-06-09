//https://www.acmicpc.net/problem/3058 짝수를 찾아라
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int n; cin>>n;
int num;
for( int i=0; i<n; i++ ){
    int sum = 0;
    int min = 999999999;
    for( int j=0; j<7; j++ ){
        cin>>num;
        if( num%2==0 ){
            sum += num;
            if( num < min ) min = num;
        }
    }
    cout<<sum<<" "<<min<<"\n";
}

    return 0;
}