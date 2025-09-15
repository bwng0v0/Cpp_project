//https://www.acmicpc.net/problem/1487 물건 팔기
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int n; cin>>n;
int arr[n][2];
int res = 0, max = 0;

for( int i=0; i<n; i++ )
cin>>arr[i][0]>>arr[i][1];

int price,sum;
for( int i=0; i<n; i++ ){
    price = arr[i][0];
    sum = 0;
for( int j=0; j<n; j++ ){
    if( arr[j][0] >= price && 0 < (price - arr[j][1]) )
    sum += (price - arr[j][1]);

}
    if( max < sum ){ max = sum; res = price; }
    if( max == sum && price < res ) res = price; 
}
cout<<res;

    return 0;
}