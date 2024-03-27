//https://www.acmicpc.net/problem/11721
#include <iostream>
int main(){

using namespace std;
string s;
getline(cin,s);

int cnt = 0;
for ( int i=0; i<s.size(); i++ ){
    cout<<s[i];
    cnt += 1;
    if( cnt == 10 ){
    cout<<'\n';
    cnt = 0;
    }
}

    return 0;
}
