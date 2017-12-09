int ulogin = 0, alogin = 0;
char ch;
char pas[100], password[100], entNewPass[100], confNewPass[100];
char userName[30], userPassword[30];
FILE *sl, *fp;
int lx = 6, ly = 9, xc, loop =0, sleep = 0, yc, num, tx, ty, loop_1, loop_2;
int i = 0, j = 0;
int numOfUser = 0;
char checkKey;
int menu = 1, maxOption;
char userAccount[5][2][40];

struct account
{
    char userName[30];
    char userPass[30];
};
struct account userAcc[5];


