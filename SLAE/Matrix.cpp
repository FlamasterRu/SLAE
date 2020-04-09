#include "Matrix.h"
#include <fstream>
#include <ctime>




Matrix::Matrix(const int height, const int width) : m_width(width), m_height(height)
{
	m_arr = new double*[m_height];
	for (int i = 0; i < m_height; ++i)
	{
		m_arr[i] = new double[m_width];
		for (int j = 0; j < m_width; ++j)
		{
			m_arr[i][j] = 0;
		}
	}
}




Matrix::Matrix(const double** arr, const int height, const int width) : m_width(width), m_height(height)
{
	m_arr = new double* [m_height];
	for (int i = 0; i < m_height; ++i)
	{
		m_arr[i] = new double[m_width];
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
		for (int j = 0; j < m_width; ++j)
		{
			iFile >> m_arr[i][j];
		}
	}

	iFile.close();
}




Matrix::Matrix(const std::string fileName, const int height, const int width) : m_width(width), m_height(height)
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
		for (int j = 0; j < m_width; ++j)
		{
			iFile >> m_arr[i][j];
		}
	}

	iFile.close();
}



Matrix::Matrix(const Matrix& m, const int line, const int col)
{
	m_height = m.m_height - 1;
	m_width = m.m_width - 1;

	m_arr = new double* [m_height];
	for (int i = 0; i < m_height; ++i)
	{
		m_arr[i] = new double[m_width];
	}

	for (int i = 0, i1 = 0; i < m.m_height; ++i)
	{
		if (line == i)
		{
			continue;
		}
		for (int j = 0, j1 = 0; j < m.m_width; ++j)
		{
			if (col == j)
			{
				continue;
			}
			m_arr[i1][j1] = m.m_arr[i][j];
			++j1;
		}
		++i1;
	}
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





Matrix Matrix::changeOneColumn(const Matrix& col, const int numCol) const
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
		temp.m_arr[i][numCol] = col.m_arr[i][0];
	}
	return temp;
}








int pow(const int b)
{
	int a = 1;
	for (int i = 0; i < b; ++i)
	{
		a *= -1;
	}
	return a;
}




double countDet(const Matrix& m)
{
	if (m.m_height != m.m_width)
	{
		throw("m.m_height != m.m_width");
	}
	if (m.m_height == 1)
	{
		return m.m_arr[0][0];
	}
	if (m.m_height == 2)
	{
		return (m.m_arr[0][0]*m.m_arr[1][1] - m.m_arr[0][1]*m.m_arr[1][0]);
	}
	if (m.m_height == 3)
	{
		return (m.m_arr[0][0] * m.m_arr[1][1] * m.m_arr[2][2] + m.m_arr[0][1] * m.m_arr[1][2] * m.m_arr[2][0] + m.m_arr[1][0] * m.m_arr[2][1] * m.m_arr[0][2]
			- m.m_arr[0][2] * m.m_arr[1][1] * m.m_arr[2][0] - m.m_arr[0][0] * m.m_arr[2][1] * m.m_arr[1][2] - m.m_arr[2][2] * m.m_arr[0][1] * m.m_arr[1][0]);
	}


	double sum = 0;
	for (int i = 0; i < m.m_height; ++i)
	{
		Matrix temp(m, i, 0);
		sum += pow(i) * countDet(temp) * m.m_arr[i][0];
	}
	return sum;

}





Matrix solveSLAE(const Matrix& a, const Matrix& b)
{
	if (a.m_height != a.m_width)
	{
		throw("a.m_height != a.m_width");
	}
	if (a.m_height != b.m_height)
	{
		throw("a.m_height != b.m_height");
	}
	double det = countDet(a);
	if (det == 0)
	{
		throw("det == 0");
	}

	double *temp = nullptr;
	temp = new double[a.m_height];


	for (int i = 0; i < a.m_height; ++i)
	{
		temp[i] = countDet(a.changeOneColumn(b, i));
		//std::cout << "          " << i << " == " << temp[i] << std::endl;
	}
	
	Matrix result(a.m_height, 1);
	for (int i = 0; i < a.m_height; ++i)
	{
		result(i, 0) = temp[i] / det;
	}

	delete[] temp;

	return result;
}






void createRandMatrix(const int height, const int width, std::string fileName)
{
	std::ofstream oFile;
	oFile.open(fileName);
	if (!oFile.is_open())
	{
		throw("Can't open file");
	}
	srand(time(0));
	oFile << height << " " << width << std::endl;
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (j == width - 1)
			{
				oFile << (rand() % 60 - 30);
			}
			else
			{
				oFile << (rand() % 60 - 30) << " ";
			}
		}
		oFile << std::endl;
	}
}



























