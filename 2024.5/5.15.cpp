//https://www.acmicpc.net/problem/1373 2진수 8진수
#include <iostream>
#include <cmath>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int main(){
fastio

string s; cin>>s;
int tmp;
int arr[s.size()] {};
int size = 0;

for( int i=s.size()-1;  i>=0; i-=3 ){
    tmp = 0;
    for( int j=0; j<3; j++)
        if( i-j >= 0 )
        tmp += (s[i-j] - '0') * pow(2,j);

    arr[size] = tmp;
    size += 1;
    }

for( int i=size-1; i>=0; i-- )
cout<<arr[i];

    return 0;
}