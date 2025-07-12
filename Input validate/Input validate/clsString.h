#pragma once
#include<iostream> 
#include <string> 
#include <fstream>
#include <iomanip> 
#include <vector> 


using std::cout;
using std::cin;
using std::string;
using std::to_string;
using std::endl;
using std::setw;
using std::setprecision;
using std::fixed;
using std::stoi;
using std::stod;
using std::vector;


class clsString
{

private:

	enum enChoiseLetter {

		kALL = 1,
		kSMALL_LETTERS = 2,
		kCAPITAL_LETTERS = 3

	};

#define Integer int 
#define Character char

	static unsigned short Integer const kNUMBER_SPACE_IN_ASCII_TABEL{ 32 };
	static unsigned short Integer const kZERO{ 0 };
	static unsigned short Integer const kONE{ 1 };

	//Member
	string _Text{ "" };
	Character _Character{  };
	bool _IsMatchCase{ false };
	enChoiseLetter _ChoiseLetterConvert{};
	vector<string> _VecString;

	//Method 
	static string functionCreateNewLine(unsigned short Integer numberOfLine) {

		string textWithLine{ "" };
		for (Integer counter{ kONE }; counter <= numberOfLine; counter++)
			textWithLine += '\n';

		return textWithLine;
	};

	static string separatorSpecificArray(unsigned short Integer sizeText, unsigned short Integer  counter, string const& kSEPARATOR) {
		//Not print last Separaator array 
		return (sizeText - kONE - kONE > counter) ? kSEPARATOR : " ";
	};
public:

	//Default Constractor 
	clsString() : _Text{ " " }, _Character{ ' ' }, _IsMatchCase{ false }, _ChoiseLetterConvert{ enChoiseLetter::kALL }, _VecString{ " " } {};

	clsString(string const& kTEXT) : _Text{ kTEXT } {};

	void setText(string const& kTEXT, Character const& kCHARACTER, bool const& kMATCHCASE, enChoiseLetter const& kCHOISE_LETTER_TO_CONVERT, vector<string> const kVECTORSTRING) {

		_Text = { kTEXT };
		_Character = { kCHARACTER };
		_IsMatchCase = { kMATCHCASE };
		_ChoiseLetterConvert = { kCHOISE_LETTER_TO_CONVERT };
		_VecString = { kVECTORSTRING };
	};

	string getText() {

		return { _Text };
	};

	__declspec (property (get = getText, put = setText)) string text;

	void setCharacter(Character const& kCHARACTER) {

		_Character = { kCHARACTER };

	};

	Character getCharacter() {

		return { _Character };
	};

	__declspec (property (get = getCharacter, put = setCharacter)) Character character;

	void setMatchCaseBoolean(bool const& kMATCH_CASE) {

		_IsMatchCase = { kMATCH_CASE };

	}

	bool getMatchCaseBoolean() {

		return { _IsMatchCase };
	};

	__declspec (property (get = getMatchCaseBoolean, put = setMatchCaseBoolean)) bool isMatchCase;


	void setChoiseLetterConvert(enChoiseLetter choise) {

		_ChoiseLetterConvert = { choise };

	};

	enChoiseLetter getChoiseLetterConvert() {

		return { _ChoiseLetterConvert };
	};

	__declspec (property (get = getChoiseLetterConvert, put = setChoiseLetterConvert)) enChoiseLetter choiseLetterToConverting;

	// Start Method of class String Library 


	// Print first letter every word 
	static void printEveryFirstLetterInTextGeneral(string const& kTEXT) {

		bool isFirstLetter{ true };

		//Static Function 
		cout << functionCreateNewLine(kONE + kONE) << "The First Letters every Word : " << functionCreateNewLine(kONE);

		for (Integer counter{ kZERO }; counter < kTEXT.size(); counter++) {

			if (kTEXT[counter] != ' ' && isFirstLetter)
				cout << kTEXT[counter] << endl;

			isFirstLetter = (kTEXT[counter] == ' ') ? true : false;

		}
	};

	void printEveryFirstLetterInText() {

		printEveryFirstLetterInTextGeneral(_Text);

	};

	//Method Specific Characters 
	inline static Character convertionUpperCharToLower(Character  const& character) {
		return static_cast <char> (character | kNUMBER_SPACE_IN_ASCII_TABEL);
	};

	inline  Character convertionUpperCharToLower() {
		return convertionUpperCharToLower(_Character);
	};

	inline static Character convertionLowerCharToUpper(Character& const character) {
		return static_cast <char> (character & ~kNUMBER_SPACE_IN_ASCII_TABEL);
	};

	inline  Character convertionLowerCharToUpper() {
		return convertionLowerCharToUpper(_Character);
	};

	// Print first letter every word upper if the character is lower or not print upper 
	inline static void printEveryFirstLetterUpperInTextGeneral(string text) {

		bool isFirstLetter{ true };

		//Static Function 
		cout << functionCreateNewLine(kONE + kONE) << "The First Letters every Word : " << functionCreateNewLine(kONE);

		for (Integer counter{ kZERO }; counter < text.size(); counter++) {

			if ((text[counter] != ' ' && isFirstLetter)) {

				if ((islower(text[counter])))
					cout << convertionLowerCharToUpper(text[counter]) << endl;
				else
					cout << text[counter] << endl;

				//	text[counter] = convertionLowerCharToUpper(text[counter]);
			}

			isFirstLetter = (text[counter] == ' ') ? true : false;

		};
	};

	inline void printEveryFirstLetterUpperInText() {
		printEveryFirstLetterUpperInTextGeneral(_Text);
	};


	// Print first letter every word Lower if the character is Upper or not print lower 
	inline static void printEveryFirstLetterLowerInText(string text) {

		bool isFirstLetter{ true };

		//Static Function 
		cout << functionCreateNewLine(kONE + kONE) << "The First Letters every Word : " << functionCreateNewLine(kONE);

		for (Integer counter{ kZERO }; counter < text.size(); counter++) {

			if ((text[counter] != ' ' && isFirstLetter)) {

				if ((isupper(text[counter])))
					cout << convertionUpperCharToLower(text[counter]) << endl;
				else
					cout << text[counter] << endl;

				//	text[counter] = convertionLowerCharToUpperGenaral(text[counter]);
			}

			isFirstLetter = (text[counter] == ' ') ? true : false;

		}
	};

	inline void printEveryFirstLetterLowerInText() {
		printEveryFirstLetterLowerInText(_Text);
	};

	//Convert All Letter if letter Lower convert the letter to Upper , and if the Letter Upper convert the lower 
	static inline string convertAllCharacter(string text) {

		for (Integer counter{ kZERO }; counter < text.size(); counter++) {

			if (islower(text[counter]))
				text[counter] = convertionLowerCharToUpper(text[counter]);
			else
				text[counter] = convertionUpperCharToLower(text[counter]);

		}

		return text;
	};

	string inline convertAllCharacter() {
		convertAllCharacter(_Text);
	};

	static unsigned short Integer countLetter(string const& kTEXT, enChoiseLetter choiseCountLetter = enChoiseLetter::kALL) {

		unsigned short Integer countLetter{ kZERO };

		if (choiseCountLetter == enChoiseLetter::kALL)
			return kTEXT.size();

		for (Integer counter{ kZERO }; counter < kTEXT.size(); counter++) {

			if (islower(kTEXT[counter]) && choiseCountLetter == enChoiseLetter::kSMALL_LETTERS) ++countLetter;
			else if (isupper(kTEXT[counter]) && choiseCountLetter == enChoiseLetter::kCAPITAL_LETTERS) ++countLetter;

		}
		return countLetter;
	};

	unsigned short Integer countLetter() {
		return countLetter(_Text, _ChoiseLetterConvert);
	};

	inline static string ConvertLetter(string text, enChoiseLetter choiseCountLetter = enChoiseLetter::kALL) {

		if (choiseCountLetter == enChoiseLetter::kALL)
			return convertAllCharacter(text);

		for (Integer counter{ kZERO }; counter < text.size(); counter++) {

			if (choiseCountLetter == enChoiseLetter::kCAPITAL_LETTERS && islower(text[counter])) {
				text[counter] = convertionLowerCharToUpper(text[counter]);
			}
			else if (choiseCountLetter == enChoiseLetter::kSMALL_LETTERS && isupper(text[counter])) {
				text[counter] = convertionUpperCharToLower(text[counter]);
			}
		}

		return text;
	};

	inline  string ConvertLetter() {

		return ConvertLetter(_Text, _ChoiseLetterConvert);

	};

	static inline unsigned short Integer countLetterSpecific(string const& kTEXT, Character const& kCHARACTER) {

		unsigned short Integer countLetter{ kZERO };

		for (Integer counter{ kZERO }; counter < kTEXT.size(); counter++) {

			if (kTEXT[counter] == kCHARACTER)++countLetter;

		}
		return countLetter;
	};

	unsigned short Integer countLetterSpecific() {

		return countLetterSpecific(_Text, _Character);

	};


	static inline unsigned short Integer countLetterSpecificMatchCase(string text, Character const& kCHARACTER, bool matchCase = false) {

		unsigned short Integer countLetter{ kZERO };


		for (Integer counter{ kZERO }; counter < text.size(); counter++) {

			if (matchCase) {

				text = ConvertLetter(text, enChoiseLetter::kSMALL_LETTERS);
				if ((text[counter] == tolower(kCHARACTER))) ++countLetter;

			}
			else
				if ((text[counter] == kCHARACTER))++countLetter;

		}
		return countLetter;
	};

	unsigned short Integer countLetterSpecificMatchCase() {
		return countLetterSpecificMatchCase(_Text, _Character, _IsMatchCase);
	};


	static inline bool isVowelCharacter(Character const& kCHARACTER) {

		string const kTEXT_HAVE_CHARACTER_VOWEL{ "aoiue AOIUE" };
		return kTEXT_HAVE_CHARACTER_VOWEL.find(kCHARACTER) != string::npos;

	};

	bool isVowelCharacter() {

		return  isVowelCharacter(_Character);

	};

	static inline unsigned short Integer countOfVowelCharacter(string const& kTEXT) {

		unsigned short Integer counterVowelLetterInText{ kZERO };
		for (Character const character : kTEXT) {
			if (isVowelCharacter(character)) ++counterVowelLetterInText;
		}
		return counterVowelLetterInText;
	};

	unsigned short Integer countOfVowelCharacter() {

		return countOfVowelCharacter(_Text);

	};

	static inline void printAllVowelInText(string const& kTEXT) {

		cout << "\n The Vowel Letter in the Text is : \n[ ";

		for (Integer counter{ kZERO }; counter < kTEXT.size(); counter++) {

			if (isVowelCharacter(kTEXT[counter]))
				if (kTEXT[counter] == ' ') continue;
				else
					cout << kTEXT[counter] << separatorSpecificArray(kTEXT.size(), counter, " , ");
		}

		cout << "]" << functionCreateNewLine(kONE);
	};


	void printAllVowelInText() {
		printAllVowelInText(_Text);
	};


	static inline void printEachWordInText(string  text, string const& kDELIMETER = " ") {

		Integer positionWord{ kZERO };
		string newWord{ "" };
		cout << functionCreateNewLine(kONE + kONE) << "All the Word in the Text :" << functionCreateNewLine(kONE + kONE);
		while ((positionWord = text.find(kDELIMETER)) != std::string::npos) {

			newWord = text.substr(kZERO, positionWord);

			if (newWord != "")
				cout << newWord << endl;

			text.erase(kZERO, positionWord + kDELIMETER.size());

		}

		if (!text.empty())
			cout << text << endl;

	};


	void printEachWordInText() {
		printEachWordInText(_Text, " ");
	};


	static inline unsigned short Integer countOfEachWordInTheText(string  text, string const& kDELIMETER = " ") {

		Integer positionWord{ kZERO };
		string newWord{ "" };
		unsigned short Integer counterWord{ kZERO };

		while ((positionWord = text.find(kDELIMETER)) != std::string::npos) {

			newWord = text.substr(kZERO, positionWord);

			if (newWord != "")
				++counterWord;

			text.erase(kZERO, positionWord + kDELIMETER.size());

		}

		if (!text.empty())
			++counterWord;

		return counterWord; ;
	}
	unsigned short Integer countOfEachWordInTheText() {

		return countOfEachWordInTheText(_Text, " ");

	};


	static inline  vector <string> splitWordInText(string  text, string const& kDELIMETER = " ") {

		vector <string> splitWord{ "" };

		Integer positionWord{ kZERO };
		string newWord{ "" };


		while ((positionWord = text.find(kDELIMETER)) != std::string::npos) {

			newWord = text.substr(kZERO, positionWord);

			if (newWord != "")
				splitWord.emplace_back(newWord);

			text.erase(kZERO, positionWord + kDELIMETER.size());

		}

		if (!text.empty())
			splitWord.emplace_back(text);

		return splitWord;
	};

	vector <string> splitWordInText() {

		return splitWordInText(_Text, " ");

	};

	static inline string trimleft(string text) {

		for (short counter = kZERO; counter < text.length(); counter++) {

			if (text[counter] != ' ') {
				return text.substr(counter, text.length() - counter);

			}
		}

		return"";
	};

	string trimleft() {

		return trimleft(_Text);

	};

	static inline  string trimRight(string const kTEXT) {

		int counter = static_cast<int>(kTEXT.size()) - kONE;

		while (counter >= kZERO && kTEXT[counter] == ' ')
			counter--;
		return kTEXT.substr(kZERO, counter + kONE);
	};

	string trimRight() {
		return trimRight(_Text);
	};

	static inline string trimString(string const kTEXT) {
		return trimRight(trimleft(kTEXT));
	};

	string  trimString() {
		return trimString(_Text);
	};

	static inline string JoinString(vector<string> vecString, string const& kDELIMETER = " ") {

		string newWord{ "" };

		for (string& const word : vecString) {
			newWord += word + kDELIMETER;

		}
		Integer length = newWord.length();

		return newWord.substr(kZERO, length - kDELIMETER.size());
	};


	string JoinString() {

		return JoinString(_VecString, " ");
	};

	string ReverseWordsInString(string text) {

		vector<string> vString;

		string S2 = "";

		vString = splitWordInText(text, " ");

		// declare iterator

		vector<string>::iterator iter = vString.end();
		while (iter != vString.begin())
		{
			--iter;
			S2 += *iter + " ";
		}
		S2 = S2.substr(kZERO, S2.length() - kONE);

		//remove last 	space.
		return S2;
	};


	static inline string replaseWords(string wordOrginal, string wordReplase, string const& kWORD_TO_REPLACE) {

		int position = wordOrginal.find(wordReplase);

		while (position != string::npos) {
			wordOrginal = wordOrginal.replace(position, wordReplase.length(), kWORD_TO_REPLACE);
			position = wordOrginal.find(wordReplase);

		}
		return wordOrginal;
	};


	static inline string RemovePunctuationsFromString(string const& kTEXT) {

		string newWord = "";
		for (Integer counter{ kZERO }; counter < kTEXT.length(); counter++) {
			if (!ispunct(kTEXT[counter])) {
				newWord += kTEXT[counter];
			}

		}
		return newWord;
	};

	string RemovePunctuationsFromString() {

		return RemovePunctuationsFromString(_Text);
	};

};

