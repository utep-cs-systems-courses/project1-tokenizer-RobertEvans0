 
#include <string.h>
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
    char *copyStr = malloc((len+1) * sizeof(char);
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

int main()
{
}
