#include <iostream>

using namespace std;

enum Month {January=1,February,March,April,May,June,July,August,September,October,November,December} ;
int year;
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
    if(year%4==0 && (year%100!=0 || year%400==0)) //                       
        return true;
    else
        return false;
}

int number_of_days_in_month ( int year, Month month )//                                                      
{
    if (month==1 || month==3 ||month==5 ||month==7 ||month==8 ||month==10 ||month==12)
        return 31;
    else if (month==2)
    {
        if(is_leap_year(year))                       //             
            return 29;
        else
            return 28;
    }
    else if (month==4 ||month==6 ||month==9 ||month==11)
        return 30;  //                                                                                                                         
}

/*                                                                   
                                                
                                                                   */
/*                         
                                                                                                                                                                                                                                                               
                                                                                                                                                                                   
                                                                                                                                                                                               
                                                                              
                                                      
                       
                          
                                                   
                       
                       
                                                   
                       
                       
                                                 
                       
                     
                                                  
                       
                      
                                                  
                       
                      
                                                    
                       
                        
                                                       
                       
                           
                                                     
                       
                         
                                                      
                       
                          
                                                      
                       
                          
  */

int noleap_days_in_month(int monthindex)
{
    if (monthindex==1 || monthindex==3 ||monthindex==5 ||monthindex==7 ||monthindex==8 ||monthindex==10 ||monthindex==12)
        return 31;
    else if (monthindex==2)
            return 28;
    else if (monthindex==4 ||monthindex==6 ||monthindex==9 ||monthindex==11)
        return 30;
}
string name_of_month(int day, int year)
{
    int months_past=1;  //                                          
    int days_past= noleap_days_in_month(months_past);//                                                                                                        
    if (day >= 60) //                                                                                         
    {
        if (is_leap_year(year))
            days_past++;
    }
    while (day>days_past)  //                                            
    {
        months_past++;
        days_past+=noleap_days_in_month(months_past);
    }
    //                                                                                                                                      
    if (months_past==1)
        return "January";
    if (months_past==2)
        return "February";
    if (months_past==3)
        return "March";
    if (months_past==4)
        return "April";
    if (months_past==5)
        return "May";
    if (months_past==6)
        return "June";
    if (months_past==7)
        return "July";
    if (months_past==8)
        return "August";
    if (months_past==9)
        return "September";
    if (months_past==10)
        return "October";
    if (months_past==11)
        return "November";
    if (months_past==12)
        return "December";
}
int day_in_month(int day,int year)
{
    int day_date;//                                                               
    int months_past=1;
    int days_past= noleap_days_in_month(months_past);//                                    
    if (day>=60)//                             
    {
        if (is_leap_year(year))
            days_past+=1; //                                            
    }
    while (day>days_past)
    {
        months_past++;
        days_past+=noleap_days_in_month(months_past);
    }
    if (months_past==60)//                                                                                
    {
        if (is_leap_year(year))
            day_date=29;
    }
    else
        day_date=day+noleap_days_in_month(months_past)-days_past;//                                                                                                                                                                                                                                 
    return day_date;
}
void show_holy_days ()
{
    int year;
    cout<<"Please enter the year of which you want to know the holy days.\n";
    cin>> year;
    //                                                                                                            
    int easter=0;
    if (is_leap_year(year))
        easter+=1; //                               
    for (int count=1;count<easter_month(year);count++) //                                                         
    {
        easter+=noleap_days_in_month(count);
    }
    easter+=easter_day(year); //                                                                                  
    int carnival_start=easter-49;
    int carnival_end=carnival_start+2; //       
    int good_friday=easter-2;//                    
    int whitsuntide=easter+49;
    int ascension_day=whitsuntide-10;
    cout<<"In the year "<<year<< " Easter is on "<< day_in_month(easter,year)<<" "<< name_of_month(easter,year); //                                                
    cout<<", Good Friday on "<< day_in_month(good_friday,year)<<" "<< name_of_month(good_friday,year);
    cout<<", Whitsuntide on "<< day_in_month(whitsuntide,year)<<" "<< name_of_month(whitsuntide,year);
    cout<<", Ascension Day on "<< day_in_month(ascension_day,year)<<" "<< name_of_month(ascension_day,year);
    cout<<", and Carnival lasts from "<< day_in_month(carnival_start,year)<<" "<< name_of_month(carnival_start,year)<<" until "<< day_in_month(carnival_end,year)<<" "<< name_of_month(carnival_end,year)<<".";
}

int main()
{
    show_holy_days() ;
    return 0;
}

