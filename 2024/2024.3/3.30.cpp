//https://www.acmicpc.net/problem/4344 평균은 넘겠지
#include <iostream>
#include <iomanip>
using namespace std;

int main(){

int N;cin>>N;
for( int i=0; i<N; i++ ){
    
    int c; cin>>c;
    int arr[c];
    double sum = 0;
    double tops = 0;

    for( int j=0; j<c; j++ ){
        cin>>arr[j];
        sum += arr[j];
    }
    double avg = sum/c;

    for( int j=0; j<c; j++ ){
        if( arr[j] > avg ){
        tops += 1;
        }
    }
    cout<<fixed<<setprecision(3)<<tops/c*100<<"%\n";

}

    return 0;
}