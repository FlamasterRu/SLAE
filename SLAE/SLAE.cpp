#include <iostream>
#include "Log.h"
#include "Matrix.h"











int main()
{
	Log &log = Log::createLog();
	Matrix A1("A1.txt");
	Matrix A2("A2.txt");
	Matrix A3("A3.txt");
	Matrix b3("b3.txt");
	Matrix m1("m1.txt");
	Matrix m2("m2.txt");
	Matrix m3("m3.txt");

	std::cout << A1 << std::endl << A2 << std::endl << A3 << std::endl << b3 << std::endl << m1 << std::endl << m2 << std::endl << m3 << std::endl;

	//std::ofstream oFile;
	//oFile.open("out.txt");
	//oFile << m1;
	//oFile.close();
















	















	Log::deleteLog();
}
