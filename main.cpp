/* Name: Matthew Matze
 * HPU ID:matzem13
 * Date: 10-27-14
 * Class: CSC2710
 * Location:~/csc2710/main.cpp
 * Description: The program essentially takes a file with a list of edges inside and prints out that in the format for the adjacency list and matrix. 
 */

#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>

using namespace std;

void matrixfun(int ,ofstream& ,ifstream&);
void listfun(int, ofstream& ,ifstream&);
/* Inputs and Outputs:
 *	The function doesn't have any direct inputs or outputs but it needs have the input data file in the correct format in order for the program to work properly.Once the function is complete there will be two files which are the adjacency list and adjcency matrix format of the original input edge list file.
 *
 */ 
int main(void)
{
	string filename;
	ifstream datafile;
	ifstream datamatrix;		//Initialze the variables
	ofstream listfile;
	ofstream matrixfile;
	int n;

	cout<<"Please enter a valid file\n";
	cin>>filename;				//enter the name of the input file
	datafile.open(filename.c_str());
	while(!datafile){
		cout<<"Please enter a valid file\n";	//if not a valid input file then ask again
		cin>>filename;
	}
	string listname	=filename+"-adj-list";
	string matrixname= filename+"-adj-matrix";	//format the name of the file correctly

	datafile>>n;	
	matrixfile.open(matrixname.c_str());	//open the output file
	matrixfun(n,matrixfile,datafile);	//call the function
	matrixfile.close();			//close the file

	datamatrix.open(matrixname.c_str());	//Open the matrix file for the list function
	listfile.open(listname.c_str());	//Open the output list file
	listfun(n,listfile,datamatrix);		//Call the list function
	return 0;
}
/*Inputs and Outputs:
 * 	The function takes in the length of the matrix n, the outputfile for the matrix matrixfile, and the input file datafile. There are no outputs to which the function returns although the function does change the matrixfile to look correct. 
 *
 */
void matrixfun(int n,ofstream& matrixfile, ifstream& datafile){
	bool matrix[n][n];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				matrix[i][j]=0;		// Sets all of the elements in the matrix to 0
			}	
		}
	while(!datafile.eof()){
		int u,v;
		datafile>>u;			//Reads through all of the input file and assigns all of
		datafile>>v;			//the edges to the correct locations in the matrix
		matrix[u][v]=1;
	}
		matrixfile<<n<<"\n";
	for(int i=0;i<n;i++){
		matrixfile<<i<<"	";
		for(int j=0; j<n; j++){			//Outputs the array in the correct formatting 
			matrixfile<<matrix[i][j]<<" ";	// to  the screen
		}
		matrixfile<<"\n";
	}
	return ;
}
/*Inputs and Outputs:
 *	The function takes in the length of the matrix n, the outputfile for the list (listfile), and the input file datamatrix. There are no Outputs to which the function returns but it does change the output file to display the adj list correctly. The datamatrix file needs to be in the correct format before being used in this function.
 *
 */ 
void listfun(int n, ofstream& listfile,ifstream& datamatrix){
	datamatrix>>n;		//Displays the number of vertices
	listfile<<n<<"\n";
	bool edge; 			
	int connect;
	
	for(int i=0;i<n;i++){
		datamatrix>>connect;
		listfile<<i;	//Prints the vertice to listfile 
		for(int j=0;j<n;j++){
			datamatrix>>edge;	//Gets edge from file datamatrix
			if(edge!=0)	//Checks if the edge is connected
				listfile<<" "<<j;    // if the edge is connected then print to listfile
		}
		listfile<<"\n";		//print new line after every line
	}
	return ;
}
