class Program
{
	int arr[10];
	void bsort()
	{
		int i,temp;
		for i=0,i<10
		{
			for j=0,j<9-i
			{
				if(arr[j]>arr[j+1])
				{
					temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
			}
		}
		return;
	}
	int main()
	{
		arr[0]=7;
		arr[1]=4;
		arr[2]=8;
		arr[3]=3;
		arr[4]=9;
		arr[5]=1;
		arr[6]=0;
		arr[7]=5;
		arr[8]=6;
		arr[9]=2;
		bsort();
		return 0;
	}
}
