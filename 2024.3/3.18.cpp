#include <iostream>
//https://www.acmicpc.net/problem/15652 N과M (4)
using namespace std;

int N,M;
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
        if( arr[K-1] <= i ){
        arr[K] = i;
        backtracking(K+1);
        }
    }
}
int main(){

cin>>N>>M;
backtracking(0);

    return 0;
}