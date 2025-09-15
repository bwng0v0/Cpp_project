//https://www.acmicpc.net/problem/2493 탑
#include <iostream>
#include <stack>
using namespace std;

int arr[500001];
stack<int> numstack;
stack<int> istack;
int n;

int main(){

cin>>n;
for(int i=0; i<n; i++)
cin>>arr[i];

for(int i=n-1; i>=0; i--){

    //비어있지않고 뜬게 탑보다 큰수라면
    if( !numstack.empty() && numstack.top() < arr[i] ){
        while( !numstack.empty() && numstack.top() < arr[i] ){
            arr[istack.top()] = i+1;
            numstack.pop();
            istack.pop();
        }
        numstack.push(arr[i]);
        istack.push(i);
    }else{
        numstack.push(arr[i]);
        istack.push(i);
    }
    
}

//스택에 남은거 처리
while( !numstack.empty() ){
    arr[istack.top()] = 0;
    numstack.pop();
    istack.pop();
}

for(int i=0; i<n; i++)
cout<<arr[i]<<' ';

    return 0;
}