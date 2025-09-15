//https://www.acmicpc.net/problem/15665 N과 M (11)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
vector<int> num;
int arr[10];

void bt(int K){
    if( K == M ){
        for( int i=0; i<M; i++ )
        cout<<arr[i]<<' ';
        
        cout<<'\n';
        return;
    }
    
    int checker{0};//지역변수여야함
    for( int i=0; i<num.size(); i++ ){
        if( checker == num[i] )
        {continue;} //나는 어떻게했더라
        else{
        checker = num[i];
        arr[K] = num[i];
        bt(K+1);
        }
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


bt(0);//첫 자릿수부터

return 0;
}
