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
    if(year % 4 == 0)
    {
        if(year % 100 == 0)
        {
            if(year % 400 == 0)
                return true;
            else
                return false;
        }
        return true;
    }
    else
        return false;
}

//                                                                                
int number_of_days_in_Febuary(int year)
{
    if(is_leap_year(year))
        return 29;
    else
        return 28;

}

//                                                                                                                                            
int number_of_days_in_month ( int year, Month month)
{
    switch(month)
    {
        case 2: return number_of_days_in_Febuary(year);
        case 4: return 30;
        case 6: return 30;
        case 9: return 30;
        case 11: return 30;
        default: return 31;

    }
}

/*                                                                   
                                                
                                                                   */

//                                                                              
int day_of_year(int easter_day, int month, int year)
{
    month--;
    int day_in_year = 0;
    for(month; month > 0; month--)
    {
        Month enum_of_month = static_cast<Month>(month);
        day_in_year += number_of_days_in_month(year,enum_of_month);
    }
    return day_in_year+easter_day;
}

//                                                                      
int calculate_holy_day_day(int day_of_the_year, int year)
{
    int month = 1;
    Month enum_of_month = static_cast<Month>(month);

    while(day_of_the_year > number_of_days_in_month(year,enum_of_month))
    {
        day_of_the_year -= number_of_days_in_month(year,enum_of_month);
        month++;
        Month enum_of_month = static_cast<Month>(month);
    }
    return day_of_the_year;
}

//                                                                       
int calculate_holy_day_month(int day_of_the_year, int year)
{
    int month = 1;
    Month enum_of_month = static_cast<Month>(month);

    while(day_of_the_year > number_of_days_in_month(year,enum_of_month))
    {
        month++;
        day_of_the_year -= number_of_days_in_month(year,enum_of_month);
        Month enum_of_month = static_cast<Month>(month);
    }
    return month;
}

//                                                                        
void carnival(int day_of_the_year,int Y)
{
    int day_of_carnival;
    int month_of_carnival;

    int day_of_carnival_end;
    int month_of_carnival_end;

    int day_of_carnival_start = day_of_the_year - 49;

    int day_of_carnival_end2 = day_of_the_year - 47;

    day_of_carnival = calculate_holy_day_day(day_of_carnival_start,Y);
    month_of_carnival = calculate_holy_day_month(day_of_carnival_start,Y);

    day_of_carnival_end = calculate_holy_day_day(day_of_carnival_end2,Y);
    month_of_carnival_end = calculate_holy_day_month(day_of_carnival_end2,Y);

    cout << "Carnival starts at: \t" << month_of_carnival << "\t" << day_of_carnival << "\n";
    cout << "Carnival ends at: \t" << month_of_carnival_end << "\t" << day_of_carnival_end << "\n";
}

void good_friday(int day_of_the_year,int Y)
{
    int good_friday = day_of_the_year - 2;
    int day_of_good_friday = calculate_holy_day_day(good_friday,Y);
    int month_of_good_friday = calculate_holy_day_month(good_friday,Y);

    cout << "Good friday: \t\t" << month_of_good_friday << "\t" << day_of_good_friday << "\n";
}

void ascension_day(int day_of_the_year,int Y)
{
    int ascension_day = day_of_the_year + 39;
    int day_of_ascension_day = calculate_holy_day_day(ascension_day,Y);
    int month_of_ascension_day = calculate_holy_day_month(ascension_day,Y);

    cout << "Ascension day: \t\t" << month_of_ascension_day << "\t" << day_of_ascension_day << "\n";
}

void whitsuntide(int day_of_the_year,int Y)
{
    int whitsuntide = day_of_the_year + 49;
    int day_of_whitsuntide = calculate_holy_day_day(whitsuntide,Y);
    int month_of_whitsuntide = calculate_holy_day_month(whitsuntide,Y);

    cout << "Whitsuntide: \t\t" << month_of_whitsuntide << "\t" << day_of_whitsuntide << "\n";
}

//                                                                                           
void show_holy_days ()
{
    int Y;
    int month_of_easter;
    int day_of_easter;

    cout << "With this program you can calculate what the dates of Christian holy days are in a particular year! \nPlease insert a year number: e.g. 1992 \n";
    cin >> Y;
    day_of_easter = easter_day (Y);
    month_of_easter = easter_month (Y);

    const int day_of_the_year = day_of_year(day_of_easter,month_of_easter,Y);
    cout << "\t\t\tMonth \tDay \n";
    cout << "Easter: \t\t" << month_of_easter << "\t" << day_of_easter << "\n";

    carnival(day_of_the_year,Y);

    good_friday(day_of_the_year,Y);

    ascension_day(day_of_the_year,Y);

    whitsuntide(day_of_the_year,Y);
}

int main()
{
    show_holy_days() ;
    return 0;
}

