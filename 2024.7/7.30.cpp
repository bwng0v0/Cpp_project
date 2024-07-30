//https://www.acmicpc.net/problem/2684 동전 게임
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define X first
#define Y second
using namespace std;

int main(){
fastio

int T; cin>>T;
string s;
for( int t=0; t<T; t++ ){
    map<string,int> M = {
        {"HHH",0},
        {"HHT",0},
        {"HTH",0},
        {"HTT",0},
        {"THH",0},
        {"THT",0},
        {"TTH",0},
        {"TTT",0},
    };
    cin>>s;
    for( int i=0; i<38; i++ )
    M[s.substr(i,3)] += 1;
    
    string res = "";
    for( auto a : M )
    res = to_string(a.second)+" " +res;
    cout<<res<<"\n";
}

    return 0;
}