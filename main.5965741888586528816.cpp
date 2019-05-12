#include <iostream>

using namespace std;

/*
            
                       
                            
*/

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
    if (year % 4 == 0){
        if (year % 100 != 0){
            return true;
        }
        else{
            if ((year % 100 == 0) && (year % 400 == 0)){
            return true;
            }
            else{
                return false;
            }
        }
    }
        else{
            return false;
    }
}

int number_of_days_in_month ( int year, Month month )
{
    switch(month){
    case January  : return 31;
    case February : if(!is_leap_year(year)){
                        return 28;
                        }
                        else{
                            return 29;
                        }
    case March    : return 31;
    case April    : return 30;
    case May      : return 31;
    case June     : return 30;
    case July     : return 31;
    case August   : return 31;
    case September: return 30;
    case October  : return 31;
    case November : return 30;
    case December : return 31;
    }
}

/*                                                                   
                                                
                                                                   */
int convert_date_to_daynumber (int year, Month month, int day)
{

    if (!is_leap_year(year)){
        switch(month){
            case January  : return (0 + day);
            case February : return (31 + day);
            case March    : return (59 + day);
            case April    : return (90 + day);
            case May      : return (120 + day);
            case June     : return (151 + day);
            case July     : return (181 + day);
            case August   : return (212 + day);
            case September: return (243 + day);
            case October  : return (273 + day);
            case November : return (304 + day);
            case December : return (344 + day);
        }
    }
    else{
        switch(month){
            case January  : return (0 + day);
            case February : return (31 + day);
            case March    : return (60 + day);
            case April    : return (91 + day);
            case May      : return (121 + day);
            case June     : return (152 + day);
            case July     : return (182 + day);
            case August   : return (213 + day);
            case September: return (244 + day);
            case October  : return (274 + day);
            case November : return (305 + day);
            case December : return (345 + day);
        }
    }
}

Month convert_daynumber_to_month (int year, int daynumber)
{
    int monthnr = 1;
    int nrdaysmonth = 31;
        while(daynumber > nrdaysmonth){
            daynumber = daynumber - nrdaysmonth;
            monthnr++;
            nrdaysmonth = number_of_days_in_month(year, static_cast<Month>(monthnr));
    }
    Month month_answer = static_cast<Month>(monthnr);
    return month_answer;
}

int convert_daynumber_to_day (int year, int daynumber)
{
    int monthnr = 1;
    int nrdaysmonth = 31;
        while(daynumber > nrdaysmonth){
            daynumber = daynumber - nrdaysmonth;
            monthnr++;
            nrdaysmonth = number_of_days_in_month(year, static_cast<Month>(monthnr));
    }
    return daynumber;
}

/*
                                                                                                               
                                                                           
                                                                                     
                                                                                                                    
         
*/

void show_holy_days ()
{
    int year;
    int easter_d;
    Month easter_m;
    cout << "Enter a year: ";
    cin >> year;
    easter_d = easter_day(year);
    easter_m = easter_month(year);
    cout << "Easter: " << easter_d << "-" << easter_m << "-" << year;

    int daynumber = convert_date_to_daynumber(year, easter_m, easter_d);
    int daynr_carn = daynumber - 49;
    int daynr_gf = daynumber - 2;
    int daynr_ad = daynumber + 39;
    int daynr_whit = daynumber + 49;

    int carn_day = convert_daynumber_to_day(year, daynr_carn);
    int carn_month = convert_daynumber_to_month(year, daynr_carn);
    cout << "\nCarnival: " << carn_day << "-" << carn_month << "-" << year;

    int gf_day = convert_daynumber_to_day(year, daynr_gf);
    int gf_month = convert_daynumber_to_month(year, daynr_gf);
    cout << "\nGood Friday: " << gf_day << "-" << gf_month << "-" << year;

    int ad_day = convert_daynumber_to_day(year, daynr_ad);
    int ad_month = convert_daynumber_to_month(year, daynr_ad);
    cout << "\nAscension Day: " << ad_day << "-" << ad_month << "-" << year;

    int whit_day = convert_daynumber_to_day(year, daynr_whit);
    int whit_month = convert_daynumber_to_month(year, daynr_whit);
    cout << "\nWhitsuntide: " << whit_day << "-" << whit_month << "-" << year;
}

int main()
{
    show_holy_days() ;
    return 0;
}

