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
    if ((year % 4 == 0 && year % 100 != 0) || (year %400 == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int number_of_days_in_month ( int year, Month month )
{
    if ((month % 2 == 0 && month <=7 && month != 2) || (month % 2 != 0 && month >= 8))
    {
        return 30;
    }
    else if ((month % 2 != 0 && month <= 7 && month != 2) || (month % 2 == 0 && month >= 8))
    {
        return 31;
    }
    else if (is_leap_year && month == 2)
    {
        return 29;
    }
    else if (!is_leap_year && month == 2)
    {
        return 28;
    }
}

/*                                                                   
                                                
                                                                   */

int easter_daynum(int year)
{
    int easter_daynumber = 0;
    for(int i = easter_month(year) - 1; i > 0; --i)
    {
        easter_daynumber += number_of_days_in_month(year, static_cast<Month>(i));
    }
    return easter_daynumber = easter_daynumber + easter_day(year) - 1;
}

void show_holy_days ()
{
    int year;
    cin >> year;
    cout << endl;

    //         
    int carnival_daynum = easter_daynum(year) - 49;
    int carnival_month = 1;
    while(carnival_daynum > number_of_days_in_month(year, static_cast<Month>(carnival_month)))
    {
        carnival_daynum = carnival_daynum - number_of_days_in_month(year, static_cast<Month>(carnival_month));
        carnival_month += 1;
    }
    if (is_leap_year(year))
    {
        carnival_daynum += 1;
    }
    cout << "Carnival is on: " << carnival_daynum << " - " << carnival_month << " - " << year << endl;

    //            
    int friday_daynum = easter_daynum(year) - 2;
    int friday_month = 1;
    while(friday_daynum > number_of_days_in_month(year, static_cast<Month>(friday_month)))
    {
        friday_daynum = friday_daynum - number_of_days_in_month(year, static_cast<Month>(friday_month));
        friday_month += 1;
    }
    cout << "Good Friday is on: " << friday_daynum + 1 << " - " << friday_month << " - " << year << endl;

    //       
    cout << "Easter is on: " << easter_day(year) << " - " << easter_month(year) << " - " << year << endl;

    //          
    int ascension_daynum = easter_daynum(year) + 39;
    int ascension_month = 1;
    while(ascension_daynum > number_of_days_in_month(year, static_cast<Month>(ascension_month)))
    {
        ascension_daynum = ascension_daynum - number_of_days_in_month(year, static_cast<Month>(ascension_month));
        ascension_month += 1;
    }
    cout << "Ascension is on: " << ascension_daynum + 1 << " - " << ascension_month << " - " << year << endl;

    //            
    int whitsuntide_daynum = easter_daynum(year) + 49;
    int whitsuntide_month = 1;
    while(whitsuntide_daynum > number_of_days_in_month(year, static_cast<Month>(whitsuntide_month)))
    {
        whitsuntide_daynum = whitsuntide_daynum - number_of_days_in_month(year, static_cast<Month>(whitsuntide_month));
        whitsuntide_month += 1;
    }
    cout << "Whitsuntide is on: " << whitsuntide_daynum + 1 << " - " << whitsuntide_month << " - " << year << endl;

    cout << "However, we don't reaaaally know if it's correct, so please use Google to get to know the right date." << endl;
}

int main()
{
    cout << "What year do you want to know?" << endl;
    cout << "Year: ";
    show_holy_days() ;
    return 0;
}

