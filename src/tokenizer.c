 
#include <string.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int space_char(char c)
{
   if (c==' '||c=='\t'){
     return 1;   
   }
    else{
        return 0;
    }
}

int non_space_char(char c)
{
    return !space_char(c);
}

char *word_start(char *str)
{
    while (*str) ){
        if (non_space_char(str)) return str;
        str++;
    }
    return str;
}

char *word_terminator(char *word)
{
    while(*word){
         if(space_char(word)) return word;
         word++;
        
    }
    return word;
}

int count_words(char *str)
{
    int count = 0;
    char *pos = word_start(str);
   
}

char *copy_str(char *inStr, short len)
{
    
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

int main()
{
}
