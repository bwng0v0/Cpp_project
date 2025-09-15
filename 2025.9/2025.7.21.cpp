//https://www.acmicpc.net/problem/21918 전구
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define X first
#define Y second
using namespace std;

int main(){
fastio

    int n,m;
    cin>>n>>m;
    bool arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    for(int i=0; i<m; i++){
        int com, a,b; cin>>com>>a>>b;

        if(com==1){
            arr[a-1] = b;
        }

        a-=1;
        b-=1;

        if(com==2){
            for(int j=a; j<=b; j++)
                arr[j] = !arr[j];
        }
        if(com==3){
            for(int j=a; j<=b; j++)
                arr[j] = 0;
        }
        if(com==4){
            for(int j=a; j<=b; j++)
                arr[j] = 1;
        }
    }

    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";


    return 0;
}