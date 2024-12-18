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

void insert_last(Node *head, Node *new) {
    while(head -> next != NULL) {
        head = head -> next;
    }
    head -> next = new;
    new -> next = NULL;
}

int delete_node(Node *head, int data) {
    int index = 1;
    while(head -> next != NULL) {
        if(head -> next -> data == data) {
            head -> next = head -> next -> next;
            printf("delete(%d)\n", data);
            return index;
        }
        index++;
        head = head -> next;
    }
    return -1;
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
    Node new;
    new.data = 100;
    insert_last(&n1, &new);
    printf("insert(%d)\n", new.data);
    show_list(&n1);
    printf("index=%d\n", delete_node(&n1, 7));
    show_list(&n1);
}
/*
| 10 | ->| 5 | ->| 3 | ->| 7 | -> NULL
insert(100)
| 10 | ->| 5 | ->| 3 | ->| 7 | ->| 100 | -> NULL
delete(7)
index=3
| 10 | ->| 5 | ->| 3 | ->| 100 | -> NULL

*/