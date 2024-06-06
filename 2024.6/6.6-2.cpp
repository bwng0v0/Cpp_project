//https://www.acmicpc.net/problem/23321 홍익 댄스파티
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

string arr[5];
for( int i=0; i<5; i++ ){
    cin>>arr[i];
}
for( int i=0; i<arr[0].size(); i++ ){
    if( arr[1][i] == 'o' ){
        arr[0][i] = 'o';
        arr[1][i] = 'w';
        arr[2][i] = 'l';
        arr[3][i] = 'n';
        arr[4][i] = '.';
    }else if( arr[1][i] == 'w' ){
        arr[0][i] = '.';
        arr[1][i] = 'o';
        arr[2][i] = 'm';
        arr[3][i] = 'l';
        arr[4][i] = 'n';
    }else if( arr[1][i] == '.' ){

    }
}
for( string s : arr ){
    cout<<s<<"\n";
}

    return 0;
}