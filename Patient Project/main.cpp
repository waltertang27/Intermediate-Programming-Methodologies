/*
 CIS 22B: Create and process an array of Patient objects
 Name: Walter Tang
 IDE: CLion
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Patient.h"
using namespace std;
const int MAX_SIZE = 100;
Patient* readData(string filename, int &size);
void displayWeightStatus(Patient list[], int size);
void writeToFile(string filename, Patient list[], int size);

int main()
{
    Patient* patArr;
    int size = 0;

    string fileName;
    cout << "Please enter the input file's name: ";
    cin >> fileName;
    cout << endl;
    /* Write your code here:
      function calls
    */
    patArr = readData(fileName, size);
    displayWeightStatus(patArr, size);
    writeToFile(fileName, patArr, size);

    return 0;
}
/*
 * This function reads in the data from a file and references the number of patients as a size variable
 */
Patient* readData(string filename, int &size) {
    ifstream inputFile;
    //variables too help read data into the array
    string n;
    int a, w;
    double h;

    //opens file
    inputFile.open(filename);

    //validation
    if(inputFile.fail()) {
        cout << "Input file: " << filename << " not found!\n";
        exit(EXIT_FAILURE);
    }
    Patient* list;
    list = new Patient[MAX_SIZE];
    int i = 0;
    size = 0;
    while(!inputFile.eof()) {
        inputFile >> a >> h >> w;
        inputFile.ignore();
        getline(inputFile, n);
        list[i].setAge(a);
        list[i].setHeight(h);
        list[i].setWeight(w);
        list[i].setName(n);
        i++;
        size++;
    }
    inputFile.close();
    return list;
}
/*
 * This function displays  the underweight, overweight, and obese patients and their names
 */
void displayWeightStatus(Patient list[], int size) {
    int count = 0;
    cout << "Showing patients with the \"Underweight\" status:\n";
    for(int i = 0; i < size; i++) {
        if(list[i].weightStatus() == "Underweight") {
            cout << list[i].getName() << endl;
            count++;
        }
    }
    if(count == 0) {
        cout << "none";
    }
    count = 0;
    cout << "\nShowing patients with the \"Overweight\" status:\n";
    for(int i = 0; i < size; i++) {
        if (list[i].weightStatus() == "Overweight") {
            cout << list[i].getName() << endl;
            count++;
        }
    }
    if(count == 0) {
        cout << "none";
    }
    count = 0;
    cout << "\nShowing patients with the \"Obese\" status:\n";
    for(int i = 0; i < size; i++) {
        if (list[i].weightStatus() == "Obese") {
            cout << list[i].getName() << endl;
            count++;
        }
    }
    if(count == 0) {
        cout << "none";
    }
}
/*
 * The writeToFile function takes in a file name, an array of patients, and a size.
 * It creates an output file that displays called filenameReport.txt that shows the name, age,
 * height, weight, and status of a patient
 */
void writeToFile(string filename, Patient list[], int size) {
    ofstream outfile;
    filename.replace(filename.size() - 4, 10, "Report.txt");
    outfile.open(filename);
    if(outfile.fail()) {
        cout << filename << " file error" << endl;
        exit(0);
    }
    outfile << "Weight Status Report" << endl;
    outfile << "==================== === ====== ====== =============\n";
    outfile << "Name                 Age Height Weight Status\n";
    outfile << "==================== === ====== ====== =============\n";
    for(int i = 0; i < size; i++) {
        outfile << list[i].getName() << setfill(' ') << setw(22 - list[i].getName().size());
        outfile << " " << list[i].getAge() << setfill(' ') << setw(2);
        outfile << "   " << list[i].getHeight() << "     " << list[i].getWeight();
        outfile << "   " << list[i].weightStatus() << endl;
    }
    outfile << "==================== === ====== ====== =============\n";
    cout << "\nReport saved in:  " << filename << endl;
    outfile.close();
}
/*
 * Outputs----------------------------------------------------------------------------------------------
 */
/*
Please enter the input file's name: patient.txt

Showing patients with the "Underweight" status:
Paul West
Laura King

Showing patients with the "Overweight" status:
Linda East

Showing patients with the "Obese" status:
Tim South
Tom Baker
William Peterson
Peter Pan
Andrew Davis

Report saved in:  patientReport.txt

 */

/*
----------------------------------------------------------------------------------------------

Please enter the input file's name: patient1.txt

Showing patients with the "Underweight" status:
Tim South
Linda East
Paul West
Victor Smith
Tom Baker

Showing patients with the "Overweight" status:
none
Showing patients with the "Obese" status:
none
Report saved in:  patient1Report.txt
*/
/*----------------------------------------------------------------------------------------------
Please enter the input file's name: patient2.txt

Showing patients with the "Underweight" status:
Laura King

Showing patients with the "Overweight" status:
none
Showing patients with the "Obese" status:
none
Report saved in:  patient2Report.txt
*/