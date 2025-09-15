//https://www.acmicpc.net/problem/16461 듀얼 채널 VHF 무전기
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int T; cin>>T;

int tmp,min;
for( int t=0; t<T; t++ ){
    int a,b,x; char c;
    double q,w,e;
    cin>>q>>w>>c>>e; q*=1000; w*=1000; e*=1000; a=q; b=w; x=e;
    // cout<<a<<" "<<b<<" "<<x<<endl;
    tmp = a; min = 6;
    for( int i=0; i<6; i++ ){
        if( tmp == x  && min > i ){ min = c=='A'?i:i+1; break;}
        tmp += 20;
        if( tmp > 146000 ) tmp = 144000;
        if( tmp < 144000 ) tmp = 146000;
    }
    tmp= a;
    for( int i=0; i<6; i++ ){
        if( tmp == x  && min > i ){ min = c=='A'?i:i+1; break;}
        tmp -= 20;
        if( tmp > 146000 ) tmp = 144000;
        if( tmp < 144000 ) tmp = 146000;
    }
    tmp = b;
    for( int i=0; i<6; i++ ){
        if( tmp == x  && min > i ){ min = c=='B'?i:i+1; break;}
        tmp += 20;
        if( tmp > 146000 ) tmp = 144000;
        if( tmp < 144000 ) tmp = 146000;
    }
    tmp = b;
    for( int i=0; i<6; i++ ){

        if( tmp == x  && min > i ){ min = c=='B'?i:i+1; break;}
        tmp -= 20;
        if( tmp > 146000 ) tmp = 144000;
        if( tmp < 144000 ) tmp = 146000;
    }

    cout<<min<<"\n";
}

    return 0;
}