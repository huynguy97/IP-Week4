
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
    float i = (year % 4);
    float j = (year % 100);
    float k = (year % 400);
    if( year == 0){
        cout << "0 is not a year !";
        return false;
    }
    if( (i == 0) && ((j != 0) || k == 0)) {
        return true;
    }
    else{
        return false;
    }
}

int number_of_days_in_month ( int year, Month month )
{
    if (is_leap_year(year)){
        switch(month){
            case 1:  return 31;
            case 2:  return 29;
            case 3:  return 31;
            case 4:  return 30;
            case 5:  return 31;
            case 6:  return 30;
            case 7:  return 31;
            case 8:  return 31;
            case 9:  return 30;
            case 10:  return 31;
            case 11:  return 30;
            case 12:  return 31;
            default: cout << "The number you entered does not have a corresponding month";
        }
    }
    else if (!is_leap_year(year)){
        switch(month){
            case 1: return 31;
            case 2: return 28;
            case 3: return 31;
            case 4: return 30;
            case 5: return 31;
            case 6: return 30;
            case 7: return 31;
            case 8: return 31;
            case 9: return 30;
            case 10: return 31;
            case 11: return 30;
            case 12: return 31;
            default: cout << "The number you entered does not have a corresponding month";
        }
        //                                   
    }
}

/*                                                                   
                                                
                                                                   */

int count_days(int year) {
    //          
    int d;
    if (is_leap_year(year)) {
        switch (easter_month(year)) {
            case 1:
                d = easter_day(year);
                return d;
            case 2:
                d = 31 + easter_day(year);
                return d;
            case 3:
                d = 31 + 29 + easter_day(year);
                return d;
            case 4:
                d = 31 + 29 + 31 + easter_day(year);
                return d;
            case 5:
                d = 31 + 29 + 31 + 30 + easter_day(year);
                return d;
            case 6:
                d = 31 + 29 + 31 + 30 + 31 + easter_day(year);
                return d;
        }
    } else {
        switch (easter_month(year)) {
            case 1:
                d = easter_day(year);
                return d;
            case 2:
                d = 31 + easter_day(year);
                return d;
            case 3:
                d = 31 + 28 + easter_day(year);
                return d;
            case 4:
                d = 31 + 28 + 31 + easter_day(year);
                return d;
            case 5:
                d = 31 + 28 + 31 + 30 + easter_day(year);
                return d;
            case 6:
                d = 31 + 28 + 31 + 30 + 31 + easter_day(year);
                return d;
        }
        //                                                                                           
    }

}
Month convert_day_month (int year, int d){
    int m = 1;

    while(d > number_of_days_in_month(year, (Month) m)){
        d -= number_of_days_in_month(year, (Month) m);
        m++;
    }
    return ((Month) m );
}
//                                                

int convert_day_date (int year, int d){
    int m = 1;

    while(d > number_of_days_in_month(year, (Month) m)){
        d -= number_of_days_in_month(year, (Month) m);
        m++;
    }
    return d;
}
//                                    

void show_holy_days (int year)
{
    std::cout <<"Easter is in month: " << convert_day_month(year, count_days(year)) << " and on day " << convert_day_date(year, count_days(year)) <<endl;
    std::cout << "Ascension is in month: " << convert_day_month(year, (count_days(year) + 39)) << " and on day " << convert_day_date(year, (count_days(year) +39)) <<endl;
    std::cout << "Whitsuntide is in month: " << convert_day_month(year, (count_days(year) + 49)) << " and on day " << convert_day_date(year, (count_days(year) +49)) << endl;
    std::cout << "Good friday is in month: " << convert_day_month(year, (count_days(year) -2)) << " and on day " << convert_day_date(year, (count_days(year)-2)) << endl;
    std::cout << "Carnival is in month: " << convert_day_month(year, (count_days(year) - 49)) << " and on day " << convert_day_date(year, (count_days(year) -49)) << endl;
}

int main()
{
    int year;
    int month;
    std::cout << "Input a year:";
    std::cin >> year;
    is_leap_year(year);
    if(is_leap_year(year)) {
        cout << year << " is a leap year" << endl;
    }
    else {
        cout << year << " is not a leap year" << endl;
    }
    std::cout << "From what month in this year would you like to know the number of days of? (1 is Jan, 2 is Feb, etc.) \n";
    std::cin >> month;
    cout << "The month you entered has " << number_of_days_in_month( year, (Month)month) << " days in year " << year << endl;
    std::cout << "\n" << "Here's a list of Christian days in the given year: " << endl;
    show_holy_days(year) ;

    return 0;
}
//                                                    
//                            

