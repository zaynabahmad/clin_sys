#include<stdio.h>
#include<stdlib.h>
#include"data.h"


/*the functions*/
void master();
int  add();
void ed_pa ();
void admin_mode();
void res_slot();
void can_slot();
void User_mode();
void view_patient();
void view_resLog ();
/*the global cons*/
int num_of_try=0;
int num_of_rec =0;
int eID;
   /*--main--*/
 
   int main (int i)
   {
	int iden;
	printf("welcome to the system\n");
	printf("Type 1 for Admin mode or 2 for User mode:");
	scanf(" %d",&iden);
	switch (iden){
		case 1:
		master();		     /*admin mode */
		
		break;
		
		case 2:
		User_mode();         /*user mode*/
		break;
	}
	
	
 return (main(i+1));	
 }
 
/*function to ensure the pass*/
 void master()
 { 
     int pass ;
	  for (int i=0 ;i<3;i++)
	  {
	   printf("Please enter the password :");
	   scanf(" %d",&pass);
	   if (pass==admin_pass)         /*admin_authen mode*/
	   {                   
          admin_mode();
		  i=3; 
	   }
	  else 
	  {
		  printf("try again:");
		  if(i>=3)
		  {
			  exit(0);
	      }
	  }
	 }
	 
 }
 /*---------------------------*/
 void admin_mode()
 {
	 int op;
	 int id;
	 printf("the options:\n1-Add new patient record\n2-Edit patient recrod\n3-Reserve a slot\n4-Cancel a slot\n");
	 scanf(" %d",&op);
	 switch(op)
	 {
		 case 1:
		 id = add();
         printf("New patient is added successfully,with ID = %d\n",id);
		 break;
		 case 2:
		 printf("Enter the id you want to edit:");
		 scanf(" %d",&eID);
		  ed_pa ();
		 break;
		 case 3:
		  res_slot();
		 break;
		 case 4:
		  can_slot();
		  break;
	 }
	 
	 
 }
 
 /*------------function to add data*/
 int  add()
 {
    num_of_rec++;
    printf("Enter the name");
	scanf(" %s",& new_record[num_of_rec].name);
	printf("Enter the age :");
	scanf(" %d",&new_record[num_of_rec].age);
	printf("Enter the patient pass:");
	scanf(" %d",&new_record[num_of_rec].pass);
	printf("Enter the patient case:");
	scanf(" %s",&new_record[num_of_rec].patient_info);
	new_record[num_of_rec].ID=num_of_rec;
	printf("The patient had been saved with ID %d\n",num_of_rec);
		 
	for ( int i = 1; i <= num_of_rec; i++)
	{ 
		printf("Patien_%d.name   : %s\n", i, new_record[i].name);
		printf("Patient_%d.age    : %d\n", i, new_record[i].age);
		printf("Patient_%d.case   : %s\n", i, new_record[i].patient_info);
		printf("Patient_%d.ID     : %d\n", i, new_record[i].ID);
    }
	return new_record[num_of_rec].ID;
	
 }
 /*------------function to edit the data*/
 void ed_pa ()
 {
	 if (eID<=num_of_rec)
	 {
		 printf("The ID is existed you can modify\n");
		 printf("Enter the new name:");
		 scanf(" %s",&new_record[eID].name);
		 printf("Enetr the age:");
		 scanf(" %d",&new_record[eID].age);
		 printf("Enter the patient info:");
		 scanf(" %s",&new_record[eID].patient_info);
		 
		 printf("Your new data\n");
		printf("Name     : %s\n", new_record[eID].name);
		printf("Age      : %d\n", new_record[eID].age);
		printf("case     : %s\n", new_record[eID].patient_info); 
		 
	 }
	 else 
	 {
		 printf("This ID is not exist");
	 }
	     
 }
 /* -------function to reseve a slot*/
 void res_slot(){
	
	 int s_id;
	 int ch_slot;
	 printf("Enter the id to reseve a slot for:");
	 scanf(" %d",&s_id);
	 if (s_id<=num_of_rec
	 ){
		 if(new_record[s_id].slot==0)
		 {
		printf("Available Slots are: \n1- 2pm to 2:30pm.\n2- 2:30pm to 3pm.\n""3- 3:30pm to 4pm.\n4- 4pm to 4:30pm.\n");
		scanf(" %d",&ch_slot);
		for (int i =0;i<5;i++)
		{
		if(ch_slot>=0&&ch_slot<=5)
		{
		if(slot_log[ch_slot]==0)
		{
			printf("The slot is avialble and had been reseved for %d",s_id);
			slot_log[ch_slot]=1;
			slot_num[ch_slot]=0;
			new_record[s_id].slot=ch_slot;
               break;			
		}
		else
		{
			printf("the slot is not avialable,please choose another one");
			scanf(" %d",&ch_slot);			
		}
		}
		else
		{
			printf("There is no slot at this time.");
		}
		
		}
		}
		 else
		{
			 printf("This ID had reseve a slot with number %d",new_record[s_id].slot);
		 }
		
	 }
 }
 
 
 /*function to cancel the reservation*/
 void can_slot(){
	 int r_id;
	 int ch_slot;
	 printf("Enter the  patient ID:");
	 scanf(" %d",&r_id);
	 if(r_id<=num_of_rec)
	 {
		printf("Enter the slot you want to cancel:");
		scanf(" %d",&ch_slot);
		if(slot_log[ch_slot]!=0)
		{
			if(slot_num[ch_slot]==0)
			{
				slot_num[ch_slot-1]=ch_slot;
				slot_log[ch_slot]=0;
				printf("The reservation has been canceled.");
			}
			else
			{
				printf("Sorry something goes wrong with the system");
			}
			 
		 }
		 else
		 {
			printf("The slot is not reserved");
		 }		 
	 }
	 else {
		 printf("There is no patient with this ID");
	 }
 }
   void User_mode()
   {
   int feature,ID;
	printf("User mode options are:\n1-View patient record.\n2-View reservation log.\n");
	printf("Choose feature: ");
	scanf(" %d",&feature);
	switch (feature)
	{
	case 1:
	view_patient(ID);
	break;
	case 2:
	view_resLog ();
	break;
	default: printf("Not available\n");
	}
   }
 
 void view_patient()
 {
    printf("Please enter your ID: ");
	scanf(" %d",&eID);
	if (eID<=num_of_rec){
	printf("Name   : %c\n",new_record[eID].name);
	printf("Age    : %d\n",new_record[eID].age);
	printf("case   : %c\n",new_record[eID].patient_info);
	printf("ID     : %d\n",new_record[eID].ID);
	}
	else
	{
		printf("There is no patient with this ID");
	}
 }
 void view_resLog ()
 { 
    printf("Enter the id:");
    scanf(" %d",&eID);
	if (eID <= num_of_rec)
	{
		if( new_record[eID].slot!=0)
		{
			printf("The number of slot you reserved is:%d",new_record[eID].slot);
		}
		else 
		{
			printf("There is no reservation for this ID");
		}
	}
	else 
	{
		printf("There is no ID.");
	}
	 
 }
