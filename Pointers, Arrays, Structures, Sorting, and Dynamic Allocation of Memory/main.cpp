/***
  Pointers, Arrays, Structures, Sorting, and Dynamic Allocation of Memory
  Name: Walter Tang
  IDE: CLion
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//define the Airport structure with a code, city, and enplanement number
struct Airport
{
    string code;
    string city;
    int enp;
};

// function prototypes
Airport *readArpData(string filename, int &size);
Airport **createPtrArray(Airport *list, int size);
void insertSort(Airport **pArp, int size);
void displayReport(Airport **pArp, Airport *list, int size);

int main()
{
    Airport *list;  // pointer to work with a dynamically allocated array of structs
    Airport **pArp; // pointer to work with an array of pointers to structs
    int size;
    string filename = "airports.txt";

    // function calls
    cout << "Enter input file name: ";
    cin >> filename;
    list = readArpData(filename, size);
    pArp = createPtrArray(list, size);
    insertSort(pArp, size);
    displayReport(pArp, list, size);

    // call readArpData
    // call createPtrArray
    // call insertSort
    // call displayReport

    return 0;
}

/*~*~*~*~*~*~
This function does the following:
 - opens the input file(with validation: exit if file not found)
 - reads size from the input file (the first number)
 - dynamically allocates an array of size Airport structures
 - reads data for size airports into the dynamically allocated array
 - closes the input file
 - returns the pointer to the dynamically allocated array
*~*/
Airport *readArpData(string filename, int &size)
{
    ifstream inputFile;
    Airport *list;

    //opens file
    inputFile.open(filename);

    //validation
    if(inputFile.fail()) {
        cout << "Error opening the input file: " << filename << ".\n";
        exit(EXIT_FAILURE);
    }

    /* Write your code here */
    //reads the number of airports
    inputFile >> size;

    list = new Airport[size];

   for(int i = 0; i < size; i++) {
       inputFile >> list[i].code >> list[i].enp;
       inputFile.ignore();
       getline(inputFile, list[i].city);
   }

    inputFile.close();
    return list;
}

/*~*~*~*~*~*~
This function creates an array of [size] pointers to Airport structures and initialize
each pointer to the corresponding element in the array of Airport structures
 -returns the pointer to the array of Airport structures

*~*/
Airport **createPtrArray(Airport *list, int size)
{
    Airport **pArp;
    pArp = new Airport*[size];
    /* Write your code here */
    for(int i = 0; i < size; i++) {
        pArp[i] = &list[i];
    }

    return pArp;
}

/*~*~*~*~*~*~
This function uses the insertion sort algorithm to rearrange the array of pointers
to show the array of structures in a descending order by the airport's number of
ennplanements
*~*/
void insertSort(Airport **list, int size)
{
    /* Write your code here */
    Airport* key;
    for(int i = 1; i < size; i++) {
        key = list[i];
        int j = i - 1;
        while(j >= 0 && key->enp > list[j]->enp) {
            list[j+1] = list[j];
            j--;
        }
        list[j+1] = key;
    }
}

/*~*~*~*~*~*~
This function displays the oringial order of the code, airports, and number of
 enplanements of the airports, then displays another column of airports
 sorted by number of enplanements in a descending order
*~*/
void displayReport(Airport **pArp, Airport *list, int size)
{
    cout << "\nOriginal Data                    Descending (enp)" << endl;
    for (int i = 0; i < size; i++){
        cout << list[i].code << " "
             << setw(15) << left << list[i].city
             << setw(10) << right << list[i].enp << "    ";
        cout << pArp[i]->code << " "
             << setw(15) << left << pArp[i]->city
             << setw(10) << right << pArp[i]->enp << endl;
    }
}


/*~*~*~*~*~*~ Save the output below

Enter input file name: airports.txt

Original Data                    Descending (enp)
BFL Bakersfield        100433    LAX Los Angeles      39636042
BUR Burbank           2077892    BUR Burbank           2077892
LAX Los Angeles      39636042    MRY Monterey           192136
MRY Monterey           192136    BFL Bakersfield        100433



*~*/


