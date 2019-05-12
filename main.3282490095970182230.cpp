//                         
//                           

#include <iostream>

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
bool is_leap_year(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0 && !(year % 400 == 0))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}

}

int number_of_days_in_month(int year, Month month)
{
	/*                                                
	                                                 
	 	                                           
	                                                                   
	                                                 */
	switch (month)
	{
		case April:
		case June:
		case November:
        case September:
			return 30; break;
		case February:
			if (is_leap_year(year))
			{
				return 29;
			}
			else
			{
				return 28;
			}
			break;
		default:
			return 31; break;

	}

}

Month int_to_month(int month)
{
	switch (month) {
	case 1: return January;
	case 2: return February;
	case 3: return March;
	case 4: return April;
	case 5: return May;
	case 6: return June;
	case 7: return July;
	case 8: return August;
	case 9: return September;
	case 10: return October;
	case 11: return November;
	case 12: return December;
	}
}

int day_from_date(int year, int month, int day)
{
	int days = 0;
	month = month - 1;
	while (month > 0) {
		days = days + number_of_days_in_month(year, int_to_month(month));
		month--;
	}
	return days + day;
}

void calc_date_from_day(int day, int year)
{
	int m = 1; //                                       
	int d = number_of_days_in_month(year, int_to_month(m));
	while (d < day) {
		int d = number_of_days_in_month(year, int_to_month(m));
		day = day - number_of_days_in_month(year, int_to_month(m));
		m++;
	}
	cout << "(" << int_to_month(m)  << "," << day << ") \n";
}

/*                                                               
                                                   
                                                            
                                                              */

void print_carnival(int easterday, int year) {
	int carnivalday = easterday - 47;
	cout << "Carnival will be on the following date: ";
	calc_date_from_day(carnivalday, year);
}

/*                                                               
                                              
                                                              */

void print_gfriday(int easterday, int year) {
	int gfriday = easterday - 2;
	cout << "Good friday will be on the following date: ";
	calc_date_from_day(gfriday, year);
}

/*                                                               
                                              
                                                              */

void print_easter(int easterday, int year) {
	int easter = easterday;
	cout << "Easter will be on the following date: ";
	calc_date_from_day(easter, year);
}

/*                                                               
                                      
                                                              */

void print_whitsuntide(int easterday, int year) {
	int whitsuntide = easterday + 49;
	cout << "Whitsuntide will be on the following date: ";
	calc_date_from_day(whitsuntide, year);
}

/*                                                               
                                        
                                                              */

void print_ascension(int easterday, int year) {
	int ascension = easterday + 39;
	cout << "Ascension will be on the following date: ";
	calc_date_from_day(ascension, year);
}

void show_holy_days()
{
	int year = 0;
	/*                                              */
	cout << "Please enter a year:  $  ";
	cin >> year;
	cout << endl << endl;

	Month month = easter_month(year);
	int day = easter_day(year);
	int easterday = day_from_date(year, month, day);
	print_easter(easterday, year);
	print_carnival(easterday, year);
	print_gfriday(easterday, year);
	print_ascension(easterday, year);
	print_whitsuntide(easterday, year);
}

int main()
{
	show_holy_days();
	return 0;
}

