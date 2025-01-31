/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include<cstdlib>

void append(Node*& list, Node*& node);

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  if(in == NULL)
  {
    return;
  }
  Node* curr = in; //the next value
  in = in->next; //disconnect
  curr->next = NULL;
  if(curr->value % 2 == 0) //even number
  {
    append(evens, curr);
  }
  else//odd number
  {
    append(odds, curr);
  }
  split(in, odds, evens);//recursive call
}

/* If you needed a helper function, write it here */
void append(Node*& list, Node*& node)
{
  if(list == NULL||list->value >= node->value)
  {
    node->next = list;
    list = node;
    return;
  }
  append(list->next, node);
}