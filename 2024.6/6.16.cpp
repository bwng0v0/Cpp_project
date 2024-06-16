//https://www.acmicpc.net/problem/5545 최고의 피자
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int n; cin>>n;
int A,B; cin>>A>>B;
int C; cin>>C;
int arr[n];
for( int i=0; i<n; i++ ){
    cin>>arr[i];
}

sort(arr,arr+n,[](int a, int b){return a>b;});

int max = C/A; // 도우열량/가격
int sum = C;
int price = A;
for( int i=0; i<n; i++ ){
    sum += arr[i];
    price += B;
    if( sum/price > max ) max = sum/price;
}

cout<<max;

    return 0;
}