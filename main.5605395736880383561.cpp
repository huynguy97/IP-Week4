/*
                        
                          
  
   */

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

bool is_leap_year (int year)
{
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int number_of_days_in_month (int year, Month month)
{
    if(month == 2 && is_leap_year(year))
        return 29;
    else if(month == 2)
        return 28;
    else if((month % 2 == 0 && month < 7) || (month % 2 != 0 && month > 7))
        return 30;
    else
        return 31;
}

/*                                                                   
                                                
                                                                   */

string days_before_easter (int days, int year)
{
    int day = easter_day(year) - days;;
    int month = easter_month(year);

    while (day <= 0) {
        day += number_of_days_in_month(year, static_cast<Month>( month - 1));
        month--;
    }
    return to_string(month) + "," + to_string(day);
}

string days_after_easter (int days, int year)
{
    int  day = easter_day(year) + days;;
    int month = easter_month(year);

    while (day > number_of_days_in_month(year, static_cast<Month>(month))) {
        day -= number_of_days_in_month(year, static_cast<Month>(month));
        month++;
    }
    return to_string(month) + "," + to_string(day);
}

void show_holy_days (int year)
{
    cout << "The holy days for " << year << " are:\n\n";
    cout << "Easter: \t(" << easter_month(year) << "," << easter_day(year) << ")\n";
    cout << "Carnival: \t(" << days_before_easter(49, year) << ")\n";
    cout << "Good Friday: \t(" << days_before_easter(2, year) << ")\n";
    cout << "Ascension: \t(" << days_after_easter(39, year) << ")\n";
    cout << "Whitsuntide: \t(" << days_after_easter(49, year) << ")\n";
}

int main()
{
    cout << "What year do you want to see the holy days for?:";
    int year;
    cin >> year;
    show_holy_days(year);
    return 0;
}

