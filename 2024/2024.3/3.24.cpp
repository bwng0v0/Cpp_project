//https://www.acmicpc.net/problem/17175 피보나치는 지겨웡~
#include <iostream>
using namespace std;
int main(){

int f[51] = {1,1};
int n;

cin>>n;
for(int i=2; i<=n; i++){
    f[i] = (f[i-2]+f[i-1]+1) % 1000000007;
}
cout<<f[n];

    return 0;
}