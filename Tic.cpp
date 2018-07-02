using namespace std;
#include<iostream>
#include<stdlib.h>

//START:
char matrix[10] = {'1','2','3','4','5','6','7','8','9'};
int player = 1;         //Player
int a[10];              //Hold position which are used
int j = 0;
void figure();          //Make tic structure
int check();            //check winning condition

int main()
{
	int pos;            //user input position
	int i = 0;

	figure();
	do{
		player = (player%2 == 0)?2:1;       //player change

		LABEL:
			cout<<"\nplayer "<<player<<" enter position "<<" = ";
			cin>>pos;
			 if(!cin)
			{
			cin.clear(); //This corrects the stream.
			cin.ignore(); //This skips the left over stream data.
			figure();
			cout<<"\nenter a valid value ";  goto LABEL;
		}


			 else if(pos>9)
			 	{	cout<<"\nenter a valid value ";  goto LABEL;			 }

			else                                                       //check pos is used of free
				{
					for(int k=0;k<j;k++)
						{
							if(a[k]== pos)  { cout<<endl<<"the position is used try another"<<endl;  goto LABEL;}
						}
					a[j]= pos;
					j=j+1;
				}

			if(player == 1)
				 matrix[pos-1] = 'X';
			else
				 matrix[pos-1] = 'O';

			figure();
		    i =	check();

			player++;
			if(i == 1)   {cout<<"player 1 wins the round \n\n\n\n\n\n\n"; break;  }
			else if(i == 2){ cout<<"player 2 wins the round \n\n\n\n\n\n\n\n";  break; }
	}while(i==0 && j!=9);


}

void figure()
{	cout << "\033[2J\033[1;1H";         //for linux
	system("cls");                    //for windows
    cout<<"\t\t       WELCOME TO TIC-TAC-TOE GAME\n\n";
	cout<<"X is for player 1 and O is for player 2"<<endl<<endl;
	cout<<"\t\t|-----------------------------------------------|"<<endl;
	for(int j=0;j<9;j++)
		{
			cout<<"\t\t|\t"<<matrix[j]<<"\t|\t"<<matrix[j+1]<<"\t|\t"<<matrix[j+2]<<"\t|"<<endl;
			j = j+2;
			cout<<"\t\t|-----------------------------------------------|"<<endl;

		}

}

int check()
{    //return 1 for player 1 win, 2 for 2 and 0 for other

	if(matrix[0]==matrix[1] && matrix[1]==matrix[2])
		{  if(matrix[0]=='X')  return(1);
		   else   return(2);
		}

	if(matrix[3]==matrix[4] && matrix[4]==matrix[5])
		{  if(matrix[3]=='X')  return(1);
		   else   return(2);
		}

	if(matrix[6]==matrix[7] && matrix[7]==matrix[8])
		{  if(matrix[6]=='X')  return(1);
		   else   return(2);
		}

	if(matrix[0]==matrix[3] && matrix[3]==matrix[6])
		{  if(matrix[0]=='X')  return(1);
		   else   return(2);
		}

	if(matrix[1]==matrix[4] && matrix[4]==matrix[7])
		{  if(matrix[1]=='X')  return(1);
		   else   return(2);
		}

	if(matrix[2]==matrix[5] && matrix[5]==matrix[8])
		{  if(matrix[5]=='X')  return(1);
		   else   return(2);
		}
	else
	{   return 0;
	}
}
