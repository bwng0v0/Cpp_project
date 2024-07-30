//https://www.acmicpc.net/problem/5704 팬그램
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define X first
#define Y second
using namespace std;

int main(){
fastio

string s;
while(true){
    getline(cin,s); int b=1;
    if( s == "*" ) break;

    for( char c = 'a'; c<='z'; c+=1 ){
        if( s.find(c) == s.npos ){ cout<<"N\n"; b=0; break;  } 
    }

    if(b)cout<<"Y\n";
}

    return 0;
}