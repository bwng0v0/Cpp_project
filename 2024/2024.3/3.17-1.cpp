//https://www.acmicpc.net/problem/15650 N과 M (2)
#include <iostream>
using namespace std;

int N,M;
int arr[10];
bool is_used[10];

void backtracking(int K){
    if( K == M ){
        for( int i=0; i<M; i++ ){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    
    for( int i=1; i<=N; i++ ){
        if( is_used[i]==0 && arr[K-1]<i ){ //조건추가 전 자리수보다 선택하려는 수가 크다면 
        // 어 근데 원래 윗줄 K=1일때 인덱스 잘못건드리는데 ㅋㅋ
            is_used[i] = 1;
            arr[K] = i;
            backtracking(K+1);
            is_used[i] = 0;
        }
    }
}
int main(){

cin>>N>>M;
backtracking(0);

    return 0;
}