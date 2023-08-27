#include<stdio.h>
#include"encryption.h"

int main(){
	printf("Press 1 for encrypt, press 2 for decrypt: ");
	int n;
	scanf("%d",&n);
	if(n==1)
		encrypt();
	else if(n==2)
		decrypt();
	else printf("Wrong Input");
	return 0;
}
