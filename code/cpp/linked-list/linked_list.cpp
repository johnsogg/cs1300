/*

  linked_list.cpp

  Your Name:

  Your Collaborators:

 */
#include <iostream>
#include <string>
#include "linked_list.h"

using namespace std;

node* init_node(int data) {
  //  Triangle tr = new Triangle(); // java syntax
  //  Triangle foo = null; // java
  //  foo.something(); // java gives NullPointerException
  //  tr.data = data; // java syntax
  node* monkey = new node;
  monkey->data = data;
  monkey->next = NULL; // necessary?
  return monkey;
}

/*
 * Study this function. We use a cursor to cruise around this data
 * structure. All of the rest of the function you have to implement
 * look a lot like this.
 */ 
void report(node* head) {
  node* cursor = head;
  cout << "[ ";
  while (cursor != NULL) {
    cout << cursor-> data << ", ";
    cursor = cursor-> next;
  }
  cout << " ]" << endl;
}

void append_data(node** head_ptr, int data) {
  node* nn = init_node(data);
  append(head_ptr, nn); // will call append(node**, node*)
}

void append(node** head_ptr, node* new_node) {
  node* head = *head_ptr;
  if (head == NULL) {
    // head = new_node; // didn't work. Why?
    *head_ptr = new_node; 
  } else {
    node* cursor = head;
    while (cursor->next != NULL) {
      cursor = cursor->next;
    }
    // now cursor is a pointer to the last node.
    cursor->next = new_node;
  }
}

void insert_data(node** head_ptr, int offset, int data) {
  // implement me
}

void insert(node** head_ptr, int offset, node* new_node) {
  // implement me
}

void remove(node** head_ptr, int offset) {
  if (*head_ptr == NULL) { // empty list
    return;
  } else { // non-empty list
    if (offset == 0) {
      // remove first thing.
      node* first = *head_ptr;
      *head_ptr = first->next; // 2nd thing is new 1st thing
      delete first; // clean up after yourself
    } else {
      // remove something later on in the list.
      int count = 0;
      node* cursor = *head_ptr;
      while (cursor != NULL && count < (offset - 1)) {
	cursor = cursor->next; // crawl along list by one
	count = count + 1; // increment actual num followed
      }
      if (cursor != NULL && count == (offset - 1)) {
	// cursor points to doomed node. It could be NULL.
	if (cursor->next == NULL) {
	  return; // done.
	}
	// cursor->next is not null.
	node* doomed = cursor->next;
	cursor->next = cursor->next->next;
	delete doomed; // clean up after yourself
      }
    }
  }
}

int size(node* head) {
  // implement me
  return -1;
}

