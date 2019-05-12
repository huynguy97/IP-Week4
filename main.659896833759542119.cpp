//                                     
//                                      

#include <iostream>
#include <cmath>

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
    if(year%4!=0 || (year%100==0 && year%400!=0))
        return false;

    return true;
}

int number_of_days_in_month ( int year, Month month )
{
    switch(month)
    {
        case January:
        case March:
        case May:
        case July:
        case August:
        case October:
        case December: return 31;
        case April:
        case June:
        case September:
        case November: return 30;
        case February:
            {
                if(is_leap_year(year))
                    return 29;
                return 28;
            }

    }
}

/*                                                                   
                                                
                                                                   */
//                                                                                    
//                           

void distance_before(int year, int month, int day, int distance)
{
    //                                                              
    //                                                        
    //                                                      
    int number_of_days;
    Month m;

    //                                                                        
    //                                                                                             
    //                                                                                          
    //                                                                                                          
    //                                                       
    if(distance==2&&day>2)
        {
            cout<<"In year "<<year<<" Ascension Day falls on ";
            number_of_days=day-2;
            distance=0;
        }
    else
        distance=distance-(day-1);

    //                                                                    
    while(distance>0)
    {
        month--;
        m=static_cast<Month>(month);
        number_of_days = number_of_days_in_month(year, m);
        if(distance<number_of_days)
            {
                number_of_days=number_of_days - distance + 1;
                distance=0;
            }
        else
            distance=distance-number_of_days;
    }
    cout<<month<<" "<<number_of_days<<endl;
}

//                                                                                       
//                  
void distance_after(int year, int month, int day, int distance)
{
    int number_of_days;
    Month m;

    m=static_cast<Month>(month);
    number_of_days=number_of_days_in_month(year, m);
    distance=distance+(number_of_days-day);

    while(distance<0)
    {
        month++;
        m=static_cast<Month>(month);
        number_of_days = number_of_days_in_month(year, m);

        if(abs(distance)<number_of_days)
            {
                number_of_days=abs(distance);
                distance=0;
            }
        else
            distance=distance+number_of_days;
    }

    cout<<month<<" "<<number_of_days<<endl;
}

void carnival(int year, int month, int day)
{
    int distance=49;

    cout<<"In year "<<year<<" Carnival falls on ";
    distance_before(year,month,day,distance);
}

void good_friday(int year, int month, int day)
{
    int distance = 2;

    cout<<"In year "<<year<<" Good Friday falls on ";
    distance_before(year,month,day,distance);
}

void ascension_day(int year, int month, int day)
{
    int distance=-39;

    cout<<"In year "<<year<<" Ascension Day falls on ";
    distance_after(year,month,day,distance);
}

void whitsuntide(int year, int month, int day)
{
    int distance=-49;

    cout<<"In year "<<year<<" Whitsuntide falls on ";
    distance_after(year,month,day,distance);
}

//                                                                       
//                                                 
void show_holy_days ()
{
    int year, month, day;
    cout<<"Please insert a year: "; cin>>year;
    cout<<"The format of the date is mm/dd, where both the day and the month are integers."<<endl;
    month=easter_month(year);
    day=easter_day(year);
    cout<<"In year "<<year<<" Easter falls on "<<month<<" "<<day<<endl;
    carnival(year, month, day);
    good_friday(year, month, day);
    ascension_day(year, month, day);
    whitsuntide(year, month, day);
}

int main()
{
    show_holy_days() ;
    return 0;
}

