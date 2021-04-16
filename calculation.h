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



/****************************************************************************************
Programmer    :	Nur Arina Nabihah Binti Muhammad Nadzri
Name          : calculateMin

task          :	This function calculates the minimum of the number in the data.
data in       : Column Number, Row Number, All Data Value, Column Names, Choice of input from the user
data returned :	Value(s) of Min
Referred to   : None
*****************************************************************************************/

double calculateMin(int columnNum, int rowNum,vector <vector<double>> allRows,vector<string>columnNames,int& calculate) // calculate denotes choice from user
{
	//initialize j, min and sucjectCol
	int j = calculate;
	double min;
	int subjectCol = columnNum - 2;
  
	//Loops to output min for one subject
	if (j <= subjectCol)
	{
    j = j + 1;
	  min = allRows[0][j];

    //Insert the lowest value of the data to min
    for (int i = 0; i < rowNum; i++)
   	{
			if (allRows [i][j] <= min)
      {
			  min = allRows[i][j];
			}
    }

    // print the table and display the minimum value
	  cout << endl;
  	string subjectChoice = columnNames[j]; 
    cout << left << setw(16) << "Subject" << subjectChoice << endl;
	
	  cout << "------------------------------"; 
  	cout << endl;
	
	  cout << setw(16) << "Minimum" << setprecision(2) << fixed <<  min << endl; 

    cout << "------------------------------";  
	  cout << endl;

		//Puts min value into vector valuesComputation
		valuesComputation.push_back(min);
	}	
  
  //Loops to output min for all subjects
  else if (j == subjectCol + 1)
  {
	  system("cls");
    cout <<left<<setw(20) <<"Subjects" << setw(20)<<left << "Minimum"<<endl;
    cout << "----------------------------"<<endl;

    for(int col = 2; col <= j; col++ )
    {
      min = allRows[0][j];
      for (int i = 0; i < rowNum; i++)
      {
        if(allRows[i][col] <= min)
        {
          min = allRows[i][col];
        }
      }

      // Display the min for all subjects
      cout << setprecision(2) << fixed;
      cout <<left<<setw(20)<< columnNames[col]  <<setw(20)<< left<< min << endl;
    }
    cout << "-----------------------------"<<endl;
  }
	return min;
}

/****************************************************************************************
Programmer    :	Ali Imran Bin Shahrin
Name          : calculateMax

task          :	This function calculates the maximum value from the subject chosen by the user.
data in       : Column Number, Row Number, All Data Value, Column Names,Choice of input from the user
data returned :	Value(s) of Max
Referred to   : None
*****************************************************************************************/

double calculateMax(int columnNum, int rowNum, vector <vector<double>> allRows, vector<string>columnNames,int& calculate)
{
	//initialize j and max
	int j = calculate;
	double max = 0;
  
	// loop for one subject
	if (j<=3){

		j = j+1;
		for(int i=0 ; i<rowNum;i++){

		if (allRows[i][j] >= max){

		max = allRows[i][j];
		} 
	}  
	
	// print the table and display the maximum value
	cout << endl; 
	string subjectChoice = columnNames[j]; 
	cout << left << setw(16) << "Subject" << subjectChoice << endl;
	
	cout << "------------------------------"; 
	cout << endl;
	
	cout << setw(16) << "Maximum" << setprecision(2) << fixed <<  max << endl; 

	cout << "------------------------------";  
	cout << endl;

  //Puts max value into vector valuesComputation
  valuesComputation.push_back(max);
	}
	
// loop for all subjects
	else if(j == 4){ // outputs the data in tabular form

  	system("cls");
  	cout <<left<<setw(20) <<"Subjects" << setw(20)<<left << "Maximum"<<endl;
    cout << "----------------------------"<<endl;

   	for(int j = 2;j<columnNum;j++){
		max = 0;
		for(int i= 0;i<rowNum;i++){

			if(allRows[i][j]>=max){

				max = allRows[i][j];
			}
		}
	
		cout << setprecision(2) << fixed;
    cout <<left<<setw(20)<< columnNames[j]  <<setw(20)<<left<<max << endl;
    }
    cout << "----------------------------"<<endl;
	}
return max;
}
//FUNCTION TO CALCULATE MAX ENDS//

/****************************************************************************************
Programmer    :	Nurul Izzah Binti Shahrin
Name          : calculateMean

task          :	This function calculates the value of mean of the data
data in       : Column num, Row num, All data values, Column name, Choice of input from the user
data returned :	Value(s) of Mean
Referred to   :	https://www.mathsisfun.com/mean.html
*****************************************************************************************/

double calculateMean (int columnNum, int rowNum, vector <vector<double>> allRows, vector<string>columnNames,int& calculate)
{
  //Initialize j, mean and total
  int j = calculate;
  double mean = 0, total = 0;

  //Loops one subject
  if (j <= 3) 
  {
    j = j + 1;

    //Sums up total
    for (int i = 0; i < rowNum; i++)
    {
      total = total + allRows[i][j];
    }

    //Calculates Mean
    mean = total / rowNum;

    // print the table and display the mean value
	  cout << endl;
    string subjectChoice = columnNames[j]; 
	  cout << left << setw(16) << "Subject" << subjectChoice << endl;
	
	  cout << "------------------------------"; 
	  cout << endl;
	
	  cout << setw(16) << "Mean" << setprecision(2) << fixed <<  mean << endl; 

	  cout << "------------------------------";  
	  cout << endl;

    //Puts mean value into vector valuesComputation
    valuesComputation.push_back(mean);
  }

  //Loops for all subjects
  else if (j == 4)
  {
		
		system("cls");
    cout <<left<<setw(20) << "Subjects" << setw(20) << left << "Mean" <<endl;
    cout << "----------------------------"<<endl;
    
    for(int j = 2; j < columnNum; j++)
    {
      mean = 0, total = 0;
      
      //Sums up total
      for (int i = 0; i < rowNum; i++)
      {
        total = total + allRows[i][j];
      }

      //Calculates Mean
      mean = total / rowNum;

	    cout << setprecision(2) << fixed;
      cout << left<<setw(20)<< columnNames[j]  <<setw(20)<<left<<mean << endl;
    } 
    cout << "----------------------------"<<endl;
  }
  return mean;
}
//FUNCTION TO CALCULATE MEAN ENDS//

/****************************************************************************************
Programmer    :	Nurul Izzah Binti Shahrin
Name          : calculateMedian

task          :	This function calculates the value of mean of the data
data in       : Column num, Row num, All data values, Column name, Choice of input from the user
data returned :	Value(s) of Mean
Referred to   :	https://www.mathsisfun.com/mean.html
*****************************************************************************************/

double calculateMedian (int columnNum, int rowNum, vector <vector<double>> allRows, vector<string>columnNames,int& calculate)
{
  //Initialize and decalres variables
  int j = calculate, count = 0;
  double median = 0, temp = 0;
  vector<double> sortvect;
  vector<vector<double>> sortall;

  //Loops for one subject
  if (j <=3)
  {
    j = j + 1;

    //Insert the values into vector sortvect
    for (int i = 0; i < rowNum; i++)
    {
      temp = allRows[i][j];
      sortvect.push_back(temp);
      count = count + 1;
    }
  
    //Sorts the values in vector sortvect
    for (int i = 0; i < rowNum; i++)
    {
      for (int j = i+1; j < rowNum; j++)
      {
        if (sortvect[i] > sortvect[j])
        {
          temp = sortvect[i];
          sortvect[i] = sortvect[j];
          sortvect[j] = temp;
        }
      }
    }

    //Calculates median 
    int i = rowNum;

    if (i % 2 == 0)
      median = ((sortvect[(i / 2) - 1]) + sortvect[i / 2]) / 2;
    else
      median = sortvect[(i / 2)];

    // print the table and display the median value
	  cout << endl;
    string subjectChoice = columnNames[j]; 
	  cout << left << setw(16) << "Subject" << subjectChoice << endl;
	
	  cout << "------------------------------"; 
	  cout << endl;
	
	  cout << setw(16) << "Median" << setprecision(2) << fixed <<  median << endl; 

	  cout << "------------------------------";  
	  cout << endl; 
    
    //Puts median value into vector valuesComputation
    valuesComputation.push_back(median);
  }

  //Loops for all subjects
  else if (j == 4)
  {
		system("cls");
    cout <<left<<setw(20) << "Subjects" << setw(20)<< left << "Median" << endl;
    cout << "----------------------------"<<endl;
    for(int j = 2; j < columnNum; j++)
    {
      temp = 0, median = 0;
      vector<double> sortvect;

      //Insert the values into vector sortvect
      for (int i = 0; i < rowNum; i++)
      {
        temp = allRows[i][j];
        sortvect.push_back(temp);
      }

      //Sorts the values in vector sortvect
      for (int i = 0; i < rowNum; i++)
      {
        for (int k = i+1; k < rowNum; k++)
        {
          if (sortvect[i] > sortvect[k])
          {
            temp = sortvect[i];
            sortvect[i] = sortvect[k];
            sortvect[k] = temp;
          }
        }
      }

      //Calculates median
      int i = rowNum;

      if (i % 2 == 0)
        median = ((sortvect[(i / 2) - 1]) + sortvect[i / 2]) / 2;
      else
        median = sortvect[(i / 2)];

      cout << setprecision(2) << fixed;
      cout << left << setw(20)<< columnNames[j] << setw(20) << left << median << endl;
    }
    cout << "----------------------------" << endl;
  }
  return median;
}

/****************************************************************************************
Programmer    :	Deivashree A/P Selva Rajoo
Name          : standardDeviation

task          :	To calculate the standard deviation value for one subject or all subjects
data in       : Column number, row number, header names, the data values and the choice of subject
data returned :	Value(s) of Standard Deviation
Referred to   : http://www.statisticslectures.com/topics/variancepopulation/
*****************************************************************************************/

double standardDeviation (int columnNum, int rowNum, vector <vector<double>> allRows, vector<string>columnNames,int& calculate) {

	vector <double> stdD; 
	int j = calculate; 
	double total = 0, mean = 0, sum = 0, std = 0;
	int subjectCol = columnNum - 2; 
	int subjectChoice = 2;

	// calculation for one subject
	if (j <= subjectCol)
	{
		j = j + 1; 

		// total marks for one subject
		for (int i = 0; i < rowNum; i++) 
		{
			total = total + allRows[i][j];
		}

		// mean value 
		mean = total/rowNum; 

		// sum of the total minus the mean squared
		for (int i = 0; i < rowNum; i++) 
		{
			sum = sum + ((allRows[i][j] - mean)*(allRows[i][j] - mean));
		}

		//standard deviation value
		std = sqrt(sum/(rowNum));

		// print the table and display the standard deviation value
		cout << endl;
		string subjectChoice = columnNames[j]; 
		cout << left << setw(20) << "Subject" << subjectChoice << endl;
		
		cout << "------------------------------"; 
		cout << endl;
		
		cout << setw(20) << "Standard Deviation" << setprecision(2) << fixed <<  std << endl; 

		cout << "------------------------------";  
		cout << endl;

	  // standard deviation stored in vector to output for full stats report function
    valuesComputation.push_back(std);
	}
	else{
    
		//for all subjects calculation and also printing in tabular form
		system("cls");
    cout <<left<<setw(20) <<"Subjects" << setw(20)<<left << "Standard Deviation"<<endl;
    cout << "----------------------------"<<endl;
		for (int col = 2; col <= j; col++)
		{
			total = 0, mean = 0, sum = 0, std = 0;

			for (int i = 0; i < rowNum; i++) // sum of the marks for one subject
			{
				total = total + allRows[i][col];

				if (i == rowNum-1)
				{
					mean = total/rowNum; // mean value
				}
			}
	
			for (int i = 0; i < rowNum; i++) 
			{
				// sum of the total minus the mean squared
				sum = sum + ((allRows[i][col] - mean)*(allRows[i][col] - mean));

				if (i == rowNum-1) 
				{
					std = sqrt(sum/(rowNum)); //standard deviation value
					
					if (subjectChoice < columnNames.size()) {
					cout << setprecision(2) << fixed;
        			cout <<left<<setw(20)<< columnNames[subjectChoice]<<setw(20)<<left<<std << endl;
        			subjectChoice += 1;
					}		
				}	
			}			   
		}
	cout << "----------------------------"<<endl;   
	}	
	return std; 
}


/****************************************************************************************
Programmer    :	Deivashree A/P Selva Rajoo
Name          : variance

task          :	To calculate the variance value for one subject or all subjects
data in       : Column number, row number, header names, the data values and the choice of subject
data returned :	Value of Variance
Referred to   : http://www.statisticslectures.com/topics/variancepopulation/
*****************************************************************************************/

double calculateVariance (int columnNum, int rowNum, vector <vector<double>> allRows, vector<string>columnNames,int& calculate) {

	int j = calculate; 
	double total = 0, mean = 0, sum = 0, var = 0;
	int subjectCol = columnNum - 2; 
	int subjectChoice = 2;
	
    // calculates for one subject
	if (j <= subjectCol)
	{
		j = j + 1; 

		for (int i = 0; i < rowNum; i++) 
		{
			total = total + allRows[i][j]; // total marks for one subject
		}

		mean = total/rowNum; //mean value

		for (int i = 0; i < rowNum; i++) 
		{
			// sum of the total marks minus the mean squared
			sum = sum + ((allRows[i][j] - mean)*(allRows[i][j] - mean));
		}

		var = sum/(rowNum); // variance value

		// print the table and display the variance value
		cout << endl;
		string subjectChoice = columnNames[j]; 
		cout << left << setw(16) << "Subject" << subjectChoice << endl;
		
		cout << "------------------------------"; 
		cout << endl;
		
		cout << setw(16) << "Variance" << setprecision(2) << fixed <<  var << endl; 

		cout << "------------------------------";  
		cout << endl; 

    valuesComputation.push_back(var); // variance stored in vector to output for full stats report function
	}

	else {
	// calculates for all subjects and also print the values in tabular form

	  system("cls");
    cout <<left<<setw(20) <<"Subjects" << setw(20)<<left << "Variance"<<endl;
    cout << "----------------------------"<<endl;
		for (int col = 2; col <= j; col++)
		{
			total = 0, mean = 0, sum = 0, var = 0;
			for (int i = 0; i < rowNum; i++)
			{
				total = total + allRows[i][col]; // total marks for one subject

				if (i == rowNum-1)
				{
					mean = total/rowNum; //mean value
				}
			}
	  
			for (int i = 0; i < rowNum; i++) 
			{
				sum = sum + ((allRows[i][col] - mean)*(allRows[i][col] - mean));

				if (i == rowNum-1)
				{
					var = sum/(rowNum); // variance value
					
					cout << setprecision(2) << fixed;
          			cout << left << setw(20) << columnNames[subjectChoice]<<setw(20)<< left << var << endl;
          			subjectChoice+=1;
				}				
			}		
		}	
    cout << "----------------------------" << endl;
	}
	return var; 
}

/************************************************************************************
Programmer    :	1) Nurul Izzah Binti Shahrin
                2) Deivashree A/P Selva Rajoo
Name          : computeMarkFreq

task          :	This function calculates the marks frequency distribution of the data.
data in       : Column num, Row num, All data values, Column name, Choice of input from the user
data returned :	None
Referred to   : https://www.statisticshowto.com/probability-and-statistics/descriptive-statistics
                /frequency-distribution-table/
*************************************************************************************/

void computeMarkFreq(int columnNum, int rowNum, vector <vector<double>> allRows, vector<string>columnNames,int& calculate)
{
  //Initialize j, temp, marks, freq
  int j = calculate, count = 0;
  double temp = 0;
  vector <double> marks;
  vector <double> freq;

  //Table header
  cout << "\n\n---------------------------------------------" << endl;
  cout << "Marks Frequency Distribution: " << columnNames[j+1] << endl;
  cout << "---------------------------------------------" << endl << endl;
  cout << "Marks " << "  Frequency" << endl;
  cout << "------------------" << endl;
  
  j = j + 1;

  //Insert the values into vector marks and freq
  for (int i = 0; i < rowNum; i++)
  {
    temp = allRows[i][j];
    marks.push_back(temp);
    freq.push_back(0);   
  }

  //Sorts the vector marks
  for (int i = 0; i < rowNum; i++)
  {
    for (int j = i+1; j < rowNum; j++)
    {
      if (marks[i] > marks[j])
      {
        temp = marks[i];
        marks[i] = marks[j];
        marks[j] = temp;
      }
    }
  }
    
  //Add values to the vector freq
  for (int i = 0; i < marks.size(); i++)
  {
    double x = marks[i];
    for (int i = 0; i < marks.size(); i++)
    {
      if (marks[i] == x)
        freq[i]++;
    }
  }
  
  //Erases the repetition of data from vectors freq & marks
  for (int i = 0; i < marks.size(); i++)
  {
    if (freq[i] > 1)
    {
      for (int count = freq[i]; count != 1; count--)
      {
        if (i == 0)
        {
          marks.erase(marks.begin());
          freq.erase(freq.begin());
        }
        else
        {
          marks.erase(marks.begin() + i);
          freq.erase(freq.begin() + i);
        }
      }
    }
  }

  //Displays values of vector marks and vector freq
  for (int i = 0; i < marks.size(); i++)
  {
    cout << left << setw(5) << marks[i] << " | " << setw(5) << right << freq[i] << endl << endl;
	
    // txt file
    string subjectName = columnNames[j];

    string textFileName = subjectName + "MarksFrequencyDistribution" + ".txt";
    ofstream MyFile(textFileName);
    MyFile << "Subject" << setw(13) << "|" << subjectName << endl;
    MyFile << "----------------------------------\n";
    for (int i = 0; i < marks.size(); i++) {
      MyFile << left << setw(19) <<marks[i] << "|";
      MyFile << freq[i] << endl;
    }

    //  to call html function
    exportMarksFrequencyDistribution(subjectName,marks,freq);
  }
  cout << "Data has been exported. ";
  return;
}


/****************************************************************************************
Programmer    :	Deivashree A/P Selva Rajoo
Name          : computeHisto

task          :	To calculate the frequency of marks between each range of values
data in       : Column number, row number, header names, the values in the data and choice of subject
data returned :	None
Referred to   : None
*****************************************************************************************/

void computeHisto(int columnNum, int rowNum, vector <vector<double>> allRows, vector<string>columnNames,int& calculate) {

	vector <int> starCount;
	vector <int> lowRange;
	vector <int> highRange;
	int subjectChoice = calculate + 1; 
	string star = "*";
	int countStar;

	// to display table for the histogram
	cout << "\nHistogram: " << columnNames[subjectChoice] << endl << endl; 
	cout << "Marks " << setw(15) << " Frequency" << endl;
	cout << "---------------------" << endl;

	for (int lowerRange = 0; lowerRange <= 100; lowerRange += 10){ //to count the number of values for each range
		
		countStar = 0;
		int upperRange = lowerRange + 10;

		if (upperRange <= 100) { //to display the range

			if (upperRange == 10) {
				cout << lowerRange << " - <" << upperRange << setw(5) << " | ";
			}
			else if (upperRange < 100) {
				cout << lowerRange << " - <" << upperRange << setw(4) << " | ";
			}
			else {
				cout << lowerRange << " - " << upperRange << setw(4) << " | "; 
			}

			//range stored in vector for text file exporting
			lowRange.push_back(lowerRange);
			highRange.push_back(upperRange);
			
		//to count the number of values for each range
		for (int val = 0; val < rowNum; val++){ 

			if (upperRange < 100) {

				if (allRows[val][subjectChoice] >= lowerRange && allRows[val][subjectChoice] < upperRange){
					
					countStar += 1;
				}
			}

			if (upperRange == 100) {

				if (allRows[val][subjectChoice] >= lowerRange && allRows[val][subjectChoice] <= upperRange){
					
					countStar += 1;	
				}
			}
		}

		for (int output = 1; output <= countStar; output++){ // to display the number of values for each range represented by "*"
				cout << star;
		}

		starCount.push_back(countStar);
		cout << endl;
		} 
	}
		cout << endl;
		cout << "Data has been exported. ";

		// text file exporting
		string subjectName = columnNames[subjectChoice];
		
		// to display the range and frequency
		string textFileName = subjectName + "Histogram" + ".txt";
		ofstream MyFile(textFileName);
		MyFile << "Histogram for "<< subjectName << endl;
		MyFile << "---------------------\n";
		MyFile << left << setw(10) << "Marks " << " Frequency" << endl; 
		MyFile << "---------------------" << endl;

		for (int i = 0; i < lowRange.size(); i++) { // to display the range

			if (highRange[i] == 10) {
				MyFile << " " << lowRange[i] << " - <" << highRange[i] << setw(6) << " | ";
			}
			else if (highRange[i] != 100) {
				MyFile << lowRange[i] << " - <" << highRange[i] << setw(4) << " | ";
			}
			else {
				MyFile << lowRange[i] << " - " << highRange[i] << setw(4) << " | ";
			}

			for (int numofStars = 0; numofStars < starCount[i]; numofStars++){
				MyFile << "*"; // to display the number of values within a range
			}

		MyFile << endl;
		}
	//to export the range and the frequency to a HTML file
	exportHistogram(subjectName, lowRange, highRange, starCount);
	
	return;    
}


/*******************************************************************************
Programmer    :	1) Nurul Izzah Binti Shahrin
                2) Ali Imran Bin Shahrin
Name          : meanAboveBelow

task          :	This function displays the the values of Average, above average 
                and below average of the chosen file
data in       : Column num, Row num, All data values, Column name, Choice of user input.
data returned : None
Referred to   : None
********************************************************************************/

void meanAboveBelow(int columnNum, int rowNum, vector <vector<double>> allRows, vector<string>columnNames,int& calculate)
{
  //initialize mean, total, temp, j, aboveMean, belowMean,
  //storeAbove, storeBelow, ID
  double mean = 0, total = 0, temp = 0;
  int j = calculate;
  vector<double> aboveMean;
  vector<double> belowMean;
  vector<double> storeAbove,storeBelow;
  vector<double> ID;

  j = j + 1;

  //Sums up total
  for (int i = 0; i < rowNum; i++)
  {
    total = total + allRows[i][j];
  }

  //Calculates Mean
  mean = total / rowNum;

  //Compares values of the data and inserts into vector belowMean if it is lower than average
  //and inserts into vector aboveMean if it is above than average
  for (int i = 0; i < rowNum; i++)
  {
    if (allRows[i][j] < mean)
      belowMean.push_back(allRows[i][j]);
    else
      aboveMean.push_back(allRows[i][j]); 
  }

  //Insert values into vector ID
  for(int i =0 ,j=0; i <belowMean[i];i++)
  {
    ID.push_back(allRows[i][j]);
  }

  string subjectName = columnNames[j];

  //Creates txt file for data to be stored
  cout << setprecision(2) << fixed;
  cout << endl << subjectName << " Average: " << mean << endl << endl;

	string textFileName = subjectName + "MeanAboveBelow" + ".txt";
	ofstream MyFile(textFileName);
	MyFile << "Subject: " << setw(5) << subjectName << endl;
	MyFile << "----------------------------------\n";    
  MyFile << "ID"<<setw(30)<<"Below Mean"<<endl;

  //Prints data in tabular form for below mean
  cout<< "ID"<<setw(19)<<"Below Mean"<< endl;
  cout << "-------------------------" << endl;
  for (int i = 0, j = 0; i < belowMean.size(); i++)
    {
    cout << setprecision(0) << fixed << allRows[i][j] << " | " << setprecision(2) << fixed << belowMean[i] << endl << endl;
    MyFile <<setprecision(0) << fixed << allRows[i][j]<<setw(20) << setprecision(2) << fixed << belowMean[i]<<endl;
    storeBelow.push_back(belowMean[i]);
    }

  MyFile << "----------------------------------\n";
  MyFile << "ID"<<setw(30)<<"Above Mean"<<endl;

  //Prints data in tabular form for below mean
  cout<< "ID"<<setw(19)<<"Above Mean" << endl;
  cout << "-------------------------" << endl;
  for (int i = 0, j = 0; i < aboveMean.size(); i++)
    {
    cout << fixed << setprecision(0) << allRows[i][j] << " | " << setprecision(2) << fixed << aboveMean[i] << endl << endl;
    MyFile << fixed << setprecision(0) << allRows[i][j] <<setw(20) <<  setprecision(2) << fixed << aboveMean[i]<<endl;
    storeAbove.push_back(aboveMean[i]);
    }
    MyFile << "----------------------------------\n";
  
  cout << "Data has been exported. ";
  
  exportMeanAboveBelow(subjectName,ID,belowMean,aboveMean,mean);

  return;
}


/****************************************************************************************
Programmer    :	1) Nurul Izzah Binti Shahrin
                2) Nur Arina Nabihah Binti Muhammad Nadzri
Name          : sortData

task          :	Sorts the data in ascending order or descending order
data in       : Column num, Row num, All data values, Column name, the choice of subject
data returned :	None
Referred to   : 1) Lecturer's lecture class exercise (swap function)
                2) https://www.w3schools.com/html/tryit.asp?filename=tryhtml_table_basic
****************************************************************************************/

void sortData(int columnNum, int rowNum, vector <vector<double>> allRows, vector<string>columnNames,int& calculate)
{
  //Value initialization
  int j = calculate + 1, choice = 0; 
  double temp1 = 0, temp2 = 0;
  vector <double> asc; 
  vector <double> desc;
  vector <int> ID;

  //Asks user if they want to sort data in ascending order or descending order
  cout << "Which order do you want the data to be in?" << endl << endl;
  cout << "1. Ascending" << endl;
  cout << "2. Descending" << endl << endl;

  choice = takeChoice("Enter an integer choice",1,2);

  //Displays "Invalid Number" if user inputs invalid input
  while (choice < 1 || choice > 2) 
  {
    cout << "Invalid Number" << endl;
    choice = takeChoice("Enter an integer choice",1,2);
  }

  //Insert the values into vector ID
  for (int i = 0, j = 0; i < rowNum; i++)
    {
      temp1 = allRows[i][j];
      ID.push_back(temp1);
    }

  //Sort values in ascending order
  if (choice == 1)
  {
    //Insert the values into a new vector
    for (int i = 0; i < rowNum; i++)
    {
      temp1 = allRows[i][j];
      asc.push_back(temp1);
    }
      
    //Sorts the asc vector and ID vector
    for (int i = 0; i < rowNum; i++)
    {
      for (int j = i+1; j < rowNum; j++)
      {
        if (asc[i] > asc[j])
        {
          temp1 = asc[i];
          asc[i] = asc[j];
          asc[j] = temp1;

          temp2 = ID[i];
          ID[i] = ID[j];
          ID[j] = temp2;
        }
      }
    }

    cout << "================================\n";
    cout << "Subject: " << columnNames[j] << endl;
    cout << "================================" << endl;
    
    //Prints out the values in the ID vector and asc vector
    for (int i = 0, j = 0; i < asc.size(); i++)
    {
      cout << fixed << setprecision(2);
      cout << ID[i] << " | " << asc[i]<< endl << endl;
    }
    cout << "The data is sorted in Ascending Order.\n" << endl;
    cout << "Data has been exported. ";
  }
  //Sorts the values in descending order
  else if (choice == 2)
  {
    //Insert the values into a new vector
    for (int i = 0; i < rowNum; i++)
    {
      temp1 = allRows[i][j];
      desc.push_back(temp1);
    }
      
    //Sorts the desc vector and ID vector
    for (int i = 0; i < rowNum; i++)
    {
      for (int j = i+1; j < rowNum; j++)
      {
        if (desc[i] < desc[j])
        {
          temp1 = desc[i];
          desc[i] = desc[j];
          desc[j] = temp1;

          temp2 = ID[i];
          ID[i] = ID[j];
          ID[j] = temp2;
        }
      }
    }

    cout << "================================\n";
    cout << "Subject: " << columnNames[j] << endl;
    cout << "================================" << endl;
  
    //Prints out the values in the ID vector and desc vector
    for (int i = 0, j = 0; i < desc.size(); i++)
    {
      cout << fixed << setprecision(2);
      cout << ID[i] << " | " << desc[i]<< endl << endl;
    }
    cout << "The data is sorted in Descending Order.\n" << endl;
	  cout << "Data has been exported. ";
  }

    // to initialize subject name
    string subjectName = columnNames[j];

    // to name the file, for example : "AscendandDescend".txt
    string textFileName = subjectName + "AscendandDescend" + ".txt";

    //to open the file
    ofstream MyFile(textFileName);

    /////////// CODE IN THE FILE /////////// 

    // to print the first line in the file which is the word "subject" and subject name
    
	  MyFile << "Subject:" << subjectName << endl;

	  MyFile << "----------------------------------\n";

    MyFile << "ID" << setw(11) << "|" << "Marks" << endl;
	 
    if (choice == 1)
    {
      //Displays values of vector asc in the file
      for (int i = 0; i < asc.size(); i++) 
      {
        MyFile << fixed << setprecision(0) << setw(12) << left << ID[i] << "|";
        MyFile << fixed << setprecision(2) << asc[i] << endl;
      }
      
    MyFile << "\nThis data is sorted in Ascending Order.";
    }
    else if (choice == 2)
    {
      //Displays values of vector desc in the file
      for (int i = 0; i < desc.size(); i++) 
      {
        MyFile << fixed << setprecision(0) << setw(12) << left << ID[i] << "|";
        MyFile << fixed << setprecision(2) << desc[i] << endl;
      }
      
    MyFile << "\nThis data is sorted in Descending Order.";
	  }

    //calls the function exportSortData
     exportSortData(subjectName, choice, ID, asc,desc);
  return;
}


/*******************************************************************************
Programmer    :	1) Nur Arina Nabihah Binti Muhammad Nadzri
                2) Nurul Izzah Binti Shahrin
Name          : exportSortData

task          : To export the sorted data according to the user choice to a HTML file.
data in       : Subject name, the choice value, the values of ID, the values of ascending,the value of decending
                the values of desc.
data returned :	None
Referred to   : None
********************************************************************************/

void exportSortData(string subjectName, int choice, vector<int>ID, vector<double> asc, vector<double> desc) 
{ 
  //starting html
	ofstream myfile;

  string createFile = subjectName + "AscendandDescend" + ".html";
  myfile.open(createFile);
	
  myfile << "<!DOCTYPE html><html><head><style> table, th, td {border: 1px solid black;}</style></head><body>" << endl;
  myfile << "<h1>" << "Subject:" << setw(10) << subjectName << "</h1>";
  //header of the code 
	myfile << "<table style=" << "'width:50'>" << endl;

  myfile << "<tr>" << endl;
  myfile << "<th>ID</th>";
  myfile << "<th>Marks</th>";
	myfile << "</tr>" << endl;

  //values in ascending
  for(int i = 0; i < asc.size();i++)
  {
    myfile << "<tr>"<<endl;
    myfile << "<td>" <<setprecision(10)<< ID[i] << "</td>";
    myfile << "<td>" << asc[i]<< "</td>";
    myfile << "</tr>"<<endl;
  }

  //values in descending
  for(int i = 0; i < desc.size();i++)
  {
    myfile << "<tr>"<<endl;
    myfile << "<td>" <<setprecision(10)<< ID[i] << "</td>";
    myfile << "<td>" << desc[i]<< "</td>";
    myfile << "</tr>"<<endl;
  }

  myfile << "</table>";
  myfile << "</body>";
  
  return;
}


/*******************************************************************************
Programmer    :	Nur Arina Nabihah Binti Muhammad Nadzri //
                Deivashree A/P Selva Rajoo //
                Ali Imran Bin Shahrin
Name          : fullstatsReport

task          :	Display min,max,mean,median,standard deviation,variance for the user chosen subject
data in       : Column num, Row num, All data values, Column name, Subject column
data returned :	None
Referred to   : None
********************************************************************************/

void fullstatsReport (int columnNum, int rowNum, vector <vector<double>> allRows, vector<string>columnNames,int subCol){  
  //Value initialization and declare
  valuesComputation.clear();
  bool valid_input = false; 
  do {
    int a = 1;
    int subCol = columnNum - 2;
    int choice;
    int allSubject = subCol + 2;
    
    cout<<"=============================\nFull Stats Report \n=============================\n";
    
    cout << "Choose the subject to full statistical report\n" << endl;

    //Display the option to choose number
    for (int b = 2; a<= subCol && b <=allSubject-1; a++, b++)
    { cout << a << "." << columnNames[b] << endl;}
      cout << "0.Back to main menu" << endl;
    
    choice = takeChoice("Enter an integer choice: ",0,a);

    //When the number is not in the range of 1 to a, it outputs error
    if (choice != 1 && choice != a)
    {
      if (allRows.empty()) 
      {
        cout << "\nError! Data is not found." << endl;
        cout << "Please press enter to continue." << endl;
        cin.get();
        system("cls");
        break; 
      } 
    }
    //When the user input 0, it takes the user back to main menu
    if (choice == 0)
    {
      valid_input = true;
      mainmenu(allRows,columnNum,rowNum,columnNames);
      break;     
    }
  //When the number is in range,it output the choice 	
  else if (choice > 0 && choice <= subCol) 
  {
    cout <<endl << "=============================" << endl; 
    cout << columnNames[choice + 1] << endl;
    cout << "=============================" << endl;
    valid_input = true;

    // to get min, max, mean, median, standard deviation, variance values
    calculateMin(columnNum,rowNum,allRows,columnNames,choice);
    calculateMax(columnNum,rowNum,allRows,columnNames,choice);
    calculateMean(columnNum,rowNum,allRows,columnNames,choice);
    calculateMedian(columnNum,rowNum,allRows,columnNames,choice);
    standardDeviation(columnNum,rowNum,allRows,columnNames,choice);
    calculateVariance(columnNum,rowNum,allRows,columnNames,choice);

      system("cls");
    
    //Display statistical report for the subject
    string subjectName = columnNames[choice+1];
    cout << left << setw(26) << "Subject" << subjectName << endl;
    cout << "--------------------------------------" << endl;
      for(int i = 0; i < valuesComputation.size(); i++)
      {
      cout << left << setw(20) << computationNames[i]  << "  |  "  << valuesComputation[i] << endl;
      }
      cout << "--------------------------------------" << endl;
    cout << endl;
    cout << "Data has been exported. ";

    // to store the calculated values: min, max, etc
    vector <double> output = valuesComputation;
    // to name the file, for example : ScienceFullStatsReport.txt
    string textFileName = subjectName + "FullStatsReport" + ".txt";

    //to open the file
    ofstream MyFile(textFileName);

    /////////// CODE IN THE FILE /////////// 

    // to print the first line in the file which is the word "subject" and subject name
    MyFile << "Subject" << setw(16) << "|" << subjectName << endl;

    MyFile << "----------------------------------\n";
    
    for (int i = 0; i < output.size(); i++) {
      // to print the name of the computation such as  min,max,etc
      MyFile << setw(22) << left << computationNames[i] <<  "|";
      // to print the values of min,max,etc
      MyFile << output[i] << endl;
    }

      exportFullStats(subjectName,output); // to export the computations values to a HTML file
      valuesComputation.clear(); // clear to prevent data from repeatedly being stored
    break;                        
    }		
  } while(valid_input == false);

	cout << "Please press enter to proceed.";
 	cin.get();
	system("cls");

  return;
}