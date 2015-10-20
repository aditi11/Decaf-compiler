class Program
{
	int arr[10];
	int temp1[10];
	int temp2[10];
	void merge(int lower,int upper)
	{
		int mid;
		int i,j,k;
		mid=(lower+upper)/2;
		for i=0,i<mid-lower+1
		{
			temp1[i]=arr[lower+i];
		}
		for i=0,i<upper-mid
		{
			temp2[i]=arr[mid+1+j];
		}
		k=lower;
		for i=0,i<mid-lower+1
		{
			for j=0,j<upper-mid
			{
				if(temp1[i]<=temp2[j])
				{
					arr[k]=temp1[i];
					i=i+1;
				}
				else
				{
					arr[k]=temp2[j];
					j=j+1;
				}
				k=k+1;
			}
		}
		for i=i,i<mid-lower+1
		{
			arr[k]=temp1[i];
			i=i+1;
			k=k+1;
		}
		for j=j,j<upper-mid
		{
			arr[k]=temp2[j];
			j=j+1;
			k=k+1;
		}
	}
	void mergesort(int lower,int upper)
	{
		int mid;
		if(lower<upper)
		{
			mid=(lower+upper)/2;
			mergesort(lower,mid);
			mergesort(mid+1,upper);
			merge(lower,upper);
		}
		return;
	}
	int main()
	{
		arr[0]=13;
		arr[1]=3;
		arr[2]=0;
		arr[3]=4;
		arr[4]=9;
		arr[5]=5;
		arr[6]=1;
		arr[7]=3;
		arr[8]=8;
		arr[9]=13;
		mergesort(0,9);
		return 0;
	}
}
