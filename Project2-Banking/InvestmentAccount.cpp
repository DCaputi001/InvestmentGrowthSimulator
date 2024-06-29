#include "InvestmentAccount.h"

using namespace std;

// Initalize an account with no monthly deposit
InvestmentAccount::InvestmentAccount(double initialAmount, double annualInterestRate)
    : initialAmount(initialAmount), annualInterestRate(annualInterestRate), monthlyDeposit(0.0) {}

// Initialize an account with a monthly deposit 
InvestmentAccount::InvestmentAccount(double initialAmount, double annualInterestRate, double monthlyDeposit)
    : initialAmount(initialAmount), annualInterestRate(annualInterestRate), monthlyDeposit(monthlyDeposit) {}

// Calculate the ending balance after a given number of years
double InvestmentAccount::getEndingBalance(int numberOfYears) {
    double totalAmount = initialAmount;

    if (monthlyDeposit > 0) {
        // Calculate compound interest with monthly deposits
        for (int month = 1; month <= numberOfYears * 12; ++month) {
            totalAmount += monthlyDeposit;
            double monthlyInterest = totalAmount * ((annualInterestRate / 100) / 12);
            totalAmount += monthlyInterest;
        }
    }
    else {
        // Calculate compound interest without monthly deposits
        for (int year = 1; year <= numberOfYears; ++year) {
            double yearlyInterest = totalAmount * (annualInterestRate / 100);
            totalAmount += yearlyInterest;
        }
    }

    return totalAmount;
}

// Calculate the interest earned for a given number of years
double InvestmentAccount::getInterestEarned(int numberOfYears) {
    double totalAmount = initialAmount;
    double totalInterest = 0.0;

    if (monthlyDeposit > 0) {
        // Calculate interest earned with monthly deposits
        for (int month = 1; month <= numberOfYears * 12; ++month) {
            totalAmount += monthlyDeposit;
            double monthlyInterest = totalAmount * ((annualInterestRate / 100) / 12);
            totalAmount += monthlyInterest;
            totalInterest += monthlyInterest;

            if (month % 12 == 0) {
                totalInterest = 0; // Reset yearly interest
            }
        }
    }
    else {
        // Calculate interest earned without monthly deposits
        for (int year = 1; year <= numberOfYears; ++year) {
            double yearlyInterest = totalAmount * (annualInterestRate / 100);
            totalAmount += yearlyInterest;
            totalInterest += yearlyInterest;
        }
    }

    return totalInterest;
}

// Get the formatted ending balance 
string InvestmentAccount::getEndingBalanceFormatted(int numberOfYears) {
    return format(round(getEndingBalance(numberOfYears), 2));
}
// Get the formatted interest earned for a given number of years
string InvestmentAccount::getInterestEarnedFormatted(int numberOfYears) {
    return format(round(getInterestEarned(numberOfYears), 2));
}

double InvestmentAccount::getInitialAmount() {
    return initialAmount;
}

double InvestmentAccount::getMonthlyDeposit() {
    return monthlyDeposit;
}

double InvestmentAccount::getAnnualInterestRate() {
    return annualInterestRate;
}

// Implementation for round and format methods
double InvestmentAccount::round(double value, int places) {
    const int multiplier = power(10, places);

    double roundedValue = (int)(value * multiplier + 0.5);
    roundedValue = (double)roundedValue / multiplier;
    return roundedValue;
}
// Format a double value as a string with two decimal places
string InvestmentAccount::format(double value) {
    string valueAsString = to_string(value);
    string formatted;

    bool decimalFound = false;
    int decimalCount = 0;

    int i;
    for (i = 0; i < valueAsString.size(); i++) {
        char currentChar = valueAsString[i];

        if (decimalCount == 2) {
            break;
        }

        if (currentChar == '.') {
            decimalFound = true;
        }
        else if (decimalFound && decimalCount != 2) {
            decimalCount++;
        }

        formatted.append(std::string(1, currentChar));
    }

    return formatted;
}


double InvestmentAccount::power(int base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

