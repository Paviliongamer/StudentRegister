#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Kids //structure initialization
{
	string dob, dadName, momName, pnum, Fjob, Mjob, address, email, gender, name, child;
	int age{}, min{}, max{};
	double avg{};
};
int n, l, tSubject; /*global variable declaration*/
double tmarks;
//function prototype
void reg(Kids*, int&); // input function
void calc(Kids*&, int&); // calculate function
void disp1(Kids*&, int&); // display function for registration details
void disp2(Kids*&, int&); // display function for calculation results
int main() //main function
{
label: // label for jump back to the statements
	int opt; //variable opt for selection
	cout << endl;
	cout << "*************************************************************************" << endl;
	cout << "*\t*\t*\t\t\t\t\t*\t*\t*" << endl;
	cout << "*\t\t       UTeM International Playschool\t\t\t*" << endl;
	cout << "*\t*\t*\t\t\t\t\t*\t*\t*" << endl;
	cout << "*************************************************************************" << endl << endl;
	cout << "Please select one of them below :" << endl << endl; //Instructions for user
	cout << "\t1. Student Registration" << endl;
	cout << "\t2. Marks Calculation" << endl;
	cout << "\t3. Exit" << endl << endl;
	cout << "Your selection : ";
	cin >> opt; //prompt user to enter value for opt
	if (opt == 1) //code to be executed if user entered 1 for opt value
	{
		cout << endl;
		cout << "\tRegistration of International Playschool" << endl;
		cout << endl;
		cout << "\nEnter the total number of students to be registered : ";
		cin >> n; //prompt user to enter total number of students to be registered
		cout << endl;
		Kids* stud; //definition of structure pointer for stud variable
		stud = new Kids[n]; //dynamically allocated struct array declaration with array size of n(determined by user)
		reg(stud, n); //function call for function reg
		cout << "Data saved successfully !" << endl << endl;
		char g; //variable to determine whether to display entered data or not
		char c; //variable for continue to starting of the program or not
	//	2. Code
			cout << "Press 1 to view entered details or press any key to skip : " << endl;
		cin >> g; // prompt user to enter character for g
		cout << endl;
		if (g == '1') //code to be executed if user enter 1
			disp1(stud, n); //function call for function disp1
	lab1: //lab1 to jump back to the statements
		cout << endl;
		cout << "Would you like to continue(Y/N) : " << endl;
		cin >> c; //prompt user to enter character for c
		if (c == 'Y' || c == 'y') //code to be executed if user enter Y or y
			goto label; //jump to label
		else if (c == 'N' || c == 'n') //code to be executed if user enter N or n
			cout << "Thank you" << endl;
		else //code to be executed if user enter other than N,Y,n, or y
		{
			cout << "Invalid input! Please try again" << endl;
			goto lab1; //jump to lab1
		}
		delete[] stud; //deallocate the dynamic array
	}
	else if (opt == 2) //code to be executed if user entered 2 for opt value
	{
		cout << endl;
		cout << "\tMarks calculation for International Playschool students" << endl;
		cout << "\nEnter the total number of students' marks need to be calculated : ";
		cin >> l; //prompt user to enter total number of students' marks need to be calculated
		cout << endl;
		Kids* pts; //definition of structure pointer for pts variable
		pts = new Kids[l]; //dynamically allocated struct array declaration with array size of n(determined by user)
		calc(pts, l); // function call for function calc
		cout << "Marks saved successfully !" << endl;
		char h; //variable to determine whether to display entered data or not
		char r; //variable for continue to starting of the program or not
		cout << "Enter 1 to view entered details or enter any key to skip : " << endl;
		cin >> h; // prompt user to enter character for h
		cout << endl;
		if (h == '1') //code to be executed if user enter 1
			disp2(pts, l); //function call for function disp2
	lab2: //jump to lab2
		cout << endl;
		cout << "Would you like to continue(Y/N) : " << endl;
		cin >> r; //prompt user to enter character for c
		if (r == 'Y' || r == 'y') //code to be executed if user enter Y or y
			goto label; //jump to label
		else if (r == 'N' || r == 'n') //code to be executed if user enter N or n
			cout << "Thank you" << endl;
		else //code to be executed if user enter other than N,Y,n, or y
		{
			cout << "Invalid input! Please try again" << endl;
			goto lab2; // jump to lab2
		}
		delete[] pts; //deallocate the dynamic array
	}
	else if (opt == 3) //code to be executed if user entered 3 for opt value
		cout << "Thank you !";
	else //code to be executed if user entered any value except 1, 2 and 3
	{
		cout << "Invalid input. Please try again" << endl << endl;
		goto label; //jump to label
	}
	return 0;
}
void reg(Kids* s1, int& n) // function definition for function reg
{
	ofstream stuData; //stuData is an output file stream, with ofstream class
	stuData.open("Students_Reg.dat"); //Open file named "Students_Reg.dat"
	for (int i = 0; i < n; i++) { //For loop to be executed until i<n, where i declared to 0 and used for loop iteration
		cout << "\t\tStudent information" << endl << endl;
		stuData << "\t\tStudent information" << endl << endl; //data for output file
		cout << "Student name: ";
		stuData << "Student name: "; //data for output file
		//code to be executed when i=0
		//Ignore the newline, so that it didnt read second output statement without taking the first input
		if (i == 0)
			cin.ignore();
		getline(cin, s1[i].name); // input statement for string (s1[i].name) //student name
		stuData << s1[i].name << endl; //data for output file
		cout << "Student age: ";
		stuData << "Student age: "; //data for output file
		cin >> s1[i].age;
		cin.ignore();
		// input statement for string (s1[i].age) //student age
		//Ignore the newline, so that it didnt read second output statement without taking the first input
		stuData << s1[i].age << endl; //data for output file
		cout << "Student gender(M/F): ";
		stuData << "Student gender(M/F): "; //data for output file
		getline(cin, s1[i].gender); // input statement for string (s1[i].gender) //student gender
		stuData << s1[i].gender << endl; //data for output file
		cout << "Student date of birth(DD/MM/YYYY): ";
		stuData << "Student date of birth(DD/MM/YYYY): "; //data for output file
		getline(cin, s1[i].dob); // input statement for string (s1[i].dob) //student date of birth
		stuData << s1[i].dob << endl; //data for output file
		cout << "Father's name: ";
		stuData << "Father's name: "; //data for output file
		getline(cin, s1[i].dadName); // input statement for string (s1[i].dadName) //student's father's name
		stuData << s1[i].dadName << endl; //data for output file
		cout << "Mother's name: ";
		stuData << "Mother's name: ";
		getline(cin, s1[i].momName);
		//data for output file
		// input statement for string (s1[i].momName) //student's mother's name
		stuData << s1[i].momName << endl; //data for output file
		cout << "Contact number: ";
		stuData << "Contact number: "; //data for output file
		getline(cin, s1[i].pnum); // input statement for string (s1[i].pnum) //student's contact number
		stuData << s1[i].pnum << endl; //data for output file
		cout << "Father occupation: ";
		stuData << "Father occupation: "; //data for output file
		getline(cin, s1[i].Fjob); // input statement for string (s1[i].Fjob) //student's father's job
		stuData << s1[i].Fjob << endl; //data for output file
		cout << "Mother occupation: ";
		stuData << "Mother occupation: "; //data for output file
		getline(cin, s1[i].Mjob); // input statement for string (s1[i].Mjob) //student's mother's job
		stuData << s1[i].Mjob << endl; //data for output file
		cout << "House Address: ";
		stuData << "House Address: "; //data for output file
		getline(cin, s1[i].address); // input statement for string (s1[i].address) //house address
		stuData << s1[i].address << endl; //data for output file
		cout << "E-mail Address: ";
		stuData << "E-mail Address: "; //data for output file
		getline(cin, s1[i].email); // input statement for string (s1[i].email) //e-mail address
		stuData << s1[i].email << endl << endl; //data for output file
		cout << "Registration is done for " << s1[i].name << endl;
		cout << endl;
	}
	stuData.close(); // "Students_Reg.dat" file is closed
}
void calc(Kids*& s2, int& l) //function definition for function calc
{
	ofstream markS; //markS is an output file stream, with ofstream class
	markS.open("Marks_Student.dat"); //Open file named "Marks_Student.dat"
	for (int k = 0; k < l; k++) { //For loop to be executed until k<l, where k declared to 0 and used for loop iteration
		int max = 0, min = 100; //declaration and initialization of varialbe max and min
		//Ignore the newline, so that it didnt read second output statement without taking
		// the first input
		cout << "Student name :";
		getline(cin, s2[k].child); // input statement for string (s2[k].child) //student name(for marks calculaion)
		markS << "Marks calculation for "; //data for output file
		markS << s2[k].child << endl << endl; //data for output file
		cout << "Number of subjects taken: ";
		cin >> tSubject; //input statement for total subject taken
		cin.ignore();
		markS << "Number of subjects taken: "; //data for output file
		markS << tSubject << endl; //data for output file
		for (int j = 1; j <= tSubject; j++) // marks details for each student based on number of subjects taken
		{
			int marks; // marks variable for take students marks for each subject
			string stat; // stat variable for hold students marks status(Pass/Fail) for each subject
			cout << "Enter marks for each subject " << (j) << ": ";
			cin >> marks; // input statement for marks
			if (marks >= 40) //code to be executed if marks >= 40
			{
				stat = "Pass";
				cout << stat << endl; //print "Pass" if marks >=40
			}
			else // code to be executed if marks < 40
			{
				stat = "Fail";
				cout << stat << endl; //print "Fail" if marks < 40
			}
			markS << "Marks for subject " << j << ": "; //data for output file
			markS << marks << "\t" << "(" << stat << ")" << endl; //data for output file
			if (marks > max) //if statement to get the maximum mark
				max = marks;
			if (marks < min) //if statement to get the minimum mark
				min = marks;
			tmarks = tmarks + marks; //add marks to tmarks variable to get total marks for all subject for each student
		}
		s2[k].max = max; //saving maximum mark in s2[k].max structure array
		s2[k].min = min; //saving minimun mark in s2[k].min structure array
		s2[k].avg = tmarks / tSubject; // calculation of average for each student
		tmarks = 0; //reset tmarks to 0, so that the variable is ready for next student's marks calculation
		//display average, maximum and minimum marks for each student
		cout << "\nAverage marks: " << s2[k].avg << endl;
		cout << "Maximum mark: " << s2[k].max << endl;
		cout << "Minimum mark: " << s2[k].min << endl << endl;
		markS << "\nAverage marks: " << s2[k].avg << endl; //data for output file
		markS << "Maximum mark: " << s2[k].max << endl; //data for output file
		markS << "Minimum mark: " << s2[k].min << endl << endl; //data for output file
	}
	markS.close(); //"Marks_Student.dat" file is closed
}
void disp1(Kids*& s, int& n) // function definition for function disp1
{
	for (int i = 0; i < n; i++) //For loop to be executed until i<n, where i declared to 0 and used for loop iteration
	{ // display all students' registration details
		cout << "Student name: ";
		cout << s[i].name << endl;
		cout << "Student age: ";
		cout << s[i].age << endl;
		cout << "Student gender(M/F): ";
		cout << s[i].gender << endl;
		cout << "Student date of birth(DD/MM/YYYY): ";
		cout << s[i].dob << endl;
		cout << "Father's name: ";
		cout << s[i].dadName << endl;
		cout << "Mother's name: ";
		cout << s[i].momName << endl;
		cout << "Contact number: ";
		cout << s[i].pnum << endl;
		cout << "Father occupation: ";
		cout << s[i].Fjob << endl;
		cout << "Mother occupation: ";
		cout << s[i].Mjob << endl;
		cout << "House Address: ";
		cout << s[i].address << endl;
		cout << "E-mail Address: ";
		cout << s[i].email << endl << endl;
	}
}
void disp2(Kids*& s, int& l) //function definition for function disp2
{
	for (int k = 0; k < l; k++) //For loop to be executed until k < l, where k declared to 0 and used for loop iteration
	{ //display all students name corresponds for marks calculations, average, maximum and minimum marks
		cout << "Student name : ";
		cout << s[k].child << endl;
		cout << "\nAverage marks: " << s[k].avg << endl;
		cout << "Maximum mark: " << s[k].max << endl;
		cout << "Minimum mark: " << s[k].min << endl << endl;
	}
}