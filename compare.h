using namespace std;

/*******************************************************************************
Programmer    :	Ali Imran Bin Shahrin
Name          : calcCompare

task          :	Compare the values between two subjects and outputs a table with their respective calculations
data in       : Data from All Rows, Column Number , Row Number , Column Names , Choice of subject 1, Choice of Subject Number two
data returned :	None
Referred to   : 1) https://www.statsdirect.com/help/regression_and_correlation/simple_linear.html
                2) https://www.statisticshowto.com/probability-and-statistics/correlation-coefficient-formula/

********************************************************************************/
void calcCompare(vector <vector<double>> allRows, int columnNum, int rowNum,vector<string> columnNames,int choice1, int choice2){

	int ch1 = choice1+1;
	int ch2 = choice2+1; 
	vector<string> compareHeader = {"ID","X","Y","XY","X2","Y2"};

	cout << endl;

	cout << right << setw(5) << compareHeader.at(0);

	for(int i = 1; i!=compareHeader.size();i++)
	{
		cout << setw(14) << compareHeader.at(i);
	}
	cout<<endl;

	cout<<"---------------------------------------------------------------------------------"<<endl;
	cout << right << setw(36) << columnNames[ch1] << " VS " << columnNames[ch2] <<endl; 
	cout<<"---------------------------------------------------------------------------------"<<endl;

	///////// FROM DOUBLE TO STRING //////////
	dataString(columnNames, allRows,ch1,ch2);

	calculatePearsonLinear(allRows,columnNum,rowNum,columnNames,choice1,choice2);

  cout << "Please press enter to proceed.";
  cin.get();
	system("cls");
  mainmenu(allRows,columnNum,rowNum,columnNames);

	return;
}

/****************************************************************************************
Programmer    :	1) Nur Arina Nabihah binti Muhammad Nadzri 
                2) Nurul Izzah Binti Shahrin
Name          : calculatePearsonLinear

task          :	Calculates the Pearson's Formula and Linear Regression Formula of the data and
                displays table for the data values.
data in       : All data values, Column num, Row num, Column name, Choice of subject 1, Choice of subject 2
data returned :	None
Referred to   : https://www.questionpro.com/blog/pearson-correlation-coefficient/
*****************************************************************************************/

void calculatePearsonLinear (vector <vector<double>> allRows, int columnNum, int rowNum, vector<string> columnNames,int choice1, int choice2) 
{
	
	//Value initialization
	double r,a,b;
	double totalx,totaly,totalxy,totalx2,totaly2, dataID;
	vector<double> data ={};
	vector<double> valuesofX = {};
	vector<double> valuesofY = {};
	vector<double> valuesofXY = {};
	vector<double> valuesofX2 = {};
	vector<double> valuesofY2 = {};
  
	int ch1 = choice1+1;
	int ch2 = choice2+1;

  cout<<endl;
  cout<<"---------------------------------------------------------------------------------"<< endl;

  // table values calculation for x and y
	for(int i =0; i<rowNum; i++)
	{
		totalx += allRows[i][ch1];
	}
	data.push_back(totalx);
	
	for(int i =0; i<rowNum; i ++)
	{
		totaly += allRows[i][ch2];
	}
	data.push_back(totaly);
	
	for(int i =0; i<rowNum; i ++)
	{
		totalxy += (allRows[i][ch1])*(allRows[i][ch2]);
	}
	data.push_back(totalxy);
	
	for(int i =0; i<rowNum; i ++)
	{
		totalx2 += (allRows[i][ch1])*(allRows[i][ch1]);
	}
	data.push_back(totalx2);
	
	for(int i =0; i<rowNum; i ++)
	{
		totaly2 += (allRows[i][ch2])*(allRows[i][ch2]);
	}
	data.push_back(totaly2);
  
	// output of the total calculation of x and y values
	cout << setprecision(2)<<fixed <<setw(10) <<"Total: "<< setw(12)<< data.at(0) << setw(12)<< data.at(1) <<setw(12)<<data.at(2)<< setw(12)<<data.at(3)<<setw(12)<< data.at(4);


	//Pearson's Formula output and calculation
	cout<<endl<<"---------------------------------------------------------------------------------"<< endl;

	cout << "==========================" << endl << "Pearson's correlation" << endl << "==========================" << endl<< endl;
	r = ((rowNum * totalxy) - (totalx * totaly)) / sqrt(((rowNum * totalx2) - (totalx * totalx)) * ((rowNum * totaly2) - (totaly * totaly)));
 
	//to change r value from double to string for display
	string outputR = to_string(r);

  cout << "r = " << "((" << rowNum << "*" << totalxy << ") - (" << totalx << "*" <<  totaly << "))" << endl << setw(5) <<"/" << "sqrt " << "((" << rowNum << "*" << totalx2  << " - " << totalx << "*" << totalx << ")) * ((" << rowNum << "*" << totaly2 << ") - (" << totaly << "*" << totaly << "))" << endl << "  = " << outputR <<endl << endl;
  
  // Linear Regression Formula output and calculation
	cout << "=========================="<<endl<< "Linear regression"<<endl<< "==========================" << endl;
  a = ((totaly * totalx2) - (totalx * totalxy)) / ((rowNum * totalx2) - (totalx * totalx));
   
 	b = ((rowNum * totalxy) - (totalx * totaly)) /  ((rowNum * totalx2) - (totalx * totalx));
   
  //to change a and b value from double to string for display
	string outputA = to_string(a); 
	string outputB = to_string(b);
 
	cout << "a = " << "((" << totaly << "*" << totalx2 << ") - ("<< totalx << "*" <<  totalxy << ")) / ((" << rowNum << "*" << totalx2 << ") - (" << totalx << "*" <<  totalx << "))" <<endl <<"  = " << outputA <<endl;
  
	cout << "b = " << "((" << rowNum << "*" << totalxy << ") - (" << totalx << "*" <<  totaly << ")) / ((" << rowNum << "*" << totalx2 << ") - (" << totalx << "*" <<  totalx << "))" << endl<<"  = " << outputB <<endl;

  cout << "y'= " << outputA << " + " << outputB << "x" << endl<< endl; 

	cout << "Data has been exported. ";
  /////////CALCULATION OF PEARSON & LINEAR ENDS/////////

  //////////// EXPORT COMPARE AND PEARSON LINEAR/////////

 	// to initialize subject name
	string subject1 = columnNames[ch1];
  string subject2 = columnNames[ch2];
  
	// to store the calculated values: min, max, etc
	vector <double> output = valuesCompare;

	// to name the file, for example : ScienceFullStatsReport.txt
	string textFileName = subject1 + subject2 + "CompareandPearsonLinear" + ".txt";

	//to open the file
	ofstream MyFile(textFileName);

	/////////// CODE IN THE FILE /////////// 

	// to print the first line in the file which is the word "subject" and subject name
	MyFile << setw(20) << subject1 << setw(25) << "vs" << setw(25) <<  subject2 << setw(14) << endl;

	MyFile << "-----------------------------------------------------------------------------------------\n";
	 
  MyFile << setw(8) << "ID" << setw(15) << "X" << setw(15) << "Y" << setw(15) << "XY" << setw(15) << "X2" << setw(15) << "Y2" << endl;

  MyFile << setw(10) << "----------" << setw(15) << "---------------" << setw(15) << "---------------" << setw(15) << "---------------" << setw(15) << "----------------------------------" << endl << endl;


  //Insert values of total into vectors
	for(int i =0; i < rowNum; i++)
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

  //Print out the values
	for (int i = 0, j = 0; i < valuesofX.size(); i++) 
  {  
    MyFile << fixed << setprecision(0) << setw(10) << right << allRows[i][j];
	  MyFile << fixed << setprecision(2);
    MyFile << setw(15) << right << valuesofX[i]
           << setw(15) << right << valuesofY[i]
           << setw(15) << right << valuesofXY[i]
           << setw(15) << right << valuesofX2[i]
           << setw(15) << right << valuesofY2[i]
           <<endl;
	}

  MyFile << "------------------------------------------------------------------------------------------\n";
  //print total
  MyFile <<setprecision(2) << fixed << setw(9) <<"Total: "<< setw(16)<< data.at(0) << setw(15)<< data.at(1) <<setw(15)<<data.at(2)<< setw(15)<<data.at(3)<<setw(15)<< data.at(4) << endl;
  MyFile << "------------------------------------------------------------------------------------------\n";

  MyFile << "\n\n==========================" << endl << "Pearson's correlation" << endl << "==========================" << endl<< endl;

  //print pearson 
  MyFile << "r = " << "((" << rowNum << "*" << data.at(2) << ") - (" << data.at(0) << "*" <<  data.at(1) << "))" << endl << setw(5) <<"/" << "sqrt " << "((" << rowNum << "*" << data.at(3)  << ") - (" << data.at(0) << "*" << data.at(0) << ")) * ((" << rowNum << "*" << data.at(4) << ") - (" << data.at(1) << "*" << data.at(1) << "))" << endl << "  = " << outputR <<endl << endl;


  MyFile << "=========================="<<endl<< "Linear regression"<<endl<< "==========================" << endl;
  //print linear
	MyFile << "a = " << "((" << data.at(1) << "*" << data.at(3) << ") - ("<< data.at(0) << "*" <<  data.at(2) << ")) / ((" << rowNum << "*" << data.at(3) << ") - (" << data.at(0) << "*" <<  data.at(0) << "))" <<endl <<"  = " << outputA <<endl;

	MyFile << "b = " << "((" << rowNum << "*" << data.at(2) << ") - ("<< data.at(0) << "*" <<  data.at(1) << ")) / ((" << rowNum << "*" << data.at(3) << ") - (" << data.at(0) << "*" <<  data.at(0) << "))" << endl<<"  = " << outputB <<endl;

  MyFile << "y'= " << outputA << " + " << outputB << "x" << endl<< endl;

  //calls the function exportCompareandPearsonLinear
  exportCompareandPearsonLinear(subject1, subject2, rowNum, allRows, ch1, ch2, outputR, outputA, outputB, totalx, totaly, totalxy, totalx2, totaly2, valuesofX, valuesofY, valuesofXY, valuesofX2, valuesofY2, columnNames, data);
  
  return;
}



/*******************************************************************************
Programmer    :	Deivashree A/P Selva Rajoo
Name          : dataString

task          :	Converts from double value to string to output the total values for X and Y in compare data 
data in       : Column Names, Data from the user chosen file, Choice of Subject 1, Choice of Subject 2 
data returned :	None
Referred to   : None
********************************************************************************/
void dataString(vector<string> columnNames, vector <vector<double>> allRows,int choice1, int choice2) {

	int ch1 = choice1;
	int ch2 = choice2; 
	int i, j = 0;

	for(int i = 0;i != allRows.size();i++){

		if (j == 0) {
		double ID = allRows[i][0]; 
		
		ostringstream streamObj; // change the ID from double to string
 		streamObj << fixed << setprecision(0) << setw(9) << left;
		streamObj << ID; // stores in string stream
		string strObj = streamObj.str();	
		cout << strObj; // prints out the ID
		}

		double x = allRows[i][ch1];
		double y = allRows[i][ch2]; 
		double xy = (allRows[i][ch1])*(allRows[i][ch2]); 
		double x2 = (allRows[i][ch1])*(allRows[i][ch1]); 
		double y2 = (allRows[i][ch2])*(allRows[i][ch2]); 
		
		ostringstream streamObj; // change the x,y,xy,x2,y2 values from double to string
		streamObj << fixed << setprecision(2);
		// stores in string stream
		streamObj << setw(13) << right << x << setw(14) << right << y << setw(14) << right << xy << setw(14) << right << x2 << setw(14) << right << y2;
		string strObj = streamObj.str();	
		cout << strObj; // prints out the values
		cout << endl;
	}
	return; 
}