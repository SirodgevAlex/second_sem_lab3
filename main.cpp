#include <iostream>
#include "Tree.h"
#include "test.h"
#include "Complex.h"
#include "DynamicArray.h"
#include "Student.h"
#include <time.h>
#include "Sequence.h"

using namespace std;

void menu() {
    cout << "0 - stop" << '\n';
    cout << "1 - input tree" << '\n';
    cout << "2 - choose path" << '\n';
    cout << "3 - add an element" << '\n';
    cout << "4 - check for occurrence" << '\n';
    cout << "5 - merge two trees" << '\n';
    cout << "6 - find item using relative path" << '\n';
    cout << "7 - find item using absolute path" << '\n';
    cout << "8 - test of functions" << '\n';
    cout << "9 - print path\n";
}

void PassesMenu() {
    cout << "input path number you want to choose\n";
    cout << "1 - NLR" << '\n';
    cout << "2 - NRL" << '\n';
    cout << "3 - LNR" << '\n';
    cout << "4 - RNL" << '\n';
    cout << "5 - LRN" << '\n';
    cout << "6 - RLN" << '\n';
}

void DataTypeMenu() {
    cout << "What data type you want?" << '\n';
    cout << "1 - int" << '\n';
    cout << "2 - float" << '\n';
    cout << "3 - complex" << '\n';
    cout << "4 - student" << '\n';
}

template<typename T>
void Mainfunc() {
    int command = -1;
    Tree<T> tree = Tree<T>();
    Sequence<T> *Arr = new ArraySequence<T>();
    while (command != 0) {
        menu();
        cin >> command;
        if (command == 0) {
            tree.delTree(tree.Get1PtrRoot());
        } else if (command == 1) {
            cout << "input size please" << '\n';
            int size;
            cin >> size;
            cout << "input data" << endl;
            tree.FillWithValues(size);
        } else if (command == 2) {
            PassesMenu();
            enum Pass {
                NLR = 1, NRL = 2, LNR = 3, RNL = 4, LRN = 5, RLN = 6
            };
            int Pass;
            cin >> Pass;
            if (Arr->GetSize() != 0) {
                Arr->~Sequence();
            }
            clock_t start = clock();
            switch (Pass) {
                case NLR:
                    tree.NLR(tree.Get1PtrRoot(), Arr);
                    break;
                case NRL:
                    tree.NRL(tree.Get1PtrRoot(), Arr);
                    break;
                case LNR:
                    tree.LNR(tree.Get1PtrRoot(), Arr);
                    break;
                case RNL:
                    tree.RNL(tree.Get1PtrRoot(), Arr);
                    break;
                case LRN:
                    tree.LRN(tree.Get1PtrRoot(), Arr);
                    break;
                case RLN:
                    tree.RLN(tree.Get1PtrRoot(), Arr);
                    break;
            }
            clock_t end = clock();
            double seconds = (double) (end - start) / CLOCKS_PER_SEC;
            cout << '\n';
            printf("The time: %f seconds\n", seconds);
        } else if (command == 3) {
            cout << "input please" << '\n';
            T data;
            cin >> data;
            tree.Add(data);
        } else if (command == 4) {
            cout << "input please" << '\n';
            T data;
            cin >> data;
            if (tree.Find(data) == true) {
                cout << "this element is in the tree" << '\n';
            } else {
                cout << "this element is not in the tree" << '\n';
            }
        } else if (command == 5) {
            cout << "input size please" << '\n';
            int size = 0;
            cin >> size;
            cout << "input please" << '\n';
            Tree<T> Newtree = Tree<T>();
            Newtree.FillWithValues(size);
            clock_t start = clock();
            tree.Merge(tree, Newtree);
            Newtree.delTree(Newtree.Get1PtrRoot());
            clock_t end = clock();
            double seconds = (double) (end - start) / CLOCKS_PER_SEC;
            cout << '\n';
            printf("The time: %f seconds\n", seconds);
        } else if (command == 6) {
            cout << "Input please string" << endl;
            string str;
            cin >> str;
            cout << "input please data from which you want start going\n";
            T StartData;
            cin >> StartData;
            cout << tree.FindRelativePass(str, str.length(), StartData) << '\n';
        } else if (command == 7) {
            cout << "input size please" << '\n';
            int size;
            cin >> size;
            T array[size];
            cout << "Input please\n";
            for (int i = 0; i < size; i++) {
                cin >> array[i];
            }
            T ans = tree.FindAbsolutePass(array, size);
            cout << ans;
        } else if (command == 8) {
            Test();
        } else if (command == 9) {
            for (int i = 0; i < Arr->GetSize(); i++) {
                cout << Arr->Get(i) << " ";
            }
            cout << endl;
        }
    }
    Arr->~Sequence();
}

int main() {
    DataTypeMenu();
    int DataType = 0;
    cin >> DataType;
    cout << "first of all input tree please" << '\n';
    if (DataType == 1) {
        Mainfunc<int>();
    } else if (DataType == 2) {
        Mainfunc<float>();
    } else if (DataType == 3) {
        Mainfunc<Complex<int>>();
    } else if (DataType == 4) {
        //Mainfunc<Student<int>>();
    }
}
