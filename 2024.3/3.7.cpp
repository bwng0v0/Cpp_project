//https://www.acmicpc.net/problem/1453 피시방 알바
#include <iostream>

int main(){
using namespace std;

int N;
cin>>N;

int seat[101] = {}, tmp;
for( int i=0; i<N; i++ ){
    cin>>tmp;
    seat[tmp] += 1;
}

int over = 0;
for( int i=0; i<101; i++ ){
    if( seat[i] > 1 )//자리에 2명 이상이면 오버한만큼 답에 더함
        over += seat[i] -1;
}

cout<<over;

    return 0;
}
