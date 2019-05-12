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

string month_name (Month month) {
switch (month) {
case 1:return "January"; break;
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
    if ( year % 4 == 0 ) {
        if ( year % 100 != 0 || year % 400 == 0 ) {
            return true;
        }
    }
    return false;
}

int number_of_days_in_month ( int year, Month month )
{
    switch (month) {
    case January: case March: case May: case July: case August: case October: case December:
        return 31;
        break;
    case 2:
        if ( is_leap_year(year)) {
            return 29;
        } else {
            return 28;
        }
        break;
    default:
        return 30;
    }
}

/*                                                                   
                                                
                                                                    */

Month move_month_forward(Month month, int ammount_of_months) {
int last_month_number = month + ammount_of_months;
return static_cast<Month>(last_month_number);
}

void print_carnival_date(int year) {
    int days = 7 * 7;
    days = days - easter_day(year);
    Month current_month = move_month_forward(easter_month(year), -1);
    while (number_of_days_in_month(year, current_month) <= days ){
        days = days - number_of_days_in_month(year, current_month);
        current_month = move_month_forward(current_month, -1);
    }
    days = number_of_days_in_month(year, current_month) - days;
    if ( days == 0 ){
        current_month = move_month_forward(current_month, -1);
        days = number_of_days_in_month(year, current_month);
    }
    int end_carnival_day = days + 2;
    Month end_carnival_month = current_month;
    if (end_carnival_day > number_of_days_in_month(year,current_month) ){
            end_carnival_day = end_carnival_day - number_of_days_in_month(year, current_month);
        end_carnival_month = move_month_forward(current_month, 1);
    }
    cout << "Carnival will be from " << month_name(current_month) << " " << days << " until " << month_name(end_carnival_month) << " " << end_carnival_day << endl;
}

void print_good_friday_date(int year) {
    int day = easter_day(year) - 2;
    Month month = easter_month(year);
    if (day < 1) {
        month = move_month_forward(month, -1);
        day = number_of_days_in_month(year, month) + day;
    }
    cout << "Good friday will be on " << month_name(month) << " " << day << endl;
}

void print_whitsuntide_date(int year) {
    int days = 49;
    Month current_month = easter_month(year);
    days = days - (number_of_days_in_month(year,current_month) - easter_day(year));
    current_month = move_month_forward(current_month, 1);
    while (number_of_days_in_month(year,current_month) <= days) {
        days = days - ( number_of_days_in_month(year,current_month));
        current_month = move_month_forward(current_month, 1);
    }
    if ( days == 0) {
        current_month = move_month_forward(current_month, -1);
        days = number_of_days_in_month(year,current_month);
    }
    cout << "Whitsuntide will be on " << month_name(current_month) << " " << days << endl;
}

void print_ascension_day_date(int year) {
    int days = 39;
    Month current_month = easter_month(year);
    days = days - (number_of_days_in_month(year,current_month) - easter_day(year));
    current_month = move_month_forward(current_month, 1);
    while (number_of_days_in_month(year,current_month) <= days) {
        days = days - ( number_of_days_in_month(year,current_month));
        current_month = move_month_forward(current_month, 1);
    }
    if ( days == 0) {
        current_month = move_month_forward(current_month, -1);
        days = number_of_days_in_month(year,current_month);
    }
    cout << "Ascension day will be on " << month_name(current_month) << " " << days << endl;
}

void show_holy_days (int year)
{
    cout << "This year:" << endl;
    cout << "Easter will be on " << month_name(easter_month(year)) << " " << easter_day(year) << endl;
    print_carnival_date(year);
    print_good_friday_date(year);
    print_whitsuntide_date(year);
    print_ascension_day_date(year);
}

int main()
{
    while ( true ) {
        cout << "Year:";
        int year;
        cin >> year;
        show_holy_days( year ) ;
    }
    return 0;
}

