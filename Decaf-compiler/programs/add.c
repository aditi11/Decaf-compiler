class Program
{
	int a[5];
	int b[5];
	int c[5];
	void add()
	{
		int i;
		for i=0,i<5
		{
			c[i]=a[i]+b[i];
			i=i+1;
		}
		return;
	}
	int main()
	{
		a[0]=1;
		a[1]=1;
		a[2]=1;
		a[3]=1;
		a[4]=1;
		b[0]=1;
		b[1]=1;
		b[2]=1;
		b[3]=1;
		b[5]=1;
		c[0]=1;
		c[1]=1;
		c[2]=1;
		c[3]=1;
		c[4]=1;
		add(a,b,c);
		return 0;
	}
}
