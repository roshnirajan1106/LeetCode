// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


 // } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int val;
    struct Node *next;
    Node(int x) {
        val = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        map<Node*,int>visited;
        Node *prev = NULL;
        Node*tail = NULL;
        Node*temp = head;
        while(temp->next != NULL)
        temp = temp->next;

        tail = temp;
        temp = head;
        
        while(temp  != NULL)
        {
            if(visited[temp] == 1)
            {
                return head;
            }
            else{
                visited[temp] = 1;
                if(temp->data == 0)
                {
                    if(prev == NULL)
                    {
                        prev = temp;
                        temp = temp->next;
                    }else{
                        prev->next =temp->next;
                        temp->next = head;
                        head = temp;
                        temp = prev->next;
                    }
                }
                else if(temp->data == 2)
                {
                    if(prev == NULL)
                    {
                        head = temp->next;
                        
                        tail->next = temp;
                        temp->next = NULL;
                        tail = temp;
                        temp = head;
                        
                    }else{
                        prev->next = temp->next;
                        tail->next = temp;
                        temp->next = NULL;
                        tail = temp;
                        temp = prev->next;
                    }
                }
                else{
                    prev = temp;
                    temp = temp->next;
                }
            }
        }
        return head;
    }
};


// { Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}  // } Driver Code Ends