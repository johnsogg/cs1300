/*

  linked_list_driver.cpp

 */

#include "linked_list.hpp"

#define EPSILON 0.0001

using namespace Thilenius;


Node* build_three_node_list(int one, int two, int three) {
  Node* head = new Node;
  head->data = one;
  head->next = new Node;
  head->next->data = two;
  head->next->next = new Node;
  head->next->next->data = three;
  head->next->next->next = NULL;
  return head;
}

Node* mknode(int data) {
  Node* ret = new Node;
  ret->data = data;
  ret->next = NULL;
  return ret;
}

void safe_check(Node* head, int offset, int data) {
  int count = 0;
  Node* cursor = head;
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

SUITE_BEGIN("Linked List (With C++ Classes)")

TEST_BEGIN("InitList")
{
  LinkedList list;
  IsTrue("Null Head", list.getHead() == NULL, "Empty list should have NULL head.");
}TEST_END

TEST_BEGIN("AppendData")
{
  Node* top = NULL;
  LinkedList list;
  IsTrue("Null", list.getHead() == NULL,
	 "Empty list should have null head node.");
  list.append_data(611);
  IsTrue("Null", list.getHead() != NULL, 
	 "List should now have non-null head node.");
  if (list.getHead() != NULL) {
    IsTrue("Data", list.getHead()->data == 611, "List should have data == 611.");
  }
  list.append_data(-42);
  IsTrue("Null", list.getHead() != NULL, "First thing null");
  top = list.getHead();
  if (top != NULL) {
    IsTrue("Null", top->next != NULL, "Second thing null");
    if (top->next != NULL) {
      IsTrue("Data", top->next->data == -42, "List should have data == -42.");
    }
  }
  Node* legit = build_three_node_list(10, 15, 20);
  list.setHead(legit);
  list.append_data(33);
  legit = list.getHead();
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
  Node* top = NULL;
  LinkedList list;
  Node* append_me = mknode(611);
  list.append(append_me);
  top = list.getHead();
  IsTrue("Null", top != NULL, "List should now have non-null head node.");
  if (top != NULL) {
    IsTrue("Data", top->data == 611, "List should have data == 611.");
  }
  append_me = mknode(-42);
  list.append(append_me);
  top = list.getHead();
  IsTrue("Null", top != NULL, "First thing null");
  if (top != NULL) {
    IsTrue("Null", top->next != NULL, "Second thing null");
    if (top->next != NULL) {
      IsTrue("Data", top->next->data == -42, "List should have data == -42.");
    }
  }
  Node* legit = build_three_node_list(10, 15, 20);
  list.setHead(legit);
  append_me = mknode(33);
  list.append(append_me);
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
  Node* head = NULL;
  LinkedList list;
  list.insert_data(0, 42);
  safe_check(list.getHead(), 0, 42);
  list.insert_data(0, 611);
  safe_check(list.getHead(), 0, 611);
  safe_check(list.getHead(), 1, 42);
  list.insert_data(1, 50);
  safe_check(list.getHead(), 1, 50);  
  list.insert_data(3, -1234);
  safe_check(list.getHead(), 3, -1234);
  list.insert_data(6, 999); // should complete without segfault
  IsTrue("End", true, "");

}TEST_END

TEST_BEGIN("Insert")
{
  LinkedList list;
  list.insert(0, mknode(42));
  safe_check(list.getHead(), 0, 42);
  list.insert(0, mknode(611));
  safe_check(list.getHead(), 0, 611);
  safe_check(list.getHead(), 1, 42);
  list.insert(1, mknode(50));
  safe_check(list.getHead(), 1, 50);  
  list.insert(3, mknode(-1234));
  safe_check(list.getHead(), 3, -1234);
  list.insert(6, mknode(999)); // should complete without segfault
  IsTrue("End", true, "");

}TEST_END

TEST_BEGIN("Remove")
{
  Node* back = build_three_node_list(20, 30, 40);
  Node* front = mknode(10);
  front->next = back;
  LinkedList list;
  list.setHead(front);
  list.remove(0);
  front = list.getHead();
  IsTrue("Null", front != NULL, "List should still have a head node");
  if (front != NULL) {
    IsTrue("Value", front->data == 20, "first data cell should be 20");
    list.remove(2);
    front = list.getHead();
    IsTrue("Sequence", front != NULL && front->next != NULL 
	   && front->next->next == NULL, 
	   "Should be 20, 30, NULL");
  }
  front = build_three_node_list(123, 234, 345);
  list.setHead(front);
  list.remove(1);
  front = list.getHead();
  bool structure_ok = (front != NULL && front->next != NULL 
		       && front->next->next == NULL);
  IsTrue("Sequence", structure_ok, "Delete from middle causes trouble");
  if (structure_ok) {
    IsTrue("Values", front->data == 123 && front->next->data == 345,
	   "Expecting 123, 345");
  }

}TEST_END

TEST_BEGIN("Size")
{
  LinkedList list;
  int s = list.size();
  IsTrue("Empty", s == 0, "Empty should be 0 size");
  Node* head = build_three_node_list(8, 4, 2);
  list.setHead(head);
  s = list.size();
  IsTrue("Three", s == 3, "Should have 3 things");

}TEST_END

TEST_BEGIN("Contains")
{
  LinkedList list;
  Node* top = build_three_node_list(8, 80, 800);
  list.setHead(top);
  IsTrue("Contain", list.contains(8), "Should contain the number"); 
  IsTrue("Contain", list.contains(80), "Should contain the number");
  IsTrue("Contain", list.contains(800), "Should contain the number");
  IsTrue("Contain", !list.contains(0), "Should not contain the number"); 
  IsTrue("Contain", !list.contains(81), "Should not contain the number");
  IsTrue("Contain", !list.contains(-800), "Should not contain the number");
}TEST_END


SUITE_END

int main (int argc, char* argv[]) {	
  UTFrameworkInit;
}
