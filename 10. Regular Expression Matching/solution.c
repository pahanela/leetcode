/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: pahanela
 *
 * Created on June 4, 2018, 11:02 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isMatch(char* s, char* p);

/*
 * 
 */
int main(int argc, char** argv) {

    if (isMatch("abbabaaaaaaacaa", "a*.*b.a.*c*b*a*c*"))
        printf("TRUE");
    else
        printf("FALSE");
    
    return (EXIT_SUCCESS);
}

bool isMatch(char* s, char* p) {
    int i = 0;
    int j = 0;
    while (p[i] != '\0' && s[j] != '\0'){
        if (p[i + 1] == '*'){
            i++;
            continue;
        }
        if (p[i] >= 'a' && p[i] <= 'z'){
            if (s[j] == p[i]){
                i++;
                j++;
                continue;
            }
            else
                return false;
        }
        if (p[i] == '.'){
            i++;
            j++;
            continue;
        }
        if (p[i] == '*'){
            
            // pattern of zero characters
            if (isMatch(&s[j], &p[i + 1]))
                return true;
            else{
                // pattern of one or more same characters
                if (p[i - 1] >= 'a' && p[i - 1] <= 'z'){
                    if (s[j] == p[i - 1])
                        j++;
                    else
                        return false;
                }
                // pattern of one or more of any characters
                if (p[i - 1] == '.')
                    j++;
                if (s[j] == '\0' && p[i + 1] == '\0')
                    return true;
                else
                    continue;
            }
        }
    }
    if (p[i] == '\0' && s[j] == '\0')
        return true;
    else if (p[i] != '\0' && s[j] == '\0'){
        if (p[i + 1] == '*'){
            if (p[i + 2] == '\0')
                return true;
            else
                return isMatch(&s[j], &p[i + 2]);
        }        
    }
    return false;
}

