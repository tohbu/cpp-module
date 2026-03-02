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
	{
		int errorGrade = gradeToSign < 1 ? gradeToSign : gradeToExecute;
		throw GradeTooHighException(errorGrade);
	}

	if (gradeToSign > 150 || gradeToExecute > 150)
	{
		int errorGrade = gradeToSign > 150 ? gradeToSign : gradeToExecute;
		throw GradeTooLowException(errorGrade);
	}
}
Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
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
		throw GradeTooLowException(this->getGradeToSign());
	}
}
Form::GradeTooHighException::GradeTooHighException(int grade) throw() : _grade(grade)
{
	std::stringstream ss;
	ss << _grade;
	_message = "Form Exception: Grade Too High. Grade: " + ss.str();
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
}

Form::GradeTooLowException::GradeTooLowException(int grade) throw() : _grade(grade)
{
	std::stringstream ss;
	ss << _grade;
	_message = "Form Exception: Grade Too Low. Grade: " + ss.str();
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
}

const char *Form::GradeTooHighException ::what() const throw()
{
	return _message.c_str();
}

const char *Form::GradeTooLowException ::what() const throw()
{
	return _message.c_str();
}
std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form: " << form.getName() << ", signed: " << form.getIsSigned() << ", grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute() << std::endl;
	return os;
}
