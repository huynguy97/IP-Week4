#include <iostream>

using namespace std;

//                                                        
//                                                  

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
string int_to_month(int x)
{
    switch(x)
    {
    case 1:
    {
        return "January";
        break;
    }
    case 2:
    {
        return "February";
        break;
    }
    case 3:
    {
        return "March";
        break;
    }
    case 4:
    {
        return "April";
        break;
    }
    case 5:
    {
        return "May";
        break;
    }
    case 6:
    {
        return "June";
        break;
    }
    case 7:
    {
        return "July";
        break;
    }
    case 8:
    {
        return "August";
        break;
    }
    case 9:
    {
        return "September";
        break;
    }
    case 10:
    {
        return "October";
        break;
    }
    case 11:
    {
        return "November";
        break;
    }
    case 12:
    {
        return "December";
        break;
    }
    default:
    {
        return "There is no month associated with that number";
        break;
    }
    }
}

/*                                                                   
                                 
                                                                   */
bool is_leap_year ( int year )
{
    if(year%4==0)                       //
    {
        //                                                                                            
        if (year%100==0&&year%400!=0)   //
            return false;
        else
            return true;
    }
    else
        return false;
}

int number_of_days_in_month ( int year, Month month ) //                                                                                            
{
    switch (month)
    {
    case January:
        return 31;
        break;
    case February:
    {
        if (is_leap_year(year))
            return 29;
        else
            return 28;
        break;
    }
    case March:
        return 31;
        break;
    case April:
        return 30;
        break;
    case May:
        return 31;
        break;
    case June:
        return 30;
        break;
    case July:
        return 31;
        break;
    case August:
        return 31;
        break;
    case September:
        return 30;
        break;
    case October:
        return 31;
        break;
    case November:
        return 30;
        break;
    case December:
        return 31;
        break;
    default:
        return 0;
        break;
    }

}

/*                                                                   
                                                
                                                                   */
void carnival_day(int year)
{
    int x=easter_month(year)-1;                                          //
    int day_sum=0;                                                       //
    while(x>0)                                                           //                                                  
    {
        //                                                                         
        day_sum+=number_of_days_in_month(year,static_cast<Month>(x));    //
        x--;                                                             //
    }                                                                    //
    day_sum+=easter_day(year)-49;
    while(day_sum>28)
    {
        day_sum-=number_of_days_in_month(year,static_cast<Month>(x));
        x++;
    }
    if(day_sum<28)   //                                                                                                                                             
        cout<<"The carnival starts on "<<int_to_month(x)<<", "<<day_sum<<" and ends on "<<int_to_month(x)<<", "<<day_sum+2<<endl;
    else if(day_sum==28)
        cout<<"The carnival starts on "<<int_to_month(x)<<", "<<day_sum<<" and ends on "<<int_to_month(x+1)<<", "<<1<<endl;
    else
        cout<<"The carnival starts on "<<int_to_month(x)<<", "<<day_sum<<" and ends on "<<int_to_month(x+1)<<", "<<2<<endl;
}

void good_friday(int year)//                                                        
{
    if(easter_day(year)>2)
        cout<<"Good Friday is on "<<int_to_month(easter_month(year))<<", "<<easter_day(year)-2<<endl;
    else if(easter_day(year)==2)
        cout<<"Good Friday is on "<<int_to_month(easter_month(year)-1)<<", "<<number_of_days_in_month(year,static_cast<Month>(easter_month(year)-1))<<endl;
    else
        cout<<"Good Friday is on "<<int_to_month(easter_month(year)-1)<<", "<<number_of_days_in_month(year,static_cast<Month>(easter_month(year)-1))-1<<endl;
}

void ascension_day(int year)   //                                                                                
{
    int x=easter_month(year)-1;
    int day_sum=0;
    while(x>0)
    {
        day_sum+=number_of_days_in_month(year,static_cast<Month>(x));
        x--;
    }
    day_sum+=easter_day(year)+39;
    while(day_sum>28)
    {
        day_sum=day_sum-number_of_days_in_month(year,static_cast<Month>(x));
        x++;
    }
    cout<<"Ascension day is on "<<int_to_month(x)<<", "<<day_sum <<endl;
}

void whitsuntide(int year)     //                                                                                
{
    int x=easter_month(year)-1;
    int day_sum=0;
    while(x>0)
    {
        day_sum+=number_of_days_in_month(year,static_cast<Month>(x));
        x--;
    }
    day_sum+=easter_day(year)+49;
    while(day_sum>28)
    {
        day_sum=day_sum-number_of_days_in_month(year,static_cast<Month>(x));
        x++;
    }
    cout<<"The Whitsuntide is on "<<int_to_month(x)<<", "<<day_sum <<endl;
}

void show_holy_days ()
{
    int year;
    cout<<"Input year: ";
    cin>>year;
    cout<<"These are the dates of the holidays in year "<<year<<":"<<endl;
    carnival_day(year);
    good_friday(year);
    cout<<"Easter is on "<<int_to_month(easter_month(year))<<", "<<easter_day(year)<<endl;
    ascension_day(year);
    whitsuntide(year);
}

int main()
{
    show_holy_days();
    return 0;
}

