#include <iostream>

using namespace std;

enum Month {January=1,February,March,April,May,June,July,August,September,October,November,December} ;

/*                                                                          
                                                                            
                                                           
*/
int easter_base ( int year ){
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
int easter_day ( int year ){
    return (easter_base (year) % 31) + 1 ;
}

/*                                                                                   
*/
Month easter_month ( int year ){
    return static_cast<Month> (easter_base (year) / 31) ;
}

/*                                                                   
                                 
                                                                   */
bool is_leap_year ( int year ){
    if (year % 400 == 0){
        return true;
    }
    else{
        if (year % 100 == 0){
            return false;
        }
        else{
            if (year % 4 == 0){
                return true;
            }
            else{
                return false;
            }
        }
    }
}

int number_of_days_in_month ( int year, Month month ){
    if (month == 2){
        if (is_leap_year(year)){
            return 29;
        }
        else{
            return 28;
        }
    }
    else{
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
            return 31;
        }
        else{
            return 30;
        }
    }
}

/*                                                                   
                                                
                                                                   */

//                       
//                    

void show_holy_days (){
    int Y;
    cout << "Of what year do you want the holy days?" << endl;
    cin >> Y;

    int carnival_day = easter_day(Y) - 49;
    Month carnival_month = easter_month(Y);
    while (carnival_day <= 0){
        carnival_month = static_cast<Month>(carnival_month - 1);
        carnival_day += number_of_days_in_month(Y, carnival_month);
    }

    int good_friday_day = easter_day(Y) - 2;
    Month good_friday_month = easter_month(Y);
    while (good_friday_day <= 0){
        good_friday_month = static_cast<Month>(good_friday_month - 1);
        good_friday_day += number_of_days_in_month(Y, good_friday_month);
    }

    int whitsuntide_day = easter_day(Y) + 49;
    Month whitsuntide_month = easter_month(Y);
    while (whitsuntide_day > number_of_days_in_month(Y, whitsuntide_month)){
        whitsuntide_day -= number_of_days_in_month(Y, whitsuntide_month);
        whitsuntide_month = static_cast<Month>(whitsuntide_month + 1);
    }

    int ascension_day = whitsuntide_day - 10;
    Month ascension_month = whitsuntide_month;
    while (ascension_day <= 0){
        ascension_month = static_cast<Month>(ascension_month - 1);
        ascension_day += number_of_days_in_month(Y, ascension_month);
    }

    int carnival_day_end = carnival_day + 2;
    Month carnival_month_end = carnival_month;
    while (carnival_day_end > number_of_days_in_month(Y, carnival_month_end)){
        carnival_day_end -= number_of_days_in_month(Y, carnival_month_end);
        carnival_month_end = static_cast<Month>(carnival_month_end + 1);
    }

    cout << "Carnival is from " << carnival_month << ", " << carnival_day << " to " << carnival_month_end << ", " << carnival_day_end << endl;
    cout << "Good Friday is on " << good_friday_month << ", " << good_friday_day << endl;
    cout << "Easter is on " << easter_month(Y) << ", " << easter_day(Y) << endl;
    cout << "Ascension Day is on " << ascension_month << ", " << ascension_day << endl;
    cout << "Whitsuntide is on " << whitsuntide_month << ", " << whitsuntide_day << endl;
}

int main(){
    show_holy_days() ;
    return 0;
}

