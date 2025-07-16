#pragma once
#include <iostream> 
#include <string>
#include "clsDate.h"
#include "clsString.h"
#include "clsUtility.h"

using std::cout;
using std::cin;
using std::string;
using std::to_string;
using std::endl;
using std::setw;
using std::fixed;
using std::setprecision;
using std::stoi;
using std::stod;
using std::numeric_limits;
using std::streamsize;



class clsInputValidate
{

private:

	unsigned short int const static _kZERO{ 0 };
	unsigned short int const static _kONE{ 1 };

public:

	template <typename T >

	static inline bool isNumberBetween(T const kNUMBER_TO_CHEAK_BETWEEN, T const kNUMBER_ONE, T const kNUMBER_TWO) {

		return ((kNUMBER_TO_CHEAK_BETWEEN >= kNUMBER_ONE)
			&& (kNUMBER_TO_CHEAK_BETWEEN <= kNUMBER_TWO));

	};


	static inline bool isDateBetween(clsDate kDATE_TO_NEED_CHEAK, clsDate kDATE_ONE, clsDate kDATE_TWO) {
		return (
			(clsDate::compareTwoDates(kDATE_TO_NEED_CHEAK, kDATE_ONE) == clsDate::enCompareTwoDate::kAFTER &&
				clsDate::compareTwoDates(kDATE_TO_NEED_CHEAK, kDATE_TWO) == clsDate::enCompareTwoDate::kBEFORE)

			||

			(clsDate::compareTwoDates(kDATE_TO_NEED_CHEAK, kDATE_ONE) == clsDate::enCompareTwoDate::kBEFORE &&
				clsDate::compareTwoDates(kDATE_TO_NEED_CHEAK, kDATE_TWO) == clsDate::enCompareTwoDate::kAFTER)
			);
	}

	template < typename T >

	static inline T readNumberByUser(const string kMESSAGE_ORGINAL, const string kMESSAGE_WARNING) {

		T number{ _kZERO };

		cout << kMESSAGE_ORGINAL;
		cin >> number;

		cout << endl;
		while (cin.fail()) {

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << kMESSAGE_WARNING;
			cin >> number;
		};

		return number;
	};

	template < typename T >
	static inline T readNumberByUserIncludeTab( unsigned short int kNUMBER_OF_TAB, const string kMESSAGE_ORGINAL, const string kMESSAGE_WARNING) {

		T number{};

		cout << clsUtility::createTabs(kNUMBER_OF_TAB) << kMESSAGE_ORGINAL;
		cin >> number;

		cout << endl;
		while (cin.fail()) {

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << clsUtility::createTabs(kNUMBER_OF_TAB) << kMESSAGE_WARNING;
			cin >> number;
		};

		return number;
	};

	template < typename T >

	static inline T readNumberBetween(T const kFRAM_NUMBER, const T kTO_NUMBER, const string kMESSAGE_ORGINAL, const string kMESSAGE_WARNING = "Number is not within range, Enter again:\n") {

		T number =  readNumberByUser <T>(kMESSAGE_ORGINAL , kMESSAGE_WARNING) ;

		cout << endl;
		while (!isNumberBetween(number, kFRAM_NUMBER, kTO_NUMBER)) {

			cout << kMESSAGE_WARNING;
			number =  readNumberByUser<T>(kMESSAGE_ORGINAL , kMESSAGE_WARNING) ;

		}

		return number;
	};

	template < typename T >

	static inline T readNumberBetweenIncludeTabs(const unsigned short int kNUMBER_TAB, T const kFRAM_NUMBER, const T kTO_NUMBER, const string kMESSAGE_ORGINAL, const string kMESSAGE_WARNING = "Number is not within range, Enter again:\n") {

		T number = readNumberByUserIncludeTab <T> ( kNUMBER_TAB , kMESSAGE_ORGINAL , kMESSAGE_WARNING) ;
		cout << endl;
		while (!isNumberBetween(number, kFRAM_NUMBER, kTO_NUMBER)) {

			number =  readNumberByUserIncludeTab<T>(kNUMBER_TAB , kMESSAGE_ORGINAL , kMESSAGE_WARNING) ;

		}

		return number;
	};



	static inline string readString(string const kMESSAGE) {

		string text{ "" };

		cout << kMESSAGE;
		getline(cin >> ws, text);
		cout << endl;
		return text;


	}

	static inline string readStringIncludeTab(const unsigned short int kNUMBER_OF_TAB, string const kMESSAGE) {

		string text{ "" };

		cout << clsUtility::createTabs(kNUMBER_OF_TAB) << kMESSAGE;
		getline(cin >> ws, text);
		cout << endl;
		return text;


	};


	static inline bool validationDate(clsDate date) {

		return (clsDate::validationDate(date));
	};


	static inline char answerYesOrNo(string const kMESSAGE_PROMT = "", string const kMESSAGE_WORNING = "Please , Enter of the [Y/N] Only : ") {

		char answer{ ' ' };

		cout << kMESSAGE_PROMT;
		cin >> answer;
		cout << endl;

		while (clsString::convertionUpperCharToLower(answer) != 'y' && clsString::convertionUpperCharToLower(answer) != 'n') {
			cout << kMESSAGE_WORNING;
			cin >> answer;
		};

		return answer;

	};
	static inline char answerYesOrNoIncludeTab(unsigned short int const kNUMBER_TAB, string const kMESSAGE_PROMT = "", string const kMESSAGE_WORNING = "Please , Enter of the [Y/N] Only : ") {

		char answer{ ' ' };

		cout << clsUtility::createTabs(kNUMBER_TAB) << kMESSAGE_PROMT;
		cin >> answer;
		cout << endl;

		while (clsString::convertionUpperCharToLower(answer) != 'y' && clsString::convertionUpperCharToLower(answer) != 'n') {
			cout << clsUtility::createTabs(kNUMBER_TAB) << kMESSAGE_WORNING;
			cin >> answer;
		};

		return answer;

	};
	static inline char readCharacter(string const kMESSAGE_PROMT = "", string const kMESSAGE_WORNING = "Please , Enter of the Character : ") {

		string inputString{ "" };
		cout << kMESSAGE_PROMT;
		cin >> inputString;

		while (inputString.length() != _kONE) {
			cout << kMESSAGE_WORNING;
			cin >> inputString;
		}

		return inputString[_kZERO];
	};

	static inline char readCharacterIncludeTab(unsigned short int const kNUMBER_OF_TAB, string const& kMESSAGE) {

		cout << clsUtility::createNewLine(1) << clsUtility::createTabs(kNUMBER_OF_TAB);
		char character = readCharacter(kMESSAGE);

		return character;
	}
};
