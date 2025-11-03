#ifndef FILE_REPLACE_HPP
#define FILE_REPLACE_HPP
#include<string>
#include <fstream>
#include<iostream>

class FileReplace
{
	private:	
		std::ifstream _InFile;
		std::ofstream _ReplaceFile;
		const 	std::string _s1;
		const 	std::string _s2;
	public:
		 FileReplace(const std::string& InFile,const std::string&s1, const std::string&s2);
		 ~FileReplace();
		 void replace_str();
};

#endif