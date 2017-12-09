#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE* open_file_r(char *s)
{
    FILE *fp;
    if((fp=fopen(s,"r"))==NULL)
    {
        printf("can't open file\n");
        exit(1);
    }
    return fp;
}
void read_file(FILE *fp)
{
    while(!feof(fp))
    {
        char ch;
        ch=fgetc(fp);
        if(ferror(fp))
        {
            printf("File error");
            break;
        }
        putchar(ch);
    }
}
FILE* open_file_w(char *s)
{
    FILE *fp;
    if((fp=fopen(s,"w"))==NULL)
    {
        printf("can't open file\n");
        exit(1);
    }
    return fp;
}
FILE* open_file_a(char *s)
{
    FILE *fp;
    if((fp=fopen(s,"a"))==NULL)
    {
        printf("can't open file\n");
        exit(1);
    }
    return fp;
}
FILE* open_file_rb(char *s)
{
    FILE *fp;
    if((fp=fopen(s,"rb"))==NULL)
    {
        printf("can't open file\n");
        exit(1);
    }
    return fp;
}
FILE* open_file_wb(char *s)
{
    FILE *fp;
    if((fp=fopen(s,"wb"))==NULL)
    {
        printf("can't open file\n");
        exit(1);
    }
    return fp;
}
FILE* open_file_ab(char *s)
{
    FILE *fp;
    if((fp=fopen(s,"r"))==NULL)
    {
        printf("can't open file\n");
        exit(1);
    }
    return fp;
}
void load_password(void)
{
    FILE *fp;
    fp=open_file_rb("Files/passw.txt");
    if(fread(password,sizeof password,1,fp)!=1)
    {
        printf("Error");
        exit(1);
    }
    fclose(fp);
    //printf("%s",password);

}

void pass(void)
{
    load_password();
    gotoxy(68,5);
    SetColor(14);
    printf("...::: ADMINISTRATOR LOG-IN :::...");
    SetColor(15);
    drawRectangle(51, 20, 121, 25);
    gotoxy(56, 22);
    SetColor(10);
    printf("ENTER THE PASSWORD: ");
    int i;
    i=pass_hider(pas);

    if(!strcmp(pas,password))
    {

        alogin=1;
        gotoxy(71, 27);
        SetColor(10);
        printf("  Successfully Logged in....           ");
        gotoxy(88, 48);
        Sleep(1000);
        ulogin = 0;
        showAdministratorMenu();
    }
    else if(strcmp(pas, password))
    {
        int k;
        for(k=0; k<=i; k++)printf("\b \b");
        gotoxy( 71, 27 );
        SetColor(4);
        printf("Wrong password ! Try again? ( Y \\ N ):");
        //gotoxy(88, 48);

        while(1)
        {
            checkKey =getch();
            if( checkKey == 'Y ' || checkKey == 'y' )
            {

                gotoxy(71,27);
                printf("                                          ");
                pass();

            }

            else if ( checkKey == 'n' || checkKey == 'N')
                showLogin();
            else
                checkOption(checkKey);
        }
    }


}

void create_pass(void)
{
    printf("ENTER THE EXISTING PASSWORD: ");
    int i;
    i=pass_hider(pas);
    if(!strcmp(pas,password))
    {


        int j;
        system("cls");
        SetColor(15);
        drawFMainWindow();
        //gotoxy(10, 10);
        SetColor(14);
        drawRectangle(56,15,111,20);
        gotoxy(61,17);
        printf("ENTER NEW PASSWORD: ");
        j=pass_hider(pas);
        FILE *fp;
        fp=open_file_wb("passw");
        if(fwrite(pas,sizeof pas,1,fp)!=1)
        {
            printf("Error");
            exit(1);
        }
        fclose(fp);
        //system("cls");
        strcpy(password,pas);
        gotoxy(62,22);
        printf("Password Has Been Changed Successfully\n");

    }
    else
    {
        int k;
        for(k=0; k<=i; k++)printf("\b \b");
        gotoxy(61,22);

        printf("Wrong Password.Try again\n");
        strcpy(pas,"");
        gotoxy(61,17);
        create_pass();
    }

}
int pass_hider(char *p)
{
    char ch;
    int i=0,k;
    while((ch=getch())!='\r')
    {
        if(ch!='\b')
        {
            p[i++]=ch;
            printf("*");
        }
        else if(ch=='\b'&&i)
        {
            printf("\b \b");
            p[--i]='\0';

        }
    }
    p[i]='\0';
    return i-1;
}

#endif // FILE_H_INCLUDED


