#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List *init_history()
{
    List *list = malloc( sizeof( List));
    list -> root = malloc( sizeof( Item));
    return list;
}

void add_history(List *list, char *str)
{
    int pos = 1;
    Item *tmp = list->root;
    while(tmp){
        tmp = tmp->next;
        pos++;
    }
    tmp=malloc(sizeof(Item));
    tmp->id = pos;
    tmp->word = str;
}

char *get_history(List *list, int id)
{
    Item *tmp;
    if(!list){
        return '\0';
    }
    else{
        tmp = list->root;
        while(tmp){
            if(tmp->id == id){
                return tmp->word;
            }
            tmp = tmp->next;
        }
        return '\0';
    }
}

void print_history(List *list)
{
    if (!list){
        printf("History is empty, please enter some sentences.\n");
    }
    else{
        Item *tmp = list->root;
        while(tmp){
            printf("%d: %s\n",tmp->id,tmp->word);
            tmp->next;
        }
        printf("\n");
    }
}

void free_history(List *list)
{
    Item *tmp;
    Item *head = list->root;
    while(head){
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

