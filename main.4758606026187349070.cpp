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
bool is_leap_year ( int year )
{
    if(year % 4 == 0 && year % 100 != 0) return true;
    else if(year % 400 == 0) return true;
    return false;
}

int number_of_days_in_month ( int year, Month month )
{
    switch(month)
    {
        case January:
        case March:
        case May:
        case July:
        case August:
        case October:
        case December: return 31;
        case April:
        case June:
        case September:
        case November: return 30;
        case February:
        {
            if (is_leap_year(year)) return 29;
            else return 28;
        }
    }
}

/*                                                                   
                                                
                                                                   */
int dayOfYearToDayOfMonth(int year, int dayOfYear)
{
    if(dayOfYear <= number_of_days_in_month(year, January)) return dayOfYear;
    dayOfYear = dayOfYear - number_of_days_in_month(year, January);
    if(dayOfYear <= number_of_days_in_month(year, February)) return dayOfYear;
    dayOfYear = dayOfYear - number_of_days_in_month(year, February);
    if(dayOfYear <= number_of_days_in_month(year, March)) return dayOfYear;
    dayOfYear = dayOfYear - number_of_days_in_month(year, March);
    if(dayOfYear <= number_of_days_in_month(year, April)) return dayOfYear;
    dayOfYear = dayOfYear - number_of_days_in_month(year, April);
    if(dayOfYear <= number_of_days_in_month(year, May)) return dayOfYear;
    dayOfYear = dayOfYear - number_of_days_in_month(year, May);
    if(dayOfYear <= number_of_days_in_month(year, June)) return dayOfYear;
    dayOfYear = dayOfYear - number_of_days_in_month(year, June);
    if(dayOfYear <= number_of_days_in_month(year, July)) return dayOfYear;
    dayOfYear = dayOfYear - number_of_days_in_month(year, July);
    if(dayOfYear <= number_of_days_in_month(year, August)) return dayOfYear;
    dayOfYear = dayOfYear - number_of_days_in_month(year, August);
    if(dayOfYear <= number_of_days_in_month(year, September)) return dayOfYear;
    dayOfYear = dayOfYear - number_of_days_in_month(year, September);
    if(dayOfYear <= number_of_days_in_month(year, October)) return dayOfYear;
    dayOfYear = dayOfYear - number_of_days_in_month(year, October);
    if(dayOfYear <= number_of_days_in_month(year, November)) return dayOfYear;
    dayOfYear = dayOfYear - number_of_days_in_month(year, November);
    if (dayOfYear <= number_of_days_in_month(year, December)) return dayOfYear;
    return 0;
}

Month dayOfYearToMonth(int year, int dayOfYear)
{
    if(dayOfYear <= number_of_days_in_month(year, January)) return January;
    dayOfYear = dayOfYear - number_of_days_in_month(year, January);
    if(dayOfYear <= number_of_days_in_month(year, February)) return February;
    dayOfYear = dayOfYear - number_of_days_in_month(year, February);
    if(dayOfYear <= number_of_days_in_month(year, March)) return March;
    dayOfYear = dayOfYear - number_of_days_in_month(year, March);
    if(dayOfYear <= number_of_days_in_month(year, April)) return April;
    dayOfYear = dayOfYear - number_of_days_in_month(year, April);
    if(dayOfYear <= number_of_days_in_month(year, May)) return May;
    dayOfYear = dayOfYear - number_of_days_in_month(year, May);
    if(dayOfYear <= number_of_days_in_month(year, June)) return June;
    dayOfYear = dayOfYear - number_of_days_in_month(year, June);
    if(dayOfYear <= number_of_days_in_month(year, July)) return July;
    dayOfYear = dayOfYear - number_of_days_in_month(year, July);
    if(dayOfYear <= number_of_days_in_month(year, August)) return August;
    dayOfYear = dayOfYear - number_of_days_in_month(year, August);
    if(dayOfYear <= number_of_days_in_month(year, September)) return September;
    dayOfYear = dayOfYear - number_of_days_in_month(year, September);
    if(dayOfYear <= number_of_days_in_month(year, October)) return October;
    dayOfYear = dayOfYear - number_of_days_in_month(year, October);
    if(dayOfYear <= number_of_days_in_month(year, November)) return November;
    return December;
}

int easterDay(int year)
{
    int day = 0;
    day = day + easter_day(year);
    //                                     
    day = day + number_of_days_in_month(year, January) + number_of_days_in_month(year, February);
    if(easter_month(year) == April) day = day + number_of_days_in_month(year, March);
    return day;
}

int carnivalStartDay(int dayOfEaster)
{
    return (dayOfEaster - 49);
}

int carnivalEndDay(int dayOfEaster)
{
    return (dayOfEaster - 47);
}

int goodFridayDay(int dayOfEaster)
{
    return (dayOfEaster - 2);
}

int whitsuntideDay(int dayOfEaster)
{
    return (dayOfEaster + 49);
}

int ascensionDayDay(int dayOfEaster)
{
    return (whitsuntideDay(dayOfEaster) - 10);
}

void show_holy_days ()
{
    int year;
    int doe;
    cout << endl << "--- Welcome to holy days calculator! ---" << endl << endl << "Enter the year of which you want to know the holy days: ";
    cin >> year;
    doe = easterDay(year);
    cout << endl << "For the year " << year << " the dates of the holy days are as following:" << endl << "[The output is in Day.Month. form]" << endl<< endl;
    cout << "- Carnival: " << dayOfYearToDayOfMonth(year, carnivalStartDay(doe)) << "." << dayOfYearToMonth(year, carnivalStartDay(doe)) << ".";
    cout << " - " << dayOfYearToDayOfMonth(year, carnivalEndDay(doe)) << "." << dayOfYearToMonth(year, carnivalEndDay(doe)) << "." << endl;
    cout << "- Good Friday: " << dayOfYearToDayOfMonth(year, goodFridayDay(doe)) << "." << dayOfYearToMonth(year, goodFridayDay(doe)) << "." << endl;
    cout << "- Easter: " << easter_day(year) << "." << easter_month(year) << "." << endl;
    cout << "- Ascension Day: " << dayOfYearToDayOfMonth(year, ascensionDayDay(doe)) << "." << dayOfYearToMonth(year, ascensionDayDay(doe)) << "." << endl;
    cout << "- Whitsuntide: " << dayOfYearToDayOfMonth(year, whitsuntideDay(doe)) << "." << dayOfYearToMonth(year, whitsuntideDay(doe)) << "." << endl;

}

int main()
{
    show_holy_days() ;
    return 0;
}

