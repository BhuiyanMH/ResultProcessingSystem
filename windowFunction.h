

COORD xy = {0,0};
void gotoxy (int x, int y)
{

    xy.X = x;
    xy.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}


void ClearConsoleToColors(int ForgC, int BackC)
{
    WORD wColor = ((BackC & 0x0F) << 5) + (ForgC & 0x0F);
    //Get the handle to the current output buffer...
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //This is used to reset the carat/cursor to the top left.
    COORD coord = {0, 0};
    //A return value... indicating how many chars were written
    //   not used but we need to capture this since it will be
    //   written anyway (passing NULL causes an access violation).
    DWORD count;

    //This is a structure containing all of the console info
    // it is used here to find the size of the console.
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    //Here we will set the current color
    SetConsoleTextAttribute(hStdOut, wColor);

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //This fills the buffer with a given character (in this case 32=space).
        FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

        FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
        //This will set our cursor position for the next print statement.
        SetConsoleCursorPosition(hStdOut, coord);
    }
    return;
}

void SetColorAndBackground(int ForgC, int BackC)
{
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
    return;
}

void check_keyboard(int num, int maxOption)
{
    if(num == 80 || num == 77)
    {
        menu++;
        if(menu > maxOption)
        {
            menu = 1;
            printf("\a");
        }
    }
    else if(num == 72 || num == 75)
    {
        menu--;
        if(menu < 1)
        {
            menu = maxOption;
            printf("\a");
        }
    }
}

void drawRectangle(int x1, int y1, int x2, int y2)
{
    int i, j;
    gotoxy(x1,y1);
    printf("%c",201);
    for(i = x1; i < x2; i++)
    {
        gotoxy(i+1, y1);
        printf("%c",205);
    }
    gotoxy(x2,y1);
    printf("%c",187);
    for(i = y1; i < y2; i++)
    {
        gotoxy(x2, i+1);
        printf("%c",186);
    }
    gotoxy(x2, y2);
    printf("%c",188);
    for(i = x2; i > x1; i--)
    {
        gotoxy(i-1,y2);
        printf("%c",205);
    }
    gotoxy(x1,y2);
    printf("%c",200);
    for(i = y2; i > y1+1; i--)
    {
        gotoxy(x1,i-1);
        printf("%c",186);
    }
    gotoxy(x1,y2+1);
}

void drawHLine(int sx, int sy, int tx)
{
    gotoxy(sx, sy );
    for(xc = sx; xc <= tx; xc++)
    {
        printf("\xB2");
        Sleep(10);
    }


}
void drawFHLine(int sx, int sy, int tx)
{
    gotoxy(sx, sy );
    for(xc = sx; xc <= tx; xc++)
        printf("\xB2");
}

void drawTHLine(int sx, int sy, int tx)
{
    gotoxy(sx, sy );
    for(xc = sx; xc <= tx; xc++)
    {
        printf("%c", 95);
    }

}

void drawVLine(int sx, int sy, int ty)
{

    for(yc = sy; yc <= ty; yc++)
    {
        gotoxy( sx, sy );
        printf("\xB2");
        Sleep(10);
        sy++;
    }

}

void drawFVLine(int sx, int sy, int ty)
{

    for(yc = sy; yc <= ty; yc++)
    {
        gotoxy( sx, sy );
        printf("\xB2");
        sy++;
    }

}

void drawTVLine(int sx, int sy, int ty)
{

    for(yc = sy; yc <= ty; yc++)
    {
        gotoxy( sx, sy );
        printf("%c", 179);
        sy++;
    }

}



void SetColor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

void drawCLine(int sx, int sy, int tx)
{
    for(i=sx; i < tx ; i++,sy++)
    {
        gotoxy(i,sy);
        printf("\xB2");
    }
}

void checkOption(char isMe)
{
    if(isMe == 'M' || isMe == 'm')
        showMainMenu();
    if( isMe == 'E' || isMe == 'e')
    {
        gotoxy(2, 51);
        exit(0);
    }
}

int yesNo()
{
    SetColor(4);
    gotoxy( 73, 41);
    printf("Are You Sure? (Y / N)");
    gotoxy(88, 48);
    ch = getch();

    SetColor(15);

    if(ch == 'y' || ch == 'Y')
        return 1;
    else if(ch == 'n' || ch == 'N')
        return 0;
    else
        return;

}

