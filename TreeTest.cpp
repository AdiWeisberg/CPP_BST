/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Adi Weisberg & Michal yelkin
 * @since 2019-03
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;  
  ariel::Tree fourtree;
  ariel::Tree fivetree;
  ariel::Tree seventree;

  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
  fourtree.insert(10);
  fourtree.insert(11);
  fourtree.insert(12);
  fourtree.insert(13);

  fivetree.insert(10);
  fivetree.insert(15);
  fivetree.insert(7); 
  fivetree.insert(14); 
  fivetree.insert(8);

  seventree.insert(6); 
  seventree.insert(18); 
  seventree.insert(4);
  seventree.insert(5);
  seventree.insert(1); 
  seventree.insert(10);
  seventree.insert(8);


  ariel::Tree mytree;  

  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (emptytree.contains(5), false)
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_THROWS(threetree.left(6))
  .CHECK_OK    (threetree.print())
  .print()

// our tests: 
// tests for tree with 4 nodes: 

  .CHECK_EQUAL (fourtree.size(), 4)
  .CHECK_EQUAL (fourtree.root(), 10)
  .CHECK_THROWS(fourtree.left(8))
  .CHECK_EQUAL (fourtree.parent(11), 10)
  .CHECK_EQUAL (fourtree.parent(12), 11)
  .CHECK_EQUAL (fourtree.parent(13), 12)
  .CHECK_EQUAL (fourtree.right(10), 11)
  .CHECK_EQUAL (fourtree.right(11), 12)
  .CHECK_EQUAL (fourtree.right(12), 13)
  .CHECK_OK (fourtree.remove(13))
  .CHECK_EQUAL (fourtree.contains(13), false)
  .CHECK_OK (fourtree.insert(8))
  .CHECK_EQUAL (fourtree.size(), 4)
  .CHECK_OK (fourtree.remove(11))
  .CHECK_EQUAL (fourtree.contains(11), false)
  .CHECK_EQUAL (fourtree.right(10), 12)
  .CHECK_THROWS (fourtree.insert(12))
  .CHECK_OK (fourtree.insert(9))
  .CHECK_EQUAL (fourtree.size(), 4)
  .CHECK_EQUAL (fourtree.parent(9), 8)
  .CHECK_OK (fourtree.print())
  .print()

// tests for tree with 5 nodes: 

  .CHECK_EQUAL (fivetree.size(), 5)
  .CHECK_EQUAL (fivetree.root(), 10)
  .CHECK_THROWS (fivetree.right(9))
  .CHECK_EQUAL (fivetree.right(10), 15)
  .CHECK_EQUAL (fivetree.left(10), 7)
  .CHECK_EQUAL (fivetree.parent(8), 7)
  .CHECK_EQUAL (fivetree.parent(14), 15)
  .CHECK_THROWS (fivetree.insert(7))
  .CHECK_OK (fivetree.remove(7))
  .CHECK_EQUAL (fivetree.contains(7), false)
  .CHECK_EQUAL (fivetree.left(10), 8)
  .CHECK_OK (fivetree.remove(10))
  .CHECK_EQUAL (fivetree.root(), 14)
  .CHECK_EQUAL (fivetree.size(), 3)
  .CHECK_OK (fivetree.insert(2))
  .CHECK_OK (fivetree.insert(1))
  .CHECK_EQUAL (fivetree.size(), 5)
  .CHECK_EQUAL (fivetree.parent(1), 2)
  .CHECK_EQUAL (fivetree.left(8), 2)
  .CHECK_OK (fivetree.print())
  .print()

// tests for tree with 7 nodes: 

  .CHECK_EQUAL (seventree.root(), 6)
  .CHECK_THROWS (seventree.left(2))
  .CHECK_EQUAL (seventree.right(6), 18)
  .CHECK_EQUAL (seventree.left(6), 4)
  .CHECK_THROWS (seventree.insert(6))
  .CHECK_OK (seventree.remove(6))
  .CHECK_THROWS (seventree.remove(6))
  .CHECK_EQUAL (seventree.root(), 8)
  .CHECK_THROWS (seventree.insert(4))
  .CHECK_EQUAL (seventree.contains(4), true)
  .CHECK_OK (seventree.remove(4))
  .CHECK_EQUAL (seventree.contains(4), false)
  .CHECK_EQUAL (seventree.left(8), 5)
  .CHECK_EQUAL (seventree.left(5), 1)
  .CHECK_EQUAL (seventree.size(), 5)
  .CHECK_OK (seventree.print())
  .print();

  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}