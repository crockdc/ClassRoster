#pragma once

#include <regex>
#include "student.h"

using std::vector;

class Roster
{
private:
	int endItem = -1;
	const static int totalStudents = 5;

	Student* students[totalStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr };

public:
	Roster();

	Student** getStudents();

	void parse(string student);

	void add(string studentID, string firstName, string lastName, string email, int age, double daysToCompleteCourse1, double daysToCompleteCourse2, double daysToCompleteCourse3, DegreeProgram degreeProgram);
	void printAll();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	void printInvalidEmails();
	void printAverageCourseDays(string studentID);
	void removeByStudentID(string studentID);

	~Roster(); //Destructor for dynamic roster based on the totalStudents variable.
};

