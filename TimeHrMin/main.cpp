
/*// This program demonstrates the TimeHrMn class's overloaded
// relational operators
#include <iostream>
#include "TimeHrMn.h"
using namespace std;

void displayTime(const TimeHrMn &obj);

int main()
{
   int hours, minutes;

   // Create two TimeHrMn objects. The default arguments
   // for the constructor will be used.
   TimeHrMn first, second;

   // Get a time from the user.
   cout << "Enter a time in hours and minutes: ";
   cin >> hours >> minutes;

   // Store the time in first.
   first.setHours(hours);
   first.setMinutes(minutes);

   // Get more input.
   cout << "Enter a time in hours and minutes: ";
   cin >> hours >> minutes;

   // Store the time in second.
   second.setHours(hours);
   second.setMinutes(minutes);

   // Compare the two objects.
   if (first == second)
   {
       displayTime(first);
       cout << " is equal to ";
       displayTime(second);
       cout << endl;
   }

   if (first > second)
   {
       displayTime(first);
       cout << " is greater than ";
       displayTime(second);
       cout << endl;
   }

   if (first < second)
   {
       displayTime(first);
       cout << " is less than ";
       displayTime(second);
       cout << endl;
   }
   return 0;
}
*/
// This program demonstrates the TimeHrMn class's overloaded
// stream insertion and extraction operators
#include <iostream>
#include "TimeHrMn.h"
using namespace std;

int main()
{
    TimeHrMn first, second;  // Define two objects.

    // Get input for the first object.
    cout << "Enter a time in hours and minutes.\n";
    cin >> first;

    // Get input for the second object.
    cout << "Enter another time in hours and minutes.\n";
    cin >> second;

    // Display the values in the objects.
    cout << "The values you entered are:\n";
    cout << first << " and " << second << endl;

    return 0;
}
