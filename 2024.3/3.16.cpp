//https://www.acmicpc.net/problem/15649 N과 M (1)
#include <iostream>
using namespace std;

int N,M;
int arr[10];
bool is_used[10];

void backtracking(int K){
    if( K == M ){ //자릿수가 꽉찼다면 출력하고 리턴함
        for( int i=0; i<M; i++ ){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;// !반환 되고나서 첫번째 자릿수부터 다시 시작하는게 아니라 for문 사이클이 넘어감
    }

    for( int i=1; i<=N; i++ ){// 1부터N까지 안쓴 수를 구별해서 채워넣음
        if( is_used[i] == 0 ){
        /* i가 안쓴 수라면 K번째 자릿수를 i로 채우고 다음 자릿수도 이함수로 채움
            만약 자릿수가 다찼다면 출력함 그리고 해당자리에 사용안한 수가 있다면 사용후 출력
            !해당 자리에 들어갈수있는 모든 수를 사용했었다면 그 전 자릿수의 for문이 한사이클 돌아감 == 123으로 12의 경우가 다돌았다면 13으로 감

        */
        arr[K] = i;
        is_used[i] = 1;
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