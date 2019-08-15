//-----------------------------------------------------------
//  Purpose:    Implementation of integer Stack class.
//-----------------------------------------------------------
#include "stack.h"

//-----------------------------------------------------------
// Constructor function.
//-----------------------------------------------------------
Stack::Stack()
{
   Head = NULL;
   Length = 0;
}

//----------------------------------------------
// Constructor function.
//----------------------------------------------
Stack::Stack(const Stack & stack)
{
   // Create first node
   StackNode *copy = new StackNode();
   Head = copy;

   // Walk list to copy nodes
   StackNode *ptr = stack.Head;
   while (ptr != NULL)
   {
      copy->Next = new StackNode();
      copy = copy->Next;
      copy->tag = ptr->tag;
      copy->Next = NULL;
      ptr = ptr->Next;
   }

   // Tidy first node
   copy = Head;
   Head = copy->Next;
   delete copy;
}

//-----------------------------------------------------------
// Destructor function.
//-----------------------------------------------------------
Stack::~Stack()
{
   // Walk stack deleting data
   while (Head != NULL)
   {
      StackNode *Temp = Head;
      Head = Head->Next;
      delete Temp;
   }

   // Reset head
   Head = NULL;
   Length = 0;
}

//-----------------------------------------------------------
// Check to see if stack is full.
//-----------------------------------------------------------
bool Stack::IsFull()
{
   return (false);
}

//-----------------------------------------------------------
// Check to see if stack is empty.
//-----------------------------------------------------------
bool Stack::IsEmpty()
{
   return (Length == 0);
}

//-----------------------------------------------------------
// Push data into the stack.
//-----------------------------------------------------------
void Stack::Push(string Tag)
{
   // Check for full stack
   if (IsFull())
      return;

   // Allocate space for data
   StackNode *Temp = new StackNode;
   if (Temp == NULL)
      return;

   // Insert data at head of list
   Temp->tag = Tag;   
   Temp->Next = Head;
   Head = Temp;
   Length++;
}

//-----------------------------------------------------------
// Pop data from the stack.
//-----------------------------------------------------------
void Stack::Pop(string &tag)
{
   // Check for empty stack
   if (IsEmpty())
      return;

   // Extract information from node
   tag = Head->tag;

   // Pop item from linked list
   StackNode *Temp = Head;
   Head = Head->Next;
   delete Temp;
   Length--;
}

//-----------------------------------------------------------
// Return data from top of stack.
//-----------------------------------------------------------
void Stack::Top(string &tag)
{
   // Check for empty stack
   if (IsEmpty())
      return;

   // Return information from node
   tag = Head->tag;
}

//-----------------------------------------------------------
// Return the number of elements in stack.
//-----------------------------------------------------------
int Stack::GetLength()
{
   return Length;
}

//-----------------------------------------------------------
// Print all records in the stack.
//-----------------------------------------------------------
void Stack::Print()
{
   // Walk the stack printing data
   cout << "Missing tags :  " << endl;
   StackNode *Temp = Head;
   while (Temp != NULL)
   {
      
      cout << Temp->tag << endl;
      Temp = Temp-> Next;
   }
   cout << endl;
}

void Stack::checking(string filename)
{
    fstream din;
    din.open(filename.c_str());
    if(din.fail())
        {cout << " OPENING FILE NAME " << filename << " FAILED. " << endl; return;}
    else
        {cout << " OPENING FILE NAME " << filename << " SUCCEEDED. " << endl;}
    
    string input,toptag;
    int find;
    char c;
  
        while(!din.eof())
        {    
            getline(din,input,'<');
            if(din.eof())break;
            string tag;
            while((din.peek() != '>')&&(din.peek() != ' '))
            {
                c = din.get();
                tag = tag+c;
                if(din.eof()) break;
            }
            cout << tag << endl;
       // ---------------------------------------------------        
            //Push or Pop 
            find = tag.find("/");
            //If beginning tag is found
            if(find < 0) 
            {                
                if(tag !="br" && tag!= "hr" && tag!= "img")    
                {                 
                    Push(tag);
                    cout << "PUSH = " << tag << endl;
                }
            }
            //If ending tag is found
            else if(find >= 0)
            {          
                tag.erase(0,1);
                Top(toptag);
                
                // if the Top stack is equal to the tag, then it pop.     
                if(tag == toptag)
                {                    
                    Pop(tag);
                    cout << "POP HAPPENING = " << tag <<endl;
                }   
            }
        }
    din.close();         
}

//-----------------------------------------------------------
// Main program.
//-----------------------------------------------------------
int main()
{
    Stack s;
    string input;
    cout <<"Write file name for error checking! (include.html)." << endl;
    cin >> input;
    s.checking(input); 
    cout << endl;
    cout << endl;
    s.Print();  
}

