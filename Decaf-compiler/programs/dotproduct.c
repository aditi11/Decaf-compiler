class Program
{
	int a[8];
	int b[8];
	int dotproduct()
	{
		int i;
		int sum;
		sum=0;
		for i=0,i<8
		{
			sum=sum+(a[i]*b[i]);
		}
		return sum;
	}
	int main()
	{
		int sum;
		a[0]=2;
		a[1]=4;
		a[2]=8;
		a[3]=2;
		a[4]=1;
		a[5]=3;
		a[6]=0;
		a[7]=0;
		b[0]=1;
		b[1]=7;
		b[2]=3;
		b[3]=2;
		b[4]=4;
		b[5]=3;
		b[6]=9;
		b[7]=1;
		sum=dotproduct();
		return 0;
	}
}
