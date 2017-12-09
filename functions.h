
void drawMainWindow( void )
{
    //Draw main Window
    drawHLine( 2, 2, 162 );
    drawVLine( 2, 2, 50 );
    drawVLine( 162, 2, 50 );
    drawHLine( 2, 50, 162 );
}

void drawFMainWindow( void )
{
    //Draw main Window
    drawFHLine( 2, 2, 162 );
    drawFVLine( 2, 2, 50 );
    drawFVLine( 162, 2, 50 );
    drawFHLine( 2, 50, 162 );

}

void showBelowBox()
{
    SetColor(15);
    drawRectangle( 56, 43, 111, 47);
    drawTVLine(75,44,46);
    drawTVLine(93,44,46);

    SetColor(10);
    gotoxy(59,45);
    printf("<-- [B] BACK");
    gotoxy(79,45);
    printf("[M] MAIN MENU");
    gotoxy(99,45);
    SetColor(4);
    printf("[E] EXIT");
    SetColor(15);
    gotoxy(79,48);
    SetColor(4);
    printf("COMMAND: ");

}

void showMainBox()
{
    SetColor(15);
    drawRectangle( 56, 43, 111, 47);
    drawTVLine(84,44,46);

    SetColor(10);
    gotoxy( 64,45 );
    printf("[M] MAIN MENU");
    gotoxy( 94,45);
    SetColor(4);
    printf("[E] EXIT");

    gotoxy(79,48);
    SetColor(4);
    printf("COMMAND: ");

}

void showHLogin()
{
    system("cls");
    SetColor(15);
    drawFMainWindow();
    showBelowBox();
    SetColor(10);
    gotoxy (6 ,8 );
    printf("LOG-IN:");
    SetColor(15);
    gotoxy( 6, 9 );
    printf(" In this software any one can search and view result. To add or modify result he must login.");
    gotoxy( 6, 10);
    printf("After login he can search, add and modify result. He can also change the administrative password.");
    gotoxy( 6, 11 );
    printf("For the first time we have set a master password \"456\".");

    gotoxy(88, 48);
    while(1)
    {
        checkKey = getch();
        checkOption(checkKey);
        if(checkKey == 'b' || checkKey == 'B')
            showHelp();
        else
            continue;
    }
}

void showHSearchResult()
{
    system("cls");
    SetColor(15);
    //drawFMainWindow();
   // showBelowBox();
    SetColor(10);
   // gotoxy (6 ,8 );
    printf("\n\n\n\tSEARCH RESULT: ");
    SetColor(15);
    //gotoxy(6, 9);
    printf("\n\tAny one can search result by entering his  Session, Semester and Id No. He can only ");
   // gotoxy( 6, 10 );
    printf("view his result but he will not be able to update or modify his result!");
    printf("\n\tFor administrator and users, there is two search option. They can search by ID no for result of a specific student. There is another option, they can ");
    printf(" \n\talso view the result of all students of a semester by entering and session and semester No.");

    gotoxy(62, 48);
    while(1)
    {
        checkKey = getch();
        checkOption(checkKey);
        if(checkKey == 'b' || checkKey == 'B')
            showHelp();
        else
            continue;
    }

}

void showHUpdate()
{
    system("cls");
    SetColor(15);
    drawFMainWindow();
    showBelowBox();
    SetColor(10);
    gotoxy (6 ,8 );
    printf("UPDATE RESULT:");
    SetColor(15);
    gotoxy( 6, 9);
    printf("It is necessary to update result of a specific student because ");
    gotoxy( 6, 10 );
    printf("he may improve his result by attending improvement or supply examination.");

    gotoxy( 62, 48 );
    while(1)
    {
        checkKey = getch();
        checkOption(checkKey);
        if(checkKey == 'b' || checkKey == 'B')
            showHelp();
        else
            continue;
    }

}




void showMainMenu( void )
{

    system("cls");
    SetColor(15);
    drawFMainWindow();
    menu = 1;
    drawFHLine( 2, 8, 162 );
    drawRectangle( 66, 13, 101, 45);

    gotoxy( 69, 5);
    SetColor(14);
    //system("set term -bold on");
    printf("....::: Main Menu :::....");
    SetColor(15);

    //Show the main menu options
    while(1)
    {
        if( menu == 1 )
            SetColorAndBackground(4, 10);
        else
            SetColorAndBackground(15, 3);
        gotoxy(71, 24);
        printf("[1] SET PASSWORD OR LOG IN");

        if( menu == 2 )
            SetColorAndBackground(4, 10);
        else
            SetColorAndBackground(15, 3);
        gotoxy(71, 26);
        printf("[2] SEARCH RESULT");

        if( menu == 3 )
            SetColorAndBackground(4, 10);
        else
            SetColorAndBackground(15, 3);
        gotoxy(71, 28);
        printf("[3] HELP");

        if( menu == 4 )
            SetColorAndBackground(4, 10);
        else
            SetColorAndBackground(15, 3);
        gotoxy(71, 30);
        printf("[4] ABOUT");

        if( menu == 5 )
            SetColorAndBackground(15, 4);
        else
            SetColorAndBackground(15, 3);
        gotoxy(71, 32);
        printf("[E] EXIT");
        SetColorAndBackground(15, 3);

        gotoxy(81, 51);
        checkKey = getch();
        check_keyboard(( int ) checkKey, 5);

        if(((int)(checkKey == 13) && menu == 1) || checkKey == '1')
            showLogin();
        else if(((int)(checkKey == 13) && menu == 2) || checkKey == '2')
            showSearchResult();
        else if(((int)(checkKey == 13) && menu == 3) || checkKey == '3')
            showHelp();
        else if(((int)(checkKey == 13) && menu == 4) || checkKey == '4')
            showAbout();
        else if(((int)(checkKey == 13) && menu == 5) || checkKey == 'E' || checkKey == 'e')
            exit(0);
    }
}


void showLogin(void)
{
    system("cls");
    SetColor(15);
    drawFMainWindow();
    showMainBox();
    gotoxy(75,5);
    SetColor(14);
    printf("...::: LOG-IN :::...");
    SetColor(15);
    drawRectangle( 56, 14, 111, 20);
    drawRectangle( 56, 22, 111, 28);
    //drawTVLine(57,23,27);
    SetColor(10);
    gotoxy( 76, 17);
    printf("[U] USER LOG-IN");
    gotoxy( 72, 25);
    printf("[A] ADMINISTRATOR LOG-IN");

    gotoxy(88, 48);
    while(1)
    {
        checkKey = getch();
        checkOption(checkKey);
        if( checkKey == 'a' || checkKey == 'A')
        {
            if( alogin == 1 )
                showAdministratorMenu();
            else
            {
                system("cls");
                SetColor(15);
                drawFMainWindow();
                showBelowBox();
                pass();
            }


        }

        else if( checkKey == 'u' || checkKey == 'U')
            {
                if( ulogin == 1 )
                    showUserMenu();
                else
                    showUserLogin();
            }

        else
            continue;

    }

}

void showSearchResult(void)
{
    system("cls");
    SetColor(15);
    drawFMainWindow();
    drawRectangle(61, 15,106,21);
    drawRectangle(61, 23,106,29);
    showBelowBox();
    gotoxy(70,5);
    SetColor(14);
    printf("...::: SEARCH RESULT :::...");

    while(1)
    {
        checkKey = getch();
        checkOption(checkKey);
    }



}

void showHelp()
{
    system("cls");
    menu = 1;
    SetColorAndBackground( 15, 3 );
    drawFMainWindow();
    drawRectangle( 66, 10, 101, 29);
    gotoxy(71,5);
    SetColor(14);
    printf("...::: HELP MENU :::...");
    SetColor(15);

    while(1)
    {

        if( menu == 1 )
            SetColorAndBackground(4, 10);
        else
            SetColorAndBackground(15, 3);
        gotoxy(71, 16);
        printf("[1] ADMINISTRATION & USER ");

        if( menu == 2 )
            SetColorAndBackground(4, 10);
        else
            SetColorAndBackground(15, 3);
        gotoxy(71, 20);
        printf("[2] SEARCH RESULT");

        if( menu == 3 )
            SetColorAndBackground(4, 10);
        else
            SetColorAndBackground(15, 3);
        gotoxy(71, 24);
        printf("[3] ADD & UPDATE RESULT");
        SetColorAndBackground(15, 3);

        SetColor(3);
        showMainBox();

        checkKey = getch();
        check_keyboard(( int ) checkKey, 3);
        checkOption(checkKey);

        if(((int)(checkKey == 13) && menu == 1) || checkKey == '1')
            showHLogin();
        else if(((int)(checkKey == 13) && menu == 2) || checkKey == '2')
            showHSearchResult();
        else if(((int)(checkKey == 13) && menu == 3) || checkKey == '3')
            showHUpdate();

    }

}
void showAbout(void )
{
    system("cls");
    drawFMainWindow();
    showMainBox();
    SetColor(14);
    gotoxy( 68, 5 );
    printf("....::: ABOUT :::....");
    gotoxy(32,10);
    printf("1. Mahmudul Hasan Bhuiyan\t\t\t2. Sabbir Ahmed\t\t\t\t3. Michel Das");
    gotoxy(32, 12);
    printf("ID: 13701005\t\t\t\t\tID: 13701015\t\t\t\tID: 13701016");
    //gotoxy(32, 13);
   // printf("mdmahmudulhasan4@gmail.com\t\t\t");
    gotoxy(32, 16);
    printf("4. Tonmoy Biswas\t\t\t\t5. Sourav Barua\t\t\t\t6. Hafizur Rahman");
    gotoxy(32, 18);
    printf("ID: 13701059\t\t\t\t\tID: 13701072\t\t\t\tID:13701080");
    SetColor(4);
    gotoxy( 64, 26 );
    printf("....::: PROJECT SUPERVISOR :::....");
    SetColor(10);
    gotoxy(68, 28);
    printf("Dr. Mohammad Khairul Islam");
    gotoxy(72,30);
    printf("Associate Professor");
    gotoxy( 60, 32);
    printf("Department of Computer Science & Engineering");
    gotoxy( 70, 34);
    printf("University of Chittagong");

    gotoxy(88, 48);

    while(1)
    {
        checkKey = getch();
        checkOption(checkKey);
    }

}

void showWelcome( void )
{
    SetColor(14);
    drawFMainWindow();

    SetColor(10);

    //Draw W
    drawFVLine( 32, 10 , 40);
    drawFHLine( 32, 40, 38);
    drawFVLine( 39, 25, 40);
    drawFHLine( 40, 40, 46 );
    drawFVLine( 46, 10 , 40);

    //draw E
    drawFVLine( 49, 10 , 40);
    drawFHLine( 49, 40, 58);
    gotoxy(23, 25);
    drawFHLine(49, 25, 56);
    gotoxy(17, 10);
    drawFHLine(49, 10, 58);

    //Draw L
    drawFVLine( 61, 10, 40);
    drawFHLine(61, 40, 71);

    //draw C
    drawFHLine( 74, 10, 83);
    drawFVLine( 83, 10, 12);
    drawFVLine( 74, 10, 40);
    drawFHLine( 74, 40, 83);

    //draw o
    drawFHLine( 86, 10, 97);
    drawFVLine( 86, 10, 40);
    drawFHLine( 86, 40, 97);
    drawFVLine( 97, 10, 40);

    //draw M
    drawFVLine( 100, 10, 40 );
    drawFHLine( 100, 10, 107 );
    drawFVLine( 108, 10, 25 );
    drawFHLine( 109, 10, 116 );
    drawFVLine( 116, 10, 40 );

    //draw E
    drawFVLine( 119, 10 , 40);
    drawFHLine( 119, 40, 131);
    gotoxy( 119, 25);
    drawFHLine(119, 25, 129);
    drawFHLine( 119, 10, 131);
    gotoxy(110,51);

    gotoxy(82, 52);
    Sleep(1000);
    //getch();

    system("cls");
    SetColor(15);

}

void showLoading( void )
{
    SetColor(15);
    drawMainWindow();
    gotoxy(32,6);
    SetColor(14);
    printf("\t\t   RESULT\t\t\t  PROCESSING\t\t\t    SOFTWARE\n");
    SetColor(10);

    sl = fopen("Files/Logo.txt", "r");
    gotoxy(36,9);
    while(!feof(sl))
    {
        char ch;
        ch=fgetc(sl);
        if(ch == '\n')
        {
            ly++;
            gotoxy(36,ly);
        }
        else
            putchar(ch);
    }

    fclose(sl);
    gotoxy( 74, 43 );
    SetColor(14);
    printf("LOADING FILES.....");
    SetColor(15);
    drawRectangle(5,44,157,46);
    gotoxy(6,45);
    sleep = 200;
    SetColor(4);
    for(loop = 0; loop <= 150; loop++)
    {
        printf("\xB2");
        Sleep(sleep);

        if( sleep >= 25 )
            sleep-=4;
    }

    gotoxy(72,47);
    SetColor(14);
    printf("LOADING COMPLEATE....");
    //getch();
    Sleep(1000);
    SetColor(15);
    system("cls");

}








