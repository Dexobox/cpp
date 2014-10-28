## Question for the Code:    

    $ Colorful number: 
    $ A number can be broken into different sub-sequence parts
    $ e.g. 3245 is broken into  3,2,4,5,32,24,45,324,245
    $ And this number  sequence is colorful as producto of digits of the sub-sequence are unique
    $ 2 , 3, 4 , 5, (3*2 =)6, (2*4=)8, (4*5=)20, (3*2*4=)24, (2*4*5=)40
    $ But 326 is not colorful as the sequenc generated is 
    $ 3, 2, 6, (3*2=)6 <<<(double), (2*6)=12, (3*2*6=)36

## Support & Documentation

Basic Sequence of operations

1. Get input from the user for number which is to be checked for colorful
2. Split the number by the decimal position and store it into a vector
3. Generate combinations based on the input numbers as depicted in the question
4. Generate products of the combinations and store them into a new vector
5. Compare the elements of the vector for duplicates to find colorful numbers or otherwise