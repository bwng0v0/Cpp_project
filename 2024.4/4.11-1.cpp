//https://www.acmicpc.net/problem/10769 행복한지 슬픈지
#include <stdio.h>
#include <string.h>

int main(){

char s[256];
fgets(s, sizeof(s), stdin);

int happy{0}, sad{0};

for( int i=2; i<strlen(s); i++ ){
    if( s[i]==')' && s[i-1]=='-' && s[i-2]==':'  ){
    happy += 1;
    }else if( s[i]=='(' && s[i-1]=='-' && s[i-2]==':'  ){
    sad += 1;
    }
}

if( happy==0 && sad==0 ){
    printf("none");
}else if( happy==sad ){
    printf("unsure");
}else if( happy>sad ){
    printf("happy");
}else{
    printf("sad");
}

    return 0;
}