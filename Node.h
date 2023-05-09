///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         EE 205 - Spr 2023 - Final Exam 1 - Linked List
//
/// A generic Node
///
/// @file   Node.h
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>

class List;  // Forward declaration

/// A generic Node class
class Node {
   friend List;  ///< A friend of Node

private:
   std::string name;  ///< Something to store in Node
   Node*       next;  ///< Pointer to the next Node

public:
   /// @return The Node that follows this Node
   Node* nextNode() {
      return next;
   }

   /// @return The Name associated with this Node
   std::string getName() {
      return name;
   }
};
