#include <iostream>
#include <assert.h>
#include "Tree.h"
#include "DynamicArray.h"

using namespace std;

void Test() {
    Tree<int> tree = Tree<int>();
    tree.Add(10);
    tree.Add(12);
    tree.Add(15);
    tree.Add(9);
    tree.Add(8);
    tree.Add(6);
    /*tree.Add(tree.GetPtrRoot(),10);
    tree.Add(tree.GetPtrRoot(),12);
    tree.Add(tree.GetPtrRoot(),15);
    tree.Add(tree.GetPtrRoot(),9);
    tree.Add(tree.GetPtrRoot(),8);
    tree.Add(tree.GetPtrRoot(),6);*/
    Tree<int> tree1 = Tree<int>();
    tree1.Add(10);
    tree1.Add(12);
    tree1.Add(15);
    tree1.Add(21);
    tree1.Add(9);
    tree1.Add(7);
    tree1.Add(8);
    Sequence<int> *Arr1 = new ArraySequence<int>();
    Sequence<int> *Arr2 = new ArraySequence<int>();
    cout << "first tree" << endl;
    tree.NLR(tree.Get1PtrRoot(), Arr1);
    for (int i = 0; i < Arr1->GetSize(); i++) {
        cout << Arr1->Get(i) << " ";
    }
    cout << endl;
    cout << "second tree" << endl;
    tree.NLR(tree1.Get1PtrRoot(), Arr2);
    for (int i = 0; i < Arr2->GetSize(); i++) {
        cout << Arr2->Get(i) << " ";
    }
    cout << endl;
    assert(tree.Find(8) == true);
    cout << "Add function works correctly" << endl;
    cout << "Find function works correctly" << endl;
    cout << "after merge" << endl;
    tree.Merge(tree, tree1);
    //Arr1->~Sequence();
    tree.NLR(tree.Get1PtrRoot(), Arr1);
    for (int i = 0; i < Arr1->GetSize(); i++) {
        cout << Arr1->Get(i) << " ";
    }
    cout << endl;
    string str = "LL";
    int array[] = {18, 15};
    assert(tree.FindRelativePass(str, 2, 18) == 6);
    cout << "Find item using relative pass function works correctly" << '\n';
    assert(tree.FindAbsolutePass(array, 2) == 6);
    cout << "Find item using absolute pass function works correctly" << '\n';
}
