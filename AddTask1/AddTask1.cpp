#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};
struct Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void SortList(struct Node* start)
{
    struct Node* ptr1, * ptr2;
    int t = 0;
    ptr1 = start;
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (ptr1->data > ptr2->next->data)
            {
                t = ptr1->data;
                ptr1->data = ptr2->next->data;
                ptr2->next->data = t;
                ptr2 = ptr2->next;
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

void printReverse(Node* head)
{
    if (head == NULL)
        return;
    printReverse(head->next);
    cout << head->data << " ";
}

void printList(struct Node* node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main()
{
    struct Node* start = newNode(113);
    start->next = newNode(12);
    start->next->next = newNode(11);
    start->next->next->next = newNode(11);
    start->next->next->next->next = newNode(12);
    start->next->next->next->next->next = newNode(11);
    start->next->next->next->next->next->next = newNode(10);
    printList(start);
    SortList(start);
    printf("\n");
    printList(start);
    printf("\n");
    printReverse(start);

    return 0;
}
