//https://www.acmicpc.net/problem/17413 단어 뒤집기 2
#include <iostream>
#include <stack>
using namespace std;

stack<char> st;
string str;
int tagmode;

void stackout(){
    int n = st.size();
    for( int i=0; i<n; i++ ){
        cout<<st.top();
        st.pop();
    }
}
int main(){

getline(cin,str);


for( int i=0; i<size(str); i++){

    if( str[i] == '<' ){
    tagmode = 1;
    stackout();//태그 시작 전 스택비우기
    }

    if( tagmode == 1 ){//태그라면 그냥 출력
        cout<<str[i];
    }else{//태그가 아니라면 스택에 푸쉬
        if( str[i] == ' ' )//태그가 아니고 공백을 저장했다면 이전에 저장한 단어를 뱉어라
        stackout();

        st.push(str[i]);

        if( str[i] == ' ' )//저장한게 공백이라면 다음단어에 공백이 들어가지않게 미리 출력
        stackout();
    }

    if( str[i] == '>' ){
    tagmode = 0;
    }
}
stackout();

    return 0;
}