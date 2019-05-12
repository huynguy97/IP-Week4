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
bool is_leap_year ( int year ) //                                                            
{
    if (year%4 == 0)
    {
        if (year%100 == 0 && year%400 !=0)
        {
            return false;
        }
        return true;
    }
    return false;
}

int number_of_days_in_month ( int year, Month month ) //                                      
{
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (is_leap_year(year))
    {
        days[1] = 29; //                                          
    }
    return days [month -1]; //                          
}

/*                                                                   
                                                
                                                                   */
int month_to_int(Month month) //                                                                      
{
    int intmonth = 0;
    switch(month)
    {
        case January : intmonth = 1; break;
        case February : intmonth = 2; break;
        case March : intmonth = 3; break;
        case April : intmonth = 4; break;
        case May : intmonth = 5; break;
        case June : intmonth = 6; break;
        case July : intmonth = 7; break;
        case August : intmonth = 8; break;
        case September : intmonth = 9; break;
        case October : intmonth = 10; break;
        case November : intmonth = 11; break;
        case December : intmonth = 12; break;
    }
    return intmonth;
}

Month int_to_month(int month) //                                                                         
{
    Month monthmonth;
    switch(month)
    {
        case 1: monthmonth = January; break;
        case 2: monthmonth = February; break;
        case 3: monthmonth = March; break;
        case 4: monthmonth = April; break;
        case 5: monthmonth = May; break;
        case 6: monthmonth = June; break;
        case 7: monthmonth = July; break;
        case 8: monthmonth = August; break;
        case 9: monthmonth = September; break;
        case 10: monthmonth = October; break;
        case 11: monthmonth = November; break;
        case 12: monthmonth = December; break;
    }
    return monthmonth;
}

int total_days(int year, Month month, int day) //                                                                   
{
    int total = day;
    int intmonth = month_to_int(month);
    if (intmonth == 1) //                                                                
    {
        return total;
    }
    else
    {
        for (int i = 1; i < intmonth; i++) //                                                                                
        {
            total += number_of_days_in_month(year, int_to_month(i));
        }
    }
    return total;
}

Month days_to_month(int year, int total) //                                               
{
    int i = 1;
    while (total > 0) //                                                                                                                       
    {
        total -= number_of_days_in_month(year, int_to_month(i));
        i += 1;
    }
    return int_to_month(i-1);
}

int days_to_day(int year, int total) //                                                                
{
    int totalmonth = total_days(year, days_to_month(year, total), 1); //                                                                                                    
    return total - totalmonth + 1;
}

int festivity_day (int year, Month emonth, int eday, int days) //                                                                                     
{
    int total = total_days(year, emonth, eday);
    total -= days;
    return days_to_day(year, total);
}

Month festivity_month (int year, Month emonth, int eday, int days) //                                                                                         
{
    int total = total_days(year, emonth, eday);
    total -= days;
    return days_to_month(year, total);
}

void show_holy_days ()
{
    int year;
    cout << "For what year do you want to know the holy days? \n"; //                     
    cin >> year;
    char* months_to_text[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"}; //                                                      
    int eday = easter_day(year); //                                                                         
    Month emonth = easter_month(year);
    int carstart = festivity_day(year, emonth, eday, 7*7);
    int carend = festivity_day(year, emonth, eday, 7*7-2);
    Month carmstart = festivity_month(year, emonth, eday, 7*7);
    Month carmend = festivity_month(year, emonth, eday, 7*7-2);
    int goodday = festivity_day(year, emonth, eday, 2);
    Month goodmonth = festivity_month(year, emonth, eday, 2);
    int asday = festivity_day(year, emonth, eday, -7*7+10);
    Month asmonth = festivity_month(year, emonth, eday, -7*7+10);
    int whitday = festivity_day(year, emonth, eday, -7*7);
    Month whitmonth = festivity_month(year, emonth, eday, -7*7);
    cout << "Carnival starts on " << carstart << " " << months_to_text[month_to_int(carmstart)-1] << " and ends on " << carend << " " << months_to_text[month_to_int(carmend)] << "\n";
    cout << "Good Friday is on " << goodday << " " << months_to_text[month_to_int(goodmonth)-1] << "\n";
    cout << "Easter is on " << eday << " " << months_to_text[month_to_int(emonth)-1] << "\n";
    cout << "Ascension Day is on " << asday << " " << months_to_text[month_to_int(asmonth)-1] << "\n";
    cout << "Whitsuntide is on " << whitday << " " << months_to_text[month_to_int(whitmonth)-1] << "\n";
}

int main()
{
    show_holy_days() ;
    return 0;
}

