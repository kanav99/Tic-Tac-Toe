#include<bits/stdc++.h>

using namespace std;

const char* getAction()
{
    #ifdef _WIN32
    return "cls";
    #elif _WIN64
    return "cls";
    #elif __linux__
    return "clear";
    #endif
}  

class Match
{
	public:
	char p1[50];
	char p2[50];
	int A[9];
	int win;
	Match(char x[50],char y[50])
	{
		strcpy(p1,x);
		strcpy(p2,y);
	}
	Match()
	{
		strcpy(p1,"");
		strcpy(p2,"");
	}
};
//int ml[][9];
//int matches;
void loadArray();
void singlePlayer();
void multiPlayer();
void printGrid(char A[3][3]);
void logger();
bool check(char A[3][3]);
int main()
{
	loadArray();
	int x;
	do{
	cout<<"###########################################################################"<<endl;
	cout<<"-------------------------TIC TAC TOE(SELF LEARNING)------------------------"<<endl;
	cout<<"###########################################################################"<<endl;
	cout<<"                           1. Single Player                                "<<endl;
	cout<<"                           2. Two Player                                   "<<endl;
	cout<<"                           3. Log                                          "<<endl;
	cout<<"                           4. Exit                                         "<<endl;
	cout<<"                     Number of Times Played= "<</*matches<<*/endl;
	cout<<"Enter the choice>>";
	cin>>x;
	cin.get();
	system(getAction());
	if(x==1)
		singlePlayer();
	else if(x==2)
		multiPlayer();
	else if(x==3)
		logger();
	}while(x!=4);
}
void singlePlayer()
{
	cout<<"Coming Soon!\n";
	cout << "Press any key to continue";
	cin.get();
	cin.ignore();
	system(getAction());
}
void multiPlayer()
{
	char A[3][3];
	int ch,i;
	char name1[50];
	char name2[50];
	cout<<"Enter Player 1's name>>";
	cin.getline(name1, 50);
	cout<<"\nEnter Player 2's name>>";
	cin.getline(name2, 50);
 	system(getAction());
	
	Match N(name1,name2);
	for(i=0;i<9;i++){
	A[i/3][i%3]=i+48;
	N.A[i]=-1;
    }
	
	for(i=0;i<9;i++)
	{
		printGrid(A);
		if(i%2==0){
			cout<<name1<<"- Make a move>>";
			cin>>ch;
			while(ch < 0 || ch > 8) {
				cout << "Invalid number entered! Enter again>>";
				cin >> ch;
			}
			while(A[ch/3][ch%3]=='X'||A[ch/3][ch%3]=='O')
			{
				cout<<"Invalid Move! Try Again>>";
				cin>>ch;
			}
			A[ch/3][ch%3]='X';	
		}
		else{
			cout<<name2<<"- Make a move>>";
			cin>>ch;
			while(ch < 0 || ch > 8) {
				cout << "Invalid number entered! Enter again>>";
				cin >> ch;
			}
			while(A[ch/3][ch%3]=='X'||A[ch/3][ch%3]=='O')
			{
				cout<<"Invalid Move! Try Again>>";
				cin>>ch;
			}
			A[ch/3][ch%3]='O';
		}
		N.A[i]=ch;
		if(check(A))
		{	
			system(getAction());
			printGrid(A);
			cout<<(i%2==0?name1:name2);
			N.win=(i%2==0?1:2);
			cout<<" wins!\n";
			cout << "Press any key to continue";
			cin.get();
			cin.ignore();
			system(getAction());
			break;
		}
	system(getAction());
	}
	if(!check(A))
	{
		cout<<"Match Tie!\n";
		cout << "Press any key to continue";
		cin.get();
		cin.ignore();
		system(getAction());
		N.win=0;
	}
	fstream fout;
	fout.open("log",ios::app|ios::binary);
	fout.write((char*)&N,sizeof(N));
	fout.close();
	
}
void logger()
{
	Match A;
	fstream fin;
	fin.open("log",ios::in|ios::binary);
	cout<<"###########################################################################"<<endl;
	cout<<"                               PREVIOUS MATCHES                            "<<endl;
	cout<<"###########################################################################"<<endl;
	cout<<"# Sr.No ##### P1 ################## P2 #################### WINNER ########"<<endl;
	int s=1;
	while(fin.read((char*)&A,sizeof(A)))
	{
		cout<<left;
		cout<<"  "<<setw(13)<<s;
		s++;
		cout<<setw(22)<<A.p1<<setw(24)<<A.p2;
		if(A.win==1)
			cout<<A.p1<<endl;
		else if(A.win==2)
			cout<<A.p2<<endl;
		else
			cout<<"Tie\n";
	}
	fin.close();
	cout<<"\n###########################################################################"<<endl;
	system("pause");
	system(getAction());
}
void printGrid(char A[3][3])
{
	cout<<"###########################################################################"<<endl;
	cout<<"                             |         |                                   "<<endl;
	cout<<"                        "<<A[0][0]<<"    |    "<<A[0][1]<<"    |    "<<A[0][2]<<endl;
	cout<<"                    ---------*---------*---------                          "<<endl;
	cout<<"                        "<<A[1][0]<<"    |    "<<A[1][1]<<"    |    "<<A[1][2]<<endl;
	cout<<"                    ---------*---------*---------                          "<<endl;
	cout<<"                        "<<A[2][0]<<"    |    "<<A[2][1]<<"    |    "<<A[2][2]<<endl;
	cout<<"                             |         |                                   "<<endl;
	cout<<"###########################################################################"<<endl;
}
bool check(char A[3][3])
{
	int i,j;
	if((A[0][0]==A[0][1])&&(A[0][1]==A[0][2])) return true;
	if((A[1][0]==A[1][1])&&(A[1][1]==A[1][2])) return true;
	if((A[2][0]==A[2][1])&&(A[2][1]==A[2][2])) return true;
	if((A[0][0]==A[1][0])&&(A[1][0]==A[2][0])) return true;
	if((A[0][1]==A[1][1])&&(A[1][1]==A[2][1])) return true;
	if((A[0][2]==A[1][2])&&(A[1][2]==A[2][2])) return true;
	if((A[0][0]==A[1][1])&&(A[1][1]==A[2][2])) return true;
	if((A[0][2]==A[1][1])&&(A[1][1]==A[2][0])) return true;
	return false;
}
void loadArray()
{
	/*fstream fin;
	fin.open("log",ios::in|ios::binary);
	Match X;
	while(fin.read((char*)&X,sizeof(X)))
	{
		for(i=0;i<9;i++)
	}*/
}
