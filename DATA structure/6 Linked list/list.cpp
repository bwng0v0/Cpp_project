#include <stdio.h>
#include <stdlib.h>

//헤드를 노드포인터말고 그냥 첫번째노드를 헤드라고하고 해드의 link부터 시작하면 안되는지
//이러면 insertfirst deletefirst는 없어도되는데
typedef int element;
typedef struct Listnode{
    element data;
    struct Listnode *link;
} Listnode;

Listnode* insert_first(Listnode *head, element value){
    Listnode *p = (Listnode*)malloc(sizeof(Listnode));
    p->data = value;//p에 값을넣고
    p->link = head; 

    head = p;//이전노드의 링크가 p를 가리키도록함
    return head;
}
//pre노드 뒤에 삽입
Listnode* insert(Listnode *head, Listnode *pre, element value){
    Listnode *p = (Listnode*)malloc(sizeof(Listnode));
    p->data = value;//p에 값을넣고
    p->link = pre->link; //이전노드의 링크를 p의 링크에 넘겨받음
    pre->link = p;//이전노드의 링크가 p를 가리키도록함

    return head;//헤드를 리턴?
}

void print_list(Listnode* head){
    Listnode *p = head;
    while( p != NULL ){
        
        printf("%d->",p->data);
        p = p->link;
    }
    printf("NULL\n");
}

int main(){

Listnode *head = NULL;

int n;scanf("%d",&n);
for( int i=0; i<n; i++ ){
    int tmp;
    scanf("%d",&tmp);
    head = insert_first(head,tmp);
}
print_list(head);
    return 0;
}
