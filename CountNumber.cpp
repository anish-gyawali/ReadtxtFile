#include<iostream>
#include<string>
using namespace std;

const int SIZE = 7;
const int PASS_LIMIT = 60;
void getQuizScore(int[]);
int returnFailCount(int[]);
void displayMessage(int);


int main()
{
	int quizArray[SIZE];
	int failCount;
	getQuizScore(quizArray);
	failCount = returnFailCount(quizArray);
	displayMessage(failCount);
	system("pause");
	return 0;
}
void getQuizScore(int array[])
{

	int i;

	cout << "Enter 7 Quiz score : ";
	for (i = 0; i < SIZE; i++)

		cin >> array[i];

}
int returnFailCount(int score[])
{
	int i, countF = 0;
	double sum = 0;
	double average = 0;
	for (i = 0; i < SIZE; ++i)

		if (score[i] < PASS_LIMIT)

		{
			sum += score[i];
			countF++;
		}

	average = sum / SIZE;
	cout << "Your quiz average is " << average << endl;

	return (countF);
}

void displayMessage(int fail)
{

	if (fail == 0)
		cout << "Congratulations! you passed all 7 quizzes\n ";
	else if (fail == 1)
		cout << "You failed in " << fail << " quiz\n";
	else
		cout << "You failed in " << fail << " quiz(zes)\n";
}
