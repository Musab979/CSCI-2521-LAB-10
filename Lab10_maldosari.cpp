/** 
 * @file Lab10_maldosari.cpp
 * @author Musab Aldosari
 * @date 2026-11-23
 * @brief A banking application that saves account info to a text file.
 */



#include<iostream>
#include "SavingsAccount.h"

void printMenu();
int getMenuOption();
bool isAmountValid(double amount);
bool isMenuChoiceValid(int choice);
void printInvalidMenuChoiceMessage();
double getDepositAmount();
double getWithdrawalAmount();
void printInvalidAmountMessage();

const int DEPOSIT = 1;
const int WITHDRAWAL = 2;
const int CLOSE_OF_BUSINESS = 3;
const int SAVE = 4;
const int QUIT = 5;

/**
 * @brief Runs the banking program and saves account information
 * @param None
 * @return 0 when the program finishes succesfully.
 */
int main()
{
    // just use dummy data for now for the customer and the account
    // we care about interacting with account object for this lab
    Customer customer("0123456789", "customer@cscc.edu");
    SavingsAccount *account = new SavingsAccount("5423678409", 100.00, .05, customer);
    account->printAccountInfo();

    int menuChoice = getMenuOption();
    while (menuChoice != QUIT)
    {
        double deposit = 0, withdrawal = 0;

        switch (menuChoice)
        {
        case DEPOSIT:
            deposit = getDepositAmount();
            account->deposit(deposit);
            break;
        case WITHDRAWAL:
            withdrawal = getWithdrawalAmount();
            account->withdraw(withdrawal);
            break;
        case CLOSE_OF_BUSINESS:
            account->closeOfBusiness();
            account->Save();
            break;
        case SAVE:
            account->Save();
			break;
        }

        menuChoice = getMenuOption();
    }

    delete account;

    return 0;
}

/**
 * @brief Display banking menu.
 * @param None
 * @return None
 */
void printMenu()
{
    cout << "\nCSCC Bank and Trust" << endl;
    cout << "Select an option:" << endl;
    cout << DEPOSIT << ". Make a deposit" << endl;
    cout << WITHDRAWAL << ". Make a withdrawal" << endl;
    cout << CLOSE_OF_BUSINESS << ". Close of Business" << endl;
    cout << SAVE << ". Save Account Info" << endl;
    cout << QUIT << ". Quit" << endl;
}

/**
 * @brief Get menu option from user.
 * @param None
 * @return Selected menu option.
 */
int getMenuOption()
{
    int choice = 0;

    do
    {
        printMenu();
        cin >> choice;

        if (!isMenuChoiceValid(choice))
        {
            printInvalidMenuChoiceMessage();
        }
    } while (!isMenuChoiceValid(choice));

    return choice;
}
/**
 * @brief Check if menu choice is valid.
 * @param choice Option selected by user.
 * @return True if valid, false if else.
 */
bool isMenuChoiceValid(int choice)
{
    return choice >= DEPOSIT and choice <= QUIT;
}

/**
 * @brief Checks if the amount is greater than zero
 * @param amount The amount inputted by user.
 * @return True if valid, false otherwise.
 */
bool isAmountValid(double amount)
{
    return amount > 0;
}

/**
 * @brief Displays an invalid menu choice message.
 * @param None
 * @return None
 */
void printInvalidMenuChoiceMessage()
{
    cout << "Invalid option selected. Please try again." << endl;
}

/**
 * @brief Gets the deposit amount from the user.
 * @param None
 * @return The valid deposit amount.
 */
double getDepositAmount()
{
    double deposit = 0;
    do
    {
        cout << "Please enter the deposit amount: $";
        cin >> deposit;

        if (!isAmountValid(deposit))
        {
            printInvalidAmountMessage();
        }

    } while (!isAmountValid(deposit));

    return deposit;
}

/**
 * @brief Gets the withdrawl amount from the user.
 * @param None
 * @return The valid withdrawal amount.
 */
double getWithdrawalAmount()
{
    double withdrawal = 0;
    do
    {
        cout << "Please enter the withdrawal amount: $";
        cin >> withdrawal;

        if (!isAmountValid(withdrawal))
        {
            printInvalidAmountMessage();
        }

    } while (!isAmountValid(withdrawal));

    return withdrawal;
}

/**
 * @brief Displays an invalid amount message.
 * @param None
 * @return None
 */
void printInvalidAmountMessage()
{
    cout << "The dollar amount must be greater than $0.00. Please try again." << endl;
}