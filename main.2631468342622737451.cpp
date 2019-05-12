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

/*                                                                                   
                                                                                   
                                                   
*/
bool is_leap_year ( int year )
{
    return (year % 4 == 0 && (!(year % 100 == 0) || year % 400 == 0));
}

/*                                                                                                                            
                                                                                            
                                                                                                                                              
                                                                                                                            
*/
int number_of_days_in_month ( int year, Month month )
{
    bool leapYear = is_leap_year (year);
    int days;
    switch (month)
    {
    case April:
    case June:
    case September:
    case November: days = 30; break;
    case February: days = (leapYear == true) ? 29 : 28; break;
    default: days = 31; break;
    }
    return days;
}

/*                                                                   
                                                
                                                                   */

/*                                                                                                                                                
                                                                                                                                                      
                                                                                              
*/
int DayOfEaster (int year, Month month)
{
    int day = easter_day(year);
    for (int i = 1; i < month; i++)
        day += number_of_days_in_month(year, static_cast<Month>(i));
    return day;
}

/*                                                                                                            
                                                                                                                                              
*/
Month DateMonth (int year, int day)
{
    int monthCount = 0;
    int i = 0;
    do
    {
        i++;
        monthCount += number_of_days_in_month(year, static_cast<Month>(i));
    }
    while (monthCount < day);
    return static_cast<Month>(i);
}

//                                                                                                     
int DateDay (int year, int day)
{
    Month month = DateMonth (year, day);
    for (int i = 1; i < month; i++)
        day -= number_of_days_in_month(year, static_cast<Month>(i));
    return day;
}

//                                                                           
//                                                                                  
void Welcome()
{
    cout << "Greetings, user! This program tells you the dates of Easter, Carnival, Good Friday, Ascension Day and Whitsuntide of any year (A.D.)!"
    << endl << "Of which year would you like to know these dates? Please enter that year as a single positive number: ";
}

//                                                                               
//                                                                                                                          
int Dates(int holiday, int year)
{
    switch (holiday)
    {
        case 0: return DayOfEaster(year, easter_month(year));
        case 1: return (DayOfEaster(year, easter_month(year)) - 49);
        case 2: return (DayOfEaster(year, easter_month(year)) - 2);
        case 3: return (DayOfEaster(year, easter_month(year)) + 39);
        case 4: return (DayOfEaster(year, easter_month(year)) + 49);
    }
    return -1;
}

/*                                                                                                                                        
                                                                                                                    
                                                                                                                       
                                                                                                                  
*/
void show_holy_days ()
{
    int year;
    Welcome();
    cin >> year;
    string holidays [] = {"Easter", "Carnival", "Good Friday", "Ascension Day", "Whitsuntide"};
    cout << "The output is given as yyyy-mm-dd.\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "The date of " << holidays[i] << " in this year is " << year << "-" << DateMonth(year, Dates(i, year)) << "-"
        << DateDay(year, Dates(i, year)) << "!" << endl;
    }
}

int main()
{
    show_holy_days();
    return 0;
}

