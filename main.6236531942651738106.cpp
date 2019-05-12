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
bool is_leap_year ( int year )
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int number_of_days_in_month ( int year, Month month )
{
    switch (month)
    {
    case January:
    case March:
    case May:
    case July:
    case August:
    case October:
    case December:
        return 31;
    case April:
    case June:
    case September:
    case November:
        return 30;
    case February:
        if(is_leap_year(year))
            return 29;
        return 28;
    }
}

/*                                                                   
                                                
                                                                   */

void introduce ()
{
    cout << "Holy day calculator!" << endl;
}

int ask_for_input ()
{
    cout << "Please, enter the year for calculations: ";
    int year;
    cin >> year;

    while(year < 0){
        cout << "Year cannot be negative, please, try again: ";
        cin >> year;
    }
    return year;
}

int day_count (int y, Month m, int d)
{
    int days = 0;
    for (int i = 1; i < m; i++)
        days += number_of_days_in_month(y, static_cast<Month>(i));
    return days + d;
}

Month get_month(int year, int day_count)
{
    for(int i = 1; i < 12; i++)
    {
        int number_of_days = number_of_days_in_month(year, static_cast<Month>(i));
        if (number_of_days > day_count)
            return static_cast<Month>(i);
        day_count -= number_of_days;
    }
}

int get_day(int year, int day_count)
{
    for(int i = 1; i < 12; i++)
    {
        int number_of_days = number_of_days_in_month(year, static_cast<Month>(i));
        if (number_of_days > day_count)
            return day_count;
        day_count -= number_of_days;
    }
}

string to_month(Month month)
{
    switch(month)
    {
    case January:
        return "January";
    case February:
        return "February";
    case March:
        return "March";
    case April:
        return "April";
    case May:
        return "May";
    case June:
        return "June";
    case July:
        return "July";
    case August:
        return "August";
    case September:
        return "September";
    case October:
        return "October";
    case November:
        return "November";
    case December:
        return "December";
    }
}

void mm_dd_phrase (int year, int day_count)
{
    Month mm = get_month(year, day_count);
    int dd = get_day(year, day_count);
    cout << to_month(mm) << " " << dd;
}

void output (int year, int cdc, int gfdc, int edc, int addc, int wdc)
{
    cout << "\n============== Holy dates for " << year << " ==============";
    cout << "\n\t* Carnival starts 7 weeks before Easter on: ";
    mm_dd_phrase(year, cdc);
    cout << "\n\t and ends on: ";
    mm_dd_phrase(year, cdc + 2);

    cout << "\n\t* Good Friday is during the Friday before Easter on: ";
    mm_dd_phrase(year, gfdc);

    cout << "\n\t* Easter is on: ";
    mm_dd_phrase(year, edc);

    cout << "\n\t* Ascension Day is 10 before Whitsuntide on: ";
    mm_dd_phrase(year, addc);

    cout << "\n\t* Whitsuntide is 7 weeks after Easter on: ";
    mm_dd_phrase(year, wdc);
}

void show_holy_days ()
{
    introduce ();
    int year = ask_for_input ();

    Month easter_m = easter_month(year);
    int easter_d = easter_day(year);
    int easter_day_count = day_count(year, easter_m, easter_d);

    int carnival_day_count = easter_day_count - 49;
    int good_friday_day_count = easter_day_count - 2;
    int whitsuntide_day_count = easter_day_count + 49;
    int ascension_day_day_count = whitsuntide_day_count - 10;

    output(year, carnival_day_count, good_friday_day_count, easter_day_count, ascension_day_day_count, whitsuntide_day_count);
}

int main()
{
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
//                                                          
//                                                             
//                                                           
//                                                            
//                                                            
    show_holy_days() ;
    return 0;
}

