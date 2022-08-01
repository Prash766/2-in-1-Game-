#include<bits/stdc++.h>
using namespace std;
#define N 9
int snake_and_ladder()
{
    int snakes;
    int ladders;
    cout<<"Enter the number of ladders in game"<<endl;
    cin>>ladders;
    map<int,int>lad;
    map<int,int>snak;
    cout<<"Choose starting point and end point of ladders respectively"<<endl;
    for(int i=0;i<ladders;i++)
    {
       int u,v; cin>>u>>v;
       lad[u]=v;
    }
    cout<<"Enter the number of snakes"<<endl;
    cin>>snakes;
    cout<<"Enter the head position and tail position of snake respectively"<<endl;
    for(int i=0;i<snakes;i++)
    {
        int u,v; cin>>u>>v;
        snak[u]=v;
    }
    int moves=0;
    queue<int>q;
    q.push(1);
    bool found=false;
    vector<int>vis(101,0);
    vis[1]=true;
    while(!q.empty() && !found)
    {
        int sz=q.size();
        while(sz--)
        {
           int t=q.front();
           q.pop();
           for(int die=1;die<=6;die++)
           {
               if(t+die==100)
               found=true;
               if(t+die<=100 and lad[t+die] and !vis[lad[t+die]])
               {
                   vis[lad[t+die]]=true;
                   if(lad[t+die]==100)
                   {
                       found=true;
                   }
                   q.push(lad[t+die]);
               }

               else if(t+die<=100 and snak[t+die] and !vis[snak[t+die]])
               {
                   vis[snak[t+die]]=true;
                   if(snak[t+die]==100)
                   {
                       found=true;
                   }
                   q.push(snak[t+die]);
               }
               else if(t+die<=100 and !vis[t+die] and !snak[t+die] and !lad[t+die])
               {
                   vis[t+die]=true;
                   q.push(t+die);
               }
           }
        }
        moves++;
    }
    if(found)
    cout<<moves;
    else
    {
        return -1;
    }
    

    return 0;
}


//SUDOKU SOLVER
int grid[N][N] = {
   {3, 0, 6, 5, 0, 8, 4, 0, 0},
   {5, 2, 0, 0, 0, 0, 0, 0, 0},
   {0, 8, 7, 0, 0, 0, 0, 3, 1},
   {0, 0, 3, 0, 1, 0, 0, 8, 0},
   {9, 0, 0, 8, 6, 3, 0, 0, 5},
   {0, 5, 0, 0, 9, 0, 6, 0, 0},
   {1, 3, 0, 0, 0, 0, 2, 5, 0},
   {0, 0, 0, 0, 0, 0, 0, 7, 4},
   {0, 0, 5, 2, 0, 6, 3, 0, 0}
};
//Rows and columns are represented using i and j respectively...
bool InCol(int j, int num){ 
   for (int i = 0; i < N; i++)
      if (grid[i][j] == num)
         return true;
   return false;
}
bool InRow(int i, int num){ 
   for (int j = 0; j < N; j++)
      if (grid[i][j] == num)
         return true;
   return false;
}
bool InBox(int boxStartRow, int boxStartCol, int num){
   for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
         if (grid[i+boxStartRow][j+boxStartCol] == num)
            return true;
   return false;
}
void sudokuGrid(){ 
   for (int i = 0; i < N; i++){
      for (int j = 0; j < N; j++){
         if(j == 3 || j == 6)
            cout << " | ";
         cout << grid[i][j] <<" ";
      }
      if(i == 2 || i == 5){
         cout << endl;
         for(int i = 0; i<N; i++)
            cout << "---";
      }
      cout << endl;
   }
}
bool findEmptyPlace(int &i, int &j){ 
   for (i = 0; i < N; i++)
      for (j = 0; j < N; j++)
         if (grid[i][j] == 0) 
            return true;
   return false;
}
bool isValidPlace(int i, int j, int num){
   return !InRow(i, num) && !InCol(j, num) && !InBox(i - i%3 ,j - j%3, num);
}
bool solveSudoku(){
   int i, j;
   if (!findEmptyPlace(i, j))
      return true; 
   for (int num = 1; num <= 9; num++){ 
      if (isValidPlace(i, j, num)){ 
         grid[i][j] = num;
         if (solveSudoku()) 
            return true;
         grid[i][j] = 0; 
      }
   }
   return false;
}

int main()
{
	while(true){
	cout<<"Welcome to 2 in 1 games solver"<<endl;
	cout<<"Press 1 for snakes and laddder solver"<<endl;
	cout<<"Press 2 for Sudoku solver"<<endl;
	cout<<"Press 0 for Exit"<<endl;
    int choice;
    cin>>choice;
    if(choice==0){cout<<"Thanks for playing !"<<endl;break;}
    switch(choice){
	case 1:{snake_and_ladder();cout<<endl;break;}

    case 2: {
    	 cout<<"The solved sudoku be: "<<endl;
    cout<<endl;
   if (solveSudoku() == true)
      sudokuGrid();
   else
      cout << "No solution exists";

	} break;
    
    default: cout<<"Enter correct choice!"<<endl;
    }
  }
}