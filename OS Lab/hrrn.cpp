//hrrn
#include <bits/stdc++.h>
using namespace std;

vector <int> c,v;
vector <float> b;

float hrn(int t,int at,int bt)
{
	float w = (t-at)+bt;
	return w/bt;
}

void printTable(int a[][6],int r)
{
	cout<<"Process Table\n\n";
	float sum3 = 0, sum4 = 0, sum5 = 0;
	int sum = 0;
	for(int i = 0;i < r;i++)
	{
		sum3 = sum3 + c[i];
		a[i][3] = sum3;
		a[i][4] = (a[i][3] - a[i][1]);
		sum4 = sum4 + (a[i][3] - a[i][1]);
		a[i][5] = (a[i][4] - a[i][2]);
		sum5 = sum5 + (a[i][4] - a[i][2]);
	}
	cout<<"Process\tA.T\tB.T\tC.T\tT.A.T\tW.T\n";
	for(int i = 0;i < r;i++)
	{
		for(int j = 0;j < 6;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"\n---------------------------------------------\n";
	
	cout<<"AVG : \t\t\t"<<sum3/r<<"\t"<<sum4/r<<"\t"<<sum5/r<<"\n\n";
}

void gannt(int a[][6],int r)
{
	cout<<"GANNT CHART\n";
	cout<<"|\t";
	for(int i = 0;i < r;i++)
	{
		cout<<"P"<<i+1<<"\t|\t";
	}
	cout<<endl;
	cout<<0;
	for(int i = 0;i < r;i++)
		cout<<"\t\t"<<a[i][3];
	cout<<endl;
}

int main()
{
	int a[10][6];
	int i,j,r;
	cout<<"\nEnter the number of process : ";
	cin>>r;
	for(i = 0;i < r;i++)
	{
		cout<<"\nEnter the process id : ";
		cin>>a[i][0];
		cout<<"\nEnter the arrival time : ";
		cin>>a[i][1];
		cout<<"\nEnter the burst time : ";
		cin>>a[i][2];
	}
    
    for(i = 0;i < r;i++)
    	c.push_back(a[i][2]);

	int min = INT_MAX,x;
	for(i = 0;i < r;i++)
	{
		if(a[i][1] < min)
		{
			min = a[i][1];
			x = i;
		}
	}

	swap(c[0],c[x]);

	for(j = 0;j < 3;j++)
		swap(a[0][j],a[x][j]);
    
    for(i = 1;i < r-1;i++)
    {
    	int t = 0;
    	for(j = 0;j < i;j++)
    		t = t + c[j];
    	v.push_back(t);
    	min = t;
    	for(j = i;j < r;j++)
    	{
    		if(a[j][1] < min)
    	    {
    	        b.push_back(hrn(t,a[j][1],a[j][2]));
    	    }
    	}
        
        float m = b[0];

        for(j = 0;j < b.size();j++)
        {
            if(b[j] > m)
            	m = b[j];
        }

        for(j = i;j < r;j++)
        {
        	if(m == hrn(t,a[j][1],a[j][2]))
        		{
        			x = j;
        			break;
        		}
        }

    	swap(c[i],c[x]);
    	for(j = 0;j < 3;j++)
    		swap(a[i][j],a[x][j]);

    	b.clear();

    }
    printTable(a,r);   
    gannt(a,r);
}
