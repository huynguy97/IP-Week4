#include <iostream>
//                                              
//                                          

using namespace std;

bool is_leap_year ( int year );

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
Month Good_Friday_month ( int year )
{
    return static_cast<Month> ((easter_base (year)-2) / 31) ;
}

int Good_Friday_day ( int year )
{
    return ((easter_base (year)-2) % 31)+1;
}

Month Carnival_month ( int year )
{
    return static_cast<Month> ((easter_base (year)-7*7) / 31) ;
}

int Carnival_day ( int year)
{
    if (is_leap_year(year))
    {
        return ((easter_base (year)-7*7) % 31)-1;
    }
    else
    {
        if(easter_month(year) == 4 && easter_day(year) >= 20)
        {
            return ((easter_base (year)-7*7) % 31)+1;
        }
        else return ((easter_base (year)-7*7) % 31)-2;
    }
}

Month Whitsuntide_month ( int year )
{
    return static_cast<Month> ((easter_base (year)+7*7) / 31) ;
}

int Whitsuntide_day ( int year )
{
    return ((easter_base (year)+7*7) % 31) + 3;
}

Month Ascension_month ( int year )
{
    return static_cast<Month> (((easter_base (year)+7*7)-10) / 31) ;
}

int Ascension_day ( int year )
{
    return (((easter_base (year)+7*7)-10) % 31)+2;
}

/*                                                                   
                                 
                                                                   */
bool is_leap_year ( int year )
{
    if(year % 100 == 0)
    {
        if((year /100) % 4 == 0)
        {
            return true;
        }
        else return false;
    }
    else
    {
        if(year % 4 == 0)
        {
            return true;
        }
        else return false;
    }
}

int number_of_days_in_month ( int year, Month month )
{

    switch(month){
        case 1:
        cout << 31;
        break;
        case 2:
        if(is_leap_year(year))
            {
            cout << 29;
            }
        else
            cout << 28;
        break;
        case 3:
        cout << 31;
        break;
        case 4:
        cout << 30;
        break;
        case 5:
        cout << 31;
        break;
        case 6:
        cout << 30;
        break;
        case 7:
        cout << 31;
        break;
        case 8:
        cout << 31;
        break;
        case 9:
        cout << 30;
        break;
        case 10:
        cout << 31;
        break;
        case 11:
        cout << 30;
        break;
        case 12:
        cout << 31;
        break;
    }

}

/*                                                                   
                                                
                                                                   */
void show_holy_days (int year)
{
    cout << "Carnival is on " <<Carnival_month(year) << "-" << Carnival_day(year) <<endl;
    cout << "Good Friday is on " <<Good_Friday_month(year) << "-"<< Good_Friday_day(year) <<endl;
    cout << "Easter is on " <<easter_month(year) << "-" << easter_day(year)<<endl;
    cout << "Ascension is on " <<Ascension_month(year) << "-" << Ascension_day(year) <<endl;
    if (Whitsuntide_day(year) > 31)
    {
        cout << "Whitsuntide is on " <<Whitsuntide_month(year)+1 << "-" << Whitsuntide_day(year)-31 <<endl;
    }
    else cout << "Whitsuntide is on " <<Whitsuntide_month(year) << "-" << Whitsuntide_day(year) <<endl;
}

int main()
{
    int year, month;
    cout << "Please enter a year: ";
    cin >> year;
    cout << "Please enter a month to get it's days: ";
    cin >> month;
    cout << "Month has ";
    number_of_days_in_month(year,(Month)month);
    cout << " number of days." << endl;
    if (is_leap_year(year))
    {
        cout << "This year is a leap year" <<endl;
    }
    else cout << "This year is not a leap year" <<endl;
    show_holy_days(year);
    return 0;
}

