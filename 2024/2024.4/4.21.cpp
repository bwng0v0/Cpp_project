//https://www.acmicpc.net/problem/2003 수들의 합 2
#include <iostream>
using namespace std;

int main(){
ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int n,m;cin>>n>>m;
int arr[n+1] {};
for( int i=1; i<=n; i++ ){
    cin>>arr[i];
    arr[i] += arr[i-1];
}

int res = 0;
for( int s=1; s<=n; s++ ){//합 범위
for( int i=1; i<=n-s+1; i++ ){//시작인덱스

//i부터 s개의 합
int cur = arr[i+s-1] - arr[i-1];
if( cur == m )
res += 1;

}
}

cout<<res;

    return 0;
}