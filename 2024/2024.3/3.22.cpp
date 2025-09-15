//https://www.acmicpc.net/problem/15664 N과 M (10)
#include <iostream>
using namespace std;

int N,M;
int num[10];
int arr[10];
bool is_used[10];
int printed[7000][10];
int print_cnt;
int same;
void bt(int K){
    if( K == M ){

        for(int i=0; i<print_cnt; i++){
            //줄단위검사
            same = 1;
            for(int j=0; j<M; j++){
                if( arr[j] != printed[i][j] ){
                    same = 0;
                    break;
                }
            }
            
            if(same==1)
            return;
        }

        for( int i=0; i<M; i++ ){
            cout<<arr[i]<<' ';
            printed[print_cnt][i] = arr[i];
        }
        cout<<'\n';
        print_cnt += 1;
        return;
    }

    for( int i=0; i<N; i++ ){
        if( is_used[i]==0 && arr[K-1] <= num[i]  ){ //인덱스아웃인데 왜 돌아가냐 아 앤드라서 뒤에 검사안하네 ㅋㅋ
            is_used[i] = 1;
            arr[K] = num[i];

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


bt(0);//첫 자릿수부터

return 0;
}
