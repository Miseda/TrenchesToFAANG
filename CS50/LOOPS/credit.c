#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number;

    //Prompt user for their card number
    number = get_long("Number:");

    //Get length of the card
    int length = 0;
    long cl = number;

    while(cl > 0)
    {
        cl = cl/10;
        length++;

    }
    //Check validity of the card

    if (length != 13 && length != 15 && length !=16 )
    {
        printf("INVLAID\n");
        return 0;
    }


    //Checksum
    int sum1 = 0;
    int sum2 = 0;
    long n = number;
    int total;
    int mod1;
    int mod2;
    int d1;
    int d2;


    do{
        //Get the last digit
        mod1 = n % 10;
        n = n / 10;
        sum1 = sum1 + mod1;

        // Get second last digit

        mod2 = n % 10;
        n = n / 10;
        // Double second last digit and add digits to sum2
        mod2 = mod2 * 2;
        d1 = mod2 % 10;
        d2 = mod2 / 10;
        sum2 = sum2 + d1 + d2;

    }
    while(n > 0);

     total = sum1 + sum2;

    //Check whether the card is valid or not

    if (total % 10!= 0)
    {
        printf("INVALID\n");
        return 0;
    }

    //Get the first two digits and length of the card

    long fd = number;

     while (fd > 100)
    {
        fd = fd / 10;
    }


    if ( fd == 51 ||  fd == 52 ||  fd == 53 ||  fd == 54 ||  fd == 55 )
    {
        printf("MASTERCARD\n");
    }
    else if ( fd == 34 || fd == 37)
    {
        printf("AMERICAN EXPRESS\n");
    }
    else if ((fd / 10 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }



}





