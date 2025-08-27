#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100000

// Stack implementation
typedef struct {
    int data[MAX];
    int top;
} Stack;

void push(Stack *s, int value) {
    s->data[++(s->top)] = value;
}

int pop(Stack *s) {
    return s->data[(s->top)--];
}

int peek(Stack *s) {
    return s->data[s->top];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int q;
    scanf("%d", &q);

    Stack s1, s2;  // s1 for enqueue, s2 for dequeue
    s1.top = -1;
    s2.top = -1;

    for (int i = 0; i < q; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int x;
            scanf("%d", &x);
            push(&s1, x);  // enqueue
        } 
        else if (type == 2) {
            // Move elements from s1 to s2 if s2 is empty
            if (isEmpty(&s2)) {
                while (!isEmpty(&s1)) {
                    push(&s2, pop(&s1));
                }
            }
            pop(&s2);  // dequeue
        } 
        else if (type == 3) {
            // Move elements from s1 to s2 if s2 is empty
            if (isEmpty(&s2)) {
                while (!isEmpty(&s1)) {
                    push(&s2, pop(&s1));
                }
            }
            printf("%d\n", peek(&s2));  // print front element
        }
    }

    return 0;
}   
