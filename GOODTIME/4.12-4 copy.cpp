//https://www.acmicpc.net/problem/10250 ACM 호텔
#include <iostream>
using namespace std;

int main(){ 
ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int h=10, w=10;
for( int i=h; i>=1; i-- ){
    for( int j=1; j<=w; j++ ){
        int n = (j*h) +i-h ;
        //cout<<n<<" ";
        cout<<(n%h*100) + (n/h)<<" ";
    }
    cout<<"\n";
}

    return 0;
}