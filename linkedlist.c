#include <stdio.h>
#include <stdlib.h>

struct student
{
    int data;
    struct student* next;
};

struct student *start = NULL;

void printLinkedList()
{
    struct student *i = start;
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

    struct student *newNode;
    newNode = (struct student*)malloc(sizeof(struct student));
    newNode->data = n;

    if (start == NULL)
    {
        newNode->next = NULL;
        start = newNode;
    }
    else
    {
        newNode->next = start;
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

    struct student* i = start;

    if (i == NULL)
    {
        start = newNode;
    }
    else
    {
        while (i->data != pos)
        {
            i = i->next;
        }
        newNode->next = i->next;
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
        start=temp->next;
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
        start=NULL;
    }
    else
    {

        struct student *i=start;
        while(i->next->next!=NULL)
        {
            i=i->next;
        }

        i->next=NULL;
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

    }else if(start->data==x)
    {
        start=start->next;
    }

    else
    {


        struct student *i=start;
        while(i->next->data!=x)
        {
            i=i->next;
        }

        i->next=i->next->next;
    }

}
int main()
{
    insertBegin();
    insertBegin();
    insertBegin();
    printLinkedList();

    insertBegin();
    printLinkedList();
    insertAny();
    printLinkedList();
    deleteFirst();
    printLinkedList();
    deleteEnd();
    printLinkedList();
    deleteAny();
    printLinkedList();


     deleteAny();
     printLinkedList();
    return 0;


}
