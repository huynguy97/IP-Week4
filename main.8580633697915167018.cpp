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
Month easter_month ( int year, int offset )//                                        
{
    return static_cast<Month> (easter_base (year) / 31 + offset) ;
}

bool is_leap_year ( int year )
{
   if((year % 4) == 0 && (year % 400) == 0){
        return true;
   } else {
        return false;
   }
}

int number_of_days_in_month ( int year, Month month )
{
    switch(month){
        case 1: return 31;
        case 2: if(is_leap_year(year)){
                    return 29;
                } else return 28;
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
    }
}

/*                                                                   
                                                
                                                                   */
int input_user(){
    int year = -1;
    cout << "Input year (>0) to find all holidays. If it's not a number, ye're fokked." << endl;
    cin >> year;
    return year;
}
//                                           
bool verifyInput(int year){
    if(year - year != 0 && year < 0){
        cout << "Now ye fokked up. Enter a proper year(after 0) or be stuck in this loop forever." << endl;
        return false;
    } else return true;
}

//                                                                               
int reachEndofMonth(int day, int year){
    int daysmonth = number_of_days_in_month(year, easter_month(year));
    return daysmonth - day;
}

//                                                                                         
Month carnevaleMonth(int year){
    if(easter_day(year) > 21){
        return easter_month(year, -1);
    } else return easter_month(year, -2);
}

void show_holy_days (int year)
{

    cout << "Carnival is on Month "  << carnevaleMonth(year) << " and Day: " << (49 - reachEndofMonth(easter_day(year), year)) % (number_of_days_in_month(year, carnevaleMonth(year)))<< endl;
    cout << "Easter is on Month " << easter_month(year) << " and Day: " << easter_day(year) << endl;
    cout << "Good Friday is on " << easter_month(year) << " and Day: " << easter_day(year) - 2 << endl;
    cout << "Ascension Day is on " << easter_month(year, 1) << " and Day: " << (39 - reachEndofMonth(easter_day(year), year))  % (number_of_days_in_month(year, easter_month(year, 1))) << endl;
    cout << "Whitsuntide is on " << easter_month(year, 1) << " and Day: " << (49 - reachEndofMonth(easter_day(year), year)) % (number_of_days_in_month(year, easter_month(year, 1))) << endl;
}

int main()
{   int year = input_user();
    while(!verifyInput(year)){
        year = input_user();
    }
    show_holy_days(year) ;
    return 0;
}

