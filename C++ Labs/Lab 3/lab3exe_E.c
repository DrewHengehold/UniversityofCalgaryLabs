/* lab3exe_E.c
 * ENSF 337, Lab 3 Exercise E
 * Author of Functions:Drew Hengehold
 */

#include <stdio.h>
#include <string.h>

int substring(const char *s1, const char *s2);
/* REQUIRES
 * s1 and s2 are valid C-string terminated with '\0';
 * PROMISES
 * returns one if s2 is a substring of s1). Otherwise returns zero.
 */

void select_negatives(const int *source, int n_source,
                      int* negatives_only, int* number_of_negatives);
/* REQUIRES
 *   n_source >= 0.
 *   Elements source[0], source[1], ..., source[n_source - 1] exist.
 *   Elements negatives_only[0], negatives_only[1], ..., negatives_only[n_source - 1] exist.
 * PROMISES
 *   number_of_negatives == number of negative values in source[0], ..., source[n_source - 1].
 *   negatives_only[0], ..., negatives_only[number_of_negatives - 1] contain those negative values, in
 *   the same order as in the source array.                           */

int main(void)
{
    char s[] = "HelloWorld";
    int a[] = { -5, -9, -13, 4, -39, 9 };
    int size_a;
    int i;
    int negative[6];
    int n_negative;
    
    size_a = sizeof(a) / sizeof(a[0]);
    
    printf("a has %d elements:", size_a);
    for (i = 0; i < size_a; i++)
        printf("  %d", a[i]);
    printf("\n");
    
    select_negatives(a, size_a, negative, &n_negative);
    
    printf("\nnegative elements from array a are as follows:\n");
    for (i = 0; i < n_negative; i++){
        printf("  %d", negative[i]);
        printf("\n");
    }
    
    printf("\nNow testing substring function....\n");
    printf("Answer must be 1. substring function returned: %d\n" , substring(s, "Wo"));
    printf("Answer must be 1. substring function returned: %d\n" , substring(s, "Hello"));
    printf("Answer must be 1. substring function returned: %d\n" , substring(s, "W"));
    printf("Answer must be 0. substring function returned: %d\n" , substring(s, "gro"));
    printf("Answer must be 1. substring function returned: %d\n" , substring(s, "ld"));
    printf("Answer must be 0. substring function returned: %d\n" , substring(s, "Hellor"));
    return 0;
}

int substring(const char *s1, const char* s2)
{
    int count1 = 0;
    int count2 = 0;
    while(s1[count1] != '\0')
        count1++;
    while(s2[count2] != '\0')
        count2++;
    
    int counter = 0;
    for(int i = 0; i < count1; i++){
        if(s1[i] == s2[counter]){
            counter++;
        }
        else
        {
            counter = 0;
        }
        if(counter == count2){
            return 1;
            break;
        }
            
    }
    
    return 0;
}

void select_negatives(const int *source, int n_source,
                      int* negatives_only, int* number_of_negatives)
{
    int counter = 0;
    for(int i = 0; i <= n_source; i++){
        if(source[i] < 0){
            negatives_only[counter] = source[i];
            counter++;
        }
    }
    *number_of_negatives = counter;
    return;
}

