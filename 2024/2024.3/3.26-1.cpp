//https://www.acmicpc.net/problem/11727 2×n 타일링 2
#include <iostream>
using namespace std;
int main(){

int n;
cin>>n;

int arr[n+1];
arr[0] = 1;
arr[1] = 1;

for(int i=2; i<=n; i++ ){
    arr[i] = (arr[i-2]*2 + arr[i-1]) % 10007;
}

cout<<arr[n];

    return 0;
}