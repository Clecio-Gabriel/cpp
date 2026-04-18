#include <iostream>
#include <utility>

using value_type = int;
using value_tuple = std::pair <value_type, value_type>;

int calc_time(value_tuple& start, value_tuple& end, value_tuple& time_passed);

int main(){
    value_tuple time1 {};
    value_tuple time2 {};

    std::cin >> time1.first >> time1.second >> time2.first >> time2.second;
    
    value_tuple total_time {};

    calc_time(time1, time2, total_time);

    std::cout << "O JOGO DUROU " << total_time.first << " HORA(S) E " << total_time.second << " MINUTO(S)\n";

    return EXIT_SUCCESS;
}

int calc_time(value_tuple& start, value_tuple& end, value_tuple& time_passed){
    
    value_type fin_min{0};
    value_type pass_min{0};
    value_type pass_hr{0};

    if(end.first>start.first or (end.first==start.first and end.second>start.second)){
        //DEALING WITH HOURS
        end.first -= start.first;
        
        //GET VALUE IN MINUTES
        fin_min = end.first*60 + end.second;
        pass_min = fin_min - start.second;
        
        if (pass_min>=60){
            pass_hr = pass_min/60;
            pass_min -= pass_hr*60;
            time_passed.first = pass_hr;
        }
        time_passed.second = pass_min;
    }

    else{
        start.first -= end.first;

        fin_min = start.first*60 + start.second - end.second;

        pass_min = 1440 - fin_min;
        pass_hr = pass_min/60;
        pass_min -= pass_hr*60;

        time_passed.first = pass_hr;
        time_passed.second = pass_min;

    }

    return EXIT_SUCCESS;
}