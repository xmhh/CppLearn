// gen2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <ctime>
const int SIZE = 60;
void c6_15(void) {
	char automobile[50];
	int year;
	double a_price;
	double d_price;
	ofstream outFile;
	outFile.open("carinfo.txt");

	cout << "Please the brand and model of the car:\n";
	cin.getline(automobile, 50);
	cout << "Enter the model year:\n";
	cin >> year;
	cout << "Enter the original asking price:\n";
	cin >> a_price;
	d_price = 0.9*a_price;

	//	display the information on the screen
	cout << fixed;
	cout.precision(3);
	cout.setf(ios_base::showpoint);
	cout << "Make and Model:\t" << automobile << endl;
	cout << "Year:\t" << year << endl;
	cout << "Was asking $" << a_price << endl;
	cout << "Now asking $" << d_price << endl;

	//  now do the same thing using outFile instead of cout
	outFile << fixed;
	outFile.precision(3);
	outFile.setf(ios_base::showpoint);
	outFile << "Make and Model:\t" << automobile << endl;
	outFile << "Year:\t" << year << endl;
	outFile << "Was asking $" << a_price << endl;
	outFile << "Now asking $" << d_price << endl;
	outFile.close();
}

void c6_16(void) {
	char filename[SIZE];
	ifstream inFile;
	cout << "Enter name of the data file:\n";
	cin.getline(filename,SIZE);
	inFile.open(filename);
	if (!inFile.is_open()) {
		cout << "Failed to open the data file\n";
		cout << "Program terminating\n";
		exit(EXIT_FAILURE);
	}
	double value;
	double sum = 0.0;
	int count = 0;

	inFile >> value;
	while (inFile.good()) {
		++count;
		sum += value;
		inFile >> value;
	}
	if (inFile.eof())
		cout << "End of File reached!\n";
	else if (inFile.fail())
		cout << "Input terminated for unknown reason.\n ";
	if (count == 0)
		cout << "No data processed.\n";
	else {
		cout << "Items read: " << count << endl;
		cout << "Sum: " << sum << endl;
		cout << "Average: " << sum / count << endl;
	}
	inFile.close();
}
void chapter6(void)
{	
	/*
	ofstream outFile;
	ofstream fout;
	outFile.open("fish.txt");
	char filename[50];
	cin.getline(filename,50);
	fout.open(filename);
	clock_t currt = clock();
	for (int i = 0; i < 4; i++) {
		fout << currt / (CLOCKS_PER_SEC);
	}
	double wt = 125.4;
	fout << wt << endl;
	char line[81] = "Objects are closer than they appear.";
	fout << line << endl;
	*/
	//c6_15();
	c6_16();

}

