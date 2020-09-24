/*
  Implementation file for the Patient class.
*/

#include "Patient.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;



/*******
This function calculates the BMI using the following formula:
 BMI = (weight in pounds * 703) / (height in inches)^2
 Then, it returns a string reflecting the weight status according to the BMI:
 <18.5 = underweight
 18.5 - 24.9 = normal
 25 - 29.9 = overweight
 >=30 = obese
 */
string Patient::weightStatus() const
    {
        double bmi;
        string stat = "";

        if (height > 0)
        {
            bmi = (weight * 703) / (pow(height, 2));
            if(bmi < 18.5) {
                stat = "Underweight";
            }
            else if (bmi < 24.9) {
                stat = "Normal";
            }
            else if(bmi < 29.9) {
                stat = "Overweight";
            }
            else {
                stat = "Obese";
            }
        }

        return stat;
    }
