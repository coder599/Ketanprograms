#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void display()
{
    struct node *temp = head;
    int i = 1;
    while (temp != NULL)
    {
        printf("%d = %d\n", i, temp->data);
        temp = temp->next;
        i++;
    }
}

void insertAtBegin(int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));

    new->data = data;
    new->next = head;
    head = new;
}

void insertAtPosition(int data, int index)
{
    struct node *temp = head;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;

    int i = 1;
    while (i < index - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    new->next = temp->next;
    temp->next = new;
}

void insertAtEnd(int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    new->next = NULL;
    new->data = data;
    temp->next = new;
}

void deleteAtBegin()
{
    if (head == NULL)
    {
        return;
    }

    struct node *temp = head;

    head = head->next;
    free(temp);
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        deleteAtBegin();
        return;
    }

    struct node *temp = head->next;
    struct node *pre = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
        pre = pre->next;
    }
    pre->next = NULL;
    free(temp);
}

void deleteAtPosition(int index)
{
    if (head == NULL)
    {
        return;
    }
    if (index == 1)
    {
        deleteAtBegin();
        return;
    }
    struct node *pre = head;
    struct node *curr = head->next;

    int i = 1;
    while (curr->next != NULL && i < index - 1)
    {
        curr = curr->next;
        pre = pre->next;
        i++;
    }
    if (curr != NULL)
    {
        pre->next = curr->next;
        free(curr);
    }
}

void main()
{
    int choice, data, index;
    while (1)
    {
        printf("********************* MENU *************************\n");
        printf("* 1. Display               2. Insert at Begin      *\n");
        printf("* 3. Insert at position    4. Insert at end        *\n");
        printf("* 5. Delet at Begin        6. Delete at position   *\n");
        printf("* 7. Delete at end         8. Exit                 *\n");
        printf("****************************************************\n\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            display();
            break;

        case 2:
            printf("Enter the data\n");
            scanf("%d", &data);
            insertAtBegin(data);
            break;

        case 3:
            printf("Enter the data\n");
            scanf("%d", &data);
            printf("Enter the index\n");
            scanf("%d", &index);
            insertAtPosition(data, index);
            break;

        case 4:
            printf("Enter the data\n");
            scanf("%d", &data);
            insertAtEnd(data);
            break;

        case 5:
            deleteAtBegin();
            break;

        case 6:
            printf("Enter the index\n");
            scanf("%d", &index);
            deleteAtPosition(index);
            break;

        case 7:
            deleteAtEnd();
            break;

        case 8:
            exit(0);

        default:
            printf("Error");
            break;
        }
    }
}