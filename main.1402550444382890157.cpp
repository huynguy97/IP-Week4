#include <iostream>

using namespace std;

//                                                                                          
//                                                                                          

enum Month {January=1,February,March,April,May,June,July,August,September,October,November,December};
int year;//        
Month month;
int m;//                
int date;//       
int day;//              

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
//                                                                        
bool is_leap_year ( int year )
{
    int counter = year%4;
    if(counter == 0){
        counter = year%100;
        if(counter == 0){
            counter = year%400;
            if(counter == 0){
                return true;}
            return false;
        }
        return true;
    }
    return false;
}

//                                                                                                                       
int number_of_days_in_month ( int year, Month month )
{
    if(is_leap_year(year)==true){
        switch(month){
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                return 31;
            case 2:
                return 29;
            case 4:
            case 6:
            case 9:
            case 11:
                return 30;
        }
    }
    else
        switch(month)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                return 31;
            case 2:
                return 28;
            case 4:
            case 6:
            case 9:
            case 11:
                return 30;
        }
}

//                                                         
void get_year ()
{
    cout<<"Please enter the desired year: ";
    cin>>year;
}

/*                                                                   
                                                
                                                                   */
//                                                                                                                                      
void convert_easter_date_to_day(int date, Month month)
{
    m = easter_month(year);
    day = easter_day(year);
   while(m>1){
        m--;
        day = day + number_of_days_in_month(year,static_cast<Month>(m));
       }
}

//                                                                                                   
void convert_day_to_date(int day, Month month)
{
    m = 0;
    while(day>0){
        m++;
        day = day - number_of_days_in_month(year,static_cast<Month>(m));}
    if(day==0){
        date = number_of_days_in_month(year,static_cast<Month>(m));}
    else if(day<0){
        date = number_of_days_in_month(year,static_cast<Month>(m))+day;}
}

//                                                                                                                                       
//                                                                      
int holiday_day(int year, Month month, int days)
{
    convert_easter_date_to_day(easter_day(year),easter_month(year));
    day = day + days;
    convert_day_to_date(day,static_cast<Month>(0));
    return date;
}

//                                                                                                                                                       
//                                                                        
int holiday_month(int year, Month month, int days)
{
    convert_easter_date_to_day(easter_day(year),easter_month(year));
    day = day + days;
    convert_day_to_date(day,static_cast<Month>(0));
    return m;
}

//                                                                                      
void show_holy_days ()
{
    cout<<"\n"<<"Carnival: "<<holiday_day(year,easter_month(year),-49)<<"-"<<holiday_month(year,easter_month(year),-49)<<"-"<<year<<"\n";
    cout<<"Good Friday: "<<holiday_day(year,easter_month(year),-2)<<"-"<<holiday_month(year,easter_month(year),-2)<<"-"<<year<<"\n";
    cout<<"Easter : "<<easter_day(year)<<"-"<<easter_month(year)<<"-"<<year<<"\n";
    cout<<"Ascension day: "<<holiday_day(year,easter_month(year),39)<<"-"<<holiday_month(year,easter_month(year),39)<<"-"<<year<<"\n";
    cout<<"Whitsuntide: "<<holiday_day(year,easter_month(year),49)<<"-"<<holiday_month(year,easter_month(year),49)<<"-"<<year<<"\n";
}

//                                                                                                                                                                            
int main()
{
    get_year();
    show_holy_days();
    return 0;
}

