#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

void print_list(node_t * head) {
    node_t * current = head;
    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

void push(node_t * head, int val) {
    node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

int pop(node_t * head) {
    int retval = 0;

    if (head->next == NULL) {
        retval = head->val;
        // free(head);
        return retval;
    }

    node_t * current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    retval = current->next->val;

    free(current->next);
    current->next = NULL;
    return retval;
}

void remove_by_index(node_t * head, int n) {
    node_t * current = head;
    int index = 0;
    while (current->next != NULL) {
        if (index == n-1) {
            current->next = current->next->next;
        }
        index++;
        current = current->next;
    }
}

int main() {
    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    head->val = 1;
    head->next = NULL;
    push(head, 2);
    push(head, 3);
    push(head, 4);
    push(head, 5);

    print_list(head);
    printf("-----------------------------------\n");
    printf("%i\n", pop(head));
    printf("-----------------------------------\n");
    print_list(head);
    remove_by_index(head, 2);
    printf("-----------------------------------\n");
    print_list(head);
    free(head);
    return 0;
}