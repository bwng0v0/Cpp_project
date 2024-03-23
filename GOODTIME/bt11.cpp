//https://www.acmicpc.net/problem/15665
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
vector<int> num;
int size;
int arr[10];
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

    for( int i=0; i<size; i++ ){
            arr[K] = num[i];
            bt(K+1);
    }
}
int main(){
ios::sync_with_stdio(0);
cin.tie(0);

cin>>N>>M;
for(int i=0; i<N; i++){
    int tmp;
    cin>>tmp;
    num.push_back(tmp);
}

//정렬후 중복제거
sort(num.begin(), num.end());
num.erase(unique(num.begin(), num.end()), num.end());
size = num.size();


bt(0);//첫 자릿수부터

return 0;
}
