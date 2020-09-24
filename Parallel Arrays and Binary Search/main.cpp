/***
 CIS 22B
 Project: Parallel Arrays and Binary Search

 Written by: Walter Tang, CIS22B
 IDE: CLion
  */


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// function prototypes
void printInfo();
void readArpData(string, string [], int [], string [], int &size, int limit);
int binarySearch(const string [], int, string);
void searchTestDriver(const string [], const int [], const string [], int [], int);
void writeToFile(string, const string [], const int [], const string [], const int [], int size);
void showTimeStamp();

int main(){
    // constants definitions
    const int AIRPORTS = 500;   // maximum size of arrays
    const string INFILENAME = "airports.txt";
    const string OUTFILENAME = "searchReport.txt";

    // arrays definitions
    string city[AIRPORTS];  //airport city
    string code[AIRPORTS];  //airport code
    int enp[AIRPORTS];      //airport enplanements
    int searchCount[AIRPORTS] = {0};    //set initial search count to 0

    // other variables
    int size;                   // actual size of arrays

    // function calls
    printInfo();
    readArpData(INFILENAME, code, enp, city, size, AIRPORTS);
    searchTestDriver(code, enp, city, searchCount, size);
    writeToFile(OUTFILENAME, code, enp, city, searchCount, size);
    showTimeStamp();
    return 0;
}
/*~*~*~*~*~*~
This function displays the project's title
*~*/
void printInfo()
{
    cout << "Project: Airports" << endl;
}

/*~*~*~*~*~*~
This function reads data about airports from a file into 3 parallel arrays.
The size variable will hold the number of airports that were stored in these arrays.
*~*/
void readArpData(string filename,
                 string code[],
                 int enp[],
                 string city[],
                 int &size,
                 int limit)
{
    ifstream inputFile;

    // open file
    inputFile.open(filename);

    // validation
    if(inputFile.fail()){
        cout << "Error opening the input file: " << filename << ".\n";
        exit(EXIT_FAILURE);
    }

    // read data from file into three parallel arrays
    size = 0;
    while (size < limit && inputFile >> code[size] >> enp[size]){
        inputFile.ignore();
        getline(inputFile, city[size]);
        size++;
    }

    // check if size reaches maximum size of array and there is more data in the file
    if(size == limit && !inputFile.eof()){
        cout << "\nThe file contains more than "<< limit << "lines!\n";
        exit(EXIT_FAILURE);
    }
    //array testing
    /*for(int i = 0; i < size; i++) {
        cout<<code[i]<<endl;
    }*/


    // close file
    inputFile.close();

}

/*~*~*~*~*~*~
 This function performs the binary search on a string array. The array has
 size elements. A value stored in this array will be searched. It will
 return the array subscript if found. Otherwise, -1 will be returned.
*~*/
int binarySearch(const string list[], int size, string code) {
    int low = 0;
    int high = size - 1;
    int mid;
    while(high >= low) {
        mid = (high + low) / 2; //finding the middle of the data
        if(list[mid] < code) {  //code must be in right-half of data
            low = mid + 1;
        }
        else if(list[mid] > code) { //code must be in left-half of data
            high = mid - 1;
        }
        else {  //if the code is at mid
            return mid;
        }
    }
   return -1;
}

/*~*~*~*~*~*~
 This writeToFile function accepts four arrays and their size, and a string value as arguments.
 It will show the number of searches for each airport, and airports information into an output
 file.
*~*/
void writeToFile(string filename,
                  const string code[],
                  const int enp[],
                  const string city[],
                  const int searchCount[],
                  int size) {

    ofstream outfile;
    outfile.open(filename);
    if(outfile.fail()) {    //checks to see if output file fails
        cout<<filename<<" file error"<<endl;
        exit(0);
    }
    outfile<<"~*~ Search History ~*~"<<endl;
    for(int i = 0; i < size; i++) {
        outfile<<searchCount[i]<<" "<<code[i]<<" "<<city[i]<<" ("<<enp[i]<<")"<<endl;
    }

}
/*~*~*~*~*~*~
 This function:
    - prompts the user to enter an airport code
    - calls binary search to search for that code
    - displays related data if found, or an error message
    - keeps track of the number of searches
    - asks the user if they want to continue searching
 *~*/
void searchTestDriver(const string code[],
                      const int enp[],
                      const string city[],
                      int searchCount[],
                      int size)
{

    int position;   //position of the airport in the data
    string inputCode;  //code the user enters
    char next;  //y/n if the user would like to continue
    do {    //use a do-while loop because it has to run at least once
        //cout<<size;, testing variable
        cout << "Please enter an airport code, such as LAX:" << endl;
        cin>>inputCode; //user enters the code
        position = binarySearch(code, size, inputCode);
        if(position == -1) {    //checks if the code does not exist in the data
            cout<<inputCode<<" not found!"<<endl;
        }
        else {
            //prints out the related information to the airport
            cout<<inputCode<<" found! See related data below:"<<endl;
            cout<<"        Code: "<<code[position]<<endl;
            cout<<"        City: "<<city[position]<<endl;
            cout<<"Enplanements: "<<enp[position]<<endl;
            ++searchCount[position];
        }
        //asks the user if they would like to enter another airport code
        cout<<"Would you like to look up another airport(Y/N)?";
        cin>>next;
    }
        //checks if the user enters "y" to continue
    while(next == 'Y' || next == 'y');

    cout<<endl;
    cout<<"The updated data has been saved into the file 'searchReport.txt'.";
    writeToFile("searchReport.txt", code, enp, city, searchCount, size);
}

/*~*~*~*~*~*~
   This function displays the current date and time
*~*/
void showTimeStamp()
{
    time_t timeval = time(0);
    char *chtime = ctime(&timeval);
    cout << "\n" << chtime << endl;
}
/*~*~*~*~*~*~ Save the output below



*~*/

