#include<stdio.h>
#include<string.h>
#include "helper.h"

int main(int argc, char * argv[]){
    if (argc<2){
        return -1;
    }
//     printf("%s\n",argv[1]);
    // insertNode();

    // char  a[]="jignesh bhatia      something";
    // char *token =strtok(a," ");
    // while(token!=NULL){
    //     printf("%s\n",token);
    //     token=strtok(NULL," ");
    // }

    // FILE* file=fopen(argv[1],"r");
    // if(file==NULL){
    //     printf("file not found\n");
    //     return -1;
    // }
    //
    // char buf[100];
    // while (fscanf(file,"%s",buf)==1){
    //     printf("%s\n",buf);
    // }

    // take input from the input file
    struct student *name_head,*surname_head,*ID_head;
    takeInput(argv[1], &name_head,&surname_head,&ID_head);
    printList(name_head,0);
    printList(surname_head,1);
    printList(ID_head,2);

}
