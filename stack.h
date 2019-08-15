//-----------------------------------------------------------
//  Purpose:    Header file for the integer Stack class.
//-----------------------------------------------------------

#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//-----------------------------------------------------------
// Stack data node definition
//-----------------------------------------------------------
struct StackNode
{
   string tag;
   StackNode *Next;
};

//-----------------------------------------------------------
// Define the Stack class interface 
//-----------------------------------------------------------
class Stack
{
 public:
   // Constructors
   Stack();
   Stack(const Stack & stack);
   ~Stack();

   // Methods
   bool IsFull();
   bool IsEmpty();
   void Push(string Tag);
   void Pop(string &tag);
   void Top(string &tag);
   int GetLength();
   void Print();
   
   //Reading HTML file
   void checking(string filename);

 private:
   StackNode *Head;
   int Length;
};
