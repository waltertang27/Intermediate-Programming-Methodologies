/**
 CIS 22B
 2D Arrays

 Project: Airports

 Written by Walter Tang
 IDE: CLion

 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAXARP = 15;  // maximum number of airports in a state

//function prototypes
void readData(string fileName, string airports[], int price[][MAXARP], const int MAXARP, int &size);
int getMenuOption(int low, int high);
void displayTable(const string airports[], const int price[][MAXARP], const int size);
void countDestination(const int price[][MAXARP], int numOfDestination[MAXARP], const int size);
void displayDestination(const string airports[],const int price[][MAXARP],
                        const int numOfDestination[MAXARP], const int size);
void displayConnection(const string airports[], const int price[][MAXARP], const int size);

int main( void )
{
    //array definitions
    string airports[MAXARP];
    int price[MAXARP][MAXARP];
    int numOfDestination[MAXARP] = {0};

    //other variables
    int size = 0; // actual number of airports in the file
    string fileName;

    // read data from file
    cout << "What is the input file's name? ";
    cin >> fileName;
    readData(fileName, airports, price, MAXARP, size);
    int option = getMenuOption(1, 4);
    switch( option )
    {
        case 1: // display the original informations as a table
            /* Write your code here: call diplayTable */
            displayTable(airports, price, size);

            break;
        case 2: // count the number of destination
            /* Write your code here: call countDestination */
            countDestination(price, numOfDestination, size);

            // list each airport's destinations, including the number of destination airports
            /* Write your code here: call displayDestination */
            displayDestination(airports, price, numOfDestination, size);
            break;
        case 3: // list all groups of two airports connected by flights, including the flight price
            /* Write your code here: call displayConnection */
            displayConnection(airports, price, size);
            break;
        case 4: cout << "\n\nEnd of Program!" << endl;
            break;
    }


    return 0;
}   // main

/*~*~*~*~*~*~
 This function displays the menu
*~*/
void displayMenu()
{
    cout << "Choose one of the following options: " << endl;
    cout << " 1. Display the original informations as a table" << endl;
    cout << " 2. Display each airport's destinations, including the number of destination airports" << endl;
    cout << " 3. Display direct flights, including price" << endl;
    cout << " 4. Exit the program" << endl;
}

/*~*~*~*~*~*~
 This function calls a function to display the program's menu
 and gets a valid option from the user
*~*/
int getMenuOption(int low, int high)
{
    if( low > high) // if out of order, swap
    {
        int hold = low;
        low = high;
        high = hold;
    }
    displayMenu();
    //variables for user input
    int option;
    bool success;
    do
    {
        cout << "Please enter a number (" << low << " to " << high << "): ";
        success = (bool)(cin >> option);
        cin.clear();          // to clear the error flag
        cin.ignore(80, '\n'); // to discard the unwanted input from the input buffer
    }while(!success || option < low || option > high);

    return option;
}

/*~*~*~*~*~*~
 This function reads data into two parallel arrays.
 The 1D string array holds the airports codes while 2D array holds the flight price of
 each airport connected to another. The first line of the file represents the number of airports,
 which will be stored in the size variable.
*~*/
void readData(string fileName, string airports[], int price[][MAXARP], const int MAXARP, int &size){
    ifstream inputFile;
    //open the file
    inputFile.open(fileName);

    //check exception
    if(inputFile.fail()){
        cout << "Please check the file. Try again.\n";
        exit(EXIT_FAILURE);
    }

    //read numbers of airports
    inputFile >> size;

    // check if size reaches maximum size of array
    /* Write your code here */
    int limit = 15;
    if(size >= limit && !inputFile.eof()){
        cout << "\nInput from file: "<<size<<"." << endl;
        cout << "It is greater than 15, the array's capacity.\n";
        cout << "Program ends here!\n";
        exit(EXIT_FAILURE);
    }
    // read airports codes into 1D array
    for (int r = 0; r < size; r++ )
    {
        inputFile >> airports[r];
    }

    // read flight price between two airports into 2D array
    /* Write your code here */
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            inputFile >> price[i][j];
        }
    }
    //closes input file
    inputFile.close();
}

/*~*~*~*~*~*~
 This function display the airports codes and information as a table. The header and first row list
 all airport codes. The number represents the flight price of two airports. '0' means no flights
 between these two airports.
*~*/
void displayTable(const string airports[], const int price[][MAXARP], const int size){
    cout << "\n\nAirport codes and original table:\n\n";
    /* Write your code here */
    //Displays the "top" part of the table
    cout<<"    |";
    for(int i = 0; i < size; i++) {
        cout<<" " << airports[i];
    }
    cout<<endl;
    cout<<"---  ";
    for(int i = 0; i < size; i++) {
        cout<<" ---";
    }
    cout<<endl;
    //displays the prices in the table
    for(int i = 0; i < size; i++ ) {
        cout<<airports[i] << " " << "|";
        for(int j = 0; j < size; j++) {
            /* checks the number of spaces to properly align the prices.
            * If the price is less than 10, use two spaces.
            * If the price is between 10 and 99, use one space.
            * If the price is greater than 99, don't use a space.
            * */
                if (price[i][j] < 10) {
                    cout << "   " << price[i][j];
                } else if (price[i][j] >= 10 && price[i][j] < 99) {
                    cout << "  " << price[i][j];
                } else {
                    cout << " " << price[i][j];
                }
            }
        cout<<endl;
    }
    cout<<endl;
}

/*~*~*~*~*~*~
 This function counts the number of destination from one airports to another, then stores it into one
 1D parallel array.
*~*/
void countDestination(const int price[][MAXARP], int numOfDestination[MAXARP], const int size){
    /* Write your code here */
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
                if(price[i][j] > 0) {      //counts a destination if there is a price
                    numOfDestination[i]++;
                }
        }
    }
}

/*~*~*~*~*~*~
 This function displays each airports' destinations, including the number of destination airports.
*~*/
void displayDestination(const string airports[], const int price[][MAXARP],
                        const int numOfDestination[MAXARP], const int size){
    cout << "\n\nAirports' destinations: \n\n";
    /* Write your code here */
    for(int i = 0; i < size; i++) {
        int count = 0;  //checks if it is the last destination
        cout << airports[i] <<" ("<<numOfDestination[i]<<"): ";
        for(int j = 0; j < size; j++) {
            //checks to see if the price is greater than 0, which means the connection between the airports exists
            if (price[i][j] > 0) {
                //if there is only one destination possible, print it and go onto the next line
                if (numOfDestination[i] == 1) {
                    cout << airports[j] << endl;
                    break;  //go onto the next airport after printing the current one
                }
                //prints the destination (unless it is the last destination in the row)
                else if (count < numOfDestination[i] - 1) {
                    cout << airports[j] << ", ";
                    count++;
                }
                // if it is the last destination in the row, print the destination then go to next line (no comma)
                else {
                    cout << airports[j] << endl;
                }
            }
        }
    }
    cout<<endl;

}

/*~*~*~*~*~*~
 This function displays all groups of two airports connected by flights, including flight.
 It determines whether two airports are connected by checking the right side of diagonal of flight price.
 It will print groups of two airports including flight price if price is not zero, otherwise no connected
 between two airports.
*~*/
void displayConnection(const string airports[], const int price[][MAXARP], int size){
    cout << "\n\nDirect Flights: \n\n";
    /* Write your code here */
    int count = 0;  //checks to read only above the diagonal line of the 2D array
        /*The nested for loops are written like this so that the direct flights
          are not repeated (ex. BUR -> LAX is the same as LAX -> BUR, so I only
          list it once). When reading the data, I only check half of the 2D array
          because it is mirrored across the 2D array diagonal line.
          This prevents the program from listing flights twice. */
        for (int i = 0; i < size; i++) {
            for (int j = count; j < size; j++) {
                if (price[i][j] > 0) {
                    cout << airports[i] << " -> " << airports[j] << " ";
                    /* checks the number of spaces to properly align the prices.
                     * If the price is less than 10, use two spaces.
                     * If the price is between 10 and 99, use one space.
                     * If the price is greater than 99, don't use a space.
                     * */
                    if (price[i][j] < 10) {
                        cout << "  " << price[i][j] << endl;
                    } else if (price[i][j] >= 10 && price[i][j] < 99) {
                        cout << " " << price[i][j] << endl;
                    } else {
                        cout << price[i][j] << endl;
                    }
                }
            }
            count++;
        }
        cout<<endl;
}
/** Save the output below

What is the input file's name? airports.txt
Choose one of the following options:
 1. Display the original informations as a table
 2. Display each airport's destinations, including the number of destination airports
 3. Display direct flights, including price
 4. Exit the program
Please enter a number (1 to 4): 1


Airport codes and original table:

    | BUR LAX SFO SMO
---   --- --- --- ---
BUR |   0 150  80  50
LAX | 150   0   0   0
SFO |  80   0   0 229
SMO |  50   0 229   0

*/
/*
What is the input file's name? airports.txt
Choose one of the following options:
 1. Display the original informations as a table
 2. Display each airport's destinations, including the number of destination airports
 3. Display direct flights, including price
 4. Exit the program
Please enter a number (1 to 4): 2


Airports' destinations:

BUR (3): LAX, SFO, SMO
LAX (1): BUR
SFO (2): BUR, SMO
SMO (2): BUR, SFO

*/
/*
What is the input file's name? airports.txt
Choose one of the following options:
 1. Display the original informations as a table
 2. Display each airport's destinations, including the number of destination airports
 3. Display direct flights, including price
 4. Exit the program
Please enter a number (1 to 4): 3


Direct Flights:

BUR -> LAX 150
BUR -> SFO  80
BUR -> SMO  50
SFO -> SMO 229

 */
/*
What is the input file's name? airports.txt
Choose one of the following options:
 1. Display the original informations as a table
 2. Display each airport's destinations, including the number of destination airports
 3. Display direct flights, including price
 4. Exit the program
Please enter a number (1 to 4): 4


End of Program!

*/
/*
What is the input file's name? airports_1.txt
Choose one of the following options:
 1. Display the original informations as a table
 2. Display each airport's destinations, including the number of destination airports
 3. Display direct flights, including price
 4. Exit the program
Please enter a number (1 to 4): 1


Airport codes and original table:

    | BUR FAT LGB LAX MRY OAK SMF SAN SFO SJC SBO SMO
---   --- --- --- --- --- --- --- --- --- --- --- ---
BUR |   0   0   0   0 122   0   0   0   0   0 316   0
FAT |   0   0   0   0   0   0   0   0 321 455   0   0
LGB |   0   0   0 125   0   0   0   0 267   0   0   0
LAX |   0   0 125   0   0  50   0   0 250   0 370   0
MRY | 122   0   0   0   0 259   0   0   0   0   0 119
OAK |   0   0   0  50 259   0   0 129   0   0   0   0
SMF |   0   0   0   0   0   0   0 111   0   0 125   0
SAN |   0   0   0   0   0 129 111   0   0   0   0   0
SFO |   0 321 267 250   0   0   0   0   0 190   0   0
SJC |   0 455   0   0   0   0   0   0 190   0   0   0
SBO | 316   0   0 370   0   0 125   0   0   0   0 145
SMO |   0   0   0   0 119   0   0   0   0   0 145   0

*/
/*
What is the input file's name? airports_1.txt
Choose one of the following options:
 1. Display the original informations as a table
 2. Display each airport's destinations, including the number of destination airports
 3. Display direct flights, including price
 4. Exit the program
Please enter a number (1 to 4): 2


Airports' destinations:

BUR (2): MRY, SBO
        FAT (2): SFO, SJC
        LGB (2): LAX, SFO
        LAX (4): LGB, OAK, SFO, SBO
        MRY (3): BUR, OAK, SMO
        OAK (3): LAX, MRY, SAN
        SMF (2): SAN, SBO
        SAN (2): OAK, SMF
        SFO (4): FAT, LGB, LAX, SJC
        SJC (2): FAT, SFO
        SBO (4): BUR, LAX, SMF, SMO
        SMO (2): MRY, SBO

*/
/*
What is the input file's name? airports_1.txt
Choose one of the following options:
 1. Display the original informations as a table
 2. Display each airport's destinations, including the number of destination airports
 3. Display direct flights, including price
 4. Exit the program
Please enter a number (1 to 4): 3


Direct Flights:

BUR -> MRY 122
BUR -> SBO 316
FAT -> SFO 321
FAT -> SJC 455
LGB -> LAX 125
LGB -> SFO 267
LAX -> OAK  50
LAX -> SFO 250
LAX -> SBO 370
MRY -> OAK 259
MRY -> SMO 119
OAK -> SAN 129
SMF -> SAN 111
SMF -> SBO 125
SFO -> SJC 190
SBO -> SMO 145

*/
/*
What is the input file's name? airports_1.txt
Choose one of the following options:
 1. Display the original informations as a table
 2. Display each airport's destinations, including the number of destination airports
 3. Display direct flights, including price
 4. Exit the program
Please enter a number (1 to 4): 4


End of Program!

*/
/*
What is the input file's name? airports_2.txt
Choose one of the following options:
 1. Display the original informations as a table
 2. Display each airport's destinations, including the number of destination airports
 3. Display direct flights, including price
 4. Exit the program
Please enter a number (1 to 4): 1


Airport codes and original table:

    | BUR LAX
---   --- ---
BUR |   0 150
LAX | 150   0

*/
/*
What is the input file's name? airports_2.txt
Choose one of the following options:
 1. Display the original informations as a table
 2. Display each airport's destinations, including the number of destination airports
 3. Display direct flights, including price
 4. Exit the program
Please enter a number (1 to 4): 2


Airports' destinations:

BUR (1): LAX
LAX (1): BUR

*/
/*
What is the input file's name? airports_2.txt
Choose one of the following options:
 1. Display the original informations as a table
 2. Display each airport's destinations, including the number of destination airports
 3. Display direct flights, including price
 4. Exit the program
Please enter a number (1 to 4): 3


Direct Flights:

BUR -> LAX 150

*/
/*
What is the input file's name? airports_2.txt
Choose one of the following options:
 1. Display the original informations as a table
 2. Display each airport's destinations, including the number of destination airports
 3. Display direct flights, including price
 4. Exit the program
Please enter a number (1 to 4): 4

*/
/*
What is the input file's name? airports_3.txt

Input from file: 16.
It is greater than 15, the array's capacity.
Program ends here!

*/
/*
What is the input file's name? fakeairport
Please check the file. Try again.

*/