#include <iostream>
/*
                     
                      
*/
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
    if(year % 4 == 0)
    {
        if(year % 100 == 0)
        {
            return (year % 400 == 0);
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

int number_of_days_in_month ( int year, Month month )
{
    int a = 0;

    switch(month)
    {
        case January :
        case March :
        case May :
        case July :
        case August :
        case October :
        case December : a = 31; break;
        case April :
        case June :
        case September :
        case November : a = 30; break;
        case February : a = 28 + is_leap_year(year); break;
    }

    return a;
}

/*                                                                   
                                                
                                                                   */
int calculate_days_of_month (int month, int year)
{
    int a = 0;

    switch(month)
    {
        case 1 :
        case 3 :
        case 5 :
        case 7 :
        case 8 :
        case 10 :
        case 12 : a = 31; break;
        case 4 :
        case 6 :
        case 9 :
        case 11 : a = 30; break;
        case 2 : a = 28 + is_leap_year(year); break;
    }

    return a;
}

int calculate_holy_day(int year, int month, int day, int translation, bool calculate_month)
{
    int days = 0;

    for(int i = 1; i < month; i++)
    {
        days = days + calculate_days_of_month(i, year);
    }
    days = days + translation + day;

    int months = 1;

    for(int i = 1; days > calculate_days_of_month(i, year); i++)
    {
        days = days - calculate_days_of_month(i, year);
        months++;
    }

    if(calculate_month)
    {
        return months;
    }
    else
    {
        return days;
    }
}

void show_holy_days (int year)
{
    cout << "Easter is in month " << easter_month(year) << " on day " << easter_day(year) << "." << endl;

    cout << "Carnival is in month " << calculate_holy_day(year, easter_month(year), easter_day(year), -49, true) << " on day " << calculate_holy_day(year, easter_month(year), easter_day(year), -49, false) << "." << endl;
    cout << "Good Friday is in month " << calculate_holy_day(year, easter_month(year), easter_day(year), -2, true) << " on day " << calculate_holy_day(year, easter_month(year), easter_day(year), -2, false) << "." << endl;
    cout << "Ascension day is in month " << calculate_holy_day(year, easter_month(year), easter_day(year), 39, true) << " on day " << calculate_holy_day(year, easter_month(year), easter_day(year), 39, false) << "." << endl;
    cout << "Whitsuntide is in month " << calculate_holy_day(year, easter_month(year), easter_day(year), 49, true) << " on day " << calculate_holy_day(year, easter_month(year), easter_day(year), 49, false) << "." << endl;
}

int pick_a_number ()
{
    int number = 0;

    cout << "Enter a Positive Year: ";
    cin >> number;
    while (number <= 0)
    {
        cout << number << " is not a Positive Year, Please Enter a Correct Year: ";
        cin >> number;
    }

    return number;
}

int main()
{
    int year = pick_a_number();

    if(is_leap_year(year))
    {
        cout << "The year " << year << " is a leap year." << endl;
    }
    else
    {
        cout << "The year " << year << " is not a leap year" << endl;
    }
    show_holy_days(year) ;
    return 0;
}
