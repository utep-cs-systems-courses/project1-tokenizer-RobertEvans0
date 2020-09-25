#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int space_char(char c)
{
    if (( c == ' '|| c == '\t')&&c!='\0' ){//checks if space or tab
        return 1;
    }
    return 0;
//     if(c == ' '){//checks if space or tab
//         return 1;   
//     }
//     else if(c == '\t'){
//         return 2;
//     }
//     return 0;
}

int non_space_char(char c)
{
    if ((c==' '||c=='\t') || c== '\0' ){//checks if space or tab
        return 0;   
    }
    return 1;
    //Pretty much the opposite of space_char
}

char *word_start(char *word)
{
    int i=0;
    while(*(word + i)){
        if (non_space_char(*(word + i))){
            return word + i;
        }
        i++;
    }
    return word + i;
}

char *word_terminator(char *word)
{
    int i=0;
    while(*(word + i)){
        if(space_char(*(word + i))){
            return word + i;
        }
        i++;
    }
    return word + i;
}

int count_words(char *str)
{
    char *tmp = str;
    int count = 0;
    int i = 0;//pointer is on the first char in the first word
    tmp = word_start(tmp);
    while(*tmp){
        if(non_space_char(*tmp)){
            count++;
        }
        tmp=word_terminator(tmp);
        tmp=word_start(tmp);
    }
   // printf("%d",count);
    return count;
}



char *copy_str(char *inStr, short len)
{
    char *copyStr = malloc(( len + 1) * sizeof(char));
    int i;
    for (i=0; i < len; i++){
        copyStr[i] = inStr[i];
    }
    copyStr[i] = '\0';
    return copyStr;
}

char **tokenize(char *str)
{
    int size = count_words(str);
    char **tokens = malloc((size + 1) * sizeof(char *));
    int i;
    int length;
    char *p = str;
    for(i = 0;i < size;i++){
        p = word_start(p);
        length = word_length(p);
        tokens[i] = copy_str(p, length);
        p = word_terminator(p);
    }
    tokens[i] = '\0';
    return tokens;
}

void print_tokens(char **tokens)
{
    int i=0;
    while (tokens[i]){
//         if(space_char(tokens[i][0])||tokens[i][0]== '\0'){
//             i++;
//             continue;
//         }
        printf("Token[%d] = %s\n", i, tokens[i]);
        i++;
    }
}

void free_tokens(char **tokens)
{
    int i = 0;
    while(tokens[i]){
        free(tokens[i]);
        i++;
    }
    free(tokens);
}

int menuOpt(char *str)
{
    if(word_length(str) > 3) return 4;
    if((str[0] == 's'||str[0] == 'S')){
        return 1;
    }
    else if(str[0] == '!'){
        return 2;
    }
    else if(*(str+0) == 'q'|| *(str+0) == 'Q'){
        return 3;
    }
    else{
        return 4;
    }
}

int word_length(char *str)
{   
    char *tmpS = word_start(str);
    char *tmpE = word_terminator(tmpS);
    int i = 0;
    int length = 0;
    length = tmpE - tmpS;
//     printf("the size was %d",length);
    return length;
}


int main()
{    
    int i;
    List *history = init_history();
    char str[100]; 
    int numHistory;
    char *strHistory;
    printf("Hello! Please enter one of the following characters:\n");
   
    while(1){
        
        printf("1. Enter 's' to type and record your sentence\n2. Enter '!' followed by a number to display a certain sentence from history\n3. Enter '!h' to display all recorded sentences\n ");
        printf("$ ");
        
        fgets(str,100,stdin);
        //printf("%d\n",word_length(str));
        i = menuOpt(str);
        switch(i)//i
        {
            case 1: 
                printf("Please enter your sentence:\n$");
                fgets(str, 100, stdin);
                char **tokens = tokenize(str);
                printf("\n");
                print_tokens(tokens);
                add_history(history, *tokens);
                free_tokens(tokens);
                break;
                    
            case 2: 
                if(*(str+1) == '0'){
                    printf("Please enter a number to display sentence from history or enter 'h' to display all recorded sentences:\n$ ");
                    
                    fgets(str, 100, stdin);
                    
                    if ((str[0]=='h'||str[0]=='H')&& str[1] == '0'){
                        print_history(history);
                        break;
                    }
                    strHistory = get_history(history,atoi(str));
                    if(*strHistory=='\0'){
                        continue;
                    }
                    printf("%s",str);
                }
                else{
                    if ((str[1]=='h'||str[1]=='H')&& str[2] == '0'){
                        print_history(history);
                        break;
                    }
                    strHistory = get_history(history,atoi(str));
                    if(*strHistory=='\0'){
                        continue;
                    }
                    printf("%s",str);
                }
                    
            case 3: 
                printf("Thank you, Goodbye!\n");
                free_history(history);
                return 0;
                
            default: 
                printf("Sorry, that was not a valid option please try again.\n");
                break;
        }
    }
}
