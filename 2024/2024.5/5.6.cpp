//https://www.acmicpc.net/problem/1526 가장 큰 금민수
#include <iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int n; cin>>n;
while(true){
    string s = to_string(n);
    
    int out = 1;
    for( int i=0; i<10; i++  ){
        if( i==4 || i==7 ) continue;
        if( s.find(to_string(i)) != string::npos ){
            out = 0;
            break;
        }
    }
    if(out){ cout<<n; return 0; }
    
    n -= 1;
}


    return 0;
}