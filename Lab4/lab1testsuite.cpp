#include <iostream> // for cout
#include "arrayclass.h"
using namespace std;

// Function Prototype
void ArrayClassTest();

 

// Main function that is called when the program is executed
int main()
{
  ArrayClassTest();

#ifdef _WIN32
  system("PAUSE"); // needed for windows to prevent the program from terminating and the command window to close
#endif
  return 0;
}

 

void ArrayClassTest()
{
  ArrayClass<int> ac1;
  ArrayClass<int> ac2(3);

  // Insert the values 1 to 7 in ac1
  for (int i = 0; i < 7; ++i)
  {
    ac1.Insert(i+1);
  }

  // Change the value with index 3 to 13
  try {
	  ac1.Set(3, 13);
	  ac1.Set(9, 22);
  }
  catch (exception e) {
	  cout << e.what() << endl;
  }

  // Attempt to change the value with index 9 to 22
  // Nothing happens since it is not an existing value

  // Print the values in reverse order
  // Should print: 7 6 5 13 3 2 1
  for(int i = ac1.Size()-1; i >= 0; i--)
  {
    cout << ac1.Get(i) << " ";
  }
  cout << endl;

  // Insert the values 2 and 4 in ac2
  try {
	  ac2.Insert(2);
	  ac2.Insert(6);
  }
  catch (exception e) {
	  cout << e.what() << endl;
  }

  // Print current and max size of ac1 and ac2
  cout << "ac1: current size = " << ac1.Size();
  cout << ", max size = " << ac1.MaxSize() << endl;
  cout << "ac2: current size = " << ac2.Size();
  cout << ", max size = " << ac2.MaxSize() << endl;

  // add some test cases here to Set and Get with invalid indices
  // Don't forget to put your statements inside a try block!

  try {
	  ac1.Set(-1, 13);
	  ac1.Set(10, 11);
  }
  catch (exception e) {
	  cout << e.what() << endl;
  }

  try {
	  ac2.Insert(6);
	  ac2.Insert(8);
	  ac2.Insert(10);
  }
  catch (exception e) {
	  cout << e.what() << endl;
  }
}