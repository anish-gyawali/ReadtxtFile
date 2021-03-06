/*
Name: Anish Gyawali
Lab: Chapter 5

Description: Program that reads student record from a inputfile(ch5input.txt) and process to caluclate the average of each student grade with letter
grade to display a formatted grade report. This program also print the final class average along with exam 1, exam 2, and exam 3 average.
Also, it prints high test grade and low test grade. 

Algorithm:

i. Make sure to include appropriate preprocessor directives to be able to use file I/O, string, setw, setprecision...
ii. Defineappropriate variables and CONSTANTS: firstName, lastName, exam1, exam2, exam3, averageGrade, letterGrade, NUM_TESTS, etc.
iii. Define and open an ifstreaminputFile object to be able to read data from the input file ch5input.txt*
iv. Print out headings for the grade report using setw().
v. Now, within a while loop: while (!inputFile.eof()), read FIVE items (First name,Lastname, Exam 1, Exam 2, and Exam 3) from the input file ch5input.txt*.
vi. Next, calculate the student’s Averagegrade using the three examgrades that just read in.
vii. Then, assign a Lettergrade to each student based on the Average grade calculated.
viii. Then, finish the output line for the current record properly formatted.
*/

#include<iostream>
#include <istream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
	string firstName, lastName;
	double Exam1, Exam2, Exam3;
	double Average,finalAvg;
	char letterGrade;
	int count = 0;
	double highest = 0, lowest = 100, ex1 = 0, ex2 = 0, ex3 = 0, AvgEx1, AvgEx2, AvgEx3;

	ifstream inputFile;
	inputFile.open("ch5input.txt");

	cout << setw(20) << "Name" << setw(15) << "Exam-1" << setw(15) << "Exam-2" << setw(15) << "Exam-3" << setw(15) << "Average" << setw(15) << "letter" << endl;
	cout << "---------------------------------------------------------------------------------------------------------\n";


	while (!inputFile.eof())

	{
		count++;
		inputFile >> firstName >> lastName >> Exam1 >> Exam2 >> Exam3;

		if (Exam1 > highest)
			highest = Exam1;
		if (Exam3 > highest)
			highest = Exam2;
		if (Exam3 > highest)
			highest = Exam3;

		if (Exam1 < lowest)
			lowest = Exam1;
		if (Exam2 < lowest)
			lowest = Exam2;
		if (Exam2 < lowest)
			lowest = Exam2;

		ex1 = ex1 + Exam1;
		ex2 = ex2 + Exam2;
		ex3 = ex3 + Exam3;

		Average = (Exam1 + Exam2 + Exam3) / 3;


		if (Average >= 90) {
			letterGrade = 'A';
		}
		else if (Average >= 79) {
			letterGrade = 'B';
		}
		else if (Average >= 69) {
			letterGrade = 'C';
		}
		else if (Average >= 59) {
			letterGrade = 'D';
		}
		else
			letterGrade = 'F';


		cout << fixed << setprecision(2) << setw(10) << firstName << setw(10) << lastName << setw(15) << Exam1 << setw(15) << Exam2 << setw(15) << Exam3 << setw(15) << Average << setw(15) << letterGrade << endl;


	}
	cout << "---------------------------------------------------------------------------------------------------------\n";

	AvgEx1 = ex1 / count;
	AvgEx2 = ex2 / count;
	AvgEx3 = ex3 / count;

	finalAvg = (AvgEx1 + AvgEx2 + AvgEx3) / 3;
	cout << "Final Class Average:" <<setw(60)<< finalAvg << endl;
	cout << "---------------------------------------------------------------------------------------------------------\n";

	cout << "High Test Grade: " << highest << endl;
	cout << "Low Test Grade: " << lowest << endl;

	cout << "Exam-1 Average: " << AvgEx1 << endl;
	cout << "Exam-2 Average: " << AvgEx2 << endl;
	cout << "Exam-3 Average: " << AvgEx3 << endl;

	inputFile.close();

	system("pause");
	return 0;
}
