#include "helper.h"



void printList(struct student *head,int val){
    int i=1;
    if(val==0) printf("The list in name-alphabetical order\n");
    else if(val==1) printf("The list in surname-alphabetical order\n");
    else if(val==2) printf("The list in ID sorted order\n");

    while(head!=NULL){
        printf("%d. %s %s %ld\n",i,head->name,head->surname,head->ID);
        if(val==0)head=head->name_next;
        else if(val==1)head=head->surname_next;
        else if(val==2)head=head->ID_next;
        i++;
    }

    printf("\n\n");
}


void insertNode(struct student**name_head,struct student**surname_head,struct student**ID_head, struct student *value){

// if the linked list is empty
    if(*name_head==NULL || *surname_head==NULL || *ID_head==NULL){
        *name_head=*surname_head=*ID_head=value;
        return ;
    }

// if linked list is not empty
    struct student *fake_head=(struct student *)malloc(sizeof(struct student));

// put the value in sorted linked list according to name
    fake_head->name_next=*name_head;
    struct student *temp_head=fake_head;
    while(temp_head->name_next!=NULL && strcmp(temp_head->name_next->name,value->name)<0){
        temp_head=temp_head->name_next;
    }
    value->name_next=temp_head->name_next;
    temp_head->name_next=value;

// put the value in sorted linked list according to surname
    fake_head->surname_next=*surname_head;
    temp_head=fake_head;
    while(temp_head->surname_next!=NULL && strcmp(temp_head->surname_next->surname,value->surname)<0){
        temp_head=temp_head->surname_next;
    }
    value->surname_next=temp_head->surname_next;
    temp_head->surname_next=value;

// put the value in sorted linked list accordint to id
    fake_head->ID_next=*ID_head;
    temp_head=fake_head;
    while(temp_head->ID_next!=NULL && temp_head->ID_next->ID<value->ID){
        temp_head=temp_head->ID_next;
    }
    value->ID_next=temp_head->ID_next;
    temp_head->ID_next=value;


    // update the new heads
    *name_head=fake_head->name_next;
    *surname_head=fake_head->surname_next;
    *ID_head=fake_head->ID_next;


}


void takeInput(char* filename,struct student**name_head,struct student**surname_head,struct student**ID_head){
    FILE* file=fopen(filename,"r");
    if(file==NULL){
        printf("file not found\n");
        exit(-1);
    }

    char buff[100];
    // struct student temp[100];
    // int i=0;
    while(fscanf(file,"%s",buff)==1){
        // printf("entered\n");
        char* firstName=(char*)malloc(100*sizeof(char));
        char* lastName=(char*)malloc(100*sizeof(char));
        long int id;
        strcpy(firstName,buff);
        fscanf(file,"%s",buff);
        strcpy(lastName,buff);
        fscanf(file,"%s",buff);
        id=atol(buff);
        // printf("%s %s %ld\n",firstName,lastName,id);
        // temp[i].name=firstName;
        // temp[i].surname=lastName;
        // temp[i].ID=id;
        // i++;

        //create temp student and add it to the linked list
        struct student *temp=(struct student *)malloc(sizeof(struct student));
        temp->name=firstName;
        temp->surname=lastName;
        temp->ID=id;
        insertNode(name_head,surname_head,ID_head,temp);

    }

    // for(int i=0;i<100;++i){
    //     printf("%s %s %ld\n",temp[i].name,temp[i].surname,temp[i].ID);
    // }


}
