//https://www.acmicpc.net/problem/7600 문자가 몇갤까
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

string s;
while(true){
    int arr[26] {};
    getline(cin,s);
    if( s == "#" ) break;
    for( int i=0; i<s.size(); i++ ){
        if( isalpha(s[i]) ){
            arr[(toupper(s[i])-'A')] = 1;
        }
    }
    int sum = 0;
    for( int i=0; i<26; i++ ) sum += arr[i];
    cout<<sum<<"\n";
}

    return 0;
}