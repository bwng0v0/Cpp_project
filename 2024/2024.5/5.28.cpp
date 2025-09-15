//https://www.acmicpc.net/problem/31909 FOCUS
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

bool bit[8];
int idx[2];
int key[8] = {0,1,2,3,4,5,6,7};
int* kp[8] = {&key[0],&key[1],&key[2],&key[3],&key[4],&key[5],&key[6],&key[7]};
void swap_key(int a,int b){
    int t = *kp[a];
    int* tp = kp[a];
    *kp[a] = *kp[b];
    kp[a] = kp[b];
    *kp[b] = t;
    kp[b] = tp;
}
int main(){
fastio

int n; cin>>n;
int arr[n]; for( int i=0; i<n; i++ ) cin>>arr[i];
int start; cin>>start;
//입력

for( int i=0; i<n; i++ ){
    int x = arr[i];

    int cnt = 0;
    for( int j=0; j<8; j++ ){
        if( bit[j] = x%2 ){ idx[cnt] = j; cnt += 1; }
        x /= 2;
    }

    if( cnt==2 ){
        swap_key(idx[0],idx[1]);
        // cout<<idx[0]<<" "<<idx[1];
    }
    
}

for( int i=0; i<8; i++ ){
    if( key[i] == start ) cout<<i;
}

    return 0;
}