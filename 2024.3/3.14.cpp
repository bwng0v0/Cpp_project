#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

int N;
cin>>N;

string arr[N];
for ( int i=0; i<N; i++ ){
    cin>>arr[i];
}

int done = 0;
for ( int i=0; i<N; i++ ){
    string rvs = arr[i];
    reverse(rvs.begin(), rvs.end());
    for ( int j=0; j<N; j++ ){
        if( rvs == arr[j] ){
            cout<<size(rvs)<<' '<<rvs[ size(rvs)/2 ];
            done = 1;
            break;
        }
    }

    if(done==1)
    break;

}

    return 0;
}