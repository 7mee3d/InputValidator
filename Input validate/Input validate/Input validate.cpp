#include <iostream>
#include "clsInputValidate.h"
#include "clsDate.h"

using namespace std;

int main() {
    int age = clsInputValidate::readNumberByUser<int>(
        "Enter your age: ",
        "Invalid input. Please enter a valid number: "
    );
    cout << "Your age is: " << age << "\n\n";

    float price = clsInputValidate::readNumberByUserIncludeTab<float>(
        2,
        "Enter product price: ",
        "Invalid input. Try again: "
    );
    cout << "Price is: " << price << "\n\n";

    int rangeValue = clsInputValidate::readNumberBetween<int>(
        10, 20,
        "Enter a number between 10 and 20: "
    );
    cout << "Range value: " << rangeValue << "\n\n";

    double tabRange = clsInputValidate::readNumberBetweenIncludeTabs<double>(
        1, 1.5, 3.5,
        "Enter a value between 1.5 and 3.5: "
    );
    cout << "Value: " << tabRange << "\n\n";

    string name = clsInputValidate::readString("Enter your name: ");
    cout << "Name: " << name << "\n\n";

    string city = clsInputValidate::readStringIncludeTab(2, "Enter your city: ");
    cout << "City: " << city << "\n\n";

    char answer = clsInputValidate::answerYesOrNo("Continue [Y/N]? ");
    cout << "Answer: " << answer << "\n\n";

    char tabAnswer = clsInputValidate::answerYesOrNoIncludeTab(1, "Continue again [Y/N]? ");
    cout << "Answer: " << tabAnswer << "\n\n";

    char gender = clsInputValidate::readCharacter("Enter gender (M/F): ");
    cout << "Gender: " << gender << "\n\n";

    char level = clsInputValidate::readCharacterIncludeTab(2, "Enter level (A/B/C): ");
    cout << "Level: " << level << "\n\n";

    clsDate d1(1, 1, 2020), d2(1, 1, 2030), checkDate(1, 1, 2025);
    bool isBetween = clsInputValidate::isDateBetween(checkDate, d1, d2);
    cout << "Date is between: " << (isBetween ? "Yes" : "No") << "\n\n";

    bool validDate = clsInputValidate::validationDate(checkDate);
    cout << "Date is valid: " << (validDate ? "Yes" : "No") << "\n\n";

    return 0;
}
