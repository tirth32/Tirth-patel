
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char Emp_Name[20][30];
int presentAttendance[20]={0};
int absentAttendance[20]={0};
int indexNumber=0;
void checkAttendance()
{
    int i;
    printf("\nTotal Present | Total Absent\n");   
    for ( i = 0; i < indexNumber; i++)
    {
        printf("%s",Emp_Name[i]);
        printf("              %d             %d\n",presentAttendance[i],absentAttendance[i]);                           
    }    
}
void addemployee()
{
    int i,num,add;   
    if (indexNumber==0)
    {
        printf("Enter how many employee you want to add: ");
        fflush(stdin);
        scanf("%d",&num);
        for ( i = 0; i < num; i++)
        {        
            printf("\nEnter %demployee name to add in attendance ragister: ",i+1);    
            fflush(stdin);
            gets(Emp_Name[i]);  
            indexNumber++;              
        }           
    }
    else
    {        
        printf("Enter how many employee you want to add: ");
        fflush(stdin);
        scanf("%d",&num);
        add=indexNumber+num;
        for ( i = indexNumber; i < add; i++)
        {        
            printf("\nEnter %demployee name to add in attendance ragister: ",i+1);    
            fflush(stdin);
            gets(Emp_Name[i]);  
            indexNumber++;              
        }
    }        
}
void removeemployee()
{
    char name[30];
    printf("Enteremployee name to remove: ");
    fflush(stdin);
    gets(name);
    for (int i = 0; i < indexNumber; i++)
    {
        if (strcmp(name,Emp_Name[i])==0)
        {          
            for (int j = i; j < indexNumber; j++)
            {
                strcpy(Emp_Name[j],Emp_Name[j+1]);  
                presentAttendance[i]=presentAttendance[i+1];
                absentAttendance[i]=absentAttendance[i+1];
            }     
            indexNumber--;
            printf("\n%semployee is removed\n",name);
            break;                    
        }
        else if(i==indexNumber-1)
        {
            printf("This name is not exits\n");
        }       
    }        
}
void takeAttendance()
{
    int i;
    char ch;
    printf("\nEnter Y for present and N for absent\n");
    for ( i = 0; i < indexNumber; i++)
    {
        repeate:
        printf("%d. %s is present: ",i+1,Emp_Name[i]);
        fflush(stdin);
        scanf("%c",&ch);
        if (ch=='Y'||ch=='y')
        {
            presentAttendance[i]+=1;
        }
        else if (ch=='N'||ch=='n')
        {            
            absentAttendance[i]+=1;                                                    
        } 
        else
        {
            printf("Invalid character Try again\n");
            goto repeate;
        }              
    }    
}
void main()
{
    int choose;
    do
    {
        printf("\n**********Main Menu***********\n");
        printf("Enter 1 for addemployee\n");
        printf("Enter 2 for take attendance\n");
        printf("Enter 3 for check attendance\n");
        printf("Enter 4 for removeemployee\n");
        printf("Enter 5 for exit\n");
        printf("Please choose any menu: ");
        fflush(stdin);
        scanf("%d",&choose);
        switch (choose)
        {
        case 1:
            addemployee();
            break;        
        case 2:
            takeAttendance();
            break;        
        case 3:
            checkAttendance();
            break;        
        case 4:
            removeemployee();
            break;        
        case 5:
            exit(0);
            break;        
        }
    } while  (choose!=5);
}
