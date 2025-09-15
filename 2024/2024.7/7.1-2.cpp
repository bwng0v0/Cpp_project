//https://www.acmicpc.net/problem/31403 $A + B - C$
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int a,b,c; cin>>a>>b>>c;
cout<<a+b-c<<"\n";
cout<<stoi(to_string(a)+to_string(b)) - c;


    return 0;
}