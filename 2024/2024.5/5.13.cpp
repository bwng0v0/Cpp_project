//https://www.acmicpc.net/problem/2579 계단 오르기
#include <iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int n; cin>>n;
int arr[n];
int d[n] {};
for( int i=0; i<n; i++ )
cin>>arr[i];

d[0] = arr[0];
d[1] = arr[0] + arr[1];
d[2] = max(arr[0],arr[1]) + arr[2];

for( int i=3; i<n; i++ ){
    d[i] = max(arr[i-1]+d[i-3], d[i-2]) + arr[i];
}
cout<<d[n-1];

// 1 2 3 4
//   0   0

// 0 0   0
// 0   0 0


    return 0;
}