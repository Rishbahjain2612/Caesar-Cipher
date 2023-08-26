#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXPL 15

int matchPassword(char *givenPassword)
{
        FILE *password = fopen("Password.txt","r");
        if(password == NULL){
		fclose(password);
                printf("Important compontent for the program is missing");
                exit(0);
        }
        else{
                char passwordFromFile[MAXPL];
                while(fgets(passwordFromFile,sizeof(passwordFromFile),password))
                {
			//printf("==>%s", passwordFromFile);

			//changing the last character from newline\n to string end\0
			if(passwordFromFile[strlen(passwordFromFile)-1]=='\n'){
				passwordFromFile[strlen(passwordFromFile)-1] = '\0';
			}

			//printf("====>%d", strlen(passwordFromFile));
			//printf("/-/%s\n", givenPassword);

                        if(strcmp(givenPassword,passwordFromFile)==0)
                        {
				fclose(password);
                                return passwordFromFile[4];
                        }

                }
		fclose(password);
        }
        return -1;
}

void decrypt(int key)
{
		printf("\nEnter the file name: \n");
		char filename[100];
		scanf("%s",&filename);
                FILE* inputFile = fopen(filename,"r");
		
		
		printf("\nEnter the destination file for decrypted text: \n");
		scanf("%s",&filename);
		FILE* newFile = fopen(filename,"w");
	
		if(inputFile==NULL)
		{
			printf("\nFile not found\n");
			exit(0);
		}else{
			while(!feof(inputFile)){
				char c = fgetc(inputFile);
				fputc(c+(key++%10),newFile);
				
			}
			

			fclose(inputFile);
			fclose(newFile);
			newFile = fopen(filename,"r");

			if(newFile == NULL)
			{
				printf("\nERROR : The destination file not found or could not be read");
				exit(1);
			}else{
				fclose(newFile);
				printf("\nSUCCESS : File successfully decrypted\n");
				return;
			}
		}
}

void encrypt(int key){
//		printf("%d",key);
		printf("\nEnter the file name: \n");
		char filename[100];
		scanf("%s",&filename);
                FILE* inputFile = fopen(filename,"r");
		
//		filename='';
		printf("\nEnter the destination file for encrypted text: \n");
		scanf("%s",&filename);
		FILE* newFile = fopen(filename,"w");
		
		
		if(inputFile==NULL)
		{
			printf("\nFile not found\n");
			exit(0);
		}else{
			while(!feof(inputFile)){
				//printf("inputting..");
				char c = fgetc(inputFile);
					fputc(c-(key++%10),newFile);
				//printf("%d",key++%100);
				//	fputc(c,newFile);
				
			}
			//fputc(fgetc(inputFile),newFile);

			fclose(inputFile);
			fclose(newFile);
			newFile = fopen(filename,"r");

			if(newFile == NULL)
			{
				printf("\nERROR : The destination file not found or could not be read");
				exit(1);
			}else{
				fclose(newFile);
				printf("\n\nSUCCESS : File successfully encrypted\n\n");
				return;
			}
		}
}
int main(){
        
	//taking password
	printf("Please Enter the Password: \n");
        char pass[15];
        scanf("%s", &pass);
        char *passptr = pass;

	printf("\nFor encrypting file PRESS 0, For decrypting PRESS 1\n");
	int choice;
	scanf("%d",&choice);

        
	int key = matchPassword(passptr);
        
	
	if(key == -1)
        {
                printf("\nInvalid Credentials\n");
                exit(1);
        }
	else if(choice==0) encrypt(key);
	else if(choice==1) decrypt(key);
	else printf("Invalid Input");
        return 0;


}



