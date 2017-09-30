#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define TABLE_SIZE 42737

#define OPT
/* optimal version */
typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

typedef struct __BRIEF_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    entry *detail;
    struct __BRIEF_ENTRY *pNext;
} brief;

brief **create_table();
brief *findName(char lastName[], brief **table);
void append(char lastName[], brief **table);
unsigned int hash(char lastName[]);

#endif
