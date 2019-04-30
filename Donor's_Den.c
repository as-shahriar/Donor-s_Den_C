#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    char name[10],bg[5],city[10],cell[15];
    char user_name_saved[10],pass_saved[10];
    int day,month,year;
    struct node *link;
}node;

node *head;

char glname[10],gluser[10];

void asif();
int time(int,int,int,int,int,int);
void search();
int count(char bg[5]);
void showall();
void reg();
int usernamecheck(char name[10]);
int login();
void deleteac();
void home();
void mainpage();
void edit();
void deleteall();

void main()
{
    asif();
    mainpage();

}

void deleteall()
{
    node *temp=head;
    while(temp!=NULL)
    {
        temp->link=NULL;
        free(temp);
        temp=temp->link;
    }
}

void edit()
{
    int aaa;
    node *temp=head;
    int cmp;
    printf("0. Back\n\n");
    while(temp!=NULL)
    {
        cmp=strcmp(temp->user_name_saved,gluser);
        if(cmp==0)
        {
            printf("Nick Name: %s\n",temp->name);
            printf("\nBlood Group: %s\n",temp->bg);
            printf("\nCity: ");
            scanf("%s",temp->city);
            cmp=strcmp(temp->city,"0");
            if(cmp==0) {system("cls");home();}
            printf("\nMobile No: ");
            scanf("%s",temp->cell);
             printf("\nDid You Donate Blood?\n1. Yes\n2. No\n");
    scanf("%d",&aaa);
    if(aaa==1)
    {
        printf("\nDate of Last Donation:\n(Format: d m y)\n");
        scanf("%d%d%d",&temp->day,&temp->month,&temp->year);
    }
            char usernt[10];
            again:
            printf("\nUsername: %s\n",temp->user_name_saved);

            printf("\nPassword: ");
            scanf("%s",temp->pass_saved);
            strcpy(glname,temp->name);
            strcpy(gluser,temp->user_name_saved);
            system("cls");
            printf("\nEdited Successfully!!!\n\n");

            home();
        }


        temp=temp->link;
    }
}

void asif()
{
      node *temp=(node*)malloc(sizeof(node));

   strcpy(temp->name,"Asif");
       strcpy(temp->bg,"B+");

 strcpy(temp->city,"Dhaka");

    strcpy(temp->cell,"015111111111");

    temp->day=2;
    temp->month=5;
    temp->year=2016;
    strcpy(temp->user_name_saved,"asif");

    strcpy(temp->pass_saved,"8617");
     strcpy(gluser,temp->user_name_saved);
    strcpy(glname,temp->name);
    temp->link=NULL;
    if(head!=NULL)
        temp->link=head;
    head=temp;
}
void mainpage()
{
    int x;
    printf("***************\n");
    printf("* Donor's Den *\n***************\n");
    printf("\nDonate Blood, Be a Hero.\n\n");

    printf("1. Login\n2. Registration\n3. Developer\n4. Exit\n\n--> ");
    scanf("%d",&x);
    int log;
    switch (x)
    {
        case 1:
                system("cls");
                log=login();
                if(log==1)
                {  system("cls");
                     printf("Login successful\n\n");
                   home();
                }
                break;
        case 2:
                system("cls");
                reg();
                home();
                break;
        case 3:
                system("cls");
                printf("**************\n* Developer *\n**************\n\n");


                printf("Asif Shahriar\n\nID: 171-15-8617\n\nData Structure\n");
                getch();
                system("cls");
                mainpage();
                break;

        case 4:
                system("cls");
                printf("\n\n\n****************\n* Thank You!!! *\n****************\n\n\n");
                getch();
                deleteall();
                system("taskkill/IM cb_console_runner.exe");
        default:
            system("cls");
            mainpage();

    }
}

void home()
{
    int x;

    printf("********\n");
    printf("* Home *\n********\n\n\n");

    printf("%s\n\n",glname);
    printf("1. Edit Profile\n2. Search Blood\n3. Show All\n4. Delete Account\n5. Logout\n");
    printf("\n\n--> ");
    scanf("%d",&x);
    switch (x)
    {
        case 1:
            system("cls");
            printf("****************\n* Edit Profile *\n****************\n\n\n");
            edit();
            break;
        case 2:
             system("cls");
             search();

             break;
        case 3:
             system("cls");
             showall();

             break;
        case 4:
            system("cls");
            deleteac();
            home();
            break;
        case 5:
            system("cls");
            mainpage();
            break;

        default:
            system("cls");
            home();
    }
}
void deleteac()
{
        node *temp=head;
        char user[10],pass[10];
        int cmp,i;
        printf("******************\n* Delete Account *\n******************\n\n");
        printf("0. Back\n\nUsername: ");
        scanf("%s",user);
        cmp=strcmp(user,"0");
        if(cmp==0)
        {
            cmp=100;
            system("cls");
            mainpage();
        }
        printf("Password: ");
        scanf("%s",pass);
        temp=head;
        while(temp!=NULL)
        {
            cmp=strcmp(user,temp->user_name_saved);
            if(cmp==0)
            {
                cmp=strcmp(pass,temp->pass_saved);
                if(cmp==0)
                {
                    strcpy(temp->user_name_saved,"0");
                   strcpy(temp->bg,"0");
                   printf("\n\nDeleted Successfully!!!!\n\n");
                   getch();
                   system("cls");
                    mainpage();
                }
                else {
                    system("cls");
                    printf("Username or Password didn't match!!\n\n");
                    deleteac();
                }
            }


        temp=temp->link;
    }
    if(temp==NULL) {
            system("cls");
            printf("Username or Password didn't match!!\n\n");
            deleteac();
    }
}

int login()
{
    char user[10],pass[10];
    node *temp =head;
    int cmp,x=0;

    again:
    printf("*********\n* Login *\n*********\n\n");
    printf("0. Back\n\nUsername: ");
    scanf("%s",user);
    cmp=strcmp(user,"0");
    if(cmp==0)
    {

        cmp=100;
        system("cls");
        mainpage();
    }
    printf("Password: ");
    scanf("%s",pass);
    temp=head;
    while(temp!=NULL)
    {
        cmp=strcmp(user,temp->user_name_saved);
        if(cmp==0)
        {
            cmp=strcmp(pass,temp->pass_saved);
            if(cmp==0)
            {

                x=1;

                strcpy(gluser,temp->user_name_saved);
                strcpy(glname,temp->name);
                return x;
            }
        }
         temp=temp->link;
    }
        system("cls");
        printf("Wrong Password or Username\n\n");

        goto again;

}

int time(int cd,int cm,int cy,int dd,int dm,int dy)
{
    int fm,fd,fy;

    if(cd<dd)
    {
        cm--;
        cd+=30;
    }
    fd=cd-dd;

    if(cm<dm)
    {
        cy--;
        cm+=12;
    }
    fm=cm-dm;

    fy=cy-dy;


    return (fm+(fy*12));
}


void search()
{
    char bg[5],city[10];
    int d,m,y,cmp;
    printf("**********\n* Search *\n**********\n\n0. Back\n\n");
    printf("Blood Group: ");
    scanf("%s",bg);
    cmp=strcmp(bg,"0");
    if(cmp==0) {system("cls");home();}
    printf("City: ");
    scanf("%s",city);
    printf("Date You Need Blood:\n(Format d m y)\n");
    scanf("%d%d%d",&d,&m,&y);

    node *temp =head;


   int cmp1,cmp2,timee,fun=0;
   system("cls");
     printf("Blood Group: %s\nCity: %s\n\n",bg,city);
    while(temp!=NULL)
    {
        cmp1=strcmp(bg,temp->bg);
        cmp2=strcmp(city,temp->city);

        timee=time(d,m,y,temp->day,temp->month,temp->year);


        if(cmp1==0 && cmp2==0 && timee>=3)
        {
            printf("Name: %s\n",temp->name);
            printf("Mobile No: %s\n\n",temp->cell);
            fun=1;

        }
        temp=temp->link;
    }
    if(fun!=1)
        printf("No Member is Available!!!\n");
    getch();
    system("cls");
    home();
}

int count(char bg[5])
{
    node *temp=head;
    int cmp,i=0;
    while(temp!=NULL)
    {
        cmp=strcmp(temp->bg,bg);
        if(cmp==0)
            i++;
        temp=temp->link;
    }
    return i;
}

void showall()
{
    node *temp = head;
    printf("All Donors\n**********\n\n");
    int cmp,a;
    a=count("A+");
   if(a!=0)
   {
        printf("Blood Group: A+ (%d)\n\n",a);
        while(temp!=NULL)
        {
            cmp=strcmp(temp->bg,"A+");
            if(cmp==0)
            {

                printf("Name: %s\n",temp->name);
                printf("Mobile No: %s\n",temp->cell);
                printf("Date of Donation: %d/%d/%d\n",temp->day,temp->month,temp->year);
                printf("City: %s\n\n",temp->city);

            }
            temp=temp->link;
        }
   }
    temp = head;

     a=count("A-");
    if(a!=0)
    {
         printf("\nBlood Group: A- (%d)\n\n",a);
        while(temp!=NULL)
        {
            cmp=strcmp(temp->bg,"A-");
            if(cmp==0)
            {
                printf("Name: %s\n",temp->name);
                printf("Mobile No: %s\n",temp->cell);
                printf("Date of Donation: %d/%d/%d\n",temp->day,temp->month,temp->year);
                printf("City: %s\n\n",temp->city);
            }
            temp=temp->link;
        }
    }

    temp = head;
     a=count("B+");
     if(a!=0)
     {
        printf("\nBlood Group: B+ (%d)\n\n",a);
        while(temp!=NULL)
        {
            cmp=strcmp(temp->bg,"B+");
            if(cmp==0)
            {
                printf("Name: %s\n",temp->name);
                printf("Mobile No: %s\n",temp->cell);
                printf("Date of Donation: %d/%d/%d\n",temp->day,temp->month,temp->year);
                printf("City: %s\n\n",temp->city);
            }
            temp=temp->link;
        }
     }
    temp = head;
     a=count("B-");
     if(a!=0)
     {

        printf("\nBlood Group: B- (%d)\n\n",a);
        while(temp!=NULL)
        {
        cmp=strcmp(temp->bg,"B-");
        if(cmp==0)
        {
            printf("Name: %s\n",temp->name);
            printf("Mobile No: %s\n",temp->cell);
            printf("Date of Donation: %d/%d/%d\n",temp->day,temp->month,temp->year);
            printf("City: %s\n\n",temp->city);
        }
        temp=temp->link;
        }
     }
   temp = head;
    a=count("AB+");
    if(a!=0)
    {

         printf("\nBlood Group: AB+ (%d)\n\n",a);
        while(temp!=NULL)
        {
            cmp=strcmp(temp->bg,"AB+");
            if(cmp==0)
            {
                printf("Name: %s\n",temp->name);
                printf("Mobile No: %s\n",temp->cell);
                printf("Date of Donation: %d/%d/%d\n",temp->day,temp->month,temp->year);
                printf("City: %s\n\n",temp->city);
            }
            temp=temp->link;
        }
    }
   temp = head;
    a=count("AB-");
    if(a!=0)
    {
         printf("\nBlood Group: AB- (%d)\n\n",a);
        while(temp!=NULL)
        {
           cmp=strcmp(temp->bg,"AB-");
            if(cmp==0)
            {
                printf("Name: %s\n",temp->name);
                printf("Mobile No: %s\n",temp->cell);
                printf("Date of Donation: %d/%d/%d\n",temp->day,temp->month,temp->year);
                printf("City: %s\n\n",temp->city);
            }
            temp=temp->link;
        }
    }
   temp = head;
    a=count("O+");
    if(a!=0)
    {
         printf("\nBlood Group: O+ (%d)\n\n",a);
        while(temp!=NULL)
        {
            cmp=strcmp(temp->bg,"O+");
            if(cmp==0)
            {
                printf("Name: %s\n",temp->name);
                printf("Mobile No: %s\n",temp->cell);
                printf("Date of Donation: %d/%d/%d\n",temp->day,temp->month,temp->year);
                printf("City: %s\n\n",temp->city);
            }
            temp=temp->link;
        }
    }
    temp = head;
     a=count("O-");
     if(a!=0)
     {
         printf("\nBlood Group: O- (%d)\n\n",a);
        while(temp!=NULL)
        {
            cmp=strcmp(temp->bg,"O-");
            if(cmp==0)
            {
                printf("Name: %s\n",temp->name);
                printf("Mobile No: %s\n",temp->cell);
                printf("Date of Donation: %d/%d/%d\n",temp->day,temp->month,temp->year);
                printf("City: %s\n\n",temp->city);
            }
            temp=temp->link;
        }
     }
     getch();
     system("cls");
     home();
}

int usernamecheck(char name[10])
{
    node *temp=head;
    int cmp,x=1;
    while(temp!=NULL)
    {
        cmp=strcmp(name,temp->user_name_saved);
        if(cmp==0)
        {
            x=0;
            printf("\nUsername Exist. Try Another\n\n");
            break;
        }
        temp=temp->link;
    }
    return x;
}

void reg()
{
    char usernt[10];
    node *temp=(node*)malloc(sizeof(node));
    int aaa;
    again1:
    printf("*****************\n* Registraition *\n*****************\n\n\n");
    printf("0. Back\n\nNick Name: ");
    scanf("%s",temp->name);
    printf("\n");
    int index,length=strlen(temp->name);

   int cmp=strcmp(temp->name,"0");
    if(cmp==0)
    {

        cmp=100;
        system("cls");
        mainpage();
    }
     for(index=0;index<length;index++)
    {
        if(!((temp->name[index]>96 && temp->name[index]<123) || (temp->name[index]>64 && temp->name[index]<91)))
        {
            system("cls");
            printf("Use a valid Nick Name\n\n");
            goto again1;
        }
    }
   printf("Blood Group: ");
    scanf("%s",temp->bg);
    printf("\n");
    printf("City: ");
    scanf("%s",temp->city);
    printf("\nMobile No: ");
    scanf("%s",temp->cell);
    printf("\n");
    printf("Did You Donate Blood?\n1. Yes\n2. No\n");
    scanf("%d",&aaa);
    if(aaa==1)
    {
        printf("Date of Last Donation:\n(Formet: d m y)\n");
        scanf("%d%d%d",&temp->day,&temp->month,&temp->year);
    }
    else
    {
        temp->day=0;
        temp->month=0;
        temp->year=0;
    }
    again:
        printf("\n");
    printf("Username: ");
    scanf("%s",usernt);
    int x;
    x=usernamecheck(usernt);
    if(x==0) goto again;

    strcpy(temp->user_name_saved,usernt);
   printf("\n");
    printf("Password: ");
    scanf("%s",temp->pass_saved);
    strcpy(glname,temp->name);
     strcpy(gluser,temp->user_name_saved);
    temp->link=NULL;
    if(head!=NULL)
        temp->link=head;
    head=temp;

    system("cls");
}
