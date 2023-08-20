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

int main(){
        
	//taking password
	printf("Please Enter the Password: \n");
        char pass[15];
        scanf("%s", &pass);
        char *passptr = pass;

        //geting the key and matching the password
	int key = matchPassword(passptr);
        
	
	if(key == -1)
        {

                printf("\n\n\nInvalid Credentials\n\n\n");
                exit(1);


        }
	else if{
		printf("\nEnter the file name: \n");
		char filename[100];
		scanf("%s",&filename);
                FILE* inputFile = fopen(filename,"r");
		
		
		printf("\n\nEnter the destination file for encrypted text: \n");
		scanf("%s",&filename);
		FILE* newFile = fopen(filename,"w");
		
		
		if(inputFile==NULL)
		{
			printf("\n\nFile not found\n\n");
			exit(0);
		}else{
			while(fgetc(inputFile)!=EOF){
				char c = fgetc(inputFile)+(key++%100);
				fputc(c,newFile);
			}

			fclose(inputFile);
			fclose(newFile);
			newFile = fopen(filename,"r");

			if(newFile == NULL)
			{
				printf("\n\nERROR : The destination file not found or could not be read");
				exit(1);
			}else{
				while(fgetc(newFile)!=EOF)
				{continue;}
				if(fgetc(newFile)==EOF)
				{
					printf("\n\nSUCCESS : File successfully encrypted");
					return 0;
				}
			}
		}
        }




        return 0;


}



