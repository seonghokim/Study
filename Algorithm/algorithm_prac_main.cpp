

/* long input;
    long input1, input2, input3;
    char i_str[100];
    long result1=0, result2=0;
    bool state1, state2, state3;
    long linput1, linput2;
    long lresult1;
    printf("Enter 1 number: ");
    scanf("%ld",&linput1);
    printf("Enter 2 number: ");
    scanf("%ld %ld",&linput1, &linput2);
    printf("Enter string: ");
    scanf("%[^\n]s",i_str);
    
    EvenOddCompare(input); // 1
    SumOfEachEvenOddNum(input); // 2
    scanf("%d %d %d",&input1, &input2, &input3); // 3
    CheckLargestNum(input1,input2,input3); // 3
    scanf("%d %d", &input1, &input2);
    Swap(&input1, &input2);
    result1 = SumOfDigits(input,NULL, 0);
    result2 = SumOfDigits(0, i_str, 2);
    printf("result: %d, result: %d\n", result1, result2);
    result1 = FindMaxAmongSameDigitsNum(input);
    p rintf("result: %d\n",result1);
    NumVowelsNConsonants(i_str);
    state1 = CheckPrimeNum(input);
    state2 = CheckPerfectNum(input);
    state3 = CheckStrongNum(input);
    printf("prime %d perfect %d stroing %d\n", state1, state2, state3);
    state1 = CheckArmstrongNum(input);
    printf("armstrongnum %d \n", state1);
    result1 = ReverseNum(input);
    state1 = CheckPalindrome(input);
    printf("reversed num %d is palindrome %d \n", result1, state1);
    lresult1 = AddBinaryNum(linput1, linput2);
    printf("Binarynum: %ld\n", lresult1);
    lresult1 = Fibonacci(linput1);
    lresult1 = Bin2Gray(linput1);
    lresult1 = Gray2Bin(linput1);
    printf("bin : %ld\n", lresult1);
    TowerOfHanoi(3,'A','B','C'); */



   
    /* vector<int> arr = {2, 3, 5, 5, 8, 12, 15, 17, 19};
    vector<int> arr2 = {1, 3, 4, 5, 1, 6, 2 };//1, 3, 4, 5, 1, 6, 2 
     1, 2, 3, 5, 3, 6
    int key = 5;
    int res = FindMissingNum(arr2);
    FindLargest3ElementWithSort(arr);
    (res==-1)? cout<< "No Key in Array"<< endl : cout << "Key is located at index " << res;

 */

// Rat in Maze
/*     vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    vector<vector<int>> path(4, vector<int>(4, 0));
    vector<pair<int,int>> sol;
    int size = maze.size();
    // Print Coordinate of Solution Path
    sol.push_back({0,0});
    if(FindMazePath(0, 0, maze, path, sol)){
        for(auto& i : sol)
            cout << "(" << i.first << ", " << i.second << ")";
        cout << endl;
    }
    else
        cout << "Can't find solution\n";
    // Print Path to text image
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++)
            cout << path[i][j] << " ";
        cout << endl;
    } */
/*     vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    vector<vector<vector<int>>> res;
    vector<vector<int>> path(4, vector<int>(4, 0));
    int size = maze.size();
    // Print Coordinate of Solution Path
    if(FindMazePath(0, 0, maze, path, res)){
        int size_res = res.size();
        for(int k=0; k<size_res; k++){
            for(int i=0; i<size; i++){
                for(int j=0; j<size; j++)
                    cout << res[k][i][j] << " ";
                cout << endl;
            }
            cout << endl;
        }
    }
 */

// Sum of Subset
/*     vector<int> arr = {2, 3, 5, 5, 8, 12, 15, 17, 19};
    int sum = 18;
    vector<int> sub;
    set<vector<int>> subset;
    SumofSubSet(arr, sum, sub, 0, subset);
    cout<< endl;
    for(auto k: subset){
        for(auto t : k)
            cout << t << " ";
        cout << endl;
    } */

// UDGraph M Coloring
/*     vector<vector<bool>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    vector<vector<int>> result;
    int size = graph.size();
    int m = 3;
    vector<int> color(size, -1);
    
    if(UDGraphColoring(graph, m, color, 0, result))
        PrintUDGraphColoring(result);
    else
        cout << "No result" << endl;
 */

// Hamiltonian Cycle
/*     vector<vector<bool>> graph = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };
    int size = graph.size();
    int start_pos = 4;
    vector<int> path(size+1, -1);
    if(HamiltonianCycle(graph, path, start_pos, 0))
        PrintHamiltonCycle(path, size, start_pos);
    else
        cout << "No result" << endl;
    cout << endl;
    vector<vector<bool>> graph2 = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}
    };
    int size2 = graph2.size();
    int start_pos2 = 0;
    vector<int> path2(size2+1, -1);
    if(HamiltonianCycle(graph2, path2, start_pos2, 0))
        PrintHamiltonCycle(path2, size2, start_pos2);
    else
        cout << "No result" << endl; */

// Sudoku
/*     vector<vector<int>> grid = {
        { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
        { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
        { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
        { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
        { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
        { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
        { 0, 0, 5, 2, 0, 6, 3, 0, 0 }
    };
    int size = grid.size();
    vector<int> row(size, 0);
    vector<int> col(size, 0);
    vector<int> box(size, 0);
    if(SudokuWithBitMask(grid, 0, 0, row, col, box))
        PrintSudoku(grid);
 */

// Remove Invalid Parentheses
/*     string expression = "()())()";
    RemoveInvalidParentheses(expression);
    expression = "()v)";
    RemoveInvalidParentheses(expression);
 */

// GraycodeToNBitNum
/*     vector<int> res;
    int n = 3;
    int cur = 0;
    GraycodeToNBitNum(res, n, cur);
    for(auto k : res)
        cout << k << endl;
 */

// Permutation of String
/*     string str = "abb";
    int n = str.size();
    PermutateStringWithNextPermutation(str);
 */

// PrintMaxActivities
/*     vector<pair<int,int>> work = {
        {2, 1},{4,3}, {6,0}, {7,5}, {9,8}, {9,5}
    };
    vector<int> result;
    PrintMaxActivities(work, result);
    for(auto k : result)
        cout << k << " ";
    cout << endl; */

// PrintMaxProfitJobSequencing
/*     Job arr[] = {
        {'a', 4, 100},
        {'b', 1, 19},
        {'c', 2, 27},
        {'d', 1, 25},
        {'e', 3, 15}
    };
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<char> result;
    PrintMaxProfitJobSequencing(arr, n, result);
    for(auto k : result)
        cout << k << " ";
    cout << endl; */

// Huffman Encoding
/*     vector<pair<char, int>> str = {
        {'a', 5},
        {'b', 9},
        {'c', 12},
        {'d', 13},
        {'e', 16},
        {'f', 45}
    };
    HuffmanCode(str); */

// Huffman Decoding
/*     string str = "geeksforgeeks";
    string encoded, decoded;
    map<char, int> freqTable;
    map<char, string> codes;
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, CompareFrequency> minheap;
    CalculateCharFrequency(freqTable, str);
    Huffman_Encoding(freqTable, codes, minheap);
    for(auto k : str)
        encoded += codes[k];
    cout << "Encoded string: " << encoded << endl;
    decoded = Huffman_Decoding(minheap.top(), encoded);
    cout << "Decoded string: " << decoded << endl;
 */

// Water Connection
/*     int h = 9, p = 6;
    vector<int> start(h+1, 0);
    vector<int> pipe(h+1, INF);
    vector<int> end(h+1, 0);
    vector<vector<int>> arr = {
        {7, 4, 98}, {5, 9, 72}, {4, 6, 10},
        {2, 8, 22}, {9, 7, 17}, {3, 1, 66}
    };
    WaterConnection(arr, start, end, pipe); */

// MinSwapCount
/*     string s = "[]][][";
    cout << MinSwapCount(s) << "\n";
 
    s = "[[][]]";
    cout << MinSwapCount(s) << "\n"; */

// Egyptian Fraction
/*     string str = "";
    vector<int> result = GetEgyptianFraction(12, 13, {});
    for(auto k : result)
        str +="1/" + to_string(k) + " + ";
    string temp = str.substr(0, str.length()-3);
    cout << temp << endl; */

// Police catch Thief
/*     int k = 2;
    string str = "PTTPT";
    cout << PoliceCatchThief(str, k) << endl;
    str = "TTPPTP";
    cout << PoliceCatchThief(str, k) << endl;
    str = "PTPTTP";
    cout << PoliceCatchThief(str, k) << endl; */

// FittingShelves
/*     int wall = 29, m = 3, n = 9;
    FittingShelves(wall, m, n);
    wall = 76, m = 1, n = 10;
    FittingShelves(wall, m, n); */

// AssignMice2Hole
/*     vector<int> mice = {4, -4, 2};
    vector<int> hole = {4, 0, 5};
    int min = AssignMice2Hole(mice, hole);
    cout << min << endl;
 */

// MinProductSubset
/*     vector<int> a = {-1, -1, -2, 4, 3};
    cout << MinProductSubset(a) << endl; */

// MaxArraySumKNegation
/*     vector<int> arr = {-2, 0, 5, -1, 2};
    cout << MaxArraySumKNegation(arr, 4) << endl; */

// MinSumOfProductOfTwoArray
/*     vector<int> a = {2, 3, 4, 5, 4};
    vector<int> b = {3, 4, 2, 3, 2};
    cout << MinSumOfProductOfTwoArray(a, b, 3) << endl; */

// MinSumOfAbsDiffOfPairTwoArr
/*     vector<int> a = {2, 3, 4, 5, 4};
    vector<int> b = {3, 4, 2, 3, 2};
    cout << MinSumOfAbsDiffOfPairTwoArr(a, b) << endl; */

// TransformNonIncArr
/*     vector<int> a = {2, 3, 4, 5, 4};
    cout << TransformNonIncArr(a) << endl; */

// IsSortingWithOnlyReverse
/*     vector<int> a = { 1, 7, 6, 4, 5, 3, 2, 8 };
    cout << IsSortingWithOnlyReverse(a) << endl; */

// MaxSumAreaOfRectangle
/*     vector<int> a = { 10, 10, 10, 10, 11, 10, 11, 10, 9, 9, 20, 20 };
    cout << MaxSumAreaOfRectangle(a) << endl; */

// AtMostKSwap
/*     vector<int> a = {3, 5, 4, 1, 2};
    int k = 4;
    AtMostKSwap(a, k);
    for(auto& k : a)
        cout << k << " "; */

// MaxDiffofSumOfSubset
/*     vector<int> a = {8, 4, 5, 2, 10};
    int k = 2;
    cout << MaxDiffofSumOfSubset(a, k) << endl; */

// First Fit
/*     vector<int> block = {100, 500, 200, 300, 600};
    vector<int> process = {212, 417, 112, 426};
    FirstFit(block, process); */

// Best Fit
/*     vector<int> block = {100, 500, 200, 300, 600};
    vector<int> process = {212, 417, 112, 426};
    BestFit(block, process); */

// Worst Fit
/*     vector<int> block = {100, 500, 200, 300, 600};
    vector<int> process = {212, 417, 112, 426};
    WorstFit(block, process); */

// CheckTwoJobsAtATime
/*     vector<pair<int, int>> job = {
        {1, 2}, {2, 3}, {4, 5}
    };
    cout << CheckTwoJobsAtATime(job); */

// OptimalPageReplacement
/*     vector<int> page = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int f_size = 4;
    OptimalPageReplacement(page, f_size);
 */
/*     vector<int> page = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5};
    int f_size = 4;
    OptimalPageReplacementWithUnorderedSet(page, f_size); */

// Kruskal's MST
/*     Graph g(4);
    g.AddEdge(0, 1, 10);
    g.AddEdge(1, 3, 15);
    g.AddEdge(2, 3, 4);
    g.AddEdge(2, 0, 6);
    g.AddEdge(0, 3, 5);
    g.Kruskal_MST(); */

// Prim's MST
/*     vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    Prim_MSTwithAdjacencyMatrix(graph); */
/*     vector<vector<int>> graph = {
        {0, 1, 5},
        {1, 2, 3},
        {0, 2, 1}
    };
    cout << Prim_MSTwithPriorityQueue(graph); */

// Boruvka's MST
/*     BoruvkaGraph g(4);
    g.AddEdge(0, 1, 10);
    g.AddEdge(0, 2, 6);
    g.AddEdge(0, 3, 5);
    g.AddEdge(1, 3, 15);
    g.AddEdge(2, 3, 4);
    g.Boruvka_MST(); */

// Dinic's Max Flow Problem
/*     DinicGraph g(6);
    g.AddEdge(0, 1, 16);
    g.AddEdge(0, 2, 13);
    g.AddEdge(1, 2, 10);
    g.AddEdge(1, 3, 12);
    g.AddEdge(2, 1, 4);
    g.AddEdge(2, 4, 14);
    g.AddEdge(3, 2, 9);
    g.AddEdge(3, 5, 20);
    g.AddEdge(4, 3, 7);
    g.AddEdge(4, 5, 4);
    cout << g.Dinic_MaxFlow(0, 5); */

// Fulkerson's Max Flow Problem
/*     vector<vector<int>> graph = {
        {0, 16, 13, 0, 0, 0}, {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0}, {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4}, {0, 0, 0, 0, 0, 0}
    };
    cout << Fulkerson_MaxFlow(graph, 0, 5); */

// Number of Single Cycle Components in Undirected Graph
/*     Cycle_AddEdge(1, 10);
    Cycle_AddEdge(1, 5);
    Cycle_AddEdge(5, 10);
    Cycle_AddEdge(2, 9);
    Cycle_AddEdge(9, 15);
    Cycle_AddEdge(2, 15);
    Cycle_AddEdge(2, 12);
    Cycle_AddEdge(12, 15);
    Cycle_AddEdge(13, 8);
    Cycle_AddEdge(6, 14);
    Cycle_AddEdge(14, 3);
    Cycle_AddEdge(3, 7);
    Cycle_AddEdge(7, 11);
    Cycle_AddEdge(11, 6);
    cout << CountingCycle(15, 14); */

// Bin Packing Problem(Minimize number of used bins)
/*     vector<int> weight = {2, 5, 4, 7, 1, 3, 8};
    int cap = 10;
    cout << BinPakcing_NextFit(weight, cap); */

// Graph Coloring
/*     GraphColoring g(5);
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 2);
    g.AddEdge(1, 3);
    g.AddEdge(2, 3);
    g.AddEdge(3, 4);
    g.Coloring();
    cout << endl;
    GraphColoring g2(5);
    g2.AddEdge(0, 1);
    g2.AddEdge(0, 2);
    g2.AddEdge(1, 2);
    g2.AddEdge(1, 4);
    g2.AddEdge(2, 4);
    g2.AddEdge(4, 3);
    g2.Coloring(); */

// K Center Problem
/*     vector<vector<int>> weight = {
        {0, 4, 8, 5},
        {4, 0, 10, 7},
        {8, 10, 0, 9},
        {5, 7, 9, 0}
    };
    int k = 2;
    KCenter(weight, k); */

// Shortest Superstring Problem
/*     vector<string> arr = {"catgc", "ctaagt", "gcta", "ttca", "atgcatc"};
    cout << FindShortestSuperstring(arr); */

// Fractional Knapsack Problem
/*     int W = 50;
    Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
    int N = sizeof(arr) / sizeof(arr[0]);
    cout << FractionalKnapSack(W, arr, N); */

// Minimum number of coins
/*     FindMinCoins(93); */

// Count ways to assign unique cap to every person
/*     int n = 3;
    int allmask = (1 << n) -1;
    vector<int> caplist[101];
    caplist[5].push_back(0);
    caplist[100].push_back(0);
    caplist[1].push_back(0);
    caplist[2].push_back(1);
    caplist[5].push_back(2);
    caplist[100].push_back(2);
    vector<vector<int>> dp(1025, vector<int>(101, -1));
    cout << CountWaysToAssignCap(0, 1, caplist, dp, allmask); */

// Travelling Salesman Problem(Bitmasking)
/*     vector<vector<char>> arr = {// r = arr.size(), c = arr[0].size();
        {'.', '.', '.', '.', '.', '*', '.'},
        {'.', '.', '.', '#', '.', '.', '.'},
        {'.', '*', '.', '#', '.', '*', '.'},
        {'.', '.', '.', '.', '.', '.', '.'}
    };
    int r = arr.size();
    int c = arr[0].size();
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            if(arr[i][j] == '*')
                dirty.push_back({i, j});
    dirty.insert(dirty.begin(), {0, 0});
    int len = dirty.size();
    int limit = (1<<len)-1;
    vector<vector<int>> dp(len, vector<int>((1<<len), -1));
    vector<vector<vector<int>>> dist(r+1, vector<vector<int>>(c+1, vector<int>(len, INF)));
    for(int i=0; i<len; i++)
        GetDist_TravelSalesman(dist, arr, r, c, i);
    cout << TravelSalesman_Bitmasking(0, 1, dp, dist); */
// Travelling Salesman Problem(Bitmasking + DP)
/*     int n = 4;
    vector<vector<int>> dist = {//node 1  {1, 1~4} 
        {0, 0, 0, 0, 0},
        {0, 0, 10, 15, 20},
        {0, 10, 0, 25, 25},
        {0, 15, 25, 0, 30},
        {0, 20, 25, 30, 0}
    };
    vector<vector<int>> memo(n+1, vector<int>(1<<(n+1), 0));
    int result = INF;
    for(int i=1; i <= n; i++)// 1 node --> any node --> i node --> 1 node
        result = min(result, TravelSalesman_DP(i, (1 <<(n+1))-1, dist, memo)+dist[i][1]);
    cout << result << endl; */

// Sum Over Subset
/*     int n = 2;
    vector<int> a = {7, 12, 14, 16};
    SumOverSubset_BruteForce(a, n); */

// Fibonacci Number
/* cout << Finonacci_PowerOfMatrix(9); */

// Catalan Number
/*     cout << CatalanNumber_BinomialCoefficient(9); */

// Binomial Coefficient
/*     int n = 5, k = 2;
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    cout << BinomialCoeff_DP3(n, k, dp); */

// Count All Combination of coins to make sum
/*     vector<int> coin = {1, 2, 3};
    int n = coin.size();
    int sum = 5;
    cout << CountAllCombiOfCoint_Recursion(coin, n, sum) << " "; */
/*     vector<int> coin = {1, 2, 3};
    int n = coin.size();
    int sum = 5;
    vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
    cout << CountAllCombiOfCoint_DPmemo(coin, n, sum, dp) << " "; */






























