/**
 *
 * @author AniruddhBallal
 */
import java.util.Scanner;

public class MatrixDiagRev {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the order of the matrix (m, n): ");
        int m = sc.nextInt(), n = sc.nextInt();

        int[][] mat = new int[m][n];
        int[][] newmat = new int[n][m];

        System.out.println("Enter the elements of the matrix:");
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                mat[i][j] = newmat[j][i] = sc.nextInt();
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if(i==j){
                    int num = newmat[i][j], rev = 0;
                    while(num!=0){
                        rev=rev*10+(num%10);
                        num/=10;
                    }
                    newmat[i][j] = rev;
                } else {
                    newmat[i][j]*=newmat[i][j];
                }
        
        System.out.println("Resultant matrix:");
        for (int i = 0; i < n; i++){
            
        
        sc.close();
    }
}