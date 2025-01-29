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

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  if(in == NULL)
  {
    return;
  }
  Node* curr = in;
  in = in->next; //the next value
  if(curr->value % 2 == 0) //even number
  {
    curr->next = evens; //move to evens list
    evens = curr;
  }
  if(curr->value % 2 == 1)//odd number
  {
    curr->next = odds;
    odds = curr;
  }
  split(in, odds, evens);//recursive call
}

/* If you needed a helper function, write it here */
