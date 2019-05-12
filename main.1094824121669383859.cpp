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
    if (year % 4 == 0) {
        if (year % 100 == 0 && year % 400 != 0){
            return false;
        }
        return true;
    }
    return false;
}

int number_of_days_in_month ( int year, Month month )
{

    int month_lengths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (is_leap_year(year) && month == February){
        return month_lengths[(int)month - 1] + 1;
    }
    else{
        return month_lengths[(int)month - 1];
    }

}

/*                                                                   
                                                
                                                                   */

int day_of_month(int days){
    return (days%31)+1;
}

Month get_month(int days){
    return (Month) (days / 31);
}

void show_holy_days (int year)
{
    int easter  = easter_base(year);
    int carnival  = easter - 52;
    int good_friday = easter - 2;
    int ascension = easter + 40;
    int whitsuntide = easter + 50;

    cout << "The holy days in " << year << " are as follows:" << endl;
    cout << "Carnival: " << day_of_month(carnival) << "/" << get_month(carnival) << endl;
    cout << "Good Friday: " << day_of_month(good_friday) << "/" << get_month(good_friday) << endl;
    cout << "Easter: " << day_of_month(easter) << "/" << get_month(easter) << endl;
    cout << "Ascension Day: " << day_of_month(ascension) << "/" << get_month(ascension)  << endl;
    cout << "Whitsuntide: " << day_of_month(whitsuntide) << "/" << get_month(whitsuntide) << endl;

}

int main()
{
    int holiday_year;
    cout << "Please enter the year of which you want to know the holidays:"<<endl;
    cin >> holiday_year;

    show_holy_days(holiday_year);

    return 0;
}

