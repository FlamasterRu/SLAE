#pragma once
#include <iostream>
#include <mutex>






int pow(const int b);		// (-1)^(b) ���������� +1 ��� -1 ��� ������� ������������ �������

void createRandMatrix(const int height, const int width, std::string fileName);		// ������ ������� �� ���������� ���������� �� -30 �� +30 � ���������� � ����,
// ������� ���������� � �� �� �����, ��� � ������



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
	Matrix(const Matrix& m, const int line, const int col);		// ������ ������� �� ������� m, ������� ������ line � ������� col
	Matrix(Matrix&& m) noexcept;

	~Matrix();


	Matrix& operator= (const Matrix& m);
	Matrix& operator= (Matrix&& m) noexcept;
	friend std::ostream& operator<< (std::ostream& out, const Matrix& m);		// ��������� ������� ������� � ������� ����� cout
	double& operator() (const int line, const int col) const;


	Matrix changeOneColumn(const Matrix& col, const int numCol) const;			// ���������� �������, � ������� ������ ������� � ������� numCol
	int getHeight() const;
	int getWidth() const;


	friend double countDet(const Matrix& m);		// ������������ ������������, �� � ����� ������
	friend Matrix solveSLAE(const Matrix& a, const Matrix& b);		// ���������� ������� ����, ���������� ���������������

};


Matrix createRandMatrix(const int height, const int width);		// ���������� ������� �� ���������� ���������� �� -20 �� +20, �������� ������� 1 �������!

bool checkSolution(Matrix& A, Matrix& b, Matrix& x);		// ��������� ������� ����



double countDetThreads(const Matrix m);		// ������������ ������������ ��������� ���������������






