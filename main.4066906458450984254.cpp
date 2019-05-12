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

//                                              

/*                                                                   
                                 
                                                                   */
//                                                                           
bool is_leap_year ( int year )
{
    if (year % 4 == 0)
    {
        if (year % 400 != 0)
            return 0 ;
        else
            return 1 ;
    }
    else
        return 0 ;
}

int number_of_days_in_month ( int year, Month month )
{
    switch (month)
    {
    case January :
    case March :
    case May :
    case July :
    case August :
    case October :
    case December : cout << 31 ; break ;
    case April :
    case June :
    case September :
    case November : cout << 30 ; break ;
    case February : cout << 28 + is_leap_year(year) ; break ;

    }
}

/*                                                                   
                                                
                                                                   */
int Y ;
int day = 0 ;
Month month ;

void Show_Month ()
{
    switch (month)
    {
        case January: cout << "January" ; break ;
        case February: cout << "February" ; break ;
        case March: cout << "March" ; break ;
        case April: cout << "April" ; break ;
        case May: cout << "May" ; break ;
        case June: cout << "June" ; break ;
        case July: cout << "July" ; break ;
        case August: cout << "August" ; break ;
        case September: cout << "September" ; break ;
        case October: cout << "October" ; break ;
        case November: cout << "November" ; break ;
        case December: cout << "December" ; break ;
    }
}

int Abs (int x)
{
    if (x >= 0)
        return x ;
    else
    return -x ;
}

void show_holy_days ()
{
    cout << "enter year\n" ;
    cin >> Y ;

    if (easter_month(Y) == March)
    {
        day = (28 + is_leap_year(Y)) - (47 - easter_day(Y)) ;
        month = February ;
    }
    else
    {
        day = (31 - (47 - easter_day(Y))) ;
        if (day <= 0)
        {
            day = (28 + is_leap_year(Y)) - Abs(day) ;
            month = February ;
        }
        else
            month = March ;
    }

    cout << "\nCarnival: " ;
    Show_Month() ;
    cout << " " << day ;

    day = easter_day(Y) - 2 ;
    if (day <= 0)
    {
        if (easter_month(Y) == March)
        {
            day = number_of_days_in_month(Y, February) + day ;
            month = February ;
        }
        else
        {
            day = number_of_days_in_month(Y, March) + day ;
            month = March ;
        }
    }
    else month = easter_month(Y) ;

    cout << "\nGood Friday: " ;
    Show_Month() ;
    cout << " " << day ;

    month = easter_month(Y) ;

    cout << "\nEaster: " ;
    Show_Month() ;
    cout << " " << easter_day(Y) ;

    if (easter_month(Y) == March)
    {
        day = easter_day(Y) + 8 ;
        if (day > 30)
        {
            day = day - 30 ;
            month = May ;
        }
        else
            month = April ;
    }
    else
    {
        day = easter_day(Y) + 9 ;
        if (day > 31)
        {
            day = day - 31 ;
            month = June ;
        }
        else
            month = May ;
    }

    cout << "\nAscension Day: " ;
    Show_Month() ;
    cout << " " << day ;

    day = day + 10 ;
    if (day > 30 && month == April)
        {
            day = day - 30 ;
            month = May ;
        }
    else if (day > 31)
    {
        day = day - 31 ;
        month = June ;
    }

    cout << "\nWhitsuntide: " ;
    Show_Month() ;
    cout << " " << day ;
}

int main()
{
    show_holy_days() ;
    return 0;
}

