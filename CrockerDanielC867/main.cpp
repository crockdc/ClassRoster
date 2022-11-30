#include <iostream>
#include "roster.h"

using namespace std;

int main()
{
    cout << "==========================================" << endl;
    cout << "C867-Scripting & Programming: Applications" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "Student ID: 010301135" << endl;
    cout << "Name: Daniel Crocker" << endl;
    cout << "==========================================" << endl;

    const string studentData[] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Daniel,Crocker,dcroc48@wgu.edu,36,54,66,41,SOFTWARE" };
    const int totalStudents = 5;

    Roster roster;

    cout << "Displaying all students:" << endl;
    roster.printAll();

    //Display by degree type
    for (int i = 0; i < 3; i++) {
        cout << "Displaying by degree type:" << degreeTypeStrings[i] << endl;
        roster.printByDegreeProgram((DegreeProgram)i); // Casted to Degree Program
    }
    
    cout << "Displaying invalid emails:" << endl;
    roster.printInvalidEmails();

    cout << "Dispalying average days in course per student:" << endl;
    for (int i = 0; i < totalStudents; i++) {
        roster.printAverageCourseDays(roster.getStudents()[i]->getStudentID());
    }

    cout << "Removing A3:" << endl;
    roster.removeByStudentID("A3");

    cout << "Removing A3 again:" << endl;
    roster.removeByStudentID("A3");

    cout << "DONE.";
    
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
