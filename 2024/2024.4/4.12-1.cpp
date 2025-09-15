//https://www.acmicpc.net/problem/2577 숫자의 개수
#include <iostream>
using namespace std;

int arr[10];

int main(){
ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);


int num = 1;
for( int i=0; i<3; i++ ){
    int tmp; cin>>tmp; num *= tmp;
}

while( num != 0 ){
    int i = num%10;
    arr[i] += 1;

    num = num/10;
}

for( int i : arr )
cout<<i<<"\n";

    return 0;
}