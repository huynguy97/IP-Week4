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
    if(year % 4 == 0) {
        if((year % 100 == 0) && (year % 400 != 0)) {
            return false;
        } else {
            return true;
        }
    }
    return false;
}

int number_of_days_in_month ( int year, Month month )
{
    if(is_leap_year(year) && month == 2) {
        return 29;
    } else {
        switch(month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12: return 31; break;
            case 2: return 28; break;
            case 4:
            case 6:
            case 9:
            case 11: return 30; break;
        }
    }
}

/*                                                                   
                                                
                                                                   */
/*

*/

//                                                                                                                            
int day_back(int day, int month, int year, int dayBack) {
    int thisday = dayBack;
    if(day > thisday) {
        return day - thisday;
    }
    thisday = thisday - day;
    int i = 1;
    while(true) {
        if(thisday - number_of_days_in_month(year, Month(month-i)) < 0) {
            return number_of_days_in_month(year, Month(month-i)) - thisday;
        } else {
            thisday = thisday - number_of_days_in_month(year, Month(month-i));
            i++;
        }
    }
}

//                                                                                                                              
int month_back(int day, int month, int year, int dayBack) {
    int thisday = dayBack;
    if(day > thisday) {
        return month;
    }
    thisday = thisday - day;
    int i = 1;
    while(true) {
        if(thisday - number_of_days_in_month(year, Month(month-i)) < 0) {
            return month - i;
        } else {
            thisday = thisday - number_of_days_in_month(year, Month(month-i));
            i++;
        }
    }
}

//                                                                                                                          
int day_forward(int day, int month, int year, int dayBack) {
    int thisday = dayBack;
    thisday =  thisday - (number_of_days_in_month(year, Month(month))- day);
    int i = 1;
    while(true) {
        if(thisday - number_of_days_in_month(year, Month(month+i)) < 0) {
            return thisday;
        } else {
            thisday = thisday - number_of_days_in_month(year, Month(month+i));
            i++;
        }
    }
}

//                                                                                                                            
int month_forward(int day, int month, int year, int dayBack) {
    int thisday = dayBack;
    thisday =  thisday - (number_of_days_in_month(year, Month(month))- day);
    int i = 1;
    while(true) {
        if(thisday - number_of_days_in_month(year, Month(month+i)) < 0) {
            return month + i;
        } else {
            thisday = thisday - number_of_days_in_month(year, Month(month+i));
            i++;
        }
    }
}
//                                                        
string month_con(int month) {
    switch(month) {
        case 1: return "January"; break;
        case 2: return "February"; break;
        case 3: return "March"; break;
        case 4: return "April"; break;
        case 5: return "May"; break;
        case 6: return "June"; break;
        case 7: return "July"; break;
        case 8: return "August"; break;
        case 9: return "September"; break;
        case 10: return "October"; break;
        case 11: return "November"; break;
        case 12: return "December"; break;
        }
}

void show_holy_days ()
{
    int year = 0;
   //                
    cout << "For which year do you want to know the Christian holy days? ";
    cin >> year;
    cout << "\n";
    cout << "The holy days for the year " << year << " are: " << endl;

   //                                                             
    int easter = easter_day(year);
    Month easterMonth = easter_month(year);
    int easterBase = easter_base(year);

    int carnivalday = day_back(easter, easterMonth, year, 49);
    int carnivalmonth = month_back(easter, easterMonth, year, 49);

    int good_friday_day = 0;
    int good_friday_month = 0;

    if(easter > 2) {
        good_friday_day = easter - 2;
        good_friday_month = easterMonth;
    } else {
        good_friday_day = 31 + (easter - 2);
        good_friday_month = easterMonth - 1;
    }

    int whitsuntideday = day_forward(easter, easterMonth, year, 49);
    int whitsuntidemonth = month_forward(easter, easterMonth, year, 49);

    int Ascension_day = day_back(whitsuntideday, whitsuntidemonth, year, 10);
    int Ascension_month = month_back(whitsuntideday, whitsuntidemonth, year, 10);

    cout << "Easter (" << month_con(easterMonth) << ", " << easter << ")" << endl;
    cout << "Carnival (" << month_con(carnivalmonth) << ", " << carnivalday << ")" << endl;
    cout << "Good Friday (" << month_con(good_friday_month) << ", " << good_friday_day << ")" << endl;
    cout << "Ascension Day (" << month_con(Ascension_month) << ", " << Ascension_day << ")" << endl;
    cout << "Whitsuntide (" << month_con(whitsuntidemonth) << ", " << whitsuntideday << ")" << endl;
}

int main()
{
    show_holy_days();
    return 0;
}

