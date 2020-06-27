//19F - 0161 Sohaib Ali
//19F - 0380 Hassan Munir


#include"Header.h"

ifstream fin;
ofstream fout;

int FileHandling::times = 0;

void validString(string &str)
{
	char chh;
	cin.get(chh);
	if (chh != '\n')
	{
		cin.putback(chh);
	}
	getline(cin, str);
	int len = str.length();
	for (int i = 0; i < len; ++i)
		if (str[i] == ' ')
			str[i] = '.';
}
bool isInt(string str)
{
	if (str == "-1")
		return true;
	int len = str.length();
	for (int i = 0; i < len; ++i)
		if (str[i]<'0' || str[i]>'9')
			return false;
	return true;
}
int strToInt(string str)
{
	if (str == "-1")
		return -1;
	int len = str.length(); int num = 0;
	for (int i = 0; i < len; ++i)
		num = (num * 10) + (str[i] - 48);
	return num;
}

void FileHandling::constructAssign()
{
	//.......................................... Declaring 2D distorted array for assigned courses
	assSize = tchSize;
	assign = new assigned[assSize];
	int tempo;
	for (int i = 0; i < assSize; ++i)
	{
		assign[i].id = tch[i].id;
		assign[i].size = tch[i].crass;
		tempo = tch[i].crass;
		assign[i].courses = new assignInfo[tempo];
	}
	loadAssigned();
	writeAssigned();
}
void FileHandling::constructMark()
{
	markSize = stdSize; int tempo; int k = 0;
	marks = new studentMark[markSize];
	for (int i = 0; i < markSize; ++i)
	{
		k = 0;
		marks[i].rollNo = std[i].rollNo;
		marks[i].clss = std[i].clss;//
		tempo = std[i].clss;
		tempo = courseSt[tempo - 1];
		marks[i].cMark = new markInfo[tempo];//
		marks[i].cMarksize = tempo;
		for (int j = 0; j < tempo; ++j)
		{
			marks[i].cMark[j].marks = 0;
			while (true)//
			{
				if (crs[k].clss == marks[i].clss)//
				{
					marks[i].cMark[j].code = crs[k].code;//
					marks[i].cMark[j].id = crs[k].id;//
					marks[i].cMark[j].name = crs[k].name; ++k;//
					break;//
				}++k;//
			}
		}

	}
}
void FileHandling::newContructMark()
{
	for (int i = 0; i < markSize; ++i)
	{
		
		cout << setw(12) << marks[i].rollNo;
		for (int j = 0; j < marks[i].cMarksize; ++j)
		{
			
			cout << setw(5) << marks[i].cMark[j].marks;
		}cout << endl;
	}
	system("pause");
	studentMark *temp; int tempo; int k = 0;
	temp = new studentMark[markSize];
	for (int i = 0; i < markSize; ++i)
	{
		k = 0;
		temp[i].rollNo = std[i].rollNo;
		temp[i].clss = std[i].clss;//
		tempo = std[i].clss;
		tempo = courseSt[tempo - 1];
		temp[i].cMark = new markInfo[tempo];//
		temp[i].cMarksize = tempo;
		for (int j = 0; j < tempo; ++j)
		{
			temp[i].cMark[j].marks = 0;
			while (true)
			{
				if (crs[k].clss == temp[i].clss)
				{
					temp[i].cMark[j].code = crs[k].code;
					temp[i].cMark[j].id = crs[k].id;
					temp[i].cMark[j].name = crs[k].name; ++k;
					break;
				}++k;
			}
		}
	}
	for (int i = 0; i < markSize; ++i)
		for (int j = 0; j < marks[i].cMarksize; ++j)
			temp[i].cMark[j] = marks[i].cMark[j];
	delete[] marks;
	constructMark();
	for (int i = 0; i < markSize - 1; ++i)
	{
		marks[i].rollNo = temp[i].rollNo;
		marks[i].clss = temp[i].clss;
		marks[i].cMarksize = temp[i].cMarksize;
		for (int j = 0; j < marks[i].cMarksize; ++j)
		{
			marks[i].cMark[j] = temp[i].cMark[j];
		}
	}delete[] temp;
	for (int i = 0; i < markSize; ++i)
	{

		cout << setw(12) << marks[i].rollNo;
		for (int j = 0; j < marks[i].cMarksize; ++j)
		{

			cout << setw(5) << marks[i].cMark[j].marks;
		}cout << endl;
	}
	system("pause");
	writeMark();
}
void FileHandling::loadAssigned()
{
	fin.open("assigned.txt");
	int tempo; string temp;
	for (int i = 0; i < assSize; ++i)
	{
		fin >> temp;
		tempo = tch[i].crass;
		for (int j = 0; j < tempo; ++j)
		{
			fin >> assign[i].courses[j].code;
			for (int k = 0; k < crsSize; ++k)
				if (crs[k].code == assign[i].courses[j].code)
				{
					assign[i].courses[j].clss = crs[k].clss;
					assign[i].courses[j].name = crs[k].name;
				}
		}
	}
	fin.close();
	writeAssigned();
}
void FileHandling::loadMark()
{
	fin.open("marks.txt");
	for (int i = 0; i < markSize; ++i)
	{
		fin >> marks[i].rollNo; marks[i].total = 0; marks[i].avg = 0;
		for (int j = 0; j < marks[i].cMarksize; ++j)
		{
			fin >> marks[i].cMark[j].marks;
			marks[i].total += marks[i].cMark[j].marks;
		}
		if (marks[i].cMarksize != 0)
		{
			marks[i].avg = (marks[i].total / marks[i].cMarksize);
		}
	}
	fin.close();
}
void FileHandling::writeAssigned()
{
	fout.open("assigned.txt");
	for (int i = 0; i < assSize; ++i)
	{
		fout << setw(5) << assign[i].id << ' ';
		for (int j = 0; j < tch[i].crass; ++j)
		{
			fout << setw(10) << assign[i].courses[j].code << ' ';

		}fout << endl;
	}
	fout.close();
}
void FileHandling::writeMark()
{
	fout.open("marks.txt");
	for (int i = 0; i < markSize; ++i)
	{
		fout << setw(10) << marks[i].rollNo << ' ';
		for (int j = 0; j < marks[i].cMarksize; ++j)
			fout << setw(5) << marks[i].cMark[j].marks << ' ';
		fout << endl;
	}
	fout.close();
	loadMark();
}
void FileHandling::updateId()
{
	//.......................................... Update IDs
	fout.open("ClassStren.txt");
	for (int i = 0; i < idSize; ++i)
		fout << id[i] << endl;
	fout.close();
	//.......................................... Update Courses' Strengths
	fout.open("courseId.txt");
	for (int i = 0; i < 11; ++i)
		fout << courseSt[i] << endl;
	fout.close();
}
void FileHandling::updateTemp()
{
	fout.open("temp.txt");
	for (int i = 0; i < tempSize; ++i)
		fout << promoteTemp[i] << endl;
	fout.close();
}
void FileHandling::loadTemp()
{
	fin.open("temp.txt");
	for (int i = 0; i < tempSize; ++i)
		fin >> promoteTemp[i];
	fin.close();
}

FileHandling::FileHandling()
{
	times += 1;
	//.......................................... Course strengths
	courseSt = new int[11];
	fin.open("courseId.txt");
	for (int i = 0; i < 11; ++i)
		fin >> courseSt[i];
	fin.close();
	crsSize = courseSt[10];
	//.......................................... Class Strengths
	idSize = 11;
	id = new int[idSize]; //first 10 student ids, then number of teachers
	fin.open("ClassStren.txt");
	for (int i = 0; i < idSize; ++i)
		fin >> id[i];
	fin.close();
	tchSize = id[10];
	//.......................................... Declaring array for students
	fin.open("student.txt");
	string line; stdSize = 0;
	while (!fin.eof())

		while (getline(fin, line))
			if (!fin.eof())
				stdSize++;
	fin.close();
	std = new student[stdSize];
	//.......................................... Declaring array for teachers
	tch = new teacher[tchSize];
	//.......................................... Declaring array for courses
	crs = new course[crsSize];
	//.......................................... Loading all files into arrays except id
	loadFiles();
	constructAssign();
	constructMark();
	//loadMark();
	//newContructMark();
	tempSize = idSize;
	promoteTemp = new int[tempSize];
}
FileHandling::	~FileHandling()
{
	delete[] std;
	delete[] tch;
	delete[] crs;
	delete[] id;
	delete[] courseSt;
	delete[] assign;
	delete[] marks;
	delete[] promoteTemp;
}

void FileHandling::loadFiles()
{
	//.......................................... Loading student file in array
	fin.open("Student.txt");
	for (int i = 0; i < stdSize; ++i)
	{
		fin >> std[i].rollNo;
		fin >> std[i].firstName >> std[i].lastName >> std[i].clss >> std[i].date >> std[i].gender;
		fin >> std[i].contact >> std[i].fName >> std[i].fProf >> std[i].pContact >> std[i].fee;
		fin >> std[i].bloodG >> std[i].password >> std[i].address;
	}
	fin.close();
	//.......................................... Loading teacher file in array
	fin.open("teacher.txt");
	for (int i = 0; i < tchSize; ++i)
	{
		fin >> tch[i].id >> tch[i].crass;
		fin >> tch[i].firstName >> tch[i].lastName >> tch[i].email >> tch[i].joinDate >> tch[i].pass;
		fin >> tch[i].cPass >> tch[i].cnic >> tch[i].gender >> tch[i].qual >> tch[i].contact;
		fin >> tch[i].DOB >> tch[i].address >> tch[i].salary;
	}
	fin.close();
	//.......................................... Loading course file in array
	fin.open("course.txt");
	for (int i = 0; i < crsSize; ++i)
		fin >> crs[i].clss >> crs[i].id >> crs[i].code >> crs[i].name >> crs[i].pCourse;
	fin.close();
}
void FileHandling::loadAll()
{
	//.......................................... Loading student file in array
	fin.open("Student.txt");
	for (int i = 0; i < stdSize; ++i)
	{
		fin >> std[i].rollNo;
		fin >> std[i].firstName >> std[i].lastName >> std[i].clss >> std[i].date >> std[i].gender;
		fin >> std[i].contact >> std[i].fName >> std[i].fProf >> std[i].pContact >> std[i].fee;
		fin >> std[i].bloodG >> std[i].password >> std[i].address;
	}
	fin.close();
	//.......................................... Loading teacher file in array
	fin.open("teacher.txt");
	for (int i = 0; i < tchSize; ++i)
	{
		fin >> tch[i].id >> tch[i].crass;
		fin >> tch[i].firstName >> tch[i].lastName >> tch[i].email >> tch[i].joinDate >> tch[i].pass;
		fin >> tch[i].cPass >> tch[i].cnic >> tch[i].gender >> tch[i].qual >> tch[i].contact;
		fin >> tch[i].DOB >> tch[i].address >> tch[i].salary;
	}
	fin.close();
	//.......................................... Loading course file in array
	fin.open("course.txt");
	for (int i = 0; i < crsSize; ++i)
		fin >> crs[i].clss >> crs[i].id >> crs[i].code >> crs[i].name >> crs[i].pCourse;
	fin.close();
	loadMark();
	loadAssigned();
}
void FileHandling::writeFiles()
{
	fout.open("student.txt");
	for (int i = 0; i < stdSize; ++i)// this writes all of them all over again, should not get a call from addStudentFile.
	{
		fout << setw(5) << std[i].rollNo << ' ';
		fout << setw(10) << std[i].firstName << ' ' << setw(10) << std[i].lastName << ' ' << setw(5) << std[i].clss << ' ' << setw(10) << std[i].date << ' ' << setw(10) << std[i].gender << ' ';
		fout << setw(15) << std[i].contact << ' ' << setw(10) << std[i].fName << ' ' << setw(10) << std[i].fProf << ' ' << setw(15) << std[i].pContact << ' ' << setw(5) << std[i].fee << ' ';
		fout << setw(5) << std[i].bloodG << ' ' << std[i].password << ' ' << setw(5) << std[i].address << ' ' << endl;
	}
	fout.close();
	fout.open("teacher.txt");
	for (int i = 0; i < tchSize; ++i)
	{
		fout << setw(5) << tch[i].id << ' ' << tch[i].crass << ' ';
		fout << setw(10) << tch[i].firstName << ' ' << setw(10) << tch[i].lastName << ' ' << setw(5) << tch[i].email << ' ' << setw(10) << tch[i].joinDate << ' ' << setw(10) << tch[i].pass << ' ';
		fout << setw(15) << tch[i].cPass << ' ' << setw(10) << tch[i].cnic << ' ' << setw(10) << tch[i].gender << ' ' << setw(15) << tch[i].qual << ' ' << setw(5) << tch[i].contact << ' ';
		fout << setw(5) << tch[i].DOB << ' ' << tch[i].address << ' ' << setw(5) << tch[i].salary << ' ' << /*tch[i].crass << ' ' << */endl;
	}
	fout.close();
	fout.open("course.txt");
	for (int i = 0; i < crsSize; ++i)
	{
		fout << setw(5) << crs[i].clss << ' ' << setw(5) << crs[i].id << ' ' << setw(8) << crs[i].code << ' ' << setw(12) << crs[i].name << ' ' << setw(12) << crs[i].pCourse << ' ' << endl;
	}
	fout.close();
	writeMark();
	writeAssigned();
	loadFiles();
}
bool FileHandling::matchId(userLogin &obj)
{
	for (int i = 0; i < tchSize; ++i)
		if (obj.user == tch[i].email)
		{
			obj.l = i;
			cout << endl << "Password is: " << tch[i].pass << endl;
			return true;
		}
	for (int i = 0; i < stdSize; ++i)
		if (obj.user == std[i].rollNo)
		{
			obj.l = i;
			cout << endl << "Password is: " << std[i].password << endl;
			return true;
		}
	return false;
}
bool FileHandling::matchPass(userLogin obj)
{
	if (obj.pass == tch[obj.l].pass)
		return true;
	if (obj.pass == std[obj.l].password)
		return true;
	return false;
}
bool FileHandling::isUniqueEmail(string str)
{
	for (int i = 0; i < tchSize; ++i)
		if (str == tch[i].email)
			return false;
	return true;
}
bool FileHandling::isUniqueCode(string str)
{
	for (int i = 0; i < crsSize; ++i)
		if (str == crs[i].code)
			return false;
	return true;
}
void FileHandling::addStudentFile(student obj)
{
	student *temp = new student[stdSize + 1];
	for (int i = 0; i < stdSize; ++i)
	{
		temp[i] = std[i];
	}delete[] std;
	temp[stdSize] = obj;
	++stdSize;
	std = new student[stdSize];
	for (int i = 0; i < stdSize; ++i)
	{
		std[i] = temp[i];
	}delete[] temp;

	fout.open("student.txt", ios::app);
	for (int j = 1; j <= 10; ++j)
	{
		if (std[stdSize - 1].clss == j)
		{
			fout << setw(5) << setfill('0') << ++id[j - 1];
			break;
		}
	}fout << setfill(' ') << ' ';
	fout << setw(10) << std[stdSize - 1].firstName << ' ' << setw(10) << std[stdSize - 1].lastName << ' ' << setw(5) << std[stdSize - 1].clss << ' ' << setw(10) << std[stdSize - 1].date << ' ' << setw(10) << std[stdSize - 1].gender << ' ';
	fout << setw(15) << std[stdSize - 1].contact << ' ' << setw(10) << std[stdSize - 1].fName << ' ' << setw(10) << std[stdSize - 1].fProf << ' ' << setw(15) << std[stdSize - 1].pContact << ' ' << setw(5) << std[stdSize - 1].fee << ' ';
	fout << setw(5) << std[stdSize - 1].bloodG << ' ' << std[stdSize - 1].password << ' ' << setw(5) << std[stdSize - 1].address << ' ' << endl;
	fout.close();
	updateId();
	loadFiles();
	constructMark();
	newContructMark();
}
void FileHandling::addTeacherFile(teacher obj)
{
	teacher *temp = new teacher[tchSize + 1];
	for (int i = 0; i < tchSize; ++i)
	{
		temp[i] = tch[i];
	}delete[] tch; obj.id = tchSize + 1;
	obj.crass = 0;
	temp[tchSize] = obj;
	++tchSize; ++id[10]; updateId();
	tch = new teacher[tchSize];
	for (int i = 0; i < tchSize; ++i)
	{
		tch[i] = temp[i];
	}delete[] temp;

	fout.open("teacher.txt", ios::app);
	fout << setw(5) << obj.id << ' ' << setw(5) << obj.crass << ' ';
	fout << setw(10) << obj.firstName << ' ' << setw(10) << obj.lastName << ' ' << setw(5) << obj.email << ' ' << setw(10) << obj.joinDate << ' ' << setw(10) << obj.pass << ' ';
	fout << setw(15) << obj.cPass << ' ' << setw(10) << obj.cnic << ' ' << setw(10) << obj.gender << ' ' << setw(15) << obj.qual << ' ' << setw(5) << obj.contact << ' ';
	fout << setw(5) << obj.DOB << ' ' << setw(10) << obj.address << ' ' << setw(5) << obj.salary << ' ' << /*setw(5) << obj.crass << ' ' << */endl;
	fout.close();
	fout.open("assigned.txt", ios::app);
	fout << obj.id << endl;
	fout.close();
	loadFiles();
}
void FileHandling::addCourseFile(course obj)
{
	course *temp = new course[crsSize + 1];

	for (int i = 0; i < crsSize; ++i)
		temp[i] = crs[i];
	delete[] crs;
	for (int i = 1; i <= 10; ++i)
		if (obj.clss == i)
			obj.id = ++courseSt[i - 1];
	temp[crsSize] = obj;
	++crsSize; ++courseSt[10]; updateId();
	crs = new course[crsSize];
	for (int i = 0; i < crsSize; ++i)
		crs[i] = temp[i];
	delete[] temp;

	fout.open("course.txt", ios::app);
	fout << setw(5) << obj.clss << ' ' << setw(5) << obj.id << ' ' << setw(8) << obj.code << ' ' << setw(12) << obj.name << ' ' << setw(12) << obj.pCourse << ' ' << endl;
	fout.close();
	loadFiles();
	newContructMark();
}
void FileHandling::updateStudent(string rollNo)
{
	string intInput;
	for (int i = 0; i < stdSize; ++i)
	{
		if (std[i].rollNo.compare(rollNo) == 0)
		{
			cout << "UPDATE STUDENT!!" << endl << endl;
			cout << "Enter First name of the student: ";
			validString(std[i].firstName);
			cout << "Enter Last name of the student: ";
			validString(std[i].lastName);
			while (true)
			{
				cout << "Enter student's fee status, 1 for submitted and 0 for not submitted: ";
				validString(intInput);
				if (isInt(intInput))
				{
					std[i].fee = strToInt(intInput);
					if (std[i].fee >= 0 && std[i].fee <= 1)
						break;
					else
					{
						cout << "INPUT NOT IN RANGE!! TRY AGAIN" << endl << endl;
						system("pause");
					}
				}
				else
				{
					cout << "Enter Integer between 0 and 1" << endl << endl;
					system("pause");
				}
			}
			cout << "Enter student's Address: ";
			validString(std[i].address);
			cout << "Enter student's contact number: ";
			validString(std[i].contact);
			writeFiles();
			return;
		}
	}
	cout << "Roll No. Does not match!!" << endl;
}
void FileHandling::updateTeacher(int x)
{
	if (x > 0 && x <= tchSize)
	{
		cout << "Enter new Address for Teacher: ";
		validString(tch[x - 1].address);
		cout << "Enter new Contact No. for Teacher: ";
		validString(tch[x - 1].address);
		cout << "Enter new Qualification for Teacher: ";
		validString(tch[x - 1].qual);
		cout << "Enter new Salary for Teacher: ";
		validString(tch[x - 1].salary);
		writeFiles();
	}
	else
	{
		cout << endl << "Input out of range, sorry" << endl << endl;
		system("pause");
	}
	return;
}
void FileHandling::updateMarksAdmin(string rollNo)
{
	int clss = 0, id, mark; string intInput;
	for (int i = 0; i < stdSize; ++i)
	{

		if (rollNo == std[i].rollNo)
		{
			clss = std[i].clss;
			break;
		}
	}
	if (clss == 0)
	{
		cout << "Wrong Roll Input" << endl;
		return;
	}
	while (true)
	{
		for (int i = 0; i < crsSize; ++i)
			if (clss == crs[i].clss)
			{
				cout << left << setw(5) << crs[i].id;
				cout << setw(10) << crs[i].code << setw(20) << crs[i].name << endl;
			}
		cout << endl << "Enter ID of course you want to update marks of: ";
		validString(intInput);
		if (isInt(intInput))
		{
			id = strToInt(intInput);
			if (id > 0 && id <= crsSize)
				break;
			else
			{
				cout << "INPUT NOT IN RANGE!! TRY AGAIN" << endl << endl;
				system("pause");
			}
		}
		else
		{
			cout << "Enter an INTEGER" << endl << endl;
			system("pause");
		}
	}
	while (true)
	{
		cout << "Enter Marks: ";
		validString(intInput);
		if (isInt(intInput))
		{
			mark = strToInt(intInput);
			break;
		}
		else
		{
			cout << "Enter an INTEGER" << endl << endl;
			system("pause");
		}
	}
	for (int i = 0; i < markSize; ++i)
		if (rollNo == marks[i].rollNo)
			marks[i].cMark[id - 1].marks = mark;
	writeMark();
	cout << endl << "Student's marks have been Updated" << endl;
}
void FileHandling::updateMarkTeacher(userLogin obj)
{
	bool out = true; int markss;
	string code; int clss; string rollNo, intInput;
	while (out)
	{
		showAssignTeacher(obj);
		cout << "Enter CODE of course you want to change marks for: ";
		validString(code);
		for (int i = 0; i < crsSize; ++i)
			if (code == crs[i].code)
			{
				clss = crs[i].clss; out = false;
				break;
			}
		if (out)
		{
			cout << "Wrong CODE Input, TRY AGAIN" << endl << endl;
			system("pause");
		}
	}
	cout << endl;
	showClass(clss);
	cout << "Enter Roll No. of student you want to change marks of: ";
	validString(rollNo); out = true;
	while (out)
	{
		for (int i = 0; i < markSize; ++i)
		{
			if (rollNo == marks[i].rollNo)
			{
				for (int j = 0; j < marks[i].cMarksize; ++j)
					if (code == marks[i].cMark[j].code)
					{
						while (true)
						{
							cout << "Enter Marks: ";
							validString(intInput);
							if (isInt(intInput))
							{
								markss = strToInt(intInput);
								break;
							}
							else
								cout << "Enter an INTEGER" << endl << endl;
						}
						marks[i].cMark[j].marks = markss;
						break;
					}
				writeMark();
				cout << "Marks have been updated successfully" << endl;
				out = false;
				break;
			}
		}
		if (out)
		{
			cout << "Wrong input for Roll no, sorry TRY AGAIN" << endl << endl;
			system("pause");
		}
	}
}
void FileHandling::assignCourseFile()
{
	int x, y; string code; bool good = true; string intInput;

	while (true)
	{
		showTeacher();
		cout << "Enter id of teacher you want to assign course to: ";
		validString(intInput);
		if (isInt(intInput))
		{
			x = strToInt(intInput);
			if (x > 0 && x <= tchSize)
				break;
			else
			{
				cout << "INPUT NOT IN RANGE!! TRY AGAIN" << endl << endl;
				system("pause");
			}
		}
		else
		{
			cout << "Enter an INTEGER" << endl << endl;
			system("pause");
		}
	}
	cout << endl;
	while (true)
	{
		while (true)
		{
			showCourse();
			cout << "Enter id of course you want to assign: ";
			validString(intInput);
			if (isInt(intInput))
			{
				y = strToInt(intInput);
				if ((y > 0 && y <= crsSize) || y == -1)
					break;
				else
				{
					cout << "INPUT NOT IN RANGE!! TRY AGAIN" << endl << endl;
					system("pause");
				}
			}
			else
			{
				cout << "Enter an INTEGER" << endl << endl;
				system("pause");
			}
		}
		if (y == -1)
		{
			good = false;
			break;
		}
		code = crs[y - 1].code;
		if (isUniqueAssign(code))
		{
			system("pause");
			break;
		}
		else
		{
			cout << endl << "This course is already ASSIGNED, TRY AGAIN or Enter -1 to exit" << endl << endl;
			system("pause");
		}
	}
	if (good == true)
	{

		int size = tch[x - 1].crass;

		assignInfo *temp = new assignInfo[size + 1];

		for (int i = 0; i < size; ++i)
		{
			temp[i] = assign[x - 1].courses[i];
		}//delete[] assign[x - 1].courses;

		temp[size].code = crs[y - 1].code;
		temp[size].clss = crs[y - 1].clss;
		temp[size].name = crs[y - 1].name;


		++size;	++tch[x - 1].crass;

		assign[x - 1].courses = new assignInfo[size];

		for (int i = 0; i < size; ++i)
		{
			assign[x - 1].courses[i] = temp[i];
		}delete[] temp;

		writeFiles();
		cout << endl << "Course has been Assigned Sucessfully" << endl;
	}
}
void FileHandling::showAllSudents()
{
	cout << left << setw(12) << "Roll No." << setw(20) << "Name" << setw(12) << "Class" << setw(12) << "Email" << endl;
	for (int i = 0; i < stdSize; ++i)
		cout << left << setw(12) << std[i].rollNo << setw(20) << std[i].firstName + " " + std[i].lastName << setw(12) << std[i].clss << setw(12) << std[i].rollNo + "@email.com" << endl;
	cout << endl;
}
void FileHandling::showMarksClass(int x)
{
	cout << left << endl << setw(15) << "Roll No. ";
	for (int i = 0; i < markSize; ++i)
		if (marks[i].clss == x)
		{
			for (int j = 0; j < marks[i].cMarksize; ++j)
				cout << setw(20) << marks[i].cMark[j].name + " " + marks[i].cMark[j].code;
			cout << setw(15) << "Total Marks" << endl;
			break;
		}
	for (int i = 0; i < markSize; ++i)
		if (marks[i].clss == x)
		{
			cout << setw(15) << marks[i].rollNo;
			for (int j = 0; j < marks[i].cMarksize; ++j)
				cout << setw(20) << marks[i].cMark[j].marks;
			cout << setw(15) << marks[i].total << endl;
		}cout << endl;
}
void FileHandling::viewFee()
{
	cout << left << setw(10) << "Roll No. " << setw(20) << "Name" << setw(10) << "Status" << endl << endl;
	for (int i = 0; i < stdSize; ++i)
	{
		cout << setw(10) << std[i].rollNo << setw(20) << std[i].firstName + " " + std[i].lastName;
		if (std[i].fee == 0)
			cout << setw(10) << "Not Submitted" << endl;
		else
			cout << setw(10) << "Submitted" << endl;
	}cout << endl;
}
void FileHandling::showTeacher()
{
	cout << "List of All Teachers" << endl << endl;
	cout << left << setw(5) << "ID" << setw(22) << "Name" << setw(12) << "Gender";
	cout << setw(12) << "Contact" << setw(12) << "Email" << endl;
	for (int i = 0; i < tchSize; ++i)
	{
		cout << left << setw(5) << tch[i].id << setw(22) << tch[i].firstName + " " + tch[i].lastName << setw(12) << tch[i].gender;
		cout << setw(12) << tch[i].contact << setw(12) << tch[i].email << endl;
	}cout << endl;
}
void FileHandling::showAssignTeacher(userLogin obj)
{
	cout << "List of Assigned Courses" << endl << endl;
	int size = assign[obj.l].size; cout << left;
	cout << "Teacher's NAME: " << tch[obj.l].firstName + " " + tch[obj.l].lastName << endl << endl;
	cout << right; cout << setw(23) << "ASSIGNED COURSES"; cout << left << endl << endl;
	cout << setw(12) << "Name" << setw(12) << "Code" << setw(12) << "Class" << endl;
	for (int i = 0; i < size; ++i)
		cout << setw(12) << assign[obj.l].courses[i].name << setw(12) << assign[obj.l].courses[i].code << setw(12) << assign[obj.l].courses[i].clss << endl;
	cout << endl << endl;
}
void FileHandling::showCourse()
{
	cout << "List of all Courses" << endl << endl;
	cout << left << setw(5) << "ID" << setw(8) << "Code" << setw(28) << "Name" << setw(20) << "Parent Name" << setw(5) << "Class" << endl;
	for (int i = 0; i < crsSize; ++i)
		cout << left << setw(5) << i + 1 << setw(8) << crs[i].code << setw(28) << crs[i].name << setw(20) << crs[i].pCourse << setw(5) << crs[i].clss << endl;
	cout << endl;
}
void FileHandling::showClass(int n)
{
	if (n > 0 && n <= 10)
	{
		cout << left << setw(12) << "Roll No." << setw(20) << "Name" << setw(12) << "Class" << setw(12) << "Email" << endl;
		for (int i = 0; i < stdSize; ++i)
			if (std[i].clss == n)
				cout << left << setw(12) << std[i].rollNo << setw(20) << std[i].firstName + " " + std[i].lastName << setw(12) << std[i].clss << setw(12) << std[i].rollNo + "@email.com" << endl;
		cout << endl;
	}
}
void FileHandling::showMails()
{
	for (int i = 0; i < tchSize; ++i)
		cout << "Emails: " << tch[i].email << endl;
}
void FileHandling::showRolls()
{
	for (int i = 0; i < stdSize; ++i)
		cout << "Roll No: " << std[i].rollNo << endl;
}
void FileHandling::viewMarksTeacher(userLogin obj)
{
	int clss; string code, name; bool out = true;
	while (out)
	{
		showAssignTeacher(obj);
		cout << "Enter CODE of course you want to view marks for: ";
		validString(code);
		for (int i = 0; i < crsSize; ++i)
			if (code == crs[i].code)
			{
				clss = crs[i].clss;
				name = crs[i].name;
				out = false;
				break;
			}
		if (out)
		{
			cout << "Wrong CODE Input, TRY AGAIN" << endl << endl;
			system("pause");
		}
	}
	system("cls");
	cout << "List of Students' Marks for " << name << " course" << endl << endl;
	cout << setw(12) << "Roll No. " << setw(12) << "Marks" << endl;
	for (int i = 0; i < markSize; ++i)
		if (clss == marks[i].clss)
			for (int j = 0; j < marks[i].cMarksize; ++j)
				if (code == marks[i].cMark[j].code)
					cout << setw(12) << marks[i].rollNo << setw(12) << marks[i].cMark[j].marks << endl;
}
void FileHandling::viewStudentMarks(userLogin obj)
{
	cout << "Marks of Roll No: " << obj.user << endl << endl << left;
	for (int i = 0; i < markSize; ++i)
		if (obj.user == marks[i].rollNo)
		{
			for (int j = 0; j < marks[i].cMarksize; ++j)
				cout << setw(16) << marks[i].cMark[j].name;
			cout << setw(16) << "Total" << endl;
			break;
		}
	for (int i = 0; i < markSize; ++i)
		if (obj.user == marks[i].rollNo)
		{
			for (int j = 0; j < marks[i].cMarksize; ++j)
				cout << setw(16) << marks[i].cMark[j].marks;
			cout << setw(16) << marks[i].total << endl;
			break;
		}cout << endl;
}
bool FileHandling::isUniqueAssign(string str)
{
	for (int i = 0; i < assSize; ++i)
		for (int j = 0; j < assign[i].size; ++j)
			if (assign[i].courses[j].code == str)
				return false;
	return true;
}
void FileHandling::viewFeeStudent(userLogin obj)
{
	cout << "Fee status of Roll No: " << obj.user << endl << endl;
	for (int i = 0; i < stdSize; ++i)
		if (obj.user == std[i].rollNo)
			if (std[i].fee == 0)
				cout << "Fee Not Submitted" << endl;
			else
				cout << "Fee is Submitted" << endl;
}
void FileHandling::promoteStudents()
{
	student tempStd;
	loadFiles();// as a safety measure
	fout.open("student.txt");
	fout.close(); // to clear all previous students
	//making temp file of classStren original roll ids
	fout.open("temp.txt");
	fout << right;
	for (int i = 1; i <= 10; ++i)
	{
		fout << setfill('0') << setw(5) << i * 1000 << endl;
	}fout << tchSize << setfill(' ') << endl;
	fout.close();
	loadTemp(); updateTemp();
	for (int i = 0; i < tempSize; ++i)
		cout << promoteTemp[i] << " ";
	cout << endl;

	int newSize = stdSize; int clsss = 0;
	for (int i = 0; i < stdSize; ++i)
	{
		tempStd = std[i];
		if (marks[i].avg >= 50)
		{
			++tempStd.clss;
			clsss = tempStd.clss - 1;
			if (tempStd.clss < 11)
			{
				tempStd.rollNo = to_string(++promoteTemp[clsss]);
				updateTemp();
				fout.open("student.txt", ios::app);
				fout << setfill('0');
				fout << setw(5) << tempStd.rollNo << ' ' << setfill(' ');
				fout << setw(10) << tempStd.firstName << ' ' << setw(10) << tempStd.lastName << ' ' << setw(5) << tempStd.clss << ' ' << setw(10) << tempStd.date << ' ' << setw(10) << tempStd.gender << ' ';
				fout << setw(15) << tempStd.contact << ' ' << setw(10) << tempStd.fName << ' ' << setw(10) << tempStd.fProf << ' ' << setw(15) << tempStd.pContact << ' ' << setw(5) << tempStd.fee << ' ';
				fout << setw(5) << tempStd.bloodG << ' ' << tempStd.password << ' ' << setw(5) << tempStd.address << ' ' << endl;
				fout.close();
			}
			else
				--newSize; // students who passed and left school
		}
		else
		{
			tempStd.rollNo = to_string(++promoteTemp[clsss]);
			updateTemp();
			fout.open("student.txt", ios::app);
			fout << setfill('0');
			fout << setw(5) << tempStd.rollNo << ' ' << setfill(' ');
			fout << setw(10) << tempStd.firstName << ' ' << setw(10) << tempStd.lastName << ' ' << setw(5) << tempStd.clss << ' ' << setw(10) << tempStd.date << ' ' << setw(10) << tempStd.gender << ' ';
			fout << setw(15) << tempStd.contact << ' ' << setw(10) << tempStd.fName << ' ' << setw(10) << tempStd.fProf << ' ' << setw(15) << tempStd.pContact << ' ' << setw(5) << tempStd.fee << ' ';
			fout << setw(5) << tempStd.bloodG << ' ' << tempStd.password << ' ' << setw(5) << tempStd.address << ' ' << endl;
			fout.close();
		}
	}
	for (int i = 0; i < idSize; ++i)
		id[i] = promoteTemp[i];
	stdSize = newSize;
	updateId();// updating new student strengths in file
	delete[] std;// the new size of array may be different, deleting old array instead of overwriting
	std = new student[stdSize];
	loadFiles();// loading new students
	delete[] marks;// erasing all old marks and adding new as zero
	constructMark();
	writeMark();

	cout << "All Students have been promoted" << endl;
}

bool Admin::isLogin()
{
	while (true)
	{
		cout << "Username is: admin" << endl;
		cout << "Enter Username: ";
		validString(login.user);
		if (login.user == "admin")
			break;
		else if (login.user == "0")
			return false;
		else
		{
			cout << "Wrong input, TRY AGAIN or Enter 0 to exit" << endl;
			system("pause");
		}
	}cout << endl;
	while (true)
	{
		cout << "Password is: admin" << endl;
		cout << "Enter Password: ";
		validString(login.pass);
		if (login.pass == "admin")
		{
			loadAll();
			return true;
		}
		else if (login.pass == "0")
			return false;
		else
		{
			cout << "Wrong input, TRY AGAIN or Enter 0 to exit" << endl;
			system("pause");
		}
	}
	return false;
}
void Admin::addStudent()
{
	student stdt; string intInput;

	cout << "Enter First name of the student: ";
	validString(stdt.firstName);
	cout << "Enter Last name of the student: ";
	validString(stdt.lastName);
	while (true)
	{
		cout << "Enter Class of the student as 01, 02...: ";
		validString(intInput);
		if (isInt(intInput))
		{
			stdt.clss = strToInt(intInput);
			if (stdt.clss > 0 && stdt.clss <= 10)
				break;
			else
			{
				cout << "INPUT NOT IN RANGE!! TRY AGAIN" << endl << endl;
				system("pause");
			}
		}
		else
		{
			cout << "Enter Integer between 1 and 10" << endl << endl;
			system("pause");
		}
	}
	cout << "Enter student's registeration date: ";
	validString(stdt.date);
	cout << "Enter student's Gender: ";
	validString(stdt.gender);
	cout << "Enter student's contact number: ";
	validString(stdt.contact);
	cout << "Enter student's Father's name: ";
	validString(stdt.fName);
	cout << "Enter student's Father's profession: ";
	validString(stdt.fProf);
	cout << "Enter student's parent's contact No: ";
	validString(stdt.pContact);
	while (true)
	{
		cout << "Enter student's fee status, 1 for submitted and 0 for not submitted: ";
		validString(intInput);
		if (isInt(intInput))
		{
			stdt.fee = strToInt(intInput);
			if (stdt.fee >= 0 && stdt.fee <= 1)
				break;
			else
			{
				cout << "INPUT NOT IN RANGE!! TRY AGAIN" << endl << endl;
				system("pause");
			}
		}
		else
		{
			cout << "Enter Integer between 0 and 1" << endl << endl;
			system("pause");
		}
	}
	cout << "Enter student's Blood Group: ";
	validString(stdt.bloodG);
	cout << "Enter student's Address: ";
	validString(stdt.address);
	cout << "Enter the password which the student shall use: ";
	validString(stdt.password);

	addStudentFile(stdt);
}
void Admin::editStudent()
{
	int x; string intInput;
	while (true)
	{
		cout << "Enter Class of the student as 01, 02...: ";
		validString(intInput);
		if (isInt(intInput))
		{
			x = strToInt(intInput);
			if (x > 0 && x <= 10)
				break;
			else
			{
				cout << "INPUT NOT IN RANGE!! TRY AGAIN" << endl << endl;
				system("pause");
			}
		}
		else
		{
			cout << "Enter Integer between 1 and 10" << endl << endl;
			system("pause");
		}
	}
	showClass(x); string str;
	cout << endl << "Enter Roll No. of the student you want to edit: ";
	validString(str);
	updateStudent(str);
}
void Admin::viewStudent()
{
	int x; string intInput;
	while (true)
	{
		cout << "Enter Class of the student as 01, 02...: ";
		validString(intInput);
		if (isInt(intInput))
		{
			x = strToInt(intInput);
			if (x > 0 && x <= 10)
				break;
			else
			{
				cout << "INPUT NOT IN RANGE!! TRY AGAIN" << endl << endl;
				system("pause");
			}
		}
		else
		{
			cout << "Enter Integer between 1 and 10" << endl << endl;
			system("pause");
		}
	}
	showClass(x);
}
void Admin::viewAllStudent()
{
	showAllSudents();
}
void Admin::addTeacher()
{
	teacher temp;

	cout << "Enter Techer's First name: ";
	validString(temp.firstName);
	cout << "Enter Techer's Last name: ";
	validString(temp.lastName);
	while (true)
	{
		cout << "You will use this Email for login..." << endl;
		cout << "Enter Techer's Email: ";
		validString(temp.email);
		if (isUniqueEmail(temp.email))
			break;
		else
		{
			cout << "EMAIL IS ALREADY TAKEN, TRY AGAIN!!" << endl << endl;
			system("pause");
		}
	}
	cout << "Enter Techer's Joining Date: ";
	validString(temp.joinDate);
	while (true)
	{
		cout << "Enter Techer's Password: ";
		validString(temp.pass);
		cout << "Enter Techer's Confirm Password: ";
		validString(temp.cPass);
		if (temp.pass == temp.cPass)
			break;
		else
		{
			cout << "BOTH PASSWORDS DONT MATCH, TRY AGAIN!!" << endl << endl;
			system("pause");
		}
	}
	cout << "Enter Techer's CNIC: ";
	validString(temp.cnic);
	cout << "Enter Techer's Gender: ";
	validString(temp.gender);
	cout << "Enter Techer's Qualification: ";
	validString(temp.qual);
	cout << "Enter Techer's Contact No.: ";
	validString(temp.contact);
	cout << "Enter Techer's Date of Birth: ";
	validString(temp.DOB);
	cout << "Enter Techer's Address: ";
	validString(temp.address);
	cout << "Enter Techer's Salary: ";
	validString(temp.salary);

	addTeacherFile(temp);
}
void Admin::editTeacher()
{
	int x; string intInput;
	showTeacher();
	while (true)
	{
		showTeacher();
		cout << "Enter id number of Teacher you want to edit: ";
		validString(intInput);
		if (isInt(intInput))
		{
			x = strToInt(intInput);
			break;
		}
		else
		{
			cout << "Enter an INTEGER" << endl << endl;
			system("pause");
		}
	}
	updateTeacher(x);
}
void Admin::viewTeacher()
{
	showTeacher();
}
void Admin::addCourse()
{
	course temp; string intInput;
	while (true)
	{
		cout << "Enter Class to add Course as 01, 02...: ";
		validString(intInput);
		if (isInt(intInput))
		{
			temp.clss = strToInt(intInput);
			if (temp.clss > 0 && temp.clss <= 10)
				break;
			else
			{
				cout << "INPUT NOT IN RANGE!! TRY AGAIN" << endl << endl;
				system("pause");
			}
		}
		else
		{
			cout << "Enter Integer between 1 and 10" << endl << endl;
			system("pause");
		}
	}
	cout << "Enter parent Course Name: ";
	validString(temp.pCourse);
	cout << "Enter Name of the Course: ";
	validString(temp.name);
	while (true)
	{
		cout << "Enter Course Code: ";
		validString(temp.code);
		if (isUniqueCode(temp.code))
			break;
		else
		{
			cout << "CODE IS ALREADY REGISTERED, TRY AGAIN!!" << endl << endl;
			system("pause");
		}
	}
	addCourseFile(temp);
}
void Admin::viewCourse()
{
	showCourse();
}
void Admin::assignCourse()
{
	assignCourseFile();
}
void Admin::updateMarks()
{
	int x; string intInput;
	while (true)
	{
		cout << "Enter Class of the student as 01, 02...: ";
		validString(intInput);
		if (isInt(intInput))
		{
			x = strToInt(intInput);
			if (x > 0 && x <= 10)
				break;
			else
			{
				cout << "INPUT NOT IN RANGE!! TRY AGAIN" << endl << endl;
				system("pause");
			}
		}
		else
		{
			cout << "Enter Integer between 1 and 10" << endl << endl;
			system("pause");
		}
	}
	showMarksClass(x); cout << endl; string str;
	cout << endl << "Enter Roll No. of the student you want to edit: ";
	validString(str);
	updateMarksAdmin(str);
}
void Admin::showMarks()
{
	int x; string intInput;
	cout << "To View Marks" << endl << endl;
	while (true)
	{
		cout << "Enter Class of the student as 01, 02...: ";
		validString(intInput);
		if (isInt(intInput))
		{
			x = strToInt(intInput);
			if (x > 0 && x <= 10)
				break;
			else
			{
				cout << "INPUT NOT IN RANGE!! TRY AGAIN" << endl << endl;
				system("pause");
			}
		}
		else
		{
			cout << "Enter Integer between 1 and 10" << endl << endl;
			system("pause");
		}
	}
	system("cls");
	cout << "Marks of Students" << endl << endl;
	showMarksClass(x);
}
void Admin::feeStatus()
{
	viewFee();
}
void Admin::promotion()
{
	promoteStudents();
}
void Admin::exit()
{
	writeFiles();
}

bool Teacher::isLogin()
{
	cout << "List of all Emails" << endl << endl;
	showMails(); cout << endl;
	cout << "Enter Your Email: ";
	validString(login.user);
	while (true)
		if (matchId(login))
		{
			cout << "Enter Password: ";
			validString(login.pass);
			if (matchPass(login))
			{
				loadAll();
				return true;
			}
			else
				cout << "Wrong Password, TRY AGAIN" << endl << endl;
		}
		else
			return false;
}
void Teacher::showCourses()
{
	showAssignTeacher(login);
}
void Teacher::updateMarks()
{
	updateMarkTeacher(login);
}
void Teacher::viewMarks()
{
	viewMarksTeacher(login);
}
void Teacher::exit()
{
	writeFiles();
}

bool Student::isLogin()
{
	cout << "LIST OF ALL ROLL NUMBERS: " << endl << endl;
	showRolls(); cout << endl;
	cout << "Enter your Roll No: ";
	validString(login.user);
	while (true)
		if (matchId(login))
		{
			cout << endl << "Enter Password: ";
			validString(login.pass);
			if (matchPass(login))
			{
				loadAll();
				return true;
			}
			else
				cout << "Wrong Password, TRY AGAIN" << endl << endl;
		}
		else
			return false;
}
void Student::viewMarks()
{
	viewStudentMarks(login);
}
void Student::viewFee()
{
	viewFeeStudent(login);
}
void Student::exit()
{
	writeFiles();
}