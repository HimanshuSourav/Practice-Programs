// Project2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


typedef struct Node {
    int data;
    Node* next;
}Node;

void LinkedList();
unsigned int DisplayMenu();
void AddToList(Node*);
void CreateList(Node*);
void DisplayNodes(Node* Head);
void ReverseList(Node* Head);
Node* removeNthFromEnd(Node* head, int n);

Node* removeNthFromEndRecursion(Node* head, int n);

int main()
{
    std::cout << "Hello World!\n";

    //1. Linked List
    LinkedList();
}


void LinkedList()
{
    //0. List
    Node* Head = (Node*)malloc(sizeof(Node));
    if(Head==NULL)
        EXIT_FAILURE;
    Head->data = 0;
    Head->next = NULL;

    //1. Display Menu
    int ch = DisplayMenu();

    switch (ch)
    {
        case 0:
            //a. add/create list
            AddToList(Head);
            break;
        case 1:
            //b. insert at position
            break;
        case 2:
            //c. delete at position/element
            break;
        case 3:
            //d. reverse the list
            ReverseList(Head);
            printf("\n-------------Reversed--------\n");
            DisplayNodes(Head);
            break;
        case 4:
            //e. create linked list with n nodes
            CreateList(Head);
            DisplayNodes(Head);
          
            
            break;
        case 5:
            //f. delete Nth node from end
            CreateList(Head);
            DisplayNodes(Head);
            removeNthFromEndRecursion(Head, 6);
            printf("\n-------------After deletion of Nth Node--------\n");
            DisplayNodes(Head);
        default:
            EXIT_FAILURE;
            break;
    }
}

unsigned int DisplayMenu()
{
    unsigned int ch;

    printf("\nAdd Node\t\t:0"
           "\nDelete Node\t\t:1"
        "\ncreate linked list\t:4"
           "\nEnter Choice:");
    scanf_s(" %d", &ch);
    return ch;
}

void DisplayNodes(Node* Head)
{
    Node* Current = Head;
    unsigned count = 1;
    while (Current != NULL)
    {
        printf("\nAddress:(0x%p) | Node %d: | data:%d next:%p", Current, count, Current->data, Current->next);
        Current = ((Node*)(Current->next));
        count++;
    }
}
void AddToList(Node* Head)
{

    Node *New = (Node*)malloc(sizeof(Node));
    Node *Curr;
    printf("\nEnter Node Value to Enter:");
    scanf_s("%d", New->data);
    
    Curr = Head;
    while(Curr)
    {
        if (Curr->next)
            Curr = Curr->next;
        else
        {
            Curr->next = New;
            break;
        }
    }
    DisplayNodes(Head);
    

    
}

void CreateList(Node* Head)
{
    Node* Curr = Head;

    for (unsigned int i = 0; i < 10; i++)
    {
        Curr->data = i;
        
        
        if (i == 9)
        {
            Curr->next = NULL;
        }
        else
        {
            Curr->next = (Node*)malloc(sizeof(Node));
            if (Curr->next == NULL)
                printf("OOM");
            Curr = ((Node*)Curr->next);
        }
            
    }
    Curr = NULL;
}

void ReverseList(Node* Head)
{
    Node* Prev = NULL;
    Node* Curr = Head;
    Node* Next = NULL;

    while (Curr != NULL)
    {
        Next = Curr->next;
        Curr->next = Prev;
        Prev = Curr;
        Curr = Next;
    }
    Head = Prev;
    DisplayNodes(Head);
}


Node* removeNthFromEnd(Node* head, int n) {
    if (head == NULL)
        return head;

    unsigned int Count = 0;
    Node* Curr = NULL, * Temp = NULL;
    Curr = head;
    while (Curr->next != NULL)
    {
        Curr = Curr->next;
        Count++;
    }

    
    if (head != NULL)
    {
        Curr = head;
        for (unsigned int i = 1; (i <= Count - n + 1); i++)
        {
            Temp = Curr;
            Curr = Curr->next;

        }
        if(Temp !=NULL && Curr !=NULL)
         Temp->next = Curr->next;
        //free(Curr);
        return head;
    }
    else
        return head;
}


Node* removeNthFromEndRecursion(Node* head, int n) {

    if (head == NULL)
        return head;

    head->next = removeNthFromEndRecursion(head->next, n);
    n = n - 1;
    
    if (n == 0)
        return head->next;

    return head;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

