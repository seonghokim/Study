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
/*     RBTree2* tree = new RBTree2();
    string sent, word;
    sent = "old is gold";
    vector<string> word_arr;
    stringstream ss(sent);
    while(ss >> word)
        word_arr.push_back(word);
    for(int i=0; i<word_arr.size(); i++)
        tree->root = tree->Insert(tree, word_arr[i]);
    tree->LevelOrder(tree->root);
    word = "forever";
    tree->root = tree->Insert(tree, word);
    cout << endl;
    tree->LevelOrder(tree->root); */

// Left Leaning Red Black Tree
/*     LLRBTreeNode* root = nullptr;
    root = InsertLLRB(root, 10);
    root->color = false;
    root = InsertLLRB(root, 20);
    root->color = false;
    root = InsertLLRB(root, 30);
    root->color = false;
    root = InsertLLRB(root, 40);
    root->color = false;
    root = InsertLLRB(root, 50);
    root->color = false;
    root = InsertLLRB(root, 25);
    root->color = false;
    InorderLLRB(root); */

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

// Persistent Segment Tree
/*     int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);
    STreeNode* version[100];
    STreeNode* root = new STreeNode(nullptr, nullptr, 0);
    STreeBuild(root, 0, n-1, arr);
    version[0] = root;
    version[1] = new STreeNode(nullptr, nullptr, 0);
    STreeUpgrade(version[0], version[1], 0, n-1, 4, 1);
    version[2] = new STreeNode(nullptr, nullptr, 0);
    STreeUpgrade(version[1], version[2], 0, n-1, 2, 10);
    cout << STreeQuery(version[1], 0, n-1, 0, 4) << endl;
    cout << STreeQuery(version[2], 0, n-1, 3, 4) << endl;
    cout << STreeQuery(version[0], 0, n-1, 0, 3) << endl; */

// Efficient Segment Tree
/*     int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    int tree[2*n];
    SegTreeBuild(arr, tree, n);
    cout << SegTreeQuery(1, 3, n, tree) << endl;
    SegTreeUpdate(2, 1, tree, n);
    cout << SegTreeQuery(1, 3, n, tree); 
 */

// Segment Tree
/*     vector<int> arr = {1, 3, 2, 5, 4, 6};
    SegmentTree st(arr);
    cout << st.Query(1, 5) << endl; */

// Iterative Segment Tree
/*     vector<int> arr = {2,6,10,4,7,28,9,11,6,33};
    int n = arr.size();
    vector<int> tree(2*n);
    BuildIterativeSegmentTre(tree, arr, n);
    int l = 1, r = 5;
    cout << QueryIterativeSegmentTree(tree, l, r+1, n) << endl;
    int idx = 5, val =32;
    UpdateIterativeSegmentTree(tree, idx, val, n);
    l = 2, r = 8;
    cout << QueryIterativeSegmentTree(tree, l, r+1, n); */

// Segment Tree Using Stack
/*     memset(sgtree, 0, sizeof(int64_t)* 1000);
    memset(lazy, 0, sizeof(int64_t) * 1000);
    int64_t arr[] = {1,3,5,7,9,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    BuildSGTreeStack(arr, n);
    cout << QuerySGTreeStack(n,1,3)<<endl;
    UpdateSGTreeStack(n,1,5,10);
    cout << QuerySGTreeStack(n,1,3)<<endl; */

// Dynamic Segment Tree
/*     DSTNode* root = GetDSTNode();
    UpdateDSTree(root, 1, 1, 10, 10);
    UpdateDSTree(root, 3, 1, 10, 5);
    cout << QueryDSTree(root, 2, 8, 1, 10) << endl;
    cout << QueryDSTree(root, 1, 10, 1, 10) << endl; */

// Lazy Propagation in Segment Tree
/*     int arr[] = {1,3,5,7,9,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    BuildLazySGTree(arr, 0, n-1, 0);
    cout << GetSumLazySGTree(0, n-1, 1, 3, 0) << endl;
    UpdateLazySGTree(0, 0, n-1, 1, 5, 10);
    cout << GetSumLazySGTree(0, n-1, 1, 3, 0) << endl; */

// Lazy Propagation in Set Segment Tree
/*     vector<int> arr = {1,2,3,4};
    LazySetSegTree *sgt = new LazySetSegTree(arr);
    sgt->How_to_Use(); */
/*     vector<int> arr = {1,2,3,4};
    LazySetSegTree *sgt = new LazySetSegTree(arr);
    sgt->Update(0,0,sgt->GetN()-1,0,3,0, sgt->SetTM());
    sgt->Update(0,0,sgt->GetN()-1,2,3,2,sgt->SetTM());
    sgt->Update(0,0,sgt->GetN()-1,0,2,10,sgt->SetTM());
    int res = sgt->Query(1,2);
    cout << res << endl; */

















































