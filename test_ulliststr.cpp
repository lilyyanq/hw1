#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;
//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr list;
  list.push_back("cs104");
  list.push_back("homework1");
  cout << "Front: " << list.front() << endl;
  cout << "Back: " << list.back() << endl;
  cout << "Size: " << list.size() << endl;
  list.push_front("first");
  cout << "Front: " << list.front() << " Back: " << list.back() << endl;
  list.pop_back();
  cout << "Size: " << list.size() << endl;
  cout << "Back: " << list.back() << endl;
  list.pop_front();
  cout << "Size after pop_front: " << list.size() << endl;
  cout << "Front: " << list.front() << endl;
  list.push_back("foo");
  list.push_back("end");
}
