#include <iostream>
#include <time.h>

int main(){
    time_t curr_time = time(NULL);
    struct tm* now = localtime(&curr_time);

    
    //std::cout << "The GMT is >> "<< now->tm_hour << ":"<< now->tm_min << std::endl;
    
    unsigned int hour = now->tm_hour % 12; /* If the input is 24hr */
    unsigned int min = now->tm_min;
    
    /*30 degrees for every hour + addition of angle due to minutes*/
    float hour_angle = (30* hour) + (min/2);
    float min_angle = (6*min);
    float result_angle;
    if(min_angle > hour_angle)
        result_angle = min_angle - hour_angle;
    else
        result_angle = hour_angle - min_angle;
        
    if(result_angle > 180)
        result_angle = 360 - result_angle;
        
    std::cout << "The angle between minute hand and hour hand at " << hour <<  ":" << min << " GMT is " << result_angle << "\u00B0" << std::endl;

}