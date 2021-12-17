#include <stdio.h>
#include <string.h>
#include "stringProg.h"
int main() {
    char word[30];
    char text[1024];
    scanf("%[^\n]", word);
    scanf("%[^~]", text);
    int wordlen = strlen(word);
    int textlen = strlen(text);
    char *w = word;
    char *t = text;

    printf("Gematria Sequences: ");
    q1(w,t,wordlen,textlen);
    printf("\n");
    printf("Atbash Sequences: ");
    q2(w,t,wordlen,textlen);
    printf("\n");
    printf("Anagram Sequences: ");
    q3(w,t,wordlen,textlen);
    printf("\n");
    return 0;
}
