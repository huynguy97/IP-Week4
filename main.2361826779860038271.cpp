//                      
//                                  

//                  
//                                   
//                                     

#include <iostream>

using namespace std;

enum Month {January=1,February,March,April,May,June,July,August,September,October,November,December} ;

/*                                                                          
                                                                            
                                                           
*/
int easter_base ( int year )
{
    const int A     = year % 19 ;
    const int B     = year / 100 ;
    const int C     = year % 100 ;
    const int D     = B / 4 ;
    const int E     = B % 4 ;
    const int F     = (B + 8) / 25 ;
    const int G     = (B - F + 1) / 3 ;
    const int H     = (19 * A + B - D - G + 15) % 30 ;
    const int I     = C / 4 ;
    const int K     = C % 4 ;
    const int L     = (32 + 2 * E + 2 * I - H - K) % 7 ;
    const int M     = (A + 11 * H + 22 * L) / 451 ;
    return H + L - 7 * M + 114 ;
}

/*                                                                                    
                   
*/
int easter_day ( int year )
{
    return (easter_base (year) % 31) + 1 ;
}

/*                                                                                   
*/
Month easter_month ( int year )
{
    return static_cast<Month> (easter_base (year) / 31) ;
}

/*                                                                   
                                 
                                                                   */

//                                                                                 
bool is_leap_year ( int year )
{
	if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//                                                                                               
void leapYear()
{
	cout << "Please enter the year number of the year you want to check." << endl;
	int year;
	cin >> year;
	bool leapYear = is_leap_year(year);
	if(leapYear)
	{
		cout << "The year " << year << " is a leap year!\n" << endl;
	}
	else
	{
		cout << "The year " << year << " is not a leap year!\n" << endl;
	}
}

//                                                                   
int getDaysYearMonth(int year, Month month)
{
	switch(month) {
		case 1:
			return 31;
		case 2:
			if(is_leap_year(year))
			{
				return 29;
			}
			else
			{
				return 28;
			}
		case 3:
			return 31;
		case 4:
			return 30;
		case 5:
			return 31;
		case 6:
			return 30;
		case 7:
			return 31;
		case 8:
			return 31;
		case 9:
			return 30;
		case 10:
			return 31;
		case 11:
			return 30;
		case 12:
			return 31;
	}
	return 0;
}

//                                                                         
void number_of_days_in_month ( int year, Month month )
{
	int days = getDaysYearMonth(year, month);
	Month m = static_cast<Month>(month);

	cout << "In year " << year << ", the month " << m << " had " << days << " days!\n" << endl;

}

//                                                     
void daysInMonth()
{
	cout << "Please enter the year you want to check!" << endl;
	int year;
	cin >> year;
	cout << "Please enter the month you want to check! (number)" << endl;
	int monthint;
	cin >> monthint;
	if(monthint > 0 && monthint < 13)
	{
		Month m = static_cast<Month>(monthint);
		number_of_days_in_month(year, m);
	}
	else
	{
		cout << "Invalid month input. Please use a number from 1-12!\n" << endl;
	}
}

/*                                                                   
                                                
                                                                   */

//                                                                    
void showCarnival(int year, int day, int month)
{
	int carnivalday = 49 - day;
	int carnivalmonth = month - 1;
	int time = -1;
	while(carnivalday > 0)
	{
		int daysInMonth = getDaysYearMonth(year, static_cast<Month>(carnivalmonth));
		if(carnivalday > daysInMonth)
		{
			carnivalday -= daysInMonth;
			carnivalmonth -= 1;
		}
		else
		{
			time = daysInMonth - carnivalday;
			carnivalday = 0;
		}
	}
	if(time != -1)
	{
		cout << "Carnival - day: " << time << ", month: " << carnivalmonth << endl;
	}
	else
	{
		cout << "Carnival - day: " << carnivalday << ", month: " << carnivalmonth << endl;
	}
}

//                                                                       
void showGoodFriday(int year, int day, int month)
{
	day = day - 2;
	while(day < 0)
	{
		int days = getDaysYearMonth(year, static_cast<Month>(month));
		day += days;
		month -= 1;
	}
	cout << "Good Friday - day: " << day << ", month: " << month << endl;
}

//                                                                     
void showAscension(int year, int day, int month)
{
	day = day + (7 * 7 - 10);
	while(day > getDaysYearMonth(year, static_cast<Month>(month)))
	{
		int days = getDaysYearMonth(year, static_cast<Month>(month));
		day -= days;
		month += 1;
	}
	cout << "Ascension day - day: " << day << ", month: " << month << endl;
}

//                                                                       
void showWhitsuntide(int year, int day, int month)
{
	day = day + (7 * 7);
	while(day > getDaysYearMonth(year, static_cast<Month>(month)))
	{
		int days = getDaysYearMonth(year, static_cast<Month>(month));
		day -= days;
		month += 1;
	}
	cout << "Whitsuntide - day: " << day << ", month: " << month << endl;
}

//                                                                                                          
void show_holy_days (int year)
{
    int day = easter_day(year);
    Month month = easter_month(year);

    showCarnival(year, day, month);

    showGoodFriday(year, day, month);

    cout << "Easter - day: " << day << ", month: " << month << endl;

    showAscension(year, day, month);

    showWhitsuntide(year, day, month);

    cout << "\n";
}

//                                                                         
void holyDays()
{
	cout << "Please enter the year you want to receive the holy days from." << endl;
	int year;
	cin >> year;
	show_holy_days(year);
}

//                                                               

//                                                
//                                                                          
//                                                                                            
//                                                       
int firstDayOfYear(int year)
{
	const int A = (year - 1) % 400;
	const int B = 6 * A;
	const int C = (year - 1) % 100;
	const int D = 4 * C;
	const int E = (year - 1) % 4;
	const int F = 5 * E;
	const int G = (1 + F + D + B);
	const int H = G % 7;

	return H;
}

//                                                              
//                                                   
int getAmountOfDays(int year, Month month)
{
	int m = static_cast<Month>(month);
	int delta = m - 1;
	int totaldays = 0;
	for(int i = 1; i <= delta; i++)
	{
		int daysinmonth = getDaysYearMonth(year, static_cast<Month>(i));
		totaldays += daysinmonth;
	}
	return totaldays;
}

//                                                                                                   
//                                                        
//                                                                    
void show_month(int year, Month month)
{
	//                                          
	int firstDay = firstDayOfYear(year);
	if(firstDay == 0)
	{
		firstDay = 7;
	}
	firstDay--;

	//                                                                 
	int rawfirstdayofmonth = getAmountOfDays(year, month) + firstDay;
	int firstdayofmonth = rawfirstdayofmonth % 7;
	int tabs = firstdayofmonth;

	int daysinmonth = getDaysYearMonth(year, month);

	//                       
	cout << "Mo\tTu\tWe\tTh\tFr\tSa\tSu" << endl;

	//                       
	while(tabs > 0)
	{
		cout << "\t";
		tabs --;
	}

	//                                               
	for(int i = 1; i <= daysinmonth; i++)
	{
		cout << i << "\t";
		firstdayofmonth ++;
		if(firstdayofmonth > 6)
		{
			firstdayofmonth = 0;
			cout << "\n";
		}
	}
	cout << "\n" << endl;
}

//                                                 
void show_months()
{
	cout << "Please enter the year you want to check!" << endl;
	int year;
	cin >> year;
	cout << "Please enter the month you want to check!" << endl;
	int monthint;
	cin >> monthint;
	if(monthint > 0 && monthint < 13)
	{
		Month m = static_cast<Month>(monthint);
		show_month(year, m);
	}
	else
	{
		cout << "Invalid month input. Please use a number from 1-12!\n" << endl;
	}
}

//                                                                                       
int main()
{
	while(true)
	{
		cout << "Which algorithm do you want to run? Type it's number to run it!\n" <<
				"(1) - Leap year calculation.\n" <<
				"(2) - Amount of days in a month calculation.\n" <<
				"(3) - Show the holy days for easter.\n" <<
				"(4) - Calendar algorithm (BONUS)\n" <<
				"(5) - Terminate program." << endl;
		int mode;
		cin >> mode;
		if(mode == 1)
		{
			leapYear();
		}
		else if(mode == 2)
		{
			daysInMonth();
		}
		else if(mode == 3)
		{
			holyDays();
		}
		else if(mode == 4)
		{
			show_months();
		}
		else if(mode == 5)
		{
			cout << "Program terminated." << endl;
			return 0;
		}
		else
		{
			cout << "Invalid input: '" << mode << "' was not recognized as a valid number." << endl;
		}
	}
}

