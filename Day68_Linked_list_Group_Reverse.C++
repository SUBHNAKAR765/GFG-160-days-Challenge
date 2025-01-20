// PROBLEM: Linked List Group Reverse

// Given the head a linked list, the task is to reverse every k node in the linked list. If the number of nodes is not a multiple of k then the left-out nodes in the end, should be considered as a group and must be reversed.

// Examples:

// Input: head = 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8, k = 4
// Output: 4 -> 2 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5
// Explanation: The first 4 elements 1, 2, 2, 4 are reversed first and then the next 4 elements 5, 6, 7, 8. Hence, the resultant linked list is 4 -> 2 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5.

// Input: head = 1 -> 2 -> 3 -> 4 -> 5, k = 3
// Output: 3 -> 2 -> 1 -> 5 -> 4
// Explanation: The first 3 elements 1, 2, 3 are reversed first and then left out elements 4, 5 are reversed. Hence, the resultant linked list is 3 -> 2 -> 1 -> 5 -> 4.

// Constraints:
// 1 <= size of linked list <= 105
// 1 <= data of nodes <= 106
// 1 <= k <= size of linked list 

// SOLUTION: 

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        Node* temp=new Node(1);
        Node* h1=head;
        Node* start=NULL;
        
        while(h1){
            int t = k;
            Node* prev=NULL;
            while(t-- && h1){
                start = h1->next;
                h1->next =prev;
                prev = h1;
                h1= start;
            }
            Node* j=temp;
            while(j->next != NULL)j=j->next;
            j->next=prev;
        }
        temp = temp->next;
        return temp;
    }
};
