//https://www.acmicpc.net/problem/18258 큐 2
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

// push X: 정수 X를 큐에 넣는 연산이다.
// pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// size: 큐에 들어있는 정수의 개수를 출력한다.
// empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
// front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.

queue<int> Q;
string cmd;
int x;
int n;
cin>>n;
for( int i=0; i<n; i++ ){
    cin>>cmd;
    if( cmd == "push" ){
        cin>>x;
        Q.push(x);
    }else if( cmd == "pop" ){
        if( Q.empty() ) x = -1;
        else{ x = Q.front(); Q.pop(); }
        cout<<x<<"\n";
    }else if( cmd == "size" ){
        cout<<Q.size()<<"\n";
    }else if( cmd == "empty" ){
        cout<<Q.empty()<<"\n";
    }else if( cmd == "front" ){
        if( Q.empty() ) x = -1;
        else x = Q.front();
        cout<<x<<"\n";
    }else if( cmd == "back" ){
        if( Q.empty() ) x = -1;
        else x = Q.back();
        cout<<x<<"\n";
    }
}




    return 0;
}