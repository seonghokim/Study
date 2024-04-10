// B Tree
/*     BTree t(3);
    t.Insert(10);
    t.Insert(20);
    t.Insert(5);
    t.Insert(6);
    t.Insert(12);
    t.Insert(30);
    t.Insert(7);
    t.Insert(17);
    t.InorderTraverse();
    int k = 6;
    t.Search(k) != NULL ? cout << "\n Present" : cout << "\nNot Present";
    k = 15;
    t.Search(k) != NULL ? cout << "\n Present" : cout << "\nNot Present"; */
/*     BTree t(3);
    t.Insert(1);
    t.Insert(3);
    t.Insert(7);
    t.Insert(10);
    t.Insert(11);
    t.Insert(13);
    t.Insert(14);
    t.Insert(15);
    t.Insert(18);
    t.Insert(16);
    t.Insert(19);
    t.Insert(24);
    t.Insert(25);
    t.Insert(26);
    t.Insert(21);
    t.Insert(4);
    t.Insert(5);
    t.Insert(20);
    t.Insert(22);
    t.Insert(2);
    t.Insert(17);
    t.Insert(12);
    t.Insert(6);
    t.InorderTraverse(); cout << endl;
    t.Remove(6);
    t.InorderTraverse(); cout << endl;
    t.Remove(13);
    t.InorderTraverse(); cout << endl;
    t.Remove(7);
    t.InorderTraverse(); cout << endl;
    t.Remove(4);
    t.InorderTraverse(); cout << endl;
    t.Remove(2);
    t.InorderTraverse(); cout << endl;
    t.Remove(16);
    t.InorderTraverse(); cout << endl; */
/*     BTree2* t = new BTree2(3);
    t->Insert(1);
    t->Insert(2);
    t->Display();
    t->Insert(5);
    t->Insert(6);
    t->Display();
    t->Insert(3);
    t->Insert(4);
    t->Display(); */

// B+ tree
/*     int t = 3;
    BPlusTree* bpt = new BPlusTree(t);
    bpt->Insert("5", 33);
    bpt->Insert("15", 21);
    bpt->Insert("25", 31);
    bpt->Insert("35", 41);
    bpt->Insert("45", 10);
    bpt->Print();
    if(bpt->Search("5", 34) != NULL)
        cout <<  "Found" << endl;
    else
        cout << "Not Found" << endl; */

// Red-Black Tree
/*     RedBlackTree t;
    int arr[] = {1, 4, 6, 3, 5, 7, 8, 2, 9};
    for(int i=0; i<9; i++){
        t.Insert(arr[i]);
        cout << endl;
        t.InorderTraversal();
    }
    t.Print(); */
/*     RBTree t;
    t.Insert(7);
    t.Insert(3);
    t.Insert(18);
    t.Insert(10);
    t.Insert(22);
    t.Insert(8);
    t.Insert(11);
    t.Insert(26);
    t.Insert(2);
    t.Insert(6);
    t.Insert(13);
    t.PrintInorder();
    t.printLevelOrder();
    cout << endl << "Deleting 18, 11, 3, 10, 22" << endl;
    t.DeleteByValue(18);
    t.DeleteByValue(11);
    t.DeleteByValue(3);
    t.DeleteByValue(10);
    t.DeleteByValue(22);
    t.PrintInorder();
    t.printLevelOrder(); */

// Ternary Tree
/*     TernaryNode* root = CreateTernaryNode(30);
    root->left = CreateTernaryNode(5);
    root->middle = CreateTernaryNode(11);
    root->right = CreateTernaryNode(63);
    root->left->left = CreateTernaryNode(1);
    root->left->middle = CreateTernaryNode(4);
    root->left->right = CreateTernaryNode(8);
    root->middle->left = CreateTernaryNode(6);
    root->middle->middle = CreateTernaryNode(7);
    root->middle->right = CreateTernaryNode(15);
    root->right->left = CreateTernaryNode(31);
    root->right->middle = CreateTernaryNode(55);
    root->right->right = CreateTernaryNode(65);
    TernaryNode* head = nullptr;
    TernaryTreeToList(root, &head);
    PrintListOfTernaryTree(head); */

// Interval Tree
/*     Interval i[] = {{15, 20}, {10, 30}, {17, 19}, {5, 20}, {12, 15}, {30, 40}};
    int n = sizeof(i)/sizeof(i[0]);
    ITNode* root = nullptr;
    for(int j=0; j<n; j++)
        root = InsertITNode(root, i[j]);
    ITInorderTraverse(root);
    Interval x = {6, 7};
    Interval* res = SearchOverlapedInterval(root, x);
    if(res == nullptr)
        cout << "No Overlapping Interval"<< endl;
    else
        cout << "Overlaps with [" << res->low << "," << res->high << "]" << endl; */

// Custom GNU Tree-based Container 
/*     custom_node_update_policy<int, int , function<int(int)>, void*> policy;
    policy.apply(10, 20);
    cout << "Success" << endl; */


// 2-3-4 Tree



// Segment Tree






































































