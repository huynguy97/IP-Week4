#include <iostream>
/*
                            
                          
*/
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
bool is_leap_year ( int year ){
    bool is_leap = false;
    if((year % 4) == 0){
        if((year % 100)==0 && (year%400)!= 0){
            is_leap = false;
        }else{
        is_leap = true;
        }
    }
return is_leap;
}
int number_of_days_in_month ( int year, Month month )
{
    cout << "Days in month " << month << ": ";
    switch(month){
        case 1: cout << "31";break;
        case 2: if(is_leap_year(year) == true){
                    cout << "29";
                }else{
                    cout << "28";
                }break;
        case 3: cout << "31";break;
        case 4: cout << "30";break;
        case 5: cout << "31";break;
        case 6: cout << "30";break;
        case 7: cout << "31";break;
        case 8: cout << "31";break;
        case 9: cout << "30";break;
        case 10: cout << "31";break;
        case 11: cout << "30";break;
        case 12: cout << "31";break;
    }
    cout << endl;
    return 0;
}

/*                                                                   
                                                
                                                                   */
int days_of_month(int year, Month month){
    switch(month){
        case 1: return 31;break;
        case 2: if(is_leap_year(year) == true){
                    return 29;
                }else{
                    return 28;
                }break;
        case 3: return 31;break;
        case 4: return 30;break;
        case 5: return 31;break;
        case 6: return 30;break;
        case 7: return 31;break;
        case 8: return 31;break;
        case 9: return 30;break;
        case 10: return 31;break;
        case 11: return 30;break;
        case 12: return 31;break;
}
}

int day_of_easter(int year){
    int i = 1;
    int days = 0;
    for(i; i < easter_month(year); i++){
        days = days + days_of_month(year, Month(i));

    }
    days = days + easter_day(year);
    return days;
}
void day_of_holiday(int year, int feestdag){
    int i = 0;
    for(i; feestdag > days_of_month(year, Month(i)); i++){
            feestdag = feestdag - days_of_month(year, Month(i));
        }
        cout << feestdag << "\t" << i << "\n";
}

void show_holy_days (int year)
{
    int carnival = day_of_easter(year) - 49;
    int friday = day_of_easter(year) - 2;
    int ascension = day_of_easter(year) + 39;
    int whitsuntide = day_of_easter(year) + 49;
    cout << "Carnaval, Good Friday, Ascension and Whitsuntide are, in this order, on: \n";
    cout << "Day \tMonth \n";
    day_of_holiday(year, carnival);
    day_of_holiday(year, friday);
    day_of_holiday(year, ascension);
    day_of_holiday(year, whitsuntide);
}

int main()
{

    int year;
    int month;
    cout << "Enter a year: \n";
    cin >> year;
    cout << "Enter a number of a month: \n";
    cin >> month;
    number_of_days_in_month(year, Month(month));
    show_holy_days(year);
}

