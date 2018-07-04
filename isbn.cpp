#include<iostream>
#include<cstring>

using namespace std;

class ISBN
{
	string num;
	int size, i,j,k, nm[20],sum,temp,fin;
	public :

		void getdata()
		{
			cout<<"\t\tEnter the ISBN no. : ";
			cin>>num;
			size=num.length();
		}

		int leng()
		{
			return size;
		}

		void convert()
		{
			for(i=0;i<size;i++)
			{
				if(num[i]=='x'||num[i]=='X')
				nm[i]=10;
				else
				nm[i] = num[i] - '0';
				//cout<<nm[i];
			}
		}

		void ISBN_10()
		{
			sum=0;
			for(i=0;i<size;i++)
			{
				j=i;
				if(i<size-1)
				sum = sum + ((j+1)*nm[i]);
				temp=nm[i];
			}
			fin=sum%11;
			if(fin==temp)
			cout<<"\t\tIt's an ISBN 10 Number!";
			else
			cout<<"\t\tIT's not an ISBN Number!";

		}

		void ISBN_10_val()
		{
			sum=0;
			for(i=0;i<size;i++)
			{
				j=i;
				sum = sum + ((j+1)*nm[i]);
			}
			fin = sum%11;
			nm[size]=fin;
			size++;
			cout<<"\t\tThe check digit : "<<fin<<"\n\t\tActual number : ";
			for(i=0;i<size;i++)
			{
				if(nm[i]==10)
				{
					cout<<"X";
				}
				else
				cout<<nm[i];
			}
		}

		void ISBN_13()
		{
			sum=0;
			for(i=0;i<size;i++)
			{
				j=i+1;
				if(j==1)
				sum = sum + (1*nm[i]);
				else if(j%2==0)
				sum = sum + (3*nm[i]);
				else
				sum = sum + (1*nm[i]);
			}
			fin=sum%10;
			if(fin==0)
			cout<<"\t\tIt's an ISBN 13 Number!";
			else
			cout<<"\t\tIT's not an ISBN Number!";
		}

		void ISBN_13_val()
		{
			sum=0;
			for(i=0;i<size;i++)
			{
				j=i+1;
				if(j==1)
				sum = sum + (1*nm[i]);
				else if(j%2==0)
				sum = sum + (3*nm[i]);
				else
				sum = sum + (1*nm[i]);
			}
			fin = sum%10;
			for(j=0;j<=10;j++)
			{
				temp=fin;
				k=j;
				temp=temp+k;
				if(temp%10==0)
				break;
			}
			nm[size]=k;
			size++;
			cout<<"\t\tThe check digit : "<<k<<"\n\t\tActual number : ";
			for(i=0;i<size;i++)
			{
				if(nm[i]==10)
				{
					cout<<"X";
				}
				else
				cout<<nm[i];
			}

		}

	/*	void display()
		{
			cout<<endl<<size<<endl;
			cout<<num<<endl;
			for(j=0;j<size;j++)
			{
				cout<<nm[j];
			}
			cout<<endl<<temp<<endl;
			cout<<sum<<endl;
			cout<<fin<<endl;
		}*/

};
int main()
{
	ISBN o1;
	int x;
	char ch='n';
	start :
		cout<<"\t\t\t!!Welcome to ISBN Checker!!\n\n"<<endl;
		o1.getdata();
		o1.convert();
		x = o1.leng();
		if(x==10)
			o1.ISBN_10();
		else if(x==13)
			o1.ISBN_13();
		else if(x==9)
			o1.ISBN_10_val();
		else if(x==12)
			o1.ISBN_13_val();
		else
			cout<<"\t\tEnter Valid Number!";
		cout<<"\n\t\tDo you want to visit again(Y/N)? \n\t\tMake a choice : ";
		cin>>ch;
		system("cls");
		if(ch=='Y'||ch=='y')
			goto start;
		else
			exit(0);
		return 0;
}
