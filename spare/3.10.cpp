#include <iostream>
//https://www.acmicpc.net/problem/9625
int main(){

int N;
std::cin>>N;

int arr[N+1][2];
arr[0][0] = 1;
arr[0][1] = 0;

for( int i=1; i<N+1; i++ ){
    arr[i][0] = arr[i-1][1];
    arr[i][1] = arr[i-1][0]+arr[i-1][1];
}

std::cout<<arr[N][0]<<' '<<arr[N][1];
    return 0;
}