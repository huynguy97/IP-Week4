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

//                             

/*                                                                   
                                 
                                                                   */
using namespace std;

bool is_leap_year ( int year )
{
    bool status = false;
    if (year % 4 == 0 && year % 100 != 0)
        status = true;
    else if (year % 400 == 0)
        status = true;
    return status;
}
int main()
{
    int YEAR;
    cout << "Enter a year: ";
    cin >> YEAR;
    if (is_leap_year(YEAR) == 1)
        status = 1;
    else
        status = 0;
    return status;
}
 //                        

int number_of_days_in_month ()
{
    int main ()
    {
        int year;
        int month;
        cout << "Enter a year: ";
        cin >> year;
        cout << "Enter a month: ";
        cin >> month;

        if (month == 4 || month == 6 || month == 9 || month == 11)
            cout << "30 days" << endl;
        else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            cout << "31 days" << endl;
        else if (month == 2 && year % 4 == 0 && year % 100 != 0)
            cout << "29 days" << endl;
        else if (month == 2 && year % 400 == 0)
            cout << "29 days" << endl;
        else if ( month == 2 && year % 4 != 0)
            cout << "28 days" << endl;
        else
            cout << "wrong month number" << endl;
        return 0;
    }
    //                        
}

/*                                                                   
                                                
                                                                   */
void show_holy_days ()
{
    cout << "Enter a year: " << endl;
    int year;
    cin >> year;

    easter_base();
    easter_day();
    easter_month();

    int carnival, good_friday, ascension_day, whitsuntide;

        carnival = easter_day() - 49;
        good_friday = easter_day() - 2;
        ascension_day = easter_day() + 39;
        whitsuntide = easter_day() + 49;
    cout <<"Carnival "<<carnival<<" Good Friday "<<good_friday<<" Ascension day "<<ascension_day<<" Whitsuntide "<<whitsuntide<< endl;
    return 0;

    //                        
}

int main()
{
    show_holy_days() ;
    return 0;
}

