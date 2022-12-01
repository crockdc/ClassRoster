#pragma once
#include <regex>
#include "student.h"

using namespace std;

class Roster
{
private:
	//Last item of the vector is the total students -1.
	int endItem = -1;
	const static int totalStudents = 5;//Total student roster is never greater than 5.
	Student* classRosterArray[totalStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr };//Roster array of nullptr students.

public:
	Roster();
	//Dereference the pointer to each student in the roster.
	Student** getStudents();
	//Parse function for a string of student information.
	void parse(string student);

	void add(string studentID, string firstName, string lastName, string email, int age, double daysToCompleteCourse1, double daysToCompleteCourse2, double daysToCompleteCourse3, DegreeProgram degreeProgram);
	void printAll();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	void printInvalidEmails();
	void printAverageCourseDays(string studentID);
	void removeByStudentID(string studentID);

	~Roster(); //Destructor for dynamic roster based on the totalStudents variable.
};

