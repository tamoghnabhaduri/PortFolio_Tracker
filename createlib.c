#include "my_project.h"

/******************************************************************************************************/
/****This function is to put the passed string inside inverted comma***********************************/
/******************************************************************************************************/
  char * add_inv_comma(char * ptr)
  {
          char *tmp1,*tmp;
          tmp1=(char *)malloc(strlen(ptr)+2);
          tmp1=strtok(ptr,"\n");
          tmp=(char *) malloc(strlen(ptr)+2);
         strcpy(tmp,"\"");
          strcat(tmp,tmp1);
          strcat(tmp,"\"");
          return tmp;
  }


  /********************************************************************************************************/
  /**This function will create the update query. Passed both string from user.*****************************/
  /*******************************************************************************************************/
  char * update_query(char *t, char *ptr1)
  {
  char part1[MAX_LIMIT]="update  Kite set Current_Marcket_Price = ",part2[MAX_LIMIT]=" where Name_of_Share = ",*t1,*t2;
  t1=(char *)malloc(strlen(part1)+strlen(part2)+strlen(t)+strlen(ptr1)+1);
  t2=(char *)malloc(strlen(ptr1));
  t2=strtok(ptr1,"\n");
  strcpy(t1,part1);
  strcat(t1," ");
  strcat(t1,t2);
  strcat(t1,part2);
  strcat(t1,t);
  //printf("\n This is inside update_query function :: %s",t1);
  return t1;
  }

/********************************************************************************************************/
/********************************************************************************************************/

 char * show_all_result(char* Share_Name,char *cmp)
  {
          char *query,part1[MAX_LIMIT]="select * from Kite";
          query=(char*)malloc(strlen(part1)+1);
          //strcpy(query,part1);
	  snprintf(query,strlen(part1),"%s",part1);
          return query;
  }
/************************************************************************************************************/
/***********************************************************************************************************/
 char * get_details()
 {
 	getchar();
	system("clear");
	char  *a1,*d1,*d2,*d3,*x4,*for_return,*check,Share_Name[MAX_LIMIT],duration1[MAX_LIMIT],duration2[MAX_LIMIT],query2[MAX_LIMIT]="> Temp.csv",*tmp,*x,*x2,*x3;
	char query[MAX_LIMIT]="https://eodhistoricaldata.com/api/eod/", str1[MAX_LIMIT]="?from=",token[MAX_LIMIT]="&api_token=5eccdeea0341a3.51273563&period=d", query1[MAX_LIMIT]="curl -s ";
 	printf("\n\n**Please enter the Share name::");
	fgets(Share_Name,MAX_LIMIT,stdin);
	//strcpy(for_return,Share_Name);
	x3=(char *)malloc(strlen(Share_Name)+1);
	printf("** This is Share_Name= %s",for_return);
 	x3=strtok(Share_Name,"\n");
	for_return=Share_Name;
 	strncat(x3,".NSE",strlen(".NSE"));
 	printf("\n\n ** Please enter the duration, format is Year Month and date  and from past to future:: ");
 	fgets(duration1,MAX_LIMIT,stdin);
 	printf("\n\n ** Please enter duration part2:: ");
 	fgets(duration2,MAX_LIMIT,stdin);
 	d2=strtok(duration2,"\n");
 	d1=strtok(duration1,"\n");
 	d3=(char *)malloc(strlen(d1)+strlen(d2)+strlen("&to=")+1);
 	strncat(d3,d1,strlen(d1));
 	strncat(d3,"&to=");
 	strcat(d3,d2);//YYYY-MM-DD&to=YYYY-MM-DD
 	x=(char *) malloc(strlen(query)+1+strlen(x3));
 	strcat(x,query);
 	strcat(x,x3);
 	x2=(char *) malloc(strlen(str1)+1);
 	strcat(x2,str1);//this is upto the from part
 	strcat(x,x2);//Query then Share Name with .NSE
 	strcat(x,d3);//Query then Share_Name with .NSE with Duration
//	printf("\nThis is x:: %s\n",x);

 	x4=(char *)malloc(strlen(token)+1);
 	strcat(x4,token);
 	strcat(x,x4);
//	printf("\nThis is url with token::%s\n",x);
	//printf("\n query2::%s\n query::%s \n query1 :: %s \n x :: %s\nd3::%s\n",query2,query,query1,x,d3);
 	tmp=(char*) malloc(strlen(x)+2);
 	tmp=add_inv_comma(x);
 	strcat(tmp,query2);
//	printf("\n This is after adding redirection  ::%s\n",tmp);
 	check=(char *) malloc(strlen(tmp)+strlen(query1)+1);
 	strcat(check,query1);
//	printf("\n before concatenating ::  %s\n",check);
 	strcat(check,tmp);
	a1=strtok(for_return,"\n");
//	printf("\n This is the string::  %s\n",check);
	system(check);

 return a1;
}
/**********************************************************************************************************************************/
/*********************************************  This is Insert query for mysql ****************************************************/
/*********************************************************************************************************************************/

char * value_insert_query(char *a,char *b,char *c,char *d)
{
	system("clear");
	printf("\n\n inside insert function::\n\n");
	char *t1,*t2,*t3;
	char part1[MAX_LIMIT]="insert into Debu_Port_Folio (Name_of_Share, Current_Market_Price , Buying_Price,Amount_Bought) values (";
	t1=add_inv_comma(a);
	t2=(char *)malloc(strlen(part1)+strlen(a)+strlen(c)+strlen(b)+strlen(d)+10);
	strcpy(t2,part1);
	strcat(t2,t1);
	strcat(t2,", ");
	t3=strtok(b,"\n");
	strcat(t2,t3);
	strcat(t2,", ");
	t3=strtok(c,"\n");
	strcat(t2,t3);
	strcat(t2,", ");
	t3=strtok(d,"\n");
	strcat(t2,t3);
	strcat(t2,")");
	//printf("\n inser query ==%s",t2);
	return t2;
}
/************************************************************************************************************************************/
/************************************************************************************************************************************/

char * for_the_sake_of_return(char *a,char *b,char *c)
{
	char * temp;
	printf("\n\n\n this is a= %s \n\nb=%s \n\nc=%s\\n",a,b,c);
	temp=(char *) malloc(strlen(a)+strlen(b)+strlen(c)+1);
	strcat(temp,a);
	strcat(a,b);
	strcat(a,c);
	return a;
}
