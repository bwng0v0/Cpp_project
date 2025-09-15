//https://www.acmicpc.net/problem/1268 임시 반장 정하기
#include <iostream>
using namespace std;

int main(){

int n; cin>>n;
int arr[n][5];
for( int i=0; i<n; i++ ){
    for( int j=0; j<5; j++ ){
        cin>>arr[i][j];
    }
}

//각각 비교 그리고 0과1로 저장
int res[n][n] = {};
for( int k=0; k<5; k++ ){

for( int i=0; i<n; i++){
    for( int j=0; j<n; j++ ){
        if( arr[i][k] == arr[j][k] ){
            res[i][j] = 1;
        }
    }
}

}


int max = 0;
int maxi = 0;
for( int i=0; i<n; i++ ){//각 같은반이었던 친구 수 세고 최대값이라면저장

    int cnt = -1;
    for( int j=0; j<n; j++ ){
        cnt += res[i][j];
    }
    
    if( max<cnt ){
        max = cnt;
        maxi= i;
    }

}

cout<<maxi+1;//인덱스를 학생번호로

    return 0;
}