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
//                                                                   
bool is_leap_year ( int year )
{
    return !(year % 4) && ( !(year % 400) || (year % 100) );
}

int number_of_days_in_month ( int year, Month month )
{
    switch(month)
    {
    case February:
        if(is_leap_year(year))
            return 29;
        else
            return 28;
    case January:
    case March:
    case May:
    case July:
    case August:
    case October:
    case December:
        return 31;
    default:
        return 30;
    }
}

/*                                                                   
                                                
                                                                   */

//                                                                               
void print_holy_day(string name, int year, Month month, int day)
{
    //                                
    while(day > number_of_days_in_month(year, month))
    {
        day -= number_of_days_in_month(year, month);
        if(month == December)
            month = January;
        else
            month = static_cast<Month>(month + 1);
    }
    while(day < 1)
    {
        if(month == January)
            month = December;
        else
            month = static_cast<Month>(month - 1);
        day += number_of_days_in_month(year, month);
    }
    //                    
    cout << name;

    //            
    string str;
    switch (month)
    {
        case January:   str = "January ";   break;
        case February:  str = "February ";  break;
        case March:     str = "March ";     break;
        case April:     str = "April ";     break;
        case May:       str = "May ";       break;
        case June:      str = "June ";      break;
        case July:      str = "July ";      break;
        case August:    str = "August ";    break;
        case September: str = "September "; break;
        case October:   str = "October ";   break;
        case November:  str = "November ";  break;
        case December:  str = "December ";  break;
    }

    //                           
    cout << str << day;
    switch(day)
    {
    case 1:
    case 21:
    case 31:
        str = "st\n";
        break;
    case 2:
    case 22:
        str = "nd\n";
    case 3:
    case 23:
        str = "d\n";
    default:
        str = "th\n";
    }
    //                     
    cout << str;
}

void show_holy_days ()
{
    int year;
    cout << "Enter year: " << endl;
    cin >> year;

    cout << "The dates of the holy days in the year " << year << " are:" << endl;

    Month month = easter_month(year);
    int day = easter_day(year);

    print_holy_day("Carnival:\t", year, month, day - 49);
    print_holy_day("Good friday:\t", year, month, day - 2);
    print_holy_day("Easter:\t\t", year, month, day);
    print_holy_day("Ascension day:\t", year, month, day + 39);
    print_holy_day("Whitsuntide:\t", year, month, day + 49);
}

int main()
{
    show_holy_days() ;
    return 0;
}

