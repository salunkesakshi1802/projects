#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
char ans=0;
int ok;
int b,valid=0;
//function declaration
void WelcomeScreen(void);
void Title(void);
void MainMenu(void);
void LoginScreen(void);
void Add_rec(void);
void func_list(void);
void Search_rec(void);
void Edit_rec(void);
void Dlt_rec(void);
void ex_it(void);
void gotoxy(short x,short y)
    {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    }
//LIST OF GLOBAL VARIABLE
struct patient
   {
    int age;
    char gender;
    char first_name[20];
    char last_name[20];
    char contact_no[15];
    char address[30];
    char email[30];
    char doctor[20];
    char problem[20];
   };
struct patient p,temp_c;
main(void)
  {
    WelcomeScreen();
    Title();
    LoginScreen();
  }
  /* *************welcome screen************ */
  void WelcomeScreen(void)
  {
  	printf("\n\n\n\n\t\t\t\t***********************************************************");
  	printf("\n\t\t\t\t\t\t     Welcome to            \t\t");
  	printf("\n\t\t\t\t\t     SAHYADRI HOSPITAL,Latur  ");
  	printf("\n\t\t\t\t*****************************************************************");
  	printf("\n\n\n\n press any key to continue.....\n");
  	getch();
  	system("cls");
  }
  /* ************title screen********** */
  void Title(void)
  {
  	printf("\n\n\n\n\n\t................................................................");
  	printf("\n\n\t\t\t\t SAHYADRI HOSPITAL");
  	printf("\n\n\n\t................................................................");
  }
  /* ************main menu*********** */
  void MainMenu(void)
  {
  	system("cls");
  	int choose;
  	Title();
  	printf("\n\t\t\t\t 1]add patients record\n");
  	printf("\n\t\t\t\t 2]list patients record\n");
  	printf("\n\t\t\t\t 3]search patients record \n");
  	printf("\n\t\t\t\t 4]edit patients record \n");
  	printf("\n\t\t\t\t 5]delete patients record \n");
  	printf("\n\t\t\t\t 6]exit \n");
  	printf("\n\n\n\n\n\t\t\t\t\t\tchoose from 1 to 6:");
  	scanf("%i",&choose);
  	switch(choose)
  	{
  		case 1:
  		 Add_rec();
  		 break;
  		case 2:
  		 func_list();
  		 break;
  		case 3:
  		 Search_rec();
  		 break;
  		case 4:
  		 Edit_rec();
  		 break;
  		case 5:
  		 Dlt_rec();
  		 break;
  		case 6:
  		 ex_it();
  		 break;
  		default:
  			printf("\t\t\tInvalid entry.Please enter right option:");
  			getch();
     }
  }
    /* *********exit screen******* */
    void ex_it(void)
    {
    	system("cls");
    	Title();
    	printf("\n\n\n\n\n\t\tTHANK YOU FOR VISITING:");
    	getch();
	}
	/* *********login screen********* */
   void LoginScreen(void)
   {
   	int e=0;
   	char username[25];
   	char password[15];
	   char original_username[25]="sakshi";
	   char original_password[15]="1234";
	   do
	   {
	   	printf("\n\n\n\n\n\t\t\tEnter your username and password:)");
	   	printf("\n\n\n\n\t\t\t\tUSERNAME:");
	   	scanf("%s",&username);
	   	printf("\n\n\n\n\t\t\t\tPASSWORD:");
	   	scanf("%s",&password);
	   	if(strcmp(username,original_username)==0 && strcmp(password,original_password)==0)
	    	{
	   		printf("\n\n\n\t\t\t\t\t***login successfull***");
	   		getch();
	   		MainMenu();
	   		break;
		   }
		   else
		   {
		   	printf("\n\t\t password is incorrect:(try again:)");
		   	e++;
		   	getch();
		   }
	    }while(e<=2);
		   if(e>2)		   
		   {
		   	printf("you have cross the limit.You cannot login:(:(");
		   	getch();
		   	ex_it();
		   }
		   system("cls");
	}  
	      /* ******add record***** */
	      void Add_rec(void)
		  {
	      system("cls");
	      Title();
	      char ans;
	      FILE*sr;
	      sr=fopen("C:\\record2.dat","a");
	      printf("\n\n\t\t\t!!ADD PATIENTS RECORD!!!!!!\n");

		  /* *******first name****** */
		  A:
		  	printf("\n\n\t first name:");
		  	scanf("%s",p.first_name);
		  	p.first_name[0]=toupper(p.first_name[0]);
		  	if(strlen(p.first_name)>20||strlen(p.first_name)<2)
		  	{
		  		printf("\n\tInvalid:(\t the maximum range for first name is 20 and minimum range is 2");
		  		goto A;	   
			  }
			  else
			  {
			  	for(b=0;b<strlen(p.first_name);b++)
			  	{
			  		if(isalpha(p.first_name[b]))
			  		{
			  			valid=1;
					}
					  else
					  {
					  	valid=0;
					  	break;
					   }
			    }
				  if(!valid)
				  {
				  	printf("\n\t\t first name content invalid charactor:( enter again:)");
				  	goto A;
				  }
			  }
			  /* ********last name******* */
			  B:
			  	printf("\n\t last name:");
		  	scanf("%s",p.last_name);
		  	p.last_name[0]=toupper(p.last_name[0]);
		  	if(strlen(p.last_name)>20||strlen(p.last_name)<2)
		  	{
		  		printf("\n\tInvalid:(\t the maximum range for last name is 20 and minimum range is 2");
		  		goto B;   
			  }
			  else
			  {
			  	for(b=0;b<strlen(p.last_name);b++)
			  	{
			  		if(isalpha(p.last_name[b]))
			  		{
			  			valid=1;
					  }
					  else
					  {
					  	valid=0;
					  	break;
					  }
				  }
				  if(!valid)
				  {
				  	printf("\n\t\t last name content invalid charactor:( enter again:)");
				  	goto B;
				  }
			  }
			  /* ********gender******** */
			 /*do
			{
			  	printf("\n\t gender[F/M]:");
		  	    scanf("%c",p.gender);
		  	    if(toupper(p.gender)=="M"||toupper(p.gender)=="F")
		       {
		  		ok=1;
			   }
			  else   
			  {
			  	ok=0;
			  }
			  if(!ok)
			  {
			  	printf("\n\n\n\t\t\t gender contain invalid character:(enter either F or M)");	  	
			  }
		}while(!ok);*/
			  /* ******age***** */
			  printf("\n\tage:");
			  scanf("%i",&p.age);
			  /* *******address******* */
			  do
			{
			  	C:
			    printf("\n\t address:");
		  	    scanf("%s",p.address);
		  	    p.address[0]=toupper(p.address[0]);
		  	    if(strlen(p.address)>20||strlen(p.address)<4)
		     {
		  		printf("\n\tInvalid:(\t the maximum range for address is 20 and minimum range is 4");
		  		goto C;	   
		     }
			}while(!valid);
			  /* **********contact no.******** */
			 /*do
			  {
			  	D:
			printf("\n\n\t contact no:");
		  	scanf("%s",p.contact_no);
		  	p.contact_no[0]=toupper(p.contact_no[0]);
		  	if(strlen(p.contact_no)>=10||strlen(p.contact_no)!=10)
		  	{
		  		printf("\n\tInvalid:(\t the maximum range for contact no is 10");
		  		goto D;   
			  }
			  else
			  {
			  	for(b=0;b<strlen(p.contact_no);b++)
			  	{
			  		if(isalpha(p.contact_no[b]))
			  		{
			  			valid=1;
					  }
					  else
					  {
					  	valid=0;
					  	break;
					  }
				  }
				  if(!valid)
				  {
				  	printf("\n\t\t contact no content invalid charactor:( enter again:)");
				  	goto D;
				  }
			  }	
	//	}while(!valid);*/
			  
			  /* **********email******** */
			  do
			  {
			printf("\n\t email:");
		  	scanf("%s",p.email);
		  	if(strlen(p.email)>30||strlen(p.email)<8)
		  	 {
		  		printf("\n\tInvalid:(\t the maximum range for email is 30 and minimum range is 8");   
			  }
			} while(strlen(p.email)>30||strlen(p.email)<8);	
			  /* *********problem******** */
			  E:
			  	printf("\n\t problem:");
		  	scanf("%s",p.problem);
		  	p.problem[0]=toupper(p.problem[0]);
		  	if(strlen(p.problem)>15||strlen(p.problem)<4)
		  	{
		  		printf("\n\tInvalid:(\t the maximum range for problem is 15 and minimum range is 4");
		  		goto E;	   
			  }
			  else
			  {
			  	for(b=0;b<strlen(p.problem);b++)
			  	{
			  		if(isalpha(p.problem[b]))
			  		{
			  			valid=1;
					  }
					  else
					  {
					  	valid=0;
					  	break;
					  }
				  }
				  if(!valid)
				  {
				  	printf("\n\t\t problem content invalid charactor:( enter again:)");
				  	goto E;
				  }
			  }
			  	/* ***********prescribed doctor********* */
			  	F:
			    printf("\n\t prescribed doctor:");
		  	    scanf("%s",p.doctor);
		  	    p.doctor[0]=toupper(p.doctor[0]);
		  	if(strlen(p.doctor)>30||strlen(p.doctor)<4)
		  	{
		  		printf("\n\tInvalid:(\t the maximum range for doctor is 30 and minimum range is 4");
		  		goto F;
				   
			  }
			  else
			  {
			  	for(b=0;b<strlen(p.doctor);b++)
			  	{
			  		if(isalpha(p.doctor[b]))
			  		{
			  			valid=1;
					  }
					  else
					  {
					  	valid=0;
					  	break;
					  }
				  }
				  if(!valid)
				  {
				  	printf("\n\t\t doctor content invalid charactor:( enter again:)");
				  	goto F;
				  }
			  }
			  fprintf(sr,"%s %s %c %i %s %s %s %s %s",p.first_name,p.last_name,/*p.gender,*/p.age,p.address,/*p.contact_no,*/p.problem,p.doctor);
			  printf("\n\n\t\t\t.......Information record successful.......");
			  fclose(sr);
		
			  sd:
			  	getch();
			  	printf("\n\n\n\t\t Do you want to add more[Y/N]??");
			  	scanf("%c",&ans);
			  	if(toupper(ans)=='Y')
			  	{
			  		Add_rec();
				  }
				  else if(toupper(ans)=='N')
				  {
				  	printf("\n\n\t\tThank you:):)");
				  	getch();
				  	MainMenu();	
				  }
				  else
				  {
				  	printf("\n\n\t\tInvalid output");
				  	goto sd;
			     }
	}
				  /* ********view record****** */
				  void func_list()
				  {
				  	int row;
				  	system("cls");
				  	Title();
				  	FILE*sr;
				  	sr=fopen("C:\\record2.dat","r");
				  printf("\n\n\n\t\t\tlist patient record\n");
                        gotoxy(1,15);
				  	printf("full name");
				  	/*	gotoxy(20,15);
				  	printf("gender");*/
				  		gotoxy(32,15);
				  	printf("age");
				  		gotoxy(37,15);
				  	printf("address");
				  	/*	gotoxy(49,15);
				  	printf("contact no");*/
				  		gotoxy(64,15);
				  	printf("email");
				  		gotoxy(88,15);
				  	printf("problem");
				  		gotoxy(98,15);
				  	printf("prescribed docter\n");
				  	printf("********");
				  	row=17;
				  	while(fscanf(sr,"%s %s  %i %s  %s %s %s",p.first_name,p.last_name,/*p.gender,*/&p.age,p.address,/*p.contact_no,*/p.problem,p.doctor))
				  	{
				  	gotoxy(1,row);
					  printf("%s %s",p.first_name,p.last_name);
					 /* gotoxy(20,row);
					  printf("%c",p.gender);*/
					  gotoxy(32,row);
					  printf("%i",p.age);
					  gotoxy(37,row);
					  printf("%s",p.address);
					  /*gotoxy(49,row);
					  printf("%s",p.contact_no);*/
					  gotoxy(64,row);
					  printf("%s",p.email);
					  gotoxy(88,row);
					  printf("%s",p.problem);
					  gotoxy(98,row);
					  printf("%s",p.doctor);
					 row++;	
					  }
			fclose(sr);
			getch();
			MainMenu();
		}
		/* *********search record********* */	  
			void Search_rec(void)
			{
				char name[20];
				system("cls");
				Title();
				FILE*sr;
				sr=fopen("C:\\record2.dat","r");
				printf("\n\n\t\t\t ******search patient Record ******\n");
				gotoxy(12,8);
				printf("\n \n\n\n\n\n\t\t\tEnter patient Name to be Viewed:");
				scanf("%s",name);
				fflush(stdin);
				name[0]=toupper(name[0]);
				while(fscanf(sr,"%s %s  %i  %s %s %s %s",p.first_name,p.last_name,/*&p.gender,*/&p.age,p.address,/*p.contact_no,*/p.problem,p.doctor))
				{
				  		if(strcmp(p.first_name,name)==0)
					{	  
				  	  gotoxy(1,15);
					  printf("full name");
					  gotoxy(25,15);
					/*  printf("gender");
					  gotoxy(32,15);*/
					  printf("age");
					  gotoxy(37,15);
					  printf("address");
					 /* gotoxy(52,15);
					  printf("contact number");*/
					  gotoxy(64,15);
					  printf("email");
					  gotoxy(80,15);
					  printf("problem");
					  gotoxy(95,15);
					  printf("prescribed doctor");
					  printf("********");
					  gotoxy(1,18);
					  printf("%s %s",p.first_name,p.last_name);
					 /* gotoxy(25,18);
					  printf("%c",p.gender);*/
					  gotoxy(32,18);
					  printf("%i",p.age);
					  gotoxy(37,18);
					  printf("%s",p.address);
					 /* gotoxy(52,18);
					  printf("%s",p.contact_no);*/
					  gotoxy(64,18);
					  printf("%s",p.email);
					  gotoxy(80,18);
					  printf("%s",p.problem);
					  gotoxy(95,18);
					  printf("%s",p.doctor);
					  printf("\n");
					  break;
				   }
			}
					if(strcmp(p.first_name,name)!=0)
					{
						gotoxy(5,10);
						printf("record not found!!!");
						getch();
				    }  	
				fclose(sr);
				L:
				getch();
				printf("\n\n\n DO YOU WANT TO VIEW MORE[Y/N]??");
				scanf("%c",&ans);
				if(toupper(ans)=='Y')
				{
					Search_rec();
				}
				else if(toupper(ans)=='N')
				{
					printf("\n\n\nTHANK YOU:)");
					getch();
					MainMenu();
				}
				else
				{
					printf("\n\n\n invalid input");
					goto L;	
				}
     }
/* *******edit record******* */
			void Edit_rec(void)	
			{
				FILE *sr,*ss;
				int i,b,valid=0;
				char ch;
				char name[20];
				system("cls");
				Title();
				ss=fopen("C:\\temp2.dat","w");
				sr=fopen("C:\\record2.dat","r");
				if(sr==NULL)
				{
					printf("\n\n\n\t\t CAN NOT OPEN THE FILE");
					getch();
					MainMenu();		
				}
				printf("\n\n\n\t\t EDIT PAITIENT RECORD");
				gotoxy(12,13);
				printf("enter first name of paitient:");
				scanf("%s",name);
				fflush(stdin);
				name[0]=toupper(name[0]);
				gotoxy(12,15);
				if(ss==NULL)
				{
					printf("\n\n\n can not open file");
					getch();
					MainMenu();	
				}
				while(fscanf(sr,"%s %s  %i  %s %s %s %s",p.first_name,p.last_name,/*&p.gender,*/&p.age,p.address,/*p.contact_no,*/p.problem,p.doctor))
				  	{
				  		if(strcmp(p.first_name,name)==0)
						  {
						  valid=1;
						  gotoxy(25,17);
						  printf("**** exit record***");
						  gotoxy(10,19);
						  printf("%s %s %i  %s %s %s %s",p.first_name,p.last_name,/*p.gender,*/p.age,p.address,/*p.contact_no,*/p.problem,p.doctor);
						  gotoxy(12,22);
						  printf("enter new first name");
						  scanf("%s",p.first_name);
						  gotoxy(12,24);
						  printf("enter new last name");
						  scanf("%s",p.last_name);
						   /*gotoxy(12,26);
						  printf("enter gender");
						  scanf("%c",p.gender);*/
						   gotoxy(12,28);
						  printf(" enter age");
						  scanf("%i",p.age);
						   gotoxy(12,30);
						  printf("enter address");
						  scanf("%s",p.address);
						  p.address[0]=toupper(p.address[0]);
						   /*gotoxy(12,32);
						  printf("enter contact no");
						  scanf("%s",p.contact_no);*/
						   gotoxy(12,34);
						  printf("enter email");
						  scanf("%s",p.email);
						   gotoxy(12,36);
						  printf("enter problem");
						  scanf("%s",p.problem);
						  p.problem[0]=toupper(p.problem[0]);
						   gotoxy(12,38);
						  printf("prescribed doctor");
						  scanf("%s",p.doctor);
						  p.doctor[0]=toupper(p.doctor[0]);
						  printf("press your character for updating operation");
						  ch=getche();
						  if(ch=='u'||ch=='U')
						  {	
						  	fprintf(ss,"%s %s %c %i %s %s %s %s %s",p.first_name,p.last_name,/*p.gender,*/p.age,p.address,/*p.contact_no,*/p.problem,p.doctor);
                            printf("\n\n\n paitient record updated successfully");
						  }
					}
					    else
					    {
					    	fprintf(ss,"%s %s  %i  %s %s %s %s",p.first_name,p.last_name,/*p.gender,*/p.age,p.address,/*p.contact_no,*/p.problem,p.doctor);	
						}
					}
						if(!valid);
						{
							printf("not record found");	
						}
						fclose(ss);
						fclose(sr);
						remove("record2.dat");
						rename("temp2.dat","record2.dat");
						getch();
						MainMenu();
					}
					/* ******delete record****** */
					void Dlt_rec()
					{
						char name[20];
						int found=0;
						system("cls");
						Title();
						FILE *sr,*ss;
						ss=fopen("C:\\temp_file2.dat","w+");
						sr=fopen("C:\\record2.dat","r");
						printf("\n\n\n\n\n\n\t\t\t\t\t\t******DELETE RECORD******\n");
						gotoxy(12,8);
						printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tEnter paitient Name To Delete:");
						fflush(stdin);
						gets(name);
						name[0]=toupper(name[0]);
						while(fscanf(sr,"%s %s %i  %s %s %s %s",p.first_name,p.last_name,/*&p.gender,*/&p.age,p.address,/*p.contact_no,*/p.problem,p.doctor))
						{
							if(strcmp(p.first_name,name)!=0)
							fprintf(ss,"%s %s  %i %s  %s %s %s",p.first_name,p.last_name,/*p.gender,*/p.age,p.address,/*p.contact_no,*/p.problem,p.doctor);
							else
							{
								printf("%s %s  %i  %s %s %s %s",p.first_name,p.last_name,/*p.gender,*/p.age,p.address,/*p.contact_no,*/p.problem,p.doctor);
								found=1;
							}
						}
						if(found==0)
						{
							printf("\n\n\nrecord not found");
							getch();
							MainMenu();	
						}
						else
						{
							fclose(sr);
							fclose(ss);
							remove("record2.dat");
							rename("temp.file2.dat","record2.dat");
							printf("record deleted successfully:)");
							getch();
							MainMenu();	
						}
					}
