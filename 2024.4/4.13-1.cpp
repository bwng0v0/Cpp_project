//https://www.acmicpc.net/problem/10250 ACM 호텔
#include <iostream>
using namespace std;

int main(){ 
ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int T; cin>>T;
for( int t=0; t<T; t++ ){
    int h,w,n; cin>>h>>w>>n;
    int res = (n%h*100) + (n/h);
    if( n%h == 0 )
    res += h*100;
    else
    res += 1;
    

    cout<<res<<"\n";
}

    return 0;
}