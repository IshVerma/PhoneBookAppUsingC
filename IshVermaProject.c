#include <stdio.h>
#include<string.h>
#include<stdlib.h>

//a node
struct node{
	char first[200];                         
	char last[200];                          
	char num[200];                             
	
	struct node * next;                         
};
//Declare methods
void printList();
void insertContact(); //add
void readingFile();// load
void retrievingContact(); //retrieve 
void writeToFile();// save
struct node *head=NULL;

struct node* retrieveNode();

int main(){ 
	int input=0;
	printf("||||--------------THE PHONEBOOK APP----------------|||||\n\n");
	int loop = 1;
	while(loop){ // for the while loop 
	printf("Add:      \tEnter 1\n");
	printf("Save:     \tEnter 2\n");
	printf("Load:     \tEnter 3\n");
	printf("Retrieve: \tEnter 4\n");
	printf("Choose what type of action you want to perform :)\n ");
		scanf("%d", &input);		
		getchar();  
		switch(input) {
			case 1:
				insertContact(); 
				break;
           case 2:
				writeToFile(); 
			
				break;
           case 3:
				readingFile(); 
				break;
           case 4:
				retrievingContact(); 
				break;
			default:
         printf("Please try again and make sure you are entering an integer :) \n");
				break;
		}
	}
	return 0;
}


//this method saves the contact in the text file
void writeToFile(){
	
	FILE *fp;
	fp = fopen("Contacts.txt","w"); //write to the the file 
	struct node *temp=head;

	while(temp != NULL) { //assign the contact details to the list 
        fprintf(fp,"%s\n%s\n%s\n",temp->first,temp->last,temp->num);
        temp=temp->next;
    }

	fclose(fp); //close the file 
	printf("\nThe contact is saved :)\n");
}

//this method loads the contact from the file 
void readingFile() {
	int i=0;
    head = NULL;
    FILE *fp;
	fp = fopen("Contacts.txt","a+"); 
	char first[200];
    char last[200];
    char num[200];
   
	while(fscanf(fp, "%s", first) != EOF) { //while the file's content has some string in it 
        fscanf(fp, "%s", last);
        fscanf(fp, "%s", num);
        
        printf("%d) First Name: %s Last Name:  %s (Contact Number: %s) \n",++i,first, last, num );
        struct node* newNode = retrieveNode(); //add this to the list 
		                                          
        strcpy(newNode->first, first);
        strcpy(newNode->last, last);
        strcpy(newNode->num, num);
        
		if(head == NULL) {
            head = newNode;
        } else {
            struct node *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
	}
	
	fclose(fp); //closes a file
}


//this method adds the contact to the list 
void insertContact(){  	
	
	char first[200];
	char last[200];
	char num[200];
	
	printf("\nEnter the First Name: \n");
	gets(first);
	printf("\nEnter the Last Name: \n");
	gets(last);
	printf("\nEnter the contact number: \n");
	gets(num);
	
   
	struct node* newNode = retrieveNode();
	strcpy(newNode->first, first);
	strcpy(newNode->last, last);
	strcpy(newNode->num, num);
	
	if(head == NULL) {
        head = newNode;
	} else {
        struct node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
		}
		temp->next = newNode;
	}
}

struct node* retrieveNode() {  
    struct node* newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->next = NULL;
	return newNode;
}

//this method retrieves the saved contact from the list 
void retrievingContact(){
	char first[200];
	printf("\nEnter the first name of the contact that you want to retrieve :) \n");
	gets(first);
	int compare;
	if(head==NULL){
        printf("\nThe list is empty :(\n");
	} else {
        struct node *temp=head;
        while(temp != NULL){
            compare =	strcmp(temp->first,first);
            if(compare==0) {
printf("First Name: %s \nLast Name:  %s \nContact Number: %s  \n",temp->first, temp->last, temp->num);
            }
                temp=temp->next;
            }
	}
}

//printing the list 
void printList(){
	
	if(head == NULL){
	printf("\n List is Empty!\n");
	}
	else{
	struct node *temp=head;
	while(temp != NULL) {
		printf("First Name: %s \nLast Name:  %s \nPhone Number: %s ",temp->first, temp->last, temp->num);
			temp=temp->next;
		}
	}
}





