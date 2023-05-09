///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_sp23_final_1_linked_list - EE 205 - Spr 2023
//
/// Declaration for the List class
///
/// @file   List.h
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Node.h"

/// A generic single linked list
class List {
private:
   Node* head = nullptr;  ///< The head pointer for the linked list

public:
   /// Add a new Node to the List
   /// @param new_name A name to put into the List
   void add( const std::string& new_name ) {
      Node* newNode = new Node();

      newNode->next = head;
      newNode->name = new_name;

      head = newNode;
   }

   /// Do Something Interesting!
   ///
   /// @param n A parameter
   /// @return A Node
   Node* doSomethingInteresting( int n );

   /// @return The head pointer to the List (List.head)
   Node* getList() {
      return head;
   }
};
