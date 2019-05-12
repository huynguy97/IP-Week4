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

/*
                                             
                                              
*/

//                                               
bool is_leap_year ( int year )
{
    if ((year%4 == 0 && year%100 != 0) || year%400 == 0)
        return true;
    else
        return false;
}

//                                         
int number_of_days_in_month ( int year, Month month )
{
    int days_in_month;
    switch (month)
    {
        case January:
        case March:
        case May:
        case July:
        case August:
        case October:
        case December: days_in_month = 31; break;
        case April:
        case June:
        case September:
        case November: days_in_month = 30; break;
        case February:
            if (is_leap_year(year))
                days_in_month = 29;
            else
                days_in_month = 28;
            break;
    }
    return days_in_month;
}

/*                                                                   
                                                
                                                                   */

//                                                                  
//                             
int correct_easter_days(int Y)
{
    int total_days = 0;
    if (is_leap_year(Y))
        switch(easter_month(Y))
        {
            case 1: total_days = 0; break;
            case 2: total_days = 31; break;
            case 3: total_days = 60; break;
            case 4: total_days = 91; break;
            case 5: total_days = 121; break;
            default: cout << "Error" << endl;
        }
    else
        switch(easter_month(Y))
        {
            case 1: total_days = 0; break;
            case 2: total_days = 31; break;
            case 3: total_days = 59; break;
            case 4: total_days = 90; break;
            case 5: total_days = 120; break;
            default: cout << "Error" << endl;
        }
    total_days = total_days + easter_day(Y);
    return total_days;
}

//                                                                                  
//                                                                                   
//                                                        
int base_to_month (int day_number, int year)
{
    int month_number = 1;
    while (number_of_days_in_month(year, (Month) month_number) < day_number )
    {
        day_number = day_number - number_of_days_in_month(year, (Month) month_number);
        month_number++;
    }
    return month_number;
}

//                                                                                      
//                                                                                   
//                                                        
int base_to_day (int day_number, int year)
{
    int month_number = 1;
    while (number_of_days_in_month(year, (Month) month_number) < day_number )
    {
        day_number = day_number - number_of_days_in_month(year, (Month) month_number);
        month_number++;
    }
    return day_number;
}

//                                                                       
//                      
void print_date(string holy_day, int date, int year)
{
    int month = base_to_month(date, year);
    int day = base_to_day(date, year);

    cout << "The date of " << holy_day << " in " << year << " is month "
        << month << ", day " << day << endl;
}

//                                                               
//                                                              
void show_holy_days()
{
    int year;

    cout << "Enter year" << endl;
    cin >> year;

    int carnival_base = correct_easter_days(year) - 49;
    int good_friday_base = correct_easter_days(year) - 2;
    int easter_date = correct_easter_days(year);
    int ascension_base = correct_easter_days(year) + 39;
    int whitsuntide_base = correct_easter_days(year) + 49;

    print_date("Carnival Sunday", carnival_base, year);
    print_date("Carnival Monday", carnival_base+1, year);
    print_date("Carnival Tuesday", carnival_base+2, year);
    print_date("Good Friday", good_friday_base, year);
    print_date("Easter", easter_date, year);
    print_date("Ascension Day", ascension_base, year);
    print_date("Whitsuntide", whitsuntide_base, year);
}

//                     
int main()
{
    show_holy_days();
    return 0;
}

