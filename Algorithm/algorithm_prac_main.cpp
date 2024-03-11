

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

// Subset Sum Problem
/*     vector<int> set = {3, 34, 4, 12, 5, 2};
    int n = set.size();
    int sum = 9;
    vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
    cout << IsSubsetSum_DPmemo(set, n, sum, dp) << " "; */
/*     vector<int> set = {3, 34, 4, 12, 5, 2};
    int n = set.size();
    int sum = 9;
    cout << IsSubsetSum_DPtable(set, n, sum) << " "; */

//Cutting a Rod
/*     vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = price.size();
    int index = n-1;
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    cout << CutRod_OverlappingSubproblem(price, index, n, dp) << " "; */
/*     vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = price.size();
    int index = n-1;
    cout << CutRod_BottomUp(price, n) << " "; */
/*     vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = price.size();
    int max_len = n;
    vector<int> length(n, 0);
    vector<vector<int>> dp(9, vector<int>(9, -1));
    for(int i=0; i<n; i++)
        length[i] = i+1;
    cout << CutRod_UnboundedKnapsack(price, n) << " "; */
/*     vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = price.size();
    cout << CutRod_DPiterative(price, n) << " "; */

// Painting Fence Algorithm
/*     int n = 3, k = 2;
    cout << PaintingFenceWays_OptimalSpace(n, k) << " "; */
    
// Longest Common Subsequence(LCS)
/*     string s1 = "aggtab";
    string s2 = "gxtxayb";
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
    cout << LCS_DPmemo(s1, s2, m, n, dp) << " "; */
/*     string s1 = "aggtab";
    string s2 = "gxtxayb";
    int m = s1.size();
    int n = s2.size();
    cout << LCS_DPtable(s1, s2, m, n) << " "; */
/*     string s1 = "aggtab";
    string s2 = "gxtxayb";
    int m = s1.size();
    int n = s2.size();
    cout << LCS_DPOptimalspace(s1, s2) << " "; */

// Longest Increasing Subsequence(LIS)
/*     vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = arr.size();
    int max = 1;
    cout << LongestIncreasingSubsequence_Recursion(arr, n, max) << " "; */
/*     vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    cout << LongestIncreasingSubsequence_DPmemo(0, -1, n, arr, dp) << " "; */
/*     vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = arr.size();
    cout << LongestIncreasingSubsequence_DPtable(arr, n) << " "; */
/*     vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = arr.size();
    cout << LongestIncreasingSubsequence_BinarySearch(arr) << " "; */

// Longest Subsequence that Difference between adjacents in 1
/*     vector<int> arr = {1, 2, 3, 4, 5, 3, 2};
    int n = arr.size();
    cout << LongestSubSequenceWithDiffOne_DP2(arr) << " "; */

// Maximum size Square Sub-Matrix with all 1
/*     vector<vector<int>> grid = {
        {0, 1, 1, 0, 1}, {1, 1, 0, 1, 0},
        {0, 1, 1, 1, 0}, {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1}, {0, 0, 0, 0, 0}
    };
    PrintMaxSizeSquareWithAllOne_OptimalSpace(grid); */

// Min Cost Path
/*     vector<vector<int>> cost = {
        {1, 2, 3},
        {4, 8, 2},
        {1, 5, 3}
    };
    vector<vector<int>> dp(cost.size(), vector<int>(cost[0].size(), -1));
    cout << MinCostPath_DPmemo(cost, 2, 2, dp); */
/*     vector<vector<int>> cost = {
        {1, 2, 3},
        {4, 8, 2},
        {1, 5, 3}
    };
    cout << MinCostPath_DPtable(cost, 2, 2); */
/*     vector<vector<int>> cost = {
        {1, 8, 8, 1, 5},
        {4, 1, 1, 8, 1},
        {4, 2, 8, 8, 1},
        {1, 5, 8, 8, 1}
    };
    cout << MinCostPath_Dijkstra(cost, 3, 4); */

// Minimum number of jumps to reach end
/*     vector<int> arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = arr.size();
    cout << MinJumpToEnd_Recursion(arr, 0, n-1); */

// Longest Common Substring
/*     string s1 = "GeeksforGeeks";
    string s2 = "GeeksQuiz";
    cout << LongestCommonSubstring_OptimalSpace(s1, s2); */
/*     string s1 = "GeeksforGeeks";
    string s2 = "GeeksQuiz";
    int m = s1.length();
    int n = s2.length();
    cout << LongestCommonSubstring_Recursion(s1, s2, m, n, 0); */

// Count ways to reach the nth stair using step 1, 2 or 3
/*     int n = 4;
    cout << WaysToReachStairEnd_Recursion(n); */
/*     int n = 4;
    cout << WaysToReachStairEnd_MatrixExponentiation(n); */
/*     int n = 4;
    cout << WaysToReachStairEnd_FourVar(n); */
/*     int n = 4;
    vector<int> dp(n+1, -1);
    cout << WaysToReachStairEnd_DPmemo(n, dp); */

// Count Unique Paths in Matrix
/*     int m = 3;
    int n = 3;
    cout << CountUniquePath_Recursion(m, n); */
/*     int m = 3;
    int n = 3;
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    cout << CountUniquePath_DPmemo(m, n, dp); */
/*     int m = 3;
    int n = 3;
    cout << CountUniquePath_DPOptimalspace(m, n); */
/*     int m = 3;
    int n = 3;
    cout << CountUniquePath_Combinatorics(m, n); */

// Unique Paths in a Grid with Obstables
/*     vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    cout << UniquePathWithObstacle_Recursion(grid, 0, 0); */
/*     vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    int r = grid.size();
    int c = grid[0].size();
    vector<vector<int>> path(r, vector<int>(c, -1));
    cout << UniquePathWithObstacle_DPmemo(grid, path, 0, 0); */

// 0/1 Knapsack Problem
/*     vector<int> profit = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int cap = 50;
    int n = profit.size();
    cout << Knapsack_Recursion(cap, weight, profit, n); */
/*     vector<int> profit = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int cap = 50;
    int n = profit.size();
    vector<vector<int>> dp(n, vector<int>(cap+1, -1));
    cout << Knapsack_DPmemo(cap, weight, profit, n-1, dp); */

// Unbounded Knapsack
/*     vector<int> profit = {10, 30, 20};
    vector<int> weight = {5, 10, 15};
    int cap = 100;
    int n = profit.size();
    vector<vector<int>> dp(n, vector<int>(cap+1, -1));
    cout << UnboundedKnapsack_DPmemo(cap, weight, profit, n-1, dp); */
/*     vector<int> profit = {10, 30, 20};
    vector<int> weight = {5, 10, 15};
    int cap = 100;
    int n = profit.size();
    cout << UnboundedKnapsack_DPOptimalSpace(cap, weight, profit, n); */

// Egg Dropping Puzzle
/*     int n = 2, k = 10;
    cout << EggDrop_DPtable(n, k); */
/*     int n = 2, k = 10;
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    cout << EggDrop_DPmemo(n, k, dp); */
/*     int n = 2, k = 10;
    cout << EggDrop_DPOptimal(n, k); */
/*     int n = 2, k = 10;
    cout << EggDrop_DPOptimalSpace(n, k); */

// Word Break Problem
/*     vector<string> dic = {
        "mobile", "samsung", "sam", "sung", "man", "mango",
        "icecream", "and", "go", "i", "like", "ice", "cream" 
    };
    cout << WordBreak_Recursion(dic, "ilikesamsung"); */
/*     cout << WordBreak_RecursionSuffixPrefix("ilikesamsung") << endl;
    cout << WordBreak_RecursionSuffixPrefix("iiiiiiii") << endl;
    cout << WordBreak_RecursionSuffixPrefix("") << endl;
    cout << WordBreak_RecursionSuffixPrefix("ilikelikeimangoiii") << endl;
    cout << WordBreak_RecursionSuffixPrefix("samsungandmango") << endl;
    cout << WordBreak_RecursionSuffixPrefix("samsungandmangok") << endl; */
/*     cout << WordBreak_DPOptimal("ilikesamsung") << endl;
    cout << WordBreak_DPOptimal("iiiiiiii") << endl;
    cout << WordBreak_DPOptimal("") << endl;
    cout << WordBreak_DPOptimal("ilikelikeimangoiii") << endl;
    cout << WordBreak_DPOptimal("samsungandmango") << endl;
    cout << WordBreak_DPOptimal("samsungandmangok") << endl; */
/*     vector<string> dic = {
        "mobile", "samsung", "sam", "sung", "man", "mango",
        "icecream", "and", "go", "i", "like", "ice", "cream" 
    };
    string str = "samsungandmangok";
    unordered_map<string, bool> mp;
    for(auto k: dic)
        mp[k] = true;
    cout << WordBreak_HashMap(mp, str); */
/*     vector<string> dic = {
        "mobile", "samsung", "sam", "sung", "man", "mango",
        "icecream", "and", "go", "i", "like", "ice", "cream" 
    };
    int n = dic.size();
    TrieNode* root = GetTrieNode();
    for(int i=0; i<n; i++)
        Insert_Trie(root, dic[i]);
    cout << WordBreak_Trie("ilikesamsung", root) << endl;
    cout << WordBreak_Trie("iiiiiiii", root) << endl;
    cout << WordBreak_Trie("", root) << endl;
    cout << WordBreak_Trie("ilikelikeimangoiii", root) << endl;
    cout << WordBreak_Trie("samsungandmango", root) << endl;
    cout << WordBreak_Trie("samsungandmangok", root) << endl; */
/*     string a = "iloveicecreamandmango";
    string b = "ilovesamsungmobile";
    WordBreak_Print_Backtracking(a, a.size(), "");
    cout<<  endl;
    WordBreak_Print_Backtracking(b, b.size(), ""); */

// Vertex Cover Problem
/*     Node* root = NewNode(20);
    root->left = NewNode(8);
    root->left->left = NewNode(4);
    root->left->right = NewNode(12);
    root->left->right->left = NewNode(10);
    root->left->right->right = NewNode(14);
    root->right = NewNode(22);
    root->right->right = NewNode(25);
    cout << VertexCoverBinaryTree_Recursion(root); */
/*     Node* root = NewNode(20);
    root->left = NewNode(8);
    root->left->left = NewNode(4);
    root->left->right = NewNode(12);
    root->left->right->left = NewNode(10);
    root->left->right->right = NewNode(14);
    root->right = NewNode(22);
    root->right->right = NewNode(25);
    cout << VertexCoverBinaryTree_DPtable(root); */
/*     int n = 8;
    vector<int> adj[n+1];
    AddEdge(adj, 1, 2);
    AddEdge(adj, 1, 7);
    AddEdge(adj, 2, 3);
    AddEdge(adj, 2, 6);
    AddEdge(adj, 3, 4);
    AddEdge(adj, 3, 8);
    AddEdge(adj, 3, 5);
    VertexCoverNormalTree_DPtable(adj, n); */
















