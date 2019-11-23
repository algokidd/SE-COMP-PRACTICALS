#include<iostream>
#include<string.h>

using namespace std;

void len() {
  int length = 0;
  char a[50], * ptr;
  cout << "Enter string :";
  cin >> a;
  ptr = a;
  while ( * ptr != '\0') {
    length++;
    ptr++;
  }
  cout << "length of String " << a << " is " << length << endl;
}

void compare() {
  char a[50], b[50];
  cout << "Enter 1st String :";
  cin >> a;
  cout << "Enter 2nd String :";
  cin >> b;
  int l1 = strlen(a), l2 = strlen(b), flag = 0;
  char * p1 = a;
  char * p2 = b;
  if (l1 == l2) {
    for (int i = 0; i < l2; i++) {

      if ( * p1 == * p2) {
        p1++;
        p2++;
      } else {

        flag++;
      }
    }
  }
  if (flag != 0)
    cout << "strings are not equal" << endl;
  else
    cout << "strings are equal" << endl;
}

void reverse() {
  char a[20], b[20], * q, * p;
  int l;

  cout << "Enter Strings: ";
  cin >> a;
  l = strlen(a);
  p = a;
  p = p + l - 1;
  while ( * p != '\0') {
    cout << * p;
    p--;
  }
  cout << endl;
}

void copy() {

  char a[50], b[50], * ptr, * p2;
  cout << "This will copy 2nd string into first \n";
  cout << "Enter 1st String :";
  cin >> a;
  cout << "Enter 2nd String :";
  cin >> b;
  ptr = a;
  p2 = b;
  while ( * p2 != '\0') {
    * ptr = * p2;
    p2++;
    ptr++;
  }
  *ptr = '\0';
  cout << a << endl;

}

void concat() {

  char a[50], b[50], * ptr, * p2;
  cout << "Enter 1st String :";
  cin >> a;
  cout << "Enter 2nd String :";
  cin >> b;
  ptr = a + strlen(a);
  p2 = b;
  while ( * p2 != '\0') {
    * ptr = * p2;
    p2++;
    ptr++;
  }
  *ptr = '\0';
  cout << a << endl;

}

int main() {
  int ch;
  do {

    cout << "------String Operations Using Pointers------" << endl;
    cout << "Menu \n1. String Length \n2. String Copy \n3. String Concat \n4. String Compare \n5. String Reverse \n6. Exit" << endl;
    cout << "Enter Choice :";
    cin >> ch;
    switch (ch) {
    case 1:
      len();
      break;
    case 2:
      copy();
      break;
    case 3:
      concat();
      break;
    case 4:
      compare();
      break;
    case 5:
      reverse();
      break;
    case 6:
      return 0;
    default:
      cout << "Invalid Choice!!" << endl;

    }
  } while (ch != 6);
}
