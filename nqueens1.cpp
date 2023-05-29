#include<bits/stdc++.h>
using namespace std;
int n;
void solve(int col, vector < string > & board, vector < vector < string >> & ans, vector < int > & leftrow, vector < int > & upperDiagonal, vector < int > & lowerDiagonal, int n) {
      if (col == n) {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
          board[row][col] = 'Q';
          leftrow[row] = 1;
          lowerDiagonal[row + col] = 1;
          upperDiagonal[n - 1 + col - row] = 1;
          solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
          board[row][col] = '.';
          leftrow[row] = 0;
          lowerDiagonal[row + col] = 0;
          upperDiagonal[n - 1 + col - row] = 0;
        }
      }
}
vector < vector < string >> solveNQueens(int n) {
      vector < vector < string >> ans;
      vector < string > board(n);
      string s(n, '.');
      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
      vector < int > leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
      solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
      return ans;
    }
    
bool isSafe1(int row, int col, vector < string > board, int n) {
      // check upper element
      int duprow = row;
      int dupcol = col;

      while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row--;
        col--;
      }

      col = dupcol;
      row = duprow;
      while (col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        col--;
      }

      row = duprow;
      col = dupcol;
      while (row < n && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row++;
        col--;
      }
      return true;
    }

void solve1(int col, vector < string > & board, vector < vector < string >> & ans, int n) {
      if (col == n) {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (isSafe1(row, col, board, n)) {
          board[row][col] = 'Q';
          solve1(col + 1, board, ans, n);
          board[row][col] = '.';
        }
      }
    }

vector < vector < string >> solveNQueens1(int n) {
      vector < vector < string >> ans;
      vector < string > board(n);
      string s(n, '.');
      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
      solve1(0, board, ans, n);
      return ans;
}

int main() {
    cout<<"Enter the number of rows:"<<endl;
    cin>>n;
    int choice;
    cout<<"Enter 1 for backtracking and 2 for branch and bound:"<<endl;

    cin>>choice;
    if(choice==1){
        vector < vector < string >> ans = solveNQueens1(n);
        if(ans.empty()){
            cout<<"Solution does not exist"<<endl;
            return 0;
        }
        for (int i = 0; i < ans.size(); i++) {
            cout << "Arrangement " << i + 1 << "\n";
            for (int j = 0; j < ans[0].size(); j++) {
              cout << ans[i][j];
              cout << endl;
            }
            cout << endl;
        }
    }else{
            
            vector<vector<string>> ans=solveNQueens(n);
            if(ans.empty()){
                cout<<"Solution does not exist"<<endl;
                return 0;
            }
            for (int i = 0; i < ans.size(); i++) {
                cout << "Arrangement " << i + 1 << "\n";
                for (int j = 0; j < ans[0].size(); j++) {
                    cout << ans[i][j];
                    cout << endl;
                }
                cout << endl;
             }
    }
  return 0;
}