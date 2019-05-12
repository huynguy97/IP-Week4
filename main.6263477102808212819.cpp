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
    if(year % 4 == 0 && !(year % 100 == 0 && !(year % 400 == 0))){
        return true;
    }
    else {
        return false;
    }
}

int number_of_days_in_month ( int year, Month month )
{
    switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: return 31; break;

        case 4:
        case 6:
        case 9:
        case 11: return 30; break;

        case 2: if(is_leap_year(year)){
                    return 29;
                } else {
                    return 28;
                }; break;
   }
}

/*                                                                   
                                                
                                                                   */
void show_holy_days ()
{
    enum holyDay {Carnival=1, goodFriday, ascensionDay, whitsuntide};
    switch(holyDay){
        case 1: (int day = ((easter_base(year) - 49) % 31) + 1),
        int month =
        ; break;
    }
}
int main()
{
    /*
                 
                  

                                      
                            
                             

                        
                            

                                         
    */
    return 0;
}

