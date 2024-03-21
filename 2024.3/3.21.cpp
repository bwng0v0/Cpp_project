#include <iostream>
//https://www.acmicpc.net/problem/15663 N과M (9)
using namespace std;

int N,M;
int arr[10];
int num[10];
bool is_used[10];

int printed[100000][10];//아니 이거라고?
int print_cnt;
int same;

void bt( int K ){
    if( K==M ){

        //출력했는지 검사
        for( int i=0; i<print_cnt; i++ ){
            same = 1;

            for( int j=0; j<M; j++ ){ //한줄검사
                if( arr[j] != printed[i][j] ){
                    same = 0;
                    break;
                }
            }

            if(same == 1)
            return;
        }
        //검사후 출력
        for(int i=0; i<M; i++){
        cout<<arr[i]<<' ';
        printed[print_cnt][i] = arr[i];
        }

        cout<<'\n';
        print_cnt += 1;
        return;
    }

    for( int i=0; i<N; i++ ){
        if( is_used[i]==0 ){ 
            arr[K] = num[i];
            is_used[i] = 1;

            bt(K+1);
            is_used[i] = 0;
        }
    }
}
int main(){

cin>>N>>M;
for(int i=0; i<N; i++)
cin>>num[i];

for(int i=0; i<N; i++){
    for(int j=0; j<N-1; j++){
        if( num[j] > num[j+1] ){
            int tmp = num[j];
            num[j] = num[j+1];
            num[j+1] = tmp;
        }
    }
}

bt(0);

    return 0;
}