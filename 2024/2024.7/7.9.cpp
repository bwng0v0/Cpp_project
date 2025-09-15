//https://www.acmicpc.net/problem/22937 교수님 계산기가 고장났어요!
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int n; cin>>n;
for( int i=0; i<n; i++ ){
string a,b; cin>>a>>b;
bool sign = (a[0]=='-' ^ b[0]=='-');
a = a[0]=='-'? a[1] + a.substr(3) : a[0] + a.substr(2) ;
b = b[0]=='-'? b[1] + b.substr(3) : b[0] + b.substr(2) ;
string res = to_string(stoull(a)*stoull(b));

while(res.size() < 19) res = '0' + res;
res.insert(res.size()-18,".");
if( sign ) res = "-" + res;
cout<<res<<"\n";
}
    return 0;
}