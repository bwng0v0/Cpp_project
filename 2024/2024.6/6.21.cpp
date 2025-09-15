//https://www.acmicpc.net/problem/25703 포인터 공부
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int n; cin>>n;
cout<<"int a;\n";
cout<<"int *ptr = &a;\n";
for( int i=2; i<=n; i++ ){
    //int **ptr2 = &ptr;
    cout<<"int ";
    for( int j=0; j<i; j++ )cout<<"*";
    cout<<"ptr"<<i<<" = &ptr";
    if( i > 2 )cout<<i-1;
    cout<<";\n";
}

    return 0;
}