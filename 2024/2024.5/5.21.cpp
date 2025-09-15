//https://www.acmicpc.net/problem/10815 숫자 카드
#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int n,m;
cin>>n;
int arr[n];
for( int i=0; i<n; i++ ) cin>>arr[i];
cin>>m;
int card[m];
for( int i=0; i<m; i++ ) cin>>card[i];

sort(arr,arr+n);

for( int i=0; i<m; i++ ){
    if( binary_search(arr,arr+n,card[i]) ) cout<<"1 ";
    else cout<<"0 ";
}

    return 0;
}