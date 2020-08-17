#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX_LIMIT 500
char * get_details();
char * load_data(char *st);
char * create_table_from_share(char *);
char * value_insert_query(char *a,char *b,char *c,char *d);
void update_table_tamo();
void show_table_tamo();
void create_Port_Folio();
char * add_inv_comma(char *);
char * for_the_sake_of_return(char *a,char *b,char *c);
char * update_query(char *, char *ptr1);
void show_portfolio();
char * show_all_result(char*, char*);
char cmp[MAX_LIMIT],*cmp1,*tmp,*tmp2,Share_Name[MAX_LIMIT];
int num_of_share,i=0;
void show_table_tamo();
char t1[MAX_LIMIT]="<!DOCTYPE html><html><head><title>Bengal's Nabab Debu Mondal</title>";
char t11[MAX_LIMIT]="<style>";
char t12[MAX_LIMIT]="h2 {text-align: center;} h4 {text-align: center;} html, body{margin:0;padding:0;height:100%;}  section { position: relative; border: 1px solid #000;padding-top: 37px;background: #500;}";
char t2[MAX_LIMIT]=" section.positioned {  position: absolute;  top:100px;  left:100px;  width:800px;  box-shadow: 0 0 15px #333;}  .container {overflow-y: auto; height: 900px;}";
char t3[MAX_LIMIT]="table {border-spacing: 0;  width:100%;}td + td {border-left:1px solid #eee;} td,th {border-bottom:1px solid #eee; background:#ddd;color: #000;  padding: 10px 25px;}"; 
char t4[MAX_LIMIT]="th{ height: 0;  line-height: 0; padding-top: 0;padding-bottom: 0;color: transparent;  border: none;  white-space: nowrap;}";
char t5[MAX_LIMIT]="th div{  position: absolute;  background: transparent;  color: #fff;  padding: 9px 25px;  top: 0;  margin-left: -25px;  line-height: normal;border-left: 1px solid #800;}";
char t6[MAX_LIMIT]="th:first-child div{ border: none;} ";
char t61[MAX_LIMIT]="</style></head><body style='background-color:powderblue;'><h2><u> This is your PortFolio</u></h2><h4> &copy;Copyright 2020, Tamoghna Bhaduri</h4>";
char t7[MAX_LIMIT]="<section class=''>  <div class='container'><table> <thead>  <tr class='header'><th>Share_Name<div>Share_Name</div></th><th>Offline_CMP<div>Offline_CMP</div> </th><th>Buying_Price<div>Buying_Price</div> </th><th>Amount_Bought <div>Amount_Bought</div> </th> </tr>";
char create1[MAX_LIMIT]="create table  ";
char create2[MAX_LIMIT]="(Date Date,Opening_Price decimal(5,2),Highest_Price decimal(5,2),Lowest_Price decimal(5,2),Closing_Price decimal(5,2),Adjusted_Closed decimal(5,2),Volume decimal(5,2))";
char t8[MAX_LIMIT]="</tbody> </table> </div> </section> </body> </html>";
char load1[MAX_LIMIT]="k";
char load2[MAX_LIMIT]=" FIELDS TERMINATED BY ',' ENCLOSED BY \'\"\' LINES TERMINATED BY \'\\n\' IGNORE 1 ROWS";
char table_open[10]="<tr><td>",table_data_close[10]="</td>",table_data_open[10]="<td>",table_close[10]="</td></tr>";
char sh[MAX_LIMIT]="<section class=''>  <div class='container'><table> <thead> <tr class='header'><th>Date<div>Date</div></th><th>Opening_Price<div>Opening_Price</div> </th><th>Highest_Price<div>Highest_Price</div> </th><th>Lowest_Price<div>Lowest_Price</div></th><th>Closing_Price<div>Closing_Price</div></th><th>Adjusted_Close<div>Adjusted_Close</div></th><th>Volume<div>Volume</div></th></tr>";
    FILE *fptr;

