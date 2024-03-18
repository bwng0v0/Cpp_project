#include <iostream>
//https://www.acmicpc.net/problem/15657 N과M (8)
using namespace std;

int N,M;
int num[10];
int arr[10];

void backtracking( int K ){
    if( K == M ){
        for( int i=0; i<M; i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }

    for( int i=1; i<=N; i++ ){
        if( arr[K-1] <= num[i] ){
            arr[K] = num[i];
            backtracking(K+1);
        }
    }
}
int main(){

cin>>N>>M;
for( int i=1; i<=N; i++ ){
    cin>>num[i];
}

//사전순으로 출력하기위해 정렬
for( int i=0; i<N; i++ ){ //반복횟수
    for( int j=1; j<=N; j++ ){ // 한 사이클
        if( num[j] < num[j-1] ){
            int tmp = num[j];
            num[j] = num[j-1];
            num[j-1] = tmp;
        }
    }
}

backtracking(0);

    return 0;
}