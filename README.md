# least-squares
Program that computes a polynomial fit for data using a Vandermonde matrix and a least squares method. No built-in matrix methods used. I had to make functions which compute the inverse, transpose, and product of matrices. Each matrix is represented by a 2D vector.

# custom data
By default, the program is configured to fit the following data:

x | 1.01, 2.2, 2.9, 4.03, 5.32 ,6.22, 8.56, 9.09
--- | ---
y | 18.5, 76.2, 150.5, 365, 780, 1265, 3250, 7099

You can add your own data by commenting out lines 185 - 187...

```
    x = {1.01, 2.2, 2.9, 4.03, 5.32 ,6.22, 8.56, 9.09};
    y = {{18.5, 76.2, 150.5, 365, 780, 1265, 3250, 7099}};
    n = 8;
```

... and uncommenting lines 189 - 204...

```
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
```
After which the program will prompt you for the number of data points you want to add, and the x and y points.

# output
The program will compute and output <b>V</b> (Vandermonde matrix of `deg` degrees), <b>V<sup>T</sup></b> (transpose of Vandermonde), <b>V<sup>T</sup>V</b> (product of transpose with Vandermonde), <b>(V<sup>T</sup>V)<sup>-1</sup></b> (inverse of product), <b>(V<sup>T</sup>V)V<sup>-1</sup>V<sup>T</sup>b</b> (coefficients of polynomial), and the equation of the polynomial.

Enjoy!
