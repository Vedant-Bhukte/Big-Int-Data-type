#include<stdio.h>
#include<string.h>

typedef struct BigInteger
{
    int arr[1024];
    int size;
}BigInt;

BigInt input()
{
    printf("Enter the number :");
    char s[1000];
    scanf("%s" , s);
    int length = strlen(s);
    BigInt k;
    int z = 0, i;
    for( i = length-1 ; i>=0 ; i--)
	{
        k.arr[z] = s[i]-'0';
        z++;
    }
    k.size = z;
    return k;
}
void printBigInt(BigInt k)
{
	int i;
    for(i = k.size-1 ; i>=0 ; i--)
	{
        printf("%d" , k.arr[i]);
    }
    printf("\n");
}

BigInt subtract(BigInt a , BigInt b)
{
    BigInt ans ;
    if(a.size < b.size)  // checking which is larger
	{
        return subtract(b , a);
    }
	else if(a.size==b.size)
	{
        int i = a.size-1;
        while(i>=0 && a.arr[i]==b.arr[i])
		{
            i--;
        }
        if(i==-1)
		{
            ans.arr[0]=0;
            ans.size = 1;
            return ans;
        }
        if(a.arr[i]<b.arr[i])
		{
            return subtract(b,a);
        }
    }
    int z=0, j=0 , i;
    for(i=0 ; i<b.size ; i++)
	{
        if(a.arr[i]-b.arr[i]<0)
		{
            a.arr[i+1]--;
            a.arr[i]+=10;
        }
        ans.arr[z] = a.arr[i]-b.arr[i];
        if(ans.arr[z]!=0)
		{
            j = i;
        }
        z++;
    }
	for(i=b.size ; i<a.size ; i++)
	{
        if(a.arr[i]!=0)
		{
            j = i;
        }
        if(a.arr[i]<0)
		{
            a.arr[i+1]--;
            a.arr[i]+=10;
        }
        ans.arr[z] = a.arr[i];
        z++;
    }
    ans.size = j+1;
    return ans;
}
BigInt add(BigInt a , BigInt b)
{
    if(a.size<b.size)
	{
        return add(b ,a);
    }
    BigInt ans ;
    int z = 0;
    int c = 0, i;
    for( i = 0 ; i<b.size ; i++)
	{
        int temp = a.arr[i]+b.arr[i]+c;
        ans.arr[z] = temp%10;
        c  = temp/10;
        z++;
    }
    for( i = b.size ; i<a.size ; i++)
	{
        int temp = a.arr[i]+c;
        ans.arr[z] = temp%10;
        c  = temp/10;
        z++;
    }
    if(c>0)
	{
        ans.arr[z] = c;
        z++;
    }
    ans.size = z;
    return ans;
    
}
BigInt multiply(BigInt a , BigInt b)
{
	int i;
    BigInt ans ;
    ans.size = 0;
    for( i = 0 ; i<a.size ; i++)
	{
        int c = 0;
        BigInt t ;
        int z = 0, j;
        for( j = 0 ; j<b.size ; j++)
		{
            int temp = a.arr[i]*b.arr[j] + c;
            t.arr[z] = temp%10;
            c=temp/10;
            z++;
        }
        if(c>0)
		{
            t.arr[z] = c;
            z++;
        }
        t.size = z;
        BigInt pro1;
        int ind = 0, p;
        for( p = 0 ; p<i ; p++)
		{
            pro1.arr[ind] = 0;
            ind++;
        }
        for( p = 0 ; p<t.size ; p++)
		{
            pro1.arr[ind] = t.arr[p];
            ind++;
        }
        pro1.size = ind;
        ans = add(ans , pro1);
    }
    return ans;
}

BigInt moduloFunc(BigInt a , BigInt b)
{
    while(a.size>=b.size)
	{
        if(a.size==b.size)
		{
            int i = a.size-1;
            while(i>=0 && a.arr[i]==b.arr[i])
			{
                i--;
            }
            if(i==-1)
			{
                a.arr[0]=0;
                a.size = 1;
                break;
            }
            if(a.arr[i]<b.arr[i])
			{
                break;
            }
        }
        a = subtract(a , b);
    }
    return a;
}
BigInt fact(BigInt a)
{
    BigInt ans ;
    ans.arr[0] = 1;
    ans.size = 1;
    while(a.size!=1 || a.arr[0]!=0)
	{
        ans = multiply(ans , a);
        BigInt b ;
        b.arr[0] = 1;
        b.size = 1;   
        a = subtract(a , b);
    }
    return ans;
}
BigInt power(BigInt a, BigInt b)
{
    BigInt one ;
    one.arr[0] = 1;
    one.size = 1;  
    if(b.size==1 && b.arr[0]==0)
	{
        return one;
    }
    BigInt temp = a;
    while(b.size!=1 || b.arr[0]!=1)
	{
        temp = multiply(temp , a); 
        b = subtract(b , one);
    }
    return temp;
}
BigInt convert(int a)
{
    BigInt ans;
    int z = 0;
    while (a!=0)
    {
        ans.arr[z] = a%10;
        a/=10;
        z++;
    }
	ans.size=z;
	return ans;
}
int main()
{
    ///*
	BigInt a = input();
    printBigInt(a);
    //BigInt b = input();
    //printBigInt(b);
    printf("\n :"  );
    //*
	BigInt ans;
	//ans=moduloFunc(a,b);
	//ans=power(a,b);
    ans=fact(a);
    printBigInt(ans);
    //*/
    //*/
    
    /*
    int num;
    printf("\nEnter an integer : ");
    scanf("%d", &num);
    BigInt n;
    n=convert(num);
    printBigInt(n);
    */
	
	return 0;
}
