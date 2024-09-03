#include<bits/stdc++.h>

#include<bits/stdc++.h>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        double right_product = 1;
        double left_product = 1;
        double maximum = INT_MIN;

        for(int i = 0; i < nums.size(); i++)
        {
            if (right_product == 0) right_product = 1;
            else if (left_product == 0) left_product = 1;
                right_product *= nums[i];
                left_product *= nums[nums.size() - i - 1];
            maximum = std::max(maximum, std::max(right_product, left_product));
        }

        return maximum;
    }
};