package java.backtraking;

public class Problem {
    public static void changeArray(int arr[], int i, int val) {
        if (i == arr.length) {
            for (int j : arr) {
                System.out.print(j + " ");
            }
            System.out.println(); // To separate different array versions
            return;
        }

        // First recursive path
        arr[i] = val;
        changeArray(arr, i + 1, val + 1);

        // Backtracking step (undoing/change)
        arr[i] = arr[i] - 2;
        changeArray(arr, i + 1, val + 1); // Second recursive path
    }
    public static void findPermurtation(String str,String ans){
        if(str.length()==0){
           System.out.println(ans);
           return;
        }
  
        for(int i=0; i<str.length(); i++){
           char ch = str.charAt(i);
           str = str.substring(0,i) + str.substring(i+1);
           findPermurtation(str, ans+ch);
        }
     }

     public static void nQueen(char[][] board, int row) {
        if (row == board.length) {
            printBoard(board);
            return;
        }
 
        for (int i = 0; i < board.length; i++) {
            if (isSafe(board, row, i)) {
                board[row][i] = 'Q'; // place queen
                nQueen(board, row + 1); // move to next row
                board[row][i] = 'X'; // backtrack
            }
        }
    }
 
    public static boolean isSafe(char[][] board, int row, int col) {
        // Vertical up
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q') return false;
        }
 
        // Upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
 
        // Upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < board.length; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
 
        return true;
    }
 
    public static void printBoard(char[][] board) {
        for (char[] row : board) {
            for (char ch : row) {
                System.out.print(ch + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    public static void main(String[] args) {
        changeArray(new int[]{0, 0, 0, 0, 0}, 0, 5);
    }
}
