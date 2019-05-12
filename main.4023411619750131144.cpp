#include <iostream>
using namespace std;
//                        
//                         
enum Month {January=1,February,March,April,May,June,July,August,September,October,November,December} ;

/*                                                                          
                                                                            
                                                           
*/
int easter_base(int year){
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
int easter_day(int year){
    return (easter_base(year) % 31) + 1 ;
}

/*                                                                                   
*/
Month easter_month(int year){
    return static_cast<Month>(easter_base(year) / 31) ;
}

/*                                                                   
                                 
                                                                   */
bool is_leap_year(int year){
   return(year%400==0||(year%4==0&&year%100!=0));
}

int number_of_days_in_month(int year, Month month){
    switch(month){
        //                                             
        case April:
        case June:
        case September:
        case November:return(30);
        case February:return(is_leap_year(year)?29:28);
        //                                                 
        default:return(31);
    }
}

/*                                                                   
                                                
                                                                   */

Month daynum_to_month(int year, int daynum){
    int curr_month=1;
    while(daynum>number_of_days_in_month(year,static_cast<Month>(curr_month))){
        curr_month++;
        daynum-=number_of_days_in_month(year,static_cast<Month>(curr_month));
    }
    return static_cast<Month>(curr_month);
}

int daynum_to_day(int year, int daynum){
    int curr_month=1;
    while(daynum>number_of_days_in_month(year,static_cast<Month>(curr_month))){
        daynum-=number_of_days_in_month(year,static_cast<Month>(curr_month));
        curr_month++;
    }
    return daynum;
}

int date_to_daynum(int year, Month month, int day){
    int daynum=day;
    for(int i=1;i<month;i++){
        daynum+=number_of_days_in_month(year, static_cast<Month>(i));
    }
    return daynum;
}
string month_to_name(Month month){
    switch(month){
    case January:return"January";
    case February:return"February";
    case March:return"March";
    case April:return"April";
    case May:return"May";
    case June:return"June";
    case July:return"July";
    case August:return"August";
    case September:return"September";
    case October:return"October";
    case November:return"November";
    case December:return"December";
    }
    return "";
}
void print_day(string phrase,int year, int daynum){
    cout << phrase+" on "+month_to_name(daynum_to_month(year, daynum));
    cout << " " << daynum_to_day(year,daynum)<< " " << year <<"." << endl;
}
void print_holy_days(int year,int easter_num){
    print_day("Carnival starts",year,easter_num-49);
    print_day("Carnival ends",year,easter_num-47);
    print_day("Good Friday is",year,easter_num-2);
    print_day("Easter is",year,easter_num);
    print_day("Ascension day is",year,easter_num+39);
    //                                                                                                                     
    print_day("Whitsuntide starts",year,easter_num+50);
    print_day("Whitsuntide ends",year,easter_num+56);
    cout<<endl;
}
void show_holy_days(){
    while(true){
        int year=0;
        do{
            cout << "For what year should I calculate the holy days around easter? ";
            cin >> year;
        }while(year<=0);
        int easter_num=date_to_daynum(year, easter_month(year), easter_day(year));
        print_holy_days(year,easter_num);
        string answer="";
        while(answer!="Y"&&answer!="N"){
            cout<<"Would you like to get the dates for another year?(Y/N) ";
            cin>>answer;
            answer=answer=="y"?"Y":answer;
            answer=answer=="n"?"N":answer;
            if(answer=="N")
                return;
        }
    }
}

int main(){
    show_holy_days() ;
    return 0;
}

