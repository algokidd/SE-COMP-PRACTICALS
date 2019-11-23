/*
Ex 2. Accept conventional matrix and convert it into sparse matrix .Implement simple and fast transpose algorithms on sparse matrix.
*/
#include<iostream>

using namespace std;

void simple_transpose(int sp[][3]) {
  int i = 0, j = 0;
  int t = sp[0][2];
  int c = sp[0][1];
  int tr[t + 1][3];
  tr[0][0] = sp[0][1];
  tr[0][1] = sp[0][0];
  tr[0][2] = sp[0][2];
  int ctr = 1;
  for (j = 0; j < c; j++) {
    for (i = 1; i < t + 1; i++) {
      if (sp[i][1] == j) {
        tr[ctr][0] = sp[i][1];
        tr[ctr][1] = sp[i][0];
        tr[ctr][2] = sp[i][2];
        ctr++;
      }
    }
  }

  cout << endl;
  cout << "Simple tranpose of the sparse matrix: \n";
  for (i = 0; i < t + 1; i++) {
    for (j = 0; j < 3; j++) {
      cout << tr[i][j] << "\t";
    }
    cout << endl;
  }

}

void fast(int sp[][3]) {

  int i, j, p;
  int t = sp[0][2];
  int c = sp[0][1];
  int row_terms[c], start_pos[c];
  int tr[t + 1][3];
  tr[0][0] = sp[0][1];
  tr[0][1] = sp[0][0];
  tr[0][2] = sp[0][2];

  for (i = 0; i < c; i++){
    row_terms[i] = 0;
}
  for (i = 1; i <= t; i++){
    row_terms[sp[i][1]]++;
}
  start_pos[0] = 1;

  for (i = 1; i < c; i++){
    start_pos[i] = start_pos[i - 1] + row_terms[i - 1];
}
  for (i = 1; i <= t; i++) {
    j = start_pos[sp[i][1]]++;
    tr[j][0] = sp[i][1];
    tr[j][1] = sp[i][0];
    tr[j][2] = sp[i][2];
  }
  cout << endl;
  cout << "Fast transpose of sparse matrix\n";
  for (i = 0; i <= sp[0][2]; i++) {
    for (j = 0; j < 3; j++) {
      cout << tr[i][j];
      cout << "\t";

    }
    cout << endl;
  }

}

int main() {
  int i, j, r, c, t;
  cout << "Enter the no. of rows and columns in the sparse matrix: ";
  cin >> r >> c;
  int a[r][c];
  cout << "Enter the elements of sparse matrix: ";
  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      cin >> a[i][j];
    }
  }

  cout << "Given matrix: \n";
  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      cout << a[i][j] << "\t";
    }
    cout << endl;
  }

  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      if (a[i][j] != 0)
        t++;
    }
  }
  int ctr = 1;
  int sp[t + 1][3];
  sp[0][0] = r;
  sp[0][1] = c;
  sp[0][2] = t;
  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      if (a[i][j] != 0) {
        sp[ctr][0] = i;
        sp[ctr][1] = j;
        sp[ctr][2] = a[i][j];
        ctr++;
      }
    }
  }

  cout << "Sparse Form of the given matrix: \n";
  for (i = 0; i < t + 1; i++) {
    for (j = 0; j <= 2; j++) {
      cout << sp[i][j] << "\t";
    }
    cout << endl;
  }

  int ch;
  do {
    cout << endl;
    cout << "Specify how u want to convert the matrix. \n1. Simple transpose. \n2. Fast transpose \n3. Exit.\n";
    cout << "Enter Choice : ";
    cin >> ch;
    switch (ch) {
    case 1:
      simple_transpose(sp);
      break;
    case 2:
      fast(sp);
      break;
    case 3:
      return 0;
    default:
      cout << "Invalid Choice !!";
    }
  } while (ch != 3);

}
