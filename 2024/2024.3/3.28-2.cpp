//https://www.acmicpc.net/problem/9935 문자열 폭발
#include <iostream>
#include <string>
using namespace std;
int main(){

string s; cin>>s;
string bomb; cin>>bomb;
//폭탄을 두 부분으로 분리
// string left = bomb.substr(0,bomb.size()-1);
char end = bomb[bomb.size()-1];
string st;//스택으로 사용

for(int i=0; i<s.size(); i++){

    st += s[i];

    //!!! 폭탄을 find로 찾지않고 끝글자가 들어올때마다 문자열끝을 폭탄 크기만큼substr으로 확인,제거함
    
    if( st.size()>=bomb.size() && s[i] == end ){//스택에 폭탄길이보다 큰 문자열이 쌓였고 방금 넣은게 폭탄끝문자라면
    if( st.substr(st.size()-bomb.size(),bomb.size()) == bomb ){//끝의 폭탄크기만큼의 문자열을 확인하고 맞다면 제거
        st.erase( st.size()-bomb.size(),bomb.size() );
        continue;
    }
    }

    cout<<"";
}


if( st == "" ){
    cout<<"FRULA";
}else{
    cout<<st;
}

    return 0;
}