#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
This program uses a stack to check whether an expression has balanced
parentheses.

A bracket is considered to be any one of the following characters: (, ), {, }, [, or ].
Two brackets are considered to be a matched pair if the an opening bracket (i.e., (, [, or {) occurs to the left of a closing bracket (i.e., ), ], or }) of the exact same type. There are three types of matched pairs of brackets: [], {}, and ().
A matching pair of brackets is not balanced if the set of brackets it encloses are not matched. For example, {[(])}is not balanced because the contents in between { and } are not balanced. The pair of square brackets encloses a single, unbalanced opening bracket, (, and the pair of parentheses encloses a single, unbalanced closing square bracket, ].
By this logic, we say a sequence of brackets is considered to be balanced if the following conditions are met:
It contains no unmatched brackets.
The subset of brackets enclosed within the confines of a matched pair of brackets is also a matched pair of brackets.
Given  strings of brackets, determine whether each sequence of brackets is balanced.
*/
bool parenMatch(string expression);
bool match(char s1,char s2);//check if elements make a pair
int main()
{
string expr1 = "(()()()())";
string expr2 = "{[(])}";
string expr3 = "(()){}()";
string expr4 = "{[(])}";
string expr5 = "{[()]}";
if (parenMatch(expr1))
cout << "Parantheses balanced in expr1" << endl;
else
cout << "Parentheses unbalanced in expr1" << endl;
if (parenMatch(expr2))
cout << "Parantheses balanced in expr2" << endl;
else
cout << "Parentheses unbalanced in expr2" << endl;
if (parenMatch(expr3))
cout << "Parantheses balanced in expr3" << endl;
else
cout << "Parentheses unbalanced in expr3" << endl;
if (parenMatch(expr4))
cout << "Parantheses balanced in expr4" << endl;
else
cout << "Parentheses unbalanced in expr4" << endl;
if (parenMatch(expr5))
cout << "Parantheses balanced in expr5" << endl;
else
cout << "Parentheses unbalanced in expr5" << endl;
return 0;
}
bool parenMatch(string expression)
{
  stack<char> s;

  for (unsigned int  i = 0; i<expression.length(); i++)//iterate through string expression
  {
  if (expression[i] == '('||expression[i] == '{'||expression[i]=='[')//when there is a open bracket push element into stack
        {

        s.push(expression[i]);
        }

    else if (expression[i] == ']' || expression[i] == '}'|| expression[i] == ')')//when encountering closed brackets
        {
           if(s.empty()||!match(s.top(),expression[i]))//see stack is empty
            // call match function to check if the closing bracket is a matching pair to the top element
            return false;
           else
           { //pop bracket off of stack
               s.pop();
           }
           }
       }
return s.empty();//if the stack in the end is empty then string is balanced otherwise it is unbalanced
    }
bool match(char s1,char s2)//match function checks if the top element is a pair with any of the closing brackets
{//this helps further refine the pop function so you don't always have an empty stack if there balancing pairs
    if( s1 == '[' &&  s2 == ']')
        return true;
    else if ( s1 == '{' &&  s2 == '}')
        return true;
    else if ( s1 == '(' &&  s2 == ')')
    return true;
    else
        return false;
}
