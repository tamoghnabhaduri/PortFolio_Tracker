
/*********************************************/
 /* Developer:-Tamoghna Bhaduri */
 /* Official Mail:- tamoghnabhaduri@gmail.com */
 /* Tester:- Debabrata Mondal  */
 /* Distributio restricted */
/********************************************/





#include "my_project.h"
#include <mysql.h>
/***************************************/

MYSQL *conn,*conn1;
MYSQL_RES *res;  /*Macro Declaration*/
MYSQL_ROW row;
MYSQL * conect_db();
/**************************************/
//char api_token[MAX_LIMIT]="5eccdeea0341a3.51273563";  /* HatiRamPati*/

/****************Connection Checker***********************/

MYSQL * connect_db()
{
char *server = "localhost";
char *user = "root";
char *password = "Sayanti@123#"; /* set me first */
char *database = "Port_Folio";
conn = mysql_init(NULL);
  
     if (!mysql_real_connect(conn, server, user,password, database, 0, NULL, 0))
     {
       	 printf("\n\n ** Unable to connect. Please check password for sql data base also check the database **\n\n");
         printf("\n** Check the file called mysql_tamo_connect.c \n");
	 fprintf(stderr, "%s\n", mysql_error(conn));

        exit(1);
     }
return conn;
}
/**********************************************************/

void show(char *, MYSQL *);
void delete_table(char *,MYSQL *);
int main()
{
	int num=0,size,i=0,sow=0;
	FILE *fptr;
	char *Share_Name,*temp,*temp1,show_help1[MAX_LIMIT]="select * from ",show_help2[MAX_LIMIT]="  Where Opening_Price is not null";
	printf("\n\n/////////********* Please seect these options  with utmost care  **************\n\n");
	printf("\n Press any key to continue::\n");
	getchar();
	system("clear");
	printf("Press 0 to create Port_Folio\n\n\n");
	printf("\n\n ** Please dont give 1. 1 is strictly for Tamoghna's laptop ** \n\n");
	printf("Enter 2 to modify the table and then see it\n\n\n");
	printf("Enter 3 for getting stock update and creating table\n\n");
	scanf("%d",&num);
	switch(num)
	{
		case 0:
		
		printf("\n\nPress any key::\n\n");
		getchar();
		create_Port_Folio();
		system("clear");
		printf("\n Press 0 to see the  temporary Port_Folio::\n");
		scanf("%d",&sow);
		printf("\n\nPress 1 to make this Port_Folio parmanent:: and thenshow it\n\n");
		if(sow==1)
				{
				conn=connect_db();
					if(mysql_query(conn,"create table  My_Port_Folio  SELECT * FROM Debu_Port_Folio;insert My_Port_Folio select * from Debu_Port_Folio"))
						{
						printf("\n Some error\n");
						fprintf(stderr, "%s\n", mysql_error(conn));
						}
					else
				    		{
					system("clear");
					printf("\n\nThanks for using our program\n\n");
				    		}
				}
		else
				{
				system("clear");
				printf("\n\n *** Good Bye my fellow human Being ****\n\n");
				}
		if(sow==0)
		{
		show_portfolio();
		}
		break;
		case 1:
		printf("\n\n This option only works in Tamoghna's Laptop. Machine Bind. This will be removed. Dont Try this. Well please update table::\n\n");
		update_table_tamo();// this shows my database
		show_table_tamo();// this creates html and show in browser
		break;

		default:
		printf("\nPlease stick to option given before:: \n");
		break;
		 
		case 3:
			printf("\n\n #### #### Press Any Key to Continue #### ####\n\n");
			getchar();
			Share_Name=get_details();//this should be inside the libtamo.so
			printf("\n** %s  **\n",Share_Name);
			if(fptr=fopen("Temp.csv","r"))
				{
				printf("\nFile is seen\n");
				fseek(fptr,0,SEEK_END);
				size=ftell(fptr);
					if(size!= 0)
					{
					printf("\nYou cleared the first hurdle, first step towards the DB creation is done::%d\n",size);
					}
		
					else
					{
					printf("\n Some error happpened. Check the token, check internet connection. Check if you have proper package::\n");
					}
				}
			else
				{
				
				printf("\n\n It seem NSE firewall is closed or you are having error with token\n\n Also you may have to use different token\n\n");
				}
		
                        conn=connect_db();
			delete_table(Share_Name,conn);
			temp=create_table_from_share(Share_Name);
                        //conn=connect_db();
                                  if (mysql_query(conn,temp))
                                          {
                                                  printf("\n Table cant be created. Please check create_table_from_share function\n");
                                                  fprintf(stderr, "%s\n", mysql_error(conn));
                                                  exit(1);
                                          }
        			  temp1=load_data(Share_Name);  
                                  if (mysql_query(conn, temp1))
                                          {
                                                  printf("\n\nProblem with loading into database. Please check the stored media \n\n");
                                                  fprintf(stderr, "%s\n", mysql_error(conn));
                                                  exit(1);
                                          }

			
			    free(temp);
                         temp=(char *)malloc(strlen(show_help1)+strlen(Share_Name)+strlen(show_help2)+1);
                         strcpy(temp,show_help1);
                         strncat(temp,Share_Name,strlen(Share_Name));
                         strncat(temp,show_help2,strlen(show_help2));
				  
			conn1=connect_db();
                                   if (mysql_query(conn1,temp))
                                                   {
                                                  printf("Error");
                                                  }

			 show(Share_Name, conn1);	
	}


	
	/* mysql_free_result(res);
   	 mysql_close(conn);
	 mysql_close(conn1);*/
	 return 0;
}

/********************************************************************/
/********************************************************************/
void delete_table(char *Share_Name,MYSQL *conn1)
{
	char t[MAX_LIMIT]="drop table if exists ",*tmp;
	tmp=(char*)malloc(strlen(t)+1+strlen(Share_Name));
	//strcpy(tmp,t);
	snprintf(tmp,strlen(t),"%s",t);
	strncat(tmp,Share_Name,strlen(Share_Name));
	system("clear");
	printf("\n This is to drop tha table :: %s::\n",tmp);
	conn1=connect_db();
	if ( mysql_query(conn1,tmp))
		{
		printf("\nCheck delete-table function\n");

		}
	else
		{
		printf("\nExisting database deleted\n");
		}
	free(tmp);
	mysql_close(conn1);
}
/********************************************************************/
/********************************************************************/
char * load_data(char *st)
{
char *t1,*t2;
t1=strtok(st,"\n");
t2=(char *) malloc(strlen(load1)+strlen(st)+strlen(load2)+10);
strcat(t2,load1);
strcat(t2,t1);
strcat(t2,load2);
//printf("\n\n load data ==  %s \n\n",t2);
return t2;
}
/********************************************************************/
char * create_table_from_share(char *st)
{
char *t1,*t2;
t1=strtok(st,"\n");
t2=(char *) malloc(strlen(create1)+strlen(st)+strlen(create2)+1);
//strcpy(t2,create1);
snprintf(t2,strlen(create1),"%s",create1);
strcat(t2,t1);
strcat(t2,create2);
//printf("\n\n &&&& %s \n\n",t2);
return t2;
}
/********************************************************************/

/*****************************************************************************************************************************************************/
/******************************************************** This is the basic part for updating or inserting already ceated table. Not to be called ****/
/****************************************************************************************************************************************************/
void update_table_tamo()
{
          printf("\n\n You choose to creae database manually. Thats something for Offline user. Brace yourself. Please do not enter wrong entry\n");
          printf("\nYou will be given chance to update  any entry later.\n");
          printf("\nPlease confirm how many entry you want to perform this time\n");
          scanf("%d",&num_of_share);
          //fflush(stdin);
          getchar();
          for(i=1;i<=num_of_share;i++)
          {
                  printf("\n Please provide your %dth share name ::\n",i);
                  fgets(Share_Name,MAX_LIMIT,stdin);
                  printf("\nEnter the CMP of %s ::",Share_Name);
                  fgets(cmp,MAX_LIMIT,stdin);
 
                  printf("\n %s \n %s",Share_Name,cmp);
 
                          tmp=add_inv_comma(Share_Name);//These functions are inside the libtamo.so
                          cmp1=update_query(tmp,cmp);//Happy Dynamic Linking
                          printf("\n %s \n",cmp1);
                          conn=connect_db();
                                  if (mysql_query(conn, cmp1))
                                          {
                                                  printf("\nPlease check your share name:: Try Again\n");
                                                  fprintf(stderr, "%s\n", mysql_error(conn));
                                                  exit(1);
                                          }
          }
mysql_close(conn);
}

/***********************************************************************************************************************************/
/************************ This is the function to create user defined Port_Folio **************************************************/
/*********************************************************************************************************************************/

void create_Port_Folio()
{
	
	conn=connect_db();
	char *t1,*t2,*t3,Share_Name[MAX_LIMIT],Buying_Price[MAX_LIMIT];
	int i,num;
	char cmp[MAX_LIMIT],amount[MAX_LIMIT];
	system("clear");
	printf("\n Please confirm How many Stock data you want to enter in the port folio::\n");
	scanf("%d",&num);	
	if(!(mysql_query(conn,"drop table if exists Debu_Port_Folio")))
	{
		printf("\\n**** So you are first time user!! ****\n\n");
		printf("\n** Press any key to continue**\n");
		getchar();
		system("clear");
		if(mysql_query(conn,"create table Debu_Port_Folio(Name_of_Share varchar(50),Current_Market_Price Decimal(10,2),Buying_Price Decimal(10,2), Amount_Bought INT(20))"))
	
		{
			printf("Unable to create the table itself.Looks like you already have existin port_folio in our database");
        		fprintf(stderr, "%s\n", mysql_error(conn));
		}
	printf("\n\n *** Congrats Empty Port_Folio Created in Database ***\n\n Lets Enter data now ***\n\n");
	for(i=0;i<num;i++)
	{
		printf("\nPlease enter the name of Share, better if you enter the symbo::\n");
		fgets(Share_Name,MAX_LIMIT,stdin);
		printf("\nPlease enter the current marcket price\n");
		fgets(cmp,MAX_LIMIT,stdin);	
		printf("\nPlease enter the Buying Price::\n");
		fgets(Buying_Price,MAX_LIMIT,stdin);
		printf("\n Please enter the amount of share bought::\n");
		fgets(amount,MAX_LIMIT,stdin);
		t1=value_insert_query(Share_Name,cmp,Buying_Price,amount);
		if(mysql_query(conn,t1))
		{
			printf("\n\n*** Some problem while inserting the values in table. Please do check the functions***\n\n\n");
			printf("%s",t1);
			
                            fprintf(stderr, "%s\n", mysql_error(conn));
		}
	

	}

}
}

/********************************************************************************************************************************/
/**************************  Show table in HTML page and open it in Firefox browser *********************************************/
/********************************************************************************************************************************/


/******************************************************************************************************/
/******************************************************************************************************/
/********* This function simply show the table. Not to be called *************************************/
void show_table_tamo()
{	
	int i=0;
	system("rm -rf *.html");
	system("clear");
	fptr=fopen("temp.html","w+");
	fputs(t1,fptr);
	fprintf(fptr,"\n");
	fprintf(fptr,"\t");
	
	fputs(t11,fptr);
	fprintf(fptr,"\n");
	fprintf(fptr,"\t");
	
	fputs(t12,fptr);	
	fprintf(fptr,"\n");
	fprintf(fptr,"\t");
	
	fputs(t2,fptr);	
	fprintf(fptr,"\n");
	fprintf(fptr,"\t");

	fputs(t3,fptr);
	fprintf(fptr,"\n");
	fprintf(fptr,"\t");


	fputs(t4,fptr);
	fprintf(fptr,"\n");
	fprintf(fptr,"\t");
	
	fputs(t5,fptr);
	fprintf(fptr,"\n");
	fprintf(fptr,"\t");
	
	fputs(t6,fptr);
	fprintf(fptr,"\n");
	fprintf(fptr,"\t");
	

	fputs(t61,fptr);
	fprintf(fptr,"\n");
	fprintf(fptr,"\t");
	
	fputs(t7,fptr);
	fprintf(fptr,"\n");
	fprintf(fptr,"\t");

          conn1=connect_db();
          if (mysql_query(conn1,"select Name_of_Share, Current_Marcket_Price,Buying_Price, Amount_Bought from Kite"))
                    {
                            printf("\nPlease check your share name:: Show Result\n");
                            fprintf(stderr, "%s\n", mysql_error(conn));
                            exit(1);
                    }
 
          res = mysql_use_result(conn1);
           while ((row = mysql_fetch_row(res)) != NULL)
	   {
           
	     fputs(table_open,fptr);
	     fputs(row[0],fptr);
	     fputs(table_data_close,fptr);
	     fputs(table_data_open,fptr);
	     fputs(row[1],fptr);
	     fputs(table_data_close,fptr);
	     fputs(table_data_open,fptr);
	     fputs(row[2],fptr);
	     fputs(table_data_close,fptr);
	     fputs(table_data_open,fptr);
	     fputs(row[3],fptr);
	     fputs(table_close,fptr);
	     fprintf(fptr,"\n");
	   }

	   fprintf(fptr,"\n");
	   fputs(t8,fptr);
	   fclose(fptr);
	   system("firefox temp.html &");

}

/***************************************************************************************************************************************************************/
/**************************************************************************************************************************************************************/
void show_portfolio()
{
	int i=0;
	system("rm -rf *.html");
	system("clear");
	fptr=fopen("temp.html","w+");
	fputs(t1,fptr);
	fprintf(fptr,"\n");
	fprintf(fptr,"\t");
	
	fputs(t11,fptr);
	fprintf(fptr,"\n");
	fprintf(fptr,"\t");
	
	fputs(t12,fptr);	
	fprintf(fptr,"\n");
	fprintf(fptr,"\t");
	
	fputs(t2,fptr);	
	fprintf(fptr,"\n");
	fprintf(fptr,"\t");

	fputs(t3,fptr);
	fprintf(fptr,"\n");
	fprintf(fptr,"\t");


	fputs(t4,fptr);
	fprintf(fptr,"\n");
	fprintf(fptr,"\t");
	
	fputs(t5,fptr);
	fprintf(fptr,"\n");
	fprintf(fptr,"\t");
	
	fputs(t6,fptr);
	fprintf(fptr,"\n");
	fprintf(fptr,"\t");
	

	fputs(t61,fptr);
	fprintf(fptr,"\n");
	fprintf(fptr,"\t");
	
	fputs(t7,fptr);
	fprintf(fptr,"\n");
	fprintf(fptr,"\t");

          conn1=connect_db();
          if (mysql_query(conn1,"select Name_of_Share, Current_Market_Price,Buying_Price, Amount_Bought from Debu_Port_Folio"))
                    {
                            printf("\nPlease check your share name:: Show Result\n");
                            fprintf(stderr, "%s\n", mysql_error(conn));
                            exit(1);
                    }
 
          res = mysql_use_result(conn1);
           while ((row = mysql_fetch_row(res)) != NULL)
	   {
           
	     fputs(table_open,fptr);
	     fputs(row[0],fptr);
	     fputs(table_data_close,fptr);
	     fputs(table_data_open,fptr);
	     fputs(row[1],fptr);
	     fputs(table_data_close,fptr);
	     fputs(table_data_open,fptr);
	     fputs(row[2],fptr);
	     fputs(table_data_close,fptr);
	     fputs(table_data_open,fptr);
	     fputs(row[3],fptr);
	     fputs(table_close,fptr);
	     fprintf(fptr,"\n");
	   }

	   fprintf(fptr,"\n");
	   fputs(t8,fptr);
	   fclose(fptr);
	   system("firefox temp.html &");

}



void show(char *t, MYSQL *conn1)
{	
	int i=0;
	char *tmp;
	tmp=(char *)malloc(strlen(t1)+1);
	//printf("\n Killing Firefox. It will open but take time. \n");
	//printf("\n inside the show function::%s\n",t1);
	system("rm -rf *.html");
	system("clear");
	fptr=fopen("temp.html","w+");
	fputs(t1,fptr);
	fprintf(fptr,"\n");
	fprintf(fptr,"\t");
	
	fputs(t11,fptr);
	fprintf(fptr,"\n");
	fprintf(fptr,"\t");
	
	fputs(t12,fptr);	
	fprintf(fptr,"\n");
	fprintf(fptr,"\t");
	
	fputs(t2,fptr);	
	fprintf(fptr,"\n");
	fprintf(fptr,"\t");

	fputs(t3,fptr);
	fprintf(fptr,"\n");
	fprintf(fptr,"\t");


	fputs(t4,fptr);
	fprintf(fptr,"\n");
	fprintf(fptr,"\t");
	
	fputs(t5,fptr);
	fprintf(fptr,"\n");
	fprintf(fptr,"\t");
	
	fputs(t6,fptr);
	fprintf(fptr,"\n");
	fprintf(fptr,"\t");
	

	fputs(t61,fptr);
	fprintf(fptr,"\n");
	fprintf(fptr,"\t");
	
	fputs(sh,fptr);
	fprintf(fptr,"\n");
	fprintf(fptr,"\t");
 
          res = mysql_use_result(conn1);
           while ((row = mysql_fetch_row(res)) != NULL)
	   {
             fputs(table_open,fptr);
	     fputs(row[0],fptr);
	     fputs(table_data_close,fptr);
	     fputs(table_data_open,fptr);
	     fputs(row[1],fptr);
	     fputs(table_data_close,fptr);
	     fputs(table_data_open,fptr);
	     fputs(row[2],fptr);
	     fputs(table_data_close,fptr);
	     fputs(table_data_open,fptr);
	     fputs(row[3],fptr);
	     fputs(table_data_close,fptr);
	     fputs(table_data_open,fptr);
	     fputs(row[4],fptr); 
	     fputs(table_data_close,fptr);
	     fputs(table_data_open,fptr);
	     fputs(row[5],fptr);
	     fputs(table_data_close,fptr);
	     fputs(table_data_open,fptr);
	     fputs(row[6],fptr);
	     fputs(table_close,fptr);
	     fprintf(fptr,"\n");
	   }

	   fprintf(fptr,"\n");
	   fputs(t8,fptr);
	   fclose(fptr);
	   system("firefox temp.html &");


}

