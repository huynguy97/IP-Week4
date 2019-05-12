#include <iostream>

using namespace std;

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
    if(year %100 != 0 && year %400 == 0)
        return true;
    else  if(year %4 == 0)
        return true;
    else
        return false;
}

int number_of_days_in_month ( int year, Month month )
{
    if(month == January || month == March || month == May || month == July || month == August || month == October || month == December)
        return 31;
    else if(month == April || month == June || month == September || month == November)
        return 30;
    else if(month == February && is_leap_year(year))
        return 29;
    else if(month == February && is_leap_year(year) == false)
        return 28;
}

/*                                                                   
                                                
                                                                   */
void show_holy_days ()
{
    Month month;
    int year;
    int carnavalbegin;
    int carnavalend;
    int carnavalmonth;
    int goodfriday;
    int goodfridaymonth;
    int whitsuntide;
    int whitsuntidemonth;
    int ascensionday;
    int ascensiondaymonth;
    string arr[] = {"January", "February", "March", "April", "May", "June", "July", "September", "October", "November", "December"};
    string input;

    cout << "Give a year (positive): ";
    cin >> year;

    cout << "\nEaster is on: " << arr[easter_month(year) - 1] << " " << easter_day(year) << " " << year << endl;

    carnavalbegin = (easter_base(year) - 49) % 31 + 1;
    carnavalend = (easter_base(year) - 47) % 31 + 1;
    carnavalmonth = easter_base(year) - 2;

    month = static_cast <Month> (carnavalmonth / 31);

    cout << "Carnival is from: " << arr[month - 1] << " " << carnavalbegin << " " << year << " until: " << arr[month - 1] << " " << carnavalend << " " << year << endl;

    goodfriday = (easter_base(year) - 2) % 31 + 1;
    goodfridaymonth = easter_base(year) - 2;

    month = static_cast <Month> (goodfridaymonth / 31);

    cout << "Good Friday is at: " << arr[month - 1] << " " << goodfriday << " " << year << endl;

    ascensionday = (easter_base(year) + 40) % 31 + 1;
    ascensiondaymonth = easter_base(year) + 40;

    month = static_cast <Month> (ascensiondaymonth / 31);

    cout << "Ascension Day is at: " << arr[month - 1] << " " << ascensionday << " " << year << endl;

    whitsuntide = (easter_base(year) + 50) % 31 + 1;
    whitsuntidemonth = easter_base(year) + 50;

    month = static_cast <Month> (whitsuntidemonth / 31);

    cout << "Whitsuntide is at: " << arr[month - 1] << " " << whitsuntide << " " << year << endl;
    cout << "\nDo you want to see the data from another year? (y/n)? ";
    cin >> input;

    if(input == "y")
        show_holy_days();
}

int main()
{
    show_holy_days() ;
    return 0;
}

