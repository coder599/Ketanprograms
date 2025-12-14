#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node *next;
};

struct Node *top = NULL;

void push(char c) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = c;
    newNode->next = top;
    top = newNode;
}

char pop() {
    if (top == NULL) {
        return '\0'; 
    }
    char c = top->data;
    struct Node *temp = top;
    top = top->next;
    free(temp);
    return c;
}

int isEmpty() {
    return top == NULL;
}

int isPalindrome(char str[]) {
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        push(str[i]);
    }

    for (int i = 0; i < len; i++) {
        if (str[i] != pop()) {
            return 0; 
        }
    }

    return 1; 
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str))
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}
