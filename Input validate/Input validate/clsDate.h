#pragma once
#pragma warning ( disable : 4996 ) 

#include <iostream> 
#include <ctime> 
#include <string> 
#include<vector> 
#include <time.h>
#include <locale.h>
#include<iomanip> 
#include"clsString.h" 




using namespace std;


class clsDate
{

private:

#define Integer  int 

	//Enumrations 


	enum enDayOfWeek {

		kSUNDAY = 0,
		kMONDAY = 1,
		kTUESDAY = 2,
		kWEDNESDAY = 3,
		kTHURSDAY = 4,
		kFRIDAY = 5,
		kSATURDAY = 6
	};

	enum enMounth {

		kJANUARY = 0,
		kFEBRUARY = 1,
		kMARCH = 2,
		kAPRIL = 3,
		kMAY = 4,
		kJUNE = 5,
		kJULY = 6,
		kAUGUST = 7,
		kSEPTEMBER = 8,
		kOCTOBER = 9,
		kNOVEMBER = 10,
		kDECEMBER = 11,
	};

	
	//Constants 

	static unsigned short Integer const _kZERO{ 0 };
	static unsigned short Integer const _kONE_HUNDRED{ 100 };
	static unsigned short Integer const _kFOUR_HUNDRED{ 400 };
	static unsigned short Integer const _kNUMBER_FOUR{ 4 };
	static unsigned short Integer const _kNUMBER_DAY_IN_YEAR_ORGINAL{ 365 };
	static unsigned short Integer const _kNUMBER_HOUR_IN_DAY{ 24 };
	static unsigned short Integer const _kNUMBER_MINTUES_IN_DAY{ 60 };
	static unsigned short Integer const _kNUMBER_SECOUNDS_IN_DAY{ 60 };
	static unsigned short Integer const _kNUMBER_OF_WEEK{ 7 };
	static unsigned short Integer const _kNUMBER_MONTH{ 12 };
	static unsigned short Integer const _kNUMBER_FIRST_MONTH{ 1 };
	static unsigned short Integer const _kONE{ 1 };
	static unsigned short Integer const _kNUMBER_ONE_DECADE{ 10 };
	static unsigned short Integer const _kNUMBER_ONE_CENTURY{ 100 };
	static unsigned short Integer const _kNUMBER_ONE_MILLENNIUM{ 1000 };

	// Members 

	unsigned short Integer _Year{};
	unsigned short Integer _Month{};
	unsigned short Integer _Day{};


public:

	static enum enCompareTwoDate {

		kBEFORE = -1,
		kEQUAL = 0,
		kAFTER = 1
	};

	friend class clsPeriod;

	clsDate() {

		time_t timee = time(NULL);
		tm* timeUTC = localtime(&timee);

		_Day = timeUTC->tm_mday;
		_Month = timeUTC->tm_mon + 1;
		_Year = timeUTC->tm_year + 1900;

	};

	/*
	clsDate(string Date ) {

		vector<string> vDate = clsString::splitWordInText(Date, "/");


				setDay( stoi(vDate[0]));
				setMonth( stoi(vDate[1]));
				setYear ( stoi(vDate[2]));



	}
	*/
	clsDate(unsigned short const& kDAY, unsigned short const& kMONTH, unsigned short const& kYEAR)

		: _Year{ kYEAR }, _Month{ kMONTH }, _Day{ kDAY } {
	};


	clsDate(unsigned short Integer numberOfDay, unsigned short const& kYEAR) {

		clsDate date = convertNumberBeginingYearToDate(kYEAR, numberOfDay);

		_Year = date._Year;
		_Day = date._Day;
		_Month = date._Month;

	};

	void setYear(unsigned short Integer const _kYEAR) {
		this->_Year = _kYEAR;
	}

	unsigned short Integer getYear(void) {
		return this->_Year;
	}

	__declspec (property (get = getYear, put = setYear)) unsigned short Integer YEAR;

	void setMonth(unsigned short Integer const _kMONTH) {
		this->_Month = _kMONTH;
	}

	unsigned short Integer getMonth(void) {
		return this->_Month;
	}
	__declspec (property (get = getMonth, put = setMonth)) unsigned short Integer MONTH;

	void setDay(unsigned short Integer const _kDAY) {
		this->_Day = _kDAY;
	}

	unsigned short Integer getDay(void) {
		return this->_Day;
	}
	__declspec (property (get = getDay, put = setDay)) unsigned short Integer DAY;


	clsDate ReadInformationDateInSystem(void) {

		clsDate date(0, 0, 0);

		time_t  timee = time(NULL);
		tm* timeUTC = localtime(&timee);

		date.setDay(timeUTC->tm_mday);
		date.setMonth(timeUTC->tm_mon + 1);
		date.setYear(timeUTC->tm_year + 1900);

		return date;
	}



	static inline bool isLeapYear(unsigned short Integer const kYEAR) {

		if (kYEAR % _kFOUR_HUNDRED == _kZERO) //kFOUR_HUNDRED --> 400 
			return true;
		else if (kYEAR % _kONE_HUNDRED == _kZERO) //kONE_HUNDRED --> 100 
			return false;
		else if (kYEAR % _kNUMBER_FOUR == _kZERO) //kNUMBER_FOUR --> 4 
			return true;

		else
			return false;

		//return (kYEAR % 4 == _kZERO && kYEAR % 100 != _kZERO) || (kYEAR % 400 == _kZERO);
		//return kYEAR % 100 == _kZERO ? kYEAR % 400 == _kZERO : kYEAR % 4 == _kZERO; 
	};

	bool isLeapYear(void) {
		return isLeapYear(_Year);
	};



	//Return the number of days if leap 366 and non-leap 365
	static inline unsigned short Integer numberOfDayInYear(unsigned short Integer const kYEAR) {

		return isLeapYear(kYEAR) ? _kNUMBER_DAY_IN_YEAR_ORGINAL + _kONE : _kNUMBER_DAY_IN_YEAR_ORGINAL;
	};

	unsigned short Integer numberOfDayInYear(void) {
		return  numberOfDayInYear(_Year);
	};


	static inline unsigned short Integer numberOfDayInMonth(unsigned short Integer const kYEAR, unsigned short Integer const kMONTH) {

		if (kMONTH < _kONE || kMONTH >  _kNUMBER_MONTH) return _kZERO;

		//unsigned short Integer const kDAY_OF_MONTH[13]{ kZERO , 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 }; 
		unsigned short Integer const kDAY_OF_MONTH[13]{ _kZERO , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 1 , 0 , 1 , 0 , 1 };
		return (kMONTH == 2) ? isLeapYear(kYEAR) ? 29 : 28 : kDAY_OF_MONTH[kMONTH] + 30;

		//return (kMONTH == 2)? isLeapYear(kYEAR) ? 29 : 28  : kDAY_OF_MONTH[kMONTH]  ;
	};

	unsigned short Integer numberOfDayInMonth(void) {
		return numberOfDayInMonth(_Year, _Month);
	};


	// --------------------------------- Calc year ----------------------------------


	//Calculating the number of hours in a day 
	static inline Integer calcNumberOfHourInYear(Integer const kYEAR) {

		return (numberOfDayInYear(kYEAR) * _kNUMBER_HOUR_IN_DAY);

	}
	Integer calcNumberOfHourInYear(void) {
		return calcNumberOfHourInYear(_Year);
	};

	//Calculating the number of minutes in a day
	static inline Integer calcNumberOfMinutsInYear(Integer const kYEAR) {
		return (_kNUMBER_MINTUES_IN_DAY * calcNumberOfHourInYear(kYEAR));
	};

	Integer calcNumberOfMinutsInYear(void) {
		return calcNumberOfMinutsInYear(_Year);
	};

	//Calculating the number of Secoounds in a day
	static inline Integer calcNumberOfSecoundsInYear(Integer const kYEAR) {
		return (_kNUMBER_SECOUNDS_IN_DAY * calcNumberOfMinutsInYear(kYEAR));
	};

	Integer calcNumberOfSecoundsInYear(void) {
		return calcNumberOfSecoundsInYear(_Year);
	};

	// --------------------------------- Calc month ----------------------------------

	 //Calculating the number of hours in a month 
	static inline Integer calcNumberOfHourInMonth(Integer const kYEAR, Integer const kMONTH) {

		return (numberOfDayInMonth(kYEAR, kMONTH) * _kNUMBER_HOUR_IN_DAY);

	};

	Integer calcNumberOfHourInMonth(void) {
		return  calcNumberOfHourInMonth(_Year, _Month);
	};


	//Calculating the number of minutes in a month
	static inline Integer calcNumberOfMinutsInMonth(Integer const kYEAR, Integer const kMONTH) {
		return (_kNUMBER_MINTUES_IN_DAY * calcNumberOfHourInMonth(kYEAR, kMONTH));
	};

	Integer calcNumberOfMinutsInMonth(void) {
		return calcNumberOfMinutsInMonth(_Year, _Month);
	};


	//Calculating the number of Secoounds in a month
	static inline Integer calcNumberOfSecoundsInMonth(Integer const kYEAR, Integer const kMONTH) {
		return (_kNUMBER_SECOUNDS_IN_DAY * calcNumberOfMinutsInMonth(kYEAR, kMONTH));
	};

	Integer calcNumberOfSecoundsInMonth(void) {
		return calcNumberOfSecoundsInMonth(_Year, _Month);
	};

	// ----------------------------------- Date Formating -------------------------------------


	static inline void printDateFormat(clsDate& date, string const kSEPARATOR = "/") {

		cout << date._Day << kSEPARATOR << date._Month << kSEPARATOR << date._Year << '\n';

	}

	void printDateFormat(void) {
		return printDateFormat(*this, "/");
	};


	static inline unsigned short Integer findTheOrderOfDayInWeek(unsigned short Integer const kYEAR, unsigned short Integer const kMOUNTH, unsigned short Integer const kDAY = { 1 }) {

		unsigned short Integer const kNUMBER_FOUTEEN{ 14 };
		unsigned short Integer const kNUMBER_MOUNTH_OF_YEAR{ _kNUMBER_MONTH };
		unsigned short Integer const kNUMBER_DAY_OF_WEEK{ 7 };

		unsigned short Integer const a = ((kNUMBER_FOUTEEN - kMOUNTH) / kNUMBER_MOUNTH_OF_YEAR);
		unsigned short Integer const year = kYEAR - a;

		unsigned short Integer const mounth = kMOUNTH + (a * kNUMBER_MOUNTH_OF_YEAR) - 2;

		unsigned short Integer const dayBornOrder = (kDAY + year + (year / 4) - (year / 100) + (year / 400) + ((31 * mounth) / kNUMBER_MOUNTH_OF_YEAR)) % kNUMBER_DAY_OF_WEEK;


		return dayBornOrder;
	}




	static inline unsigned short Integer findTheOrderOfDayInWeek(clsDate& date) {

		return findTheOrderOfDayInWeek(date._Year, date._Month, date._Day);
	};

	unsigned short Integer findTheOrderOfDayInWeek(void) {

		return  findTheOrderOfDayInWeek(*this);
	};


	static inline string findDayOfWeekString(const enDayOfWeek kDAY_INDEX_ORDER, bool IS_FULL_NAME_DAY = false) {

		string dayOfWeek[_kNUMBER_OF_WEEK]{ "Sun" , "Mon" , "Tue" , "Wed" , "Thu" , " Fri " , " Sat" };

		string dayOfWeekFull[_kNUMBER_OF_WEEK]{ "Sunday", "Monday", "Tuesday", "Wedneday", "Thursday", " Friday ", " Saturday" };

		return IS_FULL_NAME_DAY ? dayOfWeekFull[kDAY_INDEX_ORDER] : dayOfWeek[kDAY_INDEX_ORDER];
	};

	static inline string findNameMounthString(const enMounth kMUNTH_INDEX_ORDER, bool IS_FULL_NAME_DAY = false) {

		string Mounth[_kNUMBER_MONTH]{ "Jan" , "Feb" , "Mar" , "Apr" , "May" , " Jun " , " Jul" , "Aug" , "Sep" , "Oct" , "Nov" , "Dec" };

		string Mounth_FullName[_kNUMBER_MONTH]{ "January" , "February" , "March" , "April" , "May" , " June" , "July" , "August" , "Septemper" , "Octobar" , "November" , "December" };

		return IS_FULL_NAME_DAY ? Mounth_FullName[kMUNTH_INDEX_ORDER - _kONE] : Mounth[kMUNTH_INDEX_ORDER - _kONE];
	};

	string findNameMounthStringNonStatic(const enMounth kMONTH_INDEX_ORDER, bool IS_FULL_NAME_DAY_BOOL = false) {

		return findNameMounthString(kMONTH_INDEX_ORDER, IS_FULL_NAME_DAY_BOOL);

	};


	static inline  void printCalenderOfMonth(unsigned short Integer const kYEAR, unsigned short Integer const kMOUNTH) {


		printf("\n\n----------------- %s -----------------\n\n",
			findNameMounthString(static_cast <enMounth> (kMOUNTH)).c_str()
		);

		printf(" Sun   Mon  Tue  Wed  Thu  Fri  Sat\n");

		unsigned short Integer const currentOrderDay{ findTheOrderOfDayInWeek(kYEAR, kMOUNTH) };
		unsigned short Integer const numberOfDayMonth{ numberOfDayInMonth(kYEAR, kMOUNTH) };

		Integer counter{ _kZERO };
		for (; counter < currentOrderDay; counter++)
			printf("     ");

		for (Integer counterJ{ _kONE }; counterJ <= numberOfDayMonth; counterJ++) {

			printf("%5d", counterJ);

			if (++counter == _kNUMBER_OF_WEEK) {
				counter = { _kZERO };
				printf("\n");
			}

		}

		printf("\n\n---------------------------------------");
	};


	void printCalenderOfMonth(void) {

		printCalenderOfMonth(_Year, _Month);
	};

	static inline void printAllMonthCalenderAccordingYear(unsigned short Integer const kYEAR) {


		printf("\n\n---------------------------------------");
		printf("\n          Calender = %d                  ", kYEAR);
		printf("\n\n---------------------------------------");

		for (Integer counter{ _kONE }; counter <= _kNUMBER_MONTH; counter++)
			printCalenderOfMonth(kYEAR, counter);

	};

	void printAllMonthCalenderAccordingYear(void) {
		printAllMonthCalenderAccordingYear(_Year);
	};


	static inline unsigned short int numberOfBeforeBeginingYear(unsigned short Integer const kYEAR, unsigned short Integer const kMOUNTH, unsigned short Integer const kDAY = { 1 }) {

		unsigned short int totalDay{ _kZERO };

		for (Integer counter{ _kONE }; counter <= kMOUNTH - _kONE; counter++) {
			totalDay += numberOfDayInMonth(kYEAR, counter);

		}

		totalDay += kDAY;


		return totalDay;
	};

	unsigned short int numberOfBeforeBeginingYear(void) {
		return numberOfBeforeBeginingYear(_Year, _Month, _Day);
	};

	static inline  clsDate  convertNumberBeginingYearToDate(unsigned short Integer const kYEAR, unsigned short Integer const& kBEGINING_YEAR)
	{
		clsDate date(0, 0, 0);

		unsigned short Integer numberBeginingTotal{ kBEGINING_YEAR };

		date._Year = kYEAR;
		date._Month = { _kONE };

		/*		for (Integer counter{_kONE}; counter <= _kNUMBER_MONTH; counter++) {

					unsigned short Integer numbersDayInMonth{ numberOfDayInMonth(kYEAR, counter) };


					if (numberBeginingTotal > numbersDayInMonth) {

						numberBeginingTotal -= numbersDayInMonth;
						date._Month++;
					}
					else
						break;
				}

				date._Day = numberBeginingTotal;*/


		while (true) {

			unsigned short Integer numbersDayInMonth{ numberOfDayInMonth(kYEAR ,date._Month) };

			if (numberBeginingTotal > numbersDayInMonth) {

				numberBeginingTotal -= numbersDayInMonth;
				date._Month++;

			}
			else {
				date._Day = numberBeginingTotal;
				break;
			}
		}

		return date;
	};

	clsDate  convertNumberBeginingYearToDate(unsigned short Integer const& kNUMBER_OF_BEGUNING) {

		return convertNumberBeginingYearToDate(_Year, kNUMBER_OF_BEGUNING);

	};

	static inline clsDate  convertNumberBeginingYearToDateAfterAddingDays(unsigned short Integer const& kYEAR, unsigned short Integer const& kBEGINING_YEAR, unsigned short Integer const& kADDING_DAYS)
	{
		clsDate date(0, 0, 0);

		unsigned short Integer numberBeginingTotal = kBEGINING_YEAR + kADDING_DAYS;

		date._Year = kYEAR;
		date._Month = { _kONE };
		date._Day = { _kZERO };


		/*	while (true) {

				unsigned short Integer numbersDayInMonth{ numberOfDayInMonth(date._Year , date._Month) };

				if (numberBeginingTotal >= numbersDayInMonth) {

					numberBeginingTotal -= numbersDayInMonth;
					date._Month++;

					if (date._Month > 12) {
						date._Month = 1;
						date._Year++;
					}

				}
				else {

					date._Day = numberBeginingTotal;
					break;
				}
			};

			*/

		while (numberBeginingTotal > (isLeapYear(date._Year) ? 366 : 365))
		{
			numberBeginingTotal -= (isLeapYear(date._Year) ? 366 : 365);
			date._Year++;

		};

		date = convertNumberBeginingYearToDate(date._Year, numberBeginingTotal);

		return date;
	};

	clsDate  convertNumberBeginingYearToDateAfterAddingDays(unsigned short Integer const kBEGINING_YEAR, unsigned short Integer const kADDING_DAYS) {

		return convertNumberBeginingYearToDateAfterAddingDays(_Year, kBEGINING_YEAR, kADDING_DAYS);

	};

	static inline bool cheakDateOneLessThanDateTwo(clsDate& date1, clsDate& date2) {

		/*	if (date1._Year < date2._Year) {
				return true;
			}
			else if (date1._Year == date2._Year) {
				if (date1._Month < date2._Month) {
					return true;
				}
				else if (date1._Month == date2._Month) {
					if (date1._Day < date2._Day) {
						return true;
					}
				}
			}
			return false;

			*/

		return (date1._Year < date2._Year) ? true : ((date1._Year == date2._Year) ? (date1._Month < date2._Month ? true : (date1._Month == date2._Month ? date1._Day < date2._Day : false)) : false);

	};

	bool cheakDateOneLessThanDateTwo(clsDate& date2) {
		return cheakDateOneLessThanDateTwo(*this, date2);
	};

	static inline bool IsDate1EqualDate2(clsDate& date1, clsDate& date2)
	{

		return (date1._Year == date2._Year) ? ((date1._Month == date2._Month) ? ((date1._Day == date2._Day) ? true : false) : false) : false;
		//return  date1._Year == date2._Year && date1._Month == date2._Month && date1._Day == date2._Day; 

	};

	bool IsDate1EqualDate2(clsDate& date2) {

		return IsDate1EqualDate2(*this, date2);

	};


	static inline bool cheakIsLastDay(clsDate& date) {

		unsigned short Integer const  numberDayInMonthToFindLastDay{ numberOfDayInMonth(date._Year ,date._Month) };

		return (numberDayInMonthToFindLastDay == date._Day);

	};

	bool cheakIsLastDay(void) {

		return cheakIsLastDay(*this);
	};


	static inline bool cheakIsFirstDay(clsDate& date) {

		unsigned short Integer const  numberDayInMonthToFindFirstDay{ _kONE };

		return (numberDayInMonthToFindFirstDay == date._Day);

	};


	bool cheakIsFirstDay(void) {

		return cheakIsFirstDay(*this);
	};


	static inline bool cheakIsLastMonth(clsDate& date) {

		return (date._Month == _kNUMBER_MONTH);
	};

	bool cheakIsLastMonth() {
		return cheakIsLastMonth(*this);
	};

	static inline bool cheakIsFirstMonth(clsDate& date) {

		return (date._Month == _kNUMBER_FIRST_MONTH);
	};

	bool cheakIsFirstMonth(void) {
		return cheakIsFirstMonth(*this);
	};

	static inline clsDate increasingDayByOne(clsDate& date) {

		if (cheakIsLastDay(date)) {
			date._Day = { _kONE };

			if (cheakIsLastMonth(date)) {
				date._Year++;
				date._Month = { _kONE };
			}
			else
				date._Month++;

		}
		else
			date._Day++;

		return date;

	};

	clsDate increasingDayByOne(void) {

		return increasingDayByOne(*this);

	};

	static inline void SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate TempDate(0, 0, 0);

		TempDate._Year = Date1._Year;
		TempDate._Month = Date1._Month;
		TempDate._Day = Date1._Day;

		Date1._Year = Date2._Year;
		Date1._Month = Date2._Month;
		Date1._Day = Date2._Day;

		Date2._Year = TempDate._Year;
		Date2._Month = TempDate._Month;
		Date2._Day = TempDate._Day;
	};

	void SwapDates(clsDate& Date2) {

		SwapDates(*this, Date2);

	};

	static inline Integer  calcDifferanceBetweenTwoDate(clsDate date1, clsDate date2, bool flagIncludeEndDay = false) {

		Integer day{};
		short flagSwapValue{ _kONE };

		if (!cheakDateOneLessThanDateTwo(date1, date2)) {
			SwapDates(date1, date2);
			flagSwapValue = { -1 };
		}
		while (cheakDateOneLessThanDateTwo(date1, date2)) {
			day++;
			date1 = increasingDayByOne(date1);
		}

		return flagIncludeEndDay ? ++day * flagSwapValue : day * flagSwapValue;

	};

	Integer calcDifferanceBetweenTwoDate(clsDate& date2, bool flagIncludeEndDay = false) {

		return calcDifferanceBetweenTwoDate(*this, date2, flagIncludeEndDay);

	};


	///------------------------------- Date Function Incresing ------------------------------------------------ 


	static inline clsDate increasingDayByX(clsDate date, unsigned short Integer const kNUMBER_ADDING_DAY_NEW) {

		/*
		unsigned short Integer totalDayAfterCalc = kNUMBER_ADDING_DAY_NEW + date._Day;
		bool flagInisde{ true };

		while (totalDayAfterCalc >= numberOfDayInMonth(date._Year, date._Month)) {

			totalDayAfterCalc = totalDayAfterCalc - numberOfDayInMonth(date._Year, date._Month);

			if (date._Month ==  _kNUMBER_MONTH ) {
				date._Month = { _kONE };
				date._Year++;

			}
			else {

				if (totalDayAfterCalc == _kZERO ) {
					date.kDAY = kNUMBER_ADDING_DAY_NEW + _kONE ;
					flagInisde = { false };
					break;
				}

				else {
					date._Day = totalDayAfterCalc;
					date._Month++;
					flagInisde = { false };
				}
			}

		}
		if (flagInisde)
			date._Day = totalDayAfterCalc;
			*/

		for (Integer counter{ _kONE }; counter <= kNUMBER_ADDING_DAY_NEW; counter++)
			date = increasingDayByOne(date);

		return date;

	};

	clsDate increasingDayByX(unsigned short Integer const kNUMBER_ADDING_DAY_NEW) {

		return increasingDayByX(*this, kNUMBER_ADDING_DAY_NEW);

	};

	static inline clsDate increasingOneWeek(clsDate& date) {

		unsigned short Integer totalDayAfterCalc = _kNUMBER_OF_WEEK;
		return increasingDayByX(date, totalDayAfterCalc);

	};

	clsDate increasingOneWeek(void) {

		return increasingOneWeek(*this);

	};

	static inline clsDate increasingXWeek(clsDate& date, unsigned short Integer const kNUMBER_WEEK) {

		for (Integer counter{ _kONE }; counter <= kNUMBER_WEEK; counter++)
			date = increasingOneWeek(date);


		return date;
	};

	clsDate increasingXWeek(unsigned short Integer const kNUMBER_WEEK) {

		return increasingXWeek(*this, kNUMBER_WEEK);

	};

	static inline clsDate increasingXWeekFast(clsDate& date, unsigned short Integer const kNUMBER_WEEK) {

		unsigned short Integer numberWeek = _kNUMBER_OF_WEEK * kNUMBER_WEEK;
		return increasingDayByX(date, numberWeek);

	};

	clsDate increasingXWeekFast(unsigned short Integer const kNUMBER_WEEK) {

		return increasingXWeekFast(*this, kNUMBER_WEEK);
	};

	static inline clsDate increasingOneMonth(clsDate& date) {


		if (date._Month == _kNUMBER_MONTH) {
			date._Month = _kONE;
			date._Year++;
		}
		else
			date._Month++;

		//last check day in date should not exceed max days in the current month
			// example if date is 31/1/2022 increasing one month shouldnot be 31 / 2 / 2022, it should // be 28/2/2022

		unsigned short Integer const NumberOfDayOfMonth = numberOfDayInMonth(date._Year, date._Month);

		if (date._Day > NumberOfDayOfMonth)
			date._Day = NumberOfDayOfMonth;


		return date;

	};

	clsDate increasingOneMonth(void) {

		return increasingOneMonth(*this);

	};

	static inline clsDate increasingXMonth(clsDate& date, unsigned short Integer const kNUMBER_MONTH_IN_USER) {


		/*	for (Integer counter{_kONE}; counter <= _kNUMBER_MONTH; counter++) {

				if ((numberOfDayInMonth(date._Year, date._Month) % 30 == 0) && ( date._Month <= date._Month + _kNUMBER_MONTH))
					++counter2;
			}
			//unsigned short Integer numberMonth = numberOfDayInMonth(date._Year, date._Month) * _kNUMBER_MONTH ;
			return increasingDayByX(date, _kNUMBER_MONTH * 30  + counter2 );
			*/

			/*for (Integer counter = _kONE; counter <= kNUMBER_MONTH_IN_USER; counter++) {

				if (date._Month == kNUMBER_MONTH) {
					date._Month = _kONE ;
					date._Year++;
				}
				else
					date._Month++;
			}*/

		for (Integer counter{ _kONE }; counter <= kNUMBER_MONTH_IN_USER; counter++)
			date = increasingOneMonth(date);

		return date;
	};

	clsDate increasingXMonth(unsigned short Integer const kNUMBER_MONTH_IN_USER) {

		return increasingXMonth(*this, kNUMBER_MONTH_IN_USER);
	};

	static inline clsDate increasingOneYear(clsDate& date) {

		date._Year++;

		// لو التاريخ 29/2 والسنة الجديدة مش كبيسة، خليه 28
		if (date._Month == 2 && date._Day == 29 && !isLeapYear(date._Year)) {
			date._Day = 28;
		}

		return date;
	};

	clsDate increasingOneYear(void) {

		return increasingOneYear(*this);

	};

	static inline clsDate increasingXYear(clsDate& date, unsigned short Integer const kNUMBER_YEAR_INPUT_USER) {

		for (Integer counter{ _kONE }; counter <= kNUMBER_YEAR_INPUT_USER; counter++)
			date = increasingOneYear(date);

		return date;
	};

	clsDate increasingXYear(unsigned short Integer const kNUMBER_YEAR_INPUT_USER) {

		return increasingXYear(*this, kNUMBER_YEAR_INPUT_USER);
	};

	static inline clsDate increasingOneDecade(clsDate& date) {

		date._Year += _kNUMBER_ONE_DECADE;

		if (date._Month == 2 && date._Day == 29 && !isLeapYear(date._Year)) {
			date._Day = 28;
		}
		return date;
	};

	clsDate increasingOneDecade(void) {

		return increasingOneDecade(*this);

	};

	static inline clsDate increasingXDecade(clsDate& date, unsigned short Integer const kNUMBER_DECADE) {

		date._Year += _kNUMBER_ONE_DECADE * kNUMBER_DECADE;

		if (date._Month == 2 && date._Day == 29 && !isLeapYear(date._Year)) {
			date._Day = 28;
		}
		return date;
	};

	clsDate increasingXDecade(unsigned short Integer const kNUMBER_DECADE) {

		return increasingXDecade(*this, kNUMBER_DECADE);

	};

	static inline clsDate increasingOneCentury(clsDate& date) {

		date._Year += _kNUMBER_ONE_CENTURY;

		if (date._Month == 2 && date._Day == 29 && !isLeapYear(date._Year)) {
			date._Day = 28;
		}
		return date;
	};

	clsDate increasingOneCentury(void) {

		return increasingOneCentury(*this);

	};

	static inline clsDate increasingOneMillennium(clsDate& date) {

		// millennium سنة ريفية 1000 عام 
		date._Year += _kNUMBER_ONE_MILLENNIUM;

		if (date._Month == 2 && date._Day == 29 && !isLeapYear(date._Year)) {
			date._Day = 28;
		}
		return date;
	};

	clsDate increasingOneMillennium(void) {

		return increasingOneMillennium(*this);
	};


	// ------------------------------------- Substracting Date ---------------------------------------

	static inline clsDate decreasingDayByOne(clsDate& date) {

		unsigned short Integer const numberLastMonth = date._Month;
		unsigned short Integer const numberLastYear = date._Year;

		if (cheakIsFirstDay(date)) {


			if (cheakIsFirstMonth(date)) {
				date._Year--;
				date._Month = { _kNUMBER_MONTH };
			}
			else
				date._Month--;


			date._Day = { numberOfDayInMonth(date._Year  ,	date._Month) };

		}
		else
			date._Day--;

		return date;

	};

	clsDate decreasingDayByOne(void) {
		return decreasingDayByOne(*this);
	};

	static inline clsDate decreasingDayByX(clsDate& date, unsigned short Integer const kNUMBER_DAY_SUBSTRACTING) {

		for (Integer counter{ _kONE }; counter <= kNUMBER_DAY_SUBSTRACTING; counter++)
			date = decreasingDayByOne(date);

		return date;


	};

	clsDate decreasingDayByX(unsigned short Integer const kNUMBER_DAY_TO_NEED_SUBSTRACTING) {

		return decreasingDayByX(*this, kNUMBER_DAY_TO_NEED_SUBSTRACTING);

	};

	static inline clsDate decreasingOneWeek(clsDate& date) {

		for (Integer counter{ _kONE }; counter <= _kNUMBER_OF_WEEK; counter++)
			date = decreasingDayByOne(date);

		return date;
	};

	clsDate decreasingOneWeek(void) {
		return decreasingOneWeek(*this);
	};

	static inline clsDate decreasingWeekX(clsDate& date, unsigned short Integer const kNUMBER_WEEK_SUBSTRACTING) {

		for (Integer counter{ _kONE }; counter <= kNUMBER_WEEK_SUBSTRACTING; counter++)
			date = decreasingOneWeek(date);

		return date;
	};

	clsDate decreasingWeekX(unsigned short Integer const kNUMBER_DAY_TO_NEED_SUBSTRACTING) {
		return decreasingWeekX(*this, kNUMBER_DAY_TO_NEED_SUBSTRACTING);
	};


	static inline clsDate decreasingOneMonth(clsDate& date) {

		if (cheakIsFirstMonth(date)) {
			date._Month = { _kNUMBER_MONTH };
			date._Year--;

		}
		else
			date._Month--;


		unsigned short Integer const numberDay{ numberOfDayInMonth(date._Year , date._Month) };
		if (date._Day > numberDay)
			date._Day = numberDay;

		return date;
	};

	clsDate decreasingOneMonth(void) {

		return decreasingOneMonth(*this);

	};


	static inline clsDate decreasingMonthX(clsDate& date, unsigned short Integer const kNUMBER_SUBSTRACTING_MONTH) {

		for (Integer counter{ _kONE }; counter <= kNUMBER_SUBSTRACTING_MONTH; counter++)
			date = decreasingOneMonth(date);

		return date;
	};

	clsDate decreasingMonthX(unsigned short Integer const kNUMBER_TO_BE_SUBSTRACTING_MONTH) {
		return decreasingMonthX(*this, kNUMBER_TO_BE_SUBSTRACTING_MONTH);
	};

	static inline clsDate decreasingOneYear(clsDate& date) {

		date._Year--;

		if (date._Day == 29 && date._Month == 2 && !isLeapYear(date._Year))
			date._Day = 28;

		return date;
	};

	clsDate decreasingOneYear(void) {

		return decreasingOneYear(*this);

	};

	static inline clsDate decreasingYearX(clsDate& date, unsigned short Integer const kNUMBER_SUBSTRACTING_YEAR) {

		for (Integer counter{ _kONE }; counter <= kNUMBER_SUBSTRACTING_YEAR; counter++)
			date = decreasingOneYear(date);

		return date;
	};

	clsDate decreasingYearX(unsigned short Integer const kNUMBER_TO_BE_SUBSTRACTING_YEAR) {

		return decreasingYearX(*this, kNUMBER_TO_BE_SUBSTRACTING_YEAR);
	};

	static inline clsDate decreasingOneDecade(clsDate& date) {

		date._Year -= _kNUMBER_ONE_DECADE;

		if (date._Day == 29 && date._Month == 2 && !isLeapYear(date._Year))
			date._Day = 28;
		return date;

	};


	clsDate decreasingOneDecade(void) {

		return decreasingOneDecade(*this);

	};

	static inline clsDate decreasingDecadeX(clsDate& date, unsigned short Integer const kNUMBER_SUBSTRACTING_DECADE) {

		for (Integer counter{ _kONE }; counter <= kNUMBER_SUBSTRACTING_DECADE; counter++)
			date = decreasingOneDecade(date);

		return date;

	};

	clsDate decreasingDecadeX(unsigned short Integer const kNUMBER_TO_BE_SUBSTRACTING_YEAR) {
		return decreasingDecadeX(*this, kNUMBER_TO_BE_SUBSTRACTING_YEAR);
	};

	static inline  clsDate decreasingOneCentury(clsDate& date) {

		date._Year -= _kNUMBER_ONE_CENTURY;

		if (date._Day == 29 && date._Month == 2 && !isLeapYear(date._Year))
			date._Day = 28;

		return date;

	};


	clsDate decreasingOneCentury(void) {

		return decreasingOneCentury(*this);
	};

	static inline clsDate decreasingOneMilleninum(clsDate& date) {

		date._Year -= _kNUMBER_ONE_MILLENNIUM;

		if (date._Day == 29 && date._Month == 2 && !isLeapYear(date._Year))
			date._Day = 28;

		return date;

	};

	// -----------------------------------------------------------------------------------------


	static inline bool isEndOfWeek(clsDate& date) {

		return (findDayOfWeekString(static_cast<enDayOfWeek> (findTheOrderOfDayInWeek(date))) == findDayOfWeekString(static_cast<enDayOfWeek> (6)));
		//return (findTheOrderOfDayInWeek(date) == 6); 

	};

	bool isEndOfWeek(void) {
		return isEndOfWeek(*this);
	};

	static inline bool isWeekendDay(clsDate& date) {

		return (findDayOfWeekString(static_cast<enDayOfWeek> (findTheOrderOfDayInWeek(date))) == findDayOfWeekString(static_cast<enDayOfWeek> (5))
			|| findDayOfWeekString(static_cast<enDayOfWeek> (findTheOrderOfDayInWeek(date))) == findDayOfWeekString(static_cast<enDayOfWeek> (6)));

		//(findTheOrderOfDayInWeek(date) == 5 || findTheOrderOfDayInWeek(date) == 6 )

	};

	bool isWeekendDay(void) {

		return isWeekendDay(*this);

	};


	static inline bool isBusinessDay(clsDate& date) {

		return !isWeekendDay(date);

	};

	bool isBusinessDay(void) {

		return isBusinessDay(*this);

	};

	static inline unsigned short Integer dayUntilEndOfWeek(clsDate& date) {

		unsigned short Integer counter{ _kZERO };
		unsigned short Integer orderDayWeek = findTheOrderOfDayInWeek(date);

		/*for (Integer i{orderDayWeek}; i < 6; i++)
				++counter;*/

		while (orderDayWeek++ != 6)
			++counter;

		return counter;

		//return 6 - findTheOrderOfDayInWeek(date._Year , date._Month , date._Day );
	};

	unsigned short Integer dayUntilEndOfWeek(void) {

		return dayUntilEndOfWeek(*this);
	};

	static inline unsigned short Integer dayUntilEndOfMonth(clsDate& date) {

		unsigned short Integer counter{ _kZERO };
		unsigned short Integer numberDayMonth = numberOfDayInMonth(date._Year, date._Month);
		unsigned short Integer Day = date._Day;

		clsDate date2(0, 0, 0);
		date2._Day = numberOfDayInMonth(date._Year, date._Month);
		date2._Month = date._Month;
		date2._Year = date._Year;

		return calcDifferanceBetweenTwoDate(date, date2, true);

		/*for (Integer i{orderDayWeek}; i < 6; i++)
				++counter;*/

				/*	while (Day++ <= numberDayMonth)
					++counter;*/


					/*	counter = numberDayMonth - Day + 1;
						return counter;*/
	};

	unsigned short Integer dayUntilEndOfMonth(void) {
		return dayUntilEndOfMonth(*this);
	};

	static inline unsigned short Integer dayUntilEndOfYear(clsDate& date) {


		/*	unsigned short Integer  numberdayUntilEndOfYear{dayUntilEndOfMonth(date)};

			for (Integer counter = { date._Month + 1 }; counter <= 12; counter++)
				numberdayUntilEndOfYear += numberOfDayInMonth(date._Year, counter);

			return numberdayUntilEndOfYear;

			*/

		clsDate date2(0, 0, 0);
		date2._Day = 31;
		date2._Month = _kNUMBER_MONTH;
		date2._Year = date._Year;

		return calcDifferanceBetweenTwoDate(date, date2, true);
	};

	unsigned short Integer dayUntilEndOfYear(void) {
		return dayUntilEndOfYear(*this);
	};

	static inline unsigned short Integer vacationDays(clsDate& date1, clsDate& date2) {

		if (!cheakDateOneLessThanDateTwo(date1, date2)) {
			SwapDates(date1, date2);
		}

		unsigned short Integer counterVacationDays{ _kZERO };

		/*	1-

			unsigned short Integer begingingDate1 = { numberOfBeginingYear(date1._Year , date1._Month , date1._Day) };
			unsigned short Integer begingingDate2 = { numberOfBeginingYear(date2._Year , date2._Month , date2._Day) };

				while (begingingDate1 <= begingingDate2) {

				unsigned short Integer orderDay{ findTheOrderOfDayInWeek(date1._Year , date1._Month , date1._Day) };

				if( (orderDay != 5) && ( orderDay != 6) )
				counterVacationDays++;

				date1 = increasingDayByOne(date1);
				orderDay = { findTheOrderOfDayInWeek(date1.kYEAR , date1._Month , date1.kDAY) };

				begingingDate1 = { numberOfBeginingYear(date1._Year , date1._Month , date1._Day) };
				begingingDate2 = { numberOfBeginingYear(date2._Year , date2._Month , date2._Day) };

			}
				return counterVacationDays - 1   ;
			*/

		while (cheakDateOneLessThanDateTwo(date1, date2)) {

			unsigned short Integer orderDay{ findTheOrderOfDayInWeek(date1._Year , date1._Month , date1._Day) };

			if (isBusinessDay(date1))
				counterVacationDays++;

			date1 = increasingDayByOne(date1);
			orderDay = { findTheOrderOfDayInWeek(date1._Year , date1._Month , date1._Day) };

		}

		return counterVacationDays;
	};


	unsigned short Integer vacationDays(clsDate& date2) {
		return vacationDays(*this, date2);

	};

	static inline clsDate returnDateAccordingVacationDays(clsDate& date, unsigned short Integer const  kVACATION_DAY) {

		Integer counter{ _kZERO };


		while (counter < kVACATION_DAY) {

			if (isBusinessDay(date)) {
				++counter;
			}
			if (counter < kVACATION_DAY) date = increasingDayByOne(date);
		}

		//Day of return day in the work 
		date = increasingDayByOne(date);


		return date;

	};

	clsDate returnDateAccordingVacationDays(unsigned short Integer const kVACATION_DAY_CURRENT) {

		return returnDateAccordingVacationDays(*this, kVACATION_DAY_CURRENT);

	};

	static inline bool Date1AfterDate2(clsDate& date1, clsDate& date2) {

		//return (cheakDateOneLessThanDateTwo(date1, date2) == false);
		return (cheakDateOneLessThanDateTwo(date2, date1) && !IsDate1EqualDate2(date1, date2));

	};

	bool Date1AfterDate2(clsDate& date2) {

		return Date1AfterDate2(*this, date2);
	};


	static inline short Integer compareTwoDates(clsDate& const date1, clsDate& const date2) {


		if (IsDate1EqualDate2(date1, date2))
			return enCompareTwoDate::kEQUAL;
		else if (cheakDateOneLessThanDateTwo(date1, date2))
			return enCompareTwoDate::kBEFORE;

		/*else if (Date1AfterDate2(date1, date2))
			return enCompareTwoDate::kAFTER ;

		else _kZERO; */
		return enCompareTwoDate::kAFTER;

		//return (IsDate1EqualDate2(date1, date2) ? _kZERO : (cheakDateOneLessThanDateTwo(date1, date2) ? -1 : (Date1AfterDate2(date1, date2) ? 1 : 0)));
	};

	short Integer compareTwoDates(clsDate& date2) {

		return compareTwoDates(*this, date2);

	};

	//----



	static inline bool validationDate(clsDate date) {

		if (date._Month < _kONE || date._Month > _kNUMBER_MONTH) return false;

		unsigned short Integer numberDayMonth = numberOfDayInMonth(date._Year, date._Month);
		if (numberDayMonth < date._Day) return false;

		// is case not entered in the before two if statment 
		return true;
	}

	bool validationDate(void) {
		return validationDate(*this);
	};

	static inline string readDate(const string kMESSAGE) {

		string dateInfo{ "" };

		cout << kMESSAGE;
		getline(cin, dateInfo);

		return dateInfo;

	};


	static inline clsDate fillDateInformation(vector<string> const& kINFORMATION_DATE, string const kSEPARATOR = "/") {

		clsDate dateInfo(0, 0, 0);

		if (kINFORMATION_DATE.size() > 2) {
			dateInfo._Day = stoi(kINFORMATION_DATE[0]);
			dateInfo._Month = stoi(kINFORMATION_DATE[1]);
			dateInfo._Year = stoi(kINFORMATION_DATE[2]);
		}
		return dateInfo;

	};

	static inline string replaseDatekDAY_kMONTH_kYEAR_FormatDate(clsDate& date, string replace = "dd/mm/yyyy") {

		string dateFormat = "";

		dateFormat = clsString::replaseWords(replace, "dd", to_string(date._Day));
		dateFormat = clsString::replaseWords(dateFormat, "mm", to_string(date._Month));
		dateFormat = clsString::replaseWords(dateFormat, "yyyy", to_string(date._Year));
		dateFormat = clsString::replaseWords(dateFormat, "yy", to_string(date._Year % 100));
		dateFormat = clsString::replaseWords(dateFormat, "DDDD", findDayOfWeekString(static_cast <enDayOfWeek> (findTheOrderOfDayInWeek(date._Year, date._Month, date._Day)), true));
		dateFormat = clsString::replaseWords(dateFormat, "MMM", findNameMounthString(static_cast <enMounth> (date._Month)));
		dateFormat = clsString::replaseWords(dateFormat, "Month", findNameMounthString(static_cast <enMounth> (date._Month), true));

		return dateFormat;
	}

};

