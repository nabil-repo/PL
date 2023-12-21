/*Assignment no 2:- Implement a program for storing a sparse matrix using 2-D Array for following operations
Name:- Nabil Ansari
MSID:- 219
PRN:- 202302040004*/

#include <iostream>
using namespace std;

class sparse
{
private:
    int a[20][3];
    int len = 0;

public:
    sparse(int r, int c, int l)
    {

        a[0][0] = r;
        a[0][1] = c;
        a[0][2] = l;
        len = l;
    }

    void read()
    {

        cout << "Enter the elements of the sparse matrix (row, column, value):" << endl;
        for (int i = 1; i <= a[0][2]; i++)
        {
            cin >> a[i][0];
            cin >> a[i][1];
            cin >> a[i][2];
        }
    }

    void add(sparse sp2)
    {
        int result[20][3], i = 1, j = 1, k = 1, l1 = a[0][2], l2 = sp2.a[0][2];

        if (a[0][0] != sp2.a[0][0] || a[0][1] != sp2.a[0][1])
        {
            cout << "\nCannot add these two matrices. Dimensions are different." << endl;
            return;
        }

        result[0][0] = a[0][0];
        result[0][1] = a[0][1];

        while (i <= l1 && j <= l2)
        {
            if (a[i][0] == sp2.a[j][0] && a[i][1] == sp2.a[j][1])
            {
                result[k][0] = a[i][0];
                result[k][1] = a[i][1];
                result[k][2] = a[i][2] + sp2.a[j][2];
                i++;
                j++;
            }
            else if (a[i][0] < sp2.a[j][0] || (a[i][0] == sp2.a[j][0] && a[i][1] < sp2.a[j][1]))
            {
                result[k][0] = a[i][0];
                result[k][1] = a[i][1];
                result[k][2] = a[i][2];
                i++;
            }
            else
            {
                result[k][0] = sp2.a[j][0];
                result[k][1] = sp2.a[j][1];
                result[k][2] = sp2.a[j][2];
                j++;
            }
            k++;
        }

        while (i <= l1)
        {
            result[k][0] = a[i][0];
            result[k][1] = a[i][1];
            result[k][2] = a[i][2];
            i++;
            k++;
        }

        while (j <= l2)
        {
            result[k][0] = sp2.a[j][0];
            result[k][1] = sp2.a[j][1];
            result[k][2] = sp2.a[j][2];
            j++;
            k++;
        }

        result[0][2] = k - 1;

        cout << "Addition is:" << endl;
        for (int i = 1; i <= result[0][2]; i++)
        {
            cout << result[i][0] << "\t" << result[i][1] << "\t" << result[i][2] << endl;
        }
    }

    void transpose()
    {
        int result[20][3];
        result[0][0] = a[0][1];
        result[0][1] = a[0][0];
        result[0][2] = a[0][2];

        int count = 1;

        for (int i = 0; i <= a[0][1]; i++)
        {
            for (int j = 1; j <= a[0][2]; j++)
            {
                if (a[j][1] == i)
                {
                    result[count][0] = a[j][1];
                    result[count][1] = a[j][0];
                    result[count][2] = a[j][2];
                    count++;
                }
            }
        }

        for (int i = 0; i <= result[0][2]; i++)
        {
            a[i][0] = result[i][0];
            a[i][1] = result[i][1];
            a[i][2] = result[i][2];
        }
    }
    void multiply(sparse sp2)
    {
        if (a[0][1] != sp2.a[0][0])
        {
            cout << "Matrix multiplication is not possible." << endl;
            return;
        }

        int resultM[20][3] = {0};
        int l1 = a[0][2];
        int l2 = sp2.a[0][2];
        int k = 1;

        resultM[0][0] = a[0][0];
        resultM[0][1] = sp2.a[0][1];

        for (int i = 1; i <= l1; i++)
        {
            int row1 = a[i][0];
            int col1 = a[i][1];
            int val1 = a[i][2];

            for (int j = 1; j <= l2; j++)
            {
                int row2 = sp2.a[j][0];
                int col2 = sp2.a[j][1];
                int val2 = sp2.a[j][2];

                if (col1 == row2)
                {
                    resultM[k][0] = row1;
                    resultM[k][1] = col2;
                    resultM[k][2] += val1 * val2;
                }
            }
            k++;
        }

        resultM[0][2] = k - 1;

        cout << "Multiplication Result:" << endl;
        for (int i = 1; i <= resultM[0][2]; i++)
        {
            cout << resultM[i][0] << "\t" << resultM[i][1] << "\t" << resultM[i][2] << endl;
        }
    }

    void fast_transpose()
    {
        int numCols = a[0][1];
        int vals = a[0][2];

        int rowTerms[20] = {0};
        int startingPos[20] = {0};

        int result[20][3];

        result[0][0] = numCols;
        result[0][1] = a[0][0];
        result[0][2] = vals;

        for (int i = 1; i <= vals; i++)
        {
            rowTerms[a[i][1]]++;
        }

        startingPos[0] = 1;

        for (int i = 1; i < numCols; i++)
        {
            startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
        }

        for (int i = 1; i <= vals; i++)
        {
            int j = startingPos[a[i][1]];
            result[j][0] = a[i][1];
            result[j][1] = a[i][0];
            result[j][2] = a[i][2];
            startingPos[a[i][1]]++;
        }

        for (int i = 0; i <= vals; i++)
        {
            a[i][0] = result[i][0];
            a[i][1] = result[i][1];
            a[i][2] = result[i][2];
        }
    }

    void display()
    {
        cout << "Sparse Matrix:" << endl;
        for (int i = 1; i <= a[0][2]; i++)
        {
            cout << a[i][0] << "\t" << a[i][1] << "\t" << a[i][2] << endl;
        }
    }
};

int main()
{
    int rows, cols, value, ch;

    cout << "Matrix A: ";

    cout << "\nEnter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of columns: ";

    cin >> cols;

    cout << "Enter the number of non-zero elements: ";
    cin >> value;

    sparse s1(rows, cols, value);
    s1.read();
    // s1.display();

    cout << "\n------------------\nMatrix B: ";

    cout << "\nEnter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of columns: ";
    cin >> cols;

    cout << "Enter the number of non-zero elements: ";
    cin >> value;

    sparse s2(rows, cols, value);
    s2.read();
    // s2.display();

    do
    {
        cout << "--------------------\nMenu:\n1.Display\n2.Add\n3.Transpose\n4.Multiply\n5.Fast Transpose\n0.Exit\n";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Matrix A: ";
            s1.display();
            cout << "\n------------------\nMatrix B: ";
            s2.display();
            break;
        case 2:
            s1.add(s2);
            break;
        case 3:
            s2.transpose();
            s2.display();
            break;
        case 4:
            s1.multiply(s2);
            break;
        case 5:
            s1.fast_transpose();
            cout << "\nFast Transpose:" << endl;
            s1.display();
            break;
        }
    } while (ch != 0);

    return 0;
}
