#include <iostream>
//                                                     
using namespace std;

int year;

enum Month {January=1,February,March,April,May,June,July,August,September,October,November,December} ;

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
    return static_cast <Month> (easter_base (year) / 31) ;
}

/*                                                                   
                                 
                                                                   */
bool is_leap_year ( int year ) //                                               
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                return true;
            else
                return false;
        }
        else
            return true;
    }
    else
        return false;
}

int number_of_days_in_month ( int year, Month month )
{
    switch (January)
    {
        case January: return 31;
        case February: return is_leap_year(year) == 1 ? 29 : 28;
        case March: return 31;
        case April: return 30;
        case May: return 31;
        case June: return 30;
        case July: return 31;
        case August: return 31;
        case September: return 30;
        case October: return 31;
        case November: return 30;
        case December: return 31;
    }
}

Month carnival_month ( int year ) //                                                                    
{
    return static_cast <Month> (easter_base (year) / 31) ;
}

int carnival_day ( int year ) //                                            
{
    if (carnival_month(year) == April)
    {
        if (((easter_base (year) % 31) + 1 - 49 + 31) < 1)
        {
            if (is_leap_year(year) == 1) {
                return (easter_base (year) % 31) + 1 - 49 + 31 + 29;
            } else {
                return (easter_base (year) % 31) + 1 - 49 + 31 + 28;
            }
        }
        else
        {
            return ((easter_base(year) % 31) + 1 - 49 + 31);
        }
    }
    else
    {
        if (is_leap_year(year) == 1) {
            return (easter_base (year) % 31) + 1 - 49 + 29;
        } else {
            return (easter_base (year) % 31) + 1 - 49 + 28;
        }
    }
}

Month new_carnival_month ( int year ) //                                                  
{
    if (((easter_base (year) % 31) + 1 - 49 + 31) < 1)
    {
        return static_cast <Month> ((easter_base(year) / 31) - 2 );
    }
    else
    {
        return static_cast <Month> ((easter_base(year) / 31) - 1 );
    }
}

int carnival_day_end ( int year ) //                                                   
{
    if (is_leap_year(year) == 1)
    {
        if (carnival_day(year) == 28 || carnival_day(year) == 29)
        {
            return (carnival_day(year) + 2 - 29);
        }
        else
        {
            return (carnival_day(year) + 2);
        }
    }
    else
    {
        if (carnival_day(year) == 27 || carnival_day(year) == 28)
        {
            return (carnival_day(year) + 2 - 28);
        }
        else
        {
            return (carnival_day(year) + 2);
        }
    }
}
//                                                     
Month end_carnival_month ( int year ) {
    if (is_leap_year(year) == 1) {
        if (carnival_day(year) == 28 || carnival_day(year) == 29) {
            return static_cast <Month> (new_carnival_month(year) + 1);
        } else {
            return static_cast <Month> (new_carnival_month(year));
        }
    } else {
        if (carnival_day(year) == 27 || carnival_day(year) == 28) {
            return static_cast <Month> (new_carnival_month(year) + 1);
        } else {
            return static_cast <Month> (new_carnival_month(year));
        }
    }
}
Month good_month ( int year ) //                                            
{
    if ((easter_base (year) % 31) + 1 == 1 || (easter_base (year) % 31) + 1 == 2 )
    {
        return static_cast <Month> ((easter_base(year) / 31) - 1);
    }
    else
    {
        return static_cast <Month> (easter_base(year) / 31);
    }
}

int good ( int year ) //                                           
{
    if ((easter_base (year) % 31) + 1 == 1 || (easter_base (year) % 31) + 1 == 2 )
    {
        return (easter_base (year) % 31) + 1 - 2 + 31 ;
    }
    else {
        return (easter_base(year) % 31) + 1 - 2;
    }
}

Month ass_month ( int year )//                                                                
{
    return static_cast <Month> (easter_base (year) / 31) ;
}

int ass ( int year ) //                                             
{
    if (ass_month(year) == 3)
    {
        if ((easter_base(year) % 31) + 1 + 39 - 31 >= 30 )
        {
            return (easter_base(year) % 31) + 1 + 39 - 31 - 30;
        }
        else
        {
            return (easter_base(year) % 31) + 1 + 39 - 31;
        }
    }
    else
    {
        if ((easter_base(year) % 31) + 1 + 39 - 30 >= 31 )
        {
            return (easter_base(year) % 31) + 1 + 39 - 31 - 30;
        }
        else
        {
            return (easter_base(year) % 31) + 1 + 39 - 30;
        }
    }
}

Month new_ass_month (int year) //                                               
{
    if (ass_month(year) == 3) {
        if ((easter_base(year) % 31) + 1 + 39 - 31 >= 30) {
            return static_cast <Month> ((easter_base(year) / 31) + 2  );
        } else {
            return static_cast <Month> ((easter_base(year) / 31) + 1 );
        }
    }
    else {
        if ((easter_base(year) % 31) + 1 + 39 - 30 >= 31) {
            return static_cast <Month> ((easter_base(year) / 31) + 2  );
        } else {
            return static_cast <Month> ((easter_base(year) / 31) + 1 );
        }
    }
}

Month white_month ( int year ) //                                                                        
{
    return static_cast <Month> (easter_base (year) / 31) ;
}

int white ( int year ) //                                           
{
    if (white_month(year) == 3)
    {
        if ((easter_base(year) % 31) + 1 + 49 - 31 >= 30 )
        {
            return (easter_base(year) % 31) + 1 + 49 - 31 - 30;
        }
        else
        {
            return (easter_base(year) % 31) + 1 + 49 - 31;
        }
    }
    else
    {
        if ((easter_base(year) % 31) + 1 + 49 - 30 >= 31 )
        {
            return (easter_base(year) % 31) + 1 + 49 - 31 - 30;
        }
        else
        {
            return (easter_base(year) % 31) + 1 + 49 - 30;
        }
    }
}
Month new_white_month (int year) //                                         
{
    if (white_month(year) == 3) {
        if ((easter_base(year) % 31) + 1 + 49 - 31 >= 30) {
            return static_cast <Month> ((easter_base(year) / 31) + 2  );
        } else {
            return static_cast <Month> ((easter_base(year) / 31) + 1 );
        }
    }
    else {
        if ((easter_base(year) % 31) + 1 + 49 - 30 >= 31) {
            return static_cast <Month> ((easter_base(year) / 31) + 2  );
        } else {
            return static_cast <Month> ((easter_base(year) / 31) + 1 );
        }
    }
}

/*                                                                   
                                                
                                                                   */

void show_holy_days () //                                      
{
    cout << "In the year: ";
    cout << year;
    cout << "\n";
    cout << "Easter will fall in the month: ";
    cout << easter_month(year);
    cout << " on day: ";
    cout << easter_day (year);
    cout << "\n";
    cout << "Carnival will fall in the month: ";
    cout << new_carnival_month(year);
    cout << " on day: ";
    cout << carnival_day (year);
    cout << " untill ";
    cout << end_carnival_month(year);
    cout << " on day: ";
    cout << carnival_day_end (year);
    cout << "\n";
    cout << "Good Friday will fall in the month: ";
    cout << good_month(year);
    cout << " on day: ";
    cout << good (year);
    cout << "\n";
    cout << "Assension day will fall in the month: ";
    cout << new_ass_month(year);
    cout << " on day: ";
    cout << ass (year);
    cout << "\n";
    cout << "Whitesuntide will fall in the month: ";
    cout << new_white_month(year);
    cout << " on day: ";
    cout << white (year);

}

int main() //                                                            
{
    cout << "Enter a year: " ;
    cin >> year ;
    show_holy_days() ;
    return 0;
}

