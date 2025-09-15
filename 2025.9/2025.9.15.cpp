//https://www.acmicpc.net/problem/32822 행렬 게임
// #include <bits/stdc++.h>
#include<iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define X first
#define Y second
typedef long long ll;

using namespace std;

int arr[1000][1000];
int num[1000000];
int diff[1000];

int main(){

int n,m;
cin>>n>>m;
for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        cin>>arr[i][j];
    }
}
for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        int a;
        cin>>a;
        arr[i][j] = abs(arr[i][j] - a);
    }
}
for(int i=0; i<m; i++)
    cin>>num[i];
//입력 끝

//각 열에 대한 최대 diff 미리 구하기
for(int y=0; y<n; y++){
    int max = 0;
    for(int x=0; x<n; x++){
        if(max < arr[x][y]) max = arr[x][y];    
    }
    diff[y] = max;
}

int sum = 0;

for(int i=0; i<m; i++){
    int y = num[i]-1; //y = 이번에 상대가 부른 수 / 선택된 열

    sum += diff[y];
}
cout<<sum;

    return 0;
}

//N*M 약 10억 -> diff 걍 구해놓으면 되네;
//N*N + M