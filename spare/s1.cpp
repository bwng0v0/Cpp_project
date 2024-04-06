//https://www.acmicpc.net/problem/2475 검증수
#include <iostream>
using namespace std;

int main(){
ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int n;
int sum = 0;
for( int i=0; i<5; i++ ){
    cin>>n;
    sum += n*n;
}

cout<<sum%10;

    return 0;
}