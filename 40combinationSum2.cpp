#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findCombination(vector<vector<int>> &res, const int order, const int target, vector<int> &local, const vector<int> &candidates)
{
  if(target == 0)
  {
    res.push_back(local);
    return;
  }
  else
  {
    for(int i = order; i != candidates.size(); ++i)
    {
      if(candidates[i] > target)
        return;
      if(i && candidates[i] == candidates[i-1] && i>order)
        continue;
      local.push_back(candidates[i]);
      findCombination(res, i+1, target-candidates[i], local, candidates);
      local.pop_back();
    }
  }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
  vector<vector<int>> res;
  sort(candidates.begin(), candidates.end());
  vector<int> local;
  findCombination(res, 0, target, local, candidates);
  return res;
}

int main()
{
  vector<int> a{1,3,2,4,6,4,5};
  vector<vector<int>> goal = combinationSum2(a, 4);
  for(auto &i : goal)
  {
    for(auto &a : i)
      cout << a << " ";
    cout << endl;
  }
  return 0;
}
