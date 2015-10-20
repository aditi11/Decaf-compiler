class Program
{
	int arr[10];
	int maximum(boolean a,int arr)
	{
		int i,max;
		max=0;
		for i=0,i<10
		{
			if(arr[i]>max)
			{
				max=arr[i];
			}
			i=i+1;
		}
		return max;
	}
	int main()
	{
		int max;
		arr[0]=2;
		arr[1]=8;
		arr[2]=1;
		arr[3]=3;
		arr[4]=10;
		arr[5]=6;
		arr[6]=7;
		arr[7]=9;
		arr[8]=8;
		arr[9]=20;
		max=maximum();
		return 0;
	}
}
