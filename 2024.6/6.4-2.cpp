//https://www.acmicpc.net/problem/28125 2023 아주머학교 프로그래딩 정시머힌
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

string tarr[] = {"@", "[", "!", ";", "^", "0", "7", "\\\\'", "\\'" };
string farr[] = {"a", "c", "i", "j", "n", "o", "t", "w",     "v" };

int main(){
fastio

string s;
int n; cin>>n;
for( int i=0; i<n; i++ ){
    cin>>s;
    int cnt = 0;
    int index;

    for( int j=0; j<9; j++ ){
    while(true){
        index = s.find( tarr[j] );
        if( index == string::npos ) break;
        s.erase(index,tarr[j].size());
        s.insert(index,farr[j]);
        cnt += 1;
        }
    }
    // if( s.size()%2 == 1 ) cnt -= 1;
    if( cnt >= s.size()/2.0 ) cout<<"I don't understand";
    else cout<<s; cout<<"\n";

}

    return 0;
}