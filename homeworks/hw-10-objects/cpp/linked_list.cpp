/*
  linked_list.cpp

  This is the OBJECT-ORIENTED version of the linked list
  assignment. If the filenames conflict with last week's assignment:
  why are you doing everything in one big messy folder?

 */

#include "linked_list.hpp"

using namespace std;

LinkedList::LinkedList() {
  // implement me
}

void LinkedList::append_data(int data) {
  // implement me
}
  
void LinkedList::append(Node* new_node) {
  // implement me
}

void LinkedList::insert_data(int offset, int data) {
  // implement me
}

void LinkedList::insert(int offset, Node* new_node) {
  // implement me
}

void LinkedList::remove(int offset) {
  // implement me
}

int LinkedList::size() {
  // implement me
  return -1;
}

bool LinkedList::contains(int val) {
  // implement me
  return false;
}

Node* LinkedList::getHead() {
  // don't modify this
  return head;
}

void LinkedList::setHead(Node* node) {
  // don't modify this
  head = node;
}
  
ostream &operator << (ostream& out, LinkedList* state) {
  // debugging function. ok to modify if you want to
  if (state != NULL) {
    Node* cursor = state->getHead();
    out << "[";
    while (cursor != NULL) {
      out << cursor;
      cursor = cursor -> next;
    }
    out << "]";
  } else {
    out << "NULL LinkedList*";
  }
  return out;
}

ostream &operator << (ostream& out, Node* node) {
  // debugging function. ok to modify if you want to
  if (node == NULL) {
    out << "NULL Node*";
  } else {
    out << node->data << " ";
    if (node->next == NULL) {
      out << "#";
    }
  }
  return out;
}
