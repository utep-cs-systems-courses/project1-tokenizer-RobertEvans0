#ifndef _TOKENIZER_
#define _TOKENIZER_

/* Counts the number of characters in the string argument. */
int string_length(char* str);

/* Evaluates if the character c is an acceptable character for
   a token. Acceptable characters include any alphanumeric or
   special character. Unacceptable characters include any
   whitespace or control characters.
   Returns 0 if not, 1 if yes. */
char is_valid_character(char c);

/* Finds the next word in the string. 
   For example, given an input of "  my cake" the function
   should return "my cake". */
char* find_word_start(char* str);

/* Finds the end of current word.
   For example, given an input of "my cake" the function
   should return " cake". */
char* find_word_end(char* str);

/* Counts the number of words in the string argument. */
int count_words(char* str);

/* Copies the next word in str to copy. */
void copy_word(char* str, char* copy);

/* Tokenizes the string argument into an array of tokens.
   For example, "hello world string" would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" */
char** tokenize(char* str);

/* Prints all tokens. */
void print_tokens(char** tokens);

/* Frees all tokens and the array containing the tokens. */
void free_tokens(char** tokens);

#endif