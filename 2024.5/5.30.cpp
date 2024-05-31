//https://www.acmicpc.net/problem/1547 공
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int cup[4] = {0,1,2,3};
int* cp[4] = {&cup[0],&cup[1],&cup[2],&cup[3]};

void swap(int a, int b){
    int tmp = *cp[a];
    int* tmpp = cp[a];
    *cp[a] = *cp[b];
    cp[a] = cp[b];
    *cp[b] = tmp;
    cp[b] = tmpp;
}

int main(){
fastio

int n; cin>>n;
for( int i=0; i<n; i++ ){
    int a,b; cin>>a>>b;
    swap(a,b);


    cout<<"";
}
cout<<cup[1];

    return 0;
}