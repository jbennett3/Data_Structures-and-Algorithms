#include <iostream>
#include "tree_rotations.h"
using namespace std;
BinarySearchTree::BinarySearchTree()
{//create an epmpty constructor by setting root null
  root=nullptr;
}
void BinarySearchTree::insert(int element)
{
    //first step creat new node
    Node *temp = new Node();//temp node will contain the new element that will be passed in add_node
    temp->key = element;
    temp->left = nullptr;
    temp->right = nullptr;
    if(root==nullptr)//case were the root is empty -> empty tree
    {
        root=temp;//then the new node will be the root
    }
    else//if the tree is not emptpy call add_node and decide where the new node will go
    {
    add_node(root,temp);
    }


}

Node* BinarySearchTree::findNode(int key )const
{
    Node *tree =root;//make the temp the root
    if(tree==nullptr)
    {
        return 0;//if the treee is empty then return 0
    }

   while(tree!=nullptr)//if the tree is not empty then look at both sides
   {
       if(key==tree->key)//when element is found return tree
       {

          return tree;
         break;
       }
       else if (key< tree->key)//if the element is less than data in tree keep looking in the left side of tree
       {
           tree = tree->left;
       }
        else//if the element is greater than the data in the tree look on the right side of the tree
       {
           tree=tree->right;
       }
   }
}
void BinarySearchTree::add_node( Node *parent, Node *new_node)const
{
    if(parent==nullptr)//if the root/tree empty make root the new node
    {
        parent=new_node;
        return;
    }

    else if(new_node->key>=parent->key){//if the element in the node is greater thatn parent put node in right subtree
        if(parent->right!=nullptr){
        add_node(parent->right,new_node);
        }
        else{
        parent->right=new_node;//case where there is no right right child  and element is greater than paraent data
        }
       }
     else if(new_node->key<=parent->key){//if the element in the node is lesser thatn parent put node in left subtree
        if(parent->left!=nullptr)
        {
            add_node(parent->left,new_node);
        }
        else
        {
             parent->left=new_node;//case where there is no left child and element is less than parent
        }

        }
   }

void BinarySearchTree::rotateRight(Node *pivot)
   {

     Node *parent = findParentNode(pivot);//find parent of pivot
      Node *grandp = findParentNode(parent);//find the grand parent of pivot which is the parent of the parent
      if(pivot->right!=nullptr)//as long as the pivot has a right child
      {
          parent->left=pivot->right;//set the parent's left child to pivots right child
          pivot->right=parent;//and have the pivot right become the parent
      }
      if(grandp->left->key==parent->key)//set grand parent left child to pivot value if parent key is equal to
      {                                   //grand parent's left child
          grandp->left=pivot;
      }
      else//or set the grand parent right child to the pivot value
      {
          grandp->right=pivot;
      }

   }
void BinarySearchTree::rotateLeft(Node *pivot)
   {
      Node *parent = findParentNode(pivot);//find the parent and grandparents of pivot
      Node *grandp = findParentNode(parent);
      if(pivot->left!=nullptr)//if the pivot has a left child
      {
          parent->right=pivot->left;//have the parent's right child equal to the pivot's left child
          pivot->left=parent;//now have the pivot left as the parent
      }
      if(grandp->right->key==parent->key)//move the grand parent's right child to pivot
      {
          grandp->right=pivot;
      }
      else//or move the grandparent's left child
      {
          grandp->left=pivot;
      }

   }
 pivotFamily BinarySearchTree::findFamily(Node* pivot)
 {
     Node *parent = findParentNode(pivot);//set parent node to parent of pivot
     pivotFamily Fam;
     Fam.pivot=pivot;//set the pivot's left and right children with pivot->left and pivot->right
     Fam.pivot_leftchild = pivot->left;
     Fam.pivot_rightchild = pivot->right;
     Fam.pivot_parent = parent;//set the parent's left and right children
     Fam.pivot_parent_rightchild = parent->right;
     Fam.pivot_parent_leftchild = parent->left;
     return Fam;//return the family adrresses for all the nodes
 }
Node* BinarySearchTree::findParentNode(Node* node)const
{
  Node* temp = root;//set temp to root
  Node* parent = nullptr;
  while((temp!=nullptr) && (temp->key!=node->key))
{//determine if the node you are looking for is in the left subtree or right subtree
    parent = temp;//once value is found have parent set to that node
    if(node->key<temp->key)
{
    temp = temp->left;
}
    else
    {
      temp = temp->right;
    }

}//return the parent's node address
return parent;
}

void BinarySearchTree::pretty_display()
{
   if (root == nullptr)
    return;
   printPretty(root, 1, 0, cout);
}

int BinarySearchTree::maxHeight(Node *p) const {
    if (!p) return 0;
    int leftHeight = maxHeight(p->left);
    int rightHeight = maxHeight(p->right);
    return (leftHeight > rightHeight) ? leftHeight + 1: rightHeight + 1;
}

// Convert an integer value to string
string BinarySearchTree::intToString(int val) {
  ostringstream ss;
  ss << val;
  return ss.str();
}

// Print the arm branches (eg, /    \ ) on a line
void BinarySearchTree::printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<Node*>& nodesQueue, ostream& out) {
  deque<Node*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel / 2; i++) {
    out << ((i == 0) ? setw(startLen-1) : setw(nodeSpaceLen-2)) << "" << ((*iter++) ? "/" : " ");
    out << setw(2*branchLen+2) << "" << ((*iter++) ? "\\" : " ");
  }
  out << endl;
}

// Print the branches and node (eg, ___10___ )
void BinarySearchTree::printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<Node*>& nodesQueue, ostream& out) {
  deque<Node*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen)) << "" << ((*iter && (*iter)->left) ? setfill('_') : setfill(' '));
    out << setw(branchLen+2) << ((*iter) ? intToString((*iter)->key) : "");
    out << ((*iter && (*iter)->right) ? setfill('_') : setfill(' ')) << setw(branchLen) << "" << setfill(' ');
  }
  out << endl;
}

// Print the leaves only (just for the bottom row)
void BinarySearchTree::printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<Node*>& nodesQueue, ostream& out) {
  deque<Node*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? setw(indentSpace+2) : setw(2*level+2)) << ((*iter) ? intToString((*iter)->key) : "");
  }
  out << endl;
}

// Pretty formatting of a binary tree to the output stream
// @ param
// level  Control how wide you want the tree to sparse (eg, level 1 has the minimum space between nodes, while level 2 has a larger space between nodes)
// indentSpace  Change this to add some indent space to the left (eg, indentSpace of 0 means the lowest level of the left node will stick to the left margin)
void BinarySearchTree::printPretty(Node *root, int level, int indentSpace, ostream& out) {
  int h = maxHeight(root);
  int nodesInThisLevel = 1;

  int branchLen = 2*((int)pow(2.0,h)-1) - (3-level)*(int)pow(2.0,h-1);  // eq of the length of branch for each node of each level
  int nodeSpaceLen = 2 + (level+1)*(int)pow(2.0,h);  // distance between left neighbor node's right arm and right neighbor node's left arm
  int startLen = branchLen + (3-level) + indentSpace;  // starting space to the first node to print of each level (for the left most node of each level only)

  deque<Node*> nodesQueue;
  nodesQueue.push_back(root);
  for (int r = 1; r < h; r++) {
    printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
    branchLen = branchLen/2 - 1;
    nodeSpaceLen = nodeSpaceLen/2 + 1;
    startLen = branchLen + (3-level) + indentSpace;
    printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);

    for (int i = 0; i < nodesInThisLevel; i++) {
      Node *currNode = nodesQueue.front();
      nodesQueue.pop_front();
      if (currNode) {
	      nodesQueue.push_back(currNode->left);
	      nodesQueue.push_back(currNode->right);
      } else {
        nodesQueue.push_back(NULL);
        nodesQueue.push_back(NULL);
      }
    }
    nodesInThisLevel *= 2;
  }
  printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
  printLeaves(indentSpace, level, nodesInThisLevel, nodesQueue, out);
}
