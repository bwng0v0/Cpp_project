//https://www.acmicpc.net/problem/12018 Yonsei TOTO
#include <iostream>
#include <algorithm>
using namespace std;
int main(){

int n,ml;
cin>>n>>ml;

int arr[n]; //과목별 최소마일리지

for( int i=0; i<n; i++ ){
    int ppl,cut;
    cin>>ppl>>cut;
    int mlarr[ppl];
    for( int j=0; j<ppl; j++ )
    cin>>mlarr[j];
    
    if( cut > ppl ){
        arr[i] = 1;
    }else{
        sort(mlarr,mlarr+ppl);
        arr[i] = mlarr[ppl-cut]; //여기가 문제였고
    }
}

sort(arr,arr+n);

int res = 0;
for( int smlst : arr ){
    if( smlst > ml ){
        break;
    }else{
        ml -= smlst;
        res += 1;
    }
}

cout<<res;

    return 0;
}