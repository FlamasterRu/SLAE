#pragma once
#include <iostream>



double countDet(double** arr);



class Matrix
{
private:
	double** m_arr;
	int m_width;
	int m_height;


public:

	Matrix(const int width = 1, const int height = 1);
	Matrix(const double **arr, const int width, const int height);
	Matrix(const std::string fileName);
	Matrix(const std::string fileName, const int width, const int height);
	~Matrix();

	double getDet();






};












