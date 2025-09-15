#include <stdio.h>

int main(){

int stack1[100];
int stack2[100];
int top1 = 0;
int top2= 0;
int n;
scanf("%d",&n);
for( int i=0; i<n; i++ ){
    scanf("%d",&stack1[top1]);
    top1 += 1;
}

for( int i=top1-1; i>=0; i-- ){
    stack2[top2] = stack1[i];
    top2 += 1;
}

for( int i=top2-1; i>=0; i-- ){
    printf("%d ",stack2[i]);   
}


    return 0;
}