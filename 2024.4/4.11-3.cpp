//https://www.acmicpc.net/problem/16968 차량 번호판1
#include <stdio.h>
#include <string.h>

int main(){

char s[5];
scanf("%s",&s);

int res = 1;

for( int i=0; i<strlen(s); i++ ){
    if( s[i]=='d' && i+1<strlen(s) && s[i+1]=='d' ){
        res*=9;
    }else if( s[i]=='d' ){
        res*=10;
    }
    if( s[i]=='c' && i+1<strlen(s) && s[i+1]=='c' ){
        res*=25;
    }else if( s[i]=='c' ){
        res*=26;
    }
}


printf("%d",res);


    return 0;
}