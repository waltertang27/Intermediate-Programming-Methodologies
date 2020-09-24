/*
 Specification file for the Patient class
 */

#ifndef PATIENT_H
#define PATIENT_H
#include <string>

//using std:: string;
using namespace std;


class Patient
{
private:
    /* Write your code here */
    string name;
    double height;
    int age, weight;

public:
    // constructors
    /* Write your code here */
    Patient ();
    Patient (string inputName, double inputAge, int inputHeight, int inputWeight);

    // setters
    /* Write your code here */
    void setName(string patientName);
    void setHeight(double patientHeight);
    void setAge(int patientAge);
    void setWeight(int patientWeight);

    //getters
    /* Write your code here */
    string getName() const;
    double getHeight() const;
    int getAge() const;
    int getWeight() const;

    // other functions: declare display and weightStatus
    /* Write your code here */
    void display() const;
    string weightStatus() const;
};

#endif 
