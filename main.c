#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <math.h>
int strleght(char strl[]){
    int count;
    for(count = 0; strl[count] != '\0'; count ++);
    strl[1] = 'd';
    return count;
}
int atoi_spr(const char strl[]){
    int count = 0;
    int result = 0;
    while (isdigit(strl[count])) {
        result = result*10 + (strl[count]-'0');
        count++;
    }
    return result;
}

int htoi_spr(const char strl[]){
    int count = 0;
    int result = 0;
    while (isdigit(strl[count]) || ((tolower(strl[count]) >= 'a') && (tolower(strl[count]) <= 'f')) ) {
        if (isdigit(strl[count]))
            result = result*16 + (strl[count]-'0');
        else
            result = result*16 + (tolower(strl[count])-'a')+10;
        count++;
    }
    return result;
}

void squize(char strc[], char c) {
    int i, j;
    for (i=0, j=0; strc[i] != '\0'; i++) {
        if (strc[i+j] == c)
            j++;
        if (j)
            strc[i] = strc[i+j];
    }
    
}

int main() {
    // int temp = 0;
    // for (char c = 1; c > temp; c++) {
    //     temp = c;

    // }
    // printf("%d\n",temp);
    // for (char c = 1; c < temp; c--) {
    //     temp = c;
    
    // }
    // int c = 12L;
    // printf("%d\a\n", c);
    char strl[] = "abc\0";
    printf("%d\n", strleght(strl));
    enum shitquality {good,bad, ugly};
    enum shitquality a = bad;
    printf("%s\n", strl);
    printf("%d\n", a);
    char v[] = "3456a4bc";
    printf("%ld\n", atoi_spr(v));
    char strl2[] = "E9";
    printf("%ld\n", htoi_spr(strl2));
    char strl3[] = "abcdcefghc123";
    squize(strl3, 'c');
    
    printf("%s\n", strl3);

}
