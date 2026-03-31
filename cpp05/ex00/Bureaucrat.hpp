#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <sstream>

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
	/* data */
public:
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	std::string getName() const;
	int getGrade() const;

	Bureaucrat &operator++();
	Bureaucrat &operator--();
	Bureaucrat operator++(int);
	Bureaucrat operator--(int);

	//
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	//s
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
