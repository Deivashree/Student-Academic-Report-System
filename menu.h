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


/*******************************************************************************
Programmer    :	Ali Imran Bin Shahrin 
Name          : mainmenu

task          :	Displays the main menu and calls other functions
data in       : All of the data value from the user chosen file, Column Number , Row Number, Column Names
data returned :	None
Referred to   : None
********************************************************************************/

void mainmenu(vector <vector<double>> allRows, int columnNum, int rowNum,vector<string> columnNames)
{ 
  int subColumn = columnNum - 2;
	int choice;
	int choice1, choice2;
	bool valid_input = true;

  do { // print menu
    cout << "==============================" << endl; 
    cout << "Main Menu" << endl;
    cout << "==============================\n" << endl;
    cout << "1.Load Data" << endl;  
    cout << "2.Display Data" << endl;
    cout << "3.Compute Data" << endl;
    cout << "4.Compare Data" << endl;
    cout << "5.Full Statistical Report" << endl;
    cout << "6.Exit" << endl << endl;
    choice = takeChoice("Enter an integer choice",1,6);

    // to ensure user input within range
    while (choice < 1 || choice > 6) {
      cout << "Invalid Number" << endl;
      choice = takeChoice("Enter an integer choice",1,6);
    }

    if (choice > 1 && choice < 6) {
      if (allRows.empty()) {
        cout << "\nError! Data is not found." << endl;
        cout << "Please press enter to continue." << endl;
        cin.get();
        system("cls");
        continue;
      }
    }

    switch(choice)
    {
      case 1:
        system("cls");
        readFile(fileopen(), allRows, columnNum, rowNum, columnNames); //load data
        break;
      case 2: 
        system("cls");
        printFileData(allRows,columnNames); //display data
        cout << "\n";
        break;
      case 3:  
        system("cls");
        computeSubject(allRows,columnNum,rowNum,columnNames,choice); //compute data
        break; 
      case 4:
        system("cls");
        comparemenu(allRows,columnNum,rowNum,columnNames,choice1, choice2); //compare data
        break;
      case 5:
        system("cls");
        fullstatsReport(columnNum,rowNum,allRows,columnNames,columnNum-1); //to print all computations for chosen subject
        break;
      case 6:
        system("cls");
        exitfunction(columnNum,rowNum,allRows,columnNames); //to exit program
        break;  
    }
  } while(valid_input == true);

  return;
}

/*******************************************************************************
Programmer    :	Deivashree A/P Selva Rajoo
Name          : computeSubject

task          : To output a table with the subjects from the data file for the user to choose their desired choice of subject
data in       : Data from the user chosen file, column number, row number, column names,
                choice of input from the user
data returned :	Choice of subject
Referred to   : None
********************************************************************************/

int computeSubject(vector <vector<double>> allRows, int columnNum, int rowNum,vector<string> columnNames,int &subChoice) {
  
	bool valid_input = false; 

  do {
    
    int menuNum = 1;
    int subjectCol = columnNum - 2;
    int allSubject = subjectCol + 1; 

    // print menu
    cout<<"=============================\nSubject Menu\n=============================\n";

    cout << "Choose the subject to compute data." << endl << endl; 
    
    for (int subjectName = 2; menuNum <= subjectCol && subjectName <= allSubject; menuNum++, subjectName++){
      
      cout << menuNum << "." << columnNames[subjectName] << endl;	
    }

    cout << menuNum << ".All subjects" << endl;  
    cout << "0.Back to main menu" << endl; 

    subChoice = takeChoice("Enter an integer choice",0,menuNum);

    // to ensure user input within range
    while (subChoice < 0 || subChoice > menuNum) {
    cout << "Invalid Number" << endl;
    subChoice = takeChoice("Enter an integer choice",0,menuNum);
    }

    if (subChoice == 0) {
      valid_input = true; 
      system("cls");
      mainmenu(allRows,columnNum,rowNum,columnNames); //back to main menu
      break;
    }
    else if (subChoice > 0 && subChoice <= subjectCol) {
      valid_input = true; 
        system("cls");
      computemenu(allRows,columnNum,rowNum,columnNames,subChoice); //computations for one subject
      break;
    }
    else if (subChoice == allSubject) {
      valid_input = true; 
        system("cls");
      computemenuAll(allRows,columnNum,rowNum,columnNames,subChoice); //computations for all subject
      break;
    }
    
  }while(valid_input == false);
	
	return subChoice; 
}

/****************************************************************************************
Programmer    :	1) Deivashree A/P Selva Rajoo
                2) Ali Imran Bin Shahrin
Name          : computemenu

task          :	Outputs the computeing menu for the user to choose their calculation to display out the chosen computation for one subject
data in       : All Data from the user chosen file, Column Number , Row Number , Column Names, 
                Subject Choice from the user
data returned :	None
Referred to   : None
*****************************************************************************************/

void computemenu(vector <vector<double>> allRows, int columnNum, int rowNum,vector<string> columnNames, int subChoice)
{ 
	int computeSub = subChoice;
  int calchoice;
	bool valid_input = false;

	do //print computation menu
  { 
		
    cout<<"=============================\nCompute Menu\n=============================\n";
    cout <<"\n1.Minimum\n";
    cout<<"2.Maximum\n";
    cout<<"3.Mean\n";
    cout<<"4.Median\n";
    cout<<"5.Standard Deviation\n";
    cout<<"6.Variance\n";
    cout<<"7.Marks Frequency Distribution\n";
    cout<<"8.Histogram\n";
    cout<<"9.Mean Above Below\n";
    cout<<"10.Sort Data\n";
    cout<<"0.Back to subject menu\n";

    calchoice = takeChoice("Enter an integer choice",0,10);

    while (calchoice < 0 || calchoice > 10) { // to ensure user input within range
      cout << "Invalid Number" << endl;
      calchoice = takeChoice("Enter an integer choice",0,10);
    }

    switch(calchoice)
    { 
      case 0:
        valid_input = true;
        system("cls");
        computeSubject(allRows,columnNum,rowNum,columnNames,computeSub); // back to subject menu
        break; 
      case 1:
        valid_input = true;
        calculateMin(columnNum,rowNum,allRows,columnNames,computeSub); //calculate minimum
        break;
      case 2:
        valid_input = true;
        calculateMax(columnNum,rowNum,allRows,columnNames,computeSub); //calculate maximum
        break;
      case 3:
        valid_input = true;
          calculateMean(columnNum, rowNum, allRows, columnNames, computeSub); //calculate mean
        break;
      case 4:
        valid_input = true;
          calculateMedian(columnNum, rowNum, allRows, columnNames, computeSub); //calculate median
        break;
      case 5:
        valid_input = true;
        standardDeviation(columnNum,rowNum,allRows,columnNames,computeSub); //calculate standard deviation
        break;
      case 6:
        valid_input = true;
        calculateVariance(columnNum,rowNum,allRows,columnNames,computeSub); //calculate variance
        break;
      case 7:
        valid_input = true;
          computeMarkFreq(columnNum,rowNum,allRows,columnNames,computeSub); //calculate mark frequency distribution
        break;
      case 8:
        valid_input = true;
        computeHisto(columnNum,rowNum,allRows,columnNames,computeSub); //calculate histogram
        break;
      case 9:
        valid_input = true; 
        meanAboveBelow(columnNum, rowNum, allRows, columnNames, computeSub); //calculate mean above and below the average
        break;
      case 10:
        valid_input = true;
        sortData(columnNum, rowNum, allRows, columnNames, computeSub); //to sort data in ascending or descending
        break;
    }
	} while(valid_input==false);
  
	cout << "Please press enter to proceed.";
  cin.get();
	system("cls");
  mainmenu(allRows,columnNum,rowNum,columnNames); //goes back to main menu after computation
	  
	return;
}

/*******************************************************************************
Programmer    :	Deivashree A/P Selva Rajoo
Name          : computemenuAll

task          :	Outputs the table with computations that the user can choose from to display out the chosen computation for all subjects
data in       : Data from the user chosen file, Column Number, Row Number, Column Name,Subject of choice from the user
data returned :	None
Referred to   : None
********************************************************************************/

void computemenuAll(vector <vector<double>> allRows, int columnNum, int rowNum,vector<string> columnNames, int subChoice)
{

	int computeSub = subChoice;
  int calchoice;
	bool valid_input = false;

  //to print menu
	do 
  { 

    cout<<"=============================\nCompute Menu\n=============================\n";
    cout <<"\n1.Minimum\n";
    cout<<"2.Maximum\n";
    cout<<"3.Mean\n";
    cout<<"4.Median\n";
    cout<<"5.Standard Deviation\n";
    cout<<"6.Variance\n";
    cout<<"0.Back to subject menu\n";

    calchoice = takeChoice("Enter an integer choice",0,6);

    while (calchoice < 0 || calchoice > 6) { //to ensure user input within range
    cout << "Invalid Number" << endl;
    calchoice = takeChoice("Enter an integer choice",0,6);
    }

    switch(calchoice)
    { 
      case 0:
        valid_input = true;
        system("cls");
        computeSubject(allRows, columnNum,rowNum,columnNames,computeSub); //back to subject choice menu
        break; 
      case 1:
        valid_input = true;
        calculateMin(columnNum,rowNum,allRows,columnNames,computeSub); //calculate min
        break;
      case 2:
        valid_input = true;
        calculateMax(columnNum,rowNum,allRows,columnNames,computeSub); //calculate max
        break;
      case 3:
        valid_input = true;
          calculateMean(columnNum, rowNum, allRows, columnNames, computeSub); //calculate mean
        break;
      case 4:
        valid_input = true;
          calculateMedian(columnNum, rowNum, allRows, columnNames, computeSub); //calculate median
        break;
      case 5:
        valid_input = true;
        standardDeviation(columnNum,rowNum,allRows,columnNames,computeSub); //calculate standard deviation
        break;
      case 6:
        valid_input = true;
        calculateVariance(columnNum,rowNum,allRows,columnNames,computeSub); //calculate variance
        break;
    }
   
	} while(valid_input==false);
  
	cout << "Please press enter to proceed.";
  cin.get();
	system("cls");
  mainmenu(allRows,columnNum,rowNum,columnNames); //back to main menu after computation

	return; 
}

//takes the choice of user input and returns
int takeChoice(string message, int min, int max)
{
  int number;
  do{
	  cout << message << "(" << min << " to " << max << "): ";
    cin >> number;
  	cin.clear();
    cin.ignore(10000, '\n');

  }while(number<min && number>max);

  return number;
}



/****************************************************************************************
Programmer    :	1) Ali Imran Bin Shahrin
                2) Nur Arina Nabihah Binti Muhammad Nadzri
Name          : comparemenu

task          :	Compare subject
data in       : Column num, Row num, All data values, Column name, Choice of subject 1, Choice of subject 2
data returned :	None
Referred to   : None
*****************************************************************************************/

void comparemenu(vector <vector<double>> allRows, int columnNum, int rowNum, vector<string> columnNames,int &choice1, int &choice2)
{
	bool valid_input = false;
	
 	do
  {
    //initialize value i, subjectCol,maxInput
		int i = 1;
		int subjectCol = columnNum - 2;
		int maxInput = subjectCol + 2; 

		cout<<"=============================\nCompare Menu\n=============================\n";
		cout << "Choose the subject to compare data." << endl << endl;
    
		for (int j = 2; i<= subjectCol && j <= maxInput-1; i++, j++)
		{
		  cout << i << "." << columnNames[j] << endl;	
		}
		cout << endl;
    
		//Display invalid output when user choose invalid number
		choice1 = takeChoice("Choose subject 1: ",1,i-1);
		while (choice1 < 1 || choice1 > i-1)
    {
			cout  << "Invalid Number" << endl << endl;
			choice1 = takeChoice("Choose subject 1: ",1,i-1);
		}
		cout << endl << endl;
		
		choice2 = takeChoice("Choose subject 2: ",1,i-1);
		while (choice2 < 1 || choice2 > i-1)
    {
      cout << "Invalid Number" << endl;
      choice2 = takeChoice("Choose subject 2: ",1,i-1);
		}
	
		while (choice1 == choice2)
    {
			cout << endl << "Invalid Number" << endl << endl;
			choice2 = takeChoice("Choose subject 2: ",1,i-1);
		}

		calcCompare(allRows,columnNum,rowNum,columnNames,choice1,choice2);
		valid_input = true;

  	} while(valid_input==false);

  return;
} 

/*******************************************************************************
Programmer    :	Nurul Izzah Binti Shahrin
Name          : exitfunction

task          :	Prompts the user if they want to exit the program and exits the program.
data in       : Column number, Row number, All the data values, Column name
data returned :	None
Referred to   : None
********************************************************************************/

void exitfunction (int columnNum, int rowNum, vector <vector<double>> allRows, vector<string>columnNames)
{
  int choice;
  bool validInput = false;
  
  cout << endl;
  cout << "=========================================" << endl;
  cout << "Are you sure you want to exit program?" << endl;
  cout << "=========================================" << endl;
  cout << endl << "1. Yes" << endl;
  cout << "2. No" << endl;

  choice = takeChoice("Enter an integer choice",1,2);

  do
  {
    //exits the program
    if (choice == 1)
    {
      validInput = true;
      system("cls");
      exit(0);
    }
    else if (choice == 2)
    {
      //return back to main menu
      validInput = true;
      system("cls");
      mainmenu(allRows,columnNum,rowNum,columnNames);
    }
    else
    {
      cout << "Please enter a valid choice." << endl;
      choice = takeChoice("Enter an integer choice",1,2);
      cout << endl;
    }
  }while(validInput == false);
  return;
}
///////// EXIT FUNCTION ENDS HERE ////////////
