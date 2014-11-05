## Question for the Code:    

    $ Given a specific time(like 02:23),Find the angle between hour and minute(less than 180)
    

## Support & Documentation

Basic Sequence of operations

1. Instead of getting time from the user, program gets the current GMT time from the system
2. Arithmetic to obtain the angle in degrees for each hand from the 12 o'clock position
3. Substraction from the grater angle for result_angle
4. If result_angle is greater than 180 degrees then it is substracted from 360 deg.