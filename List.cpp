///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_sp23_final_1_linked_list - EE 205 - Spr 2023
//
/// Implementation for the List class
///
/// @file   List.cpp
///////////////////////////////////////////////////////////////////////////////
#include <cassert>
#include <iostream>

#include "List.h"

using namespace std;

Node* List::doSomethingInteresting( const int n ) {
   if( head == nullptr ) {
      return nullptr;
   }

   if( n <= 0 ) {
      return nullptr;
   }

   // Get the number of nodes in the list
   int count = 0 ;
   for( Node* current = head ; current != nullptr ; current = current->next ) {
      count++;
   }

   assert( count > 0 );
   assert( head != nullptr );

   Node* removedNode;

   /// For clarity of thought...
   ///
   ///     head->C->B->A->nullptr
   ///     size=3, n=3, skip=-1, current=nullptr
   ///     size=3, n=2, skip=0,  current=C (head)
   ///     size=3, n=1, skip=1,  current=B

   int nodes_to_skip = count - n - 1; // Seek to the Node before the one we will remove
   // cout << "n=" << n << "   count=" << count << "  nodes_to_skip=" << nodes_to_skip << endl;

   if( nodes_to_skip <= -1 ) { // Base case:  Remove the head node
      // cout << "Remove head node" << endl;
      removedNode = head;
      head = removedNode->next;
   } else {
      Node* current = head;
      for( ; nodes_to_skip-- > 0 ; current = current->next ) {}
      // cout << "current=" << current->name << endl;
      removedNode = current->next;
      assert( removedNode != nullptr );
      current->next = removedNode->next;
   }

   removedNode->next = nullptr;

   return removedNode;
}
