#include <iostream>

using namespace std;

enum Month {January=1,February,March,April,May,June,July,August,September,October,November,December} ;

/*                                                                          
                                                                            
                                                                                
*/

//                         
//                       
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
    if(((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0){
        return true;
    }
    else{
        return false;
    }

}

int number_of_days_in_month ( int year, Month month )
{
    if(month == February){
        if(is_leap_year(year)){
            return 29;
        }
        else{
            return 28;
        }
    }
    else if(month % 2 == 0){
        if (month <= 6){
            return 30;
        }
        else {
            return 31;
        }
    }
    else if (month <= 7){
            return 31;
        }
        else {
            return 30;
        }
}

/*                                                                   
                                                
                                                                    
                                                          */

string number_to_month(int nr)
{
    //                                   
    switch (nr){
        case 1:
            return "January";
            break;

        case 2:
            return "February";
            break;

        case 3:
            return "March";
            break;

        case 4:
            return "April";
            break;

        case 5:
            return "May";
            break;

        case 6:
            return "June";
            break;

        case 7:
            return "July";
            break;

        case 8:
            return "August";
            break;

        case 9:
            return "September";
            break;

        case 10:
            return "October";
            break;

        case 11:
            return "November";
            break;

        case 12:
            return "December";
            break;
    }
}

string days_to_month(int days, int year){
    int months = 0;

    while(days >= 0){
        days -= number_of_days_in_month(year, static_cast<Month>(months+1));
        months ++;
    }
    return number_to_month(months);
}

int days_to_days(int days, int year){
    int months = 0;

    while(days >= 0){
        days -= number_of_days_in_month(year, static_cast<Month>(months+1));
        months ++;
    }
    return days + number_of_days_in_month(year, static_cast<Month>(months));
}
void show_holy_days (int year)
{
    //              
    cout << "Easter is on:\t\t" << number_to_month(easter_month(year)) << " " << easter_day(year) << endl;

    //             
    int easter_year_day = 0;
    for(int i=1; i < easter_month(year); i++){
        //                                             
        easter_year_day += number_of_days_in_month(year, static_cast<Month>(i));
    }
    easter_year_day += easter_day(year);
    //                        

    //         
    int carnival_start = easter_year_day - 7*7;
    int carnival_end = carnival_start + 2;
    cout << "Carnival starts on:\t" << days_to_month(carnival_start, year) << " " << days_to_days(carnival_start, year) << endl;
    cout << "Carnival ends on:\t" << days_to_month(carnival_end, year) << " " << days_to_days(carnival_end, year) << endl;

    //            
    int good_friday = easter_year_day - 2;
    cout << "Good friday is on:\t" << days_to_month(good_friday, year) << " " << days_to_days(good_friday, year) << endl;

    //           
    int whitsuntide = easter_year_day + 7*7;
    cout << "Whitsuntide is on:\t" << days_to_month(whitsuntide, year) << " " << days_to_days(whitsuntide, year) << endl;

    //              
    int asc = whitsuntide - 10;
    cout << "Ascension Day is on:\t" << days_to_month(asc, year) << " " << days_to_days(asc, year) << endl;

    //                                                                           

}

int main()
{
    int year;
    cout << "Please enter a year: ";
    cin >> year;
    cout << endl;
    show_holy_days(year) ;

    return 0;
}

