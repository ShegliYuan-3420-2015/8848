#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>

using namespace std;

class record
{
protected:
	int matrix[6][6];
	int matrix_clone[6][6];
	enum possible_rowscol_t {full,not_full,comp_row,comp_col};
	possible_rowscol_t *row,*col;
	possible_rowscol_t row_status[6], col_status[6],diag1_status[3],diag1_1_status,diag1_2_status,diag2_status[3],diag2_1_status,diag2_2_status;
	
	enum row_cols_diag {rows,columns,diagonal_1,diagonal_1_1,diagonal_1_2,diagonal_2,diagonal_2_1,diagonal_2_2};
    row_cols_diag identifier;

	int pos_row, pos_col, pos_diag1, pos_diag2;
	
public:
	record()
	{
		row = new possible_rowscol_t[];
		col = new possible_rowscol_t[];

		identifier = rows;

	for (int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 6; j++)
		{
		matrix[i][j] = 0;
		matrix_clone[i][j] = 0;
		row_status[i] = not_full;
		col_status[i] = not_full;
		if( i < 3)
		{
		diag1_status[i] = not_full;
		diag1_status[i] = not_full;
		}
		row[i] = not_full;
		col[i] = not_full;
		}
	}
	
	diag1_1_status = diag1_2_status = diag2_1_status = diag2_2_status = not_full;
	pos_row = pos_col = pos_diag1 = pos_diag2 = 0;
	}
	
void player_move(int x, int y, SDL_Rect* r)
{

int i = ceil(y/100) - 1; 
int j = ceil(x/100) - 1;

r->x = 100 + j*100;
r->y = 100 + i*100;


if(matrix[i][j] == 0)
{
 matrix[i][j] = 1;
 if(row[i] != full) row[i] = full;
 if(col[j] != full) col[j] = full;
}
else
cout << "occupied";

}

void see()
{
	cout << "\n";
for (int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			cout << "\t" << matrix_clone[i][j];
			if((j == 5)) 
			cout << "\n\n";
		}
	}

}


bool computer_move()
{
	int i;
	for (int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 6; j++)
		{
		matrix_clone[i][j] = 0;
		}
	}

	int boxes_to_count = 0;
	int sum_of_boxes = 0;

	//////////////////////////////////////////////////////////////////// check for completed rown and columns and diags and ignore them
	boxes_to_count = 4;
	sum_of_boxes = 4;
	
	cout << "\n Checking for taken rows";
	if(check_num_stones_row(sum_of_boxes,&i,boxes_to_count) == true)
	{
	cout << " \nRow Taken = ";
	}
	if(check_num_stones_col(sum_of_boxes,&i,boxes_to_count) == true)
	{
	cout << " \nColumn Taken = ";
	}
	if(check_num_stones_diag1(sum_of_boxes,&i,boxes_to_count) == true)
	{
	cout << " \nThis diag taken = ";
	}
	if(check_num_stones_diag2(sum_of_boxes,&i,boxes_to_count) == true)
	{
	cout << " \nThis diag taken = ";
	}

	////////////////////////////////////////////////////////////////////////// check for 3 stones in a row and take action
	boxes_to_count = 3;
	sum_of_boxes = 3;
	cout << " \nchecking for 3 consecutive swords";
	pos_row = pos_col = pos_diag1 = pos_diag2 = 0;

	if(check_num_stones_row(sum_of_boxes,&i,boxes_to_count) == true)
	{
	cout << " \nPossible rows = " << pos_row;
	}

	if(check_num_stones_col(sum_of_boxes,&i,boxes_to_count) == true)
	{
	cout << " \nPossible columns = " << pos_col;
	}

	if(check_num_stones_diag1(sum_of_boxes,&i,boxes_to_count) == true)
	{
	cout << " \nPossible diagonal one = " << pos_diag1;
	}

	if(check_num_stones_diag2(sum_of_boxes,&i,boxes_to_count) == true)
	{
	cout << " \nPossible diagonal two = " << pos_diag2;	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	see();
	return true;
}

void check_XXX_(int i, int j, row_cols_diag identifier,int boxes)
{

	switch(identifier)
	{
	case rows:
		if( j-1 >= 0)
		{
			if(matrix[i][j-1] == 0)
				matrix_clone[i][j-1]++;
		}
	    if( j+boxes <= 5)
		{
			if(matrix[i][j+boxes] == 0)
				matrix_clone[i][j+boxes]++;		
		}
		break;

	case columns: 
		if( i-1 >= 0)
		{
			if(matrix[i-1][j] == 0)
				matrix_clone[i-1][j]++;
		}
	    if( i+boxes <= 5)
		{
			if(matrix[i+boxes][j] == 0)
				matrix_clone[i+boxes][j]++;		
		}
		break;

	case diagonal_1:

		if(((i-1) >= 0) && ((j - 1) >= 0))
		{
		if(matrix[i-1][j-1] == 0)
		matrix_clone[i-1][j-1]++;
		}
	    if(((i+boxes) <= 5) && ((j + boxes) <= 5))
		{
		if(matrix[i+boxes][j+boxes] == 0)
		matrix_clone[i+boxes][j+boxes]++;
		}
		break;
	case diagonal_1_1:
		if(((i-1) >= 0) && ((j - 1) >= 0))
		{
		if(matrix[i-1][j-1] == 0)
		matrix_clone[i-1][j-1]++;
		}
	    if(((i+boxes) <= 5) && ((j + boxes) <= 5))
		{
		if(matrix[i+boxes][j+boxes] == 0)
		matrix_clone[i+boxes][j+boxes]++;
		}

		break;

	case diagonal_1_2:
		
		if(((i-1) >= 0) && ((j - 1) >= 0))
		{
		if(matrix[i-1][j-1] == 0)
		matrix_clone[i-1][j-1]++;
		}
	    if(((i+boxes) <= 6) && ((j + boxes) <= 6))
		{
		if(matrix[i+boxes][j+boxes] == 0)
		matrix_clone[i+boxes][j+boxes]++;
		}

		break;
	case diagonal_2:
		if(((i-1) >= 0) && ((j + 1) <= 5))
		{
		if(matrix[i-1][j+1] == 0)
		matrix_clone[i-1][j+1]++;
		}
	    if(((i+boxes) <= 5) && ((j - boxes) >= 0))
		{
		if(matrix[i+boxes][j-boxes] == 0)
		matrix_clone[i+boxes][j-boxes]++;
		}
		break;
/*	case diagonal_2_1:
		if(((i-1) >= 0) && ((j + 1) <= 5))
		{
		if(matrix[i-1][j+1] == 0)
		matrix_clone[i-1][j+1]++;
		}
	    if(((i+box) <= 5) && ((j - box) >= 0))
		{
		if(matrix[i+box][j-box] == 0)
		matrix_clone[i+box][j-box]++;
		}
		break;

	case diagonal_2_2:
		if(((i-1) >= 0) && ((j + 1) <= 5))
		{
		if(matrix[i-1][j+1] == 0)
		matrix_clone[i-1][j+1]++;
		}
	    if(((i+box) <= 5) && ((j - box) >= 0))
		{
		if(matrix[i+box][j-box] == 0)
		matrix_clone[i+box][j-box]++;
		}
		break;
*/
	}
}

void check_XXXX_(int i, int j, row_cols_diag identifier)
{
	switch(identifier)
	{
	case rows:
		row_status[i] = full;
			break;
	case columns:
		col_status[j] = full;
			break;
	case diagonal_1:
		diag1_status[j] = full;
		break;
	case diagonal_1_1:
		diag1_1_status = full;
		break;
	case diagonal_1_2:
		diag1_2_status = full;
		break;
	case diagonal_2:
		diag2_status[j] = full;
		break;
	case diagonal_2_1:
		diag2_1_status = full;
		break;
	case diagonal_2_2:
		diag2_2_status = full;
		break;
	}
}
bool check_num_stones_row(int s,int* ii,int boxes)
{
	int sum = 0;
	bool found = false;
	int i = 0;	
	int k = 0;
	int j = 0;// the row whose some is S

	while(row_status[i] != not_full && i < 6)
	i++;

	do
	{
	j = 0;
	do{
		k = j; 
		sum = 0;
	for(k; k < j + boxes ;k++)
	{
	sum += matrix[i][k];
	}
	
	if(sum == s)
	{
		found = true;
		*ii = i;
		sum = 0;
		pos_row++;
		if(s == 3 && boxes == 3 && row_status[i] != full)
		{
		identifier = rows;
		check_XXX_(i, j, identifier,boxes); 
		}
		else if( s == 4 && boxes == 4)
		{
		identifier = rows;
		check_XXXX_(i,0,identifier);	
		}
	}

	j++;
	}while (j <= 6 - boxes);
	i++;

	while(row_status[i] != not_full && i < 6)
	i++;
	}while(i < 6 );

return found;
}

bool check_num_stones_col(int s,int* ii,int boxes)
{
	int sum = 0;
	bool found = false;
	int i = 0;	
	int k = 0;
	int j = 0;    // the row whose some is S
	do
	{
	i = 0;
	do{
		k = i; 
		sum = 0;
	for(k; k < i + boxes; k++)
	{
	sum += matrix[k][j];
	}
	
	if(sum == s)
	{
		found = true;
		*ii = i;
		pos_col++;

		if(s == 3 && boxes == 3 && col_status[j] == not_full)
		{
		identifier = columns;
		check_XXX_(i, j, identifier,boxes); 
		}
		else if( s == 4 && boxes == 4)
		{
		identifier = columns;
		check_XXXX_(0,j,identifier);	
		}

	}
	i++;
	}while (i <= 6 - boxes);
	j++;
	}while(j < 6 );

return found;
}

bool check_num_stones_diag1(int s,int* ii,int boxes)
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
	for(k; k < i + boxes; k++)
 	{
	sum += matrix[k][l];
	l++;
	}
	
	if(sum == s)
	{ 
		found = true;
		*ii = i;
		sum = 0;
		pos_diag1++;
		
		if(s == 3 && boxes == 3 && diag1_status[j] == not_full)
		{
		identifier = diagonal_1;
		check_XXX_(i, ll, identifier,boxes);
		}
		else if(s == 4 && boxes == 4)
		{
		identifier = diagonal_1;
		check_XXXX_(0,j,identifier);
		}

	}
	else 
		sum = 0;
	i++;
	ll++;
	}while (i < 4 && ll < 4);
	j++;
	}while(j < 3 );
	/////////////////////////////////////
	
	j = 0;
	i = 1;
	do{
		k = i;
		l = j;
		sum = 0;
	for(k; k < i + boxes; k++)
 	{
	sum += matrix[k][l];
	l++;
	}
	
	if(sum == s)
	{

		found = true;
		*ii = i;
		sum = 0;
		pos_diag1++;

		//identifier = diagonal_1;
		//check_XXX_(i, j, identifier,boxes);
		
		if(s == 3 && boxes == 3 && diag1_1_status == not_full)
		{
		identifier = diagonal_1;
		check_XXX_(i, j, identifier,boxes);
		}
		else if(s == 4 && boxes == 4)
		{
		identifier = diagonal_1_1;
		check_XXXX_(0,j,identifier);
		}


	}
	else 
		sum = 0;
	i++;
	j++;
	}while (i <= 6 - boxes && j <= 6 - boxes);
	///////////////////

		/////////////////////////////////////

	j = 0;
	i = 2;
	do{
		k = i;
		l = j;
		sum = 0;
	for(k; k < i + boxes; k++)
 	{
	sum += matrix[k][l];
	l++;
	}

	if(sum == s)
	{

		found = true;
		*ii = i;
		sum = 0;
		pos_diag1++;

//		identifier = diagonal_1;
//		check_XXX_(i, j, identifier,boxes);

		if(s == 3 && boxes == 3 && diag1_2_status == not_full)
		{
		identifier = diagonal_1;
		check_XXX_(i, j, identifier,boxes);
		}
		else if(s == 4 && boxes == 4)
		{
		identifier = diagonal_1_2;
		check_XXXX_(0,0,identifier);
		}


	}
	else 
		sum = 0;
	i++;
	j++;
	}while (i <= 6 - boxes && j <= 6 - boxes);
	///////////////////

	
	return found;
}


bool check_num_stones_diag2(int s,int* ii,int boxes)
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
	for(k; k < i + boxes; k++)
 	{
	sum += matrix[k][l];
	l--;
	}

	if(sum == s)
	{
		found = true;
		*ii = i;
		sum = 0;
		pos_diag2++;


		if(s == 3 && boxes == 3 && diag2_status[j-3] != full)
		{
	
		identifier = diagonal_2;
		check_XXX_(i, ll, identifier,boxes);
		}
		else if(s==4 && boxes == 4)
		{
		identifier = diagonal_2;    /// which diagonal to check d0 d1 d3 determined by j = 0,1,2
		check_XXXX_(0,j-3,identifier);
		}
	}
	else 
		sum = 0;
	i++;
	ll--;
	}while (i <= 6 - boxes && ll >= boxes - 1);
	j++;
	}while(j < 6 );
	/////////////////////////////////////

	j = 5;
	i = 1;
	do{
		k = i;
		l = j;
		sum = 0;
	for(k; k < i + boxes; k++)
 	{
	sum += matrix[k][l];
	l--;
	}

	if(sum == s)
	{
		found = true;
		*ii = i;
		sum = 0;
		pos_diag2++;

//		identifier = diagonal_2;
//		check_XXX_(i, j, identifier,boxes);

		if(s == 3 && boxes == 3 && diag2_1_status != full)
		{
		
		identifier = diagonal_2;
		check_XXX_(i, j, identifier,boxes);
		}
		else if(s==4 && boxes == 4)
		{
		identifier = diagonal_2_1;
		check_XXXX_(0,0,identifier);
		}


	}
	else 
		sum = 0;
	i++;
	j--;
	}while (i <= 6 - boxes && j >= boxes - 1);
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
	l--;

	}
	
	if(sum == s)
	{
		found = true;
		*ii = i;
		sum = 0;
		pos_diag2++;

//		identifier = diagonal_2;
//		check_XXX_(i, j, identifier,boxes);

		if(s == 3 && boxes == 3 && diag2_2_status != full)
		{
		identifier = diagonal_2;
		check_XXX_(i, j, identifier,boxes);
		}
		else if(s==4 && boxes == 4)
		{
		identifier = diagonal_2_2;
		check_XXXX_(0,0,identifier);
		}


	}
	else 
		sum = 0;
	i++;
	j--;
	}while (i <= 6 - boxes && j >= boxes - 1);
	///////////////////

	
	return found;
}
};
