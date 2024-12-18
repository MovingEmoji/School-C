//Naoyda Iida
#include <stdio.h>

typedef struct Node{
    int data;
    struct Node *next; //次のノードへのポインタ
} Node;

void show_list(Node *head){
    Node *p = head;
    while(p != NULL){
        printf("| %d | ->", p->data);
        p = p->next;
    }
    printf(" NULL\n");
}

int list_len(Node *head) {
    int cnt = 0;
    if(head != NULL) {
        cnt++;
    }
    while(head -> next != NULL) {
        head = head -> next;
        cnt++;
    }
    return cnt;
}


int main(){
    Node n1, n2, n3, n4;
    n1.data = 10;
    n2.data = 5;
    n3.data = 3;
    n4.data = 7;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = NULL;
    show_list(&n1);
    printf("list_len() = %d", list_len(&n1));
}
/*
| 10 | ->| 5 | ->| 3 | ->| 7 | -> NULL
list_len() = 4

*/