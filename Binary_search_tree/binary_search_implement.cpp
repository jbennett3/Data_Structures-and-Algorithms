#include "binary_search_tree.h"
#include <iostream>
#include <string>
using namespace std;
BinarySearchTree::BinarySearchTree()
{//create an epmpty constructor by setting root null
  root=nullptr;
}
void BinarySearchTree::insert(string element)
{
    //first step creat new node
    Node *temp = new Node();//temp node will contain the new element that will be passed in add_node
    temp->data = element;
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
int  BinarySearchTree::count(string element) const
{
    Node *tree =root;//make the temp the root
    int found = 0;//will change to 1 if element is found or 0 if the item is not found
    if(tree==nullptr)
    {
        return found;//if the treee is empty then return 0
    }

   while(tree!=nullptr)//if the tree is not empty then look at both sides
   {
       if(element==tree->data)//element is found return 1 and leave
       {
           found = 1;
         return found;
         break;
       }
       else if (element< tree->data)//if the element is less than data in tree keep looking in the left side of tree
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

    else if(new_node->data>=parent->data){//if the element in the node is greater thatn parent put node in right subtree
        if(parent->right!=nullptr){
        add_node(parent->right,new_node);
        }
        else{
        parent->right=new_node;//case where there is no right right child  and element is greater than paraent data
        }
       }
     else if(new_node->data<=parent->data){//if the element in the node is lesser thatn parent put node in left subtree
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

void BinarySearchTree::erase(string element)
{
   int found  = 0;
   Node *parent = nullptr;
   Node *Current = root;
   if(Current==nullptr)//nothing in tree
   {
       cout<<"nothing in node"<<endl;
         return;
   }
   while(Current!=nullptr)//look for data if found begin erase procedure
   {
       if(Current->data==element)
       {
           found = 1;
           break;
       }
   else
 {
    parent = Current;

   if(element<Current->data)
       Current=Current->left;

   else
       Current=Current->right;
    }
   }

    if(!found)
    {
        cout<<"item "<<element<<"not found"<<endl;
        return;
    }
    //Case where node being deleted hase has no children
     if(Current->left==nullptr&&Current->right==nullptr)
   {
       if(parent->left==Current)
           parent->left=nullptr;
       else
           parent->right=Current;

        delete Current;
        return;
   }
    //case if the node has one child either on the left or the right
    //delete link to node and have the subtree link to the parent of the node that is being deleted
    if((Current->left==nullptr&&Current->right!=nullptr)||(Current->left!=nullptr&&Current->right==nullptr))
    {
        if(Current->left==nullptr&&Current->right!=nullptr)
        {
        if(parent->left==Current)
        {
            parent->left=Current->right;
            delete Current;
            Current=nullptr;
        }
        else
        {
            parent->right=Current->right;
            delete Current;
            Current =nullptr;
        }
    }
    else
    {
         if(parent->left==Current)
        {
            parent->left=Current->left;
            delete Current;
            Current=nullptr;
        }
        else
        {
            parent->right=Current->left;
            delete Current;
            Current =nullptr;
        }
    }

    return;
}


 //case where there are 2 children
   if(Current->left!=nullptr&&Current->right!=nullptr)
    {
        // try to find the minimum in the right sub tree and replace the node with two children with it
        // next remove the dulicate in this case the node you want to delete
      Node *some = Current->right;
       if((Current->left==nullptr)&&(Current->right==nullptr))
       {
           Current=some;
           delete some;
           Current->right=nullptr;

       }
      else
       {

           if(Current->right!=nullptr)
           {
               Node *new_leftc;
               Node *new_leftcparent;

               new_leftcparent=Current->right;
               new_leftc = Current;


              while(new_leftc->left!=nullptr)
               {
                   new_leftcparent = new_leftc;

                   new_leftc=new_leftc->left;

               }

               Current->data=new_leftc->data;

               delete new_leftc;
               new_leftc=nullptr;
               new_leftcparent->left=nullptr;


            }
           else{
               Node *t=Current->right;
               Current->data=t->data;
               Current->right=t->right;
               delete t;
               t=nullptr;

           }

     }

       return;
   }
}
void BinarySearchTree::print(Node *parent) const
{
    //this will print data in order
     if(parent!=nullptr)
        //recursively call the print fuction to show left side and root and right's data
       {
           if(parent->left!=nullptr)
           {
               //print the data on the left
            print(parent->left);

           }
           cout<<parent->data<<" ";//print data at root
           if(parent->right!=nullptr)
            //print data on right side
           {
               print(parent->right);
           }

       }
}
void BinarySearchTree::print()const
{
   print(root);//simply pass in the root and print data
}
