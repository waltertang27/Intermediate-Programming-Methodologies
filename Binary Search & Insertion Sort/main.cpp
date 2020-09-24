/***
 Array of structures: Binary Search, Insertion Sort
 Name: Walter Tang
 IDE: CLion
*/

#include <iostream>
#include <fstream>
#include <string>


using namespace std;


/* The Airport structure with the following fields:
- code, a string
- city, a string
- enp, and integer
*/
struct Airport {
    string code;
    string city;
    int enp;
};

// function prototypes
/* Write your code here */
void readArpData(string filename, Airport list[], int AIRPORTS, int &size);
void searchTestDriver(Airport list[], int size);
void insertSort(Airport list[], int size);
void printArpData(Airport list[], int size);
void writeToFile(string filename, Airport list[], int size);
int binarySearch(Airport list[], int size, string code);

int main(){
    // constants definitions
    const int AIRPORTS = 30;        // maximum size of array

    // array definition
    Airport list[AIRPORTS];

    // other variables
    int size;           // actual size of arrays
    string filename;

    // function calls
    cout << "Enter input file name: ";
    cin >> filename;
    readArpData(filename, list, AIRPORTS, size);
    cout << endl;
    searchTestDriver(list, size);
    insertSort(list, size);

    string answer;
    //checks if user wants to show report
    cout << "Show Report(Y/N)? \n";
    cin >> answer;
    if (answer == "y" || answer == "Y")
        printArpData(list, size);
    writeToFile("report.txt", list, size);

    return 0;
}

/* Write your code here. For each function definition write a short comment too,
as demonstrated in previous assignments */

/* readArpData function
 * This function reads airport data from a file into a structure array
 *  The size variable will hold the number of airports stored in the structure array
 *  If the size of the array is bigger than the limit, the program ends
 */
void readArpData(string filename, Airport list[], int limit, int &size) {
    ifstream inputFile;

    //open file
    inputFile.open(filename);

    //validation
    if (inputFile.fail()) {
        cout << "Error opening the input file: " << filename << "." << endl;
        exit(EXIT_FAILURE);
    }
    size = 0;
    while (size < limit && inputFile >> list[size].code >> list[size].enp) {
        inputFile.ignore();
        getline(inputFile, list[size].city);
        size++;
    }
    //checks if size reaches maximum size of array
    if (size >= limit && !inputFile.eof()) {
        cout << "\nThe file contains more than 30lines!\n";
        exit(EXIT_FAILURE);
    }
    inputFile.close();
}
/* binarySearch function
 * uses the binary search algorithm to see if the user-input code is in the array of airports
 * The array has size elements
 * returns array subscript if the code is found, otherwise, returns -1
 */
int binarySearch(Airport list[], int size, string code) {
    int low = 0;
    int high = size - 1;
    int mid;
    while(high >= low) {
        mid = (low + high) / 2;
        if(list[mid].code < code) { //code must be in the right-half of the array
            low = mid + 1;
        }
        else if(list[mid].code > code) { //code must be in left-half of array
            high = mid - 1;
        }
        else {
            return mid; //found the code! (when list[mid].code = code);
        }
    }
    return -1;  //if code is not found, return -1
}
/* searchTestDriver function
 * prompts the user to enter an airport code
 * calls the binarySearch() function to search for the code
 * if  found, displays the enplanements number and city
 */
void searchTestDriver(Airport list[], int size) {
    char nextMove;
    do {    //use a do-while loop because it has to run at least once
        cout << "Please enter an airport code, such as LAX: \n";
        string input;
        cin >> input;
        int position = binarySearch(list, size, input);
        if (position != -1) {
            cout << input << " found! See related data below:\n";
            cout << "        Code: " << input << endl;
            cout << "        City: " << list[position].city << endl;
            cout << "Enplanements: " << list[position].enp << endl;
        } else {
            cout << input << " not found!\n";
        }
        //asks the user if they would like to enter another code
        cout << "Would you like to look up another airport(Y/N)? \n";
        cin >> nextMove;
    } while(nextMove == 'Y'  || nextMove == 'y');
}

/*
 * insertSort uses the insertion sort algorithm to sort the array of Airport structs
    a descending order
 */
void insertSort(Airport list[], int size) {
    Airport key;
    for(int i = 1; i < size; i++) {
        key = list[i];
        int j = i - 1;
        while(j >= 0 && key.enp > list[j].enp) {
            list[j+1] = list[j];
            j--;
        }
        list[j+1] = key;
    }
}
/*
 * prints the sorted array out by code, city, then enplanements
 */
void printArpData(Airport list[], int size) {
    cout << "Sorted List:\n";
    for (int i = 0; i < size; i++) {
        cout << list[i].code << " " << list[i].city << " (" << list[i].enp << ")\n";
    }
    cout << endl;
}
/*
 * Writes to an output file which displays the code, city, and enplanements of the airport array
 * accepts a string value, struct airport array, and an integer size value
 */
void writeToFile(string filename, Airport list[], int size) {
    ofstream outfile;
    outfile.open(filename);
    if(outfile.fail()) {   //checks to see if  output file fails
        cout << filename << " file error\n";
        exit(0);
    }
    for(int i = 0; i < size; i++) {
        outfile << list[i].code << " " << list[i].city << " (" << list[i].enp << ")\n";
    }
    cout << "The updated data has been saved into the file \"" << filename << "\".\n";
    outfile.close();
}
// Outputs
//------------------------------------------------------------------
/*
Enter input file name: airports.txt

Please enter an airport code, such as LAX:
ABC
ABC not found!
Would you like to look up another airport(Y/N)?
n
Show Report(Y/N)?
n
The updated data has been saved into the file "report.txt".

*/
//------------------------------------------------------------------
/*
Enter input file name: airports.txt

Please enter an airport code, such as LAX:
ACV
ACV found! See related data below:
        Code: ACV
        City: Acarta / Eureka
Enplanements: 69732
Would you like to look up another airport(Y/N)?
Y
Please enter an airport code, such as LAX:
STS
STS found! See related data below:
        Code: STS
        City: Santa Rosa
Enplanements: 167151
Would you like to look up another airport(Y/N)?
y
Please enter an airport code, such as LAX:
MRY
MRY found! See related data below:
        Code: MRY
        City: Monterey
Enplanements: 192136
Would you like to look up another airport(Y/N)?
n
Show Report(Y/N)?
n
The updated data has been saved into the file "report.txt".

*/
//------------------------------------------------------------------
/*
Enter input file name: airports.txt

Please enter an airport code, such as LAX:
AAB
AAB not found!
Would you like to look up another airport(Y/N)?
Y
Please enter an airport code, such as LAX:
STU
STU not found!
Would you like to look up another airport(Y/N)?
y
Please enter an airport code, such as LAX:
PQR
PQR not found!
Would you like to look up another airport(Y/N)?
n
Show Report(Y/N)?
n
The updated data has been saved into the file "report.txt".

 */
//------------------------------------------------------------------
/*
Enter input file name: airports.txt

Please enter an airport code, such as LAX:
AAAB
AAAB not found!
Would you like to look up another airport(Y/N)?
n
Show Report(Y/N)?
Y
Sorted List:
LAX Los Angeles (39636042)
SFO San Francisco (25707101)
SAN San Diego (10340164)
OAK Oakland (5934639)
SJC San Jose (5321603)
SNA Santa Ana (5217242)
SMF Sacramento (4969366)
ONT Ontario (2104625)
BUR Burbank (2077892)
LGB Long Beach (1386357)
PSP Palm Springs (995801)
FAT Fresno (761298)
SBA Santa Barbara (329751)
MRY Monterey (192136)
STS Santa Rosa (167151)
SBP San Louis Obispo (162719)
BFL Bakersfield (100433)
SCK Stockton (93076)
ACV Acarta / Eureka (69732)
RDD Redding (43414)
SMX Santa Maria (40120)
MMH Mammoth Lakes (21826)
CEC Crescent City (8667)
CRQ Carlsbad (180)
CIC Chico (0)

The updated data has been saved into the file "report.txt".

*/
//------------------------------------------------------------------
/*
Enter input file name: airports_2.txt

The file contains more than 30lines!

 */
//------------------------------------------------------------------
/*
Enter input file name: abc.text
Error opening the input file: abc.text.

*/
//------------------------------------------------------------------
/*
Enter input file name: airports.txt

Please enter an airport code, such as LAX:
LAX
LAX found! See related data below:
        Code: LAX
        City: Los Angeles
Enplanements: 39636042
Would you like to look up another airport(Y/N)?
y
Please enter an airport code, such as LAX:
PSP
PSP found! See related data below:
        Code: PSP
        City: Palm Springs
Enplanements: 995801
Would you like to look up another airport(Y/N)?
y
Please enter an airport code, such as LAX:
RDD
RDD found! See related data below:
        Code: RDD
        City: Redding
Enplanements: 43414
Would you like to look up another airport(Y/N)?
y
Please enter an airport code, such as LAX:
SCK
SCK found! See related data below:
        Code: SCK
        City: Stockton
Enplanements: 93076
Would you like to look up another airport(Y/N)?
y
Please enter an airport code, such as LAX:
SSS
SSS not found!
Would you like to look up another airport(Y/N)?
y
Please enter an airport code, such as LAX:
SJC
SJC found! See related data below:
        Code: SJC
        City: San Jose
Enplanements: 5321603
Would you like to look up another airport(Y/N)?
n
Show Report(Y/N)?
y
Sorted List:
LAX Los Angeles (39636042)
SFO San Francisco (25707101)
SAN San Diego (10340164)
OAK Oakland (5934639)
SJC San Jose (5321603)
SNA Santa Ana (5217242)
SMF Sacramento (4969366)
ONT Ontario (2104625)
BUR Burbank (2077892)
LGB Long Beach (1386357)
PSP Palm Springs (995801)
FAT Fresno (761298)
SBA Santa Barbara (329751)
MRY Monterey (192136)
STS Santa Rosa (167151)
SBP San Louis Obispo (162719)
BFL Bakersfield (100433)
SCK Stockton (93076)
ACV Acarta / Eureka (69732)
RDD Redding (43414)
SMX Santa Maria (40120)
MMH Mammoth Lakes (21826)
CEC Crescent City (8667)
CRQ Carlsbad (180)
CIC Chico (0)

The updated data has been saved into the file "report.txt".

*/


