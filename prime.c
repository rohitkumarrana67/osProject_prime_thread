#include<stdio.h>
#include<pthread.h>

int prime(int x)
 { int flag=1;
 for(int i=2;i<=x/2;i++)
   {if(x%i==0)
      flag++;
    }
   if(flag==1)
    { return 1;
     }
   else return 0;

}
void *f1()
{  printf("*********************************************Welome*********************************\n");
   printf("*********************************************PRIME NUMBER*****************************\n");
   printf("*************************************************************************************\n");
   printf("**********ENTER ANY NUMBER GREATER THAN 1 TO FIND THE PRIME NUMBERS UPTO THAT NUMBER************\n");
}
void *f2(void *x)
{  int *a=(int *)x;
   int b=*a;
    if(b<=1)
{  printf(" prime no. can't be less than or equal to 1");
}
   if(b<=1)
   {
   	 printf("PRIME number can't be less than or equal to 1\n");
   }
   printf("\n\n\n PRIME NUMBERS LESS THAN OR EQUAL TO %d ARE:\n",b);
   if(b>=2)
   { printf("2\n");
     for(int i=3;i<=b;i++)
     {   int  test=prime(i);
         if(test==1
)
          { printf("%d\n",i);

           }
      }
   }
}

void main()
{ 
  int n;
  pthread_t th1,th2;
  pthread_create(&th1,NULL,f1,NULL);
  scanf("%d",&n);
  pthread_create(&th2,NULL,f2,&n);
  pthread_join(th1,NULL);
  pthread_join(th2,NULL);
}
