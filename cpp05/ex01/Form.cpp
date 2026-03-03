#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(/* args */) : _isSigned(false), _gradeToSign(0), _gradeToExecute(0)
{
}
Form::~Form()
{
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}
Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
		this->_gradeToSign = other._gradeToSign;
		this->_gradeToExecute = other._gradeToExecute;
	}
	return *this;
}

std::string Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

void Form::beSigned(Bureaucrat &bur)
{
	if (bur.getGrade() <= this->getGradeToSign())
	{
		this->_isSigned = true;
		return;
	}
	else
	{
		throw GradeTooHighException();
	}
}

const char *Form::GradeTooHighException ::what() const throw()
{
	return "Form Exception: Grade Too High";
}

const char *Form::GradeTooLowException ::what() const throw()
{
	return "Form Exception: Grade Too Low";
}
std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form: " << form.getName() << ", signed: " << form.getIsSigned() << ", grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute() << std::endl;
	return os;
}
