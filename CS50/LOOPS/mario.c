
#include <cs50.h>
#include <stdio.h>

int main(void) {

    int height, line;

    //establish user input rules: not less than 0 and not more than 23
    do {
        height = get_int("What is the height of the pyramid?");
    } while (height <= 0 || height > 8);
    printf("Height: %i\n", height);


    //line control formula
    for (line = 0; line < height; line++) {

        //define values of space and hash
        int space = height - line - 1;
        int hash = line + 1;

        //define formula of printing space
        for (int x = 0; x < space; x++) {
            printf(" ");
        }

        //define formula of printing hashtag
        for (int y = 0; y < hash; y++) {
            printf("#");
        }

        printf("  ");

          for (int y = 0; y < hash; y++) {
            printf("#");
        }



        printf("\n");
    }

}