//https://www.acmicpc.net/problem/1181 단어 정렬
#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;


bool com(string& a, string& b){
    if( a.size() < b.size() ) return 1;
    else 
    if( a.size() == b.size() && a<b ) return 1;
    return 0;
}

int main(){
fastio

int n; cin>>n;
string arr[n];
for( int i=0; i<n; i++ ) cin>>arr[i];

sort(arr,arr+n,com);


for( int i=0; i<n; i++ ){
    if(i!=n-1 && arr[i]==arr[i+1]) continue;
    cout<<arr[i]<<"\n";
}
    return 0;
}