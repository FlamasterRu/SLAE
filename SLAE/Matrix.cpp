#include "Matrix.h"
#include <fstream>
#include <ctime>
#include <thread>
#include <queue>
#include <future>


std::mutex Matrix::mtx;



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
	if (m_arr != nullptr)
	{
		for (int i = 0; i < m_height; ++i)
		{
			delete[] m_arr[i];
		}
		delete[] m_arr;
	}
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



Matrix::Matrix(Matrix&& m) noexcept
{
	m_height = m.m_height;
	m_width = m.m_width;
	m_arr = m.m_arr;
	m.m_arr = nullptr;
}



Matrix& Matrix::operator= (const Matrix& m)
{
	if (this == &m) 
	{
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



Matrix& Matrix::operator= (Matrix&& m) noexcept 
{
	if (this == &m) 
	{
		return *this;
	}
	m_height = m.m_height;
	m_width = m.m_width;
	m_arr = m.m_arr;
	m.m_arr = nullptr;
	return *this;
}



std::ostream& operator<< (std::ostream& out, const Matrix& m)
{
	for (int i = 0; i < m.m_height; ++i)
	{
		for (int j = 0; j < m.m_width; ++j)
		{
			out.width(4);
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

	auto futureDet = std::async(std::launch::async, countDet, a);

	double* temp = nullptr;
	temp = new double[a.m_height];

	unsigned int cores = std::thread::hardware_concurrency();
	if (cores <= 2)
	{
		cores = 3;    // костыль маленький, на случай одно или двухядерных пк
	}
	std::queue<std::thread> threads;
	std::queue<int> qu;

	auto f = [&temp, &a, &b](int i) 
	{
		std::unique_lock<std::mutex> l(Matrix::mtx);
		Matrix changedMatrix(a.changeOneColumn(b, i));
		l.unlock();
		temp[i] = countDet(std::move(changedMatrix));		
	};


	for (int i = 0; i < a.m_height; ++i)
	{
		threads.push(std::thread(f, i));
		qu.push(i);
		if ((qu.size() >= cores - 2) or (i == a.m_height - 1))			////////////// qu.size() >= cores - 2 отвечает за одновременно работающее количество потоков
		{
			if (i < a.m_height - 1)
			{
				++i;
				f(i);		// запуск части задачи на основном потоке
			}
			while (qu.size() > 0)
			{
				threads.front().join();
				threads.pop();
				qu.pop();
			}
		}
	}


	double det = futureDet.get();
	if (det == 0)
	{
		throw("det == 0");
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


int Matrix::getHeight()
{
	return this->m_height;
}


int Matrix::getWidth()
{
	return this->m_width;
}



Matrix createRandMatrix(const int height, const int width)
{
	srand(time(0) + height + width);
	Matrix temp(height, width);
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			temp(i, j) = rand() % 40 - 20;
		}
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));		// чтобы все матрицы не получились одинаковыми (для srand), если они подряд генерируются
	return temp;
}





bool checkSolution(Matrix& A, Matrix& b, Matrix& x)
{
	if ((A.getWidth() != b.getHeight()) or (A.getHeight() != x.getHeight()))
	{
		throw ("((A.getWidth() != b.getHeight()) or (A.getHeight() != x.getHeight()))");
	}
	double error = 0;
	for (int line = 0; line < A.getHeight(); ++line)
	{
		double sum = 0;
		for (int col = 0; col < A.getWidth(); ++col)
		{
			sum += A(line, col) * x(col, 0);
		}
		error += sum - b(line, 0);
	}

	if ((error > 0.00000001) or (error < -0.00000001))		/// Допустимая погрешность
	{
		//std::cout << "False solution!  error = " << error << std::endl;
		return 0;
	}
	else
	{
		//std::cout << "True solution.  error = " << error << std::endl;
		return 1;
	}
}

























