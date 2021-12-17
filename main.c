#include <stdio.h>
#include <string.h>
#include "stringProg.h"
int main() {
    char word[30];
    char text[1024];
    for (int i = 0; i < 30; ++i) {word[i] = '\000';}
    for (int i = 0; i < 1024; ++i) {text[i] = '\000';}
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
