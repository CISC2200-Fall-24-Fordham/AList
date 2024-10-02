#include "AListInheritance.h"
#include <iostream>
#include <cstdlib>

using namespace std;

#define SIZE 10

int main()
{
  AList<int> L;

  // randomly add SIZE ints to the array nums, and the SLList L 
  int nums[SIZE];
  srand(time(0)); // setting the seed for rand()

  //fill nums array from back to front, and insert same num to L
  for (int i = SIZE - 1; i >= 0; i--) {
    nums[i] = rand() % 20 + 1; // generating random numbers by rand()
    L.addFirst(nums[i]);
  }

  //test get(): 
  if (L.get(0) != nums[0])
  {
      cout <<"failed get(0)\n";
  } 
  if (L.get(SIZE - 1) != nums[SIZE - 1])
  {
      cout <<"failed get(last)\n";
  }

  //test copy constructor 
  AList<int> *K = new AList<int>(L);

  if (L.size() != K->size() || 
     K->get(0) != nums[0] || 
     K->get(SIZE - 1) != nums[SIZE - 1])
  {
      cout <<"failed copy constructor test\n";
  }
  else
	  cout <<"passed copy constructor test\n";


  delete K; // this should not also delete L

  //test "removeFirst" 
  if ( nums[0] != L.removeFirst() )
     cout <<"failed removeFirst testcase\n";
  if ((SIZE - 1) != L.size())
     cout <<"failed removeFirst testcase: size is wrong\n";
  if (nums[5] != L.get(4))
  {
     cout <<"failed removeFirst testcase: get(4) gives wrong result\n";
  }

  //test "removeLast"
  if ( nums[SIZE - 1] != L.removeLast())
     cout <<"failed removeFirst testcase\n";
  if ((SIZE - 2) != L.size())
     cout <<"failed removeFirst testcase: size is wrong\n";
  if (nums[5] != L.get(4))
     cout <<"failed removeFirst testcase: get(5) gives wrong result\n";

}
