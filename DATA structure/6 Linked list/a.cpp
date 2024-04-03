#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* nextnode;

    node(int d, node* next): data{d}, nextnode{next}  {}
    node(int d ): data{d},nextnode{nullptr} {}
    node(){}
};
void insert_first(node &head, node &tmp){
        //헤드가 널을 가리키면
        if( head.nextnode == nullptr ){
            head.nextnode = &tmp;
        }
        //헤드가 무언가 가리킨다면
        else{
        tmp.nextnode = head.nextnode;
        head.nextnode = &tmp;
        }

    }
    void printlist(node head){
        node* np = head.nextnode;

        while( np->nextnode != nullptr ){
            cout<<np->data<<" ";
            np = np->nextnode;
        }
        cout<<"\n";
    }

    int listsize(node &head){
        node* np = head.nextnode;
        int cnt = 0;
        while( np->nextnode != nullptr ){
            cnt += 1;
            np = np->nextnode;
        }
        return cnt;
    }

    void insert( node &head, int n, node &tmp ){
        if( listsize(head) < n ){
            cout<<"insert fail\n";
            return;
        }
        node* np = &head;
        //np를 n번째 노드까지 끌고감
        for( int i=0; i<n-1; i++ ){
            np = np->nextnode;
        }
        
        // head-> 1 -> 2 -> 3
        //1. tmp가 np 다음노드를 가리키게함
        //2. np가 tmp를 가리키게함
        tmp.nextnode = np->nextnode;
        np->nextnode = &tmp;
        
    }

    void listdelete(node &head, int n){
        if( listsize(head) < n || n <0 ){
            cout<<"out of bound\n";
            return;
        }

        node *np = &head;
        node *back; //n-1번째 노드
        for( int i=0; i<n; i++ ){
            back = np;
            np = np->nextnode;
        }
        
        back->nextnode = np->nextnode;
    }

int main(){
ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);


node head;
node n1(10);
node n2(20);
node n3(30);
cout<<listsize(head)<<"\n";
insert_first(head,n3);
insert_first(head,n2);
insert_first(head,n1);
printlist(head);
cout<<listsize(head)<<"\n";

node n4(40);
insert(head,2,n4);
printlist(head);
listdelete(head,2);
printlist(head);

    return 0;
}