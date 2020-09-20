#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int space_char(char c)
{
    if (c==' '||c=='\t'){//checks if space or tab
        return 1;   
    }
    else {
        return 0;
    }
}

int non_space_char(char c)
{
    return !space_char(c);//Pretty much the opposite of space_char
}

char *word_start(char *word)
{
    while (*word) ){
        if (non_space_char(word)) return str;//takes pointer to char at beginning of the word
        word++;
    }
    return word;
}

char *word_terminator(char *word)
{
    while (*word){
         if (space_char(word)) return word;//takes pointer to the space after the last char in word
         word++;
    }
    return word;
}

int count_words(char *str)
{
    int count = 0;
    char *pos = word_start(str);//pointer is on the first char in the first word
    while (*p){
        count++;
        pos=word_terminator(p);//pointer will go to first char in each word then the space behind the word til the end.
        pos=word_start(p);
    }
    return count;
}

char *copy_str(char *inStr, short len)
{
    char *copyStr = malloc((len+1) * sizeof(char);// allocating memory with +1 for '\0' that the end.
    int i = 0;
    for (   ; i < len; i++){
        copyStr[i] = inStr[i];
    }
    copyStr[len] = '\0';
    return copyStr;
}

char **tokenize(char *str)
{
    
}

void print_tokens(char **tokens)
{
    
}
void free_tokens(char **tokens)
{
    
}

int menuOpt(char *str)
{
    if (str[0]=='s'||str[0]=='S'){
        return 1;
    }
    else if (str[0]=='!'){
        return 2;
    }
    else if (str[0]=='q'||str[0]=='Q'){
        return 3;
    }
    else{
        return 4;
    }
    
}

int main()
{   printf("Hello! Please enter one of the following characters:\n");
    int i;
    int numHistory;
    char str[100];
    while(1){
        printf("1. Enter 's' to type and record your sentence\n2. Enter '!' followed by a number to display a certain sentence from history\n3. Enter '!h' to display all recorded sentences\n ");
        printf("$");
        fgets(str,100,stdin);
        i = menuOpt(str);
        switch(i)
        {
            case 1: printf("Please enter your sentence:\n");
                    fgets( str, 100, stdin);
                    //tokenize
                    //print_tokens
                    //free_tokens
                    break;
                    
            case 2: if (str[1]=='\0'){
                        printf("Please enter a number to display sentence from history or enter 'h' to display all recorded sentences:\n");
                        fgets(str, 100, stdin);
                        if (str[0]=='h'||str[0]=='H'){
                            //print_history();
                            break;
                        }
                        //printf(get_history(history,atoi(str)));
                        break;
                    }
                    else{
                        if (str[1]=='h'||str[1]=='H'){
                            //print_history();
                            break;
                        }
                        //printf(get_history(history,atoi(str)));
                        break;
                    }
                    
            case 3: printf("Thank you, Goodbye!\n");
                    //free_history(history);
                    return 0;
                
            default:    printf("Sorry, that was not a valid option please try again.\n");
                    break;
        }
        
        
    }
}
