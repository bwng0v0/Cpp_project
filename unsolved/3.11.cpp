#include <iostream>
//https://www.acmicpc.net/problem/10826
int main(){

//오버플로우
//해결방법: 문자열로 덧셈 근데 어케함?
int N;
long long unsigned int arr[N+1];
arr[0] = 0;
arr[1] = 1;
std::cin>>N;

for( int i=2; i<N+1; i++ ){
    arr[i] = arr[i-1]+arr[i-2];
}

std::cout<<arr[N];
    return 0;
}