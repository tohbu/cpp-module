#ifndef AFORM_HPP
#define AFORM_HPP
#include <string>
#include <sstream>
#include <ostream>

class Bureaucrat;
class AForm
{
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;
	/* data */

public:
	AForm(/* args */);
	virtual ~AForm();
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	AForm(const std::string &name, int gradeToSign, int gradeToExecute);

	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;

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

std::ostream &operator<<(std::ostream &os, const AForm &form);
#endif
