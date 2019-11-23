/*
Ex 3. a.Create a database using array of structures and perform following operationson it :
	i.Add record 
	ii.Display Database
	iii.Search record(binary search)
      b.For database implemented using array, perform
	iv.Modify record
	v.Delete record
	vi.Sortrecords(Bubble sort).
*/
#include<iostream>

using namespace std;
struct stud {
  unsigned int rollNo;
  char name[20];
  char addr[20];
}
s[100];
void getdata(int n) {

  for (int i = 0; i < n; i++) {
    cout << endl;
    cout << "Enter roll no,name and address";
    cin >> s[i].rollNo >> s[i].name >> s[i].addr;
  }
}
void display(int n) {
  system("clear");
  cout << "\nRNo\tName \tAddress\n";
  cout << "-----------------------------\n";
  for (int i = 0; i < n; i++) {
    cout << s[i].rollNo << "\t" << s[i].name << "\t" << s[i].addr << endl;
  }
}

void bubble_sort(stud list[], int n) {
  stud s1;
  int iteration;
  int index;
  for (iteration = 1; iteration < n; iteration++) {
    for (index = 0; index < n - iteration; index++)
      if (list[index].rollNo > list[index + 1].rollNo) {
        s1 = list[index];
        list[index] = list[index + 1];
        list[index + 1] = s1;
      }
  }
}
void binary(stud list[], int key, int lb, int ub) {
  int mid;
  while (lb <= ub) {
    mid = (lb + ub) / 2;
    if (key == list[mid].rollNo) {
      cout << "Entry found at location :" << mid + 1 << endl;
      break;
    } else {
      if (key > list[mid].rollNo)
        lb = mid + 1;
      else
        ub = mid - 1;
    }
  }
}
void modify(stud list[], int n) {
  int tp;
  cout << "please enter the roll no of student you would like to edit";
  cin >> tp;
  for (int i = 0; i < n; i++) {
    if (tp == list[i].rollNo) {
      cout << endl;

      cout << "Enter updated name and address of student :" << endl;
      cin >> s[i].name >> s[i].addr;
    } else {
      cout << "Please enter valid roll no" << endl;
    }
  }
}
int del(int n) {
  int rn, i, j, cnt = 0;
  cout << "\nEnter the Roll No of the Student to delete: ";
  cin >> rn;
  for (i = 0; i < n; i++) {
    if (s[i].rollNo == rn) {
      for (j = i; j < n; j++) {
        s[j] = s[j + 1];
        cnt++;
      }
    }
  }

  if (cnt != 0)
    n = n - 1;
  return n;
}
int main() {

  int n, choice;
  int key;
  system("clear");

  do {
    cout << endl;
    cout << "Student Database " << endl;
    cout << "1. Enter Data \n2. Add New Data \n3. Display \n4. Bubble sort \n5. Binary search \n6. Modify Record \n7. Delete \n8. Exit" << endl;
    cout << "Enter Choice : ";
    cin >> choice;
    switch (choice) {
    case 1:
      cout << "Enter how many records: ";
      cin >> n;
      getdata(n);
      break;
    case 2:
      n = n + 1;
      cout << "Enter Roll NO , Name & Address for New Entry : ";
      cin >> s[n - 1].rollNo >> s[n - 1].name >> s[n - 1].addr;
      break;
    case 3:
      if (n < 0) {
        cout << "Enter data first!!";
        break;
      } else {
        display(n);
        break;
      }
    case 4:
      bubble_sort(s, n);
      display(n);
      cout << "^^^ Sorted Data ^^^ \n";
      break;
    case 5:
      cout << "Enter element to be search:";
      cin >> key;
      binary(s, key, 0, n - 1);
      break;
    case 6:
      modify(s, n);
      break;
    case 7:
      n = del(n);
      break;
    case 8:
      return 0;
    default:
      cout << "Invalid Choice !!!";
    }
  } while (choice != 8);

}
