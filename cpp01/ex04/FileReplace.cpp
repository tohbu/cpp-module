#include "FileReplace.hpp"

FileReplace::FileReplace(const std::string& InFile,const std::string&s1, const std::string&s2):_InFile(InFile.c_str()), _s1(s1), _s2(s2)
{
	if(_s1 == "" || _s2 == "")
		throw std::runtime_error("Error: s1 or s2 cannot be empty.");
	if(!_InFile.is_open())
		throw std::runtime_error("Cannot open input file: " + InFile);
	_ReplaceFile.open((InFile + ".replace").c_str());
	if(!_ReplaceFile.is_open())
		throw std::runtime_error("Cannot open input file: " + InFile + ".replace");
}

FileReplace::~FileReplace()
{
	if(_InFile.is_open())
		_InFile.close();
	if(_ReplaceFile.is_open())
		_ReplaceFile.close();
}

void FileReplace::	replace_str()
{
	std::string read_line;
	while(std::getline(_InFile,read_line))
	{
		std::string result;
		size_t top = 0;
		size_t found;
		while((found = read_line.find(_s1,top)) != std::string::npos)
		{
			result.append(read_line,top, found - top);
			result.append(_s2);
			top = found + _s1.length();
		}
		result.append(read_line,top, std::string::npos);
		_ReplaceFile << result;
		if(!_InFile.eof())
			_ReplaceFile << std:: endl;
	}
}