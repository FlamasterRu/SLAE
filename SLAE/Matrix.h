#pragma once
#include <iostream>



//double countDet(const Matrix& m);
//Matrix solveSLAE(const Matrix& m);



class Matrix
{
private:
	double** m_arr;
	int m_width;
	int m_height;


public:

	Matrix(const int width = 1, const int height = 1);
	Matrix(const double **arr, const int width, const int height);
	Matrix(const std::string fileName);		//+++++
	Matrix(const std::string fileName, const int width, const int height);
	Matrix(const Matrix& m);

	~Matrix();


	Matrix& operator= (const Matrix& m);
	friend Matrix operator+ (const Matrix& left, const Matrix& right);
	friend bool operator== (const Matrix& left, const Matrix& right);
	Matrix& operator+= (const Matrix& m);
	Matrix& operator- ();
	Matrix& operator-= (const Matrix& m);
	friend std::ostream& operator<< (std::ostream& out, const Matrix& m);		//+++++
	double& operator() (const int line, const int coll);

	Matrix changeOneColumn(const Matrix& col, const int numCol);




};












