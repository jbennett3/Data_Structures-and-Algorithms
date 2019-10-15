#include <string>
#include <iostream>
#include "List.h"

using namespace std;

int main()
{  
   List names;

   names.push_back("Tom");
   names.push_back("Diana");
   names.push_back("Harry");
   names.push_back("Juliet");

   // Add a value in fourth place

   Iterator pos = names.begin();
   pos.next();
   pos.next();
   pos.next();
    cout << "\nBefore Romeo" << endl;
   for (pos = names.begin(); !pos.equals(names.end()); pos.next())
   {
      cout << pos.get() << endl;
   }
   
   names.insert(pos, "Romeo");

   // Remove the value in second place

   pos = names.begin();
   pos.next();

   names.erase(pos);

   // Print all values
   cout << "\nAfter Romeo" << endl;
   for (pos = names.begin(); !pos.equals(names.end()); pos.next())
   {
      cout << pos.get() << endl;
   }
   cout << endl;
   List names_copy(names); //Copy constructor - homework
   names_copy.push_back("Shakespeare");
   
   // Verify that Shakespeare was inserted.
   cout << "\nPrinting new list" << endl;
   for (pos = names_copy.begin(); !pos.equals(names.end()); pos.next())
   {
      cout << pos.get() << endl; //
   }
   cout << "\nPrinting original list " << endl;
   for (pos = names.begin(); !pos.equals(names.end()); pos.next())
   {
      cout << pos.get() << endl;
   }
   cin.get();
   return 0;
}

