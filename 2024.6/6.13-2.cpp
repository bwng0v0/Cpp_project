//https://www.acmicpc.net/problem/1356 유진수
#include <iostream>
#include <sstream>
#include <string>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

string s; cin>>s;
if( s.size() < 2 ){ cout<<"NO"; return 0; }


string left,right;
int l,r;
for( int i = 1; i<s.size(); i++ ){
    left = s.substr(0,i);
    right = s.substr(i);
    // cout<<left<<" "<<right<<endl;
    l = 1;
    for( int j=0; j<left.size(); j++ ) l *= left[j] - '0';
    r = 1;
    for( int j=0; j<right.size(); j++ ) r *= right[j] - '0';
    
    if( r==l ){
        cout<<"YES";
        return 0;
    }
}


cout<<"NO";

    return 0;
}