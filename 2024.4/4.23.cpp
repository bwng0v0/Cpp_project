//https://www.acmicpc.net/problem/2435 기상청 인턴 신현수
#include <iostream>
#include <string>
using namespace std;

int main(){
ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int n,k; cin>>n>>k;
int arr[n] {};
cin>>arr[0];
for( int i=1; i<n; i++ ){
    cin>>arr[i];
    arr[i] += arr[i-1];
}

int sarr[n-k+1] {};
int max = -99999999;
for( int i=0; i<n-k+1; i++ ){
    sarr[i] = arr[i+k-1] - arr[i-1];
    if( max < sarr[i] )
    max = sarr[i];
}

cout<<max;

    return 0;
}