#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 30
int main()
{ 
    int num1, num2, num3, count=0, resultTrue[N],flag;//result:用户输入结果 resultTrue:正确结果 flag:0 先计算左边 1先计算右边
    char op1, op2;
    srand(time(NULL)); //启动随机数生成器
    for(int count=0;count<N;)
   {
    num1 = rand() % 100;
    num2 = rand() % 100;
    num3 = rand() % 100;
    switch (num1 % 4)
    {
        case 0:       	
            op1 = '+';
        break;
        case 1:
            op1 = '-';
        break;
        case 2:
            op1 = '*';
        break;
        case 3:
            op1 = '/';
        break;
        default:
        break;
    }
    switch (num2 % 4)
    {
    	case 0:
    		op2 = '+';
    		flag = 0;
    	break;
    	case 1:
            op2 = '-';
            flag = 0;
        break;
        case 2:
            op2 = '*';
           	if((op1=='*')||(op1=='/')) flag = 0;
           	else flag = 1;
        break;
        case 3:
            op2 = '/';
            if((op1=='*')||(op1=='/')) flag = 0;
            else flag = 1;
        break;
        default:
        break;
    }
    
    if(flag==0)
    {
    	resultTrue[count] = 0;
        switch (op1)
        {
        	case '+':
        		resultTrue[count] = num1+num2;
        	break;
            case '-':
        	    resultTrue[count] = num1-num2;
            break;
            case '*':
            	num1=rand()%10;
            	num2=rand()%10;
        	    resultTrue[count] = num1*num2;
            break;
            case '/':
            	if(num1%num2!=0)
            	{
            		num2=rand()%10;
            		num1=num2*(rand()%10+1);
            	}
        	    resultTrue[count] = num1/num2;
            break;
            default:
            break;
        }
        switch (op2)
        {
        	case '+':
        		resultTrue[count] += num3;
        	break;
        	case '-':
        		resultTrue[count] -= num3;
        	break;
        	case '*':
        		num3=rand()%10;
        		resultTrue[count] *= num3;
        	break;
        	case '/':
        		if(resultTrue[count]%num3!=0)
        		{
        			for(int j=2;j<=resultTrue[count];j++)
					     if(resultTrue[count]%j==0)	
						     num3=j;      
        		}
        		resultTrue[count] /= num3;
        	break;
        	default:
        	break;
        }
    }
    else
    {
    	resultTrue[count] = 0;
    	switch (op2)
    	{
    		case '+':
    			resultTrue[count] = num2+num3;
    		break;
    		case '-':
    			resultTrue[count] = num2-num3;
    		break;
    		case '*':
    			num2=rand()%10;
            	num3=rand()%10;
    			resultTrue[count] = num2*num3;
    		break;
    		case '/':
    			if(num2%num3!=0)
            	{
            		num3=rand()%10;
            		num2=num3*(rand()%10+1); 
            	}
    			resultTrue[count] = num2/num3;
    		break;
    		default:
			break;
        }
        switch (op1)
		{
			case '+':
				resultTrue[count] = num1 + resultTrue[count];
		    break;
		    case '-':
		        resultTrue[count] = num1 - resultTrue[count];
		    break;
		    case '*':
		    	num1=rand()%10;
			    resultTrue[count] = num1 * resultTrue[count];
		    break;
		    case '/':
		    	if(num1 % resultTrue[count]!=0)
			        continue;      
		        resultTrue[count] = num1 / resultTrue[count];
		    break;
		    default:
		    break;
		}
    }
    if(resultTrue[count]>100||resultTrue[count]<0)
    {
	   continue;
    }
    printf("%d %c %d %c %d = %d\n",num1,op1,num2,op2,num3,resultTrue[count]);
    count++;
   }
   return 0;
    
}                                                   
