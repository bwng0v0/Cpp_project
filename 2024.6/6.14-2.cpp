//https://www.acmicpc.net/problem/16130 벌점 (DemeritPoints)
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int n; cin>>n;
for( int i=0; i<n; i++ ){
    string s; cin>>s;
    int p = 0;
    int out = 0;
    int lout = 0;
    int b = 0;
    for( int j=0; j<s.size(); j++ ){
        if( s[j] <= '9' ){ p += s[j] - '0'; }
        else{ p += (10 + s[j] - 'A'); }
        if( p/10 > lout ){
            if( (p/10) == 4 ){ cout<<out<<"(weapon)\n"; b=1; break; }
            if( (p/10) > 4 ){ cout<<out<<"(09)\n"; b=1; break; }
            out += p/10;
            lout = p/10;
        }
    }
    if(b)continue;
    cout<<out<<"\n";
}

    return 0;
}