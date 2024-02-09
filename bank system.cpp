#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
//declearing all the function
void account(void);
void accountcreated(void);
void login(void);
void loginsu(void);
void display(char*);
void checkbalance(char*);
void transfermoney(void);
void logout(void);
//declearing gotoxy func for setting cursor position
void gotoxy(int x,int y){
	COORD c;
	c.X=x;
	c.Y=y;
	
	SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE),c);
}
//creating a structure to store data from a user
struct pass{
	char username[50];
	int date,month,year;
	char pnumber[15];
	char adharnum[20];
	char fname[20];
	char lname[20];
	char fathname[20];
	char mothname[20];
	char address[50];
	char typeaccount[20];
};
struct userpass{
	char password[50];
};
struct money{
	char usernameto[50];
	char userpersonfrom[50];
	long int money1;
};
int main(){
	int i,a,b,choice;
	int passwordlength;
	
	gotoxy(20,3);
	//Creating main menu for user
	printf("WELCOME TO BANK ACCOUNT SYSTEM\n\n");
	gotoxy(18,5);
	printf("**********************************");
	gotoxy(25,7);
	printf("DEVELOPER : PK CHAURASIYA");
	gotoxy(20,10);
	printf("1...CREATE A BANK ACCOUNT");
	gotoxy(20,12);
	printf("2...ALREADY A USER? SIGN IN");
	gotoxy(20,14);
	printf("3...EXIT\n\n");
	
	printf("\n\nENTER YOUR CHOICE..");
	scanf("%d",&choice);
	switch(choice){
		case 1: 
				system("cls");
				printf("\n\nUSERNAME MAX 50 CHARACTERS !!");
				printf("\n\nPASSWORD MAX 50 CHARACTERS !!");
				account();
				break;
		case 2: 
				login();
				break;
		case 3: 
				exit(0);
				break;
				
		getch();
	}
}
//function to create account
void account(void){
	char password[20];
	int passwordlength,i,seek=0;
	char ch;
	FILE *fp,*fu;
	struct pass u1;
	struct userpass p1;
	struct userpass u2;
	
	//opening file to write data of a user
	fp=fopen("username.txt","ab");
	//inputs
	system("cls");
	printf("\n\n!!!!CREATE ACCOUNT!!!!");
	printf("\n\nFIRST NAME..");
	scanf("%s",&u1.fname);
	printf("\n\nLAST NAME..");
	scanf("%s",&u1.lname);
	printf("\n\nFATHER NAME..");
	scanf("%s",&u1.fathname);
	printf("\n\nMOTHER NAME..");
	scanf("%s",&u1.mothname);
	printf("\n\nADHAR NUMBER..");
	scanf("%s",&u1.adharnum);
	printf("\n\nMOBILE NUMBER..");
	scanf("%s",&u1.pnumber);
	printf("\n\nADDRESS..");
	scanf("%s",&u1.address);
	printf("\n\nYOUR DATE OF BIRTH..");
	printf("\nDAY..");
	scanf("%d",&u1.date);
	printf("\nMONTH..");
	scanf("%d",&u1.month);
	printf("\nYEAR..");
	scanf("%d",&u1.year);
	printf("\n\nYOUR USERNAME..");
	scanf("%s",&u1.username);
	printf("\n\nTYPE ACCOUNT..");
	scanf("%s",&u1.typeaccount);
	
	printf("\n\nPASSWORD..");
	//taking password in the form of star
	for(i=0;i<50;i++){
		ch=getch();
		if(ch!=13){
			password[i]=ch;
			ch='*';
			printf("%c",ch);
		}
		else
			break;
		scanf("%s",&p1.password);
	}
	//writing to the file
	fwrite(&u1,sizeof(u1),1,fp);
	//closing file
	fclose(fp);
	
	//calling another function after creating a successful account
	accountcreated();
}

void accountcreated(void){
	int i;
	char ch;
	system("cls");
	printf("PLEASE WAIT...\n\nYOUR DATA IS PROCESSING");
	for(i=0;i<210000000;i++){
		i++;
		i--;
	}
	gotoxy(30,10);
	printf("ACCOUNT CREATED SUCCESSFULLY....");
	gotoxy(0,20);
	printf("Press enter to login");
	getch();
	login();
}
//login func to check data of user
void login(void){
	system("cls");
	char username[50];
	char password[50];
	int i,j,k;
	char ch;
	FILE *fp,*fu;
	struct pass u1;
	struct userpass u2;
	
	//opening file of user data
	fp=fopen("username.txt","rb");
	if(fp==NULL){
		printf("ERROR IN OPENING FILE");
	}
	gotoxy(34,2);
	printf(" ACCOUNT LOGIN ");
	gotoxy(7,5);
	printf("*******************************************************************");
	gotoxy(35,10);
	printf("===LOG IN===");
	
	//take input
	gotoxy(35,12);
	printf("USERNAME...");
	scanf("%s",&username);
	gotoxy(35,14);
	printf("PASSWORD...");
	//input the password
	for(i=0;i<50;i++){
		ch=getch();
		if(ch!=13){
			password[i]=ch;
			ch='*';
			printf("%c",ch);
		}
		else
			break;
	}
	//checking username exists or not in file
	while(fread(&u1,sizeof(u1),1,fp)){
		if(strcmp(username,u1.username)==0){
			loginsu();
			display(username);
		}
	}
		if(strcmp(username,u1.username)!=0){
			printf("\n\nPASSWORD OR USERNAME IS INCORRECT\n\nPLEASE TRY AGAIN...");
		}
	//closing the file
	getch();
	login();
	fclose(fp);
}
//redirect after successful login
void loginsu(void){
	int i;
	FILE *fp;
	struct pass u1;
	system("cls");
	printf("Fetching account details.....\n");
	for(i=0;i<200000;i++){
		i++;
		i--;
	}
	gotoxy(30,10);
	printf("LOGIN SUCCESSFUL....");
	gotoxy(0,20);
	printf("Press enter to continue...");
	getch();
}
//display func to show the data of the user on screen
void display(char username1[]){
	system("cls");
	FILE *fp;
	int choice,i;
	fp=fopen("username.txt","rb");
	struct pass u1;
	
	if(fp==NULL){
		printf("ERROR IN OPENING FILE");
	}
	while(fread(&u1,sizeof(u1),1,fp)){
		if(strcmp(username1,u1.username)==0){
			gotoxy(30,1);
			printf("WELCOME %s %s",u1.fname,u1.lname);
			gotoxy(28,2);
			printf("..............................");
			gotoxy(55,6);
			printf("===YOUR ACCOUNT INFO===");
			gotoxy(55,8);
			printf("**************************");
			gotoxy(55,10);
			printf("NAME..%s %s",u1.fname,u1.lname);
			gotoxy(55,12);
			printf("FATHER NAME..%s %s",u1.fathname,u1.lname);
			gotoxy(55,14);
			printf("MOTHER NAME..%s",u1.mothname);
			gotoxy(55,16);
			printf("MOBILE NUMBER..%s",u1.pnumber);
			gotoxy(55,18);
			printf("ADHAR NUMBER..%s",u1.adharnum);
			gotoxy(55,20);
			printf("DATE OF BIRTH..%d-%d-%d",u1.date,u1.month,u1.year);
			gotoxy(55,22);
			printf("YOUR ADDRESS..%s",u1.address);
			gotoxy(55,24);
			printf("ACCOUNT TYPE..%s",u1.typeaccount);
		}
	}
	fclose(fp);
	gotoxy(0,6);
	//menu to perform different action by user
	printf("HOME");
	gotoxy(0,7);
	printf("********");
	gotoxy(0,9);
	printf("1..CHECK BALANCE....");
	gotoxy(0,11);
	printf("2..TRANSFER MONEY....");
	gotoxy(0,13);
	printf("3..LOG OUT\n\n");
	gotoxy(0,15);
	printf("4..EXIT\n\n");
	
	printf("ENTER YOUR CHOICE..");
	scanf("%d",&choice);
	switch(choice){
		case 1: checkbalance(username1);
		        break;
		case 2: transfermoney();
		        break;
		case 3: logout();
				break;
		case 4: exit(0);
				break;
	}
}
void checkbalance(char username2[]){
	system("cls");
	FILE *fm;
	struct money m1;
	char ch;
	int i=1,summoney=0;
	//opening amount file record
	fm=fopen("mon.txt","rb");
	int k=5,l=10;
	int m=30,n=10;
	int u=60,v=10;
	gotoxy(30,2);
	printf("===BALANCE DASHBOARD===");
	gotoxy(30,3);
	printf("******************************");
	gotoxy(k,l);
	printf("S no.");
	gotoxy(m,n);
	printf("TRANSACTION ID");
	gotoxy(u,v);
	printf("AMOUNT");
	
	//READING USERNAME TO FETCH THE CORRECT RECORD
	while(fread(&m1,sizeof(m1),1,fm)){
		if(strcmp(username2,m1.usernameto)==0){
			gotoxy(k,++l);
			printf("%d",i);
			i++;
			gotoxy(m,++n);
			printf("%s",m1.userpersonfrom);
			gotoxy(u,++v);
			printf("%d",m1.money1);
			//adding and finding total money
			summoney=summoney+m1.money1;
		}
	}
	gotoxy(80,10);
	printf("TOTAL AMOUNT");
	gotoxy(80,12);
	printf("%d",summoney);
	getch();
	
	fclose(fm);
	display(username2);
}
void transfermoney(void){
	int i,j;
	FILE *fm,*fp;
	struct pass u1;
	struct money m1;
	char usernamet[20];
	char usernamep[20];
	system("cls");
	//OPENING FILE TO READ MODE TO READ USAER'S USERNAME
	fp=fopen("username.txt","rb");
	//CREATING A ANOTHER FILE TO WRITE AMOUNT ALONG WITH USERNAME TO WHICH AMOUNT IS GOING TO BE TRANSFERED
	fm=fopen("mon.txt","ab");
	gotoxy(33,4);
	printf("____TRANSFER MONEY____");
	gotoxy(33,5);
	printf("========================");
	gotoxy(33,11);
	printf("FROM(your username)...");
	scanf("%s",&usernamet);
	gotoxy(33,13);
	printf("TO(username of person)...");
	scanf("%s",&usernamep);
	
	//cheking for username if it is present in file or not
	while(fread(&u1,sizeof(u1),1,fp)){
		if(strcmp(usernamet,u1.username)==0){
			strcpy(m1.usernameto,u1.username);
			strcpy(m1.userpersonfrom,usernamet);
		}
	}
	gotoxy(33,16);
	//taking amount input
	printf("ENTER AMOUNT TO BE TRANSFERED..");
	scanf("%d",&m1.money1);
	//writing to the file
	fwrite(&m1,sizeof(m1),1,fm);
	gotoxy(0,26);
	printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _");
	gotoxy(0,28);
	printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _");
	gotoxy(0,29);
	printf("transfering amount, please wait...");
	gotoxy(10,27);
	for(i=0;i<70;i++){
		for(j=0;j<120000000;j++){
			j++;
			j--;
		}
		printf("*");
	}
	//close file
	fclose(fp);
	fclose(fm);
	system("cls");
	gotoxy(33,44);
	printf("AMOUNT SUCCESSFULLY TRANSFERED...");
	getch();
	display(usernamet);
}
void logout(void){
	int i,j;
	system("cls");
	printf("please wait, logging out....");
	for(i=0;i<15;i++){
		for(j=0;j<2250000;j++){
			j++;
			j--;
		}
		printf(".");
	}
	gotoxy(30,10);
	printf("YOU SIGN OUT SUCCESSFULLY....\n");
	gotoxy(0,20);
	printf("press any key to continue....");
	getch();
	system("cls");
	main();
}





