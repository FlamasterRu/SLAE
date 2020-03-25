#include "Matrix.h"
#include <fstream>




Matrix::Matrix(const int width = 1, const int height = 1) : m_width(width), m_height(height)
{
	m_arr = new double*[m_height];
	for (int i = 0; i < m_height; ++i)
	{
		m_arr[i] = new double[m_width];
	}
	for (int i = 0; i < m_height; ++i)
	{
		for (int j = 0; j < m_width; ++j)
		{
			m_arr[i][j] = 0;
		}
	}
}




Matrix::Matrix(const double** arr, const int width, const int height) : m_width(width), m_height(height)
{
	m_arr = new double* [m_height];
	for (int i = 0; i < m_height; ++i)
	{
		m_arr[i] = new double[m_width];
	}
	for (int i = 0; i < m_height; ++i)
	{
		for (int j = 0; j < m_width; ++j)
		{
			m_arr[i][j] = arr[i][j];
		}
	}
}



Matrix::Matrix(const std::string fileName) 
{
	std::ifstream iFile(fileName);
	iFile.open(fileName);
	if (!iFile.is_open())
	{
		throw("Can't open file");
	}
	iFile >> m_height >> m_width;

	m_arr = new double* [m_height];
	for (int i = 0; i < m_height; ++i)
	{
		m_arr[i] = new double[m_width];
	}

	for (int i = 0; i < m_height; ++i)
	{
		for (int j = 0; j < m_width; ++j)
		{

		}
	}





}

















