//https://www.acmicpc.net/problem/8958 OX퀴즈
#include <iostream>
using namespace std;

int main(){
ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int T; cin>>T;

for( int t=0; t<T; t++ ){

string s; cin>>s;
int res = 0;

int cnt = 1;
for( int i=0; i<s.size(); i++ ){
    if( s[i] == 'O' ){
    res += cnt;
    cnt += 1;
    }
    else
    cnt = 1;
}

cout<<res<<"\n";

}

    return 0;
}