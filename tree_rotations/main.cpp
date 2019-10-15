#include <iostream>
#include "tree_rotations.h"
#include "tree_rotations_test.cpp"
using namespace std;

int main()
{
   BinarySearchTree t;
   t.insert(2);
   t.insert(1);
   t.insert(3);
   t.insert(7);
   t.insert(10);
   t.insert(2);
   t.insert(5);
   t.insert(8);
   t.insert(6);
   t.insert(4);
   t.pretty_display();
   Node *n = t.findNode(5);
   cout << "Node with element 5: " << n << " And parent is " << t.findParentNode(n) << endl;
   pivotFamily pFam_R = t.findFamily(n);
   cout << "pivot parent: " << pFam_R.pivot_parent << " pivot: " << pFam_R.pivot << " pivot left child: " << pFam_R.pivot_leftchild << " pivot right child: " << pFam_R.pivot_rightchild << " pivot parent right child: " << pFam_R.pivot_parent_rightchild << endl;
   cout << "Rotate right" << endl;
   t.rotateRight(n);
   t.pretty_display();
   n = t.findNode(7);
   pivotFamily pFam_L = t.findFamily(n);
   cout << "Rotate left" << endl;
   t.rotateLeft(n);
   t.pretty_display();
   return 0;
}
