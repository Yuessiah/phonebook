#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "phonebook_opt.h"

/* optimal version */
brief *findName(char lastName[], brief **table)
{
    int hash_idx = hash(lastName);
    brief *tmp = table[hash_idx];

    while(tmp) {
        if(!strcasecmp(lastName, tmp->lastName)) return tmp;
        tmp = tmp->pNext;
    }

    return NULL;
}

void append(char lastName[], brief **table)
{
    unsigned int hash_idx = hash(lastName);
    entry *newErief = (entry *)malloc(sizeof(entry));
    brief *newBrief = (brief *)malloc(sizeof(brief));

    strcpy(newErief->lastName, lastName);
    strcpy(newBrief->lastName, lastName);
    newBrief->detail = newErief;

    newBrief->pNext = table[hash_idx];
    table[hash_idx] = newBrief;
}

brief **create_table()
{
    int i;
    brief **table;

    table = (brief **)malloc(sizeof(brief *)*TABLE_SIZE);
    for(i = 0; i < TABLE_SIZE; i++) table[i] = NULL;

    return table;
}

unsigned int hash(char lastName[])
{
    int i = 0;
    unsigned int val = 0;
    while(lastName[i]) val = val + (val << 5) + lastName[i++];

    return val % TABLE_SIZE;
}
