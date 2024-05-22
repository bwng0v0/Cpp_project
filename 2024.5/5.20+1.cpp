//https://www.acmicpc.net/problem/16953 A → B
#include <iostream>
#include <queue>
#define X first
#define Y second
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

queue<pair<long long int,long long int>> Q;
pair<long long int,long long int> cur;

int main(){
fastio

int a,b; cin>>a>>b;

Q.push({a,1});

while( !Q.empty() ){
    cur = Q.front();
    if( cur.X == b ){ cout<<cur.Y; return 0; }
    Q.pop();
    
    for( int i=0; i<2; i++ ){
        long long int x;
        if( i==0 ) x = cur.X *2;
        if( i==1 ) x = cur.X * 10 + 1;

        if( x > b ) continue;
        Q.push({x,cur.Y+1});
    }

}
cout<<-1;

    return 0;
}