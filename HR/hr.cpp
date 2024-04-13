#include <bits/stdc++.h>
using namespace std;

int arr[1000] = {64};

int main(){
ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int size = 1;
int sum = 64;
int x;cin>>x;


while( sum > x ){
//총합이 x보다 크다면 가장작은걸 절반 나눔
int tmp = arr[size-1]/2;
arr[size-1] = tmp;
arr[size] = tmp;
size+= 1;

if( sum - tmp >= x ){
sum -= tmp;
size -= 1;
}

}

cout<<size;

    return 0;
}