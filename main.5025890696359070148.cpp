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
bool is_leap_year ( int year )
{
    if(year % 4 == 0)
    {
        if(year % 100 == 0 && year % 400 != 0)
        {
            return false;
        }
        return true;
    }
    return false;
}

int number_of_days_in_month ( int year, Month month )
{
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
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        if(is_leap_year(year)==true)
        {
            return 29;
        }
        return 28;
    }
}

/*                                                                   
                                                
                                                                   */

//                        
int year_input()
{
    int y;
    cout << "Enter a year to show the dates of it's holy days: " << endl;
    cin >> y;
    return y;
}

//                                     
int easter_in_year(int year)
{
    int sum_days_in_months = 0;
    int m = easter_month(year);

    for(int i=1; i<m; i++)
    {
        sum_days_in_months += number_of_days_in_month(year, Month(i));
    }

    int day_in_year = sum_days_in_months + easter_day(year);

    return day_in_year;

}

//                                                           
int carnaval_start_in_year(int easter_day_in_year){
         return easter_day_in_year - 49;
}

//                                                         
int carnaval_end_in_year(int easter_day_in_year){
    return easter_day_in_year - 47;
}

//                                                     
int good_friday_in_year(int easter_day_in_year){
    return easter_day_in_year - 2;
}

//                                                   
int ascension_day_in_year(int easter_day_in_year){
    return easter_day_in_year + 39;
}

//                                                 
int whitsuntide_in_year(int easter_day_in_year){
    return easter_day_in_year + 49;
}

//                                                        
int day_year_to_month(int day_in_year, int year){

    int days_left = day_in_year;
    int m = 1;
    while(days_left > number_of_days_in_month(year, Month(m))){

        days_left -= number_of_days_in_month(year, Month(m));
        m++;
    }
    return m;
}

//                                                      
int day_year_to_day_month(int day_in_year, int year){

    int days_left = day_in_year;
    int m = 1;
    while(days_left > number_of_days_in_month(year, Month(m))){

        days_left -= number_of_days_in_month(year, Month(m));
        m++;
    }
    return days_left;
}

//                         
//                   
void print_holy_days()
{
    int y = year_input();
    int e = easter_in_year(y);

    int cs = carnaval_start_in_year(e);
    int ce = carnaval_end_in_year(e);
    int gf = good_friday_in_year(e);
    int ad = ascension_day_in_year(e);
    int w = whitsuntide_in_year(e);

    cout << "These are the holy days for year: " << y << endl;
    cout << "      ID            Day       Month" << endl;
    cout << "Easter              " << easter_day(y) << "\t        " << easter_month(y) << endl;
    cout << "Carnaval (start)    " << day_year_to_day_month(cs, y) << "\t        " << day_year_to_month(cs, y) << endl;
    cout << "Carnaval (end)      " << day_year_to_day_month(ce, y) << "\t        " << day_year_to_month(ce, y) << endl;
    cout << "Good Friday         " << day_year_to_day_month(gf, y) << "\t        " << day_year_to_month(gf, y) << endl;
    cout << "Ascension Day       " << day_year_to_day_month(ad, y) << "\t        " << day_year_to_month(ad, y) << endl;
    cout << "Whitsuntide         " << day_year_to_day_month(w, y) << "\t        " << day_year_to_month(w, y) << endl;

}
void show_holy_days ()
{

    print_holy_days();

}

int main()
{
    show_holy_days() ;
    return 0;
}

