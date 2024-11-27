#include <stdio.h>
#include <string.h>
#define BOLD "\x1B[1m"
#define RED "\x1B[31m"
#define BLU "\x1B[34m"
#define RESET "\x1B[0m"
#define YEL "\x1B[33m"
#define WHT "\x1B[37m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define GREEN "\x1B[32m"

struct Book
{
    char bookNam[1000];
    int bb;
}b[1000];
struct Account
{
    char userName[1000],password[1000],bookName[1000];
    int bk,bid;

}acc[1000];
int i=0,bookCount=4;
void view()
{
    int j,f=0;
    printf("Available Books :\n  ");
    for(j=0;j<=bookCount;j++)
    {
        if(b[j].bb==0)
        {
            f=1;
            printf("%d.%s\n  ",j+1,b[j].bookNam);
        }
    }
    if(f==0)
    printf("*********************%s%sNo Books Available%s%s************************\n",RED,BOLD,RESET,RESET);
}
void issued()
{
    int j,f=0;
    printf("Issued Books :\n   ");
    for(j=0;j<=bookCount;j++)
    {
        if(b[j].bb==1)
        {
            f=1;
            printf("%d.%s\n  ",j+1,b[j].bookNam);
        }
    }
        if(f==0)
        printf("*****************No Books Available******************\n");
}
void Account()
{
    printf("Enter your UserName : ");
    scanf(" %[^\n]",acc[i].userName);
    printf("Enter Your password: ");
    scanf(" %[^\n]",acc[i].password);
    strcpy(acc[i].bookName," ");
    acc[i].bk=0;
    printf("********************* Account created successfully *****************\n");
    i++;
}
    
void adds()
{
    printf("Enter Book Name : \n");
    bookCount++;
    scanf(" %[^\n]",b[bookCount].bookNam);
    b[bookCount].bb=0;
}
void issue(int s)
{
    int j,nn;
    for(;1;)
    {
        view();
        printf("Enter number what book you want : ");
        scanf("%d",&nn);
        if(acc[s].bk==0)
        {
            if((nn-1<=bookCount&&nn>=0)&&b[nn-1].bb==0)
            {
                strcpy(acc[s].bookName,b[nn-1].bookNam);
                acc[s].bid=nn-1;
                acc[s].bk=1;
                b[nn-1].bb=1;
                printf("Take Your %s Book\n",acc[s].bookName);
                break;
            }
            else
            printf("Enter Valid Book Number:\n");
        }
        else
    {
        printf("You already have a book\n");
        break;
    }
        
    }
    
}
void ret(int s)
{
    if(acc[s].bk)
    {
        printf("Thanks for returning your %s book\n",acc[s].bookName);
        strcpy(acc[s].bookName," ");
        acc[s].bk=0;
        b[acc[s].bid].bb=0;
    }
    else
    printf("You don't get book ok\n");
}
void Login()
{
    int f=1,l=0,ccc=0;
    char na[1000],pas[1000];
    for(;f;)
    {
        f=0;
        printf("Account Name: \t");
        scanf(" %[^\n]",na);
        printf("Account Password: \t");
        scanf(" %[^\n]",pas);
        for(l=0;l<i;i++)
        {
            if(!strcmp(acc[l].userName,na)&&!strcmp(acc[l].password,pas));
            {
                f=1;
                break;
            }
        }
    if(f)
    {
        printf("\n Login successfully------\n");
        break;
    }
    else
    {
        printf("Invalid Login\n");
        break;
    }
}
for(;f;)
{
    printf("1.for get book \t 2.for return Book \t 3.for Exit\n");
    scanf("%d",&ccc);
    if(ccc==1)
    {
        issue(l);
    }
    else if(ccc==2)
    {
        ret(l);
    }
    else if(ccc==3)
    {
        f=0;
    }
}
}
int main()
{
    int choice=0,c=0,ss;
    char s[1000];
    strcpy(b[0].bookNam,"Ponnien Selvan");
    strcpy(b[1].bookNam,"Tirukural");
    strcpy(b[2].bookNam,"Manimegalai");
    strcpy(b[3].bookNam,"Kadhaigalin Nayagan");
    strcpy(b[4].bookNam,"Un vizhigazhizh");
    b[0].bb=0;
    b[1].bb=0;
    b[2].bb=0;
    b[3].bb=0;
    b[4].bb=0;
    printf("************""%s%sWelcome to krishnabharathi Library%s%s""****************\n\n",GREEN,BOLD,RESET,RESET);
    while(1)
    {
        printf("%s%s1.For Users \t 2.For Admin \t 3.For Exit\n%s%s",BLU,BOLD,RESET,RESET);
        scanf("%d",&choice);
        if(choice==1)
        {
            while(1)
            {
                printf("1.For Login\t 2.For Create Account \t 3.For Exit \n");
                scanf("%d",&c);
                if(c==1)
                {
                    Login();
                }
                else if(c==2)
                {
                    Account();
                    i++;
                }
                else if(c==3)
                {
                    printf("Thank You\n");
                    break;
                }
            }
            
        }
        else if(choice==2)
        {
            for(;1;)
            {
                printf("\nEnter Admin Password:\t");
                scanf(" %[^\n]",s);
                if(!strcmp("Krishnabharathi",s))
                {
                    for(;1;)
                    {
                        printf("1.for Add book \t 2.for view book \t 3.for exit\n");
                        scanf("%d",&ss);
                        if(ss==1)
                        {
                            adds();
                        }
                else if(ss==2)
                {
                    view();
                }
                else if(ss==3)
                {
                    issued();
                }
                else if(ss==4)
                {
                    break;
                }
                }  
                break;
                
                }
                else 
                  printf("Invalid Password");
            }
            
        }
        else if(choice==3)
        {
            break;
        }
    }

}

