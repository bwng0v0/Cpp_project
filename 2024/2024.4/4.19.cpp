//https://www.acmicpc.net/problem/11660 구간 합 구하기 5
//누적 합 알고리즘
//sum((r2,c2) - (r1,c1)) = prefix_sum[r2 + 1][c2 + 1] - prefix_sum[r1][c2 + 1] - prefix_sum[r2 + 1][c1] + prefix[r1][c1]
#include <iostream>
using namespace std;

int main(){
ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int n,m; cin>>n>>m;
int arr[n][n] {};
int sum[n][n] {};
for( int i=0; i<n; i++ ){
    for( int j=0; j<n; j++ ){
        cin>>arr[i][j];
    }
}

//합배열 저장
sum[0][0] = arr[0][0];
for( int i=1; i<n; i++ ){
    sum[i][0] = sum[i-1][0] + arr[i][0];
    sum[0][i] = sum[0][i-1] + arr[0][i];
}
for( int i=1; i<n; i++ ){
    for( int j=1; j<n; j++ ){
        sum[i][j] = sum[i-1][j] +sum[i][j-1] +arr[i][j]  -sum[i-1][j-1];
    }
}


for( int i=0; i<m; i++ ){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    x1-=1; y1-=1; x2-=1; y2-=1;
    //범위아웃 예외처리
    int res = {sum[x2][y2] 
    -(x1-1<0? 0:sum[x1-1][y2])
    -(y1-1<0? 0:sum[x2][y1-1])
    +(x1-1<0||y1-1<0? 0:sum[x1-1][y1-1])
    };
    cout<<res<<"\n";
}
    return 0;
}