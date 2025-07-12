
# InputValidator 📥

`clsInputValidate` is a powerful and reusable C++ class that simplifies and secures **user input** by validating different data types before accepting them. It ensures your program doesn’t crash from unexpected or invalid input.

---

## 🚀 Why Use InputValidator?

When building console applications, users can enter incorrect data (like letters when numbers are expected). This class prevents such issues by:
- Forcing valid input types
- Ensuring numbers or dates fall within acceptable ranges
- Providing clear prompts and error messages
- Making the code cleaner and more maintainable

---

## 🔧 Features

| Feature                     | Description |
|----------------------------|-------------|
| Integer & Double Reading   | Forces correct numeric input |
| Range Checking             | Ensures number is within a valid range |
| Character Input            | Accepts only a single character |
| Yes/No Prompts             | Accepts only 'Y' or 'N' (case-insensitive) |
| Date Validation & Range    | Validates and compares custom `clsDate` objects |

---

## 📦 Required Libraries

```cpp
#include <iostream>
#include <string>
#include <limits>
#include "clsDate.h"
#include "clsString.h"
```

You must define `clsDate` and `clsString` in your project for this to work correctly.

---

## 📘 Functions and Usage

### 1. ✅ Number Between Check

Check whether a number is between two values (inclusive):

```cpp
bool isNumberBetween(int value, int from, int to);
bool isNumberBetween(double value, double from, double to);
```

🔎 **Example:**

```cpp
if (clsInputValidate::isNumberBetween(5, 1, 10)) {
    cout << "Number is valid!";
}
```

---

### 2. 📆 Date Between Check

Check if a date is between two other dates using your custom `clsDate` type.

```cpp
bool isDateBetween(clsDate dateToCheck, clsDate date1, clsDate date2);
```

---

### 3. 🔢 Read Integer

Read an integer safely with a custom prompt and warning:

```cpp
int readNumberInteger(string prompt, string warning);
```

Read integer between two values:

```cpp
int readNumberIntegerBetween(int from, int to, string prompt, string warning);
```

🧪 **Example:**

```cpp
int age = clsInputValidate::readNumberIntegerBetween(18, 99, "Enter your age: ", "Age must be between 18 and 99!
");
```

---

### 4. 📈 Read Double

```cpp
double readNumberDouble(string prompt, string warning);
double readNumberDoubleBetween(double from, double to, string prompt, string warning);
```

🧪 **Example:**

```cpp
double price = clsInputValidate::readNumberDouble("Enter price: ", "Invalid number!
");
```

---

### 5. 🔠 Read Character

Reads only a **single character** input:

```cpp
char readCharacter(string prompt = "", string warning = "Please enter a single character:");
```

---

### 6. ✅ Yes or No Prompt

Reads only **Y** or **N**, case-insensitive:

```cpp
char answerYesOrNo(string prompt = "", string warning = "Please enter Y or N only:");
```

🧪 **Example:**

```cpp
char response = clsInputValidate::answerYesOrNo("Continue? [Y/N]: ");
```

---

### 7. 📅 Validate Date

Delegates to your `clsDate::validationDate()` function:

```cpp
bool validationDate(clsDate date);
```

---

## 🧪 Sample Interactive Session

```
Enter your age: ahmed
Invalid input. Try again: 25

Enter price: five
Invalid number! Please try again: 5.75

Continue? [Y/N]: maybe
Please enter Y or N only: y
```

This shows how the class guards the program from bad input.

---

## 🧠 Tips for Integration

- Ideal for **menus, banking systems, admin panels**, etc.
- Replace `cin >> var;` with these functions for **safe input**
- You can **customize all messages** for localization or branding

---
## 🤝 Contributing

Love this project? Want to improve it?  
Feel free to submit **Issues** or **Pull Requests** on GitHub — your contributions are highly appreciated! 🙌

---

# 👨💻 Author

**Ahmed Jehad Ahmed**  


🔗 [GitHub Profile](https://github.com/7mee3d)

📧 [Email Contact](mailto:enginnerahemdjehad2004@gmail.com)


---
