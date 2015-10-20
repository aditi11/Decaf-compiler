class Program
{
	int arr[10];
	int minimum()
	{
		int i;
		int min;
		min=1000;
		for i=0, i<10
		{
			if(arr[i]<min)
			{
				min=arr[i];
			}
			i=i+1;
		}
		return min;
	}
	int main()
	{
		int min;
		arr[0]=2;
		arr[1]=8;
		arr[2]=1;
		arr[3]=3;
		arr[4]=10;
		arr[5]=6;
		arr[6]=7;
		arr[7]=9;
		arr[8]=8;
		arr[9]=0;
		min=minimum();
		return 0;
	}
}
