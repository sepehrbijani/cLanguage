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

void puts_spr(char ln[]){
    for (int i = 0; ln[i] != '\n'; i++)
        putchar(ln[i]);
}

void squize_spr(char strc[], char c) {
    int i, j;
    for (i=0, j=0; strc[i] != '\0'; i++) {
        if (strc[i+j] == c) // skip copying c to its own location 
            j++;
        strc[i] = strc[i+j]; 
    }  
}

void squize_book(char strc[], char c) {
    int i, j;
    for (i=0, j=0; strc[i] != '\0'; i++) {
        if (strc[i] != c)
            strc[j++] = strc[i];
    }
    strc[j] = '\0';
}

void strcat_spr(char s[], char t[]) {
    int i, j;
    for(i = 0; s[i] != '\0'; i++);
    for(j = 0; t[j] != '\0'; j++)
        s[i+j] = t[j];
}

void squize_str_v1_spr(char s1[], char s2[]) {
    int i, j, k;
    i = j = k = 0;
    for (i = 0; s1[i] != '\0'; i++) {
        for(j = 0; (s1[i+k+j] == s2[j]) && ((s2[j++] != '\0') && s1[i+j] !='\0'); j++);
        if (s2[j] == '\0') 
            k+=j;
        s1[i] = s1[i+k];
    }
}

void squize_str_v2_spr(char s1[], char s2[]) {
    int i, j, k;
    i = j = k = 0;
    for(i = 0; s1[i] != '\0'; i++) {
        while( (s1[i+j] == s2[j]) && ((s2[j++] != '\0') || s1[i+j] !='\0'));
        if(s2[j] != '\0')
            s1[k++] = s1[i];
        else {
            i += (j-1);
            j = 0;
        }
    }
    s1[k] = '\0';
}

int str_str_int_spr(char s1[], char s2[]) {
    int i, j;
    i = j = 0;
    for(i = 0; s1[i] != '\0'; i++) {
        while(((s1[i+j] != '\0') && (s2[j] != '\0') ) && (s1[i+j]==s2[j++]));
        if(s2[j] == '\0')
            return i;
        j = 0;
    }
    return -1;

}

int any_spr(char s1[], char s2[]) {
    int i, j;
    i = j = 0;
    for(i = 0; s1[i] != '\0'; i++) {
        for(j = 0; s2[j] != '\0'; j++)
            if(s1[i] == s2[j])
                return i;
    }

}

char * binString(short n) {


    static char result[17];
    for (int count = 0; count <= 15; count++) {
        result[15-count] = (n & (1<<count)) ? '1':'0';
    }
    result[16] = '\0';
    
    return result;
}



unsigned getbit_spr(unsigned x, int p , int n) {
    x = x >> (p-n+1);
    return (x & ~(~0 << n));
}

unsigned bitcount_spr(unsigned x) {
    int result = 0;
    while(x) {
        if(x&1)
            result++;
        x>>=1;
    }
        
    return result;

}

void tolower_spr(char s[]) {
    int i;
    for(i = 0; s[i]; i++)
        s[i] = ((s[i] >= 'A') && (s[i] <= 'Z')) ? (s[i] - 'A'+'a') : s[i];
    s[i] = '\0';
}
int binay_search_spr(int n, int list[], int x) {
    int l = 0;
    int h = n;
    int middle = (h+l)/2;
    while((l <= h)){
        if(list[middle] > x)
            h = middle-1;
        else
            l = middle+1;
        middle = (h+l)/2; 
    }
    return (list[middle] == x)? middle : -1;

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
    // char strl[] = "abc\0";
    // printf("%d\n", strleght(strl));
    // enum shitquality {good,bad, ugly};
    // enum shitquality a = bad;
    // printf("%s\n", strl);
    // printf("%d\n", a);
    // char v[] = "3456a4bc";
    // printf("%ld\n", atoi_spr(v));
    // char strl2[] = "E9";
    // printf("%ld\n", htoi_spr(strl2));
    // char strl3[] = "abcdcefghc123";
    // squize_spr(strl3, 'c');
    
    // printf("%s\n", strl3);

    // char strl4[100] = "abc";
    // char strl5[4] = "123";
    // strcat_spr(strl4, strl5);
    // printf("%s\n", strl4);
    char strl6[] = "a1bcdefgh1234gh1vf3";
    char strl7[4] = "gh1";
     char strl8[] = "ABC24234vgbwef3234vdFfgbb";

    // printf("%d\n", any_spr(strl6,strl7));
    // squize_str_v2_spr(strl6, strl7);
    // printf("%s\n", strl6);
    // printf("%d\n", getbit_spr(0b10000111011,6,4));
    // printf("%d\n", bitcount_spr(0b10010111010));
    tolower_spr(strl8);
    printf("%s\n", strl8);
    int list[] = {0, 1, 4, 5, 6, 8, 19};
    for(__int64_t c; c < 100000000; c++)
    binay_search_spr(7, list, 5);
}
