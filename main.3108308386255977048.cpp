#include <iostream>

using namespace std;

//                     
//                   
//                      

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
    if(year % 4 == 0 && !(year % 400 != 0 && year % 100 == 0)) {
        return true;
    } else {
        return false;
    }
}

int number_of_days_in_month ( int year, Month month )
{
    int l = 0;
    switch(month) {
        case January:
            l = 30;
            break;
        case February:
            if( is_leap_year(year) ) {
                l = 29;
            } else {
                l = 28;
            }
            break;
        case March:
            l = 31;
            break;
        case April:
            l = 30;
            break;
        case May:
            l = 31;
            break;
        case June:
            l = 30;
            break;
        case July:
            l = 31;
            break;
        case August:
            l = 31;
            break;
        case September:
            l = 30;
            break;
        case October:
            l = 31;
            break;
        case November:
            l = 30;
            break;
        case December:
            l = 31;
            break;
    }
    return l;
}

/*                                                                   
                                                
                                                                   */

void print_data(string name, int month, int day){
    cout << name << "\t(" << static_cast<Month>(month) << "," << day << ")" << endl;
}

void show_holy_days ()
{
    int y;
    cout << "Enter a year: ";
    cin >> y;
    int easterDay = easter_day(y);
    int easterMonth = easter_month(y);
    int easterMonthLength = number_of_days_in_month(y, static_cast<Month>(easterMonth));
    int previousMonthLength = number_of_days_in_month(y, static_cast<Month>(easterMonth - 1));
    int nextMonthLength = number_of_days_in_month(y, static_cast<Month>(easterMonth + 1));

   //        
    int carnivalMonth, carnivalDay;
    if( (49 - easterDay) >= previousMonthLength) {
        carnivalMonth = easterMonth - 2;
        carnivalDay = number_of_days_in_month(y, static_cast<Month>(carnivalMonth)) + (easterDay + previousMonthLength - 49);
    } else {
        carnivalMonth = easterMonth - 1;
        carnivalDay = number_of_days_in_month(y, static_cast<Month>(carnivalMonth)) + (easterDay - 49);
    }

    //           
    int goodFriDay, goodFriMonth;
    if (easterDay <= 2) {
        goodFriMonth = easterMonth - 1;
        goodFriDay = previousMonthLength + easterDay - 2;
    } else {
        goodFriMonth = easterMonth;
        goodFriDay = easterDay - 2;
    }
    //           
    int whitsunMonth, whitsunDay;
    if((49 - (easterMonthLength - easterDay)) >= nextMonthLength) {
        whitsunMonth = easterMonth + 2;
        whitsunDay = 49 + easterDay - nextMonthLength - number_of_days_in_month(y, static_cast<Month>(whitsunMonth));
    } else {
        whitsunMonth = easterMonth + 1;
        whitsunDay = 49 - (easterMonthLength - easterDay);
    }

    //             
    int ascensionDay, ascensionMonth;
    if (whitsunDay <= 10) {
        ascensionMonth = whitsunMonth - 1;
        ascensionDay = previousMonthLength + whitsunDay - 10;
    } else {
        ascensionMonth = whitsunMonth;
        ascensionDay = whitsunDay - 10;
    }

    print_data("Carnival:", carnivalMonth, carnivalDay);
    print_data("Good Friday:", goodFriMonth, goodFriDay);
    print_data("Easter:    ", easterMonth, easterDay);
    print_data("Ascension:", whitsunMonth, whitsunDay);
    print_data("Whitsuntide:", whitsunMonth, whitsunDay);
}

int main()
{
    show_holy_days() ;
    return 0;
}

