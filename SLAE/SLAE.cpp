#include <iostream>
#include "Log.h"
#include "Matrix.h"
#include <ctime>
#include <chrono>




void testLog()
{
	Log& log = Log::createLog();

	Matrix A3("A3.txt");
	Matrix A4("A4.txt");
	Matrix A5("A5.txt");
	Matrix A6("A6.txt");
	Matrix A7("A7.txt");
	Matrix A8("A8.txt");
	Matrix A9("A9.txt");
	Matrix A10("A10.txt");
	Matrix A11("A11.txt");
	Matrix b3("b3.txt");
	Matrix b4("b4.txt");
	Matrix b5("b5.txt");
	Matrix b6("b6.txt");
	Matrix b7("b7.txt");
	Matrix b8("b8.txt");
	Matrix b9("b9.txt");
	Matrix b10("b10.txt");
	Matrix b11("b11.txt");

	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
	std::chrono::duration<double> sec = end - start;

	start = std::chrono::system_clock::now();
	solveSLAE(A3, b3);
	end = std::chrono::system_clock::now();
	sec = end - start;
	log << "Size 3:  " << sec.count() << " Sec" << '\n';

	start = std::chrono::system_clock::now();
	solveSLAE(A4, b4);
	end = std::chrono::system_clock::now();
	sec = end - start;
	log << "Size 4:  " << sec.count() << " Sec" << '\n';

	start = std::chrono::system_clock::now();
	solveSLAE(A5, b5);
	end = std::chrono::system_clock::now();
	sec = end - start;
	log << "Size 5:  " << sec.count() << " Sec" << '\n';

	start = std::chrono::system_clock::now();
	solveSLAE(A6, b6);
	end = std::chrono::system_clock::now();
	sec = end - start;
	log << "Size 6:  " << sec.count() << " Sec" << '\n';

	start = std::chrono::system_clock::now();
	solveSLAE(A7, b7);
	end = std::chrono::system_clock::now();
	sec = end - start;
	log << "Size 7:  " << sec.count() << " Sec" << '\n';

	start = std::chrono::system_clock::now();
	solveSLAE(A8, b8);
	end = std::chrono::system_clock::now();
	sec = end - start;
	log << "Size 8:  " << sec.count() << " Sec" << '\n';

	start = std::chrono::system_clock::now();
	solveSLAE(A9, b9);
	end = std::chrono::system_clock::now();
	sec = end - start;
	log << "Size 9:  " << sec.count() << " Sec" << '\n';

	start = std::chrono::system_clock::now();
	solveSLAE(A10, b10);
	end = std::chrono::system_clock::now();
	sec = end - start;
	log << "Size 10:  " << sec.count() << " Sec" << '\n';

	start = std::chrono::system_clock::now();
	solveSLAE(A11, b11);
	end = std::chrono::system_clock::now();
	sec = end - start;
	log << "Size 11:  " << sec.count() << " Sec" << '\n';

	Log::deleteLog();
}



void testCout()
{

	Matrix A3("A3.txt");
	Matrix A4("A4.txt");
	Matrix A5("A5.txt");
	Matrix A6("A6.txt");
	Matrix A7("A7.txt");
	Matrix A8("A8.txt");
	Matrix A9("A9.txt");
	Matrix A10("A10.txt");
	Matrix A11("A11.txt");
	Matrix b3("b3.txt");
	Matrix b4("b4.txt");
	Matrix b5("b5.txt");
	Matrix b6("b6.txt");
	Matrix b7("b7.txt");
	Matrix b8("b8.txt");
	Matrix b9("b9.txt");
	Matrix b10("b10.txt");
	Matrix b11("b11.txt");

	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
	std::chrono::duration<double> sec = end - start;

	start = std::chrono::system_clock::now();
	solveSLAE(A3, b3);
	end = std::chrono::system_clock::now();
	sec = end - start;
	std::cout << "Size 3:  " << sec.count() << " Sec" << '\n';

	start = std::chrono::system_clock::now();
	solveSLAE(A4, b4);
	end = std::chrono::system_clock::now();
	sec = end - start;
	std::cout << "Size 4:  " << sec.count() << " Sec" << '\n';

	start = std::chrono::system_clock::now();
	solveSLAE(A5, b5);
	end = std::chrono::system_clock::now();
	sec = end - start;
	std::cout << "Size 5:  " << sec.count() << " Sec" << '\n';

	start = std::chrono::system_clock::now();
	solveSLAE(A6, b6);
	end = std::chrono::system_clock::now();
	sec = end - start;
	std::cout << "Size 6:  " << sec.count() << " Sec" << '\n';

	start = std::chrono::system_clock::now();
	solveSLAE(A7, b7);
	end = std::chrono::system_clock::now();
	sec = end - start;
	std::cout << "Size 7:  " << sec.count() << " Sec" << '\n';

	start = std::chrono::system_clock::now();
	solveSLAE(A8, b8);
	end = std::chrono::system_clock::now();
	sec = end - start;
	std::cout << "Size 8:  " << sec.count() << " Sec" << '\n';

	start = std::chrono::system_clock::now();
	solveSLAE(A9, b9);
	end = std::chrono::system_clock::now();
	sec = end - start;
	std::cout << "Size 9:  " << sec.count() << " Sec" << '\n';

	start = std::chrono::system_clock::now();
	solveSLAE(A10, b10);
	end = std::chrono::system_clock::now();
	sec = end - start;
	std::cout << "Size 10:  " << sec.count() << " Sec" << '\n';

	start = std::chrono::system_clock::now();
	solveSLAE(A11, b11);
	end = std::chrono::system_clock::now();
	sec = end - start;
	std::cout << "Size 11:  " << sec.count() << " Sec" << '\n';

}











int main()
{
	testLog();
}
