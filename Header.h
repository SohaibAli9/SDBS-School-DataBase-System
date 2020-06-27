//19F - 0161 Sohaib Ali
//19F - 0380 Hassan Munir


#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void validString(string &str);
bool isInt(string str);
int strToInt(string str);

struct student
{
	string firstName, lastName;
	int clss;
	string rollNo, date, gender, contact, fName, fProf, pContact;
	int fee;
	string bloodG, address, password;
};
struct teacher
{
	int id;
	int crass; //courses assigned
	string firstName, lastName, email, joinDate, pass, cPass;
	string cnic, gender, qual, contact, DOB, address, salary;
};
struct course
{
	int id;
	string name, code;
	int clss;
	string pCourse;
};
struct assignInfo
{
	string code, name;
	int clss;
};
struct assigned
{
	int id, size;
	assignInfo *courses;
	~assigned()
	{
		delete[] courses;
	}
};
struct markInfo
{
	int marks; //course marks
	int id;
	string name, code;
};
struct studentMark
{
	string rollNo;
	int cMarksize; int clss;
	markInfo *cMark; //course marks
	int total, avg; // avg is total marks divided by number of subjects
	~studentMark()
	{
		delete[] cMark;
	}
};
struct userLogin
{
	int l;
	string user, pass;
};

class FileHandling
{
	static int times;

	student *std; int stdSize;
	int *id, idSize;
	teacher *tch;  int tchSize;
	int *courseSt;
	course *crs; int crsSize;
	assigned *assign; int assSize;
	studentMark *marks; int markSize;
	int *promoteTemp, tempSize;
	virtual void func() = 0;
	void constructAssign();
	void constructMark();
	void newContructMark();
	void loadMark();
	void loadAssigned();
	void writeAssigned();
	void writeMark();
	void updateId();
	void updateTemp();
	void loadTemp();
protected:
	FileHandling();
	void loadFiles();
	void loadAll();
	void writeFiles();
	void addStudentFile(student obj);
	void updateStudent(string rollNo);
	void showClass(int n);
	void showAllSudents();
	void addTeacherFile(teacher obj);
	void updateTeacher(int x);
	void showTeacher();
	void addCourseFile(course obj);
	void showCourse();
	bool isUniqueAssign(string str);
	void assignCourseFile();
	void updateMarksAdmin(string rollNo);
	void showMarksClass(int x);
	void viewFee();
	bool matchId(userLogin &obj);
	bool matchPass(userLogin obj);
	void showMails();
	void showRolls();
	bool isUniqueEmail(string str);
	bool isUniqueCode(string str);
	void showAssignTeacher(userLogin obj);
	void updateMarkTeacher(userLogin obj);
	void viewMarksTeacher(userLogin obj);
	void viewStudentMarks(userLogin obj);
	void viewFeeStudent(userLogin obj);
	void promoteStudents();
	~FileHandling();
};
class Admin : private virtual FileHandling
{
	userLogin login;
	void func() {}
public:
	bool isLogin();
	void addStudent();
	void editStudent();
	void viewStudent();
	void viewAllStudent();
	void addTeacher();
	void editTeacher();
	void viewTeacher();
	void addCourse();
	void viewCourse();
	void assignCourse();
	void updateMarks();
	void showMarks();
	void feeStatus();
	void promotion();
	void exit();
};
class Teacher : private virtual FileHandling
{
	userLogin login;
	void func() {}
public:
	bool isLogin();
	void showCourses();
	void updateMarks();
	void viewMarks();
	void exit();
};
class Student : private virtual FileHandling
{
	userLogin login;
	void func() {}
public:
	bool isLogin();
	void viewMarks();
	void viewFee();
	void exit();
};