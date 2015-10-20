class Program
{
	int arr[10];
	int bsearch(int arr,int lower,int upper,int a)
	{
		int middle;
		if(upper<lower)
		{
			return -1;
		}
		middle=lower+(upper-lower)/2;
		if(arr[middle]==a)
		{
			return middle;
		}
		if(arr[middle]>a)
		{
			return bsearch(arr,lower,middle-1,a);
		}
		if(arr[middle]<a)
		{
			return bsearch(arr,middle+1,upper,a);
		}
	}
	int main()
	{
		int pos;
		arr[0]=1;
		arr[1]=3;
		arr[2]=7;
		arr[3]=4;
		arr[4]=9;
		arr[5]=5;
		arr[6]=6;
		arr[7]=0;
		arr[8]=2;
		arr[9]=8;
		pos=bsearch(arr,0,9,2);
		return 0;
	}
}
