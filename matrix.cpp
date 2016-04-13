#include <iostream>

using namespace std;

class MatrizC
{
public:
    int **p;
    int rows;

    MatrizC(int n)
    {
        rows=n;
        p=new int*[rows];
        for (int i=0; i<rows; i++)
            p[i]= new int[rows];
    }
    void insertar()
    {
        cout<<"Ingreso elementos:";
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<rows; j++)
                cin>> p[i][j];
        }
    }
    void mostrar()
    {
        cout <<"\nMi matriz: ";
        for(int i=0; i<rows; i++)
        {
            cout <<endl;
            for(int j=0; j<rows; j++)
                cout<< p[i][j]<<" ";
        }
    }
};

MatrizC square_matrix_multiply(MatrizC A,MatrizC B)
{
    int n=A.rows;
    MatrizC C(n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            C.p[i][j]=0;
            for(int k=0; k<n; k++)
                C.p[i][j]+=(A.p[i][k]*B.p[k][j]);
        }
    }
    return C;
}

MatrizC strassen(MatrizC A,MatrizC B)
{
    int n=A.rows;
    MatrizC C(n);

    if(n==1)
        C=square_matrix_multiply(A,B);

    int m1=(A.p[1][2]-A.p[2][2])*(B.p[2][1]+B.p[2][2]),
        m2=(A.p[1][1]+A.p[2][2])*(B.p[1][1]+B.p[2][2]),
        m3=(A.p[1][1]-A.p[2][1])*(B.p[1][1]+B.p[1][2]),
        m4=(A.p[1][1]+A.p[1][2])*B.p[2][2],
        m5=A.p[1][1]*(B.p[1][2]-B.p[2][2]),
        m6=A.p[2][2]*(B.p[2][1]-B.p[1][1]),
        m7=(A.p[2][1]+A.p[2][2])*B.p[1][1];

    C.p[1][1]=m1+m2-m4+m6;
    C.p[1][2]=m4+m5;
    C.p[2][1]=m6+m7;
    C.p[2][2]=m2-m3+m5-m7;

    return C;
}

/*
MatrizC C(2);

int ** square_matrix_multiply_recursive(int **A,int ** B)
{
    int n=2;
    int **p;
    p=new int*[n];
    for (int i=0; i<n; i++)
        p[i]= new int[n];

    if(n==1)
        p[1][1]=A[1][1]+B[1][1];
    else
    {
        p[1][1]=square_matrix_multiply_recursive(A[1][1],B[1][1])+
                  square_matrix_multiply_recursive(A[1][2],B[2][1]);

        p[1][2]=square_matrix_multiply_recursive(A[1][1],B[1][2])+
                  square_matrix_multiply_recursive(A[1][2],B[2][2]);

        p[2][1]=square_matrix_multiply_recursive(A[2][1],B[1][1])+
                  square_matrix_multiply_recursive(A[2][2],B[2][1]);

        p[2][2]=square_matrix_multiply_recursive(A[2][1],B[1][2])+
                  square_matrix_multiply_recursive(A[2][2],B[2][2]);
    }
    return p;
}*/

int main()
{
    int n=2;
    MatrizC a(n),b(n);
    a.insertar();
    b.insertar();
    a.mostrar();
    b.mostrar();
   
    MatrizC c=square_matrix_multiply(a,b);
    cout<<"\nMi respuesta";
    c.mostrar();
    cout<<"\n............\n";
    MatrizC cr=strassen(a,b);
    cr.mostrar();

    return 0;
}
