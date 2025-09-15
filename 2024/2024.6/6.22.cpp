//https://www.acmicpc.net/problem/2750 수 정렬하기
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int n; cin>>n;
int arr[n];
for( int i=0; i<n; i++ ){
    cin>>arr[i];
}

sort(arr,arr+n);

for( int x : arr ) cout<<x<<"\n";

    return 0;
}