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
	static void deleteLog();


	friend Log& operator<< (Log& log, const std::string str);
	void writeLog(const std::string str);
	void clearFile();


};
























