#include<iostream>
# define n 9
using namespace std;

bool isValidGrid(int grid[n][n]) {
    // Check rows for duplicates
    for (int i = 0; i < n; i++) {
        bool seen[10] = {false};  // Array to track numbers 1 to 9
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != 0) {
                if (seen[grid[i][j]]) {
                    return false;  // Duplicate found in row
                }
                seen[grid[i][j]] = true;
            }
        }
    }

    // Check columns for duplicates
    for (int j = 0; j < n; j++) {
        bool seen[10] = {false};  // Array to track numbers 1 to 9
        for (int i = 0; i < n; i++) {
            if (grid[i][j] != 0) {
                if (seen[grid[i][j]]) {
                    return false;  // Duplicate found in column
                }
                seen[grid[i][j]] = true;
            }
        }
    }

    // Check 3x3 subgrids for duplicates
    for (int i = 0; i < n; i += 3) {
        for (int j = 0; j < n; j += 3) {
            bool seen[10] = {false};  // Array to track numbers 1 to 9
            for (int r = i; r < i + 3; r++) {
                for (int c = j; c < j + 3; c++) {
                    if (grid[r][c] != 0) {
                        if (seen[grid[r][c]]) {
                            return false;  // Duplicate found in subgrid
                        }
                        seen[grid[r][c]] = true;
                    }
                }
            }
        }
    }

    return true;  // No conflicts found
}


void printGrid(int grid[n][n]){
     for(int i=0;i<n;i++){
             if((i%3==0)&&(i!=0)){
            cout<<"-------------------"<<endl;
           }
       for(int j=0;j<n;j++){
           if((j%3==0)&&j!=0){
            cout<<"|";
           }
        cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool findEmptyloc(int grid[n][n],int &row,int &col){
    for(row=0;row<n;row++){
            for(col=0;col<n;col++){
            if(grid[row][col]==0){
                return true;
            }
        }
    }
    return false;
}

bool isTrueinRow(int grid[n][n],int row,int num){
        for(int col=0;col<n;col++){
            if(grid[row][col]==num){
                return false;
            }
        }
    return true;
}

bool isTrueinCol(int grid[n][n],int col,int num){
        for(int row=0;row<n;row++){
            if(grid[row][col]==num){
                return false;
            }
        }
        return true;
}

bool isTrueinMatrix(int grid[n][n], int startRow, int startCol, int num){
    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
                if (grid[row + startRow][col + startCol] == num) {
                return false; // Number already exists in the box
            }
        }
    }
    return true;
}

bool isSafe(int grid[n][n],int row,int col,int num){

   return isTrueinRow(grid,row,num) &&
   isTrueinCol(grid,col,num) &&
   isTrueinMatrix(grid, row - row % 3, col - col % 3, num);
}

bool sudukoSolver(int grid[n][n]){
    int row, col;
    if(!findEmptyloc(grid,row,col)){
        return true;
    }
    for(int num=1;num<=9;num++){
        if(isSafe(grid,row,col,num)){
            grid[row][col]=num;


            if(sudukoSolver(grid)){
                return true;
            }
            grid[row][col]=0;
        }
    }
    return false;
}

int main(){
    int grid[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    if (!isValidGrid(grid)) {
        cout << "No Solution Exists!!!" << endl;
    }
    else{
    if(sudukoSolver(grid)){
        cout<<"Solved Suduko Grid: \n";
        printGrid(grid);
    }
    else{
        cout<<"No SOlution Exist!!!";
    }
  }
    return 0;
}
