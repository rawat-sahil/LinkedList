#include "helper.h"



void printList(struct student *head,int val){
    int i=1;
    if(val==0) printf("The list in name-alphabetical order\n");
    else if(val==1) printf("The list in surname-alphabetical order\n");
    else if(val==2) printf("The list in ID sorted order\n");

    while(head!=NULL){
        printf("\t%d. %s %s %ld\n",i,head->name,head->surname,head->ID);
        if(val==0)head=head->name_next;
        else if(val==1)head=head->surname_next;
        else if(val==2)head=head->ID_next;
        i++;
    }

    printf("\v\v");
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
    free(fake_head);

}

void deleteNode(struct student **name_head,struct student **surname_head, struct student **ID_head){

// if the linked list is emtpy
    if(*name_head==NULL){
        printf("The linked list is empty\n");
        return ;

    }

// take id as input and considering the id of all the students will be different
    long int id;
    printf("Enter the student ID: ");
    scanf("%ld",&id);

    int found=0;
    struct student *fake_head=(struct student *)malloc(sizeof(struct student));

// check for the node with the id same as id entered
    fake_head->name_next=*name_head;
    struct student *temp_head=fake_head;

    while(temp_head->name_next!=NULL){
        if(temp_head->name_next->ID==id){
            found=1;
            break;
        }
        temp_head=temp_head->name_next;
    }

//if id not found return
    if(!found){
        printf("ID not found\n");
        return;
    }
// else delete the id from the name
    temp_head->name_next=temp_head->name_next->name_next;

// removing the pointer from the surname
    fake_head->surname_next=*surname_head;
    temp_head=fake_head;
    while(temp_head->surname_next!=NULL && temp_head->surname_next->ID!=id){
        temp_head=temp_head->surname_next;
    }
    temp_head->surname_next=temp_head->surname_next->surname_next;

// removing the pointer from the id
    fake_head->ID_next=*ID_head;
    temp_head=fake_head;
    while(temp_head->ID_next!=NULL && temp_head->ID_next->ID!=id){
        temp_head=temp_head->ID_next;
    }
    struct student * toBeFreed=temp_head->ID_next;
    temp_head->ID_next=temp_head->ID_next->ID_next;

// updating the pointer
    *name_head=fake_head->name_next;
    *surname_head=fake_head->surname_next;
    *ID_head=fake_head->ID_next;
    free(fake_head);
    printf("The student %s %s\t%ld is deleted from the list!\n",toBeFreed->name,toBeFreed->surname,toBeFreed->ID);
    free(toBeFreed);

}



void takeInput(char* filename,struct student**name_head,struct student**surname_head,struct student**ID_head){
    FILE* file=fopen(filename,"r");
    if(file==NULL){
        printf("file not found\n");
        exit(-1);
    }

    char buff[namebuf];
    // struct student temp[namebuf];
    // int i=0;
    while(fscanf(file,"%s",buff)==1){
        // printf("entered\n");
        char* firstName=(char*)malloc(namebuf*sizeof(char));
        char* lastName=(char*)malloc(namebuf*sizeof(char));
        long int id;
        strcpy(firstName,buff);
        fscanf(file,"%s",buff);
        strcpy(lastName,buff);
        fscanf(file,"%s",buff);
        id=atol(buff);


        //create temp student and add it to the linked list
        struct student *temp=(struct student *)malloc(sizeof(struct student));
        temp->name=firstName;
        temp->surname=lastName;
        temp->ID=id;
        insertNode(name_head,surname_head,ID_head,temp);

    }
    fclose(file);


}


void outputFile(char*filename,struct student*name_head,struct student*surname_head,struct student*ID_head){
    FILE *file=fopen(filename,"w");

// write name in alphabetical order
    fprintf(file,"The list in name-alphabetical order:\n");
    int i=1;
    while(name_head!=NULL){
        fprintf(file,"\t%d. %s %s \t%ld\n",i,name_head->name,name_head->surname,name_head->ID);
        name_head=name_head->name_next;
        i++;
    }
    fprintf(file,"\v\v");


    // write in surname-alphabetical order
    fprintf(file,"The list in surname-alphabetical order:\n");
    i=1;
    while(surname_head!=NULL){
        fprintf(file,"\t%d. %s %s \t%ld\n",i,surname_head->name,surname_head->surname,surname_head->ID);
        surname_head=surname_head->surname_next;
        i++;
    }
    fprintf(file,"\v\v");


    // write in the ID order
    fprintf(file,"The list in ID sorted order:\n");
    i=1;
    while(ID_head!=NULL){
        fprintf(file,"\t%d. %s %s \t%ld\n",i,ID_head->name,ID_head->surname,ID_head->ID);
        ID_head=ID_head->ID_next;
        i++;
    }
    fprintf(file,"\v\v");

// close the file
    fclose(file);

}
