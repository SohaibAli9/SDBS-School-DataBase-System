//19F - 0161 Sohaib Ali
//19F - 0380 Hassan Munir


#include "Header.h"

int main()
{
	Admin admin;
	Teacher teacher;
	Student student;
	string choice; int choose; cout << left;

	//admin.addCourse();
	//admin.showMarks();

	//main menu................................
	while (true)
	{
		while (true)
		{
		mainMenu:
			system("cls");
			cout << "Press." << endl;
			cout << "1. If you are the Admin" << endl;
			cout << "2. If you are a Teacher" << endl;
			cout << "3. If you are a Student" << endl;
			cout << "4. to EXIT THE PROGRAM" << endl << endl;
			cout << "Enter: ";
			validString(choice);
			if (isInt(choice))
			{
				choose = strToInt(choice);
				if (choose > 0 && choose <= 4)
					break;
			}
			else
				cout << "Enter integer between range" << endl << endl;
		}cout << endl;
		switch (choose)
		{
		case 1:
			if (admin.isLogin())
			{
				while (true)
				{
					while (true)
					{
						system("cls");
						cout << "Press" << endl;
						cout << "1. Add new Student" << endl;
						cout << "2. Edit Student Details" << endl;
						cout << "3. Update students' Marks" << endl;
						cout << "4. View all Students" << endl;
						cout << "5. View students' Marks" << endl;
						cout << "6. View students' Fee Status" << endl;
						cout << "7. Add new Course" << endl;
						cout << "8. View all Courses" << endl;
						cout << "9. Add new Teacher" << endl;
						cout << "10. Edit Teacher Details" << endl;
						cout << "11. View all Teachers" << endl;
						cout << "12. to Assign a Course to Teacher" << endl;
						cout << "13. Promote Passing students to next class" << endl;
						cout << "14. to Go back to Main Menu" << endl;
						cout << "Enter Input: ";
						validString(choice);
						if (isInt(choice))
						{
							choose = strToInt(choice);
							if (choose > 0 && choose <= 14)
								break;
						}
						else
						{
							cout << "Enter integer between range" << endl << endl;
							cout << endl << "PRESS any key to go back to MENU" << endl;
							system("pause");
						}
					}
					switch (choose)
					{
					case 1:
						system("cls");
						admin.addStudent();
						cout << endl << "New student has been Added" << endl;
						cout << endl << "PRESS any key to go back to MENU" << endl;
						system("pause");
						break;
					case 2:
						system("cls");
						admin.editStudent();
						cout << endl << "Student has been Edited" << endl;
						cout << endl << "PRESS any key to go back to MENU" << endl;
						system("pause");
						break;
					case 3:
						system("cls");
						admin.updateMarks();
						cout << endl << "PRESS any key to go back to MENU" << endl;
						system("pause");
						break;
					case 4:
						system("cls");
						cout << "List of ALL STUDENTS" << endl << endl;
						admin.viewAllStudent();
						cout << endl << "PRESS any key to go back to MENU" << endl;
						system("pause");
						break;
					case 5:
						system("cls");
						admin.showMarks();
						cout << endl << "PRESS any key to go back to MENU" << endl;
						system("pause");
						break;
					case 6:
						system("cls");
						cout << "Students' Fee Status" << endl << endl;
						admin.feeStatus();
						cout << endl << "PRESS any key to go back to MENU" << endl;
						system("pause");
						break;
					case 7:
						system("cls");
						admin.addCourse();
						cout << endl << "New course has been Added" << endl;
						cout << endl << "PRESS any key to go back to MENU" << endl;
						system("pause");
						break;
					case 8:
						system("cls");
						admin.viewCourse();
						cout << endl << "PRESS any key to go back to MENU" << endl;
						system("pause");
						break;
					case 9:
						system("cls");
						admin.addTeacher();
						cout << endl << "New teacher has been Added" << endl;
						cout << endl << "PRESS any key to go back to MENU" << endl;
						system("pause");
						break;
					case 10:
						system("cls");
						admin.editTeacher();
						cout << endl << "Teacher has been Edited" << endl;
						cout << endl << "PRESS any key to go back to MENU" << endl;
						system("pause");
						break;
					case 11:
						system("cls");
						admin.viewTeacher();
						cout << endl << "PRESS any key to go back to MENU" << endl;
						system("pause");
						break;
					case 12:
						system("cls");
						admin.assignCourse();
						cout << endl << "PRESS any key to go back to MENU" << endl;
						system("pause");
						break;
					case 13:
						system("cls");
						admin.promotion();
						cout << endl << "PRESS any key to go back to MENU" << endl;
						system("pause");
						break;
					case 14:
						admin.exit();
						goto mainMenu;
						break;
					}
				}
			}
			break;
		case 2:
			while (true)
			{
				system("cls");
				if (teacher.isLogin())
				{
					while (true)
					{
						while (true)
						{
							system("cls");
							cout << "Press" << endl;
							cout << "1. View Courses assigned to you" << endl;
							cout << "2. Update students' Marks" << endl;
							cout << "3. View Students' Marks" << endl;
							cout << "4. to Go back to Main Menu" << endl;
							cout << "Enter Input: ";
							validString(choice);
							if (isInt(choice))
							{
								choose = strToInt(choice);
								if (choose > 0 && choose <= 4)
									break;
							}
							else
							{
								cout << "Enter integer between range" << endl << endl;
								cout << endl << "PRESS any key to go back to MENU" << endl;
								system("pause");
							}
						}
						switch (choose)
						{
						case 1:
							system("cls");
							teacher.showCourses();
							cout << endl << "PRESS any key to go back to MENU" << endl;
							system("pause");
							break;
						case 2:
							system("cls");
							teacher.updateMarks();
							cout << endl << "PRESS any key to go back to MENU" << endl;
							system("pause");
							break;
						case 3:
							system("cls");
							teacher.viewMarks();
							cout << endl << "PRESS any key to go back to MENU" << endl;
							system("pause");
							break;
						case 4:
							teacher.exit();
							goto mainMenu;
							break;
						}
					}
					break;
				}
				else
					cout << "Incorrect Email ID, TRY AGAIN" << endl << endl;
			}
			break;
		case 3:
			while (true)
			{
				system("cls");
				if (student.isLogin())
				{
					while (true)
					{
						while (true)
						{
							system("cls");
							cout << "Press" << endl;
							cout << "1. View your Marks" << endl;
							cout << "2. View your Fee Status" << endl;
							cout << "3. to Go back to Main Menu" << endl;
							cout << "Enter Input: ";
							validString(choice);
							if (isInt(choice))
							{
								choose = strToInt(choice);
								if (choose > 0 && choose <= 3)
									break;
							}
							else
							{
								cout << "Enter integer between range" << endl << endl;
								cout << endl << "PRESS any key to go back to MENU" << endl;
								system("pause");
							}
						}
						switch (choose)
						{
						case 1:
							system("cls");
							student.viewMarks();
							cout << endl << "PRESS any key to go back to MENU" << endl;
							system("pause");
							break;
						case 2:
							system("cls");
							student.viewFee();
							cout << endl << "PRESS any key to go back to MENU" << endl;
							system("pause");
							break;
						case 3:
							student.exit();
							goto mainMenu;
							break;
						}
					}
					break;
				}
				else
					cout << "Incorrect Roll No, TRY AGAIN" << endl << endl;
			}
			break;
		case 4:
			exit(0);
			break;
		}
	}

	system("pause");
	return 0;
}