#include <iostream>

using namespace std;

//                          
//                         

enum Month {January=1,February,March,April,May,June,July,August,September,October,November,December} ;
Month month;
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

int days_in_month;

/*                                                                   
                                 
                                                                   */
bool is_leap_year ( int year )
//                                                                    
{
    if ( ((year%100 == 0) && (year%400 == 0) ))
        return true;
    else if (year%4 == 0)
        return true;
    return false;
}

int number_of_days_in_month ( int year, Month month )
//                                                   
{
	switch(month)
	{
		case(January):
		case(March):
		case(May):
		case(July):
		case(August):
		case(October):
		case(December): return 31;
		case(February):
			{
				if(is_leap_year(year))
					return 29;
                return 28;
			}
		default: return 30;
	}
}

/*                                                                   
                                                
                                                                   */
//                                                                            
//                                                                            
//                                                                                                
//                                  
int convert_easter_date_to_day_number(int year)
{
    int month_of_easter = static_cast<int>(easter_month(year)) - 1; //                                                                                
    int days;
    int big_day = 0;
    for(month_of_easter; month_of_easter > 0; month_of_easter--)
    {
        Month e_month = static_cast<Month>(month_of_easter); //                                                                                          
        days = number_of_days_in_month(year, e_month);
        big_day = big_day + days; //                                                                         
    }
    return big_day + easter_day(year);
}

//                                                                 
//                                                                   
//             
//                                                                                    
//                                                                              
//                                                                                
//                
int convert_days_to_date(int year, int day_number, bool day_or_month)
{
    int number_of_months = 0;
    int number_month;
    int rest = 1;
    for(number_month = 1; rest > 0; number_month++)
    {
        month = static_cast<Month>(number_month);
        int number_of_days = static_cast<int>(number_of_days_in_month (year, month)); //                                                           
        rest = day_number - number_of_days;
        if (rest > 0)
        {
            day_number = rest;
            number_of_months = number_month;
        }
    }
    if(day_or_month)
        return day_number;
    return (number_of_months+1);
}

void find_carnival(int day_number, int year)
//                           
{
    int carnival = day_number - 49;
    cout << "Carnival is on \t \t " << convert_days_to_date(year, carnival, true) << "\t"
    << convert_days_to_date(year, carnival, false) << endl;
}

void find_good_friday(int day_number, int year)
//                              
{
    int goodfriday = day_number - 2;
    cout << "Good Friday is on \t " << convert_days_to_date(year, goodfriday, true) << "\t"
    << convert_days_to_date(year, goodfriday, false) << endl;
}

void find_ascension(int day_number, int year)
//                                
{
    int ascension = day_number + 39;
    cout << "Ascension Day is on \t " << convert_days_to_date(year, ascension, true) << "\t"
    << convert_days_to_date(year, ascension, false) << endl;
}

void find_whitsuntide(int day_number, int year)
//                              
{
    int whitsuntide = day_number + 49;
    cout << "Whitsuntide is on \t " << convert_days_to_date(year, whitsuntide, true) << "\t"
    << convert_days_to_date(year, whitsuntide, false) << endl;
}

void show_holy_days (int year, int day_number)
//                                                                                    
//                                  
{
    cout << "\n";
    if(is_leap_year(year))
        cout << year << " is a leap year" << endl;
    else
        cout << year << " is not a leap year" << endl;
    cout << "------------------------ day \tmonth \n";
    find_carnival(day_number, year);
    find_good_friday(day_number, year);
    cout << "Easter is on \t \t " << easter_day(year) << "\t" << easter_month(year) << endl;
    find_ascension(day_number, year);
    find_whitsuntide(day_number, year);
    cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";

}

int user_interface()
//                                                                                                    
{
	int input;
	cout << "Welcome to the your personal holyday calculator! \n";
	cout << "If you want to know the holydays in a particular year A.D., please enter the year: ";
	cin >> input;
	return input;
}
int main()
//                                                                                          
//                                                           
{
    int year = user_interface();
    int day_number = convert_easter_date_to_day_number(year) ;
    show_holy_days(year, day_number);
    cout <<"I hope this was insightful, thank you for using our service and drive safe :)" << endl;
    return 0;
}

