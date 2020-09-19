#pragma once
#include <chrono>


class Timer
{
private:

	std::chrono::system_clock::time_point t_start;			// ������ �������� ������� Timer
	std::chrono::system_clock::time_point t_lastStart;


public:

	Timer();
	~Timer();


	void PrintTimeFromStart();		// ������� � ������� ������ ����� ������������� ������� Timer 
	void StartTimer();			// ��������� ����� �������� ����, �� ������� ���������� �����
	double StopTimer();			// ���������� ����� ���������� ���� � ������� ���������� ������ StartTimer
};
