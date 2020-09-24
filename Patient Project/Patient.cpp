/*
  Implementation file for the Patient class.
*/

#include "Patient.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;

/*******
 This is the default constructor; it sets everything to 0 or "".
 */
Patient::Patient()
{
     name = "";
     height = 0;
     age = 0;
     weight = 0;

}

/*******
This is an overloaded constructor.
 It sets the variables according to the parameters.
*/
Patient::Patient(string inputName, double inputAge, int inputHeight, int inputWeight)
{
    name = inputName;
    height = inputHeight;
    age = inputAge;
    weight = inputWeight;
}

/*******
This function displays the member variables
 in a neat format.
*/
void Patient::display() const
{
    //cout << "Testing the first object:" << endl;
    cout << "         Name: " << name << endl;
    cout << "          Age: " << age << endl;
    cout << "       Height: " << height << " inches" << endl;
    cout << "       Weight: " << weight << " pounds" << endl;
    cout << "Weight Status: " << weightStatus() << endl;
}

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
/*
 * This function sets the name of the Patient
 */
void Patient::setName(string patientName) {
    name = patientName;
}
/*
 * This function sets the height of the Patient
 */
void Patient::setHeight(double patientHeight) {
    height = patientHeight;
}
/*
 * This function sets the age of the Patient
 */
void Patient::setAge(int patientAge) {
    age = patientAge;
}
/*
 * This function sets the weight of the Patient
 */
void Patient::setWeight(int patientWeight) {
    weight = patientWeight;
}

/*
 * This function returns the name of the Patient
 */
string Patient::getName() const {
    return name;
}
/*
 * This function returns the height of the Patient
 */
double Patient::getHeight() const {
    return height;
}
/*
 * This function returns the age of the Patient
 */
int Patient::getAge() const {
    return age;
}
/*
 * This function returns the weight of the Patient
 */
int Patient::getWeight() const {
    return weight;
}