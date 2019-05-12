#include <iostream>
#include <string>

/*                                        
                                 
 */

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
    if(year%100==0 && year%400 != 0) return false;
    else if (year%4 ==0) return true;
    else return false;
}

int number_of_days_in_month ( int year, Month month )
{
        switch(month){
            case(February):{
                if(is_leap_year(year)) return 29; else return 28;
            };
            case(January):
            case(March):
            case(May):
            case(July):
            case(August):
            case(October):
            case(December): return 31;
            default: return 30;
        }
}

string get_monthname (Month month) {
    switch (month) {
    case(January):
        return "January";
    case(February):
        return "February";
    case(March):
        return "March";
    case(April):
        return "April";
    case(May):
        return "May";
    case(June):
        return "June";
    case(July):
        return "July";
    case(August):
        return "August";
    case(September):
        return "September";
    case(October):
        return "October";
    case(November):
        return "November";
    case(December):
        return "December";
   }
}

/*                                                                   
                                                
                                                                   */
//                                 
int get_days_in_year(int year, int month, int month_day){
    int days = month_day;
    month = month-1;
    while(month >= 1){
            days+=number_of_days_in_month(year,(Month)month);
            month--;
    }
    return days;
}
//                                                
void print_yeardays_as_date(int year, int days){
    int month = 1;
    int n = number_of_days_in_month(year, (Month)month);

    //                                                  
    while(days > n) {
        days -= n;
        month++;
        n = number_of_days_in_month(year, (Month)month);
    }
    cout << "Day: " << days << ", Month: " << get_monthname((Month)month) << ", Year: " << year << endl;
}

void show_holy_days (int year)
{
    Month easterMonth = easter_month(year);
    int easterDay = easter_day(year);
    int easter_year_day = get_days_in_year(year,(int)easterMonth,easterDay);

    //                                
    cout << "Easter: ";
    print_yeardays_as_date(year, easter_year_day);
    cout << "Carnival: ";
    print_yeardays_as_date(year,easter_year_day-49);
    cout << "Good Friday: ";
    print_yeardays_as_date(year,easter_year_day-2);
    cout << "Ascension Day: ";
    print_yeardays_as_date(year,easter_year_day+39);
    cout << "Whitsuntide: ";
    print_yeardays_as_date(year,easter_year_day+49);
    cout << "Christmas: ";
    if (is_leap_year(year)) {
        print_yeardays_as_date(year, 360);
    }
    else {
        print_yeardays_as_date(year, 359);
    }

}

int main()
{
    cout << "Which year do you want to know? ";
    int my_year;
    cin >> my_year;
    show_holy_days(my_year);

    return 0;
}

