#include <stdio.h>
#include <stdlib.h>

struct student
{
    int data;
    struct student* next;
    struct student* prev;
};

struct student* start = NULL;

void printLinkedList()
{
    struct student* i = start;
    while (i != NULL)
    {
        printf("%d ->", i->data);
        i = i->next;
    }
}

void insertBegin()
{
    int n;
    printf("Enter a number to insert begin: ");
    scanf("%d", &n);

    struct student* newNode;
    newNode = (struct student*)malloc(sizeof(struct student));
    newNode->data = n;
    newNode->prev = NULL;
    if (start == NULL)
    {
        newNode->next = NULL;
        start = newNode;
    }
    else
    {
        newNode->next = start;
        start->prev = newNode;
        start = newNode;
    }
}

void insertEnd()
{
    int n;
    printf("Enter number to insert end: ");
    scanf("%d", &n);

    struct student* newNode;
    newNode = (struct student*)malloc(sizeof(struct student));
    newNode->data = n;
    newNode->next = NULL;
    newNode->prev = NULL;

    struct student* i;
    i = start;

    if (i == NULL)
    {
        start = newNode;
    }
    else
    {
        while (i->next != NULL)
        {
            i = i->next;
        }
        i->next = newNode;
        newNode->prev = i;
    }
}

void insertAny()
{
    int n, pos;
    printf("Enter number to insert anywhere: ");
    scanf("%d", &n);
    printf("Enter the number after which you want to insert: ");
    scanf("%d", &pos);

    struct student* newNode;
    newNode = (struct student*)malloc(sizeof(struct student));
    newNode->data = n;
    newNode->next = NULL;
    newNode->prev = NULL;

    struct student* i = start;

    if (i == NULL)
    {
        start = newNode;
    }
    else
    {
        while (i != NULL && i->data != pos)
        {
            i = i->next;
        }
        if (i == NULL)
        {
            printf("Position not found!\n");
            free(newNode);
            return;
        }
        newNode->next = i->next;
        newNode->prev = i;
        if (i->next != NULL)
        {
            i->next->prev = newNode;
        }
        i->next = newNode;
    }
}

void deleteFirst()
{
    if(start==NULL)
    {
        printf("There is no element to delete!");
    }
    else
    {
        struct student *temp=start;
        start=start->next;
        if (start != NULL)
        {
            start->prev = NULL;
        }
        free(temp);
    }
}

void deleteEnd()
{
    if(start==NULL)
    {
        printf("There is no element to delete: ");
    }
    else if(start->next==NULL)
    {
        free(start);
        start=NULL;
    }
    else
    {
        struct student *i=start;
        while(i->next!=NULL)
        {
            i=i->next;
        }
        i->prev->next=NULL;
        free(i);
    }
}

void deleteAny()
{
     int x;
    printf("Which element you want to delete:");
    scanf("%d",&x);

    if(start==NULL)
    {
        printf("There is no element to delete: ");
    }
    else
    {
        struct student *i=start;
        while(i!=NULL && i->data!=x)
        {
            i=i->next;
        }
        if(i==NULL)
        {
            printf("Element not found!");
            return;
        }
        if(i->prev!=NULL)
        {
            i->prev->next=i->next;
        }
        else
        {
            start=i->next;
        }
        if(i->next!=NULL)
        {
            i->next->prev=i->prev;
        }
        free(i);
    }
}

int main()
{
    insertBegin();
    insertBegin();
    insertBegin();
    printLinkedList();

    deleteAny();
    printLinkedList();
}

