#include <iostream>
#include "Log.h"
#include "Timer.h"
#include "Matrix.h"


// Системы размерностью до 12 решаются быстро, дальше не имеет смысла ждать
// Для эффективного использования многопоточности стоит Свойства Проекта -> С/С++ -> Оптимизация установить оптимизацию на максимальную
// производительность и использовать режим Release

// Мои замеры времени выполнения в  \SLAE\SLAE\myLog.log   


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
	Matrix A12("A12.txt");
	Matrix b3("b3.txt");
	Matrix b4("b4.txt");
	Matrix b5("b5.txt");
	Matrix b6("b6.txt");
	Matrix b7("b7.txt");
	Matrix b8("b8.txt");
	Matrix b9("b9.txt");
	Matrix b10("b10.txt");
	Matrix b11("b11.txt");
	Matrix b12("b12.txt");

	Timer t;

	t.StartTimer();
	solveSLAE(A3, b3);
	log << "Size 3:  " << t.StopTimer() << '\n';

	t.StartTimer();
	solveSLAE(A4, b4);
	log << "Size 4:  " << t.StopTimer() << '\n';

	t.StartTimer();
	solveSLAE(A5, b5);
	log << "Size 5:  " << t.StopTimer() << '\n';

	t.StartTimer();
	solveSLAE(A6, b6);
	log << "Size 6:  " << t.StopTimer() << '\n';

	t.StartTimer();
	solveSLAE(A7, b7);
	log << "Size 7:  " << t.StopTimer() << '\n';

	t.StartTimer();
	solveSLAE(A8, b8);
	log << "Size 8:  " << t.StopTimer() << '\n';

	t.StartTimer();
	solveSLAE(A9, b9);
	log << "Size 9:  " << t.StopTimer() << '\n';

	t.StartTimer();
	solveSLAE(A10, b10);
	log << "Size 10:  " << t.StopTimer() << '\n';

	t.StartTimer();
	solveSLAE(A11, b11);
	log << "Size 11:  " << t.StopTimer() << '\n';

	t.StartTimer();
	solveSLAE(A12, b12);
	log << "Size 12:  " << t.StopTimer() << '\n';

	log.deleteLog();
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
	Matrix A12("A12.txt");
	Matrix b3("b3.txt");
	Matrix b4("b4.txt");
	Matrix b5("b5.txt");
	Matrix b6("b6.txt");
	Matrix b7("b7.txt");
	Matrix b8("b8.txt");
	Matrix b9("b9.txt");
	Matrix b10("b10.txt");
	Matrix b11("b11.txt");
	Matrix b12("b12.txt");

	Timer t;
	double allTime = 0;
	Matrix x;

	std::cout.setf(std::ios::boolalpha);

	t.StartTimer();
	x = solveSLAE(A3, b3);
	allTime += t.StopTimer();
	std::cout << "Size 3:  " << t.StopTimer() << "    " << checkSolution(A3, b3, x) << std::endl;

	t.StartTimer();
	x = solveSLAE(A4, b4);
	allTime += t.StopTimer();
	std::cout << "Size 4:  " << t.StopTimer() << "    " << checkSolution(A4, b4, x) << std::endl;

	t.StartTimer();
	x = solveSLAE(A5, b5);
	allTime += t.StopTimer();
	std::cout << "Size 5:  " << t.StopTimer() << "    " << checkSolution(A5, b5, x) << std::endl;

	t.StartTimer();
	x = solveSLAE(A6, b6);
	allTime += t.StopTimer();
	std::cout << "Size 6:  " << t.StopTimer() << "    " << checkSolution(A6, b6, x) << std::endl;

	t.StartTimer();
	x = solveSLAE(A7, b7);
	allTime += t.StopTimer();
	std::cout << "Size 7:  " << t.StopTimer() << "    " << checkSolution(A7, b7, x) << std::endl;

	t.StartTimer();
	x = solveSLAE(A8, b8);
	allTime += t.StopTimer();
	std::cout << "Size 8:  " << t.StopTimer() << "    " << checkSolution(A8, b8, x) << std::endl;
	
	t.StartTimer();
	x = solveSLAE(A9, b9);
	allTime += t.StopTimer();
	std::cout << "Size 9:  " << t.StopTimer() << "    " << checkSolution(A9, b9, x) << std::endl;
	
	t.StartTimer();
	x = solveSLAE(A10, b10);
	allTime += t.StopTimer();
	std::cout << "Size 10:  " << t.StopTimer() << "    " << checkSolution(A10, b10, x) << std::endl;

	t.StartTimer();
	x = solveSLAE(A11, b11);
	allTime += t.StopTimer();
	std::cout << "Size 11:  " << t.StopTimer() << "    " << checkSolution(A11, b11, x) << std::endl;

	t.StartTimer();
	x = solveSLAE(A12, b12);
	allTime += t.StopTimer();
	std::cout << "Size 12:  " << t.StopTimer() << "    " << checkSolution(A12, b12, x)  << std::endl;

	std::cout << "All time:    " << allTime << std::endl;

}



void testRand()
{
	Matrix A1(createRandMatrix(8,8));
	Matrix b1(createRandMatrix(8, 1));
	Matrix A2(createRandMatrix(9, 9));
	Matrix b2(createRandMatrix(9, 1));
	Matrix A3(createRandMatrix(10, 10));
	Matrix b3(createRandMatrix(10, 1));
	Matrix A4(createRandMatrix(7, 7));
	Matrix b4(createRandMatrix(7, 1));


	Timer t;
	double allTime = 0;
	Matrix x;

	t.StartTimer();
	x = solveSLAE(A1, b1);
	allTime += t.StopTimer();
	std::cout << "E12:  " << t.StopTimer() << "    " << checkSolution(A1, b1, x) << std::endl;

	t.StartTimer();
	x = solveSLAE(A2, b2);
	allTime += t.StopTimer();
	std::cout << "E13:  " << t.StopTimer() << "    " << checkSolution(A2, b2, x) << std::endl;

	t.StartTimer();
	x = solveSLAE(A3, b3);
	allTime += t.StopTimer();
	std::cout << "E15:  " << t.StopTimer() << "    " << checkSolution(A3, b3, x) << std::endl;	

	t.StartTimer();
	x = solveSLAE(A4, b4);
	allTime += t.StopTimer();
	std::cout << "E17:  " << t.StopTimer() << "    " << checkSolution(A4, b4, x) << std::endl;
	

	std::cout << "All time:    " << allTime << std::endl;
}











int main()
{
	testCout();
}
