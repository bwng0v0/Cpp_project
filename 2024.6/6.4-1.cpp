//https://www.acmicpc.net/problem/1590 캠프가는 영식
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int n,time; cin>>n>>time;
int start, interval, bus;
int res = INT32_MAX;
for( int i=0; i<n; i++ ){
    cin>>start>>interval>>bus;
    int bustime = start;
    for( int j=0; j<bus; j++ ){
        if( time <= bustime && res >= bustime-time ) res = bustime-time;
        bustime += interval;
    }
}
if( res == INT32_MAX )
cout<<-1;
else
cout<<res;

/*
세션리더가 fork하고 죽으면
세션리더는 없는건가
*/

    return 0;
}