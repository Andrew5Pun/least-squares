/*
 Andrew Pun
 Sept 2, 2020
 */

#include <bits/stdc++.h>

using namespace std;

vector<vector<double>> fillVand(vector<vector<double>> vand, vector<double> x) { // function that fills Vandermonde matrix
    
    for (int i = 0; i < vand.size(); i++) { // loop iterates through matrix 1 row at a time
        
        for (int j = 0; j < vand[i].size(); j++) {
            vand[i][j] = (pow(x[i], j)); // each row is equal to x^j, where j = 0, 1, 2, ..., degree (x^0 is 1, so first element of each row is 1)
        }
        
    }
    
    return vand;
    
}

vector<vector<double>> transposeMat(vector<vector<double>> mat) { // function that computes transpose
    
    vector<vector<double>> tr(mat[0].size(), vector<double> (mat.size()));
    
    for (int i = 0; i < tr.size(); i++) { // loop iterates through matrix 1 row at a time
        
        for (int j = 0; j < tr[i].size(); j++) {
            tr[i][j] = mat[j][i]; // copy item in matrix mat at (j, i) into transpose position (i, j)
        }
        
    }
    
    return tr;
    
}

vector<vector<double>> multiply(vector<vector<double>> mat1, vector<vector<double>> mat2) { // function that multiplies matrices together
    
    vector<vector<double>> mul(mat1.size(), vector<double> (mat2[0].size())); // create matrix with # of rows of mat1 and # of columns of mat2
    
    for (int i = 0; i < mul.size(); i++) { // iterate through entire matrix 1 row at a time
        
        for (int j = 0; j < mul[i].size(); j++) {
            mul[i][j] = 0; // first initialize to 0
            
            for (int p = 0; p < mat1[0].size(); p++) { // compute dot product of row of mat1 and column of mat2
                mul[i][j] += mat1[i][p] * mat2[p][j]; // add sum of products together
            }
            
        }
        
    }
    
    return mul;
    
}

void printVect(vector<vector<double>> mat) { // function that prints the entire vector
    
    cout << "{";
    
    for (int i = 0; i < mat.size(); i++) {
        cout << "\n\t";
        
        for (int j = 0; j < mat[i].size(); j++) {
            cout << mat[i][j] << " ";
        }
        
    }
    
    cout << "\n}\n";

}

vector<double> addRow(vector<double> row1, vector<double> row2) { // function that computes addition of two rows and returns sum. This was unused.
    
    vector<double> sum(row1.size());
    
    for (int i = 0; i < row1.size(); i++) { // goes through row
        sum[i] = row1[i] + row2[i]; // adds row elements together
    }
    
    return sum;
}

vector<double> subRow(vector<double> row1, vector<double> row2) { // function that computes subtraction of two rows and returns difference. Using multRow(row, -1) may be too intensive.
    
    vector<double> diff(row1.size());
    
    for (int i = 0; i < row1.size(); i++) { // goes through row
        diff[i] = row1[i] - row2[i]; // subtracts row elements together
    }
    
    return diff;
}

vector<double> multRow(vector<double> row, double C) { // function that multiplies row by constant and returns row.
    
    for (int i = 0; i < row.size(); i++) { // goes through row
        row[i] *= C; // multiply row element by constant
    }
    
    return row;
}

vector<vector<double>> compInv(vector<vector<double>> mat) { // function that computes inverse of matrix
    
    for (int i = 0; i < mat.size(); i++) {
        
        mat[i].resize(mat.size()*2); // resize mat to double its columns. This is to amend an identity matrix of the same dimension to the back of the matrix so that calculations are made easier during row operations (identity matrix is tranformed with every operation). After the identity matrix is transformed (becomes the inverse) the function will return it.
        
        for (int j = 0; j < mat.size(); j++) { // add identity matrix to back
            if (j == i) { // if it is a diagnonal element
                mat[i][j+mat.size()] = 1; // change element to 1
                
            } else { // if it is not
                mat[i][j+mat.size()] = 0; // change element to zero
            }
            
        }
    }
    
    // create bottom "triangle" of 0s.
    for (int j = 0; j < mat.size()-1; j++) { // index rows downwards starting at row 0 and ending at second last
        for (int i = j+1; i < mat.size(); i++) { // index through all rows below row j
            mat[i] = subRow(mat[i], multRow(mat[j], mat[i][j]/mat[j][j])); // subtract row i from row j. Row j is multiplied by mat[i][j]/mat[j][j] to turn mat[i][j] into 0.
        }
    }
    
    // create top "triangle" of 0s.
    for (int j = mat.size()-1; j > 0; j--) { // index rows upwards starting at bottom row and finishing at row 1
        for (int i = j-1; i >= 0; i--) { // index through all rows above row j
            mat[i] = subRow(mat[i], multRow(mat[j], mat[i][j]/mat[j][j])); // subtract row i from row j. Row j is multiplied by mat[i][j]/mat[j][j] to turn mat[i][j] into 0.
        }
        
    }
    
    // finish identity by dividing all rows by diagonal element to turn them all into 1s
    for (int i = 0; i < mat.size(); i++) { // index through rows
        mat[i] = multRow(mat[i], 1/mat[i][i]); // multiply entire row by reciprocal to get 1
    }
    
    vector<vector<double>> inv(mat.size(), vector<double> (mat.size())); // create new inv matrix
    
    // copy values from amended matrix in mat to inv
    for (int i = 0; i < mat.size(); i++) { // index through rows
        for (int j = 0; j < mat.size(); j++) { // index through columns
            inv[i][j] = mat[i][j+mat.size()]; // copy value
        }
    }
    
    return inv;
    
}

vector<vector<double>> fillVect(vector<vector<double>> mat) { // function that fills vector via inputs
    
    for (int i = 0; i < mat.size(); i++) {
        
        for (int j = 0; j < mat[i].size(); j++) {
            
            cin >> mat[i][j];
            
        }
        
    }
    
    return mat;
    
}

int main() {
    
    int n; // n, number of data pairs (x, y)
    
    int deg; // degree for Vandermonde matrix. Cubic polynomial is needed for assignment
    
    vector<double> x; // vector with x points
    
    vector<vector<double>> y; // vector with y points
    
    x = {1.01, 2.2, 2.9, 4.03, 5.32 ,6.22, 8.56, 9.09};
    y = {{18.5, 76.2, 150.5, 365, 780, 1265, 3250, 7099}};
    n = 8;
    
    /*
    cout << "Input number of data points: ";
    cin >> n; // prompts for n
     
    cout << "Input x values in order, separated by white space:\n";
    for (int i = 0; i < n; i++) { // loop n times
        cin >> x[i]; // prompt for x data
    }
    cout << "\n";
    
    cout << "Input y values in order, separated by white space:\n";
    for (int i = 0; i < n; i++) { // loop n times
        cin >> y[i]; // prompt for y data
    }
    cout << "\n";
    */
    
    cout << "Input degree of polynomial (input 1 for linear fit): ";
    
    cin >> deg; // prompts for degree of polynomial
    
    cout << "x: ";
    for (int i = 0; i < n; i++) { // loop n times
        cout << x[i] << ", "; // print x data
    }
    cout << "\n";
    
    cout << "y: ";
    for (int i = 0; i < n; i++) { // loop n times
        cout << y[0][i] << ", "; // print y data
    }
    cout << "\n\n";
    
    vector<vector<double>> vand(n, vector<double> (deg + 1)); // create Vandermonde matrix with n rows and degree + 1 columns
    
    vand = fillVand(vand, x); // fill Vandermonde matrix with x values
    
    cout << "V = \n";
    printVect(vand); // print Vandermonde matrix
    cout << "\n";
    
    vector<vector<double>> transpose = transposeMat(vand); // create transpose of Vandermonde
    
    cout << "V^T = \n";
    printVect(transpose); // print transpose
    cout << "\n";
    
    vector<vector<double>> mul = multiply(transpose, vand); // create product of V^T and V
    
    cout << "(V^T)*V = \n";
    printVect(mul);
    cout << "\n";
    
    vector<vector<double>> inv = compInv(mul); // create inverse of V^T and V
    
    cout << "((V^T)*V)^-1 = \n";
    printVect(inv);
    cout << "\n";
    
    vector<vector<double>> coeff = (multiply(inv, transpose)); // compute coefficients (((V^T)*V)^-1)*(V^T)*b
    
    coeff = multiply(coeff, transposeMat(y));
    
    cout << "(((V^T)*V)^-1)*(V^T)*b = \n";
    printVect(coeff);
    cout << "\n";
    
    cout << "The equation of the polynomial of best fit is:\ny = ";
    for (int i = deg; i > 0; i--) { // print out all the
        cout << coeff[i][0] << "x^" << i << " + ";
    }

    cout << coeff[0][0]; // print out the last constant
    
    cout << "\n\n";

}
