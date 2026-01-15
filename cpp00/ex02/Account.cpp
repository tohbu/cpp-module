#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
	std::time_t now = std::time(NULL);
	std::tm *local = std::localtime(&now);
	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", local);
	std::cout << buffer;
}

Account::Account(int initial_deposit)
{
	//instance
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	//class
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed" << std::endl;
	_totalAmount -= _amount;
	_nbAccounts--;
}

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}
int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}
int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
}
//

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << _amount + deposit;
	std::cout << ";nb_deposits:" << ++_nbDeposits << std::endl;
	//instance
	_amount += deposit;
	//class
	_totalAmount += deposit;
	_totalNbDeposits++;
}
bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	if (_amount < withdrawal)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	else
	{
		std::cout << ";withdrawal:" << withdrawal;
		std::cout << ";amount:" << _amount - withdrawal;
		std::cout << ";nb_withdrawals:" << ++_nbWithdrawals << std::endl;
		//instance
		_amount -= withdrawal;
		//class
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		return true;
	}
}

int Account::checkAmount(void) const
{
	return _amount;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}
