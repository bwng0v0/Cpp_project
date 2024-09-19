//https://www.acmicpc.net/problem/13410 거꾸로 구구단
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define X first
#define Y second
using namespace std;

int main(){
fastio

int n,k; cin>>n>>k;
int max = 0;
for( int i=1; i<=k; i++ ){
    string s = to_string(n*i);
    reverse(s.begin(),s.end());
    int a = stoi(s);
    if( max < a ) max = a;
}

cout<<max;

    return 0;
}