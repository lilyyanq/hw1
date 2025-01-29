/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/
#include<cstdlib>
#include "split.h"

void deleteList(Node* head)
{
  if(head != nullptr)
  {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
}
int main(int argc, char* argv[])
{
  Node *in = NULL;
  Node *odds = NULL;
  Node * evens = NULL;
  Node* current = NULL;
  for(int i = 0; i < argc; i++)
  {
    int number = atoi(argv[i]);
    Node* newNode = new Node(number, NULL);
    if(in == NULL)
    {
      in = newNode;
      current = in;
    }
    else
    {
      current->next = newNode;
      current = newNode;
    }
  }
  split(in, odds, evens);
  deleteList(odds);
  deleteList(evens);
  return 0;
}
