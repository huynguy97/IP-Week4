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
//                                     
bool is_leap_year ( int year)
{
    //                        
    return (( year % 4 == 0) && (year % 100 != 0 || year % 400 == 0));
}

//                                 
int number_of_days_in_month ( int year, Month month )
{
    //                        
    switch (month)
    {
        case 1: return 31;
        case 2:
            if (is_leap_year(year))
            {
                return 29;
            }
            else
            {
                return 28;
            }
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: cout << "There exists no month with this number." << endl;
    }
}

/*                                                                   
                                                
                                                                   */
//                                           
int day_of_year (int year)
{
    int days;
    if (is_leap_year(year))
    {
        switch (easter_month(year))
        {
            case 1: days = easter_day(year);
                    return days;
            case 2: days = 31 + easter_day(year);
                    return days;
            case 3: days = 31 + 29 + easter_day(year);
                    return days;
            case 4: days = 31 + 29 + 31+ easter_day(year);
                    return days;
            case 5: days = 31 + 29 + 31 + 30 + easter_day(year);
                    return days;
        }
    }
    else
    {
        switch (easter_month(year))
        {
            case 1: days = easter_day(year);
                    return days;
            case 2: days = 31 + easter_day(year);
                    return days;
            case 3: days = 31 + 28 + easter_day(year);
                    return days;
            case 4: days = 31 + 28 + 31+ easter_day(year);
                    return days;
            case 5: days = 31 + 28 + 31 + 30 + easter_day(year);
                    return days;
        }
    }
}

//                                       
Month convert_nr_to_month (int year, int days)
{
    int monthnr = 1;
    while (days > number_of_days_in_month(year, (Month) monthnr))
    {
        days -= number_of_days_in_month(year, (Month) monthnr);
        monthnr++;
    }
    return (Month) monthnr;
}

//                                                  
int convert_day (int year, int days)
{
    int monthnr = 1;
    while (days > number_of_days_in_month(year, (Month) monthnr))
    {
        days -= number_of_days_in_month(year, (Month) monthnr);
        monthnr++;
    }
    return days;
}

void show_holy_days (int year)
{
    //                        
    cout << "In the year " << year << " carnival starts on day " << convert_day(year, (day_of_year(year) - 49)) << " of month " << convert_nr_to_month(year, (day_of_year(year) - 49)) << "." << endl;
    cout << "In the year " << year << " Good Friday is on day " << convert_day(year, (day_of_year(year) - 2)) << " of month " << convert_nr_to_month(year, (day_of_year(year) - 2)) << "." << endl;
    cout << "In the year " << year << " Easter is on day " << easter_day(year) << " of month " << easter_month(year) << "." << endl;
    cout << "In the year " << year << " Ascension day is on day " << convert_day(year, (day_of_year(year) + 39)) << " of month " << convert_nr_to_month(year, (day_of_year(year) + 39)) << "." << endl;
    cout << "In the year " << year << " Whitsuntide is on day " << convert_day(year, (day_of_year(year) + 49)) << " of month " << convert_nr_to_month(year, (day_of_year(year) + 49)) << "." << endl;
}

int main( )
{
    int year;
    cout << "Please enter a year." << endl;
    cin >> year;
    int month;
    cout << "Please enter a number for the month from which you would like to know the number of days. (1 is January, 2 is February, etc.)" << endl;
    cin >> month;
    cout << "Month " << month << " in year " << year << " has " << number_of_days_in_month(year, (Month) month) << " days." << endl;
    is_leap_year(year);
    number_of_days_in_month(year, (Month) month);
    day_of_year(year);
    show_holy_days(year) ;
    return 0;
}

