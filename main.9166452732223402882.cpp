#include <iostream>
#include <string>

using namespace std;

enum Month {January=1,February,March,April,May,June,July,August,September,October,November,December};

/*                                                                          
                                                                            
                                                           
*/
int easter_base(int year) {
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
int easter_day(int year) {
    return (easter_base (year) % 31) + 1 ;
}

/*                                                                                   
*/
Month easter_month(int year) {
    return static_cast<Month> (easter_base (year) / 31) ;
}

/*                                                                   
                                 
                                                                   */
//                           
//                     

bool is_leap_year(int year) {
    if(year % 4 == 0 && year % 100 != 0) {
        return true;
    } else if(year % 400 == 0) {
        return true;
    } else {
        return false;
    }
}

int number_of_days_in_month(int year, Month month) {
    if(month == 2) {
        if(is_leap_year(year)) {
            return 29;
        } else {
            return 28;
        }
    } else if(month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

/*                                                                   
                                                
                                                                   */
//                                                                                                                 
const string monthDic[] = {"error", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

//                                                                                          
//                          
int add_days (int year, Month month, int day, int days_to_add) {
    for (int i = 0; i < days_to_add; i++) {
        if (day >= number_of_days_in_month(year, month)) {
            day = 1;
            month = static_cast<Month>(static_cast<int>(month) + 1);
        } else {
            day++;
        }
    }
    return day;
}

int add_month (int year, Month month, int day, int days_to_add) {
    for (int i = 0; i < days_to_add; i++) {
        if (day >= number_of_days_in_month(year, month)) {
            day = 1;
            month = static_cast<Month>(static_cast<int>(month) + 1);
        } else {
            day++;
        }
    }
    return month;
}

int subtract_days (int year, Month month, int day, int days_to_subtract) {
    for (int i = 0; i < days_to_subtract; i++) {
        if (day == 1) {
            month = static_cast<Month>(static_cast<int>(month) - 1);
            day = number_of_days_in_month(year, month);
        } else {
            day--;
        }
    }
    return day;
}

int subtract_month (int year, Month month, int day, int days_to_subtract) {
    for (int i = 0; i < days_to_subtract; i++) {
        if (day == 1) {
            month = static_cast<Month>(static_cast<int>(month) - 1);
            day = number_of_days_in_month(year, month);
        } else {
            day--;
        }
    }
    return month;
}
//                        
//                    
int carnival_day_start(int year) {
    return subtract_days(year, easter_month(year), easter_day(year), 49);
}

int carnival_month_start(int year) {
    return subtract_month(year,easter_month(year), easter_day(year), 49);
}

int carnival_day_end(int year) {
    return add_days(year, static_cast<Month>(carnival_month_start(year)), carnival_day_start(year), 2);
}

int carnival_month_end(int year) {
    return add_month(year, static_cast<Month>(carnival_month_start(year)), carnival_day_start(year), 2);
}

int good_friday_day(int year) {
    return subtract_days(year, easter_month(year), easter_day(year), 2);
}

int good_friday_month(int year) {
    return subtract_month(year, easter_month(year), easter_day(year), 2);
}

int whitsuntide_day(int year) {
    return add_days(year,easter_month(year), easter_day(year), 49);
}

int whitsuntide_month(int year) {
    return add_month(year,easter_month(year), easter_day(year), 49);
}

int ascension_day_day(int year) {
    return subtract_days(year, static_cast<Month>(whitsuntide_month(year)), whitsuntide_day(year), 10);
}

int ascension_day_month(int year) {
    return subtract_month(year, static_cast<Month>(whitsuntide_month(year)), whitsuntide_day(year), 10);
}
//                  

void show_holy_days() {
    int year;
    cout << "Christian holy days of what year? ";
    cin >> year;
    //             
    cout << "\n";
    //                                                                          
    cout << "Carnival: " << monthDic[carnival_month_start(year)] << " " << carnival_day_start(year)
    << " - " << monthDic[carnival_month_end(year)]  << " " << carnival_day_end(year) << "\n\n";
    cout << "Good Friday: " << monthDic[good_friday_month(year)] << " " << good_friday_day(year) << "\n\n";
    cout << "Easter: " << monthDic[easter_month(year)] << " " << easter_day(year) << "\n\n";
    cout << "Ascension Day: " << monthDic[ascension_day_month(year)] << " " << ascension_day_day(year) << "\n\n";
    cout << "Whitsuntide: " << monthDic[whitsuntide_month(year)] << " " << whitsuntide_day(year) << "\n\n";
}

int main() {
    //                                         
    char ans = 'y';
    while(ans == 'y') {
        show_holy_days();
        cout << "Another year? (y) ";
        cin >> ans;
    }
    return 0;
}

