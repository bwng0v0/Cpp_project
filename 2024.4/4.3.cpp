//https://www.acmicpc.net/problem/2810 컵홀더
#include <iostream>
using namespace std;

int main(){

int n;
scanf("%d",&n);
char s[51];
scanf("%s",&s);

double res = 1;

for( int i=0; i<n; i++ ){
    if( s[i] == 'S' ){
        res += 1;
    }else if( s[i] == 'L' ){
        res += 0.5;
    }
}

if( res > n ){
    res = n;
}
printf("%.0lf",res);

    return 0;
}