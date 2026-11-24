/**
 * @file SavingsAccount.cpp
 * @author Musab Aldosari
 * @date 2026-11-23
 * @brief Manages savings account info including interest and saving account info to a text file.
 */

#include <fstream>
#include "SavingsAccount.h"

/**
 * @brief Creates default savings account.
 * @param None
 * @return None
 */
SavingsAccount::SavingsAccount() : interest(1)
{
}

/**
 * @brief Creates a savings account with the provided information.
 * @param accNum The account number.
 * @param initialBalance The starting balance.
 * @param interest The daily rate of interest
 * @param customer Account owner.
 * @return None
 */
SavingsAccount::SavingsAccount(const string& accNum, double initialBalance, float interest, const Customer& customer)
    : Account(accNum, initialBalance, customer)
{    
    this->interest = interest;
}

/**
 * @brief Updates the balance and applies daily interest.
 * @param None
 * @return None
 */
void SavingsAccount::closeOfBusiness()
{
    double totalDeposits = accumulate(deposits.begin(), deposits.end(), 0.0);
    double totalWithdrawals = accumulate(withdrawals.begin(), withdrawals.end(), 0.0);

    double previousBalance = balance;
    double interestToApply = previousBalance <= 0 ? 0 : interest;
    double newBalance = (previousBalance + totalDeposits - totalWithdrawals) * (1 + interestToApply);

    printSummary(previousBalance, totalDeposits, totalWithdrawals, newBalance);

    balance = newBalance;

    deposits.clear();
    withdrawals.clear();
}

/**
 * @brief Display the savings account info
 * @param None
 * @return None
 */
void SavingsAccount::printAccountInfo() const
{
    cout << "Account Number: " << accountNumber << endl;
    cout << "Current Balance: $" << balance << endl;
    cout << "Interest Rate: " << interest * 100 << "%" << endl;
    owner.printCustomerInfo();
}

/** 
 * @brief Save account info to a text file.
 * @param None
 * @return None
 */
void SavingsAccount::Save() {
    ofstream accountFile("account_summary.txt");

    accountFile << "Account Number: " << accountNumber << endl;
    accountFile << "Current Balance: $" << balance << endl;
    accountFile << "Daily Interest Rate: " << interest * 100 << "%" << endl;

    accountFile.close();

    cout << "Account information saved to account_summary.txt" << endl;
}