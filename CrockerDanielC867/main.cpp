/*The following program creates a student class and roster class, each with 
* a corresponding header file. A degree header is used to create an enumerator
* for the 3 Degree Programs. A string of 5 students is added to the roster file, which
* is then parsed and instantiated into unique Student objects, which are then added
* to a vector. Various functions are then performed onto the vector and displayed. */

#include <iostream>
#include "roster.h"

using namespace std;

int main()
{
    //Display unique program and programmer information.
    cout << "==========================================" << endl;
    cout << "C867-Scripting & Programming: Applications" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "Student ID: 010301135" << endl;
    cout << "Name: Daniel Crocker" << endl;
    cout << "==========================================" << endl;
    
    const int totalStudents = 5;//Array is kept at 5.
    
    Roster classRoster;//Instantiate the roster(corresponding STRING with student info is within the roster.cpp)

    cout << "\nDisplaying all students:" << endl;
    classRoster.printAll();//Print all the students via function.

    cout << "\nDisplaying invalid emails:" << endl;
    classRoster.printInvalidEmails();//Print the invalid emails via function.

    //Iterate through the 5 students via a for loop, each time calling the average function.
    cout << "\nDisplaying average days in course per student:" << endl;
    for (int i = 0; i < totalStudents; i++) {
        classRoster.printAverageCourseDays(classRoster.getStudents()[i]->getStudentID());
    }

    //Display by degree type(including SOFTWARE) using the corresponding enum and iterating through each student.
    for (int i = 0; i < 3; i++) {
        cout << "\nShowing students in degree program " << degreeTypeStrings[i] << ":" << endl;
        classRoster.printByDegreeProgram((DegreeProgram)i); //Cast the integer to the Degree Program via enum.
    }
    
    //Remove student ID of A3 using function.
    cout << "\nRemoving A3:" << endl;
    classRoster.removeByStudentID("A3");

    cout << "\nDisplaying all students:" << endl;
    classRoster.printAll();

    //Attempt to remove same student, different output is displayed due to student being removed from vector.
    cout << "\nRemoving A3 again:" << endl;
    classRoster.removeByStudentID("A3");

    cout << "\nDONE." << endl << endl;
    
    return 0;
}