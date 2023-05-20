#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

struct Students {
   char first_Name[100];
   char last_Name[100];
   int age ;
   int total_grade ;
   int ID ;
   char gender[10];
   char password[100];
   char pass_admain[100];
};
struct Students std[1000];
int count = 0 ;
char pass[]="1234";
void login ();
void Admin_Mode();
void add_student();
void RemoveStudentRecord();
void View_record();
void View_all_Records();
void Edit_admin_Password();
void EditStudentGrade();
void User_Mode();
void View();
void editname();
void editPassword();
#endif // STUDENT_H_INCLUDED
