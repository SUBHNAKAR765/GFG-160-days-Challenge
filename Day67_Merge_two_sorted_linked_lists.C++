// PROBLEM: Merge two sorted linked lists

// Given the head of two sorted linked lists consisting of nodes respectively. The task is to merge both lists and return the head of the sorted merged list.

// Examples:

// Input: head1 = 5 -> 10 -> 15 -> 40, head2 = 2 -> 3 -> 20
// Output: 2 -> 3 -> 5 -> 10 -> 15 -> 20 -> 40
// Explanation:

// Input: head1 = 1 -> 1, head2 = 2 -> 4
// Output: 1 -> 1 -> 2 -> 4
// Explanation:

// Constraints:
// 1 <= no. of nodes<= 103
// 0 <= node->data <= 105

// SOLUTION: 

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        Node* dummy = new Node(0);
        Node* temp = dummy;
        Node*h1 = head1; 
        Node*h2 = head2;
        
        while(h1 && h2){
            if(h1->data < h2->data){
                temp->next = h1;
                temp = h1;
                h1 = h1->next;
            }
            else{
                temp->next = h2;
                temp = h2;
                h2 = h2->next;
            }
        }
        if(h2){
            temp->next = h2;
        }
        else{
            temp->next = h1;
        }
        return dummy->next;
    }
};
