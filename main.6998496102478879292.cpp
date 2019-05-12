#include <iostream>

#include <string>
using namespace std;

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
bool is_leap_year ( int year ) //                                          
{
    if ((year % 4 == 0) && (year % 100 != 0))
    {
        return true;
    } else if (year % 400 == 0)
    {
        return true;
    } else
    {
        return false;
    }
}

int number_of_days_in_month ( int year, Month month ) //                                                      
{
    switch (month) {
        case January:
        case March:
        case May:
        case July:
        case August:
        case October:
        case December:
            return 31;
        case February:
            if (is_leap_year(year))
            {
                return 29;
            } else
            {
                return 28;
            }
        case April:
        case June:
        case September:
        case November:
            return 30;
        default: return 0;
    }
}

int get_day_number(int year, Month month, int mDay) //                                                            
{
    int result = 0;
    int m = static_cast<int>(month);
    for (int i = 1; i < m; i++){
        result += number_of_days_in_month(year, static_cast<Month>(i));
    }
    return result + mDay;
}

string get_month_name(Month month){ //                                           
    switch (month)
    {
            case January: return "January";
            case February: return "February";
            case March: return "March";
            case April: return "April";
            case May: return "May";
            case June: return "June";
            case July: return "July";
            case August: return "August";
            case September: return "September";
            case October: return "October";
            case November: return "November";
            case December: return "December";
            default: return "";
    }
}

string date_string(int dateNumber, int year) //                                                        
{
    int n = 1;
    while (dateNumber > number_of_days_in_month(year, static_cast<Month>(n))){
        dateNumber -= number_of_days_in_month(year, static_cast<Month>(n));
        n++;
    }
    //                                                               
    return get_month_name(static_cast<Month>(n)) + " " + to_string(dateNumber);
}

void print_day(string name, int day, int year) //                       
{
    cout << name <<" falls on " << date_string(day, year) << endl;
}

/*                                                                   
                                                
                                                                   */
void show_holy_days (int year) //                               
{
    int easter_day_number = get_day_number(year, easter_month(year), easter_day(year));
    int whitsunde_day = easter_day_number + 49;
    int ascension_day = whitsunde_day - 10;
    int good_friday = easter_day_number - 2;
    int carnival_beginning = easter_day_number - 49;
    int carnival_ending = carnival_beginning + 2;

    print_day("Carnival Start", carnival_beginning, year);
    print_day("Carnival End", carnival_ending, year);
    print_day("Good Friday", good_friday, year);
    print_day("Easter", easter_day_number, year);
    print_day("Ascension Day", ascension_day, year);
    print_day("Whitsunde", whitsunde_day, year);

}

int main()
{
    int y = 1;

    while (true){ //                                          
        cout << "This program calculates the date of holy days." << endl;
        cout << "Enter a year number... (Press Enter to continue, enter 0 or a negative number to quit)" << endl;
        cin >> y;
        if (y <= 0){
            return 0;
        }
        show_holy_days(y) ;
        cout << endl;
    }
    return 0;
}

