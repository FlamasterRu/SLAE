#pragma once
#include <string>
#include <fstream>



class Log
{
private:
	std::ofstream l_file;

	static Log* l_ptr;


	Log();
	Log(const Log& a) = delete;
	Log& operator= (const Log& a) = delete;
	~Log();



public:


	static Log& createLog();
	//static void deleteLog();

	template <typename T>
	friend Log& operator<< (Log& log,const T str);

	void writeLog(const std::string str);
	void clearFile();


};



template <typename T>
Log& operator<< (Log& log, const T str)
{
	if (Log::l_ptr != nullptr)
	{
		log.l_file << str;
		return log;
	}
	else
	{
		std::cout << "Log was deleted" << std::endl;
	}
}



















