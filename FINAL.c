#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
int header(void);
void records(void);
void up_pass(void);
void read(void);
void searching(void);
void Delete(void);
void write(void);
void edit(void);
void back_to_main(void);
void about(void);
int login_sys(void);

//===============STRUCTURE FOR LOGIN==================

struct login {
    char name[20],pass[10];
};

//===============STRUCTURE OF STUDENT==================

struct student{
    int studentid;
    char name[25],address[20];
        };

//================GOTO_X_Y FUNCTION=====================

void gotoxy(int x, int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

//=====================MAIN FUNCTION======================

int main()
{
    if(login_sys()==1){
        printf("Login !! Successfully Welcome");
        back_to_main();
                }
    else{
        printf("Error !! USER or PASSWORD Incorrect\n\n");
        }
    return 0;
    getch();
}

//===============HEADER SECTION DEFINITION================

int header(void)
{
    int a;
    printf("\n\nADMIN_PANNEL_OF_STUDENT_MANAGEMENT_SYSTEM\n");
    printf("1. View Records\n");
    printf("2. Update Password\n");
    printf("3. About\n");
    printf("0. Exit\n");
    printf("Enter your option:> ");
    scanf("%d",&a);
    system("cls");
    return a;
}


//=======VIEW RECORDS(STUDENT INFO,ADD,EDIT,DELETE)=========


int header1(void)
{
  int b;
    printf("You are in STUDENT SECTION");
    printf("\n\nVIEW RECORDS\n");
    printf("1. Info Student\n");
    printf("2. Search Student\n");
    printf("3. Add Student\n");
    printf("4. Edit Student\n");
    printf("5. Delete Student\n");
    printf("0. Back To Main\n\n");
    printf("Enter your option:> ");
    scanf("%d",&b);
    system("cls");
    return b;
}
void records(void)
{
    while(1){
        switch(header1())
        {
    case 1:
        read();
        break;
    case 2:
        searching();
        break;
    case 3:
        write();
        break;
    case 4:
        edit();
        break;
    case 5:
        Delete();
        break;
    case 0:
        back_to_main();
        break;
    default:
        printf("Error !! Please Enter Valid Option\n\n");
        exit(0);
        }
        printf("\n\nPress any key to continue . . . .");
        _getch();
        system("cls");
    }
}


//====================BACK TO MAIN======================

void back_to_main(void)
{
    while(1){
    switch(header())
     {
     case 0:
         printf("Your Program Successfully !! exit . . .\n\n");
        exit(0);
     case 1:
        records();
        break;
     case 2:
        up_pass();
        break;
     case 3:
        about();
        break;
     default:
        printf("Error !! Please ENTER valid Option . . .");
        exit(0);
     }
      printf("\n\nPress any key to continue . . . .");
        _getch();
        system("cls");
        }
}


//==================READ STUDENT INFO====================

void read(void)
{
    FILE *fp;
    struct student s1;
    fp=fopen("stdRecords.txt","r");
    if(fp == NULL){
        printf("Error !! your file doesn't exit");
    }
     while(fread(&s1,sizeof(s1),1,fp)>0){
    printf("%d\t",s1.studentid);
    printf("%s\t",s1.name);
    printf("%s \n",s1.address);
    }
    fclose(fp);
}

//===================ADD STUDENT INFO====================

void write(void)
{
     FILE *fp;
    struct student s1;
    fp=fopen("stdRecords.txt","a");

    printf("\nEnter the following information\n");

    printf("Student Id:> ");
    scanf("%d",&s1.studentid);

    printf("Student Name:> ");
    fflush(stdin);
    gets(s1.name);

    printf("student Address:> ");
     fflush(stdin);
    gets(s1.address);

    fwrite(&s1,sizeof(s1),1,fp);

    printf("Successfully recorded");
    fclose(fp);
    printf("\n\nDo you want to Record again !! then press 'y' Or 'Y'");
    if(_getch()=='y' || _getch()=='Y')
    {
        system("cls");
        write();
    }
}

//===================EDIT STUDENT INFO================

void edit(void)
{
    printf("\n\n This option available SOON !!! . . .");
}

//===================DELETE STUDENT INFO=================

void Delete(void)
{

    printf("\n\n This option available SOON !!! . . .");
}

//==================SEARCHING STUDENT INFO==============

void searching(void)
{
    FILE *fp;
    struct student s1;
    fp=fopen("stdRecords.txt","r");
    if(fp==NULL)
    {
        printf("Your file does not exits");
        exit(0);
    }
    printf("\n\nEnter the following information\n");
    printf("Enter the id: ");
    scanf("%d",&s1.studentid);
    fseek(fp,(s1.studentid-1)*sizeof(s1),0);
    if(fread(&s1,sizeof(s1),1,fp)==1){
    printf("\nSuccessful !! Record found \n");
    printf("Student Id      = %d\n",s1.studentid);
    printf("Student name    = %s\n",s1.name);
    printf("Student address = %s\n",s1.address);
    fclose(fp);
    printf("\n\nPRESS 'y' or 'Y' to search again !!");
    if(_getch()=='y' || _getch()=='Y'){
        searching();
    }
    }
    else
    {
    printf("\nThis DATA does not exist in the file");
    }
}

//====================ABOUT PROGRAM=====================

void about(void)
{
    printf("\nABOUT\n\n");
     printf("DEVELOPER:- Bhabin_Buduja_Pun\n");
     printf("VERSION  :- 0.0.1 Version\n");
     printf("GITHUB   :- github.com/bhabinpun\n");
     printf("LINKEDIN :- linkedin.com/in/bhabin/\n");
}


//===================UPDATE PASSWORD====================

void up_pass(void)
{
    int a;
    char name[20],pass[15];
     FILE *fp;
    struct login a1;
    fp=fopen("password.txt","w");

    printf("Enter Nes User name and Password\n");
    printf("User    : ");
        fflush(stdin);
    gets(a1.name);

    printf("Password: ");
        fflush(stdin);
    gets(a1.pass);

    fprintf(fp,"%s %s",a1.name,a1.pass);

    printf("Successfully !! USER_NAME and PASSWORD has been recorded. . . .");
    fclose(fp);

    printf("\n\nWhat do your want !!\n");
    printf("1.Logout\n");
    printf("2.Stay Login\n");
    printf("Option: ");
    scanf("%d",&a);
    while(1)
    {
        switch(a)
        {
        case 1:
            system("cls");
            printf("\n\nLogin\n");
        printf("User    : ");
        fflush(stdin);
        gets(name);
        printf("Password: ");
        gets(pass);
        fscanf(fp,"%s",a1.name);
        fscanf(fp,"%s",a1.pass);
        if(strcmp(name,a1.name)==0 && strcmp(pass,a1.pass)==0){
            printf("\n\nSuccessfully !! login with User and Password\n");
            back_to_main();
        }
        else{
            printf("\n\nEnter valid User OR Password");
            exit(0);
        }
        fclose(fp);
            break;
        case 2:
            //printf("")
            back_to_main();
            break;
        default:
            printf("Please ENTER valid option");
            exit(0);
        }
    }

}

//=====================LOGIN SECTION=====================

int login_sys(void)
{
        struct login a1;
        char pass[15],name[20];
        FILE *fp;
        fp=fopen("password.txt","r");
        if(fp==NULL){
            printf("Your file does not exist");
            exit(0);
        }
        printf("Login\n");
        printf("User    : ");
        fflush(stdin);
        gets(name);
        printf("Password: ");
        gets(pass);
        fscanf(fp,"%s",a1.name);
        fscanf(fp,"%s",a1.pass);
        if(strcmp(name,a1.name)==0 && strcmp(pass,a1.pass)==0){
            return 1;
        }
        else{
            return 0;
        }
        fclose(fp);
}
