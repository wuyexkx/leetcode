#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

/**************************存在重复元素*********************************
 * 
给定一个整数数组，判断是否存在重复元素。

如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

示例 1:

输入: [1,2,3,1]
输出: true
示例 2:

输入: [1,2,3,4]
输出: false
示例 3:

输入: [1,1,1,3,3,4,3,2,4,2]
输出: true
*******************************************************************/

class Solution {
public:
    // 1. 利用unordered_set的 count和insert成员函数得到是否插入重复元素
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_set<int> hash_set;
        for(auto n : nums)
        {
            if(hash_set.count(n))
                return true; // 存在重复直接返回
            hash_set.insert(n);
        }
        return false;        // 不存在重复
    }

    // 2. 先排序，然后查找相邻元素是否相等
    // bool containsDuplicate(vector<int>& nums) 
    // {
    //     sort(begin(nums), end(nums));
    //     for (int i = 1; i < nums.size(); i++)
    //         if (nums[i] == nums[i-1])
    //             return true;
    //     return false;
    // }
};



// 测试主程序
int main()
{
    // 测试用例
    vector<int> v{0,2,3,4,0};

    Solution so;
    cout << "results: " << so.containsDuplicate(v) << endl;

    return 0;
}
