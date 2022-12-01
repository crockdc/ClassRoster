#include <iostream>
#include "degree.h"

using namespace std;

class Student 
{
public:
	const static int daysToCompleteCourseArraySize = 3;//Only 3 inputs for each student's course completion days.

//Student variables
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
	//Constructor with parameters.
	Student(string studentID, string firstName, string lastName, string email, int age, double daysToCompleteCourse[], DegreeProgram degreeProgram);
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

	//Print details of the student
	void print();
};

