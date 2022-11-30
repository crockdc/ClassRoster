#include "roster.h"

Roster::Roster()
{

}

void Roster::parse(string student)
{
	vector<string> result;
	size_t start;
	size_t end = 0;
	while ((start = student.find_first_not_of(',', end)) != string::npos)
	{
		end = student.find(',', start);
		result.push_back(student.substr(start, end - start));
	}
	DegreeProgram dp = DegreeProgram::SECURITY;
	switch (result.at(6).back())
	{
	case 'Y': dp = DegreeProgram::NETWORK; break;
	case 'N': dp = DegreeProgram::SOFTWARE; break;
	}
	add(result.at(0), result.at(1), result.at(2), result.at(3), stoi(result.at(4)), stod(result.at(5)), stod(result.at(6)), stod(result.at(7)), dp);
}

void Roster::add(string studentID, string firstName, string lastName, string email, int age, double daysToCompleteCourse1, double daysToCompleteCourse2, double daysToCompleteCourse3, DegreeProgram degreeProgram)
{
	double daysToCompleteCourseArray[3] = { daysToCompleteCourse1, daysToCompleteCourse2, daysToCompleteCourse3 };
	students[++endItem] = new Student(studentID, firstName, lastName, email, age, daysToCompleteCourseArray, degreeProgram);
	cout << "Student added to roster at row " << endItem + 1 << endl;
}

void Roster::printAll()
{
	Student::printBar();
	for (int i = 0; i <= Roster::endItem; i++) {
		Roster::students[i]->print();
	}
}

void Roster::printByDegreeProgram(DegreeProgram dp)
{
	Student::printBar();
	for (int i = 0; i <= Roster::endItem; i++) {
		if (Roster::students[i]->getDegreeProgram() == dp) {
			students[i]->print();
		}
	}
}

void Roster::printInvalidEmails()
{
	for (int i = 0; i <= Roster::endItem; i++) {
		string studentID = Roster::getStudents()[i]->getStudentID();
		if (studentID.find(' ') != string::npos || studentID.find('.') != string::npos || studentID.find('@') == string::npos) {
			cout << studentID << " is invalid!" << endl;
		}
	}
}
void Roster::printAverageCourseDays(string studentID)
{
	for (int i = 0; i <= Roster::endItem; i++) {
		if (students[i]->getStudentID() == studentID) {
			cout << studentID << ":";
			cout << (students[i]->getDaysToCompleteCourse()[0] + students[i]->getDaysToCompleteCourse()[1] + students[i]->getDaysToCompleteCourse()[2]) / 3.0 << endl;
		}
	}
}

void Roster::removeByStudentID(string studentID)
{
	bool correct = false;
	for (int i = 0; i <= Roster::endItem; i++) {
		if (students[i]->getStudentID() == studentID) {
			correct = true;
			Student* holder = students[i];
			students[i] = students[totalStudents - 1];
			students[totalStudents - 1] = holder;
			Roster::endItem--;
		}
	}
	if (correct) {
		cout << "Student " << studentID << " removed." << endl;
		printAll();
	}
	else cout << "Student " << studentID << " not found." << endl;
}

Roster::~Roster()
{
	for (int i = 0; i < totalStudents; i++) {
		cout << "Memory destruction/deletion successful for " << students[i]->getStudentID() << endl;
		delete students[i];
		students[i] = nullptr;
	}
}

