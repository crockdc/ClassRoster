#include "roster.h"

using namespace std;

//Create array of strings which contain student data.
const string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Daniel,Crocker,dcroc48@wgu.edu,36,54,66,41,SOFTWARE" };
const int totalStudents = 5;//Five students are the maximum amount in the roster, which does not change.

//Instantiate a roster which uses the following parse function to parse each string of the studentData array.
Roster::Roster()
{
	parse(studentData[0]);
	parse(studentData[1]);
	parse(studentData[2]);
	parse(studentData[3]);
	parse(studentData[4]);
}

//Dereference the pointer to each student in the Roster
Student** Roster::getStudents()
{
	return Roster::classRosterArray;
}

//Parse a string containing student parameters that are separated by commas.
void Roster::parse(string student)
{
	vector<string> result;//Create a vector of each of the strings.
	size_t start;
	size_t end = 0;
	//Parse by the commas within the student string.
	while ((start = student.find_first_not_of(',', end)) != string::npos)
	{
		end = student.find(',', start);
		result.push_back(student.substr(start, end - start));
	}
	DegreeProgram dp = DegreeProgram::SECURITY;//Set degree program to Security initially, verify with switch.
	switch (result.at(8).back())
	{
	case 'K': dp = DegreeProgram::NETWORK; break;//If last character is K, then degree program is Network.
	case 'E': dp = DegreeProgram::SOFTWARE; break;//If last character is E, then degree program is Software.
	}
	//Call the add function created below, use stoi for integer argument and stod for double argument.
	add(result.at(0), result.at(1), result.at(2), result.at(3), stoi(result.at(4)), stod(result.at(5)), stod(result.at(6)), stod(result.at(7)), dp);
}

//Add function adds a student object to the students array using the student constructor.
void Roster::add(string studentID, string firstName, string lastName, string email, int age, double daysToCompleteCourse1, double daysToCompleteCourse2, double daysToCompleteCourse3, DegreeProgram degreeProgram)
{
	double daysToCompleteCourseArray[3] = { daysToCompleteCourse1, daysToCompleteCourse2, daysToCompleteCourse3 };
	classRosterArray[++endItem] = new Student(studentID, firstName, lastName, email, age, daysToCompleteCourseArray, degreeProgram);
}

//Print each student in the students array.
void Roster::printAll()
{
	for (int i = 0; i <= Roster::endItem; i++) {
		Roster::classRosterArray[i]->print();
	}
}

//Iterate through the students array and display any students with matching Degree Programs.
void Roster::printByDegreeProgram(DegreeProgram dp)
{
	for (int i = 0; i <= Roster::endItem; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == dp) {
			classRosterArray[i]->print();
		}
	}
}

//Iterate through the array of students, get their email, check if email contains space, period, or is missing an @.
//If any of the 3 is true then the email is displayed as invalid.
void Roster::printInvalidEmails()
{
	for (int i = 0; i <= Roster::endItem; i++) {
		string email = Roster::getStudents()[i]->getEmail();
		if (email.find(' ') != string::npos || email.find('.') == string::npos || email.find('@') == string::npos) {
			cout << email << " - is invalid." << endl;
		}
	}
}

//Iterate through the array of students, add their 3 course day totals together then divide by 3, cast that to integer type and display.
void Roster::printAverageCourseDays(string studentID)
{
	for (int i = 0; i <= Roster::endItem; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			cout << "Student ID: " << studentID << ", average days in course is: ";
			cout << (int)(classRosterArray[i]->getDaysToCompleteCourse()[0] + classRosterArray[i]->getDaysToCompleteCourse()[1] + classRosterArray[i]->getDaysToCompleteCourse()[2]) / 3 << endl;
		}
	}
}

//Take in a student ID, check if each student of the array has a matching ID, if TRUE then that student gets
//swapped with the last item of the array(if applicable), then the endItem variable gets reduced by 1.
void Roster::removeByStudentID(string studentID)
{
	bool correct = false;
	for (int i = 0; i <= Roster::endItem; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			correct = true;
			Student* holder = classRosterArray[i];
			classRosterArray[i] = classRosterArray[totalStudents - 1];
			classRosterArray[totalStudents - 1] = holder;
			Roster::endItem--;
		}
	}
	if (correct) {
		cout << "Student " << studentID << " removed." << endl;
	}
	else cout << "Student " << studentID << " not found." << endl;
}

//Iterate through the array of students and delete their memory, assign their pointer to nullptr.
Roster::~Roster()
{
	for (int i = 0; i < totalStudents; i++) {
		cout << "Memory destruction/deletion successful for " << classRosterArray[i]->getStudentID() << endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}

