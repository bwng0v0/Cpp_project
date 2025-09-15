//https://www.acmicpc.net/problem/9465 스티커
#include <iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

inline int max(int a, int b){ return a>b?a:b; }
int arr[2][100001];
int d[2][100001];

int main(){
fastio

int T; cin>>T;
for( int t=0; t<T; t++ ){
    int n; cin>>n;
    // int arr[2][n+1] {};
    // int d[2][n+1] {};

    for( int i=0; i<2; i++ ){
        for( int j=1; j<n+1; j++ ){
            cin>>arr[i][j];
        }
    }
    //입력
    

    d[0][1] = arr[0][1];
    d[1][1] = arr[1][1];
    for( int i=2; i<n+1; i++ ){
        d[0][i] = max(d[1][i-1], d[1][i-2/*인덱스 접근 항상주의*/]) + arr[0][i];
        d[1][i] = max(d[0][i-1], d[0][i-2]) + arr[1][i];
    }

    cout<<max(d[0][n], d[1][n])<<"\n";
}


    return 0;
}