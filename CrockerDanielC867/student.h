#include <iostream>
#include <iomanip>
#include "degree.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::left;
using std::setw;

class Student 
{
public:
	const static int daysToCompleteCourseArraySize = 3;

private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	double daysToCompleteCourse[daysToCompleteCourseArraySize];
	DegreeProgram degreeProgram;

public:
	Student(); //Empty constructor
	Student(string studentID, string firstName, string lastName, string email, int age, double daysToCompleteCourse[], DegreeProgram degreeProgram); //Constructor with parameters.
	~Student(); //Destructor for what the Student class creates.

	//Accessors
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	const double* getDaysToCompleteCourse();
	DegreeProgram getDegreeProgram();

	//Mutators
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDaysToCompleteCourse(const double daysToCompleteCourse[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	static void printBar();

	void print();


};

