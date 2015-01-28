#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>

using namespace std;

class record
{
protected:
	int matrix[6][6];
	enum possible_rowscol_t {full,not_full,comp_row,comp_col};
	possible_rowscol_t *row,*col;
	
public:
	record()
	{
		row = new possible_rowscol_t[];
		col = new possible_rowscol_t[];

	for (int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 6; j++)
		{
		matrix[i][j] = 0;
		row[i] = not_full;
		col[i] = not_full;
		}
	}
	}
	
void player_move(int x, int y, SDL_Rect* r)
{

int i = ceil(y/100) - 1; 
int j = ceil(x/100) - 1;

r->x = 100 + j*100;
r->y = 100 + i*100;

//cout << "x: " << i << "y:" << j;

if(matrix[i][j] == 0)
{
 matrix[i][j] = 1;
 if(row[i] != full) row[i] = full;
 if(col[j] != full) col[j] = full;
}
else
cout << "occupied";

//see();
}

void see()
{
	cout << "\n";
for (int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			cout << "\t" << matrix[i][j];
			if((j == 5)) 
			cout << "\n\n";
		}
	}

}


bool computer_move()
{
	int i;
	cout << " \nchecking for 3 consecutive swords";
	if(check_num_stones_row(3,&i))
	{
	cout << " \nrow found";
	}

	if(check_num_stones_col(3,&i))
	{
	cout << " \ncol found";
	}

	if(check_num_stones_diag1(3,&i))
	{
	cout << "\ndiag_1 found";
	}

	if(check_num_stones_diag2(3,&i))
	{
	cout << "\ndiag_2 found";
	}

	return true;
}
bool check_num_stones_row(int s,int* ii)
{
	int sum = 0;
	bool found = false;
	int i = 0;	
	int k = 0;
	int j = 0;// the row whose some is S
	do
	{
	j = 0;
	do{
		k = j; 
		sum = 0;
	for(k; k < j + 3 ;k++)
	{
	sum += matrix[i][k];
	}
	
	if(sum == s)
	{
		found = true;
		cout << "\nstart: " <<  " " << i << " " << j << " " << matrix[i][j];
		i = 6;
		j = 3;
		*ii = i;
		sum = 0;
	}

	j++;
	}while (j < 3);
	i++;
	}while(i < 6 );

return found;
}


bool check_num_stones_col(int s,int* ii)
{
	int sum = 0;
	bool found = false;
	int i = 0;	
	int k = 0;
	int j = 0;// the row whose some is S
	do
	{
	j = 0;
	do{
		k = j; 
		sum = 0;
	for(k; k < j + 3; k++)
	{
	sum += matrix[k][i];
	}
	
	if(sum == s)
	{
		found = true;
		i = 6;
		j = 3;
		*ii = i;
	}
	j++;
	}while (j < 3);
	i++;
	}while(i < 6 );

return found;
}

bool check_num_stones_diag1(int s,int* ii)
{

	int sum = 0;
	bool found = false;
	int i = 0;	
	int k = 0;
	int l = 0;
	int ll = 0;
	int j = 0;// the row whose some is S
	do
	{
	i = 0;
	ll = j;
	do{
		k = i;
		l = ll;
		sum = 0;
	for(k; k < i + 3; k++)
 	{
	sum += matrix[k][l];
//	cout << "\nk-l:  " << k <<"," << l;
	l--;
	//cout << "\t sum: " << sum;
	}
	cout << endl;
	if(sum == s)
	{
		found = true;
		i = 10;
		j = 15;
		*ii = i;
		sum = 0;
	}
	else 
		sum = 0;
	i++;
	ll--;
	}while (i < 4 && ll >= 2);
	j++;
	}while(j < 6 );
	/////////////////////////////////////

	j = 5;
	i = 1;
	do{
		k = i;
		l = j;
		sum = 0;
	for(k; k < i + 3; k++)
 	{
	sum += matrix[k][l];
//	cout << "\nk-l:  " << k <<"," << l;
	l--;
	//cout << "\t sum: " << sum;
	}
	cout << endl;
	if(sum == s)
	{
		found = true;
		i = 10;
		*ii = i;
		sum = 0;
	}
	else 
		sum = 0;
	i++;
	j--;
	}while (i < 4 && j >= 3);
	///////////////////

		/////////////////////////////////////

	j = 5;
	i = 2;
	do{
		k = i;
		l = j;
		sum = 0;
	for(k; k < i + 3; k++)
 	{
	sum += matrix[k][l];
//	cout << "\nk-l:  " << k <<"," << l;
	l--;
	//cout << "\t sum: " << sum;
	}
	cout << endl;
	if(sum == s)
	{
		found = true;
		i = 10;
		*ii = i;
		sum = 0;
	}
	else 
		sum = 0;
	i++;
	j--;
	}while (i < 4 && j >= 4);
	///////////////////

	
	return found;
}


bool check_num_stones_diag2(int s,int* ii)
{
	int sum = 0;
	bool found = false;
	int i = 0;	
	int k = 0;
	int l = 0;
	int ll = 0;
	int j = 3;// the row whose some is S
	do
	{
	i = 0;
	ll = j;
	do{
		k = i;
		l = ll;
		sum = 0;
	for(k; k < i + 3; k++)
 	{
	sum += matrix[k][l];
//	cout << "\nk-l:  " << k <<"," << l;
	l--;
	//cout << "\t sum: " << sum;
	}
	cout << endl;
	if(sum == s)
	{
		found = true;
		i = 10;
		j = 15;
		*ii = i;
		sum = 0;
	}
	else 
		sum = 0;
	i++;
	ll--;
	}while (i < 4 && ll >= 2);
	j++;
	}while(j < 6 );
	/////////////////////////////////////

	j = 5;
	i = 1;
	do{
		k = i;
		l = j;
		sum = 0;
	for(k; k < i + 3; k++)
 	{
	sum += matrix[k][l];
//	cout << "\nk-l:  " << k <<"," << l;
	l--;
	//cout << "\t sum: " << sum;
	}
	cout << endl;
	if(sum == s)
	{
		found = true;
		i = 10;
		*ii = i;
		sum = 0;
	}
	else 
		sum = 0;
	i++;
	j--;
	}while (i < 4 && j >= 3);
	///////////////////

		/////////////////////////////////////

	j = 5;
	i = 2;
	do{
		k = i;
		l = j;
		sum = 0;
	for(k; k < i + 3; k++)
 	{
	sum += matrix[k][l];
//	cout << "\nk-l:  " << k <<"," << l;
	l--;
	//cout << "\t sum: " << sum;
	}
	cout << endl;
	if(sum == s)
	{
		found = true;
		i = 10;
		*ii = i;
		sum = 0;
	}
	else 
		sum = 0;
	i++;
	j--;
	}while (i < 4 && j >= 4);
	///////////////////

	
	return found;
}
};
	/*
void see()
{
	cout << "\n";
for (int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			cout << "\t" << matrix[i][j];
			if((j == 5)) 
			cout << "\n\n";
		}
	}


}



bool AI_convert(SDL_Rect* r)
{
bool found = false;

if(check_first(r)==false)
	{

	if(computer_move(r) == true)
		{
			found = true;
			cout << "\ncomputer move success";
		}
	else
		cout << "\n2. computer move returned false";
	}
else
{
	found = true;
	cout << "\ncheck first returned true";
}
	return found;
}

bool check_first(SDL_Rect* r)
{
	int i = 0;
	int j = 0;

	bool found = false;
//////////////
	if(find_sum(3,&i))
	{
	found = true;
	for(int j = 0; j < 6;j++)
	{
	if(matrix[i][j] == 0)
		{
		 matrix[i][j] = 10;
		 r->x = 100 + j*100;
		 r->y = 100 +i*100;
		 i = 6;
		 j= 6;
		}
	}
	}
/////////////////
	if(find_sum_vert(3,&j) && found == false)
	{
	found = true;
	for(int i = 0; i < 6;i++)
	{
	if(matrix[i][j] == 0)
		{
		 matrix[i][j] = 10;
		 r->x = 100 + j*100;
		 r->y = 100 +i*100;
		 i = 6;
		 j= 6;
		}
	}
	}//////////////////////////

return found;
}

bool computer_move(SDL_Rect* r)
{
	int i = 0;
	int j = 0;
	int sum = 0;
	bool found = false;
//////////////
	if(find_sum(30,&i))
	{
	found = true;
	for(int j = 0; j < 6;j++)
	{
	if(matrix[i][j] == 0)
		{
		 matrix[i][j] = 10;
		 r->x = 100 + j*100;
		 r->y = 100 +i*100;
		 i = 6;
		 j= 6;
		}
	}
	}
//////////////////
	if(find_sum_vert(30,&j))
	{
	found = true;
	for(int i = 0; i < 6; i++)
	{
	if(matrix[i][j] == 0)
		{
		 matrix[i][j] = 10;
		 r->x = 100 + j*100;
		 r->y = 100 +i*100;
		 i = 6;
		 j= 6;
		}
	}
	}
return found;
//////////////////////////

}

bool find_sum(int s,int* ii)
{
	int sum = 0;
	bool found = false;
	int i = 0;    // the row whose some is S
	do
	{
	sum = 0;
	for(int j = 0; j < 6;j++)
	{
	sum += matrix[i][j];
	}
	//cout << "\nsum_up: " << sum;
	if(sum == s)
	{
		found = true;
		*ii = i;
		i = 6;
	}
	i++;
	}while(i < 6 );

return found;
}

bool find_sum_vert(int s,int* jj)
{
	int sum = 0;
	bool found = false;
	int j = 0;
	do
	{
	sum = 0;
	for(int i = 0; i < 6; i++)
	{
	sum += matrix[i][j];
	}
	//cout << "\nsum: " << sum;
	if(sum == s)
	{
		found = true;
		*jj = j;
		j = 6;
	}
	j++;
	}while(j < 6 );

return found;
}

bool create_fork(SDL_Rect* r)
{
	int i = 0;
	int j = 0;
	int sum = 0;
	bool found = false;
//////////////
	if(find_sum(40,&i) == true)
	{
	found = true;
	//cout << "I: " << i << endl;
	for(int j = 0; j < 6;j++)
	{
	if(matrix[i][j] == 0)
		{
		 matrix[i][j] = 10;
		 r->x = 100 + j*100;
		 r->y = 100 +i*100;
		 i = 6;
		 j= 6;
		}
	}
	}
//////////////////
	if(find_sum_vert(40,&j) == true)
	{
	found = true;
	for(int i = 0; i < 6; i++)
	{
	if(matrix[i][j] == 0)
		{
		 matrix[i][j] = 10;
		 r->x = 100 + j*100;
		 r->y = 100 +i*100;
		 i = 6;
		 j= 6;
		}
	}
	}
return found;
//////////////////////////
}
	
void make_move(SDL_Rect* q)
{
	cout << "\nmaking moves";
	bool success = false;
	int i = 0; 
	int j = 0;

	  if(success == false)
		{
		cout <<"\nFilling empty rows";
	      for(int i = 0; i < 6; i++)
		  {
		   if(row[i] != full)
		   {
			take_move(i,100,q);
			success = true;
			i = 6;
		   }
		  }
		}
		
	 if(success == false)
	 {
	  cout << "\nFilling empty columns";
		{
	      for(int i = 0; i < 6; i++)
		  {
		   if(col[i] != full)
		   {
			take_move(100,i,q);
			success = true;
			i = 6;
		   }
		  }
		}
	 }
	
	 if(success == false)
	{
	cout << "\nempty rows not found";
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 6; j++)
		{
	if(matrix[i][j] == 0)
		{
		 matrix[i][j] = 10;
		 q->x = 100 + j*100;
		 q->y = 100 + i*100;
		 i = 6;
		 j= 6;
		}
		}
	}
	}
}

void take_move(int i, int j, SDL_Rect* q)
{
	if(j == 100)
	{
cout << "\nvRow number = " << i << " and sum of row is " << matrix[i][3]; 
int z = 0;
while(z < 6)
{
if(matrix[i][z] == 0)
	{
		matrix[i][z] = 10;
		q->x =  100 + z*100;
		q->y = 100 + i*100;
		z = 6;
		row[i] = comp_row;
	}
z++;
}
	}
else
	{
cout << "\nvColumn number = " << j << " and sum of column is " << matrix[3][j];
int z = 0;
while(z < 6)
{
if(matrix[z][j] == 0)
		{
matrix[z][j] = 10;
q->y = 100 + z*100;
q->x = 100 + j*100;
z = 6;
col[j] = comp_col;
	}
z++;
}
}
}
 
bool check_win(int i)
{
bool win = false;
int dummy = 0;
if(i == 0)
{
if(find_sum(60,&dummy) == true)
{
	cout << " \n\n\n\n\n\n\n\nComputer Wins";
	win = true;
}
else if(find_sum_vert(60,&dummy) == true)
{
	cout << "\n\n\n\n\n\n\n\n Computer Wins";
	win = true;
}
}
else if(i == 1)
	{
if(find_sum(6,&dummy) == true)
{
	cout << " \n\n\n\n\n\n\n\nPlayer Wins";
	win = true;
}
else if(find_sum_vert(6,&dummy) == true)
{
	cout << " \n\n\n\n\n\n\n\n\n\n\nPlayer Wins";	
	win = true;
}
	}
return win;
}
};
*/