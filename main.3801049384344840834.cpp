
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
//                                 

//                                               
bool is_leap_year (int year)
{
    if (year % 100 == 0 && year % 400 != 0 )
    {
        return false;
    }
    else if (year % 4 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//                                                                     
int number_of_days_in_month (int year, Month month)
{
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        return 31;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }
    else if (is_leap_year(year))
    {
        return 29;
    }
    else
    {
        return 28;
    }
}

/*                                                                   
                                                
                                                                   */
//                                                                         
int date_to_days(int year, int day, Month month)
{
    int days = 0;

    for (int i = 1; i < month; i++)
    {
        days += number_of_days_in_month(year, Month(i));
    }

    days += day;
    return days;
}

//                                                       
string get_month_name(int month_number)
{
    if (month_number == 1) return "January";
    else if (month_number == 2) return "February";
    else if (month_number == 3) return "March";
    else if (month_number == 4) return "April";
    else if (month_number == 5) return "May";
    else if (month_number == 6) return "June";
    else if (month_number == 7) return "July";
    else if (month_number == 8) return "August";
    else if (month_number == 9) return "September";
    else if (month_number == 10) return "October";
    else if (month_number == 11) return "November";
    else if (month_number == 12) return "December";
}

//                                                                                 
void days_to_date(int days, int year)
{
    int i = 1;
    int days_left = days;
    while (days - date_to_days(year, number_of_days_in_month(year, Month(i)), Month(i)) > 0)
    {
        days_left -= number_of_days_in_month(year, Month(i));
        i++;
    }
    string month_name = get_month_name(i);
    cout << month_name << " " << days_left << "\n";
}

void show_holy_days ()
{
    int year;
    cout << "Please input the year for which you would like to calculate Christian holy days:\n";
    cin >> year;

    //                                                           
    int days_easter = date_to_days(year, easter_day(year), easter_month(year));
    int days_carnival = days_easter - 49;
    int days_carnival_end = days_carnival + 2;
    int days_good_friday = days_easter - 2;
    int days_ascension_day = days_easter + 39;
    int days_whitsuntide = days_easter + 49;

    cout << "\nIn the year " << year << " the following Christian holy days are on the following dates:\n\n";

    //                
    cout << "Carnival, from:\n";
    days_to_date(days_carnival, year);
    cout << "Till:\n";
    days_to_date(days_carnival_end, year);
    cout << "\nGood Friday, on:\n";
    days_to_date(days_good_friday, year);
    cout << "\nEaster, on:\n";
    days_to_date(days_easter, year);
    cout << "\nAscension Day, on:\n";
    days_to_date(days_ascension_day, year);
    cout << "\nWhitsuntide, on:\n";
    days_to_date(days_whitsuntide, year);
}

int main()
{
    show_holy_days() ;
    return 0;
}

