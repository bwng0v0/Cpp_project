//https://www.acmicpc.net/problem/9342 염색체
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int T; cin>>T;
string s; bool res;
for( int t=0; t<T; t++ ){
    cin>>s;
    if( ('A' <= s[0] && s[0] <= 'F') && ('A' <= s[s.size()-1] && s[s.size()-1] <= 'F') ){
        s = s.substr(1,s.size()-2);
        int pos = 0;
        while( s[pos] == 'A' ) pos += 1;
        while( s[pos] == 'F' ) pos += 1;
        while( s[pos] == 'C' ) pos += 1;

        if( pos == s.size() ) cout<<"Infected!\n";
        else cout<<"Good\n";

    }else{
        cout<<"Good\n";
    }
}


    return 0;
}