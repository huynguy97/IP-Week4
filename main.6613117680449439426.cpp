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
    if(year % 4 == 0)
    {
        if(year % 100 == 0 && year % 400 != 0)
        {
            return false;
        }
        return true;
    }
    else
    {
        return false;
    }
}

int number_of_days_in_month ( int year, int month )
{
    if(is_leap_year(year))
    {
        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            return 31;
        }
        if(month == 2)
        {
            return 29;
        }
        if(month == 4 || month == 6 || month == 9 || month == 11)
        {
            return 30;
        }
    }
    if(!is_leap_year(year))
    {
        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            return 31;
        }
        if(month == 2)
        {
            return 28;
        }
        if(month == 4 || month == 6 || month == 9 || month == 11)
        {
            return 30;
        }
    }
}

/*                                                                   
                                                
                                                                   */
int year;
int month;
int whitd;
int whitm;
int febdays;
string monthname;

void int_to_mont (int month)//                     
{
    if (month == 1)
    {
        monthname = "January";
    }
    if (month == 2)
    {
        monthname = "February";
    }
    if (month == 3)
    {
        monthname = "March";
    }
    if (month == 4)
    {
        monthname = "April";
    }
    if (month == 5)
    {
        monthname = "May";
    }
    if (month == 6)
    {
        monthname = "June";
    }
    if (month == 7)
    {
        monthname = "Juli";
    }
    if (month == 8)
    {
        monthname = "Augustus";
    }
    if (month == 9)
    {
        monthname = "September";
    }
    if (month == 10)
    {
        monthname = "October";
    }
    if (month == 11)
    {
        monthname = "November";
    }
    if (month == 12)
    {
        monthname = "December";
    }
}

void whitsuntide ()
{
    whitd = easter_day(year) + 7*7;
    whitm = easter_month(year);
    if (easter_month(year) == 4)
    {
        whitd = whitd-30;
        whitm++;
        if (whitd > 31)
        {
            whitd = whitd-31;
            whitm++;
        }
    }
    else
    {
        whitd = whitd - 31;
        whitm++;
        if (whitd >30)
        {
            whitd = whitd-30;
            whitm++;
        }
    }
    month = whitm;
    int_to_mont(month);
    cout<<"Whitsuntide is on " << whitd << " " << monthname << "\n";
}

void carnival ()
{
    int card;
    int carm;
    card = easter_day(year) - 7*7;
    carm = easter_month(year);
    if (easter_month(year) == 4)
    {
        card = card + 31;
        carm--;
        if (card <= 0)
        {
            card = card + febdays;
            carm--;
        }
    }
    if (easter_month(year) == 3)
    {
        card = card + febdays;
        carm--;
        if (card <= 0)
        {
            card = card + 31;
            carm--;
        }
    }
    month = carm;
    int_to_mont(month);
    cout<<"Carnival starts on " << card << " until " << card + 2 << " " << monthname << "\n";
}

void good_friday()
{
    int g_fd;
    int g_fm;
    g_fd = easter_day(year) - 2;
    g_fm = easter_month(year);
    if (g_fd < 0)
    {
        if (g_fm == 4)
        {
            g_fd = 31 + g_fd;
            g_fm--;
        }
        else
        {
            g_fd = febdays + g_fd;
            g_fm--;
        }
    }
    month = g_fm;
    int_to_mont(month);
    cout<<"Good Friday is on " << g_fd << " " << monthname << "\n";
}

void ascension_day ()
{
    int a_dd;
    int a_dm;
    a_dd = whitd - 10;
    a_dm = whitm;
    if (a_dd < 1)
    {
        if (whitm == 3)
        {
            a_dd = 30 + a_dd;
            a_dm--;
        }
        else
        {
            a_dd = 31 + a_dd;
            a_dm--;
        }
    }
    month = a_dm;
    int_to_mont(month);
    cout<<"Ascension day is on " << a_dd << " " << monthname << "\n";

}

void show_holy_days ()
{
    month = easter_month(year);
    int_to_mont(month);
    cout<<"Easter is on " << easter_day(year) << " " << monthname << "\n";
    if (is_leap_year(year))
    {
        febdays = 29;
    }
    else
    {
        febdays = 28;
    }
    whitsuntide();
    carnival();
    good_friday();
    ascension_day();
}

int main()
{
    cout<<"Which year?";
    cin>>year;
    bool is_leap_year(year);
    show_holy_days();
    return 0;
}
/*
          
 
             
                
                           
                
                                   
                          
     
                               
     
                           
     
                                
     
                                              
                 
                                                        
                                                 
 
*/
