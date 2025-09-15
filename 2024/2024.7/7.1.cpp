//https://www.acmicpc.net/problem/1018 체스판 다시 칠하기
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

string b[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
};
string w[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
};
int n,m; cin>>n>>m;
string arr[n];
for( int i=0; i<n; i++ ){
    cin>>arr[i];
}

int endn = 8, endm = 8, min = 64;
while(endn <= n){

int resw = 0, resb = 0;
for( int i=endn - 8,i2=0; i<endn; i++ ){
    for( int j=endm - 8,j2=0; j<endm; j++ ){
        if( arr[i][j] != w[i2][j2] ) resw += 1;
        if( arr[i][j] != b[i2][j2] ) resb += 1;
        j2 += 1;
    }
    i2 += 1;
}


if( min > resw ) min = resw;
if( min > resb ) min = resb;

endm += 1;
if( endm == m+1 ){ endn += 1; endm = 0; }
}
cout<<min;

    return 0;
}