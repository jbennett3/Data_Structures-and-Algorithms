#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <iostream>
using namespace std;

/**
   This class implements a heap.
*/
template<typename T>
class Heap
{
public:
   /**
      Constructs an empty heap.
   */
   Heap()
   {
       vector<T>elements;
   }

   /**
      Adds a new element to this heap.
      @param element the element to add
   */
   void push(T element)
   {
      elements.push_back(element);
      fix_heap();
   }

   /**
      Gets the maximum element stored in this heap.
      @return the maximum element
   */
   T top() const
   {
        return elements.front();

   }

   /**
      Removes the maximum element from this heap.
   */
   void pop()
   {

       elements.at(0) = elements.back();
       elements.pop_back();
       fix_heap();
   }

   /**
      Gets the size of this heap.
      @return the size
   */
   int size() const
   {
       return (elements.size());
   }
private:
   /**
      Turns the tree back into a heap, provided only the root
      node violates the heap condition.
   */
vector<T> elements;
   void fix_heap()
   {

       for(int i =0;i<elements.size();++i)
       {

       int LEFT = get_left_child_index(i);
       int RIGHT = get_right_child_index(i);
       int smallest = i;
       if (LEFT>=elements.size())
       {
           return;
       }
       if(elements[LEFT]<elements[i])
       {
           smallest = LEFT;
       }
       if((RIGHT<elements.size()) && (elements.at(RIGHT)<elements.at(smallest)))
       {
           smallest = RIGHT;
       }
       if(smallest!=i)
       {
           swap(elements[i],elements[smallest]);
           fix_heap();
       }
       }

   }

   /**
      Returns the index of the left child.
      @param index the index of a node in this heap
      @return the index of the left child of the given node
   */
   int get_left_child_index(int index) const
   {
       return (2*index+1);
   }

   /**
      Returns the index of the right child.
      @param index the index of a node in this heap
      @return the index of the right child of the given node
   */
   int get_right_child_index(int index) const
   {
       return (2*index+2);
   }

   /**
      Returns the index of the parent.
      @param index the index of a node in this heap
      @return the index of the parent of the given node
   */
   int get_parent_index(int index) const
   {
       return (index-1)/2;
   }

   
};

#endif
