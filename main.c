#include<stdio.h>
#include<string.h>
#include "helper.h"

int main(int argc, char * argv[]){
    if (argc<2){
        printf("Filename not given\n");
        return -1;
    }


    // take input from the input file
    struct student *name_head,*surname_head,*ID_head;
    takeInput(argv[1], &name_head,&surname_head,&ID_head);
    printList(name_head,0);
    printList(surname_head,1);
    printList(ID_head,2);

    int val=1;
    while(val){
        printf("Enter your choice\n"
                "\t1. to insert a student in the list\n"
                "\t2. to delete a student from the list\n"
                "\t3. to print the student in the list\n"
                "\t4. to print the student to an output file\n"
                "\t5. to end\n");

        int option;
        printf("Enter the option: ");
        scanf("%d",&option);

        // add a new student
        if(option==1){

            struct student *temp=(struct student *)malloc(sizeof(struct student));
            temp->name=(char*)malloc(namebuf*sizeof(char));
            temp->surname=(char*)malloc(namebuf*sizeof(char));

            printf("Enter the name: ");
            scanf("%s",temp->name );
            printf("Enter the surname: ");
            scanf("%s",temp->surname );
            printf("Enter the ID: " );
            scanf("%ld",&(temp->ID) );

            // printf("%s %s %ld\n",temp->name,temp->surname,temp->ID);
            insertNode(&name_head,&surname_head,&ID_head,temp);

        }

        // delete a student
        else if(option==2){
            deleteNode(&name_head,&surname_head,&ID_head);
        }

        //print the list of students
        else if(option==3){

            printList(name_head,0);
            printList(surname_head,1);
            printList(ID_head,2);
        }


        // print the output to a file
        else if(option==4){
            char filename[namebuf];
            printf("Enter the file name: ");
            scanf("%s",filename);
            outputFile(filename,name_head,surname_head,ID_head);
        }

        // exit program
        else if(option==5){
            val=0;
        }

        else printf("Invalid option\n");


    }

}
