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
    //                        
    if(year%4!=0)return false;
    else if(year%100==0 && year%400!=0)return false;
    return true;
}

int number_of_days_in_month ( int year, Month month )
{
    //                        
    switch(month){
        case 2:{
            if(is_leap_year(year))return 29;
            else return 28;
                }
        case 4:
        case 6:
        case 9:
        case 11: return 30;
        default: return 31;
    }
}

/*                                                                   
                                                
                                                                   */
void show_holy_days (int year)
{
    //                        
    int eDay = easter_day(year);
    Month eMonth = easter_month(year);
    cout << "\nThese are all the Christian holidays(month, day) for the year of " << year << ":\n";
    cout <<"Easter: (" << static_cast<Month>(eMonth)<< ", " << eDay << ")\n";

    int eDayOfTheYear = number_of_days_in_month(year, January)+number_of_days_in_month(year, February)+eDay;
    if(eMonth==4)eDayOfTheYear+=number_of_days_in_month(year, March);

    //          
    int x = eDayOfTheYear;
    x+= -49-number_of_days_in_month(year,January);
    if(x>number_of_days_in_month(year, February)){
        x-=number_of_days_in_month(year, February);
        cout << "Carnival: (3, " << x << ")\n";
    }else{
        cout << "Carnival: (2, "<< x << ")\n";
    }

    //            
    if(eDay-2>0)cout<<"Good friday: (" << eMonth << ", " << eDay-2 << ")\n";
    if(eDay==1) cout<<"Good friday: (" << eMonth-1<<", "<< 30<<")\n";
    if(eDay==2) cout<<"Good friday: (" << eMonth-1<<", "<< 29<<")\n";

    //            
    x = eDay;
    int y = eMonth;
    for(int i=1;i<=49;i++){
        x++;
        if(x>number_of_days_in_month(year,static_cast<Month>(y))){
            x=1;
            y++;
        }
    }
    cout << "Whitsuntide: ("<<y<<", "<<x<<")\n";

    //              
    for(int i=10;i>0;i--){
        x--;
        if(x<1){
            y--;
            x=number_of_days_in_month(year,static_cast<Month>(y));
        }
    }
    cout << "Ascension Day: ("<<y<<", "<<x<<")\n";
}

int main()
{
    int year;
    cout << "Enter a year: ";
    cin >> year;
    show_holy_days(year) ;
    return 0;
}

