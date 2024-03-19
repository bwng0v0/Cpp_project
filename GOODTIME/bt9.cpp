#include <iostream>
//https://www.acmicpc.net/problem/15663 N과M (9)
using namespace std;

int N,M;
int arr[10];
int num[10];
bool is_used[10];
int lastout[10];
bool isoverlap;

//num에 같은수가 있으면 중복
//입력에서?

void bt( int K ){
    if( K==M ){

        isoverlap = 1;
        for(int i=0; i<M; i++){
            if(lastout[i] != arr[i]){ //?? 중괄호 안쳤다고 이게 
            isoverlap = 0;
            break;
            }
        }


        if( isoverlap == 0 ){
        for(int i=0; i<M; i++)
        cout<<arr[i]<<' ';
        cout<<'\n';
        //출력하고 마지막출력으로 기록
        for(int i=0; i<M; i++){
            lastout[i] = arr[i];
        }

       }

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