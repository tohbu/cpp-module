#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(/* args */) : _isSigned(false), _gradeToSign(0), _gradeToExecute(0)
{
}
AForm::~AForm()
{
}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();

	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
		this->_gradeToSign = other._gradeToSign;
		this->_gradeToExecute = other._gradeToExecute;
	}
	return *this;
}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat &bur)
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

const char *AForm::GradeTooHighException ::what() const throw()
{
	return "AForm Exception: Grade Too High";
}

const char *AForm::GradeTooLowException ::what() const throw()
{
	return "AForm Exception: Grade Too Low";
}

const char *AForm::FormNotSignedException ::what() const throw()
{
	return "AForm Exception: Form Not Signed";
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "AForm: " << form.getName() << ", signed: " << form.getIsSigned() << ", grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute() << std::endl;
	return os;
}
