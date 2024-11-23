//
//  main.cpp
//  搜索旋转排序数组
//
//  Created by 付闯 on 2024/11/3.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target? 0 : -1;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            // 判断中间值所在的区间以及目标值应该在的区间
            if (nums[0] <= nums[mid]) {
                // 如果目标值在左侧有序区间内
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                // 如果目标值在右侧有序区间内
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    int result = solution.search(nums, target);
    if (result!= -1) {
        std::cout << "Target found at index: " << result << std::endl;
    } else {
        std::cout << "Target not found." << std::endl;
    }

    return 0;//综合考虑main和develop分支的修改思路后重新编写
}

//第二次添加的内容



