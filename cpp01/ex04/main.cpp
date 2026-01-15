#include "FileReplace.hpp"
#define FILENAME 1
#define FROM 2
#define TO 3

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "please 3 parameters." << std::endl;
		return 1;
	}
	try
	{
		FileReplace f(argv[FILENAME], argv[FROM], argv[TO]);
		f.replace_str();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}