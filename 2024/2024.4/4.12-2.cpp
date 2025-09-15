//https://www.acmicpc.net/problem/2920 음계
#include <iostream>
using namespace std;

int main(){
ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

string s;
for( int i=0; i<8; i++ ){
    string tmp; cin>>tmp; s.append(tmp);
}

if( s == "12345678" ){
    cout<<"ascending";
    return 0;
}
if( s == "87654321" ){
    cout<<"descending";
    return 0;
}
cout<<"mixed";

    return 0;
}