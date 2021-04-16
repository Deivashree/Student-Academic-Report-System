#include<fstream>
#include<iostream>
#include<istream>
#include<ostream>
#include<sstream>
#include<iomanip>
#include<vector>
#include<string>
#include<cmath> 

#include"fileOpen.h"
#include"calculation.h"
#include"compare.h"
#include"menu.h"
#include"export.h"

using namespace std;

int main(){ 

	vector <vector<double>> studData;
	vector <string> headernames;
	int columnNum;
	int rowNum;

	// welcome message for the user
	cout << "Welcome to Student Academic Report System" << endl;
	cout << "=========================================" << endl;

	cout << "Please press enter to proceed." ;
 	cin.get();

	system("cls");

	mainmenu(studData, columnNum, rowNum, headernames); // leads to main menu 

	return 0; 
}