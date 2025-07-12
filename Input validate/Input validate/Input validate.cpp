#include <iostream>
#include "clsInputValidate.h"
#include "clsDate.h"

using namespace std;

int main() {

    // Test: readNumberInteger
    int iNum = clsInputValidate::readNumberInteger("Enter an integer: ", "Invalid input! Try again: ");
    cout << "You entered: " << iNum << "\n\n";

    // Test: readNumberIntegerBetween
    int iRange = clsInputValidate::readNumberIntegerBetween(1, 10, "Enter an integer between 1 and 10: ");
    cout << "You entered valid range: " << iRange << "\n\n";

    // Test: readNumberDouble
    double dNum = clsInputValidate::readNumberDouble("Enter a decimal number: ", "Invalid input! Try again: ");
    cout << "You entered: " << dNum << "\n\n";

    // Test: readNumberDoubleBetween
    double dRange = clsInputValidate::readNumberDoubleBetween(5.5, 15.5, "Enter a number between 5.5 and 15.5: ");
    cout << "You entered valid range: " << dRange << "\n\n";

    // Test: isNumberBetween (int and double)
    cout << "Test isNumberBetween(5, 1, 10): " << (clsInputValidate::isNumberBetween(5, 1, 10) ? " Yes" : " No") << "\n";
    cout << "Test isNumberBetween(20.5, 10.0, 30.0): " << (clsInputValidate::isNumberBetween(20.5, 10.0, 30.0) ? " Yes" : " No") << "\n\n";

    // Test: readCharacter
    char ch = clsInputValidate::readCharacter("Enter a character: ");
    cout << "You entered: " << ch << "\n\n";

    // Test: answerYesOrNo
    char yn = clsInputValidate::answerYesOrNo("Do you want to continue? [Y/N]: ");
    cout << "You answered: " << yn << "\n\n";

    // Test: isDateBetween
    clsDate date1(1, 1, 2020);
    clsDate date2(1, 1, 2025);
    clsDate checkDate(10, 10, 2023);

    bool isBetween = clsInputValidate::isDateBetween(checkDate, date1, date2);
    cout << "Test date between 01/01/2020 and 01/01/2025 → 10/10/2023: " << (isBetween ? "Yes" : "No") << "\n\n";

    // Test: validationDate
    clsDate dValid(30, 2, 2024); // Invalid: Feb 30
    bool valid = clsInputValidate::validationDate(dValid);
    cout << "Test validationDate(30/02/2024): " << (valid ? "Valid" : "Invalid") << "\n";

    clsDate dValid2(28, 2, 2024); // Valid
    bool valid2 = clsInputValidate::validationDate(dValid2);
    cout << "Test validationDate(28/02/2024): " << (valid2 ? "Valid" : "Invalid") << "\n";

    return 0;
}
