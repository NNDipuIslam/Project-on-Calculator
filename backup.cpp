#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
void showptr();
void getmousepos(int *,int*,int*);
int button,x,y,x1,y1,x2,y2,s;
long double num=0,get,num1=0,result=0,ze=0;
long double addnum(long double);
long double subnum(long double);
long double sqrt_chk(long double);
long double Lon(long double );
long double power(long double );
long double Log(long double );
long double zero(long double);
long double factorial(long double);
long double point(long double,long double);
void page1();
void page2();
void calculator1();
void calculator2();
char opr;
long double a,b,r,i1,count,c,sq,newnum=1,d=0,chk=0,ans=0,chk1=0,Final=0;
int DR=0,on=0,page=1;
union REGS i,o;
char ar[8][5];
void calculator1()
{
    cleardevice();
    char* arr[8][5]= {"1st","2nd","Exit","D/R","ON",
                      "sqrt","x^2","x^a","Log","Ln",
                      "(-)","x^-1","Sinh","Cosh","Tanh",
                      "%","Pi","Sin","Cos","Tan"
                     };
    char* arr1[4][5]= {"7","8","9","DEL","AC",
                       "4","5","6","*","/",
                       "1","2","3","+","-",
                       "0",".","Exp","Ans","="
                      };
    setfillstyle(1,3);
    bar(236,435,447,150);
    setcolor(WHITE);
    rectangle(236,149,447,40);
    rectangle(237,148,446,41);
    rectangle(238,147,445,42);
    c=240;

    d=152;

    s=0;

    for(a=0; a<4; a++)
    {
        c=240;
        for(b=0; b<5; b++)
        {
            setfillstyle(1,24);
            bar(c,d,c+35,d+30);
            setcolor(BLACK);
            outtextxy(c+5,d+14,arr[a][b]);
            c+=42;

        }
        d+=35;
    }
    d+=4;
    for(a=0; a<4; a++)
    {
        c=240;
        for(b=0; b<5; b++)
        {
            if(a==0 &&(b==3 ||b==4))
            {
                setfillstyle(1,YELLOW);
            }
            else  setfillstyle(1,BLACK);
            bar(c,d,c+35,d+30);
            if(a==0 &&(b==3 || b==4))
            {
                setcolor(BLACK);
            }
            else
                setcolor(YELLOW);
            outtextxy(c+10,d+14,arr1[a][b]);
            c+=42;

        }
        d+=35;
    }
    page=1;
}
void calculator2()
{
    cleardevice();
    char* arr[8][5]= {"1st","2nd","Exit","D/R","ON",
                      "sqrt","x^3","x^a","10^a","e^a",
                      "(-)","x!","Csch","Sech","Coth",
                      "%","Pi","SinI","CosI","TanI"
                     };
    char* arr1[4][5]= {"7","8","9","DEL","AC",
                       "4","5","6","*","/",
                       "1","2","3","+","-",
                       "0",".","Exp","Ans","="
                      };
    setfillstyle(1,3);
    bar(236,442,447,150);
    setcolor(WHITE);
    rectangle(236,149,447,40);
    rectangle(237,148,446,41);
    rectangle(238,147,445,42);
    c=240;

    d=152;

    s=0;

    for(a=0; a<4; a++)
    {
        c=240;
        for(b=0; b<5; b++)
        {
            setfillstyle(1,24);
            bar(c,d,c+35,d+30);
            setcolor(BLACK);
            outtextxy(c+5,d+14,arr[a][b]);
            c+=42;

        }
        d+=35;
    }
    d+=10;
    for(a=0; a<4; a++)
    {
        c=240;
        for(b=0; b<5; b++)
        {
            if(a==0 &&(b==3 ||b==4))
            {
                setfillstyle(1,YELLOW);
            }
            else  setfillstyle(1,BLACK);
            bar(c,d,c+35,d+30);
            if(a==0 &&(b==3 || b==4))
            {
                setcolor(BLACK);
            }
            else
                setcolor(YELLOW);
            outtextxy(c+10,d+14,arr1[a][b]);
            c+=42;

        }
        d+=35;
    }
    if(DR%2==0)
    {
        gotoxy(40,4);
        printf("DEG");

    }
    else
    {
        gotoxy(40,4);
        printf("RAD");

    }
    page=2;
    page2();
}
void page1()
{
    char input;
    char ar[8][5]= {'q','w','B','n','o',
                    'r','x','^','L','l',
                    '(','i','H','h','j',
                    '%','P','s','c','t',
                    '7','8','9','D','A',
                    '4','5','6','*','/',
                    '1','2','3','+','-',
                    '0','.','E','a','='
                   };
    showptr();
    num=0;
    num1=0;
    count=0;
    while(!kbhit())
    {

        outtextxy(30,20,"Press any key to exit..");

        i1=0;

        c=240;

        d=152;

        rectangle(0,0,638,478);

        getmousepos(&button,&x,&y);

        for(a=0; a<9; a++)

        {

            c=240;

            for(b=0; b<5; b++)

            {

                if((x>=c&&x<=c+35)&&(y>=d&&y<=d+30))

                {

                    if((button&1)==1)
                    {

                        delay(150);
                        input=ar[a][b];
                        switch(input)
                        {

                        case 'q':
                            if(on==1)
                            {
                                calculator1();
                                page=1;
                            }
                            break;
                        case 'w':
                            if(on==1)
                            {
                                calculator2();
                                page=2;
                            }
                            break;

                        case 'B':
                            exit(1);
                            break;

                        case 'n':
                            if(on==1)
                            {
                                DR++;
                                if(DR%2==0)
                                {
                                    gotoxy(40,4);
                                    printf("DEG");

                                }
                                else
                                {
                                    gotoxy(40,4);
                                    printf("RAD");

                                }
                            }
                            break;
                        case'o':
                            on=1;
                            gotoxy(40,4);
                            printf("DEG");
                            break;
                        case 'r':
                            if(on==1)
                            {
                                get=sqrt(get) ;
                                chk1= sqrt_chk(get);
                                if(chk1==0)
                                {
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                    chk++;
                                    chk++;
                                }
                                else if(chk1==1)
                                {
                                    gotoxy(35,9);
                                    printf("%18.10Lf",get);
                                }

                                num=get;
                                if(ze==1)
                                {
                                    get=zero(1);
                                    ze=0;
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }


                            }
                            break;
                        case 'x':
                            if(on==1)
                            {
                                get=get*get;
                                num=get;
                                if(chk>=1)
                                {
                                    get=point(1,chk);
                                    gotoxy(35,9);
                                    printf("%18.10Lf",get);
                                    chk++;
                                    chk++;
                                }
                                else if(ze==1)
                                {
                                    get=zero(1);
                                    ze=0;
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }

                                else
                                {
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                            }
                            break;

                        case '^':
                            if(on==1)
                            {
                                num1=num;
                                num=0;
                                chk=0;
                                get=0;
                                opr='^';
                                gotoxy(35,9);
                                printf("%18.0Lf",num);
                            }
                            break;
                        case 'L':
                            if(on==1)
                            {
                                get=Log(get);
                                num=get;

                                gotoxy(35,9);
                                printf("%18.10Lf",get);

                            }
                            break;
                        case 'l':
                            if(on==1)
                            {

                                get=Lon(get);
                                num=get;
                                gotoxy(35,9);
                                printf("%18.10Lf",get);

                            }
                            break;

                        case '(':
                            if(on==1)
                            {
                                if(chk>=1)
                                {
                                    get=-1*get;
                                    num=-1*num;
                                    gotoxy(35,9);
                                    printf("%18.10Lf",get);
                                }
                                else
                                {
                                    get=-1*get;
                                    num=-1*num;
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                            }
                            break;
                        case 'i':
                            if(on==1)
                            {
                                get=1/get;
                                num=get;
                                gotoxy(35,9);
                                printf("%18.10Lf",get);

                            }
                            break;
                        case 'H':
                            if(on==1)
                            {
                                get=sinh(get);
                                num=get;
                                gotoxy(35,9);
                                printf("%18.10Lf",num);

                            }
                            break;
                        case 'h':
                            if(on==1)
                            {
                                get=cosh(get);
                                num=get;

                                gotoxy(35,9);
                                printf("%18.10Lf",get);

                            }
                            break;
                        case 'j':
                            if(on==1)
                            {

                                get=tanh(get);
                                num=get;
                                gotoxy(35,9);
                                printf("%18.10Lf",get);

                            }
                            break;

                        case '%' :
                            if(on==1)
                            {
                                get=get/100;
                                num=num/100;
                                chk+=2;
                                gotoxy(35,9);
                                printf("%18.10Lf",get);
                            }
                            break;
                        case 'P':
                            if(on==1)
                            {

                                get=3.1415926;
                                num=3.1415926;
                                chk=5;
                                gotoxy(35,9);
                                printf("%18.5Lf",get);
                            }
                            break;
                        case 's':
                            if(on==1)
                            {
                                if(get==90 || get==-90 || get==0)
                                {
                                    if(DR%2==0)
                                    {
                                        get*=3.1416;
                                        get/=180;
                                    }
                                    get=sin(get);
                                    num=get;
                                    gotoxy(35,9);
                                    printf("%18.0Lf",num);
                                }
                                else
                                {
                                    if(DR%2==0)
                                    {
                                        get*=3.1416;
                                        get/=180;
                                    }
                                    get=sin(get);
                                    num=get;
                                    gotoxy(35,9);
                                    printf("%18.5Lf",num);
                                }
                            }
                            break;
                        case 'c':
                            if(on==1)
                            {
                                if(get==90 || get==-90 || get==0)
                                {
                                    if(get==90 || get==-90)
                                    {
                                        gotoxy(35,9);
                                        get=0;
                                        num=0;
                                        printf("%18.0Lf",get);
                                    }
                                    else
                                    {
                                        if(DR%2==0)
                                        {
                                            get*=3.1416;
                                            get/=180;
                                        }
                                        get=cos(get);
                                        num=get;

                                        gotoxy(35,9);
                                        printf("%18.0Lf",get);
                                    }
                                }
                                else
                                {
                                    if(DR%2==0)
                                    {
                                        get*=3.1416;
                                        get/=180;
                                    }
                                    get=cos(get);
                                    num=get;
                                    gotoxy(35,9);
                                    printf("%18.5Lf",get);
                                }
                            }
                            break;
                        case 't':
                            if(on==1)
                            {
                                if(get==45 || get==-45)
                                {

                                    if(DR%2==0)
                                    {
                                        get*=3.1416;
                                        get/=180;
                                    }
                                    get=tan(get);
                                    num=get;
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);

                                }
                                else
                                {
                                    if(get==90)
                                    {
                                        gotoxy(35,9);
                                        printf("Math Error");

                                    }
                                    else
                                    {
                                        get=tan(get);
                                        num=get;
                                        gotoxy(35,9);
                                        printf("%18.10Lf",get);

                                    }
                                }
                            }
                            break;
                        case '7':
                            if(on==1)
                            {
                                if(chk>=1)
                                {
                                    get=point(7,chk);
                                    chk++;
                                    gotoxy(35,9);
                                    printf("%18.10Lf",get);
                                }
                                else if(ze==1)
                                {
                                    get=zero(7);
                                    ze=0;
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                                else
                                {
                                    get=addnum(7);
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                            }
                            break;
                        case '8':
                            if(on==1)
                            {
                                if(chk>=1)
                                {
                                    get=point(8,chk);
                                    chk++;
                                    gotoxy(35,9);
                                    printf("%18.10Lf",get);
                                }
                                else if(ze==1)
                                {
                                    get=zero(8);
                                    ze=0;
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                                else
                                {
                                    get=addnum(8);
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                            }
                            break;

                        case '9':
                            if(on==1)
                            {
                                if(chk>=1)
                                {
                                    get=point(9,chk);
                                    chk++;
                                    gotoxy(35,9);
                                    printf("%18.10Lf",get);
                                }
                                else if(ze==1)
                                {
                                    get=zero(9);
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                    ze=0;
                                }
                                else
                                {
                                    get=addnum(9);
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                            }
                            break;
                        case 'D':
                            if(on==1)
                            {
                                num=subnum(num);
                                gotoxy(35,9);
                                printf("%18.0Lf",num);
                            }
                            break;

                        case 'A':
                            if(on==1)
                            {
                                num=0;
                                num1=0;
                                get=0;
                                result=0;
                                count=0;
                                chk=0;
                                ze=0;
                                Final=0;
                                if(page==1)
                                    calculator1();
                                else if(page==2)
                                {
                                    calculator2();
                                }
                                else if(page==3)
                                {
                                    ;
                                }
                                if(DR%2==0)
                                {
                                    gotoxy(40,4);
                                    printf("DEG");

                                }
                                else
                                {
                                    gotoxy(40,4);
                                    printf("RAD");

                                }


                            }
                            break;


                        case '4':
                            if(on==1)
                            {

                                if(chk>=1)
                                {
                                    get=point(4,chk);
                                    gotoxy(35,9);

                                    printf("%18.10Lf",get);
                                    chk++;
                                }
                                else if(ze==1)
                                {
                                    get=zero(4);
                                    ze=0;
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                                else
                                {
                                    get=addnum(4);
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                            }
                            break;
                        case '5':
                            if(on==1)
                            {
                                if(chk>=1)
                                {

                                    get=point(5,chk);
                                    gotoxy(35,9);
                                    chk++;
                                    printf("%18.10Lf",get);
                                }
                                else if(ze==1)
                                {
                                    get=zero(5);
                                    gotoxy(35,9);
                                    ze=0;
                                    printf("%18.0Lf",get);
                                }
                                else
                                {
                                    get=addnum(5);
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                            }
                            break;
                        case '6':
                            if(on==1)
                            {
                                if(chk>=1)
                                {
                                    get=point(6,chk);
                                    chk++;
                                    gotoxy(35,9);
                                    printf("%18.10Lf",get);
                                }
                                else if(ze==1)
                                {
                                    get=zero(6);
                                    gotoxy(35,9);
                                    ze=0;
                                    printf("%18.0Lf",get);
                                }
                                else
                                {
                                    get=addnum(6);
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                            }
                            break;
                        case '*':
                            if(on==1)
                            {
                                num1=num;
                                if(chk>0) Final=1;
                                num=0;
                                chk=0;

                                get=0;
                                opr='*';
                                gotoxy(35,9);
                                printf("%18.0Lf",num);
                            }
                            break;
                        case '/':
                            if(on==1)
                            {
                                num1=num;
                                num=0;
                                if(chk>0) Final=1;
                                chk=0;
                                get=0;
                                opr='/';
                                gotoxy(35,9);
                                printf("%18.0Lf",num);
                            }
                            break;

                        case '1':
                            if(on==1)
                            {
                                if(chk>=1)
                                {
                                    get=point(1,chk);
                                    gotoxy(35,9);
                                    printf("%18.10Lf",get);
                                    chk++;
                                }
                                else if(ze==1)
                                {
                                    get=zero(1);
                                    ze=0;
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }

                                else
                                {
                                    get=addnum(1);
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }

                            }
                            break;

                        case '2':
                            if(on==1)
                            {
                                if(chk>=1)
                                {
                                    get=point(2,chk);
                                    gotoxy(35,9);
                                    printf("%18.10Lf",get);
                                    chk++;
                                }
                                else if(ze==1)
                                {
                                    get=zero(2);
                                    ze=0;
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                                else
                                {
                                    get=addnum(2);
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                            }
                            break;

                        case '3':
                            if(on==1)
                            {
                                if(chk>=1)
                                {
                                    get=point(3,chk);
                                    gotoxy(35,9);
                                    chk++;
                                    printf("%18.10Lf",get);
                                }
                                else if(ze==1)
                                {
                                    get=zero(3);
                                    ze=0;
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                                else
                                {
                                    get=addnum(3);
                                    gotoxy(35,9);

                                    printf("%18.0Lf",get);
                                }
                            }
                            break;
                        case '+':
                            if(on==1)
                            {
                                num1+=num;
                                if(chk>0) Final=1;
                                num=0;
                                opr='+';
                                chk=0;
                                get=0;

                                gotoxy(35,9);
                                printf("%18.0Lf",num);
                            }
                            break;

                        case '-':
                            if(on==1)
                            {
                                num1-=num;
                                if(chk>0) Final=1;
                                num=0;
                                chk=0;
                                get=0;

                                opr='-';
                                gotoxy(35,9);
                                printf("%18.0Lf",num);
                            }
                            break;

                        case '0':
                            if(on==1)
                            {

                                if(chk>=1)
                                {
                                    get=point(0,chk);
                                    chk++;
                                    gotoxy(35,9);
                                    printf("%18.10Lf",get);
                                }
                                else if(ze==1)
                                {
                                    get=zero(0);
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                    ze=0;
                                }
                                else
                                {
                                    get=addnum(0);
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                            }
                            break;
                        case '.':
                            if(on==1)
                            {
                                chk=1;
                                Final=1;
                                // gotoxy(20,30);
                                // printf("FFS");
                                gotoxy(35,9);
                                printf("%18.10Lf",get);
                            }
                            break;

                        case 'E':
                            if(on==1)
                            {
                                ze=1;
                            }
                            break;
                        case 'a':
                            if(on==1)
                            {
                                gotoxy(35,9);
                                printf("%18.0Lf",result);
                            }
                            break;
                        case '=':
                            if(on==1)
                            {
                                switch(opr)
                                {
                                case '+':
                                    if(on==1)
                                    {
                                        if(count<1)
                                        {
                                            result=num+num1;
                                        }
                                        else
                                        {
                                            result=result+num;
                                        }
                                        gotoxy(35,9);
                                        if(Final==1)
                                            printf("%18.10Lf",result);
                                        else
                                            printf("%18.0Lf",result);
                                        count+=1;
                                        chk=0;
                                        get=result;
                                    }
                                    break;

                                case '-':
                                    if(on==1)
                                    {

                                        if(count<1)
                                        {
                                            result=num1-num;
                                        }
                                        else
                                        {
                                            result=result-num;
                                        }
                                        gotoxy(35,9);
                                        if(Final==1)
                                            printf("%18.10Lf",result);
                                        else
                                            printf("%18.0Lf",result);
                                        count+=1;
                                        chk=0;
                                        get=result;
                                    }
                                    break;
                                case '*':
                                    if(on==1)
                                    {
                                        if(count<1)
                                        {
                                            result=num1*num;
                                        }
                                        else
                                        {
                                            result=result*num;
                                        }
                                        gotoxy(35,9);
                                        if(Final==1)
                                            printf("%18.10Lf",result);
                                        else
                                            printf("%18.0Lf",result);
                                        count+=1;
                                        chk=0;
                                        get=result;
                                    }
                                    break;

                                case '/':
                                    if(on==1)
                                    {
                                        if(count<1)
                                        {
                                            result=num1/num;
                                        }
                                        else
                                        {
                                            result=result/num;
                                        }
                                        gotoxy(35,9);
                                        if(Final==1)
                                            printf("%18.10Lf",result);
                                        else
                                            printf("%18.0Lf",result);
                                        count+=1;
                                        chk=0;
                                        ze=0;
                                        get=result;
                                    }
                                    break;

                                case '^':
                                {
                                    if(on==1)
                                    {
                                        result=pow(num1,num);
                                        gotoxy(35,9);
                                        if(Final==1)
                                            printf("%18.10Lf",result);
                                        else
                                            printf("%18.0Lf",result);

                                        chk=0;
                                        get=result;

                                    }
                                    break;
                                }
                                }
                            }
                        }
                    }
                }

                c+=42;
            }

            d+=35;
            if(a==3) d+=4;
        }

    }
}
void page2()
{
    char input;
    char ar[8][5]= {'q','w','B','n','o',
                    'r','x','^','L','l',
                    '(','i','H','h','j',
                    '%','P','s','c','t',
                    '7','8','9','D','A',
                    '4','5','6','*','/',
                    '1','2','3','+','-',
                    '0','.','E','a','='
                   };
    showptr();
    num=0;
    num1=0;
    count=0;
    while(!kbhit())
    {

        outtextxy(30,20,"Press any key to exit..");

        i1=0;

        c=240;

        d=152;

        rectangle(0,0,638,478);

        getmousepos(&button,&x,&y);

        for(a=0; a<9; a++)

        {

            c=240;

            for(b=0; b<5; b++)

            {

                if((x>=c&&x<=c+35)&&(y>=d&&y<=d+30))

                {

                    if((button&1)==1)
                    {

                        delay(150);
                        input=ar[a][b];
                        switch(input)
                        {

                        case 'q':
                            if(on==1)
                            {
                                calculator1();
                                page=1;
                            }
                            break;
                        case 'w':
                            if(on==1)
                            {
                                calculator2();
                                page=2;
                            }
                            break;

                        case 'B':
                            exit(1);
                            break;

                        case 'n':
                            if(on==1)
                            {
                                DR++;
                                if(DR%2==0)
                                {
                                    gotoxy(40,4);
                                    printf("DEG");

                                }
                                else
                                {
                                    gotoxy(40,4);
                                    printf("RAD");

                                }
                            }
                            break;
                        case'o':
                            on=1;
                            if(DR%2==0)
                            {
                                gotoxy(40,4);
                                printf("DEG");

                            }
                            else
                            {
                                gotoxy(40,4);
                                printf("RAD");

                            }
                            break;
                        case 'r':
                            if(on==1)
                            {
                                get=sqrt(get) ;
                                chk1= sqrt_chk(get);
                                if(chk1==0)
                                {
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                    chk++;
                                    chk++;
                                }
                                else if(chk1==1)
                                {
                                    gotoxy(35,9);
                                    printf("%18.10Lf",get);
                                }

                                num=get;
                                if(ze==1)
                                {
                                    get=zero(1);
                                    ze=0;
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }


                            }
                            break;
                        case 'x':
                            if(on==1)
                            {
                                get=get*get*get;
                                num=get;
                                if(chk>=1)
                                {
                                    get=point(1,chk);
                                    gotoxy(35,9);
                                    printf("%18.10Lf",get);
                                    chk++;
                                    chk++;
                                }
                                else if(ze==1)
                                {
                                    get=zero(1);
                                    ze=0;
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }

                                else
                                {
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                            }
                            break;

                        case '^':
                            if(on==1)
                            {
                                num1=num;
                                num=0;
                                chk=0;
                                get=0;
                                opr='^';
                                gotoxy(35,9);
                                printf("%18.0Lf",num);
                            }
                            break;
                        case 'L':
                            if(on==1)
                            {
                                get=pow(10,get);
                                num=get;
                                gotoxy(35,9);
                                printf("%18.10Lf",get);

                            }
                            break;
                        case 'l':
                            if(on==1)
                            {

                                get=exp(get);
                                num=get;
                                gotoxy(35,9);
                                printf("%18.10Lf",get);

                            }
                            break;

                        case '(':
                            if(on==1)
                            {
                                if(chk>=1)
                                {
                                    get=-1*get;
                                    num=-1*num;
                                    gotoxy(35,9);
                                    printf("%18.10Lf",get);
                                }
                                else
                                {
                                    get=-1*get;
                                    num=-1*num;
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                            }
                            break;
                        case 'i':
                            if(on==1)
                            {
                                get=factorial(get);
                                num=get;
                                gotoxy(35,9);
                                printf("%18.10Lf",get);

                            }
                            break;
                        case 'H':
                            if(on==1)
                            {
                                get=sinh(get);
                                get=1/get;
                                num=get;
                                if(get==1.0 || get==-1.0 || get==0.0)
                                {
                                    gotoxy(35,9);
                                    printf("%18.0Lf",num);
                                }
                                else
                                {
                                    gotoxy(35,9);
                                    printf("%18.5Lf",num);
                                }
                            }
                            break;
                        case 'h':
                            if(on==1)
                            {
                                get=cosh(get);
                                get=1/get;
                                num=get;
                                if(num==1 || num==-1 || num==0)
                                {
                                    gotoxy(35,9);

                                    printf("%18.0Lf",get);
                                }
                                else
                                {
                                    gotoxy(35,9);
                                    printf("%18.5Lf",get);
                                }
                            }
                            break;
                        case 'j':
                            if(on==1)
                            {

                                get=tanh(get);
                                get=1/get;
                                num=get;
                                if(num==1 || num==-1 || num==0)
                                {
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                                else
                                {
                                    gotoxy(35,9);
                                    printf("%18.5Lf",get);
                                }
                            }
                            break;

                        case '%' :
                            if(on==1)
                            {
                                get=get/100;
                                num=num/100;
                                chk+=2;
                                gotoxy(35,9);
                                printf("%18.10Lf",get);
                            }
                            break;
                        case 'P':
                            if(on==1)
                            {

                                get=3.1415926;
                                num=3.1415926;
                                chk=5;
                                gotoxy(35,9);
                                printf("%18.5Lf",get);
                            }
                            break;
                        case 's':
                            if(on==1)
                            {
                                if(get==1 || get==-1 || get==0)
                                {

                                    get=asin(get);
                                    if(DR%2==0)
                                    {
                                        get/=3.1415926;
                                        get*=180;
                                    }
                                    num=get;
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                                else
                                {
                                    get=asin(get);
                                    if(DR%2==0)
                                    {
                                        get/=3.1415926;
                                        get*=180;
                                    }
                                    num=get;
                                    gotoxy(35,9);
                                    printf("%18.5Lf",num);
                                }
                            }
                            break;
                        case 'c':
                            if(on==1)
                            {

                                if(num==1 || num==-1 || num==0)
                                {
                                    get=acos(get);
                                    if(DR%2==0)
                                    {
                                        get/=3.1416;
                                        get*=180;
                                    }
                                    num=get;

                                    gotoxy(35,9);

                                    printf("%18.0Lf",get);
                                }
                                else
                                {
                                    get=acos(get);
                                    if(DR%2==0)
                                    {
                                        get/=3.1416;
                                        get*=180;
                                    }
                                    num=get;
                                    gotoxy(35,9);
                                    printf("%18.5Lf",get);
                                }
                            }
                            break;
                        case 't':
                            if(on==1)
                            {
                                if(get==1 || get==-1 || get==0)
                                {

                                    get=asin(get);
                                    if(DR%2==0)
                                    {
                                        get/=3.1415926;
                                        get*=180;
                                    }
                                    num=get;
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                                else
                                {

                                    get=atan(get);
                                    if(DR%2==0)
                                    {
                                        get/=3.1416;
                                        get*=180;
                                    }
                                    num=get;
                                    gotoxy(35,9);
                                    printf("%18.5Lf",get);
                                }

                            }
                            break;
                        case '7':
                            if(on==1)
                            {
                                if(chk>=1)
                                {
                                    get=point(7,chk);
                                    chk++;
                                    gotoxy(35,9);
                                    printf("%18.10Lf",get);
                                }
                                else if(ze==1)
                                {
                                    get=zero(7);
                                    ze=0;
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                                else
                                {
                                    get=addnum(7);
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                            }
                            break;
                        case '8':
                            if(on==1)
                            {
                                if(chk>=1)
                                {
                                    get=point(8,chk);
                                    chk++;
                                    gotoxy(35,9);
                                    printf("%18.10Lf",get);
                                }
                                else if(ze==1)
                                {
                                    get=zero(8);
                                    ze=0;
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                                else
                                {
                                    get=addnum(8);
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                            }
                            break;

                        case '9':
                            if(on==1)
                            {
                                if(chk>=1)
                                {
                                    get=point(9,chk);
                                    chk++;
                                    gotoxy(35,9);
                                    printf("%18.10Lf",get);
                                }
                                else if(ze==1)
                                {
                                    get=zero(9);
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                    ze=0;
                                }
                                else
                                {
                                    get=addnum(9);
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                            }
                            break;
                        case 'D':
                            if(on==1)
                            {
                                num=subnum(num);
                                gotoxy(35,9);
                                printf("%18.0Lf",num);
                            }
                            break;

                        case 'A':
                            if(on==1)
                            {
                                num=0;
                                num1=0;
                                get=0;
                                result=0;
                                count=0;
                                chk=0;
                                ze=0;
                                Final=0;
                                if(page==1)
                                    calculator1();
                                else if(page==2)
                                {
                                    calculator2();
                                }
                                if(DR%2==0)
                                {
                                    gotoxy(40,4);
                                    printf("DEG");

                                }
                                else
                                {
                                    gotoxy(40,4);
                                    printf("RAD");

                                }


                            }
                            break;


                        case '4':
                            if(on==1)
                            {

                                if(chk>=1)
                                {
                                    get=point(4,chk);
                                    gotoxy(35,9);

                                    printf("%18.10Lf",get);
                                    chk++;
                                }
                                else if(ze==1)
                                {
                                    get=zero(4);
                                    ze=0;
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                                else
                                {
                                    get=addnum(4);
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                            }
                            break;
                        case '5':
                            if(on==1)
                            {
                                if(chk>=1)
                                {

                                    get=point(5,chk);
                                    gotoxy(35,9);
                                    chk++;
                                    printf("%18.10Lf",get);
                                }
                                else if(ze==1)
                                {
                                    get=zero(5);
                                    gotoxy(35,9);
                                    ze=0;
                                    printf("%18.0Lf",get);
                                }
                                else
                                {
                                    get=addnum(5);
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                            }
                            break;
                        case '6':
                            if(on==1)
                            {
                                if(chk>=1)
                                {
                                    get=point(6,chk);
                                    chk++;
                                    gotoxy(35,9);
                                    printf("%18.10Lf",get);
                                }
                                else if(ze==1)
                                {
                                    get=zero(6);
                                    gotoxy(35,9);
                                    ze=0;
                                    printf("%18.0Lf",get);
                                }
                                else
                                {
                                    get=addnum(6);
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                            }
                            break;
                        case '*':
                            if(on==1)
                            {
                                num1=num;
                                if(chk>0) Final=1;
                                num=0;
                                chk=0;

                                get=0;
                                opr='*';
                                gotoxy(35,9);
                                printf("%18.0Lf",num);
                            }
                            break;
                        case '/':
                            if(on==1)
                            {
                                num1=num;
                                num=0;
                                if(chk>0) Final=1;
                                chk=0;
                                get=0;
                                opr='/';
                                gotoxy(35,9);
                                printf("%18.0Lf",num);
                            }
                            break;

                        case '1':
                            if(on==1)
                            {
                                if(chk>=1)
                                {
                                    get=point(1,chk);
                                    gotoxy(35,9);
                                    printf("%18.10Lf",get);
                                    chk++;
                                }
                                else if(ze==1)
                                {
                                    get=zero(1);
                                    ze=0;
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }

                                else
                                {
                                    get=addnum(1);
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }

                            }
                            break;

                        case '2':
                            if(on==1)
                            {
                                if(chk>=1)
                                {
                                    get=point(2,chk);
                                    gotoxy(35,9);
                                    printf("%18.10Lf",get);
                                    chk++;
                                }
                                else if(ze==1)
                                {
                                    get=zero(2);
                                    ze=0;
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                                else
                                {
                                    get=addnum(2);
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                            }
                            break;

                        case '3':
                            if(on==1)
                            {
                                if(chk>=1)
                                {
                                    get=point(3,chk);
                                    gotoxy(35,9);
                                    chk++;
                                    printf("%18.10Lf",get);
                                }
                                else if(ze==1)
                                {
                                    get=zero(3);
                                    ze=0;
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                                else
                                {
                                    get=addnum(3);
                                    gotoxy(35,9);

                                    printf("%18.0Lf",get);
                                }
                            }
                            break;
                        case '+':
                            if(on==1)
                            {
                                num1+=num;
                                if(chk>0) Final=1;
                                num=0;
                                opr='+';
                                chk=0;
                                get=0;

                                gotoxy(35,9);
                                printf("%18.0Lf",num);
                            }
                            break;

                        case '-':
                            if(on==1)
                            {
                                num1-=num;
                                if(chk>0) Final=1;
                                num=0;
                                chk=0;
                                get=0;

                                opr='-';
                                gotoxy(35,9);
                                printf("%18.0Lf",num);
                            }
                            break;

                        case '0':
                            if(on==1)
                            {

                                if(chk>=1)
                                {
                                    get=point(0,chk);
                                    chk++;
                                    gotoxy(35,9);
                                    printf("%18.10Lf",get);
                                }
                                else if(ze==1)
                                {
                                    get=zero(0);
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                    ze=0;
                                }
                                else
                                {
                                    get=addnum(0);
                                    gotoxy(35,9);
                                    printf("%18.0Lf",get);
                                }
                            }
                            break;
                        case '.':
                            if(on==1)
                            {
                                chk=1;
                                Final=1;
                                // gotoxy(20,30);
                                // printf("FFS");
                                gotoxy(35,9);
                                printf("%18.10Lf",get);
                            }
                            break;

                        case 'E':
                            if(on==1)
                            {
                                ze=1;
                            }
                            break;
                        case 'a':
                            if(on==1)
                            {
                                gotoxy(35,9);
                                printf("%18.0Lf",result);
                            }
                            break;
                        case '=':
                            if(on==1)
                            {
                                switch(opr)
                                {
                                case '+':
                                    if(on==1)
                                    {
                                        if(count<1)
                                        {
                                            result=num+num1;
                                        }
                                        else
                                        {
                                            result=result+num;
                                        }
                                        gotoxy(35,9);
                                        if(Final==1)
                                            printf("%18.10Lf",result);
                                        else
                                            printf("%18.0Lf",result);
                                        count+=1;
                                        chk=0;
                                        get=result;
                                    }
                                    break;

                                case '-':
                                    if(on==1)
                                    {

                                        if(count<1)
                                        {
                                            result=num1-num;
                                        }
                                        else
                                        {
                                            result=result-num;
                                        }
                                        gotoxy(35,9);
                                        if(Final==1)
                                            printf("%18.10Lf",result);
                                        else
                                            printf("%18.0Lf",result);
                                        count+=1;
                                        chk=0;
                                        get=result;
                                    }
                                    break;
                                case '*':
                                    if(on==1)
                                    {
                                        if(count<1)
                                        {
                                            result=num1*num;
                                        }
                                        else
                                        {
                                            result=result*num;
                                        }
                                        gotoxy(35,9);
                                        if(Final==1)
                                            printf("%18.10Lf",result);
                                        else
                                            printf("%18.0Lf",result);
                                        count+=1;
                                        chk=0;
                                        get=result;
                                    }
                                    break;

                                case '/':
                                    if(on==1)
                                    {
                                        if(count<1)
                                        {
                                            result=num1/num;
                                        }
                                        else
                                        {
                                            result=result/num;
                                        }
                                        gotoxy(35,9);
                                        if(Final==1)
                                            printf("%18.10Lf",result);
                                        else
                                            printf("%18.0Lf",result);
                                        count+=1;
                                        chk=0;
                                        ze=0;
                                        get=result;
                                    }
                                    break;

                                case '^':
                                {
                                    if(on==1)
                                    {
                                        result=pow(num1,num);
                                        gotoxy(35,9);
                                        if(Final==1)
                                            printf("%18.10Lf",result);
                                        else
                                            printf("%18.0Lf",result);

                                        chk=0;
                                        get=result;

                                    }
                                    break;
                                }
                                }
                            }
                        }
                    }
                }

                c+=42;
            }

            d+=35;
            if(a==3) d+=4;
        }

    }
}

long double addnum(long double getnum)
{
    num=num*10+getnum;
    return(num);
}
long double zero(long double getnum)
{
    long double i;
    for(i=1; i<=getnum; i++)
        num*=10;
    return (num);
}
long double subnum(long double a)
{
    a=a/10;
    long double b=floorl(a);
    return(b);
}
long double point(long double getnum,long double a)
{
    long double i;

    for(i=1; i<=a; i++)
        getnum=getnum/10;
    num=num+(getnum);
    return num;
}
long double sqrt_chk(long double a)
{
    if(a*a!=num) chk1=1;
    return chk1;

}
long double Lon(long double d)
{
    return log(d);
}

long double Log(long double d)
{
    return log10(d);
}
long double factorial(long double n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}
void showptr()
{
    i.x.ax=1;
    int86(0x33,&i,&o);
}

void getmousepos(int *button,int *x,int *y)
{
    i.x.ax=3;
    int86(0x33,&i,&o);
    *button=o.x.bx;
    *x=o.x.cx;
    *y=o.x.dx;
}
void main()
{
    int driver=DETECT,mode;
    initgraph(&driver,&mode,"C: \\Turboc3\\BGI");
    calculator1();
    page1();
    getch();
}
