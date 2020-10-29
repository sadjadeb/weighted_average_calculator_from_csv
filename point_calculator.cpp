#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>

#define ROW_NUMBER 40
#define MAX_POINT 4
#define FACTOR_NUMBER 10

#define FACTOR1  0.002
#define FACTOR2  0.001
#define FACTOR3  0.0005
#define FACTOR4  0.001
#define FACTOR5  0.0015
#define FACTOR6  0.001
#define FACTOR7  0.0005
#define FACTOR8  0.001
#define FACTOR9  0.0005
#define FACTOR10 0.001

using namespace std;

int main()
{
	long long i=0, j=0, read[ROW_NUMBER][FACTOR_NUMBER+2]; // We create two additional columns to store the first and last name
	string line, word;
	double point[ROW_NUMBER];
	fstream inf, outf;
    inf.open("input.csv", ios::in);
    outf.open("output.csv", ios::out);
    
	for (i = 0;i < ROW_NUMBER; i++)
	{ 
		getline(inf, line); 
        stringstream sin (line); 
		for (j = 0; j < FACTOR_NUMBER; j++)
		{
			getline(sin, word, ',');
			istringstream(word) >> read[i][j];
		}
    }
    for(i = 1;i < ROW_NUMBER;i++)
	{
		// start from third column because first and second column stored name and lastname
		point[i] = (FACTOR1 * read[i][2]) + (FACTOR2 * read[i][3]) + (FACTOR3 * read[i][4]) + (FACTOR4 * read[i][5])
					+ (FACTOR5 * read[i][6]) + (FACTOR6 * read[i][7]) + (FACTOR7 * read[i][8]) + (FACTOR8 * read[i][9])
					+(FACTOR9 * read[i][10]) + (FACTOR10 * read[i][11]);
		// multiples score by MAX_POINT to change number in maximum format
		point[i] *= MAX_POINT;
	}
	for(i = 1;i < ROW_NUMBER;i++)
	{
		// writes points both in console and output.csv	
		cout<<i<<"-"<<point[i]<<endl;
		outf<<point[i]<<endl;
	}
	inf.close();
	outf.close();
}
