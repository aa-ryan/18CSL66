#include <stdio.h>
#include<string.h>
#include<stdlib.h>

void firstset();
void followset();
void parsingtable();
void parseinput();
void err();

int i,count,j,k,n,l[10],temp;
char grm[10][20],fst[10][20],fol[10][20],stk[20],matched[20],inpt[20],inp[20];

int  main()
{   
printf("The given grammar is\n A->aBa\n B->bB|@ \n\n");
    	printf("Enter the number of rules\n");
    	scanf("%d",&n);
    	printf("Enter the grammar and please enter @ instead of Epsilon\n");
    	for(i=0;i<n;i++)
		scanf("%s",grm[i]);
	firstset();
	followset();
	parsingtable();
	parseinput();
}

void firstset()
{
	printf("\nThe First Set is \n");
	for(i=0;i<n;i++)
	{
		printf("FIRST[%c]={",grm[i][0]);
		count=0;
		j=3;
		while(grm[i][j]!='\0')
		{
			if(!((grm[i][j]>64)&&(grm[i][j]<91)))
			{
				fst[i][count]=grm[i][j];
				printf("%c,",fst[i][count]);
				count=count+1;
			}
			for(;grm[i][j]!='|'&&grm[i][j]!='\0';j++);
			j=j+1;
		}
		printf("\b}\n");
	}
}

void followset()
{
	printf("\nThe Follow set is\n");
	for(k=0;k<n;k++)
	{
		count=0;
		printf("FOLLOW[%c]={",grm[k][0]);
		if(k==0)
		{
			printf("$,");
			fol[k][count]='$';
			count=count+1;
		}
		for(i=0;i<n;i++)
		{
			for(j=3;grm[i][j]!='\0';j++)
			{
				if((grm[i][j]==grm[k][0])&&(grm[i][j+1]!='\0'&&grm[i][j+1]!='|'))
				{
					if(!((grm[i][j+1]>64)&&(grm[i][j+1]<91)))
					{
					    fol[k][count]=grm[i][j+1];
						printf("%c,",fol[k][count]);
						count=count+1;
					}
				}
			}	
		}
		printf("\b}\n");
	}
}

void parsingtable()
{
    	printf("\nThe Parsing Table is\n");
	char p[10]="A->aBa",q[10]="B->bB",r[10]="B->@",tble[2][4];
	tble[0][0]='A';
	tble[1][0]='B';
	int j,k;
	for(i=0;i<n;i++)
	{
		j=0;
		while(fst[i][j]!='\0')
		{
			if(fst[i][j]=='a')
				tble[i][1]='p';
			else if(fst[i][j]=='b')
				tble[i][2]='q';
			else if(fst[i][j]=='@')
			{
				k=0;
				for(k=0;fol[i][k]!='\0';k++)
				{
					if(fol[i][k]=='a')
						tble[i][1]='r';
				}
			}
			j++;
		}
	}
	printf("\ta\tb\t$\t\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<4;j++)
		{
		            	if(tble[i][j]!='p'&&tble[i][j]!='q'&&tble[i][j]!='r'&&tble[i][j]!='A'&&tble[i][j]!='B')
				tble[i][j]=' ';
			if(tble[i][j]=='p')
				printf("%s\t",p);
			else if(tble[i][j]=='q')
				printf("%s\t",q);
			else if(tble[i][j]=='r')
				printf("%s\t",r);
			else 
				printf("%c\t",tble[i][j]);
			
  
		}
		printf("\n");
	}
}

void parseinput()
{
	printf("\nEnter the input string\n");
	scanf("%s",inp);
	strcpy(inpt,inp);
	strcat(inpt,"$");
	printf("matched\t\tstack\t\tinput\t\taction\n");
	strcpy(stk,"A$");
	i=0;
	j=0;
	k=0;	
	while(matched!=inp)
	{
		 if(stk[i]==inpt[j])
	    	{
	   		 if(stk[i]=='$')
	        		{
	               		printf("%s\t\t%s\t\t%s\t\t accepted\n",matched,stk,inpt);
	               		break;
	        		}
	        		temp=stk[i];
	        		printf("%s\t\t%s\t\t%s\t\t pop %c\n",matched,stk,inpt,temp);
	        	            stk[i]=inpt[j]=' ';
	        		i=i+1;
	        		j=j+1;
	        		matched[k]=temp;
		    	k=k+1;
	    	}
		else if(stk[i]=='A'&&inpt[j]=='a')
		{
			i=0;
			printf("%s\t\t%s\t\t%s\t\t A->aBa\n",matched,stk,inpt);
			strcpy(stk,"aBa$");
		}
		else if(stk[i]=='B')
		{
			i=0;
			if(inpt[j]=='b')
			{
				printf("%s\t\t%s\t\t%s\t\t B->bB\n",matched,stk,inpt);
				strcpy(stk,"bBa$");
			}
			else if(inpt[j]=='a')
			{
				printf("%s\t\t%s\t\t%s\t\t B->@\n",matched,stk,inpt);
				strcpy(stk,"a$");
			}
		}
		else if(stk[i]=='$'&&inpt[j]=='$')
			break;
		else
			err();
	}
}


void err()
{
 printf("%s\t\t%s\t\t%s\t\t error\n",matched,stk,inpt);
    	exit(0);
}


