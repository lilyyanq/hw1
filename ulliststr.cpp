#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val)
{
  if(empty())//first Item(empty list)
  {
    head_ = new Item();
    head_->val[0] = val;
    head_->last = 1;
    tail_ = head_;
    size_++;
    return;
  }
  if(tail_->last < ARRSIZE)
  {
    tail_->val[tail_->last] = val;
    tail_->last++;//increase index
    size_++;
    return;
  }
  //if the array of this item is full
  Item* temp = new Item();
  temp->val[0] = val;
  temp->last = 1;
  temp->prev = tail_;
  tail_->next = temp;
  tail_ = temp;
  size_++;//number of strings in entire list
}

void ULListStr::pop_back()
{
  if(empty())
  {
    return;
  }
  if((tail_->last - tail_->first) == 1)
  {
    if(tail_->prev == nullptr)
    {
      delete tail_;
      head_ = tail_ = nullptr;
    }
    else
    {
      Item* temp = tail_;
      tail_ = tail_->prev;
      tail_->next = nullptr;
      delete temp;
    }
  }
  else//more than one element in tail node
  {
    tail_->last--;
  }
  size_--;
}

void ULListStr::push_front(const std::string& val)
{
  if(empty())
  {
    head_ = new Item();
    tail_ = head_;
    head_->val[0] = val;
    head_->last = 1;
  }
  else
  {
    if(head_->first > 0)//there is space in the array
    {
      head_->first--;
      head_->val[head_->first]= val;
    }
    else
    {
      Item* temp = new Item();
      temp->val[ARRSIZE-1] = val;
      temp->first = ARRSIZE - 1;
      temp->last = ARRSIZE; //no space in back
      temp->next = head_;
      head_->prev = temp;
      head_ = temp;
    }
  }
  size_++;
}

void ULListStr::pop_front()
{
   head_->first++;
   if(head_->first == head_->last)//if after deleting it becomes empty
   {
    if(head_ == tail_)//delete everything
    {
      delete head_;
      head_ = nullptr;
      tail_ = nullptr;
    }
    else
    {
      Item* temp = head_;
      head_ = head_->next;
      head_->prev = nullptr;
      delete temp;
    }
   }
   size_--;
}

std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last-1];
}

std::string const& ULListStr::front() const
{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if(loc >=size_)
  {
   return nullptr; //invalid 
  }
  Item* temp = head_;
  size_t location = loc;
  while(temp != nullptr)
  {
    size_t items = temp->last - temp->first;
    if(location < items)//it will be in this node
    {
      return &temp->val[temp->first + location];
    }
    //otherwise not in this node
    location -= items;
    temp = temp->next;
  }
  return nullptr; //if not found
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL)
  {
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
