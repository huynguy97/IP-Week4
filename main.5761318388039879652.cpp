#include <iostream>
#include <limits>

using namespace std;

enum Month {January=1,February,March,April,May,June,July,August,September,October,November,December} ;

/*                                                                          
                                                                            
                                                           
*/
int easter_base ( int year ) {
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
int easter_day ( int year ) {
    return (easter_base (year) % 31) + 1 ;
}

/*                                                                                   
*/
Month easter_month ( int year ) {
    return static_cast<Month> (easter_base (year) / 31) ;
}

/*                                                                   
                                 
                                                                   */
bool is_leap_year ( int year ) {
    //                                                                                                              
    if (year % 4 == 0 && (year % 100 != 0  || year % 400 == 0 )){
        return true;
    }
    return false;
}

//                                                                                                                                               
int number_of_days_in_month ( int year, Month month ) {
    int month_int = static_cast<int>(month);
    if (month_int == 2) { //                                          
        if (is_leap_year(year)){
            return 29;
        }
        else return 28;
    }
    else if (month_int <= 7) {
        return 30 + month_int % 2; //                                                          
    }
    else {
        return 31 - month_int % 2; //                                                                                
    }
}

//                                                                                                                                                                
//                                                                                          
Month take_input_month(string message){
    int month_int = 0;
    cout << message << endl;
    while (!(cin >> month_int) || month_int < 1 || month_int > 12){ //                                                                                                                       
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid input. " << message << endl;
    }
    cout << endl; //                                    
    return static_cast<Month>(month_int); //                            
}

//                                                                                                                                                    
int take_input_year(string message){
    int year = 0;
    cout << message << endl;
    while (!(cin >> year)){ //                                                                                                                        
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid input. " << message << endl;
    }
    cout << endl; //                                    
    return year;
}

/*                                                                   
                                                
                                                                   */

/*                                                                       
                                                                                                  
                                                                                                                                 
                                                                                        
                        
*/
int calculate_holy_day (int year, int day_easter, Month month_easter, int offset) {
    int output = day_easter + offset;
    int month_check = static_cast<int>(month_easter);

    //                                                                                                     
    //                                                                               
    bool safe = false;
    int days_before_easter = 0;
    int days_after_easter = 0;
    for (int i = 1; i < month_check; i++){
        days_before_easter -= number_of_days_in_month(year, static_cast<Month>(i));
    }
    for (int j = month_check; j <= 12; j++){
        days_after_easter += number_of_days_in_month(year, static_cast<Month>(j));
    }
    days_before_easter -= day_easter;
    days_after_easter += day_easter;
    if (offset < days_before_easter || offset > days_after_easter){ //                                                                                            
        cout << "Error: Invalid offset detected. Holiday is not in the same year as Easter. Date will default to Easter." << endl;
        return day_easter;
    }

    //                                                                                                      
    while (output <= 0) { //                                                                                       
        output += number_of_days_in_month(year,static_cast<Month>(month_check - 1));
        month_check -= 1; //                                        
    }
    while (output > number_of_days_in_month(year,static_cast<Month>(month_check))) { //                                                                                               
        output -= number_of_days_in_month(year,static_cast<Month>(month_check));
        month_check += 1; //                                       
    }
    return output;
}

//                                                                         
//                                                                                                    
//                                                                                                                                    
Month calculate_holy_month (int year, int day_easter, Month month_easter, int offset) {
    int day_check = day_easter + offset;
    int month_check = static_cast<int>(month_easter);
    Month output = month_easter;

    //                                                                                                     
    //                                                                               
    bool safe = false;
    int days_before_easter = 0; //                                                              
    int days_after_easter = 0; //                                                        
    for (int i = 1; i < month_check; i++){
        days_before_easter -= number_of_days_in_month(year, static_cast<Month>(i));
    }
    for (int j = month_check; j <= 12; j++){
        days_after_easter += number_of_days_in_month(year, static_cast<Month>(j));
    }
    days_before_easter -= day_easter - 1;
    days_after_easter -= day_easter;
    if (offset < days_before_easter || offset > days_after_easter){ //                                                                                            
        return month_easter;
    }

    //                                                                                                      
    while (day_check <= 0) { //                                                                                       
        day_check += number_of_days_in_month(year, static_cast<Month>(month_check - 1));
        month_check -= 1; //                                         
    }
    while (day_check > number_of_days_in_month(year, static_cast<Month>(month_check))) { //                                                                                               
        day_check -= number_of_days_in_month(year, static_cast<Month>(month_check));
        month_check += 1; //                                        
    }
    output = static_cast<Month>(month_check);
    return output;
}

/*                                                             
                                                                               
                                                                                                                
                                                            */
void show_holy_days () {
    int year = take_input_year("Please enter a year to calculate the holy days of: ");
    int day_easter = easter_day(year);
    Month month_easter = easter_month(year);
    //                                                                                                          
    int offset_carnival_start = -49;
    int offset_carnival_end = -47;
    int offset_good_friday = -2;
    int offset_ascension = 39;
    int offset_whitsuntide = 49;
    //                                                                                                                                                    
    cout << "List of holidays (d/m/yyyy) derived from Easter in year " << year << ":" << endl << endl;
    cout << "Carnival starts " << '\t' << calculate_holy_day(year, day_easter, month_easter, offset_carnival_start)
         << "/" << calculate_holy_month(year, day_easter, month_easter, offset_carnival_start) << "/" << year
         << '\t' << " and ends " << '\t' << calculate_holy_day(year, day_easter, month_easter, offset_carnival_end)
         << "/" << calculate_holy_month(year, day_easter, month_easter, offset_carnival_end) << "/" << year << "." << endl;
    cout << "Good Friday is on " << '\t' << calculate_holy_day(year, day_easter, month_easter, offset_good_friday)
         << "/" << calculate_holy_month(year, day_easter, month_easter, offset_good_friday) << "/" << year << "." << endl;
    cout << "Easter is on " << '\t' << '\t' << day_easter << "/" << month_easter << "/" << year << endl;
    cout << "Ascension day is on " << '\t' << calculate_holy_day(year, day_easter, month_easter, offset_ascension)
         << "/" << calculate_holy_month(year, day_easter, month_easter, offset_ascension) << "/" << year << "." << endl;
    cout << "Whitsuntide is on " << '\t' << calculate_holy_day(year, day_easter, month_easter, offset_whitsuntide)
         << "/" << calculate_holy_month(year, day_easter, month_easter, offset_whitsuntide) << "/" << year << "." << endl << endl;
}

//                                              
int main() {
    //                                                                                    
    /*
                                                                  
                                                        
                                                                                    
                                                                                                                               
                                                  
    */
    show_holy_days() ;
    return 0;
}

