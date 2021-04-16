using namespace std; 

//function prototypes 
string fileopen(); 
void readFile(string, vector<vector<double>> &allRows, int&,int&, vector <string> &columnNames); 
void printFileData(vector <vector<double>> &allRows,vector<string>&columnNames);
double calculateMax(int , int , vector <vector<double>> allRows,vector<string>columnNames,int&);
double calculateMean (int, int, vector <vector<double>> allRows, vector<string>columnNames,int&);
double calculateMedian (int, int, vector <vector<double>> allRows, vector<string>columnNames,int&);
double standardDeviation (int, int, vector <vector<double>>, vector<string>,int&);
double calculateVariance(int, int, vector <vector<double>>, vector<string>,int&);
void computeMarkFreq(int columnNum, int rowNum, vector <vector<double>> allRows, vector<string>columnNames,int& calculate);
void computeHisto(int, int, vector <vector<double>>, vector<string>,int&);
void meanAboveBelow(int columnNum, int rowNum, vector <vector<double>> allRows, vector<string>columnNames,int& calculate);
void sortData(int columnNum, int rowNum, vector <vector<double>> allRows, vector<string>columnNames,int& calculate);
void mainmenu(vector <vector<double>> allRows, int, int,vector<string> columnNames);
int computeSubject(vector <vector<double>> allRows, int, int,vector<string> columnNames,int &calc);
void computemenu(vector<vector<double>> allRows, int, int, vector <string> columnNames,int);
void computemenuAll(vector<vector<double>> allRows, int, int, vector <string> columnNames,int);
void comparemenu(vector <vector<double>> allRows, int columnNum, int rowNum,vector<string> columnNames, int&, int&);
void exitfunction (int columnNum, int rowNum, vector <vector<double>> allRows, vector<string>columnNames);
void fullstatsReport (int columnNum, int rowNum, vector <vector<double>> allRows, vector<string>columnNames,int subCol);
void calcCompare(vector <vector<double>>, int, int,vector<string>,int, int);
void calculatePearsonLinear (vector <vector<double>> allRows, int columnNum, int rowNum, vector<string> columnNames,int choice1, int choice2);
void dataString(vector<string> columnNames, vector <vector<double>> allRows,int, int);
void exportFullStats(string subjectName, vector <double>);
void exportMarksFrequencyDistribution(string subjectName, vector <double> exportmarks, vector <double> exportfreq);
void exportHistogram(string, vector <int>, vector <int>, vector <int>);
void exportMeanAboveBelow(string subjectName,vector<double>ID,vector<double>belowMean,vector<double>aboveMean,double mean);
void exportSortData(string subjectName,int choice,vector<int>ID,vector<double>asc,vector<double>desc);
void exportCompareandPearsonLinear(string subject1,string subject2,int rowNum,vector <vector<double>> allRows, int ch1, int ch2,string outputR,string outputA,string outputB, double totalx, double totaly, double totalxy, double totalx2, double totaly2, vector <double> valuesofX,vector <double> valuesofY, vector <double> valuesofXY, vector <double> valuesofX2, vector <double> valuesofY2, vector <string> columnNames, vector <double> data);
int takeChoice(string message, int min, int max);


//global vector variables//

	//to store the name of the computations // Made by Ali Imran
	vector<double> valuesComputation = {};
	vector<string> computationNames = {"Minimum","Maximum","Mean","Median","Standard Deviation","Variance"};

	//to store the header names for the compare data display table 
	vector <double> valuesCompare = {};
	vector<string> compareNames = {"x","y","xy","x2","y2"};


  
/***********************************************************************
Programmer    :	Deivashree A/P Selva Rajoo
Name          : fileopen

task          :	Prompts the user to enter a file name and opens the file
data in       : None
data returned :	The file is stored in a string variable called filename
Referred to   :	-
************************************************************************/

string fileopen() {

	string filename;
	ifstream dataIn(filename); 

	cout << "Enter text file name: \n"; //asks for file name
	cin >> filename;
	dataIn.open(filename);

  	while(!(dataIn.is_open())){//loop for wrong input of file

		cout << "Error! Wrong input of file. \n";
		cout << "Enter text file name: \n"; 
		cin >> filename;
		dataIn.open(filename);
	}
	//displays the file name and prompts user to go back to main menu
	cout << "\n"<< filename <<" has been loaded successfully!" << endl;
	cout << "Please press enter to go back." << endl;
	cin.ignore();
	cin.get();
	system("cls");

	return filename; 
}

/****************************************************************************************
Programmer    :	Ali Imran Bin Shahrin
Name          : readFile

task          :	Reads the data file given from the user.
data in       : file name, Data from all rows, Column Number, Row Number, Column Names
data returned :	None
Referred to   :	None
*****************************************************************************************/

void readFile(string fileName,vector <vector<double>> &allRows,int &columnNum, int &rowNum,vector<string> &columnNames){

  ifstream dataIn{fileName};
	string columnNumber, rowNumber;
  allRows.clear(); 
	columnNames.clear(); 

  // To get data from the first line of csv file
  getline(dataIn, columnNumber);
	columnNum = stoi(columnNumber); 

  // To get data from the second line of csv file
  string secondLine {};
  getline(dataIn, secondLine);

  istringstream iss {secondLine};
  string columnItem;
  while(getline(iss, columnItem, ',')) {
	columnNames.push_back(columnItem);
	}     

  // To get data from the third line of csv file
  getline(dataIn, rowNumber);
	rowNum = stoi(rowNumber); 

  // To get data from the fourth line until the end of csv file
  string lines;
  while (getline(dataIn, lines)) {
    istringstream iss2 {lines};
    string rowItem;
    vector<double> rowNames{};
  while(getline(iss2, rowItem, ',')) {
    rowNames.push_back(stold(rowItem));
  }
    allRows.push_back(rowNames);
	}   
 	return;		
} 


/****************************************************************************************
Programmer    :	Deivashree A/P Selva Rajoo
Name          : printFileData

task          :	To display all the data from the file and the header names
data in       : Header names and the student ID, age, and subject values
data returned :	None
Referred to   : https://thispointer.com/c-convert-double-to-string-and-manage-precision-scientific-notation/
*****************************************************************************************/

void printFileData(vector <vector<double>> &allRows,vector<string>&columnNames){

  for(int i = 0; i < columnNames.size(); i++)//Print column names
  {
    cout << left << setw(14) << columnNames[i];
  }

	cout << endl;

  for(int i = 0;i != allRows.size();i++){//Prints data from user

		//Prints a line after header names
	for (int length = 0; length < columnNames.size(); length++) {
		cout << "--------------";
	}
    cout << endl;
		
	for(int j = 0;j != allRows[i].size();j++){
		
		if (j == 0) {
			double ID = allRows[i][j]; //convert double ID to string
			ostringstream streamObj;
			streamObj << fixed << setprecision(0);
			streamObj << ID; 
			string strObj = streamObj.str();	
			cout << left << setw(14) << strObj;
		}
		else if (j == 1) {
				double age = allRows[i][j];  // convert age to string
				ostringstream streamObj;
				streamObj << fixed << setprecision(0);
				streamObj << age; 
				string strObj = streamObj.str();	
				cout << left << setw(14) << strObj; 
			}
		else {
			//convert marks for all subject from double to string
			double marks = allRows[i][j]; 
			ostringstream streamObj;
			streamObj << fixed << setprecision(2);
			streamObj << marks; 
			string strObj = streamObj.str();
			cout << setw(15) << strObj; 
		}
  }
	cout << endl;
}

	//Prints a line after all data is displayed 
	for (int length = 0; length < columnNames.size(); length++) {
		cout << "--------------";
	}
	cout << endl;

	//Prompt user to go back to main menu
	cout << "Please press enter to go back." << endl;
	cin.get();
	system("cls");

  return;
}