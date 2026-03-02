#ifndef FORM_HPP
#define FORM_HPP
#include <string>
#include <sstream>
#include <ostream>

class Bureaucrat;
class Form
{
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;
	/* data */

public:
	Form(/* args */);
	~Form();
	Form(const Form &other);
	Form &operator=(const Form &other);
	Form(const std::string &name, int gradeToSign, int gradeToExecute);

	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception
	{
	private:
		int _grade;
		std::string _message;

	public:
		GradeTooHighException(int grade) throw();
		virtual ~GradeTooHighException() throw();
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	private:
		int _grade;
		std::string _message;

	public:
		GradeTooLowException(int grade) throw();
		virtual ~GradeTooLowException() throw();
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Form &form);
#endif
