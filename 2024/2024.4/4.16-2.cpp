//https://www.acmicpc.net/problem/1932 정수 삼각형
#include <iostream>
using namespace std;
int main(){
ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int n; cin>>n;
int arr[n][n] = {};
int index = 0;
cin>>arr[0][0];
for( int i=1; i<n; i++ ){
    for( int j=0; j<=i; j++ ){
        cin>>arr[i][j];
        
        int left =  j-1;
        if( left < 0 ) left = j;
        int right = j;
        if( right > i-1 ) left = j-1;
        arr[i][j] += (arr[i-1][left]>arr[i-1][right])? arr[i-1][left] : arr[i-1][right];
    }
}

int max = 0;
for( int i=0; i<n; i++ )
if( arr[n-1][i] > max ) max = arr[n-1][i];

cout<<max;

    return 0;
}