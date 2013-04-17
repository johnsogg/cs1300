#ifndef __linked_list_hpp__
#define __linked_list_hpp__

#include <string>
#include <iostream>
#include <vector>
#include <iostream>

#include "UTFramework.h"

using namespace std;

class Node;

class LinkedList {
private:
  Node* head;

public:

  /**
   * Initialize the member variables for the LinkedList class. This
   * should be one line of code: set head to NULL. For more involved
   * classes (with more variables) this will be more interesting.
   *
   * You will get very trippy undefined behavior if you don't
   * implement this, because 'head' will refer to an arbitrary spot in
   * memory that you don't own and you'll get segmentation faults.
   **/
  LinkedList();

  /**
   * Insert an integer into the list. The resulting list is one
   * element longer, and the newly appended node has the given data
   * value. Consider using the 'append' function to help.
   **/
  void append_data(int data);
  
  /**
   * This is the same as append_data, except we're adding a Node,
   * rather than an integer.
   **/
  void append(Node* new_node);  

  /**
   * Similar to append_data. Insert a new node that contains the given
   * data value, such that the new node occupies the offset
   * indicated. Any nodes that were already in the list at that offset
   * and beyond are shifted down by one. For example if the list
   * contains 23, 74, 93, and we insert 42 at index 1, the resulting
   * list should be 23, 42, 74, 93.
   *
   * BEWARE: 
   *
   * The offset parameter must be either a currently indexable spot,
   * or it should refer to the last element.
   *
   * If this is an empty list then 'offset' must be 0.
   *
   * If this list has 4 items, they are indexable by 0, 1, 2, or 3. So
   * the 'offset' must be 0, 1, 2, 3, or 4.
   *
   * If the offset is out of range (either negative or too large) this
   * function should silently return without doing anything.
   **/
  void insert_data(int offset, int data);

  /**
   * This is the same as insert_data, except we're inserting a Node,
   * rather than an integer.
   **/
  void insert(int offset, Node* new_node);

  /**
   * Remove the node indicated by the given offset. For example if our
   * list contains 23, 74, 93, and we remove offset 1, the resulting
   * list should then contain 23, 93.
   *
   * BEWARE:
   *
   * If the offset is negative or refers to a cell that is past the
   * end of the indexable range, this function should return silently
   * and not crash and burn.
   **/
  void remove(int offset);

  /**
   * Report the number of nodes in the linked list.
   **/
  int size();

  /**
   * Return true if there is a Node in the list with the given value,
   * false otherwise.
   **/
  bool contains(int val);

  /**
   * Gets the Node*. This is only needed for unit testing. Normally
   * this sort of thing wouldn't be here because we want to hide the
   * implementation. This is implemented for you.
   **/
  Node* getHead();

  /**
   * Sets the head pointer. This is only needed for unit testing and
   * is implemented for you.
   **/
  void setHead(Node* node);

  /**
   * Prints the contents of the linked list to the given output
   * stream. This is implemented for you.
   **/
  friend ostream &operator << (ostream& out, LinkedList* state);
}; // end class LinkedList

class Node {
public:
  int data;
  Node* next;
  
  /**
   * Prints the contents of the node to the given output stream.
   **/
  friend ostream &operator << (ostream& out, Node* node);
}; // end class Node

#endif

