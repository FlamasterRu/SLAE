#pragma once
#include <iostream>
#include <mutex>






int pow(const int b);		// (-1)^(b) возвращает +1 или -1 для расчёта определителя матрицы

void createRandMatrix(const int height, const int width, std::string fileName);		// создаёт матрицу со случайными значениями от -30 до +30 и записывает в файл,
// который помещается в ту же папку, что и проект



class Matrix
{
private:
	double** m_arr;
	int m_width;
	int m_height;



public:

	static std::mutex mtx;

	Matrix(const int width = 1, const int height = 1);
	Matrix(const std::string fileName);
	Matrix(const std::string fileName, const int width, const int height);
	Matrix(const Matrix& m);
	Matrix(const Matrix& m, const int line, const int col);		// строит матрицу из матрицы m, вырезая строку line и столбец col
	Matrix(Matrix&& m) noexcept;

	~Matrix();


	Matrix& operator= (const Matrix& m);
	Matrix& operator= (Matrix&& m) noexcept;
	friend std::ostream& operator<< (std::ostream& out, const Matrix& m);		// позволяет вывести матрицу в консоль через cout
	double& operator() (const int line, const int col) const;


	Matrix changeOneColumn(const Matrix& col, const int numCol) const;			// возвращает матрицу, в которой заменён столбец с номером numCol
	int getHeight() const;
	int getWidth() const;


	friend double countDet(const Matrix& m);		// рассчитывает определитель, всё в одном потоке
	friend Matrix solveSLAE(const Matrix& a, const Matrix& b);		// возвращает решение слау, использует многопоточность

};


Matrix createRandMatrix(const int height, const int width);		// возвращает матрицу со случайными значениями от -20 до +20, работает минимум 1 секунду!

bool checkSolution(Matrix& A, Matrix& b, Matrix& x);		// проверяет решение слау



double countDetThreads(const Matrix m);		// рассчитывает определитель используя многопоточность






