//https://www.acmicpc.net/problem/11659 구간 합 구하기 
#include <iostream>
using namespace std;

int main(){
ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int n,m;cin>>n>>m;
int arr[n] = {};
cin>>arr[0];
for( int i=1; i<n; i++ ){
    cin>>arr[i];
    arr[i] += arr[i-1];
}


for( int i=0; i<m; i++ ){
    int a,b; cin>>a>>b;
    a -= 1; b -= 1;
    cout<<arr[b]-(a-1<0?0:arr[a-1])<<"\n";
}

    return 0;
}