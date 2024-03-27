//https://www.acmicpc.net/problem/9935 문자열 폭발
#include <iostream>
#include <string>
using namespace std;
int main(){

string s; cin>>s;
string bomb; cin>>bomb;
//폭탄을 두 부분으로 분리
string left = bomb.substr(0,bomb.size()-1);
char end = bomb[bomb.size()-1];
string st;//스택으로 사용

for(int i=0; i<s.size(); i++){
    if( s[i] == end )
    if( st.find(left) != string::npos ){
        st.erase( st.find(left),left.size() );
        continue;
    }

    st += s[i];
}

while( st.find(bomb) != string::npos ){
    st.erase( st.find(bomb),bomb.size() );
}


if( st == "" ){
    cout<<"FRULA";
}else{
    cout<<st;
}

    return 0;
}