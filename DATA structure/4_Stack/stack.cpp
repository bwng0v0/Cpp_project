#include <iostream>
using namespace std;

int top;
int stack[10];
//top 맨위 값을 반환 비어있다면 -1
int stack_top(){
    if( top == 0 )
    return -1;
    
    return stack[top-1];
}
//push 요소 추가
void stack_push(){
    int x;
    cin>>x;
    stack[top] = x;
    top += 1;
}
//pop 맨위 반환,삭제
int stack_pop(){
    if( top > 0 ){
    top -= 1;
    return stack[top];
    }else{
        return -1;
    }
}
//size 들어있는 요소개수
int stack_size(){
    return top;
}
int main(){

string cmd;

while(1){

cin>>cmd;
if( cmd == "break" )
break;

if( cmd == "push" )
stack_push();
else if( cmd == "top" )
cout<<stack_top()<<'\n';
else if( cmd == "pop" )
cout<<stack_pop()<<'\n';
else if( cmd == "size" )
cout<<stack_size()<<'\n';


}



    return 0;
}