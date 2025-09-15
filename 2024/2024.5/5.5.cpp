//https://www.acmicpc.net/problem/1259 팰린드롬수
#include <iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

string s;
while(true){
    cin>>s;
    if( s=="0" ) return 0;

    int isp = 1;
    for( int i=0; i<s.size()/2; i++ ){
        if( s[i] != s[s.size()-1-i] ){
            cout<<"no\n";
            isp = 0;
            break;
        }
    }

    if(isp)cout<<"yes\n";
}   

    return 0;
}