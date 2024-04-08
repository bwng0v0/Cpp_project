//https://www.acmicpc.net/problem/15905 스텔라(STELLA)가 치킨을 선물했어요
#include <stdio.h>

int main(){

int n; scanf("%d",&n);
int arr[n][2];
for( int i=0; i<n; i++ )
scanf("%d %d",&arr[i][0],&arr[i][1]);

int max = 0;
int maxi = 0;

for( int j=0; j<5; j++ ){

max = 0;

for( int i=0; i<n; i++ ){
    if( arr[i][0] > max ){
        max = arr[i][0];
        maxi = i;
      }
    }

    if( j==4 )//5등이면 살림
    break;

    arr[maxi][0] = -1;//4등까지 버림
}

int cnt = -1;//본인제외
for( int i=0; i<n; i++ ){
    if( arr[i][0] == arr[maxi][0] )
    cnt+=1;
}

printf("%d",cnt);

    return 0;
}