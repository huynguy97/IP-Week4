#include <iostream>
//                      
//                            
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
    if(year%4==0 && year%100!=0) //                        
    {
        return true;
    }
    else if (year%4==0 && year%100==0 && year%400==0)
    {
        return true;
    }
    return false;

}

int number_of_days_in_month ( int year, Month month )
{
    switch(month)

    {

    case January : return 31;

    case February: {if(is_leap_year(year)) return 29;
                    else return 28;}

    case March : return 31;

    case April : return 30;

    case May : return 31;

    case June: return 30;

    case July: return 31;

    case August: return 31;

    case September: return 30;

    case October: return 31;

    case November: return 30;

    case December: return 31;

    }//                        
}

/*                                                                   
                                                
                                                                   */
int day (int Days, int Y, int k) //                                                                  
{
    while (Days > number_of_days_in_month(Y,static_cast<Month>(k)))
    {
        Days -=  number_of_days_in_month(Y,static_cast<Month>(k));
        k++;
    }
    return Days;

}

string month_string (int Days, int Y, int k) //                                                 
{
    while (Days > number_of_days_in_month(Y,static_cast<Month>(k)))
    {
        Days -=  number_of_days_in_month(Y,static_cast<Month>(k));
        k++;
    }

    switch (k)
    {
        case 1: return "January";

        case 2: return "February";

        case 3: return "March";

        case 4: return "April";

        case 5: return "May";

        case 6: return "June";

        case 7: return "July";

        case 8: return "August";
    }
}

void show_holy_days (int Y)
{
    int i=easter_month(Y),n=0,k=1;

    for(int j=1;j<i;j++)
        n+=number_of_days_in_month(Y,static_cast<Month>(j)); //                                                                                                       
                                                             //                  
    n+=easter_day(Y);

    //                                  
    int carnival = n-49;
    int g_fri = n-2;
    int ascen = n+39;
    int whit = n + 49;

    cout<<"Carnival: "      <<day(carnival, Y, k)   <<" "<< month_string(carnival, Y, k)    << endl;
    cout<<"Good Friday: "   <<day(g_fri, Y, k)      <<" "<< month_string(g_fri, Y, k)       << endl;
    cout<<"Easter: "        <<easter_day(Y)         <<" "<< month_string(n, Y, k)           << endl;
    cout<<"Ascension day: " <<day(ascen, Y, k)      <<" "<< month_string(ascen, Y, k)       << endl;
    cout<<"Whitsuntide: "   <<day(whit, Y, k)       <<" "<< month_string(whit, Y, k)        << endl;

}

int main()
{
    int year1;
    int year2;
    int year3;
    int month;

    cout<< "Type a year to find out if it's a leap year" << endl;
    cin >> year1;

    if(is_leap_year(year1)) cout<<year1<<" is a leap year."<<endl;
    else cout<<year1<<" is not a leap year."<<endl;

    cout<< "Type a year and a month to find out how many days are in that month (yyyy mm)" << endl;
    cin >> year2;
    cin >> month;

    cout << number_of_days_in_month(year2,static_cast<Month>(month)) << endl;

    cout << "Type the year you want to know the holy days dates of." << endl;
    cin >> year3;
    cout << "The holy dates are:"<<endl;
    show_holy_days(year3) ;

    return 0;
}

