#include "student.h"
#include <iostream>

using namespace std;

//Parameterless constructor sets generic values.
Student::Student() 
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < daysToCompleteCourseArraySize; i++) {
		this->daysToCompleteCourse[i] = 0;
	}
	this->degreeProgram = DegreeProgram::SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string email, int age, double daysToCompleteCourse[], DegreeProgram degreeProgram) 
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	//Array iterated through and created.
	for (int i = 0; i < daysToCompleteCourseArraySize; i++) {
		this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
	}
	this->degreeProgram = degreeProgram;
}

Student::~Student() {} //Days to complete is not dynamically allocated so needs no destruction.

//Accessors
string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmail() { return this->email; }
int Student::getAge() { return this->age; }
const double* Student::getDaysToCompleteCourse() { return this->daysToCompleteCourse; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

//Mutators; proper parameter is provided, student's corresponding variables then set to the provided argument.
void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }
//Days to complete each course is an array of 3, which is iterated through and assigned to the student.
void Student::setDaysToCompleteCourse(const double daysToCompleteCourse[]) {
	for (int i = 0; i < daysToCompleteCourseArraySize; i++) {
		this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
	}
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

//Print each Student's information tab separated.
void Student::print() {
	cout << this->studentID << "\t";
	cout << this->firstName << "\t";
	cout << this->lastName << "\t";
	//cout << this->email << "\t";
	cout << this->age << "\t";
	cout << "{";
	cout << daysToCompleteCourse[0] << ",";
	cout << daysToCompleteCourse[1] << ",";
	cout << daysToCompleteCourse[2] << "}\t";
	cout << degreeTypeStrings[(int)this->degreeProgram]; //Converts the Student's degree program to the corresponding enum integer, which then displays the corresponding enum as a string.
	cout << endl;
}