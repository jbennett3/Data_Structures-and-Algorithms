//Binary search tree that operates using strings for data input of the nodes
//the tree can insert a string node, it can erase a string from tree,it can count number of occurrences of string,
// also it can print the contents of the tree in a sorted order.
#include <iostream>
#include<string>
#include "binary_search_tree.h"
using namespace std;

int main()
{
   BinarySearchTree t;
   t.insert("C");
   t.insert("D");
   t.insert("L");
   t.erase("D");
   t.print();
   cout << "There are  was " << t.count("L")<<" L counted" << endl;
   cin.get();
   return 0;
}
