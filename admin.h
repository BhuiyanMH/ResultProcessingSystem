#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include "vars.h"
#include "file.h"
#include "windowFunction.h"
#include "functions.h"


void loadUser( void )
{
    FILE *fp;
    fp=open_file_rb("Files/userAccount.txt");
    if(fread(userAcc,sizeof userAcc,1,fp)!=1)
    {
        gotoxy(88, 48);
        printf("Error");
        Sleep(1000);

        exit(1);
    }
    fclose(fp);
}

void showUserLogin()
{
    system("cls");
    SetColor(15);
    drawFMainWindow();
    showBelowBox();
    loadUser();
    gotoxy(66,5);
    SetColor(14);
    printf("...::: USER LOG-IN :::...");
    SetColor(15);
    drawRectangle(61, 10,106,14);
    drawRectangle(61, 15,106,19);
    drawRectangle(61, 20,106,24);
    drawRectangle(61, 25,106,29);
    drawRectangle(61, 30,106,34);
    SetColor(10);
    yc = 12;
    j=0;
    for(i=1; i<=5; i++)
    {

        gotoxy(66,yc);
        printf("[%d] ", i);

        if(userAcc[j].userName[0] != NULL)

            puts(userAcc[j].userName);

        else
            printf("User Not Added !");
        yc+=5;
        j++;

    }

    gotoxy( 88, 48 );
    while(1)
    {

        checkKey = getch();
        checkOption(checkKey);

        if( checkKey == '1' || checkKey == '2' || checkKey == '3' || checkKey == '4' || checkKey == '5')
            if(userAcc[checkKey - '1'].userName[0] != NULL)
                authenticateUser(checkKey);
            else
            {
                SetColor(4);
                gotoxy(70, 41);
                printf("Invalid User !! Try Another.");
                SetColor(15);
                gotoxy( 88, 48 );
            }

        else if( checkKey == 'b' || checkKey == 'B')
        {
            showMainMenu();
        }

        else
            continue;
    }

}

void addAccount()
{

    system("cls");
    SetColor(15);
    drawFMainWindow();
    showBelowBox();
    gotoxy(69,5);
    SetColor(14);
    printf("...::: ADD USER ACCOUNT :::...");
    SetColor(15);
    loadUser();
    while(1)
    {
        if(userAcc[numOfUser].userName[0] != NULL)
            numOfUser++;
        else
            break;
    }

    while(1)
    {
        if(numOfUser < 5)
        {
            drawRectangle(61, 15,106,21);
            drawRectangle(61, 23,106,29);
            SetColor(10);
            gotoxy( 63, 26 );
            printf("ENTER PASSWORD: ");
            gotoxy(63, 18);
            printf("ENTER USER NAME: ");
            gets(userAcc[numOfUser].userName);
            gotoxy(80, 26);
            gets(userAcc[numOfUser].userPass);

            gotoxy( 61,32);
            if(userAcc[numOfUser].userName[0] != NULL  && userAcc[numOfUser].userPass[0] != NULL)
                printf("Do You Want to Add this User? ( Y \\ N): ");
            else
            {
                SetColor(4);
                gotoxy( 66,32);
                printf("No User Name or Password Entered !! ");
                SetColor(15);
                Sleep(1000);
                numOfUser = 0;
                showAdministratorMenu();
            }


            gotoxy(88, 48);
            while(1)
            {
                checkKey = getch();
                checkOption(checkKey);
                if(checkKey == 'Y' || checkKey == 'y')
                {
                    fp=open_file_wb("Files/userAccount.txt");
                    if(fwrite(userAcc,sizeof userAcc,1,fp)!=1)
                    {
                        gotoxy(88, 48);
                        printf("Error");
                        Sleep(1000);
                        exit(1);
                    }
                    fclose(fp);

                    gotoxy(56,32);
                    printf("User Successfully Added. Do You Want to Add more? ( Y \\ N ):");
                    gotoxy(88,48);
                    while(1)
                    {
                        checkKey = getch();
                        checkOption(checkKey);
                        if( checkKey == 'Y' || checkKey == 'y')
                        {
                            numOfUser++;
                            addAccount();

                        }

                        else if(checkKey == 'n' || checkKey == 'N')
                        {
                            fp=open_file_wb("Files/userAccount.txt");
                            if(fwrite(userAcc,sizeof userAcc,1,fp)!=1)
                            {
                                gotoxy(88, 48);
                                printf("Error");
                                Sleep(1000);
                                exit(1);
                            }
                            fclose(fp);
                            numOfUser = 0;
                            showAdministratorMenu();
                        }

                    }

                }

                else if(checkKey == 'n' | checkKey == 'N')
                    showAdministratorMenu();
                else if(checkKey == 'b' || checkKey == 'B')
                    showAdministratorMenu();
                else
                    continue;
            }
        }
        else
        {
            SetColor(4);
            gotoxy(58, 25);
            printf("User List Is Full !! Delete Any User To Add New User.");
            SetColor(15);
            Sleep(1500);
            numOfUser = 0;
            showAdministratorMenu();
        }
    }
}
void deleteAccount()
{
    system("cls");
    loadUser();
    SetColor(15);
    drawFMainWindow();
    showBelowBox();
    gotoxy(67,5);
    SetColor(14);
    printf("...::: DELETE USER ACCOUNT :::...");
    SetColor(14);
    gotoxy(58, 8);
    printf("USER");
    gotoxy(100, 8);
    printf("PASSWORD");
    SetColor(15);

    ty = 10;
    for(loop_1 = 1; loop_1 <= 5; loop_1++)
    {
        drawRectangle(40, ty, 80, ty+4 );

        drawRectangle(85, ty, 125, ty+4 );
        ty+=5;
    }

    SetColor(10);
    tx = 46;
    ty = 12;
    for(loop_1 = 1; loop_1 <= 5; loop_1++)
    {
        gotoxy(tx, ty);
        printf("[%d] ", loop_1);
        if( userAcc[loop_1 - 1].userName[0] != NULL )
        {
            puts(userAcc[ loop_1 - 1 ].userName);
            gotoxy(90, ty);
            puts(userAcc[ loop_1 -1 ].userPass);
        }

        else
        {
            printf("User Not Registered");
            gotoxy(90, ty);
            printf("Invalid !");

        }
        ty+=5;
    }
    gotoxy( 88, 48 );

    while(1)
    {
        checkKey = getch();
        checkOption(checkKey);


        if( checkKey == '1' || checkKey == '2' || checkKey == '3' || checkKey == '4' || checkKey == '5')
        {
            SetColor(4);
            gotoxy( 73, 41);
            printf("Are You Sure? (Y / N)");
            gotoxy(88, 48);
            ch = getch();

            SetColor(15);

            if(ch == 'y' || ch == 'Y')
                swapUser(checkKey-'1');
            else if(ch == 'n' || ch == 'N')
                showAdministratorMenu();

        }

        else if( checkKey == 'b' || checkKey == 'B')
            showAdministratorMenu();

        else
            continue;
    }

}

void editSystem()
{
    system("cls");
    SetColor(15);
    drawFMainWindow();
    showBelowBox();
    loadUser();
    gotoxy(66,5);
    SetColor(14);
    printf("...::: EDIT RESULT SYSTEM :::...");
    SetColor(15);
    ty = 15;
    for(loop_1 = 1; loop_1 <= 4; loop_1++)
    {
        drawRectangle(40, ty, 80, ty+4 );

        drawRectangle(85, ty, 125, ty+4 );
        ty+=5;
    }

    SetColor(10);
    gotoxy(45, 17);
    printf("[1] FIRST SEMESTER");
    gotoxy(90, 17);
    printf("[2] SECOND SEMESTER");
    gotoxy(45, 22);
    printf("[3] THIRD SEMESTER");
    gotoxy(90, 22);
    printf("[4] FOURTH SEMESTER");
    gotoxy(45, 27);
    printf("[5] FIFTH SEMSETER");
    gotoxy(90, 27);
    printf("[6] SIXTH SEMESTER");
    gotoxy(45, 32);
    printf("[7] SEVENTH SEMESTER");
    gotoxy(90, 32);
    printf("[8] EIGHTH SEMSETER");
    SetColor(15);
    gotoxy(88, 48);
    checkKey = getch();
    checkOption(checkKey);



}

void processResult()
{

    system("cls");
    SetColor(15);
    drawFMainWindow();
    showBelowBox();
    loadUser();
    gotoxy(66,5);
    SetColor(14);
    printf("...::: PROCESS RESULT :::...");
    SetColor(15);
    drawRectangle(61, 10,106,14);
    drawRectangle(61, 15,106,19);
    drawRectangle(61, 20,106,24);
    drawRectangle(61, 25,106,29);
    SetColor(10);
    yc = 12;
    j=0;
    /*for(i=1; i<=5; i++)
    {

        gotoxy(66,yc);
        printf("[%d] ", i);

        if(userAcc[j].userName[0] != NULL)

            puts(userAcc[j].userName);

        else
            printf("User Not Added !");
        yc+=5;
        j++;

    }*/
    gotoxy(66, 12);
    printf("[1] ADD EXAMINEE");
    gotoxy(66, 17);
    printf("[2] ENTER CLASS TEST MARKS");
    gotoxy(66, 22);
    printf("[3] GENERATE CODE");
    gotoxy(66, 27);
    printf("[4] FINAL CALCULATION");

    gotoxy(88, 48);
    getch();
    /*while(1)
    {
        checkKey = getch();

        if(checkKey == '1')
        else if( checkKey == '2')
        else if( checkKey == '3')
        else if( checkKey == '4')

    } */

}

void updateResult()
{

}

void searchResult()
{

}

void changeUserPassword( int index )
{
    loadUser();
    system("cls");
    SetColor(15);
    int i;
    int j;
    drawFMainWindow();
    drawRectangle(61, 15,106,21);
    drawRectangle(61, 23,106,29);
    showBelowBox();
    gotoxy(68,5);
    SetColor(14);
    printf("...::: CHANGE USER PASSWORD :::...");
    SetColor(15);
    SetColor(10);
    gotoxy( 63, 26 );
    printf("CONFIRM NEW PASSWORD: ");
    gotoxy(63, 18);
    printf("ENTER NEW PASSWORD: ");
    i = pass_hider(entNewPass);
    gotoxy( 85, 26 );
    j = pass_hider(confNewPass);
    gotoxy(56, 32);

    if(confNewPass[0] == NULL || confNewPass[0] == NULL)
    {
        SetColor(4);
        gotoxy(73, 32);
        printf("No Password Entered !");
        SetColor(15);
        gotoxy(88, 48);
        Sleep(1000);
        showAdministratorMenu();
    }

    else if(!strcmp(entNewPass , confNewPass))
    {
        strcpy(userAcc[index].userPass, confNewPass);

        fp=open_file_wb("Files/userAccount.txt");
        if(fwrite(userAcc,sizeof userAcc,1,fp)!=1)
        {
            gotoxy(88, 48);
            printf("Error");
            Sleep(1000);
            exit(1);
        }
        fclose(fp);


        gotoxy(66, 32);
        printf("Password Successfully Changed !");
        Sleep(1000);
        showUserMenu();
    }

    else
    {
        SetColor(4);
        gotoxy(60, 32);
        printf("Password Doesn't Matched! Try Again !!! ( Y \\ N )");

    }
    gotoxy( 88, 48);

    while(1)
    {
        checkKey = getch();
        checkOption( checkKey );
        if(checkKey == 'y' || checkKey == 'Y')
            changeUserPassword( ulogin - 1 );
        else if(checkKey == 'N' || checkKey == 'n')
            showAdministratorMenu();
        else if( checkKey == 'B' || checkKey == 'b' )
            showUserMenu();
        else
            continue;


    }
}
void changeAddPassword()
{
    system("cls");
    SetColor(15);
    int i;
    int j;
    drawFMainWindow();
    drawRectangle(61, 15,106,21);
    drawRectangle(61, 23,106,29);
    showBelowBox();
    gotoxy(62,5);
    SetColor(14);
    printf("...::: CHANGE ADMINISTRATIVE PASSWORD :::...");
    SetColor(15);
    SetColor(10);
    gotoxy( 63, 26 );
    printf("CONFIRM NEW PASSWORD: ");
    gotoxy(63, 18);
    printf("ENTER NEW PASSWORD: ");
    i = pass_hider(entNewPass);
    gotoxy( 85, 26 );
    j = pass_hider(confNewPass);
    gotoxy(56, 32);

    if(confNewPass[0] == NULL || confNewPass[0] == NULL)
    {
        SetColor(4);
        gotoxy(73, 32);
        printf("No Password Entered !");
        SetColor(15);
        gotoxy(88, 48);
        Sleep(1000);
        showAdministratorMenu();
    }

    else if(!strcmp(entNewPass , confNewPass))
    {
        fp=open_file_wb("Files/passw.txt");
        if(fwrite(confNewPass,sizeof confNewPass,1,fp)!=1)
        {
            printf("Error");
            exit(1);
        }
        fclose(fp);
        gotoxy(66, 32);
        printf("Password Successfully Changed !");
    }

    else
    {
        SetColor(4);
        gotoxy(60, 32);
        printf("Password Doesn't Matched! Try Again !!! ( Y \\ N )");
    }
    gotoxy( 88, 48);

    while(1)
    {
        checkKey = getch();
        checkOption( checkKey );
        if(checkKey == 'y' || checkKey == 'Y')
            changeAddPassword();
        else if(checkKey == 'N' || checkKey == 'n')
            showAdministratorMenu();
        else if( checkKey == 'B' || checkKey == 'b' )
            showAdministratorMenu();
        else
            continue;

    }
}


void authenticateUser(char c)
{
    loadUser();
    SetColor(15);
    system("cls");
    drawFMainWindow();
    gotoxy(72,5);
    SetColor(14);
    printf("...::: AUTHENTICATE USER :::...");
    SetColor(15);
    drawRectangle(51, 20, 121, 25);
    gotoxy(56, 22);
    SetColor(10);
    printf("ENTER THE PASSWORD: ");

    num = pass_hider(pas);

    if(!strcmp(pas,userAcc[c-'1'].userPass))
    {

        ulogin=c - '0';
        alogin = 0;
        gotoxy(71, 27);
        SetColor(10);
        printf("  Successfully Logged in....           ");
        gotoxy(88, 48);
        Sleep(1000);
        showUserMenu();
    }
    else if(strcmp(pas, userAcc[ checkKey - '1'].userPass ))
    {
        int k;
        for(k=0; k<=i; k++)printf("\b \b");
        gotoxy( 71, 27 );
        SetColor(4);
        printf("Wrong password ! Try again? ( Y \\ N ):");

        while(1)
        {
            checkKey =getch();
            if( checkKey == 'Y ' || checkKey == 'y' )
            {

                gotoxy(71,27);
                printf("                                          ");
                authenticateUser(c);

            }

            else if ( checkKey == 'n' || checkKey == 'N')
                showLogin();
            else
                checkOption(checkKey);
        }
    }

}

void swapUser( int key )
{
    loadUser();

    for( loop_1=key; loop_1<4; loop_1++)
    {
        strcpy(userAcc[loop_1].userName, userAcc[loop_1+1].userName);
        strcpy(userAcc[loop_1].userPass, userAcc[loop_1+1].userPass);

    }
    userAcc[4].userName[0] = NULL;
    userAcc[4].userPass[0] = NULL;

    fp=open_file_wb("Files/userAccount.txt");
    if(fwrite(userAcc,sizeof userAcc,1,fp)!=1)
    {
        gotoxy(88, 48);
        printf("Error");
        Sleep(1000);
        exit(1);
    }
    fclose(fp);
    SetColor(10);
    gotoxy( 73, 41);
    printf("User Successfully Deleted !");
    SetColor(14);
    Sleep(1000);
    showAdministratorMenu();

}

void showAdministratorMenu()
{
    system("cls");
    SetColor(15);
    drawFMainWindow();
    showBelowBox();
    gotoxy(67,5);
    SetColor(14);
    printf("...::: ADMINISTRATOR MENU :::...");
    SetColor(15);
    drawRectangle(61, 10,106,14);
    drawRectangle(61, 15,106,19);
    drawRectangle(61, 20,106,24);
    drawRectangle(61, 25,106,29);
    drawRectangle(61, 30,106,34);
    drawRectangle(61, 35,106,39);
    SetColor(10);
    gotoxy(66,12);
    printf("[1] ADD USER ACCOUNT");
    gotoxy(66,17);
    printf("[2] DELETE USER ACCOUNT");
    gotoxy( 66, 22);
    printf("[3] EDIT RESULT SYSTEM");
    gotoxy( 66, 27);
    printf("[4] SEARCH RESULT");
    gotoxy(66, 32);
    printf("[5] CHANGE ADMINISTRATIVE PASSWORD");
    gotoxy(66, 37);
    printf("[6] LOG-OUT");
    gotoxy( 88, 48 );
    while(1)
    {

        checkKey = getch();
        checkOption(checkKey);

        if( checkKey == '1')
            addAccount();
        else if( checkKey == '2')
            deleteAccount();
        else if( checkKey == '3')
            editSystem();
        else if( checkKey == '4')
            showSearchResult();
        else if( checkKey == '5')
            changeAddPassword();
        else if( checkKey == '6')
        {
            gotoxy( 72,41);
            SetColor(4);
            printf("Are You Sure? (Y // N) ");
            SetColor(15);
            while(1)
            {
                gotoxy( 88, 48 );
                checkKey = getch();
                if( checkKey == 'y' || checkKey == 'Y')
                {
                    alogin = 0;
                    ulogin = 0;
                    showMainMenu();
                }
                else if(checkKey == 'n' || 'N')
                    showAdministratorMenu();
                else
                    continue;
            }

        }

        else if( checkKey == 'b' || checkKey == 'B')

            showMainMenu();

        else
            continue;
    }

}


void showUserMenu()
{

    system("cls");
    SetColor(15);
    drawFMainWindow();
    showBelowBox();
    gotoxy(66,5);
    SetColor(14);
    printf("...::: USER MENU :::...");
    SetColor(15);
    drawRectangle(61, 10,106,14);
    drawRectangle(61, 15,106,19);
    drawRectangle(61, 20,106,24);
    drawRectangle(61, 25,106,29);
    drawRectangle(61, 30,106,34);
    SetColor(10);
    gotoxy(66,12);
    printf("[1] CREATE NEW RESULT");
    gotoxy(66,17);
    printf("[2] UPDATE RESULT");
    gotoxy( 66, 22);
    printf("[3] SEARCH RESULT");
    gotoxy( 66, 27);
    printf("[4] CHANGE USER PASSWORD");
    gotoxy(66, 32);
    printf("[5] LOG-OUT");

    gotoxy( 88, 48 );
    while(1)
    {

        checkKey = getch();
        checkOption(checkKey);

        if( checkKey == '1')
            processResult();
        else if( checkKey == '2')
            updateResult();
        else if( checkKey == '3')
            showSearchResult();
        else if( checkKey == '4')
            changeUserPassword( ulogin -1 );
        else if(checkKey == '5')
        {
            gotoxy( 72,41);
            SetColor(4);
            printf("Are You Sure? (Y // N) ");
            SetColor(15);
            while(1)
            {
                gotoxy( 88, 48 );
                checkKey = getch();
                if( checkKey == 'y' || checkKey == 'Y')
                {
                    ulogin = 0;
                    showMainMenu();
                }
                else if(checkKey == 'n' || 'N')
                    showUserMenu();
                else
                    continue;
            }
        }

        else if( checkKey == 'b' || checkKey == 'B')
            showMainMenu();

        else
            continue;
    }

}
