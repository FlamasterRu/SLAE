#pragma once
#include <iostream>
#include <mutex>






int pow(const int b);

void createRandMatrix(const int height, const int width, std::string fileName);



class Matrix
{
private:
	double** m_arr;
	int m_width;
	int m_height;



public:

	static std::mutex mtx;

	Matrix(const int width = 1, const int height = 1);		//+++++
	Matrix(const std::string fileName);		//+++++
	Matrix(const std::string fileName, const int width, const int height);		//+++++
	Matrix(const Matrix& m);		//+++++
	Matrix(const Matrix& m, const int line, const int col);		//+++++
	Matrix(Matrix&& m) noexcept; 		//

	~Matrix();


	Matrix& operator= (const Matrix& m);		//+++++
	Matrix& operator= (Matrix&& m) noexcept;		//
	friend std::ostream& operator<< (std::ostream& out, const Matrix& m);		//+++++
	double& operator() (const int line, const int col);		//+++++


	Matrix changeOneColumn(const Matrix& col, const int numCol) const;		//+++++


	friend double countDet(const Matrix& m);		//+++++
	friend Matrix solveSLAE(const Matrix& a, const Matrix& b);		//+++++

};












