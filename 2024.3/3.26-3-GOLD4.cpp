//https://www.acmicpc.net/problem/17298 오큰수
#include <iostream>
#include <stack>
using namespace std;

int arr[1000001];
stack<int> numstack;
stack<int> istack;

int main(){
    cin.tie(0);

int n; cin>>n;
int tmp;
for( int i=0; i<n; i++ ){
    cin>>tmp;
    arr[i] = tmp;
}


int index;
for( int i=0; i<n; i++ ){
    if( !numstack.empty() && numstack.top() < arr[i] ){//스택이 비어있지않고 && 이번수가 스택맨위보다 크다면
        
        //!!!!!!!!!!!비어있는 상태에서 탑메소드를 호출하면 세그먼트폴트
        while( !numstack.empty() && numstack.top() < arr[i] ){//이번수보다 "작은수"만 다뺌 
            index = istack.top();
            arr[index] = arr[i];
            istack.pop();
            numstack.pop();
        }
        //본인보다 작은수 다뺀 후 이번수 푸쉬
        numstack.push(arr[i]);
        istack.push(i);
    }
    else{//스택 맨위보다 작다면 푸쉬(쌓기)
        numstack.push(arr[i]);
        istack.push(i);
    }
}

//자기보다 큰수를 못찾아 스택에 남아있는애들 -1처리
while( !istack.empty() ){//스택빌때까지
    index = istack.top();
    arr[index] = -1;
    istack.pop();
}

for( int i=0; i<n; i++ )
cout<<arr[i]<<' ';

    return 0;
}