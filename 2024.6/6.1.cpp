//https://www.acmicpc.net/problem/2693 N번째 큰 수
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int arr[10];
int n; cin>>n;
for( int i=0; i<n; i++ ){
    for( int j=0; j<10; j++ ) cin>>arr[j];
    sort(arr,arr+10);
    cout<<arr[7]<<"\n";
}

    return 0;
}