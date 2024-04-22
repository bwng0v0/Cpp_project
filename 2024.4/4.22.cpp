//https://www.acmicpc.net/problem/2851 슈퍼 마리오
#include <iostream>
#include <cmath>
using namespace std;

int main(){
ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int arr[10] {};
cin>>arr[0];
for( int i=1; i<10; i++ ){
    cin>>arr[i];
    arr[i] += arr[i-1];
}

int res = 0;
for( int i=0; i<10; i++ ){
    if( abs(res-100) >= abs(arr[i]-100) )
    res = arr[i];
}

cout<<res;
    return 0;
}