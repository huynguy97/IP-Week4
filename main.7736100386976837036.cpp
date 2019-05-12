#include <iostream>
//                                       
//                                            

//                                          
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
    if (year%400==0)
        return true;
    if(year%100==0)
        return false;
    return year % 4 ==0;
}

int number_of_days_in_month ( int year, Month month )
{
    switch(month)
    {
    case February:
        if (is_leap_year(year))
            return 29;
        else
            return 28 ;
    case April:
    case June:
    case September:
    case November: return 30;
    default: return 31;
    }
}

/*                                                                   
                                                
                                                                   */
//                                      
const int DIFFERENCE_CARNIVAL = -7*7;
const int DIFFERENCE_GOOD_FRIDAY = -2;
const int DIFFERENCE_WHITSUNTIDE = 7*7;
const int DIFFERENCE_ASCENSION_DAY = DIFFERENCE_WHITSUNTIDE - 10;

void show_Month (Month month)
{
    switch(month)
    {
        case January: cout << "January" ; break;
        case February: cout << "February"; break;
        case March: cout << "March"; break;
        case April: cout << "April"; break;
        case May: cout << "May"; break;
        case June: cout << "June"; break;
        case July: cout << "July"; break;
        case August: cout << "August"; break;
        case September: cout << "September"; break;
        case October: cout << "October"; break;
        case November: cout << "November"; break;
        case December: cout << "December"; break;
        default:       cout << "Unknown month, that is odd..."; break;
    }
}

int enter_year ()
{
    int year;
    do
    {
        cout << "Enter a year (1500 - 2100) or 0 to stop: ";
        cin >> year;
    }
    while ( (year<1500||year>2100) && year != 0);
    return year;
}

int day_number_in_year (int day, Month month, int year)
{
    Month m = January;
    int days_in_months = 0;
    while (m<month)
    {
        days_in_months=days_in_months+number_of_days_in_month(year, m);
        m=static_cast<Month> (m+1);
    }
    return days_in_months + day;
}

Month month_in_year_of_day_number (int day_number, int year)
{
    Month m = January;
    while(day_number>number_of_days_in_month(year, m))
    {
        day_number=day_number-number_of_days_in_month(year, m);
        m=static_cast<Month>(m+1);
    }
    return m;
}
 int day_in_month_of_day_number (int day_number, int year)
 {
    const Month MONTH = month_in_year_of_day_number(day_number,year);
    return day_number - day_number_in_year(1, MONTH, year) +1;
 }

 void show_day_number_as_date (int day_number, int year)
{
    cout << day_in_month_of_day_number(day_number,year);
    cout << ' ';
    show_Month(month_in_year_of_day_number(day_number, year));
}

void show_holy_days ()
{
    int year = enter_year();
    while (year!=0)
    {
        const int DAY = easter_day(year);
        const Month MONTH = easter_month(year);
        const int EASTER = day_number_in_year(DAY, MONTH, year);
        const int CARNIVAL = EASTER + DIFFERENCE_CARNIVAL;
        const int GOOD_FRIDAY = EASTER +DIFFERENCE_GOOD_FRIDAY;
        const int ASCENSION = EASTER + DIFFERENCE_ASCENSION_DAY;
        const int WHITSUNTIDE = EASTER + DIFFERENCE_WHITSUNTIDE;

        cout << "In year " << year << endl;
        cout << "Carnival is on " ; show_day_number_as_date(CARNIVAL, year) ; cout << endl;
        cout << "Good Friday is on " ; show_day_number_as_date(GOOD_FRIDAY, year) ; cout << endl;
        cout << "Easter is on " ; show_day_number_as_date(EASTER, year) ; cout << endl;
        cout << "Ascension is on " ; show_day_number_as_date(ASCENSION, year) ; cout << endl;
        cout << "Whitsuntide is on " ; show_day_number_as_date(WHITSUNTIDE, year) ; cout << endl;
        year=enter_year();
    }
}

int main()
{
    show_holy_days() ;
    return 0;
}

