/*
 Specification file for the Patient class
 */

#ifndef PATIENT_H
#define PATIENT_H
#include <string>
#include <iostream>

using std:: string;
using namespace std;


class Patient
{
private:
    string name;
    double height;
    int age, weight;
public:
    // constructors
    Patient () {
        name = " ";
        height = 0;
        age = 0;
        weight = 0;
    }
    Patient (string inputName, double inputAge, int inputHeight, int inputWeight) {
        name = inputName;
        age = inputAge;
        height = inputHeight;
        weight = inputWeight;
    }

    // setters
    void setName(string patientName) {name = patientName;}
    void setHeight(double patientHeight) {height = patientHeight;}
    void setAge(int patientAge) {age = patientAge;}
    void setWeight(int patientWeight) {weight = patientWeight;}

    //getters
    /* Write your code here */
    string getName() const {return name;}
    double getHeight() const {return height;}
    int getAge() const {return age;}
    int getWeight() const {return weight;}

    // other functions: declare display and weightStatus
    void display() const;
    string weightStatus() const;
  //  Patient operator = (Patient &rhs);

};

#endif
