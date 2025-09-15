//https://www.acmicpc.net/problem/1284 집 주소
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

while(true){
    string s; cin>>s;
    if( s == "0" ) break;
    int sum = 2 + s.size()-1;
    for( int i=0; i<s.size(); i++ ){
        sum += 3;
        if(s[i]=='0') sum += 1;
        if(s[i]=='1') sum -= 1;
    }
    cout<<sum<<"\n";
}

    return 0;
}