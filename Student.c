#include <string.h>
#include <stdio.h>
#include "Student.h"
#include "Private.h"




/***************************************************************
@fn: login function of the program******************************
@brief: It asks about the mode: Admin or user*******************
@parameter:No parameter it is (void) datatype*******************
@return value: No return value (void)***************************
***************************************************************/

    void login(){
        int i =0;
   while(TRUE){
    int choice ;
    printf("\t\t**STUDENT RECORD**");
    printf("\n1)select 1 for Admin Mode\n2)select 2 for User Mode");
    printf("\nchoice the mode you want ");
    scanf("%d",&choice);
    switch(choice){
   case ADMINMODE:
   while(TRUE){
  printf("Please , Enter the password:");
  scanf("%s",&std[i].pass_admain);
  if(strcmp(pass,std[i].pass_admain)==THE_SAME){
    printf("\t\t **ADMIN MODE**\n");
     Admin_Mode();
    break ;
  }
  else{
    printf("Wrong Password , try again!\n");
    i++;
  }
  if(i == MAX_ATTEMPT){
    printf("you try 3 attempts , can not try again\n");
    break;
    }
 }
    break ;
   case USERMODE  :
       User_Mode();
       }
    }
 }


/***************************************************************
@fn: Choice of List function of the program*********************
@brief: It gives you some options(previliges) if you are Admin *
@parameter:No parameter it is (void) datatype*******************
@return value: No return value (void)***************************
***************************************************************/

void Admin_Mode(){
 while(TRUE){
 printf("You have Seven Options:\n");
 printf("Press 1 for Add New Student\n");
 printf("Press 2 for Remove Student Record\n");
 printf("Press 3 for View Student record\n");
 printf("Press 4 for View all records\n");
 printf("Press 5 for Edit Admin Password\n");
 printf("Press 6 for Edit Student Grade\n");
 printf("Press 7 for Exit.\n");
 printf("Enter your choice:");
   int choice;
  do{
    scanf("%d", &choice);
    if(choice>=OPTION_ONE && choice<=OPTION_SEVEN){
        break;
		}
    else{
        printf("\n*Invalid Choice* ");
        printf("\nEnter Choice Here : ");
        }
      }while(TRUE);
   switch(choice){
   case OPTION_ONE :                                                                       //for Add New Student
       system("cls");
       Add_Student();
       system("cls");
       break ;
   case OPTION_TWO :                                                                       //for Remove Student Record
       RemoveStudentRecord();
       break;
   case OPTION_THREE :                                                                      //for View Student record
       View_Record();
       break ;
   case OPTION_FOUR :                                                                      //for view all records
       system("cls");
       View_All_Records();
       break;
   case OPTION_FIVE :                                                                      //for Edit Admin PassWord
       Edit_Admin_Password();
       break;
   case OPTION_SIX :                        			                                   //for Edit Student Grade
       EditStudentGrade();
       break;
   case OPTION_SEVEN :                                                               			  //For Exit
       system("cls");
       login();
       break;
   /*default :
       printf("Invalid ccChoice");*/
       }
    }
  }
/***************************************************************
@fn: Add_student function of the program************************
@brief: First option for The admin: It will add new student*****
@parameter:No parameter it is (void) datatype*******************
@return value: No return value (void)***************************
***************************************************************/

void Add_Student(){
   while(TRUE){
     do{
     printf("For get back press 00\n*** Select any ID U want except 00 ***\nEnter Student ID :");
     scanf("%d", &std[count].ID);
     if(std[count].ID == GET_BACK){
        Admin_Mode();
     }
        int s=0;
        for(int j=0; j < count; j++){
        if(std[count].ID==std[j].ID){
            s = NOT_UNIQUE;
            break;
               }
            }
       if(s == UNIQUE){
            break;
               }
       else{
          printf("This ID is ID Already Exist !\n");
          printf("Please Enter Different ID :\n");
           }
    }while(TRUE);
    printf("Enter The First Name :");
    scanf("%s",std[count].first_Name);
    printf("Enter The Last Name :");
    scanf("%s",std[count].last_Name);
    printf("Enter The Student Gender  :");
    scanf("%s",std[count].gender);
    printf("Enter The Student Age :");
    scanf("%d",&std[count].age);
    printf("Enter The Total Grade :");
    while(TRUE){
    scanf("%d",&std[count].total_grade);
    if(std[count].total_grade < INITIAL_GRADE || std[count].total_grade > MAX_GRADE ){
            printf("this is not valid number!!\n");
        }
        else
            break ;
    }
    printf("Enter the Student Password :");
    scanf("%s",std[count].password);
    printf("Success\n");
    count++;
     break;
        }
    }
/***************************************************************
@fn: RemoveStudentRecord function of the program****************
@brief: Second option for The admin: It will Remove student*****
@parameter:No parameter it is (void) datatype*******************
@return value: No return value (void)***************************
***************************************************************/
void RemoveStudentRecord(){
int i;
printf("For get back press 00\nPlease , enter the ID that you want to remove:");
scanf("%d",&i);
if(i == GET_BACK){
    Admin_Mode();
}
 for(int j=0; j < count; j++){
        if(i==std[j].ID){
          std[j].ID = Removed;
          break ;
        }
      }
   }
/***************************************************************
@fn: View_record function of the program************************
@brief: Third option for The admin: It will view records********
@parameter:No parameter it is (void) datatype*******************
@return value: No return value (void)***************************
***************************************************************/
void View_Record(){
    int check_id;
    system("cls");
    printf("For get back press 00\nEnter Student Id For Search : ");
    while(TRUE){
    scanf("%d",&check_id);
    if(check_id == GET_BACK){
       Admin_Mode();
    }
    int s=-1;
    for(int i=0;i<count;i++){
        if(check_id==std[i].ID){
            s=i;
            break;
                }
		}
    if(s == Removed){
          printf("There is no Record !\n");
          printf("Enter different ID :");
      }
    else{
          printf("\nStudent Information  ");
          printf("\nFirst Name   = %s",std[s].first_Name);
          printf("\nLast Name    = %s",std[s].last_Name);
          printf("\nID           = %d",std[s].ID);
          printf("\nAge          = %d",std[s].age);
          printf("\nGender       = %s",std[s].gender);
          printf("\nTotal Grade  = %d",std[s].total_grade);
          printf("\nPassword     = %s\n",std[s].password);
          break;
            }}
        }
/*****************************************************************************
@fn: View_all_record function of the program**********************************
@brief: fourth option for The admin: It will view all records after removing**
@parameter:No parameter it is (void) datatype*********************************
@return value: No return value (void)*****************************************
*****************************************************************************/

void View_All_Records(){
    int i;
 for( i =0; i<count;i++){
    if(std[i].ID == Removed){
        continue;
                     }
    else{
          printf("\nStudent Information");
          printf("\nFirst Name   = %s",std[i].first_Name);
          printf("\nLast Name    = %s",std[i].last_Name);
          printf("\nID           = %d",std[i].ID);
          printf("\nAge          = %d",std[i].age);
          printf("\nGender       = %s",std[i].gender);
          printf("\nTotal Grade  = %d",std[i].total_grade);
          printf("\nPassword     = %s\n",std[i].password);
        }
     }
   }
/*****************************************************************************
@fn: Edit_Admin_Password function of the program******************************
@brief: fifth option for The admin: It will change the password***************
@parameter:No parameter it is (void) datatype*********************************
@return value: No return value (void)*****************************************
*****************************************************************************/
void Edit_Admin_Password(){
    int i =0 ;
  while(TRUE){
    printf("For get back press 00\nFor confirm enter the current passworld:");
    scanf("%s",&std[i].pass_admain);
    if(strcmp("00",std[i].pass_admain) == THE_SAME){
       Admin_Mode();
    }
   if(strcmp(pass,std[i].pass_admain) == THE_SAME){
    printf("Now You can change it :\n");
    scanf("%s",&std[i].pass_admain);
    strcpy(pass,std[i].pass_admain);
    printf("%s",pass);
    system("cls");
    login();
    break ;
  }
    else{
     printf("Wrong Password , try again!\n");
         }
      }
   }
/*****************************************************************************
@fn: EditStudentGrade function of the program******************************
@brief: VI option for The admin: It will change the grade of student**********
@parameter:No parameter it is (void) datatype*********************************
@return value: No return value (void)*****************************************
*****************************************************************************/
void EditStudentGrade(){
    int check_id ;
    int i ;
    printf("For get back press 00\nEnter Student Id For Search : ");
    while(TRUE){
    scanf("%d",&check_id);
    if(check_id == GET_BACK){
       Admin_Mode();
    }
    int s=-1;
    for( i=0;i<count;i++){
        if(check_id == std[i].ID){
            s=i;
            break;
                }
              }
    if(s == Removed){
      printf("There is no Record !\n");
      printf("Enter different ID :");
      }
      else{
        printf("\nnew grade for student:");
        scanf("%d",&std[i].total_grade);
        break ;
          }}
        }
/*****************************************************************************
@fn: User_Mode function of the program****************************************
@brief: If you are user you can do that: 1- for View Your Record**************
                                         2- for Edit your Name****************
                                         3- for Edit Your Password************
@parameter:No parameter it is (void) datatype ********************************
@return value: No return value (void *****************************************
*****************************************************************************/
void User_Mode(){
           system("cls");
       while(TRUE){
         printf("\t\t** USER MODE **\n");
         printf("Press 1 for View Your Record.\n");
         printf("Press 2 for Edit your Name.\n");
         printf("Press 3 for Edit Your Password.\n");
         printf("Press 4 for Exit.\n");
         printf("Press the choice(order) you want :");
        int choice1 ;
        scanf("%d",&choice1);
        switch(choice1){

        case OPTION_ONE :                                //for View Your Record
                ViewRecord();
                break ;
        case OPTION_TWO :
                EditName();                             //for Edit your Name
                break ;
        case OPTION_THREE :                             //for Edit Your Password
                EditPassword();
                break ;
        case OPTION_FOUR :                             //for Exit
               login();
               break ;
        default :
               printf("Invalid Choice");
       }
     }
}


/*****************************************************************************
@fn: View Record function of the program**************************************
@brief: It will view record of student that admin entered*********************
@parameter:No parameter it is (void) datatype*********************************
@return value: No return value (void)*****************************************
*****************************************************************************/
void ViewRecord(){
    int check_id;
    system("cls");
    printf("For get back press 00\nEnter Student Id For Search : ");
    while(TRUE){
    scanf("%d",&check_id);
    if(check_id == GET_BACK){
            User_Mode();
    }
    int s=-1;
    for(int i=0;i<count;i++){
        if(check_id == std[i].ID){
            s=i;
            break;
                }
              }
    if(s == Removed){
      printf("There is no Record !\n");
      printf("Enter different ID :");
      }
    else{
          printf("\nStudent Information  ");
          printf("\nFirst Name   = %s",std[s].first_Name);
          printf("\nLast Name    = %s",std[s].last_Name);
          printf("\nID           = %d",std[s].ID);
          printf("\nAge          = %d",std[s].age);
          printf("\nGender       = %s",std[s].gender);
          printf("\nTotal Grade  = %d",std[s].total_grade);
          printf("\nPassword     = %s\n",std[s].password);
          break ;
          }}
        }


/*****************************************************************************
@fn: EditName function of the program*****************************************
@brief: It will edit the name that admin entered******************************
@parameter:No parameter it is (void) datatype*********************************
@return value: No return value (void)*****************************************
*****************************************************************************/
void EditName(){
    int check_id;
    char nname[NUM_ARR];
    system("cls");
    printf("For get back press 00\nEnter Student Id For Search : ");
    while(TRUE){
    scanf("%d",&check_id);
    if(check_id== GET_BACK){
        User_Mode();
    }
    int s=-1;
    for(int i=0;i<count;i++)
    {
        if(check_id==std[i].ID)
        {
            s=i;
            break;
         }}
    if(s == Removed)
    {
      printf("There is no Record!\n");
       printf("Enter different ID :");
      }
    else{
        fflush(stdin);
        printf("Enter The First Name:");
        gets(std[s].first_Name);
        printf("Enter The Last Name:");
        gets(std[s].last_Name);
        fflush(stdin);
        break ;
      }
    }}

/*************************************************************************
@fn: EditPassword function of the program*********************************
@brief: It will edit the Password of student******************************
@parameter:No parameter it is (void) datatype*****************************
@return value: No return value (void)*************************************
*************************************************************************/
void EditPassword(){
int check_id;
    system("cls");
    printf("For get back press 00\nEnter Student Id For Search : ");
    while(TRUE){
    scanf("%d",&check_id);
    if(check_id == GET_BACK){
        User_Mode();
    }
    int s=-1;
    for(int i=0;i<count;i++){
        if(check_id == std[i].ID){
            s=i;
            break;
         }
    }
    if(s == Removed){
      printf("There is no Record !\n");
      printf("Enter different ID :");
      }
      else{
        printf("\nEnter the New Password:");
        scanf("%s",&std[s].password);
        break ;
      }}
     }
