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
void *f1(void *x)
{  int *a=(int *)x;
   int b=*a;
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
{ printf("*************************************************WELCOME*****************************************\n");
  printf("\n\n*****************************************PRIME NUMBERS***********************************************\n");
  printf("\n\n ENTER THE NUMBER TO PRINT THE PRIME NUMBERS LESS THAN OR EQUAL TO THE GIVEN NUMBER\n");
  int n;
  pthread_t th1;
  scanf("%d",&n);
  pthread_create(&th1,NULL,f1,&n);
  pthread_join(th1,NULL);
}
