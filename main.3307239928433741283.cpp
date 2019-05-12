
//                            
//                            

#include <iostream>
#include <string>

using namespace std;

enum Month {January=1,February,March,April,May,June,July,August,September,October,November,December};

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
    if(year % 4 == 0 && !(year % 100 == 0))
        return true;
    else if(year % 400 == 0)
        return true;
    else
        return false;
}

int number_of_days_in_month ( int year, Month month )
{
    switch(month){
        case 1: return 31;
        case 2:
            if(is_leap_year(year))
                return 29;
            else
                return 28;
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
        default: cout << "This is not a valid month.\n";
    }
}

/*                                                                   
                                                
                                                                   */

string relative_day(int difference, int relDay, int relMonth, int relYear)
{
    bool positive;
    if(difference > 0)
        positive = true;
    else
        positive = false;

    while(relDay + difference < 1 || relDay + difference > number_of_days_in_month(relYear, (Month)relMonth)){
        if(positive){
            relDay = relDay + difference - number_of_days_in_month(relYear, (Month)relMonth);
            relMonth++;
        }else{
            relMonth--;
            relDay = relDay + difference + number_of_days_in_month(relYear, (Month)relMonth);
        }
        difference = 0;
    }

    relDay = relDay + difference;

    string date = to_string(relDay) + "-" + to_string(relMonth) + "-" + to_string(relYear);
    return date;
}

void show_holy_days ()
{
    cout << "Enter a year: ";
    int year;
    cin >> year;

    int easterDay = easter_day(year);
    int easterMonth = easter_month(year);

    cout << "Easter is on: " << easterDay << "-" << easterMonth << "-" << year << endl;
    cout << "Carnival is on: " << relative_day(-49, easterDay, easterMonth, year)
         << " till " << relative_day(-47, easterDay, easterMonth, year) << endl;
    cout << "Good Friday is on: " << relative_day(-2, easterDay, easterMonth, year) << endl;
    cout << "Ascension Day is on: " << relative_day(39, easterDay, easterMonth, year) << endl;
    cout << "Whitsuntide is on: " << relative_day(49, easterDay, easterMonth, year) << endl;
}

int main()
{
    show_holy_days() ;
    return 0;
}

