#ifndef TREE_ROTATIONS_H
#define TREE_ROTATIONS_H

#include <string>
#include <iostream>
#include <iomanip>      // std::setw
#include <deque>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;



class Node {
    private:
        int key;
        Node* left;
        Node* right;
        friend class BinarySearchTree;
};

struct pivotFamily {
    Node *pivot;
    Node *pivot_leftchild;
    Node *pivot_rightchild;
    Node *pivot_parent;
    Node *pivot_parent_leftchild;
    Node *pivot_parent_rightchild;
};

/*
   This class implements a binary search tree whose
   nodes hold strings.
*/
class BinarySearchTree {
    public:
        BinarySearchTree();
        void insert(int element);
        void pretty_display();
        /* Tree rotation */
        Node* findNode(int key) const; // Returns the address of the node containing key
        Node* findParentNode(Node *node) const; // Returns address of the parent of node containing key
        pivotFamily findFamily(Node *pivot);  // Returns all nodes needed for rotation given pivot parent
        void rotateRight(Node *pivot);
        void rotateLeft(Node *pivot);
    private:
        void add_node(Node* parent, Node* new_node) const;
        /* To pretty print binary tree */
        int maxHeight(Node *p) const;
        string intToString(int val);
        void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<Node*>& nodesQueue, ostream& out);
        void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<Node*>& nodesQueue, ostream& out);
        void printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<Node*>& nodesQueue, ostream& out);
        void printPretty(Node *root, int level, int indentSpace, ostream& out);

        Node* root;
};
#endif
