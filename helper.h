#include<stdio.h>
#include <stdlib.h>
struct student{
    char * name;
    char * surname;
    long int ID;
    struct student * name_next;
    struct student * surname_next;
    struct student * ID_next;

} ;

void takeInput(char* filename,struct student **name_head,struct student  **surname_head,struct student **ID_head);
void insertNode(struct student **name_head,struct student **surname_head,struct student **ID_head, struct student *value);
void deleteNode();
void printList(struct student *head,int val);
