//https://www.acmicpc.net/problem/7795 먹을 것인가 먹힐 것인가
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

//트리 , 우선순위 큐 쓰면 단축가능 -> 아 정렬써도됨
//일단 브루트포싱 -> 시간초과 
int main(){
fastio

int A[20000], B[20000];

int T; cin>>T;
for( int t=0; t<T; t++ ){
    int n,m; cin>>n>>m;
    for( int i=0; i<n; i++ ) cin>>A[i];
    for( int i=0; i<m; i++ ) cin>>B[i];
    sort(A,A+n);
    sort(B,B+m);

    int cnt = 0;
    for( int i=0; i<n; i++ ){
        for( int j=0; j<m; j++ ){
            if( A[i] > B[j] ) cnt += 1;
            else continue;
        }
    }

    cout<<cnt<<"\n";
}

    return 0;
}