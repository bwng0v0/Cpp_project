//https://www.acmicpc.net/problem/1043
#include <iostream>
using namespace std;

int res[50];//거짓말해도되면 1 안되면 0

int main(){
ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int n,party; cin>>n>>party;
int arr[n+1] = {0}; // 1 ~ n+1
// + 각 사람은 만났던 사람들 저장해놔야함

int know; cin>>know;
for( int i=0; i<know; i++ ){
    int num;cin>>num;
    arr[num] = 1;
}

int parr[party][n+1] = {0};

for( int p=0; p<party; p++ ){

//

}




int sum = 0;
for( int i=0; i<party; i++ )
sum += res[i];

cout<<sum;


    return 0;
}