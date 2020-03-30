#include "Matrix.h"
#include <fstream>




Matrix::Matrix(const int width, const int height) : m_width(width), m_height(height)
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
	std::ifstream iFile;
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
			iFile >> m_arr[i][j];
		}
	}

	iFile.close();
}




Matrix::Matrix(const std::string fileName, const int width, const int height) : m_width(width), m_height(height)
{
	std::ifstream iFile;
	iFile.open(fileName);
	if (!iFile.is_open())
	{
		throw("Can't open file");
	}

	m_arr = new double* [m_height];
	for (int i = 0; i < m_height; ++i)
	{
		m_arr[i] = new double[m_width];
	}

	for (int i = 0; i < m_height; ++i)
	{
		for (int j = 0; j < m_width; ++j)
		{
			iFile >> m_arr[i][j];
		}
	}

	iFile.close();
}




Matrix::~Matrix()
{
	for (int i = 0; i < m_height; ++i)
	{
		delete[] m_arr[i];
	}
	delete[] m_arr;
}



Matrix::Matrix(const Matrix& m)
{
	m_height = m.m_height;
	m_width = m.m_width;
	m_arr = new double* [m_height];
	for (int i = 0; i < m_height; ++i)
	{
		m_arr[i] = new double[m_width];
	}

	for (int i = 0; i < m_height; ++i)
	{
		for (int j = 0; j < m_width; ++j)
		{
			m_arr[i][j] = m.m_arr[i][j];
		}
	}
}












Matrix& Matrix::operator= (const Matrix& m)
{
	if (this == &m) {
		return *this;
	}

	for (int i = 0; i < m_height; ++i)
	{
		delete[] m_arr[i];
	}
	delete[] m_arr;

	m_height = m.m_height;
	m_width = m.m_width;
	m_arr = new double* [m_height];
	for (int i = 0; i < m_height; ++i)
	{
		m_arr[i] = new double[m_width];
	}

	for (int i = 0; i < m_height; ++i)
	{
		for (int j = 0; j < m_width; ++j)
		{
			m_arr[i][j] = m.m_arr[i][j];
		}
	}
	return *this;
}





Matrix operator+ (const Matrix& left, const Matrix& right)
{
	if (left.m_height != right.m_height)
	{
		throw("Can't sum matrix with different height");
	}
	if (left.m_width != right.m_width)
	{
		throw("Can't sum matrix with different width");
	}

	Matrix temp(left);

	for (int i = 0; i < temp.m_height; ++i)
	{
		for (int j = 0; j < temp.m_width; ++j)
		{
			temp.m_arr[i][j] += right.m_arr[i][j];
		}
	}

	return temp;
}




bool operator== (const Matrix& left, const Matrix& right)
{
	if (left.m_height != right.m_height)
	{
		return 0;
	}
	if (left.m_width != right.m_width)
	{
		return 0;
	}
	for (int i = 0; i < left.m_height; ++i)
	{
		for (int j = 0; j < left.m_width; ++j)
		{
			if (left.m_arr[i][j] != right.m_arr[i][j])
			{
				return 0;
			}
		}
	}
	return 1;
}




Matrix& Matrix::operator+= (const Matrix& m)
{
	if (m_height != m.m_height)
	{
		throw("Can't sum matrix with different height");
	}
	if (m_width != m.m_width)
	{
		throw("Can't sum matrix with different width");
	}
	for (int i = 0; i < m_height; ++i)
	{
		for (int j = 0; j < m_width; ++j)
		{
			m_arr[i][j] += m.m_arr[i][j];
		}
	}
	return *this;
}




Matrix& Matrix::operator- ()
{
	for (int i = 0; i < m_height; ++i)
	{
		for (int j = 0; j < m_width; ++j)
		{
			m_arr[i][j] *= -1;
		}
	}
	return *this;
}


Matrix& Matrix::operator-= (const Matrix& m)
{
	if (m_height != m.m_height)
	{
		throw("Can't subtract matrix with different height");
	}
	if (m_width != m.m_width)
	{
		throw("Can't subtract matrix with different width");
	}
	for (int i = 0; i < m_height; ++i)
	{
		for (int j = 0; j < m_width; ++j)
		{
			m_arr[i][j] -= m.m_arr[i][j];
		}
	}
	return *this;
}





std::ostream& operator<< (std::ostream& out, const Matrix& m)
{
	out << m.m_height << " " << m.m_width << std::endl;
	for (int i = 0; i < m.m_height; ++i)
	{
		for (int j = 0; j < m.m_width; ++j)
		{
			if (j == m.m_width - 1)
			{
				out << m.m_arr[i][j];
			}
			else
			{
				out << m.m_arr[i][j] << " ";
			}
		}
		out << std::endl;
	}
	return out;
}



double& Matrix::operator() (const int line, const int col)
{
	if (line >= m_height)
	{
		throw("Line access error");
	}
	if (col >= m_width)
	{
		throw("Column access error");
	}
	return m_arr[line][col];
}





Matrix Matrix::changeOneColumn(const Matrix& col, const int numCol)
{
	if (numCol >= m_width)
	{
		throw("Column access error");
	}
	if (col.m_height != m_height)
	{
		throw("Line access error");
	}
	Matrix temp(*this);
	for (int i = 0; i < m_height; ++i)
	{
		temp.m_arr[i][numCol] = col.m_arr[i][numCol];
	}
	return temp;
}































