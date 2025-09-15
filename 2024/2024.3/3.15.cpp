//https://www.acmicpc.net/problem/14659 한조서열정리하고옴ㅋㅋ
#include <iostream>
using namespace std;
int main(){

int N;
cin>>N;
int arr[N];

for ( int i=0; i<N; i++ ){
    cin>>arr[i];
}

int cnt{0}, maxcnt{0}, atker{0};
for (int i=1; i<N; i++){
    if ( arr[atker] < arr[i] ){
        //공격실패하면
        cnt = 0;
        atker = i;
    }else{
        //공격성공
        cnt += 1;
        if ( maxcnt < cnt )
        maxcnt = cnt;
    }
}

cout<<maxcnt;

    return 0;
}