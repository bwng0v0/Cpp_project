//https://www.acmicpc.net/problem/1264 모음의 개수
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

string s;
int cnt;
while(true){
    getline(cin,s);
    if( s == "#") return 0;
    cnt = 0;
    for( int i=0; i<s.size(); i++ ){
        if( s[i] == 'a' ) cnt += 1;
        if( s[i] == 'e' ) cnt += 1;
        if( s[i] == 'i' ) cnt += 1;
        if( s[i] == 'o' ) cnt += 1;
        if( s[i] == 'u' ) cnt += 1;
        if( s[i] == 'A' ) cnt += 1;
        if( s[i] == 'E' ) cnt += 1;
        if( s[i] == 'I' ) cnt += 1;
        if( s[i] == 'O' ) cnt += 1;
        if( s[i] == 'U' ) cnt += 1;
    }
    cout<<cnt<<"\n";
}

    return 0;
}