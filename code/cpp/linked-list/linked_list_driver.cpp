/*

  linked_list_driver.cpp

 */

#include <cmath>
#include "UTFramework.h"
#include "linked_list.h"

#define EPSILON 0.0001

using namespace Thilenius;

node* build_three_node_list(int one, int two, int three) {
  node* head = new node;
  head->data = one;
  head->next = new node;
  head->next->data = two;
  head->next->next = new node;
  head->next->next->data = three;
  head->next->next->next = NULL;
  return head;
}

node* mknode(int data) {
  node* ret = new node;
  ret->data = data;
  ret->next = NULL;
  return ret;
}

void safe_check(node* head, int offset, int data) {
  int count = 0;
  node* cursor = head;
  while (count < offset) {
    if (cursor == NULL) {
      IsTrue("Null", cursor != NULL, "Found null pointer when looking for index");
      return;
    }
    cursor = cursor->next;
    count = count + 1;
  }
  if (cursor == NULL) {
      IsTrue("Null", cursor != NULL, "Found null pointer when looking for index");
      return;
  } else {
    IsTrue("Value", cursor->data == data, "Wrong data value");
  }
}

SUITE_BEGIN("Linked List")
TEST_BEGIN("InitNode")
{
  node* res = init_node(42);
  IsTrue("Null", res != NULL, "init_node returns NULL");
  if (res != NULL) {
    IsTrue("Value", res->data == 42, "Node data should be 42");
    if (res->data == 42) {
      delete res;
      bool next_ok = true;
      for (int i=0; i < 100000; i++) {
	node* n = init_node(i);
	if (n->next != NULL) {
	  next_ok = false;
	}
	delete n;
	if (!next_ok) {
	  break;
	}
      }
      if (!next_ok) {
	IsTrue("Next Ptr", false, "Be sure to initialize node's next pointer to NULL");
      }
    }
  }
}TEST_END

TEST_BEGIN("AppendData")
{
  node* empty = NULL;
  node** head_ptr = &empty;
  append_data(head_ptr, 611);
  IsTrue("Null", empty != NULL, "List should now have non-null head node.");
  if (empty != NULL) {
    IsTrue("Data", empty->data == 611, "List should have data == 611.");
  }
  append_data(head_ptr, -42);
  IsTrue("Null", empty != NULL, "First thing null");
  if (empty != NULL) {
    IsTrue("Null", empty->next != NULL, "Second thing null");
    if (empty->next != NULL) {
      IsTrue("Data", empty->next->data == -42, "List should have data == -42.");
    }
  }
  node* legit = build_three_node_list(10, 15, 20);
  append_data(&legit, 33);
  //  10               15                     20
  if (legit != NULL && legit->next != NULL && legit->next->next != NULL) {
    IsTrue("4th item Null", legit->next->next->next != NULL, 
	   "4th item is null.");
    if (legit->next->next->next != NULL) {
      IsTrue("4th item value", legit->next->next->next->data == 33,
	     "4th item value should be 33");
    }
  }
  
}TEST_END

TEST_BEGIN("Append")
{
  node* empty = NULL;
  node** head_ptr = &empty;
  node* append_me = mknode(611);
  append(head_ptr, append_me);
  IsTrue("Null", empty != NULL, "List should now have non-null head node.");
  if (empty != NULL) {
    IsTrue("Data", empty->data == 611, "List should have data == 611.");
  }
  append_me = mknode(-42);
  append(head_ptr, append_me);
  IsTrue("Null", empty != NULL, "First thing null");
  if (empty != NULL) {
    IsTrue("Null", empty->next != NULL, "Second thing null");
    if (empty->next != NULL) {
      IsTrue("Data", empty->next->data == -42, "List should have data == -42.");
    }
  }
  node* legit = build_three_node_list(10, 15, 20);
  append_me = mknode(33);
  append(&legit, append_me);
  //  10               15                     20
  if (legit != NULL && legit->next != NULL && legit->next->next != NULL) {
    IsTrue("4th item Null", legit->next->next->next != NULL, 
	   "4th item is null.");
    if (legit->next->next->next != NULL) {
      IsTrue("4th item value", legit->next->next->next->data == 33,
	     "4th item value should be 33");
    }
  }
}TEST_END

TEST_BEGIN("InsertData")
{
  node* head = NULL;
  node** head_ptr = &head;
  insert_data(head_ptr, 0, 42);
  safe_check(*head_ptr, 0, 42);
  insert_data(head_ptr, 0, 611);
  safe_check(*head_ptr, 0, 611);
  safe_check(*head_ptr, 1, 42);
  insert_data(head_ptr, 1, 50);
  safe_check(*head_ptr, 1, 50);  
  insert_data(head_ptr, 3, -1234);
  safe_check(*head_ptr, 3, -1234);
  insert_data(head_ptr, 6, 999); // should complete without segfault
  IsTrue("End", true, "");
}TEST_END

TEST_BEGIN("Insert")
{
  node* head = NULL;
  node** head_ptr = &head;
  insert(head_ptr, 0, mknode(42));
  safe_check(*head_ptr, 0, 42);
  insert(head_ptr, 0, mknode(611));
  safe_check(*head_ptr, 0, 611);
  safe_check(*head_ptr, 1, 42);
  insert(head_ptr, 1, mknode(50));
  safe_check(*head_ptr, 1, 50);  
  insert(head_ptr, 3, mknode(-1234));
  safe_check(*head_ptr, 3, -1234);
  insert(head_ptr, 6, mknode(999)); // should complete without segfault
  IsTrue("End", true, "");
}TEST_END

TEST_BEGIN("Remove")
{
  node* back = build_three_node_list(20, 30, 40);
  node* front = mknode(10);
  front->next = back;
  remove(&front, 0);
  IsTrue("Null", front != NULL, "front should still point to something");
  if (front != NULL) {
    IsTrue("Value", front->data == 20, "first data cell should be 20");
    remove(&front, 2);
    IsTrue("Sequence", front != NULL && front->next != NULL && front->next->next == NULL, 
	   "Should be 20, 30, NULL");
  }
  front = build_three_node_list(123, 234, 345);
  remove(&front, 1);
  bool structure_ok = (front != NULL && front->next != NULL && front->next->next == NULL);
  IsTrue("Sequence", structure_ok, "Delete from middle causes trouble");
  if (structure_ok) {
    IsTrue("Values", front->data == 123 && front->next->data == 345,
	   "Expecting 123, 345");
  }
}TEST_END

TEST_BEGIN("Size")
{
  node* head = NULL;
  int s = size(head);
  IsTrue("Empty", s == 0, "Empty should be 0 size");
  head = build_three_node_list(8, 4, 2);
  s = size(head);
  IsTrue("Three", s == 3, "Should have 3 things");

}TEST_END

SUITE_END

int main (int argc, char* argv[]) {	
  UTFrameworkInit;
}
