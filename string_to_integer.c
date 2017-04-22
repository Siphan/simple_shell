/* This function converts a string into an integer */
#include "my_functions.h"
int string_to_integer(char *s){
    int count = 0;
    int total;
    int c; /* Character */
    int nc; /* Not a character */
    int l = 1;
    long on = 0;
    while (s[count] != '\0'){
        c = s[count]+0;
        nc = s[count+1]+0;
        if (s[count] == 45){
            l*=-1;
        }
        if (c > 47 && c < 58){
            total = c - '0';
            on = on + total;
            if ( (on > 2147483647 && l == 1 ) || (on > 2147483648  && l == -1 )){
                return (0);
            }
            if( nc < 47 || nc > 58){
                break; /* Not a number */
            }
            on *= 10;
        }
        count+=1;
    }
    return(on*l);
}
