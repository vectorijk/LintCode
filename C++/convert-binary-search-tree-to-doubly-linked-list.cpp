// Time:  O(n)
// Space: O(h)

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 * Definition of Doubly-ListNode
 * class DoublyListNode {
 * public:
 *     int val;
 *     DoublyListNode *next, *prev;
 *     DoublyListNode(int val) {
 *         this->val = val;
           this->prev = this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
    DoublyListNode* bstToDoublyList(TreeNode* root) {
        DoublyListNode *prev = nullptr, *head = nullptr;
        treeToDoublyList(root, &prev, &head);
        return head;
    }

    void treeToDoublyList(TreeNode *p, DoublyListNode **prev, DoublyListNode **head) {
      if (!p) {
          return;
      }
      treeToDoublyList(p->left, prev, head);
      DoublyListNode *root = new DoublyListNode(p->val);
      if (!*prev) {
          *head = root;
      } else {
          root->prev = *prev;
          (*prev)->next = root;
      }
      *prev = root;
      treeToDoublyList(p->right, prev, head);
    }
};




// A simple recursive function to convert a given Binary tree to Doubly
// Linked List
// root --> Root of Binary Tree
// head --> Pointer to head node of created doubly linked list
void BinaryTree2DoubleLinkedList(node *root, node **head)
{
    // Base case
    if (root == NULL) return;
 
    // Initialize previously visited node as NULL. This is
    // static so that the same value is accessible in all recursive
    // calls
    static node* prev = NULL;
 
    // Recursively convert left subtree
    BinaryTree2DoubleLinkedList(root->left, head);
 
    // Now convert this node
    if (prev == NULL)
        *head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
 
    // Finally convert right subtree
    BinaryTree2DoubleLinkedList(root->right, head);
}
