#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


int count_letters(string input);
int count_words(string input);
int count_sentences(string input);

int main(void)
{

    //To get input
    string t = get_string("Text:");

    //To get toatal letters
    float tl = count_letters(t);

    //To get total words
    float tw = count_words(t) + 1;

    //To get total sentences
    float ts = count_sentences(t);


    //To get average letters per 100 words
    float la = tl / tw ;

    float l = la * 100 ;

    //To get average sentences per 100 words
    float sa = ts / tw ;

    float s  = sa * 100 ;

    //To calculate and round off Grades
    int GRADE = round(0.0588 * l - 0.296 * s - 15.8) ;

    //Check if grade is below one or above 16
    if (GRADE >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (GRADE < 0)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", GRADE);
    }

}

int count_letters(string input)
{
    int letters = 0;
    int length = strlen(input);

    for (int i = 0 ; i < length ; i++)
    {
        if (input[i] > 64 && input[i] < 123)
        {
            letters = letters + 1;
        }
    }

    return letters;

}

int count_words(string input)
{
    int words = 0;
    int length2 = strlen(input);

    for (int i = 0 ; i < length2 ; i++)
    {
        if (input[i] == 32)
        {
            words = words + 1;
        }
    }

    return words;
}

int count_sentences(string input)
{
    int sentences = 0;
    int length3 = strlen(input);

    for (int i = 0 ; i < length3 ; i++)
    {
        if (input[i] == 33 || input[i] == 46 || input[i] == 63)
        {
            sentences = sentences + 1 ;
        }
    }

    return sentences;
}
