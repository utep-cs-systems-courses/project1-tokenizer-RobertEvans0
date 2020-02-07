Lab Project 1: Building a Tokenizer
===================================
All work should be your own work. Please see the [Course Website](https://sites.google.com/site/arch1utep/home#TOC-Academic-Honesty) for full details on the course's policy on academic honesty.

The following should be pushed to your private Github repository prior to the deadline.:
- All .c and .h source files
- A Makefile to build and clean your project
- A brief README explaining how to use your program

_Your repository should be clean and not cluttered with any temporary scratch files (e.g. hello.c~ or #hello.c#)._

You will be evaluated based on the following criteria:

- Tools (efficiently utilize bash, emacs, make, the compiler, and git)
- Written Communication (appropriate documentation)
- Mature Programming 
  - proper code hygiene (i.e expressive variable, function, and struct names)
  - appropriate algorithms
  - modularization
  - header files
- Variable Allocation (appropriate use of variables, scope, allocation)
- Completion

You may refer to the [Grading and Course Learning Outcomes webpage](https://sites.google.com/site/arch1utep/course-learning-outcomes) for an in depth explanation of the grading criteria.

## Overview
Your objective for the first lab project is to build a tokenizer that
maintains a history. Tokenizing is the process of dividing a string into
tokens by some delimeter (e.g. the string librarys split() function).
Consider tokenizing the string “The cake is a lie!” using the space
character. This would result in: \[“The”, “cake”, “is”, “a”, “lie!”\].

When designing your functions, it is important to consider situations
where a string is not constructed ideally. In other words, what would
happen if your tokenizer encountered a string which contained multiple
delimeters between each token? For example, using a space as a delimeter
and accepting the following string as input, “&nbsp;&nbsp;&nbsp;Oh&nbsp;&nbsp;hi&nbsp;&nbsp;&nbsp;there”, would result
in \[“Oh”, “hi”, “there”\].

Lastly, your tokenizer should maintain a history. A good example of this
is the bash command, **history**; or, something similar to below:

1.  The cake is a lie!
2.  But it was delicious.
3.  True.

A user should be able to view and recall a certain history item by using a command
similar to ’!2’. This would then use the string “But it was delicious.” as input and
tokenize.

## Building a Simple UI
The first milestone for your project is to complete a simple functioning
user interface (which means it does not have to be anything fancy). It
should have an indicator on the left to notify the user that the program
is ready to receive input. For example:

`$ this would work`

`> or even this`

At this point of the project, your program should just echo the input
back to the user.

```
$ my fancy interface thing
my fancy interface thing
```

## Working with Strings
Inside this repository there are two header files, **tokenizer.h** and **history.h**, 
that declare the functions your project will define. You should explore the
contents of each file so that you are familiar with the instructions to
follow.

The second milestone of your project is to define several of the
functions contained in the tokenizer.h file:

1.  `int string_length(char*);`
2.  `char is_valid_character(char c);`
3.  `int find_word_start(char*);`
4.  `int find_word_end(char*);`
5.  `int count_words(char*);`

Each function definition should appropriately use the arguments and
return the correct type declared in the method signature. **You should
not modify these method signatures.** Inside the header file you will
find helpful comments explaining the purpose of each function. 

Lastly, you are **not allowed to use any libraries except stdio.h and stdlib.h**
in your source code.

## Dealing with Memory Allocation
The third milestone of your project will require you to allocate and
free memory. Going back to the **tokenizer.h** file, you are now going
to define the following functions:

1.  `void print_tokens(char**);`
2.  `void free_tokens(char**);`

To test your functions, you should hardcode the allocation of an array
of strings (char\*\*).

## Putting it All Together
Now that you have all the pieces for the tokenizer defined, the last
part is to put them together and define the tokenizer:

1.  `char** tokenize(char*);`

As explained in the Overview, the tokenize method should accept a string
of characters as input and return an array of tokens. It is important to
understand that you must determine the amount of tokens prior to
allocating space for the array, and similarly with each token.

## Maintaining History
The final milestone of the project is to build the history component.
The history can be represented as a linked list data structure, with
each node containing:

1.  an id based on its place in the list,
2.  the string entered by user,
3.  and, a pointer to the next node.

Inside the **history.h** header file you will find two struct declarations representing this notion. 

Overall, a user should be able to: 

1. view the history of strings entered by the user 
2. and recall a certain history item by using the command `!3` (i.e. an exclamation directly followed by the sequence number).

You should define each function from the **history.h** header file in a separate history.c file and then incorporate the history with your tokenizer and interface.
