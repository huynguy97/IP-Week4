#include <iostream>

//                             
//                         
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

//                              

bool is_leap_year ( int year )
{
    if (year % 100 == 0)
        if (year % 400 == 0)
        return true;
        else return false;
    else if (year % 4 == 0)
        return true;
    else return false;
}

//                                                           

int number_of_days_in_month (int year, Month month)
{
    switch (month){
    case January:
        return 31;
        break;
    case February:
        if(is_leap_year(year))
            return 29;
        return 28;
        break;
    case March:
        return 31;
        break;
    case April:
        return 30;
        break;
    case May:
        return 31;
        break;
    case June:
        return 30;
        break;
    case July:
        return 31;
        break;
    case August:
        return 31;
        break;
    case September:
        return 30;
        break;
    case October:
        return 31;
        break;
    case November:
        return 30;
        break;
    case December:
        return 31;
        break;
    default: cout << "Unknown month" << endl;
    }
}

/*                                                                   
                                                
                                                                   */

//                                                   

string month_number_to_name(Month month) {
    switch(month) {
    case January:
        return "January";
        break;
    case February:
        return "February";
        break;
    case March:
        return "March";
        break;
    case April:
        return "April";
        break;
    case May:
        return "May";
        break;
    case June:
        return "June";
        break;
    case July:
        return "July";
        break;
    case August:
        return "August";
        break;
    case September:
        return "September";
        break;
    case October:
        return "October";
        break;
    case November:
        return "November";
        break;
    case December:
        return "December";
        break;
    default:
        cout << "Unknown month";
        return " ";
    }
}

//                                       

void holy_days(int year, int days_from_easter){
    int j = easter_month(year);
    int i = (easter_day(year) + days_from_easter);
    while (i > number_of_days_in_month(year, static_cast < Month > (j))){
        i = (i - number_of_days_in_month(year, static_cast < Month > (j)));
        j++;
    }
    while (i<1){
        j--;
        i = (i+ number_of_days_in_month(year, static_cast < Month > (j)));
    }
    cout << month_number_to_name(static_cast < Month > (j)) << " " << i << endl;
}

//                       

void show_holy_days (int year)
{
    cout << "Carnival starts on ";
    holy_days(year, -49);
    cout << "Good Friday starts on ";
    holy_days(year, -2);
    cout << "Easter starts on " << month_number_to_name(static_cast < Month > (easter_month(year))) << " " << easter_day(year) << endl;
    cout << "Ascension Day starts on ";
    holy_days(year, 39);
    cout << "Whitsuntide starts on ";
    holy_days(year, 49);
}
int main()
{
    int year = 0 ;
    cout << "Please enter a year: ";
    cin >> year ;
    show_holy_days(year) ;
    return 0;
}

