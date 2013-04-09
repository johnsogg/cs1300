/*

  linked_list.h

 */

#ifndef __linked_list__
#define __linked_list__

#include <iostream>
#include <string>

using namespace std;

/**
 * This is the basic node structure for a linked list.
 **/
struct node {
  int data;    // data: the value of this node
  node* next;  // next: pointer to the next node in the list, or NULL
	       // if this is the last node.
};

/**
 * Create a new node structure that points to NULL and holds the
 * provided integer. Return a pointer to that new node.
 **/
node* init_node(int data);

/**
 * Debugging function that produces something like the following:
 *
 * [ ] 
 *
 * [42, 38, 93, ]
 *
 * This is done for you.
 **/
void report(node* head);

/**
 * Insert an integer into the list pointed to by head_ptr. The resulting
 * list is one element longer, and the newly appended node has the
 * given data value. consider using the 'append' function to help.
 **/
void append_data(node** head_ptr, int data);

/**
 * This is the same as append_data, except we're adding a node, rather
 * than a value.
 **/
void append(node** head_ptr, node* new_node);

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
 * The offset parameter must be either a currently indexable spot, or
 * it should refer to the last element.
 *
 * If this is an empty list (e.g. *head_ptr is NULL), then 'offset'
 * must be 0.
 *
 * If this list has 4 items, they are indexable by 0, 1, 2, or 3. So
 * the 'offset' must be 0, 1, 2, 3, or 4.
 *
 * If the offset is out of range (either negative or too large) this
 * function should silently return without doing anything.
 **/
void insert_data(node** head_ptr, int offset, int data);

/**
 * This is the same as insert_data, except we're inserting a node,
 * rather than a value.
 **/
void insert(node** head_ptr, int offset, node* new_node);

/**
 * Remove the node indicated by the given offset. For example if our
 * list contains 23, 74, 93, and we remove offset 1, the resulting
 * list should then contain 23, 93.
 *
 * BEWARE:
 *
 * If the offset is negative or refers to a cell that is past the end
 * of the indexable range, this function should return silently and
 * not crash and burn.
 **/
void remove(node** head_ptr, int offset);

/**
 * Report the number of nodes in the linked list pointed to by head.
 **/
int size(node* head);

/**
 * Return true if the linked list pointed to by head contains a node
 * with the specified value.
 **/
bool contains(node* head, int data);

#endif /* defined __linked_list__ */
