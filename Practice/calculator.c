#include<stdio.h>
int main()
{
int a,b,c;
char ch;

do{
printf("Enter two numbers\n");
scanf("%d%d", &a, &b);
printf("Enter your choice:\n 1: Addition\n 2: Subtraction\n 3: Multiplication\n 4: Division\n 5: Remainder\n 6: Bitwise AND\n 7: Bitwise OR\n\nChoice:");
scanf("%d", &c);

switch(c)
{
	case 1:
		printf("%d+%d=%d", a, b, a+b);
		break;
	case 2:
		printf("%d-%d=%d", a, b, a-b);
			
		break;
	
	case 3:
		printf("%d*%d=%d", a, b, a*b);
		
		break;

	case 4:
		printf("%d/%d=%f", a, b, (float)a/(float)b);
			
		break;
	case 5:
		printf("%d%%%d=%d", a, b, a%b);
	
		break;
	case 6:
		printf("%d&%d=%d", a, b, a&b);

		break;
	case 7:
	
		printf("%d|%d=%d", a, b, a|b);

		break;
	default: 
		printf("Error");
		break;
}

  printf("\n\n");
 
 printf("Would you like to continue ? y\\n  ");
 scanf("%s",&ch);
  }while(ch=='y');

return 0;
}
