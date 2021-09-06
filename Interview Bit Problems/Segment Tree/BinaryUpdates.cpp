void Build (int index, int start, int end, vector <int> &Tree, vector <int> &A)
{
  if (start == end)
  Tree[index] = A[start];

  else
  {
    int mid = start + (end - start) / 2,
         Left_Child = 2 * index + 1,
         Right_Child = Left_Child + 1;

      Build (Left_Child, start, mid, Tree, A);
      Build (Right_Child, mid + 1, end, Tree, A);

      Tree[index] = Tree[Left_Child] + Tree[Right_Child];
  }
}

int Query (int index, int start, int end, int count, vector <int> &Tree)
{
    if (start == end)
    return start;

    int mid = start + (end - start) / 2,
         LeftChild = 2 * index + 1,
         RightChild = LeftChild + 1;

    return (Tree[LeftChild] >= count) ? Query (LeftChild, start, mid, count, Tree) : Query (RightChild, mid + 1, end, count - Tree[LeftChild], Tree);

}

void Update (int index, int start, int end, int UpdateLocation, int UpdateValue, vector <int> &Tree)
{
  // We will not update the values at other locations
  if (UpdateLocation < start || UpdateLocation > end)
  return;

  // If the function comes here and start = end, it automatically implies that start = UpdateLocation = end
  if (start == end)
  Tree[index] += UpdateValue;

 // Updating Values in the Segment Tree only where it is needed using Recursion
  else 
  {
    int mid = start + (end - start) / 2,
        Left_Child = 2 * index + 1,
        Right_Child = Left_Child + 1;

    Update (Left_Child, start, mid, UpdateLocation, UpdateValue, Tree);
    Update (Right_Child, mid + 1, end, UpdateLocation, UpdateValue, Tree);

    Tree[index] = Tree[Left_Child] + Tree[Right_Child];
    
  }
}

vector<int> Solution::solve(int A, vector<vector<int> > &B) {
    
    vector <int> Data (A, 1);
    vector <int> Tree (4*A, 0);
    vector <int> Answer;
    
    Build (0, 0, A - 1, Tree, Data);

    for (auto iter : B)
    {
      if (iter[0] == 0 && Data[iter[1] - 1] != 0)
      {
        Update (0, 0, A - 1, iter[1] - 1, -1, Tree);
        Data[iter[1] - 1] = 0;
      }
      
      else if (iter[0] == 1)
      (Tree[0] >= iter[1]) ? Answer.push_back (Query (0, 0, A - 1, iter[1], Tree) + 1) : Answer.push_back (-1);

    }
    
    return Answer;
    
}