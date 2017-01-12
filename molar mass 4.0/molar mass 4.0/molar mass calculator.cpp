/*using stack method*/

#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

char stack[31];					/*stack declaration*/
int g=-1;
void push(char);				/*push declaration*/
char pop();						/*pop declaration*/
void main()
{
	system("color 80");
	cout<<"Note :  Number of atoms/molecules cannot be a fraction.\n";
	bool check=true;
	char e[57][3]={"Hj","He","Li","Be","Bj","Cj","Nj","Oj","Fj","Ne","Na","Mg","Al","Si","Pj","Sj","Cl","Ar","Kj","Ca","Se","Ti","Vj","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Gi","As","Se","Br","Kr","Rb","Sr","Yj","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","Ij","Xe","Cs","Ba"};
	char x,elem[3],num[3];
	int i=0,k=0,len=0,j=0,rotate=0,var=0;
	double m[57]={1.0079,4.0026,6.941,9.0122,10.811,12.0107,14.0067,15.9994,18.9984,20.1797,22.9897,24.305,26.9815,28.0855,30.9738,32.065,35.453,39.984,39.0983,40.078,44.9559,47.867,50.9415,51.9961,54.938,55.845,58.9332,58.6934,63.546,65.39,69.723,72.64,74.9216,78.96,79.904,83.8,85.4678,87.62,88.9059,91.224,92.9064,95.94,98,101.07,102.9055,106.42,107.8682,112.411,114.818,118.71,121.76,127.6,126.9045,131.293,132.9055,137.327};
	double z=0;
	char comp[31];
	while(true)
	{
		check=true;
		k=0;
		rotate=0;
		var=0;
		z=0;
		g=-1;
		cout<<"\nEnter your compound : ";
		cin>>comp;
		for(j=0;j<31;j++)
		{
			if(comp[j]==comp[30])
			{
				break;
			}
		}
		len=j;
		x=comp[0];
		push(x);
		for(i=1;i<(len-1);i++)			/*a=97,z=122,A=65,Z=90,0=48,9=57/changes input*/
		{
			if(comp[i-1]>64 && comp[i-1]<91)
			{
				if(comp[i]>96 && comp[i]<123)
				{
					x=comp[i];
					push(x);
				}
				else if(comp[i]>47 && comp[i]<58)
				{
					x=comp[i];
					push('j');
					push(x);
					rotate++;
				}
				else if(comp[i]>64 && comp[i]<91)
				{
					x=comp[i];
					push('j');
					push('1');
					rotate++;
					push(x);
				}
				else
				{
					check=false;
					break;
				}
			}
			else if(comp[i-1]>96 && comp[i-1]<123)
			{
				if(comp[i]>47 && comp[i]<59)
				{
					x=comp[i];
					push(x);
					rotate++;
				}
				else if(comp[i]>64 && comp[i]<91)
				{
					x=comp[i];
					push('1');
					push(x);
					rotate++;
				}
				else
				{
					check=false;
					break;
				}
			}
			else if(comp[i-1]>47 && comp[i-1]<58)
			{
				if(comp[i]>47 && comp[i]<58)
				{
					x=comp[i];
					push(x);
				}
				else if(comp[i]>64 && comp[i]<91)
				{
					x=comp[i];
					push(x);
				}
				else
				{
					check=false;
					break;
				}
			}
			else
			{
				if(comp[i]<65 || comp[i]>90)
				{
					check=false;
					break;
				}
			}
		}
		if(check==false)
		{
			cout<<"error : invalid compound (1)\n";
			continue;
		}
		if(comp[i-1]>96 && comp[i-1]<123)				/*last value*/
		{
			push('1');
			rotate++;
		}
		else if(comp[i-1]>64 && comp[i-1]<91)
		{
			push('j');
			push('1');
			rotate++;
		}
		while(var<rotate)			/*execution*/
		{
			num[0]='r';
			num[1]='r';
			elem[0]='j';
			elem[1]='j';
			for(i=0;stack[g]>47 && stack[g]<58;i++)
			{
				num[i]=pop();
			}
			k=atof(num);
			for(i=1;true;i--)
			{
				if(stack[g]>47 && stack[g]<58)
				{
					break;
				}
				else if(g==-1)
				{
					break;
				}
				elem[i]=pop();
			}
			for(i=0;i<57;i++)
			{
				if(e[i][0]==elem[0] && e[i][1]==elem[1])
				{
					z=z+(m[i]*k);
					break;
				}
				else if(i==56)
				{
					cout<<"error : invalid compound"<<endl;
					check=false;
					z=0;
					break;
				}
			}
			var++;
		}
		if(z!=0 && check==true)
		{
			cout<<"molar mass of the compound : "<<z<<endl;
		}
		for(i=0;i<len;i++)
		{
			comp[i]=comp[30];
		}
	}
}
void push(char x)
{
	g++;
	stack[g]=x;
}
char pop()
{
	char q;
	q=stack[g];
	stack[g]=stack[g+1];
	g--;
	return q;
}