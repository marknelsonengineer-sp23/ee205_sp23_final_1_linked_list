///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         EE 205 - Spr 2023 - Final Exam 1 - Linked List
//
/// Final Exam Test Suite
///
/// @file   test_Final.cpp
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
/// @cond Suppress Doxygen warnings

#define BOOST_TEST_MODULE Final Exam Test Suite
#include <boost/test/included/unit_test.hpp>  // include this to get Boost Test's main()
#include <boost/test/unit_test.hpp>

#include <climits>
#include <vector>

#include "List.h"

using namespace std;

BOOST_AUTO_TEST_SUITE( test_Final )

   string makeList( List* aList ) {
      stringstream aStream;

      for( Node* current = aList->getList() ; current != nullptr ; current = current->nextNode() ) {
         aStream << current->getName() << ":";
      }

      return aStream.str();
   }


   BOOST_AUTO_TEST_CASE( test_empty_list ) {
      List aList;

      BOOST_CHECK_EQUAL( makeList( &aList ), "" ) ;

      BOOST_CHECK_EQUAL( aList.doSomethingInteresting( 0 ), nullptr ) ;
      BOOST_CHECK_EQUAL( aList.doSomethingInteresting( 1 ), nullptr ) ;
      BOOST_CHECK_EQUAL( aList.doSomethingInteresting( 2 ), nullptr ) ;
      BOOST_CHECK_EQUAL( aList.doSomethingInteresting( 3 ), nullptr ) ;
      BOOST_CHECK_EQUAL( aList.doSomethingInteresting( INT_MAX ), nullptr ) ;

      BOOST_CHECK_EQUAL( makeList( &aList ), "" ) ;
   }

   BOOST_AUTO_TEST_CASE( test_low_n_values ) {
      List aList;

      aList.add( "Bea" );
      aList.add( "Ali" );

      BOOST_CHECK_EQUAL( makeList( &aList ), "Ali:Bea:" ) ;

      BOOST_CHECK_EQUAL( aList.doSomethingInteresting( 0 ), nullptr ) ;
      BOOST_CHECK_EQUAL( aList.doSomethingInteresting( -1 ), nullptr ) ;
      BOOST_CHECK_EQUAL( aList.doSomethingInteresting( -2 ), nullptr ) ;
      BOOST_CHECK_EQUAL( aList.doSomethingInteresting( -3 ), nullptr ) ;
      BOOST_CHECK_EQUAL( aList.doSomethingInteresting( INT_MIN ), nullptr ) ;

      BOOST_CHECK_EQUAL( makeList( &aList ), "Ali:Bea:" ) ;
   }


   BOOST_AUTO_TEST_CASE( test_base_case ) {
      List aList;

      aList.add( "Edo" );
      aList.add( "Dan" );
      aList.add( "Cal" );
      aList.add( "Bea" );
      aList.add( "Ali" );

      BOOST_CHECK_EQUAL( makeList( &aList ), "Ali:Bea:Cal:Dan:Edo:" ) ;

      Node* aNode = aList.doSomethingInteresting( 2 );

      BOOST_CHECK_EQUAL( makeList( &aList ), "Ali:Bea:Cal:Edo:" ) ;
      BOOST_CHECK_EQUAL( aNode->getName(), "Dan" ) ;
      BOOST_CHECK_EQUAL( aNode->nextNode(), nullptr ) ;
 }

   BOOST_AUTO_TEST_CASE( test_remove_size_plus_one ) {
      List aList;

      aList.add( "Edo" );
      aList.add( "Dan" );
      aList.add( "Cal" );
      aList.add( "Bea" );
      aList.add( "Ali" );

      BOOST_CHECK_EQUAL( makeList( &aList ), "Ali:Bea:Cal:Dan:Edo:" );

      Node* aNode = aList.doSomethingInteresting( 6 );

      BOOST_CHECK_EQUAL( makeList( &aList ), "Bea:Cal:Dan:Edo:" ) ;
      BOOST_CHECK_EQUAL( aNode->getName(), "Ali" ) ;
      BOOST_CHECK_EQUAL( aNode->nextNode(), nullptr ) ;

      aNode = aList.doSomethingInteresting( 5 );

      BOOST_CHECK_EQUAL( makeList( &aList ), "Cal:Dan:Edo:" ) ;
      BOOST_CHECK_EQUAL( aNode->getName(), "Bea" ) ;
      BOOST_CHECK_EQUAL( aNode->nextNode(), nullptr ) ;

      aNode = aList.doSomethingInteresting( 4 );

      BOOST_CHECK_EQUAL( makeList( &aList ), "Dan:Edo:" ) ;
      BOOST_CHECK_EQUAL( aNode->getName(), "Cal" ) ;
      BOOST_CHECK_EQUAL( aNode->nextNode(), nullptr ) ;

      aNode = aList.doSomethingInteresting( 3 );

      BOOST_CHECK_EQUAL( makeList( &aList ), "Edo:" ) ;
      BOOST_CHECK_EQUAL( aNode->getName(), "Dan" ) ;
      BOOST_CHECK_EQUAL( aNode->nextNode(), nullptr ) ;

      aNode = aList.doSomethingInteresting( 2 );

      BOOST_CHECK_EQUAL( makeList( &aList ), "" ) ;
      BOOST_CHECK_EQUAL( aNode->getName(), "Edo" ) ;
      BOOST_CHECK_EQUAL( aNode->nextNode(), nullptr ) ;
   }

   BOOST_AUTO_TEST_CASE( test_remove_INT_MAX ) {
      List aList;

      aList.add( "Edo" );
      aList.add( "Dan" );
      aList.add( "Cal" );
      aList.add( "Bea" );
      aList.add( "Ali" );

      BOOST_CHECK_EQUAL( makeList( &aList ), "Ali:Bea:Cal:Dan:Edo:" );

      Node* aNode = aList.doSomethingInteresting( INT_MAX );

      BOOST_CHECK_EQUAL( makeList( &aList ), "Bea:Cal:Dan:Edo:" ) ;
      BOOST_CHECK_EQUAL( aNode->getName(), "Ali" ) ;
      BOOST_CHECK_EQUAL( aNode->nextNode(), nullptr ) ;

      aNode = aList.doSomethingInteresting( INT_MAX );

      BOOST_CHECK_EQUAL( makeList( &aList ), "Cal:Dan:Edo:" ) ;
      BOOST_CHECK_EQUAL( aNode->getName(), "Bea" ) ;
      BOOST_CHECK_EQUAL( aNode->nextNode(), nullptr ) ;

      aNode = aList.doSomethingInteresting( INT_MAX );

      BOOST_CHECK_EQUAL( makeList( &aList ), "Dan:Edo:" ) ;
      BOOST_CHECK_EQUAL( aNode->getName(), "Cal" ) ;
      BOOST_CHECK_EQUAL( aNode->nextNode(), nullptr ) ;

      aNode = aList.doSomethingInteresting( INT_MAX );

      BOOST_CHECK_EQUAL( makeList( &aList ), "Edo:" ) ;
      BOOST_CHECK_EQUAL( aNode->getName(), "Dan" ) ;
      BOOST_CHECK_EQUAL( aNode->nextNode(), nullptr ) ;

      aNode = aList.doSomethingInteresting( INT_MAX );

      BOOST_CHECK_EQUAL( makeList( &aList ), "" ) ;
      BOOST_CHECK_EQUAL( aNode->getName(), "Edo" ) ;
      BOOST_CHECK_EQUAL( aNode->nextNode(), nullptr ) ;
   }

   BOOST_AUTO_TEST_CASE( test_evan_rau_remove_from_end ) {
      for( int i = 0 ; i <= 20 ; i++ ) {
         List aList;
         for( int j = 0 ; j <= i ; j++ ) {  // Build up a list
            aList.add( to_string( j ) );
         }

         // cout << makeList( &aList ) << endl;

         for( int j = 0 ; j <= i ; j++ ) {
            // cout << "List before=" << makeList( &aList ) << "   ";
            Node* aNode = aList.doSomethingInteresting( 1 );  //Remove from end
            // cout << "Removed " << aNode->getName() << "   j=" << j << "   list=" << makeList( &aList ) << endl;
            BOOST_CHECK_EQUAL( aNode->getName(), to_string( j ) );
            BOOST_CHECK_EQUAL( aNode->nextNode(), nullptr ) ;
         }
      }
   }

   BOOST_AUTO_TEST_CASE( test_evan_rau_remove_from_beginning ) {
      for( int i = 0 ; i <= 20 ; i++ ) {
         List aList;
         for( int j = 0 ; j <= i ; j++ ) {  // Build up a list
            aList.add( to_string( j ) );
         }

         // cout << makeList( &aList ) << endl;

         for( int j = 0 ; j <= i ; j++ ) {
            Node* aNode = aList.doSomethingInteresting( INT_MAX );  //Remove from start
            BOOST_CHECK_EQUAL( aNode->getName(), to_string( i - j ) ) ;
            BOOST_CHECK_EQUAL( aNode->nextNode(), nullptr ) ;
         }
      }
   }

   BOOST_AUTO_TEST_CASE( test_random ) {
      srand( time( nullptr ) );
      List aList;
      for( int k = 0 ; k < 100 ; k++ ) {
         for( int i = 0 ; i <= 20 ; i++ ) {
            list<string> referenceList;

            for( int j = 0 ; j <= i ; j++ ) {  // Build up a list
               aList.add( to_string( j ) );
               referenceList.push_front( to_string( j ) );
            }

            vector<string> referenceVector;
            for( auto reverseIterator = referenceList.begin() ; reverseIterator != referenceList.end() ; reverseIterator++ ) {
               referenceVector.push_back( *reverseIterator );
            }

            while( aList.getList() != nullptr ) {
               // cout << "aList:     " << makeList( &aList ) << endl;

               stringstream referenceString;
               for( const auto& j: referenceVector ) {
                  referenceString << j << ":";
               }
               // cout << "reference: " << referenceString.str() << endl;

               BOOST_CHECK_EQUAL( makeList( &aList ), referenceString.str());

               const int reverseRandomIndex = (int) ( rand() % referenceVector.size() ) + 1;
               // cout << "   reverseRandomIndex=" << reverseRandomIndex << endl;

               Node* aNode = aList.doSomethingInteresting( reverseRandomIndex );
               if( aNode == nullptr ) {
                  // cout << "aNode == nullptr" << endl;
                  continue;
               }

               const string removedString = *( referenceVector.end() - reverseRandomIndex );
               // cout << "removedString=" << removedString << "   Removed from aList=" << aNode->getName() << endl;
               referenceVector.erase( referenceVector.end() - reverseRandomIndex );

               BOOST_CHECK_EQUAL( aNode->getName(), removedString );
               BOOST_CHECK_EQUAL( aNode->nextNode(), nullptr );
            }
         }
      }
   }

BOOST_AUTO_TEST_SUITE_END()
/// @endcond
