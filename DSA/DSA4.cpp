/*
Ex 4. a)Sort the data in ascending order using Selection sort and descending order by using Insertion sort.Display pass by pass output) 
      b)Search a particular data using linear search.
*/
#include<iostream>

using namespace std;

void selection(int b[], int n) {
  int i, j, pos, t;
  for (i = 0; i < n; i++) {
    pos = i;
    for (j = i + 1; j < n; j++) {
      if (b[j] < b[pos]) {
        pos = j;
      }
    }
    t = b[i];
    b[i] = b[pos];
    b[pos] = t;
  }
  cout << "Array after selection sort\n";
}
void display(int b[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    cout << b[i] << " ";
  }
  cout << endl;
}
void insertion(int b[], int n) {
  int j, t;
  for (int i = 1; i < n; i++) {
    t = b[i];
    j = i - 1;
    while ((t > b[j]) && (j >= 0)) {
      b[j + 1] = b[j];
      j--;
    }
    b[j + 1] = t;
  }
  cout << "Array after insertion sort\n";
}
void search(int b[], int n) {
  int el, flag = 0;
  cout << "Enter element to be search:";
  cin >> el;
  for (int i = 0; i < n; i++) {
    if (b[i] == el) {
      flag = 1;
      cout << "Element found at location: " << i << endl;
    }
  }
  if (flag == 0)
    cout << "Element not found" << endl;
}

int main() {
  int t, n, a[100], i, j, pos, choice;

  cout << "Enter no of elements in array:";
  cin >> n;
  cout << "Enter array elements:";
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  do {
    cout << endl << "1. Selection sort \n2. Insertion sort \n3. Display \n4. Search \n5. Exit" << endl;
    cout << "Enter your choice:";
    cin >> choice;
    cout << endl;
    switch (choice) {
    case 1:
      selection(a, n);
      display(a, n);
      break;
    case 2:
      insertion(a, n);
      display(a, n);
      break;
    case 3:
      display(a, n);
      break;
    case 4:
      search(a, n);
      break;
    case 5:
      return 0;
    default:
      cout << "Invalid Choice!!";
    }
  } while (choice != 5);
  return 0;
}
