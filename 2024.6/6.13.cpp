//https://www.acmicpc.net/problem/31428 엘리스 트랙 매칭
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

int n; cin>>n;
int arr[4] {};
for( int i=0; i<n; i++ ){
    string s; cin>>s;
    if( s == "C" ){
        arr[0] += 1;
    }else if( s == "S"){
        arr[1] += 1;
    }else if( s == "I" ){
        arr[2] += 1;
    }else{
        arr[3] += 1;
    }
}

string s; cin>>s;
if( s == "C" ){
    cout<<arr[0];
}else if( s == "S"){
    cout<<arr[1];
}else if( s == "I" ){
    cout<<arr[2];
}else{
    cout<<arr[3];
}

    return 0;
}