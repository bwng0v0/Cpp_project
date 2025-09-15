//https://www.acmicpc.net/problem/1551 수열의 변화
#include <stdio.h>
#include <string.h>

int main(){

int n,k;
scanf("%d %d",&n,&k);
int arr[n];

for( int i=0; i<n; i++ ){
    scanf("%d,",&arr[i]);    
}

for( int j=0; j<k; j++ ){
for( int i=0; i<n-1; i++ ){
    arr[i] = arr[i+1] - arr[i];
}
n -= 1;
}

for( int i =0; i<n-1; i++ ){
    printf("%d,",arr[i]);
}
printf("%d",arr[n-1]);

    return 0;
}