/*
 Build and procees a sorted linked list of Patient objects.
 The list is sorted in ascending order by name.
 Assume that the name is unique.
*/

// Written By: A. Student
// Changed By: Walter Tang
// IDE: Xcode


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>
#include "LinkedList.h"

using namespace std;

void buildList(const string &filename, LinkedList &list);
void deleteManager(LinkedList &list);
void searchManager(const LinkedList &list);
void displayManager(const LinkedList &list);

int main()
{

    string inputFileName = "patient.txt";
    LinkedList list;

    buildList(inputFileName, list);
    displayManager(list);
    searchManager(list);
    deleteManager(list);
    displayManager(list);
    return 0;
}

/* 
 This function reads data about colleges from a file and inserts them
 into a sorted linked list. The list is sorted in ascending order by code
 */
void buildList(const string &filename, LinkedList &list)
{
    ifstream inFile(filename);
    cout << "Reading data from \"" << filename << "\"\n";

    if(!inFile)
    {
        cout << "Error opening the input file: \""<< filename << "\"" << endl;
        exit(EXIT_FAILURE);
    }

    int age;
    double height;
    int weight;
    string name;

    while (inFile >> age >> height >> weight )
    {
        inFile.ignore(); //ignore a space
        getline(inFile, name);
        // create a Patient object and initialize it with data from file
        /* Write your code here */
        Patient p;
        p.setAge(age);
        p.setHeight(height);
        p.setWeight(weight);
        p.setName(name);
        
        // call insert to insert this new Patient object into the sorted list
        /* Write your code here */
        list.insertNode(p);
    }

    inFile.close();
}

/* 
 Delete manager: delete items from the list until the user enters Q to quit
 deleting
 Input Parameter: list
 */
void deleteManager(LinkedList &list)
{
    string target = "";

    cout << "\n Delete\n";
    cout << "=======\n";

    while(target != "Q")
    {
        cout << endl << "Enter a name (or Q to stop deleting) : \n";
        getline(cin, target);
        cout << endl;
        target[0] = toupper(target[0]);
        if(target != "Q")
        {
            if(list.deleteNode(target))
                cout << target << " has been deleted!\n";
            else
                cout << "College \"" << target << "\" was not found in this list." << endl;
        }
    }
    cout << "___________________END DELETE SECTION_____\n";
}

/* 
 Search manager: search the list until the user enters Q to quit searching
 Input Parameter: list
 */
void searchManager(const LinkedList &list)
{
    string target = "";
    Patient aPatient;

    cout << "\n Search\n";
    cout <<   "=======\n";



    while (target != "Q"){
        cout << "\nEnter a name (or Q to stop searching) : ";
        getline(cin, target);
        cout << endl;
        target[0] = toupper(target[0]);
        if(target != "Q") {
            if (list.searchList(target, aPatient) && target != "Q") {
                cout << "         Name: " << aPatient.getName() << endl;
                cout << "          Age: " << aPatient.getAge() << " years" << endl;
                cout << "       Height: " << aPatient.getHeight() << ".00 inches" << endl;
                cout << "       Weight: " << aPatient.getWeight() << " pounds" << endl;
                cout << "Weight Status: " << aPatient.weightStatus() << endl;
            }
            else {
                cout << target << "\" was not found in this list.\n";
            }
        }

    }
    cout << "___________________END SEARCH SECTION _____\n";
}

/* 
Display manager: diplay a header, formatted list content, and footer,
 depending on the user's choice;
 displays the number of nodes (always)
Input Parameter: list
*/
void displayManager(const LinkedList &list)
{
    // Sub-functions of displayManager()
    void showMenu(void);
    string getOption(void);
    void showHeader(string line);
   
    
    string line = "==================== ========= ============= =========== =============\n";
    string option;
    
    showMenu();
    option = getOption();
    while(option[0] != 'Q')
    {
        showHeader(line);
        switch (option[0])
        {
            case 'A':
               list.displayList();
                break;
            case 'U':
                list.displayList("Underweight");
                break;
            case 'N':
                list.displayList("Normal");
                break;
            case 'O':
                list.displayList("Overweight");
                break;
            case 'B':
                list.displayList("Obese");
                break;
        }
        cout << endl;
        cout << line;
        option = getOption();
    }
    cout << "Number of patients: " << list.getLength() << endl;
}

/* 
Displays the header of the list used in displayManager()
Input Parameter: line
*/
void showHeader(string line)
{
    cout << line;
    cout << left << setw(21) << "Name"
              << setw(11) << "Age"
              << setw(13) << "Height"
              << setw(12) << "Weight"
              << setw(13) << "Status" << endl;
     cout << line;
}

/* 
Displays a menu, gets and returns the user's option (used in displayManager())
*/
string getOption(void)
{
    void showMenu(void);
    
    string option;
    cout << "What is your option [A/U/N/O/B/Q]? ";
    cin >> option;
    cin.ignore();
    option[0] = toupper(option[0]);
    while (option != "A" && option != "U" && option != "N" && option != "O" && option != "B" && option != "Q")
    {
        cout << "Invalid Option: Try again!";
        cout << "What is your option [A/U/N/O/B/Q]? ";
        cin >> option;
        cin.ignore();
        option[0] = toupper(option[0]);
    }
    
    return option;
}
/*
Displays a menu - used in displayManager()
*/
void showMenu(void)
{
    cout << "The following reports are available: " << endl;
    cout << "[A] - All" << endl
         << "[U] - Underweight" << endl
         << "[N] - Normal" << endl
         << "[O] - Overweight" << endl
         << "[B] - Obese" << endl
         << "[Q] - Quit" << endl;
}

/*-------------------------------------------------------
Reading data from "patient.txt"
The following reports are available:
[A] - All
[U] - Underweight
[N] - Normal
[O] - Overweight
[B] - Obese
[Q] - Quit
What is your option [A/U/N/O/B/Q]? Q
Number of patients: 17

 Search
=======

Enter a name (or Q to stop searching) : Q

___________________END SEARCH SECTION _____

 Delete
=======

Enter a name (or Q to stop deleting) :
Q

___________________END DELETE SECTION_____
The following reports are available:
[A] - All
[U] - Underweight
[N] - Normal
[O] - Overweight
[B] - Obese
[Q] - Quit
What is your option [A/U/N/O/B/Q]? Q
Number of patients: 17
*/
/*-------------------------------------------------------
Reading data from "patient.txt"
The following reports are available:
[A] - All
[U] - Underweight
[N] - Normal
[O] - Overweight
[B] - Obese
[Q] - Quit
What is your option [A/U/N/O/B/Q]? A
==================== ========= ============= =========== =============
Name                 Age        Height       Weight      Status
==================== ========= ============= =========== =============
Andrew Davis          69 years  72.00 inches  254 pounds Obese
Ann McDonald          33 years  71.00 inches  162 pounds Normal
Diana Newman          26 years  68.00 inches  133 pounds Normal
George Paul Lucas     29 years  70.00 inches  144 pounds Normal
Jane North            25 years  66.00 inches  120 pounds Normal
Jim Gaddis            28 years  68.00 inches  143 pounds Normal
Laura King            42 years  67.00 inches  115 pounds Underweight
Linda East            52 years  69.00 inches  175 pounds Overweight
Mary Jane Doe         42 years  65.00 inches  130 pounds Normal
Mary Johnson          22 years  67.00 inches  135 pounds Normal
Monica T. Potter      23 years  66.00 inches  135 pounds Normal
Paul West             31 years  71.00 inches  122 pounds Underweight
Peter Pan             52 years  75.00 inches  270 pounds Obese
Tim South             64 years  72.00 inches  251 pounds Obese
Tom Baker             39 years  73.00 inches  229 pounds Obese
Victor Smith          19 years  71.00 inches  150 pounds Normal
William Peterson      54 years  70.00 inches  215 pounds Obese

==================== ========= ============= =========== =============
What is your option [A/U/N/O/B/Q]? U
==================== ========= ============= =========== =============
Name                 Age        Height       Weight      Status
==================== ========= ============= =========== =============
Laura King            42 years  67.00 inches  115 pounds Underweight
Paul West             31 years  71.00 inches  122 pounds Underweight

==================== ========= ============= =========== =============
What is your option [A/U/N/O/B/Q]? N
==================== ========= ============= =========== =============
Name                 Age        Height       Weight      Status
==================== ========= ============= =========== =============
Ann McDonald          33 years  71.00 inches  162 pounds Normal
Diana Newman          26 years  68.00 inches  133 pounds Normal
George Paul Lucas     29 years  70.00 inches  144 pounds Normal
Jane North            25 years  66.00 inches  120 pounds Normal
Jim Gaddis            28 years  68.00 inches  143 pounds Normal
Mary Jane Doe         42 years  65.00 inches  130 pounds Normal
Mary Johnson          22 years  67.00 inches  135 pounds Normal
Monica T. Potter      23 years  66.00 inches  135 pounds Normal
Victor Smith          19 years  71.00 inches  150 pounds Normal

==================== ========= ============= =========== =============
What is your option [A/U/N/O/B/Q]? O
==================== ========= ============= =========== =============
Name                 Age        Height       Weight      Status
==================== ========= ============= =========== =============
Linda East            52 years  69.00 inches  175 pounds Overweight

==================== ========= ============= =========== =============
What is your option [A/U/N/O/B/Q]? B
==================== ========= ============= =========== =============
Name                 Age        Height       Weight      Status
==================== ========= ============= =========== =============
Andrew Davis          69 years  72.00 inches  254 pounds Obese
Peter Pan             52 years  75.00 inches  270 pounds Obese
Tim South             64 years  72.00 inches  251 pounds Obese
Tom Baker             39 years  73.00 inches  229 pounds Obese
William Peterson      54 years  70.00 inches  215 pounds Obese

==================== ========= ============= =========== =============
What is your option [A/U/N/O/B/Q]? Q
Number of patients: 17

 Search
=======

Enter a name (or Q to stop searching) : Q

___________________END SEARCH SECTION _____

 Delete
=======

Enter a name (or Q to stop deleting) :
Q

___________________END DELETE SECTION_____
The following reports are available:
[A] - All
[U] - Underweight
[N] - Normal
[O] - Overweight
[B] - Obese
[Q] - Quit
What is your option [A/U/N/O/B/Q]? Q
Number of patients: 17
*/
