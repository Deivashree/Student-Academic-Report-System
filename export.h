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



/***********************************************************************
Programmer    :	Ali Imran Bin Shahrin
Name          : exportItem

task          :	Exports the Full Stats Report to html
data in       : Subject Name , Export Values
data returned :	None
Referred to   :	None
************************************************************************/

void exportFullStats(string subjectName, vector <double> exportValues) {
 
	//starting html
	ofstream myfile;

  string createFile = subjectName + "FullStatsReport" + ".html";
  myfile.open(createFile);
	
  myfile << "<!DOCTYPE html><html><head><style> table, th, td {border: 1px solid black;}</style></head><body>" << endl;

	myfile << "<table style=" << "'width:50'>" << endl;

	myfile << "<tr>" << endl;
	myfile << "<th>"<< "Subject"<<"</th>" << endl; 
  myfile << "<th>" << subjectName << "</th>" << endl; 
	myfile << "</tr>" << endl;

	for (int i = 0; i <= 5;i++)
  {
		myfile << "<tr>" << endl;
		myfile << "<td> " << endl; 
		myfile << computationNames[i];
		myfile << "</td>" << endl; 
		myfile << "<td> " << endl; 
		myfile <<setprecision(2) << fixed << exportValues[i];
		myfile << "</td>" << endl; 
		myfile << "</tr>" << endl; 
 	} 
	
  	myfile << "</table>" << endl;

   	//ending html
    myfile << "</body></html>";
    myfile.close();

  return;
}


/****************************************************************************************
Programmer    :	Deivashree A/P Selva Rajoo
Name          : exportMarksFrequencyDistribution

task          :	To export the values of the marks and the frequency of the distinct marks to a HTML file
data in       : Subject name, the values of the marks and the values of the frequency
data returned :	None
Referred to   : https://stackoverflow.com/questions/11206604/create-html-reports-using-c
*****************************************************************************************/

void exportMarksFrequencyDistribution(string subjectName, vector <double> exportmarks, vector <double> exportfreq) {

	//starting html
	ofstream myfile;

  string createFile = subjectName + "MarksFrequencyDistribution" + ".html";
  myfile.open(createFile);

  myfile << "<!DOCTYPE html><html><head><style> table, th, td {border: 1px solid black;}</style></head><body>" << endl;

	myfile << "<table style=" << "'width:50'>" << endl;

 	myfile << "<tr>" << endl; 
  myfile << "<h1>"<< "Marks Frequency Distribution for " << subjectName <<"</h1>" << endl; //header name
 	myfile << "<th>Marks</th>" << endl;
  myfile << "<th>Frequency</th>" << endl;
	myfile << "</tr>" << endl;

  for (int i = 0; i < exportmarks.size();i++) // displays marks and frequency
  {
    myfile << "<tr>" << endl;

	  myfile << "<td> " << endl;
	  myfile << exportmarks[i];
    myfile << "</td>" << endl;

	  myfile << "<td> " << endl;
	  myfile << exportfreq[i];
	  myfile << "</td>" << endl;

	  myfile << "</tr>" << endl;

  }

  myfile << "</table>" << endl;

  //ending html
  myfile << "</body></html>";
  myfile.close();

	return;
}


/****************************************************************************************
Programmer    :	Deivashree A/P Selva Rajoo
Name          : exportHistogram

task          :	To export the range of the marks and the frequency of the marks to a HTML file 
data in       : Subject name, upper range, lower range and the frequency value for each range
data returned :	None
Referred to   : https://stackoverflow.com/questions/11206604/create-html-reports-using-c
*****************************************************************************************/

void exportHistogram(string subjectName, vector <int> exportLowerRange, vector <int> exportHigherRange, vector <int> frequencyCount) {

	//starting html
	ofstream myfile;

    string createFile = subjectName + "Histogram" + ".html";
    myfile.open(createFile);

    myfile << "<!DOCTYPE html><html><head><style> table, th, td {border: 1px solid black;}</style></head><body>" << endl;

	  myfile << "<table style=" << "'width:50'>" << endl;

  	myfile << "<tr>" << endl;
	  myfile << "<h1>"<< "Histogram for " << subjectName <<"</h1>" << endl; //header name
  	myfile << "<th>Marks</th>" << endl;
  	myfile << "<th>Frequency</th>" << endl;
	  myfile << "</tr>" << endl;

  for (int i = 0; i < exportLowerRange.size();i++){//to display the range and the frequency of the values
    myfile << "<tr>" << endl;

	  myfile << "<td> " << endl;

	  if (exportHigherRange[i] != 100) {
	  myfile << exportLowerRange[i] << " - < " << exportHigherRange[i];
	  }
	  else {
		  myfile << exportLowerRange[i] << " - " << exportHigherRange[i];
	  }
	  myfile << "</td>" << endl;

	  myfile << "<td>" << endl;
	  for (int numofStars = 0; numofStars < frequencyCount[i]; numofStars++){

		myfile << "*";
	  }
	  myfile << "</td>" << endl;

	  myfile << "</tr>" << endl;
  }
  	myfile << "</table>" << endl;

   	//ending html
    myfile << "</body></html>";
    myfile.close();

    return;
}

/*******************************************************************************
Programmer    :	Ali Imran Bin Shahrin
Name          : exportMeanAboveBelow

task          :	Exports the MeanAboveBelow into a html file
data in       : Subject Name , ID from the user chosen file, Above Mean value, Below Mean value, Mean value
data returned : None
Referred to   : None
********************************************************************************/

void exportMeanAboveBelow(string subjectName,vector<double>ID,vector<double>belowMean,vector<double>aboveMean,double mean){
  //starting html
	ofstream myfile;

    string createFile = subjectName + "MeanAboveBelow" + ".html";
    myfile.open(createFile);

    //start of html file
  myfile << "<!DOCTYPE html><html><head><style> table, th, td {border: 1px solid black;}</style></head><body>" << endl;
  myfile << "<p>" << "Subject: " << subjectName << "</p>";
	myfile << "<p>" << "Average: "<< mean << "</p>";

	myfile << "<table style=" << "'width:50'>" << endl;

  myfile << "<tr>" << endl;
  myfile << "<th>ID</th>";
  myfile << "<th>Below Mean</th>";
  myfile << "<th>Above Mean</th>";
	myfile << "</tr>" << endl;

  for(int i = 0; i < belowMean.size();i++)
  {
  myfile << "<tr>" << endl;
  myfile << "<td>" << setprecision(10) << ID[i] << "</td>";
  myfile << "<td>" << belowMean[i] << "</td>";
  myfile << "<td>" << aboveMean[i] << "</td>";
  myfile << "<tr>" << endl;
  }
  // end of html file

  return;
}


/****************************************************************************************
Programmer    :	Nur Arina Nabihah binti Muhammad Nadzri // 
                Nurul Izzah Binti Shahrin
Name          : exportCompareandPearsonLinear

task          :	Output table for data values in html 
data in       : Name of subject 1, Name of subject 2,  Row Num, All data values, Choice of subject 1,
                Choice of subject 2, output of r, output of a, output of b, total value of x,
                total value of y, total value of xy, total value of x2, total value of y2, values of x,values of y, values of xy, values of x2,values of y2, Column name, values of data
data returned :	None
Referred to   : https://www.w3schools.com/html/html_tables.asp
*****************************************************************************************/

void exportCompareandPearsonLinear(string subject1,string subject2,int rowNum,vector <vector<double>> allRows, int ch1, int ch2, string outputR, string outputA, string outputB, double totalx, double totaly, double totalxy, double totalx2, double totaly2, vector <double> valuesofX,vector <double> valuesofY, vector <double> valuesofXY, vector <double> valuesofX2, vector <double> valuesofY2, vector <string> columnNames, vector <double> data) 
{
	//starting html;
	ofstream myfile;
  
  subject1 = columnNames[ch1];
  subject2 = columnNames[ch2];

  string createFile = subject1 + subject2 + "CompareandPearsonLinear" + ".html";
  myfile.open(createFile);
	
  myfile << "<!DOCTYPE html><html><head><style> table, th, td {border: 1px solid black;}</style></head><body>" << endl;

	myfile << "<table style=" << "'width:50'>" << endl;
	
  myfile << "<table>" << endl;
	myfile << "<h1>" << subject1 << "(X)" <<  " VS " << subject2 << "(Y)" << "</h1>" << endl;
	myfile << "<tr>" << endl;
	myfile << "<th>"<< "ID" <<"</th>" << endl; 
	myfile << "<th>" << "X" << "</th>" << endl;
	myfile << "<th>"<< "Y" <<"</th>" << endl; 
	myfile << "<th>"<< "XY" <<"</th>" << endl; 
	myfile << "<th>"<< "X2" <<"</th>" << endl;  
	myfile << "<th>"<< "Y2" <<"</th>" << endl; 
	myfile << "</tr>" << endl;

  for(int i = 0; i < rowNum; i++)
	{
		totalx = allRows[i][ch1];
		totaly = allRows[i][ch2];
    totalxy = (allRows[i][ch1])*(allRows[i][ch2]);
  	totalx2 = (allRows[i][ch1])*(allRows[i][ch1]);
  	totaly2 = (allRows[i][ch2])*(allRows[i][ch2]);

		valuesofX.push_back(totalx);
		valuesofY.push_back(totaly);
    valuesofXY.push_back(totalxy);
  	valuesofX2.push_back(totalx2);
  	valuesofY2.push_back(totaly2);
	}
	
  //VALUES IN TABLE
  for (int i = 0, j = 0; i < allRows.size();i++)
  {
    myfile << "<tr>" << endl;

    myfile << "<td> " << endl; 
    myfile << fixed << setprecision(0) << allRows[i][j] << endl;
    myfile << "</td>" << endl;

    myfile << fixed << setprecision(2); 
    myfile << "<td> " << endl;  
    myfile << valuesofX[i];
    myfile << "</td>" << endl;

    myfile << "<td> " << endl;  
    myfile << valuesofY[i];
    myfile << "</td>" << endl;

    myfile << "<td> " << endl;  
    myfile << valuesofXY[i];
    myfile << "</td>" << endl;

    myfile << "<td> " << endl; 
    myfile << valuesofX2[i];
    myfile << "</td>" << endl;

    myfile << "<td> " << endl;  
    myfile << valuesofY2[i];
    myfile << "</td>" << endl;

    myfile << "</tr>" << endl;
  }

	/// TOTAL /// 

	myfile << "<tr>" << endl;
	
	myfile << "<td> " << endl;
	myfile << "Total";
	myfile << "</td>" << endl;

  myfile << "<td> "; 
  myfile << setw(15) << right << data.at(0);
  myfile << "</td>" << endl;

  myfile << "<td> "; 
  myfile << setw(15) << right << data.at(1);
  myfile << "</td>" << endl;

  myfile << "<td> "; 
  myfile << setw(15) << right << data.at(2);
  myfile << "</td>" << endl;

  myfile << "<td> "; 
  myfile << setw(15) << right << data.at(3);
  myfile << "</td>" << endl;

  myfile << "<td> "; 
  myfile << setw(15) << right << data.at(4);
  myfile << "</td>" << endl;

  myfile << "</tr>" << endl;
	
  myfile << "</table>" << endl;

  //pearson value
  myfile << "<p>" << "\n==========================" << endl; 
  myfile << "Pearson's correlation" << endl;
  myfile << "==========================" << endl << "</p>";
    
  myfile << "<p>" << fixed << setprecision(2); 
  myfile << "r = " << "(" << rowNum << "*" << data.at(2) << " - " << data.at(0) << "*" <<  data.at(1) << ")" << endl << setw(5) <<"/" << "sqrt " << "((" << rowNum << "*" << data.at(3)  << " - " << data.at(0) << "*" << data.at(0) << ")) * ((" << rowNum << "*" << data.at(4) << ") - (" << data.at(1) << "*" << data.at(1) << "))" << endl << "  = " << outputR <<endl << endl << "</p>";
    
  //linear regression value
  myfile << endl << "<p>" << "\n==========================" << endl;
  myfile << "Linear Regression" << endl;
  myfile << "==========================" << endl << "</p>";
    
  myfile << endl << "<p>" << "a = " << "(" << data.at(1) << "*" << data.at(3) << " - "<< data.at(0) << "*" <<  data.at(2) << ") / (" << rowNum << "*" << data.at(3) << " - " << data.at(0) << "*" <<  data.at(0) << ")" <<endl <<"  = " << outputA << endl << "</p>";

	myfile << endl << "<p>" << "b = " << "(" << rowNum << "*" << data.at(2) << " - "<< data.at(0) << "*" <<  data.at(1) << ") / (" << rowNum << "*" << data.at(3) << " - " << data.at(0) << "*" <<  data.at(0) << ")" << endl<<"  = " << outputB << endl << "</p>";

  myfile << endl << "<p>" << "y'= " << outputA << " + " << outputB << "x" << "</p>" << endl;

  //ending html
  myfile << "</body></html>";
  myfile.close();
  return;
}