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

//                      
//                                   

/*                                                                   
                                 
                                                                   */

//                                                                                                                          
bool is_leap_year ( int year )
{
    if (year % 100 == 0)
        return (year % 400) == 0 ;
    else
        return (year % 4) == 0 ;
}

//                                                                        
int number_of_days_in_month ( int year, Month month )
{
    if (is_leap_year(year) && month == 2) //                                                                    
        return 29 ;
    switch (month) //                                                                          
    {
        case January: case March: case May: case July: case August: case October: case December:
            return 31 ;
        case February:
            return 28 ;
        case April: case June: case September: case November:
            return 30 ;
    }
}

/*                                                                   
                                                
                                                                   */
//                                                                                                  
int ask_year ()
{
    int year ;
    cout << "Please enter the year of which you want to know the date of the holidays: \n" ;
    cin >> year ;
    return year ;
}

//                                                                                                                

int good_friday_month (int Y) //                                    
{
    if (easter_day(Y)-2 > 0) //                                           
        return easter_month(Y) ;
    else //                                                          
        return easter_month(Y)-1 ;
}

int good_friday_day (int Y)
{
    if (easter_day(Y)-2 > 0) //                                           
        return easter_day(Y)-2 ;
    if (easter_day(Y)-2 == 0) //                                                                            
        return number_of_days_in_month(Y, static_cast<Month> (easter_month(Y)-1) ) ;
    else //                                                                                      
        return number_of_days_in_month(Y, static_cast<Month> (easter_month(Y)-1) )-1 ;

}

int whitsuntide_month (int Y)
{
    int a = easter_day(Y) + 49 ; //                                                  
    int counter = 0;
    while (a > 31)
    {
        a -= number_of_days_in_month(Y, static_cast<Month> (easter_month(Y)+counter)) ; //                                          
        //                                                               
        counter++ ; //                                                                                                            
    }
    if (a <= number_of_days_in_month(Y, static_cast<Month> (easter_month(Y)+counter))) //                                                            
        //                                                                              
        return easter_month(Y)+counter ;
    else //                                                                                                                                                        
        //                                                                                                                                              
        return easter_month(Y)+counter+1 ;
}

int whitsuntide_day (int Y) //                                                                                                           
{
    int a = easter_day(Y) + 49 ;
    int counter = 0;
    while (a > 31)
    {
        a -= number_of_days_in_month(Y, static_cast<Month> (easter_month(Y)+counter)) ;
        counter++ ;
    }
    if (a <= number_of_days_in_month(Y, static_cast<Month> (easter_month(Y)+counter)))
        return a ;
    else
        return 1 ;
}

int carnival_month (int Y) //                                                                                                          
//                                                     
{
    if ((49-easter_day(Y)) < number_of_days_in_month(Y, static_cast<Month> (easter_month(Y)-1)) ) //                                                 
        //                                                                                    
        return easter_month(Y)-1 ;
    else //                                                     
        easter_month(Y)-2 ;

}

int carnival_day (int Y)
{
    int b = easter_day(Y) - 49 ;
    if (-b < number_of_days_in_month(Y, static_cast<Month> (easter_month(Y)-1)) ) //                                                                            
        //                                                                                                                                                          
        //                                     
        return number_of_days_in_month(Y, static_cast<Month> (easter_month(Y)-1)) + b ;
    else //                                                                                                                                              
        //                                                                                                                                                        
        return number_of_days_in_month(Y, static_cast<Month> (easter_month(Y)-2)) + number_of_days_in_month(Y, static_cast<Month> (easter_month(Y)-1)) + b;
}

int ascension_month (int Y) //                                            
{
    if (whitsuntide_day(Y)-10 > 0) //                                      
        return whitsuntide_month(Y) ;
    else //                                    
        return whitsuntide_month(Y)-1 ;
}

int ascension_day (int Y)
{
    int c = whitsuntide_day(Y)-10 ;
    if ( c > 0) //                                      
        return c ;
    else //                                                                                                                            
        return number_of_days_in_month(Y, static_cast<Month> (whitsuntide_month(Y)-1)) + c ;
}

//                                                                                                                                    
void show_holy_days ()
{
    int Y = ask_year() ;
    cout << "Holiday" "\t" "\t" "Month" "\t" "\t" "Day" << endl ;
    cout << "Carnival \t" << carnival_month(Y) << "\t" "\t" << carnival_day(Y) << endl ;
    if (carnival_day(Y)+2 <= number_of_days_in_month(Y, static_cast<Month> (carnival_month(Y)))) //                                                                
        cout << "End Carnival \t" << carnival_month(Y) << "\t" "\t" << carnival_day(Y)+2 << endl ;
    else //                                                       
    {
        int end_carnival_day = carnival_day(Y)+2-number_of_days_in_month(Y, static_cast<Month> (carnival_month(Y))) ; //                                                         
        //                                                                
        cout << "End Carnival \t" << carnival_month(Y)+1 << "\t" "\t" << end_carnival_day << endl ;
    }
    cout << "Good Friday \t" << good_friday_month(Y) << "\t" "\t" << good_friday_day(Y) << endl ;
    cout << "Easter \t" "\t" << easter_month(Y) << "\t" "\t" << easter_day(Y) << endl ;
    cout << "Ascension Day \t" << ascension_month(Y) << "\t" "\t" << ascension_day(Y) << endl ;
    cout << "Whitsuntide \t" << whitsuntide_month(Y) << "\t" "\t" << whitsuntide_day(Y) << endl ;

}

int main()
{
    show_holy_days() ;
    return 0;
}

