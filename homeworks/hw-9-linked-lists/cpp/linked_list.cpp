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
  // implement me
  return NULL;
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
  // implement me
}

void append(node** head_ptr, node* new_node) {
  // implement me
}

void insert_data(node** head_ptr, int offset, int data) {
  // implement me
}

void insert(node** head_ptr, int offset, node* new_node) {
  // implement me
}

void remove(node** head_ptr, int offset) {
  // implement me
}

int size(node* head) {
  // implement me
  return -1;
}

