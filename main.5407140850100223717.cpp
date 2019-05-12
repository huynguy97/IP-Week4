//                                           

#include <iostream>
#include <string>

using namespace std;

enum Month { January = 1, February, March, April, May, June, July, August, September, October, November, December };

/*                                                                          
	                                                                        
	                                                       
*/
int easter_base(int year)
{
	const int A = year % 19;
	const int B = year / 100;
	const int C = year % 100;
	const int D = B / 4;
	const int E = B % 4;
	const int F = (B + 8) / 25;
	const int G = (B - F + 1) / 3;
	const int H = (19 * A + B - D - G + 15) % 30;
	const int I = C / 4;
	const int K = C % 4;
	const int L = (32 + 2 * E + 2 * I - H - K) % 7;
	const int M = (A + 11 * H + 22 * L) / 451;
	return H + L - 7 * M + 114;
}

/*                                                                                    
	               
*/
int easter_day(int year)
{
	return (easter_base(year) % 31) + 1;
}

/*                                                                                   
*/
Month easter_month(int year)
{
	return static_cast<Month> (easter_base(year) / 31);
}

/*                                                                   
	                             
                                                                   */
//                                            
//                                         
bool is_leap_year(int year)
{
	bool is_leap = false;

	if (year % 4 == 0)
		is_leap = true;

	if (year % 100 == 0)
		if (year % 400 != 0)
			is_leap = false;

	return is_leap;
}

//                                        
//                    
int number_of_days_in_month(int year, Month month)
{
	int days_number = 31;

	switch (month)
	{
        case February:
            days_number = 28;
            if (is_leap_year(year))
                days_number++;
            break;

        case April:
        case June:
        case September:
        case November:
            days_number = 30;
            break;
	}

	return days_number;
}

/*                                                                   
	                                            
                                                                   */
//                                                
//                               
int daynumber_in_year(int day, Month month, int year)
{
	int daynumber = 0;

	for (int i = 1; i < month; i++)
		daynumber += number_of_days_in_month(year, static_cast<Month>(i));

	daynumber += day;
	return daynumber;
}

//                                                  
//                               
Month daynumber_to_month(int daynumber, int year)
{
	int month_number = 0;

	while (daynumber > 0)
	{
		daynumber -= number_of_days_in_month(year, static_cast<Month>(month_number));
		month_number++;
	}

	return static_cast<Month>(month_number);
}

//                                                            
//                                                      
int daynumber_to_day(int daynumber, int year)
{
	Month month = daynumber_to_month(daynumber, year);

	for (int i = 1; i < month; i++)
		daynumber -= number_of_days_in_month(year, static_cast<Month>(i));

	return daynumber;
}

//                                                                    
//                                               
void show_date(string name, int daynumber, int year)
{
	int day = daynumber_to_day(daynumber, year);
	Month month = daynumber_to_month(daynumber, year);

	cout << name << " is at " << month << ", " << day << " in " << year << endl;
}

//                                                                                             
//                                                                 
void show_holy_days()
{
	int year = 1;
	cout << "enter a year : ";
	cin >> year;

	int easter_d = easter_day(year);
	Month easter_m = easter_month(year);
	int easter_dn = daynumber_in_year(easter_d, easter_m, year);
	int carnival_dn = easter_dn - 49;
	int gfriday_dn = easter_dn - 2;
	int whitsuntide_dn = easter_dn + 49;
	int ascension_dn = whitsuntide_dn - 10;

	show_date("Carnival", carnival_dn, year);
	show_date("Good Friday", gfriday_dn, year);
	show_date("Eastern", easter_dn, year);
	show_date("Ascension day", ascension_dn, year);
	show_date("Whitsuntide", whitsuntide_dn, year);

}

int main()
{
	while (1)
	{
		show_holy_days();
		cout << "- - - - -" << endl;
	}
	return 0;
}

