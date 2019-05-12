//                     
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
    return ((year%4==0 && !year%100==0) || year%400==0);
}

int number_of_days_in_month ( int year, Month month )
{
    int x = 31 ;
    if (month%2==0 && month<7)
        x--;
    if (month==9 || month==11)
        x--;
    if (month==2)
        x=28;
    if(is_leap_year(year) && month==2)
        x++;
    return x;
}

/*                                                                   
                                                
                                                                   */
void find_day_and_month(int &day, Month &month, int year, int diff)
{
    if (diff >= 0)
        while (diff > 0)
        {
            if (number_of_days_in_month(year, month) - day <= diff)
                {
                    diff -= number_of_days_in_month(year, month) - day + 1;
                    month = static_cast<Month> (month + 1);
                    day = 1;
                }
            else
                {
                    day += diff;
                    diff = 0;
                }
        }
    else
        while (diff < 0)
        {
            if (day + diff <= 0)
            {
                month = static_cast<Month> (month - 1);
                diff += day;
                day = number_of_days_in_month(year, month);
            }
            else
            {
                day += diff;
                diff = 0;
            }
        }
}

void show_holy_days ()
{
    int y = 0;
    cout << "What year do you want to know the holy days of?\n";
    cin >> y;
    int easD = easter_day(y);
    Month easM = easter_month(y);
    int tempD = easD;
    Month tempM = easM;
    //        
    find_day_and_month(tempD, tempM, y, -47);
    cout << "Carnival ends on: " << tempD << "/" << tempM << endl;
    tempD = easD;
    tempM = easM;
    //           
    find_day_and_month(tempD, tempM, y, -2);
    cout << "Good Friday falls on: " << tempD << "/" << tempM << endl;
    tempD = easD;
    tempM = easM;
    //      
    cout << "Easter falls on: " << easD << "/" << easM << endl;
    //         
    find_day_and_month(tempD, tempM, y, 39);
    cout << "Ascension Day falls on: " << tempD << "/" << tempM << endl;
    tempD = easD;
    tempM = easM;
    //           
    find_day_and_month(tempD, tempM, y, 49);
    cout << "Whitsuntide falls on: " << tempD << "/" << tempM << endl;
}

int main()
{
    show_holy_days() ;
    return 0;
}

