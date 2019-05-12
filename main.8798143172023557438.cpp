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
    if (year % 4 == 0)
    {
        if (year % 100 == 0 && year % 400 != 0)
        {
            return false;
        }
        return true;
    }
    return false;
}

//                                                                                       
void determine_leap_year ()
{
    cout << "Hello world!\n"
         << "What year would you like to investigate?" << endl;
    int x;
    cin  >> x;
    bool result = is_leap_year(x);
    std::cout << std::boolalpha;
    cout << result << endl;
}

    //                        
void welcome_message_days_in_month ()
{

}

enum MonthLength
{
    Jan_Length = 31, Feb_Length = 28,
    Mar_Length = 31, Apr_Length = 30,
    May_Length = 31, Jun_Length = 30,
    Jul_Length = 31, Aug_Length = 31,
    Sep_Length = 30, Oct_Length = 31,
    Nov_Length = 30, Dec_Length = 31
};

int number_of_days_in_month(int year, int month)
{
    switch (static_cast<Month>(month))
    {
    case January:
        return static_cast<int>(Jan_Length);
    case February:
        if (is_leap_year (year))
            {
                return static_cast<int>(Feb_Length) + 1;
            }
        return static_cast<int>(Feb_Length);
    case March:
        return static_cast<int>(Mar_Length);
    case April:
        return static_cast<int>(Apr_Length);
    case May:
        return static_cast<int>(May_Length);
    case June:
        return static_cast<int>(Jun_Length);
    case July:
        return static_cast<int>(Jul_Length);
    case August:
        return static_cast<int>(Aug_Length);
    case September:
        return static_cast<int>(Sep_Length);
    case October:
        return static_cast<int>(Oct_Length);
    case November:
        return static_cast<int>(Nov_Length);
    case December:
        return static_cast<int>(Dec_Length);
    }
}
//                                                     
//                            
//                                 
//          
//              
//                                         
//          
//             
//                                                
//             

/*                                                                   
                                                
                                                                   */
int whitsuntide (int year)
{
    return easter_base (year) + 7*7;
}

int start_carnival (int year)
{
    return easter_base (year) - 7*7;
}

int end_carnival (int year)
{
    return easter_base (year) - 7*7 + 2;
}

int ascencion_day (int year)
{
    return whitsuntide (year) - 10;
}

int good_friday (int year)
{
    return easter_base (year) - 2;
}

string day_and_weekday (int day)
{
    switch (day)
    {
    case -6:
        return "Saturday";
    case -5:
        return "Friday";
    case -4:
        return "Thursday";
    case -3:
        return "Wednesday";
    case -2:
        return "Tuesday";
    case -1:
        return "Monday";
    case 0:
        return "Sunday";
    case 1:
        return "Monday";
    case 2:
        return "Tuesday";
    case 3:
        return "Wednesday";
    case 4:
        return "Thursday";
    case 5:
        return "Friday";
    case 6:
        return "Saturday";
    }
}

void show_day_and_month (int year, int daynumber)
{
    int weekdaynumber_easter = easter_base(year)%7;
    int weekdaynumber = daynumber%7;
    int weekday = weekdaynumber_easter - weekdaynumber;

    cout << day_and_weekday(weekday);
}

int show_day_in_month(int daynumber)
{
    cout << (daynumber % 31) + 1;
}

void show_month(int daynumber, int year)
{
    if (daynumber - 31 <= 0)
    {
        cout << "January";
        return;
    }
    daynumber = daynumber - 31;
    if (is_leap_year (year))
    {
        if (daynumber - 29 <= 0)
        {
            cout << "February";
            return;
        }
        daynumber = daynumber - 29;
    }
    else
    {
        if (daynumber - 28 <= 0)
        {
            cout << "February";
            return;
        }
        daynumber = daynumber - 28;
    }
    if (daynumber - 31 <= 0)
    {
        cout << "March";
        return;
    }
    daynumber = daynumber - 31;
    if (daynumber - 30 <= 0)
    {
        cout << "April";
        return;
    }
    daynumber = daynumber - 30;
    if (daynumber - 31 <= 0)
    {
        cout << "May";
        return;
    }
    daynumber = daynumber - 31;
    if (daynumber - 30 <= 0)
    {
        cout << "June";
        return;
    }
    daynumber = daynumber - 30;
    if (daynumber - 31 <= 0)
    {
        cout << "July";
        return;
    }
    daynumber = daynumber - 31;
    if (daynumber - 31 <= 0)
    {
        cout << "Augustus";
        return;
    }
    daynumber = daynumber - 31;
    if (daynumber - 30 <= 0)
    {
        cout << "September";
        return;
    }
    daynumber = daynumber - 30;
    if (daynumber - 31 <= 0)
    {
        cout << "October";
        return;
    }
    daynumber = daynumber - 31;
    if (daynumber - 30 <= 0)
    {
        cout << "November";
        return;
    }
    cout << "December" << endl;

}

void show_holy_days(int year)
{
    cout << "This year Easter is on : Sunday " << easter_day(year) << " ";
    show_month (easter_base(year), year);
    cout << "." << endl;
    cout << "This year Whitsuntide is on : ";
    show_day_and_month(year, whitsuntide(year));
    cout << " ";
    show_day_in_month(whitsuntide(year));
    cout << " ";
    show_month(whitsuntide(year), year);
    cout << "." << endl;
    cout << "This year Carnival starts on : ";
    show_day_and_month(year, start_carnival(year));
    cout << " ";
    show_day_in_month(start_carnival(year));
    cout << " ";
    show_month(start_carnival(year), year);
    cout << "." << endl;
    cout << "This year Carnival ends on : ";
    show_day_and_month(year, end_carnival(year));
    cout << " ";
    show_day_in_month(end_carnival(year));
    cout << " ";
    show_month(end_carnival(year), year);
    cout << "." << endl;
    cout << "This year Ascension Day is on : ";
    show_day_and_month(ascencion_day(year), year);
    cout << " ";
    show_day_in_month(ascencion_day(year));
    cout << " ";
    show_month(ascencion_day(year), year);
    cout << "." << endl;
    cout << "This year Good Friday day ends on : ";
    show_day_and_month(year, good_friday(year));
    cout << " ";
    show_day_in_month(good_friday(year));
    cout << " ";
    show_month(good_friday(year), year);
    cout << "." << endl;
    //                        
}

int main()
{
    cout << "Hello world!\n"
         << "Enter year to find out on what days the Holy days are:" << endl;
    int year;
    cin >> year;
    show_holy_days(year);
}

//                                                             
//                                                 
//   
//                                                                                                  
//                                                                                                  
//
//                            
//                                 
//          
//              
//                         
//     
//                                    
//     
//                               
//   

