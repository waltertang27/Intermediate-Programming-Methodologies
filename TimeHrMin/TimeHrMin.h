// Specification file for the TimeHrMn class
// The TimeHrMn class holds time
// expressed in hours and minutes.

#ifndef TIMEHRMN_H
#define TIMEHRMN_H
#include <iostream>

using std::ostream;
using std::istream;
class TimeHrMn; // Forward Declaration
// Function Prototypes for Overloaded Stream Operators
ostream &operator << (ostream &, const TimeHrMn &);
istream &operator >> (istream &, TimeHrMn &);

class TimeHrMn
{
private:
   int hours;
   int minutes;
   void update(); // Defined in TimeHrMn.cpp
public:
   // Constructor
   TimeHrMn(int h = 0, int m = 0) {
       hours = h;
       minutes = m;
       update();
   }

   // Setters
   void setHours(int h) { hours = h; }
   void setMinutes(int m) {
       minutes = m;
       update();
   }

   // Getters
   int getHours() const { return hours; }
   int getMinutes() const { return minutes; }

   // Overloaded operator functions
   TimeHrMn operator+ (const TimeHrMn &); // Overloaded +
   TimeHrMn operator- (const TimeHrMn &); //Overloaded -
   TimeHrMn operator++ ();       // Prefix ++
   TimeHrMn operator++ (int);    // Postfix ++
   TimeHrMn operator-- ();    // Prefix --
   TimeHrMn operator-- (int);   // Postfix --
     
    bool operator > (const TimeHrMn &);        // Overloaded >
    bool operator < (const TimeHrMn &);        // Overloaded <
    bool operator == (const TimeHrMn &);        // Overloaded ==

    // Friends
    /* Write your code here */
    friend istream &operator >> (istream &, TimeHrMn &);
    friend ostream &operator << (ostream &, const TimeHrMn &);
};

#endif
