#include <stdio.h>
#include <stdlib.h>


int arr[100],len=100;

void linSearch( int num)
{
	int flag=0;
	for(int i=0;i<len;i++)
	{
		if(arr[i]==num)
		{
			printf("Number found at %d index of array\n",i);
			flag=1;
			return;
		}
	}
	if(flag==0)
	printf("Sorry! number doesn't exist\n");
}



void binSearch( int num)
{
	int f,l,m,i,j,min,temp;
	printf("Sorting the array to perform binary search\n");
	for (i = 0; i < len-1; i++) 
    { 
        min = i; 
        for (j = i+1; j < len; j++) 
        {
			if (arr[j] < arr[min]) 
				min = j;
		}
  
        
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    } 
	printf("Array has been sorted as...\n");
	for (i = 0; i < len-1; i++) 
    { 
		printf(" %d ",arr[i]);
	}
	f = 0;
    l = len-1;
    m = (f+l)/2;

    while (f <= l) 
    {
		if (arr[m] < num)
		  f = m + 1;
		else if (arr[m] == num) 
		{
		  printf(" \n %d found at loc-  %d.\n", num, m+1);
		  break;
		}
		else
		  l = m - 1;

		m = (f + l)/2;
	  }
	  if (f > l)
		printf(" %d is not present in the list.\n", num);
}
int main()
{
	int ch,ele,j;
	printf("Creating array of '%d' random numbers from range[1,100]\n",len);
	for(j=0;j<len;j++)
	{
		arr[j]=rand() % 100 + 1;
	}
	printf("\nPrinting the numbers...\n");
	for(j=0;j<len;j++)
	{
		printf(" %d ",arr[j]);
	}
	do
	{
		printf("\n \n 1. linear search \n 2. binary search \n 3. Exit \n \t Enter option\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("enter the number to be searched[1-100]\n");
			scanf("%d",&ele);
			linSearch(ele);
			break;
			
			case 2:
			printf("enter the number to be searched[1-100]\n");
			scanf("%d",&ele);
			binSearch(ele);
			break;
			
			case 3: 
			break;
			
			default:
			printf("Invalid option !\n");
		}
	}while(ch!=3);
	return 0;
}