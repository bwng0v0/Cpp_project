//https://www.acmicpc.net/problem/11899 괄호 끼워넣기
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){

char stack[51];
int pointer = 0;
string str;

getline(cin,str);
for( int i=0; i<str.size(); i++ ){
    if( str[i] == '(' ){//여는괄호는 스택에 쌓음
        stack[pointer] = '(';
        pointer += 1;
    }
    if( str[i] == ')' ){//스택 맨위가 여는 괄호라면 서로 맞아없어짐
        if( stack[pointer-1] == '(' ){
            stack[pointer-1] == '\0';
            pointer -= 1;
        }else{//짝이 안맞으면 스택에 추가
            stack[pointer] = ')';
            pointer += 1;
        }
    }
}

cout<<pointer;


    return 0;
}