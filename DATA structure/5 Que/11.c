#include <stdio.h>
#include <string.h>
int main(){

char s[51];
int arr[26];
for ( int i=0; i<26; i++ ){
    arr[i] = 0;
}
scanf("%s",&s);



for ( int i=0; i<strlen(s); i++ ){
    arr[((int)s[i])-65] += 1;
}

int is_possible = 1;
int in_one = 0;
char one;
for ( int i=0; i<26; i++ ){

    if ( arr[i] % 2 != 0 && in_one == 1 ){
        printf("impossible");
        is_possible = 0;
        break;
    }

    if ( arr[i] % 2 != 0 ){
        in_one = 1;
        one = (char)i+65;
    }

}



if( is_possible == 1){
int half;
for ( int i=0; i<26; i++ ){ // 왼쪽 절반
    half = arr[i]/2;
    for ( int j=0; j<half; j++ )
    printf("%c",(char)(i+65));
}

if ( in_one == 1 )
printf("%c",one);

for ( int i=25; i>=0; i-- ){ // 오른쪽 절반
    half = arr[i]/2;
    for ( int j=0; j<half; j++ )
    printf("%c",(char)(i+65));
}
}

    return 0;
}