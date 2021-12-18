//
// Created by Or on 12/16/2021.
//

#include <stdio.h>



int isAtbash(char *start , char *end , char *word , int wordlen);
int isAnagram(char *start ,char *end, char *word , int wordlen);
int sum_of_chars(char *w,int wordlen) {
    int a = 0, sum = 0 ,i = 0;
    for (i = 0; i < wordlen; i++ , w++) {
        a = (int) *w;
        if (a >= 65 && a <= 90) {
            sum += (a - 64);
        } else if (a >= 97 && a <= 122) {
            sum += (a - 96);
        }
    }
    return sum;
}

void q1(char *w, char *t , int wordlen, int textlen) {
    //Variables
    char ans[1024];
    int value_of_input = sum_of_chars(w, wordlen);
    int  a=0 , b= 0 ,run_index_ans = 0;
    //point to last char + 1
    char *endChar = t+textlen;

    for(int i =0 ;i<1024;i++) ans[i] = '\000';
    for (char *i = (char *) t; *i!=*endChar; i++) {

        int sum_to_compare = 0;
        for (char *j = (char *) i; *j!=*endChar ; ++j) {

            a = (int) *j;
            if (a >= 65 && a <= 90) {
                sum_to_compare += (a - 64);
            } else if (a >= 97 && a <= 122) {
                sum_to_compare += (a - 96);
            }


            if(sum_to_compare>value_of_input) break;

            else if(sum_to_compare == value_of_input) {
                char *start = (char *) i , *end = (char *) j;
                a = (int)*start;
                b = (int)*end;

                int letterA = ((a >= 65 && a <= 90) || (a >= 97 && a <= 122));
                int letterB = ((b >= 65 && b <= 90) || (b >= 97 && b <= 122));

                if(letterA && letterB){
                    if(run_index_ans!=0){
                        ans[run_index_ans++] = '~';
                    }
                    while (start <= end) {
                        ans[run_index_ans++] =  *start++;
                    }
                    break;
                }
                else if(!letterA && letterB){
                    while((*start < 65 || (*start > 90 && *start < 97) || *start > 122)){start++; i++;}
                    if(run_index_ans!=0){
                        ans[run_index_ans++] = '~';
                    }
                    while(start<=end)
                    {
                            ans[run_index_ans++] = *start++;
                    }
                    break;
                }
            }
        }

    }
    printf("%s",ans);

}
void q2(char *w, char *t , int wordlen, int textlen) {
    //Variables
    char ans[1024];
    int value_of_input = sum_of_chars(w, wordlen);
    int  a=0 , b= 0 ,run_index_ans = 0;
    //point to last char + 1
    char *endChar = t+textlen;

    for(int i =0 ;i<1024;i++) ans[i] = '\000';

    int lowerChar = 'z' + 'a';
    int upperChar = 'Z' + 'A';
    for (char *i = (char *) t; *i!=*endChar; i++) {

        int sum_to_compare = 0;
        //      int counter = 0;
        //      char tempword[30];
        for (char *j = (char *) i; *j!=*endChar ; ++j){

            //if the char is legal, sum it.
            a = (int) *j;
            if (a >= 65 && a <= 90) {
                a = upperChar - a;
                sum_to_compare += (a - 64);
                //               tempword[counter++] = *j;
            } else if (a >= 97 && a <= 122) {
                a = lowerChar - a;
                sum_to_compare += (a - 96);
//                tempword[counter++] = *j;
            }

            //if the sum to compare is greater then the value of input -> break
            if(sum_to_compare>value_of_input) break;

                //if its equal
            else if(sum_to_compare == value_of_input) {
                char *start = (char *) i , *end = (char *) j;
                a = (int)*start;
                b = (int)*end;

                //check if their unnecessary chars and remove them

                int letterA = ((a >= 65 && a <= 90) || (a >= 97 && a <= 122));
                int letterB = ((b >= 65 && b <= 90) || (b >= 97 && b <= 122));

                if(letterA && letterB){
                    if(!isAtbash((char *) start, (char *) end, (char *) w, wordlen)) break;
                    if(run_index_ans!=0){
                        ans[run_index_ans++] = '~';
                    }
                    while (start <= end) {
                        ans[run_index_ans++] =  *start++;
                    }
                    break;
                }
                else if(!letterA && letterB){
                    if(run_index_ans!=0){
                        ans[run_index_ans++] = '~';
                    }
                    while(start<=end)
                    {
                        letterA = ((*start >= 65 && *start <= 90) || (*start >= 97 && *start <= 122));
                        if(letterA) if(!isAtbash((char *) start, (char *) end, (char *) w, wordlen)) break;

                        if((*start >= 65 && *start <= 90) || (*start >= 97 && *start <= 122)){
                            ans[run_index_ans++] = *start++;
                        }
                        else {
                            start++;
                            i++;
                        }
                    }
                    break;
                }
            }
        }

    }
    printf("%s",ans);

}
void q3(char *w, char *t , int wordlen, int textlen){
    //Variables
    char ans[1024];
    int value_of_input = sum_of_chars(w, wordlen);
    int  a=0 , b= 0 ,run_index_ans = 0;
    //point to last char + 1
    char *endChar = t+textlen;

    for(int i =0 ;i<1024;i++) ans[i] = '\000';
    for (char *i = (char *) t; *i!=*endChar; i++) {

        int sum_to_compare = 0;
        for (char *j = (char *) i; *j!=*endChar ; ++j) {

            a = (int) *j;
            if (a >= 65 && a <= 90) {
                sum_to_compare += (a - 64);
            } else if (a >= 97 && a <= 122) {
                sum_to_compare += (a - 96);
            }

            if(sum_to_compare>value_of_input) break;
            else if(sum_to_compare == value_of_input) {
                char *start = (char *) i , *end = (char *) j;
                a = (int)*start;
                b = (int)*end;

                int letterA = ((a >= 65 && a <= 90) || (a >= 97 && a <= 122));
                int letterB = ((b >= 65 && b <= 90) || (b >= 97 && b <= 122));
                //check if word is anagram
                if (!isAnagram((char *) start, (char *) end, (char *) w, wordlen)) break;

                if(letterA && letterB){
                    if(run_index_ans!=0){
                        ans[run_index_ans++] = '~';
                    }
                    while (start <= end) {
                        ans[run_index_ans++] =  *start++;
                    }
                    break;
                }
                else if(!letterA && letterB){
                    if(run_index_ans!=0){
                        ans[run_index_ans++] = '~';
                    }
                    while(start<=end)
                    {
                        if((*start >= 65 && *start <= 90) || (*start >= 97 && *start <= 122)){
                            ans[run_index_ans++] = *start++;
                        }
                        else {
                            start++;
                            i++;
                            letterA = ((*start >= 65 && *start <= 90) || (*start >= 97 && *start <= 122));
                        }
                    }
                    break;
                }
            }
        }

    }
    printf("%s",ans);

}

int isAtbash(char *start , char *end , char *word , int wordlen){
    int lowerChar = 'z' + 'a';
    int upperChar = 'Z' + 'A';
    char *p1  = (char *) start;
    char *p2  = (char *) end;
    char *p3 = (char *)word;
    char *p4 = (char *)word + wordlen - 1 ;

    int z = (int) *p1;
    int w = (int) *p2;
    z = (z >= 65 && z <= 90) ? upperChar - z : (z >= 97 && z <= 122) ? lowerChar - z : 0;
    w = (w >= 65 && w <= 90) ? upperChar - w : (w >= 97 && w <= 122) ? lowerChar - w : 0;


    if(z == *p3 && w == *p4)
    {
        for( ;p1!=p2 ; p3++ , p1++)
        {
            z = (int) *p1;
            z = (z >= 65 && z <= 90) ? upperChar - z : (z >= 97 && z <= 122) ? lowerChar - z : 0;
            if(*p3 != z) return 0;

        }
        return 1;
    }
    else if(w == *p3 && z == *p4)
    {
        for( ;p1!=p2 ; p3++ , p2--)
        {
            w = (int) *p2;
            w = (w >= 65 && w <= 90) ? upperChar - w : (w >= 97 && w <= 122) ? lowerChar - w : 0;
            if(*p3 != w) return 0;
        }


        return 1;
    }

    return 0;
}

int isAnagram(char *start ,char *end, char *word , int wordlen) {
    int source[26] = {0}, temp[26] = {0}, c = 0;
    if ((*start >= 65 && *start <= 90) || (*start >= 97 && *start <= 122)) {
        while (start < end + 1) {
            if ((*start >= 97 && *start <= 122)){
                temp[*start - 'a']++;
                start++;
            }else if((*start >= 65 && *start <= 90)){
                temp[*start - 'A']++;
                start++;
            }
            else return 0;
        }
    }else{
        while((*start < 65 || (*start > 90 && *start < 97) || *start > 122)){start++;}
        while (start < end + 1) {
            if ((*start >= 97 && *start <= 122)){
                temp[*start - 'a']++;
                start++;
            }else if((*start >= 65 && *start <= 90)){
                temp[*start - 'A']++;
                start++;
            }
            else return 0;
        }
    }
    for (int i = 0; i < wordlen; ++i) {
        if((*word >= 97 && *word <= 122)) {
            source[*word - 'a']++;
            word++;
        }else if((*word >= 65 && *word <= 90)) {
            source[*word - 'A']++;
            word++;
        }
        else return 0;
    }

    for (c = 0; c < 26 ; ++c) {
        if(source[c]!= temp[c]) return 0;
    }
    return 1;
}
