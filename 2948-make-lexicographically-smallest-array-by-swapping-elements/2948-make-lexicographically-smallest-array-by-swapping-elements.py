from collections import deque
from typing import List

class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        n = len(nums)
        sorted_nums = sorted(nums)
        mpp1 = {} 
        mpp2 = {} 

        grp = 0
        mpp1[grp] = deque([sorted_nums[0]])

        for i in range(1, n):
            if sorted_nums[i] - sorted_nums[i - 1] > limit:
                grp += 1
            if grp not in mpp1:
                mpp1[grp] = deque()
            mpp1[grp].append(sorted_nums[i])
            mpp2[sorted_nums[i]] = grp
        
        for grp, dq in mpp1.items():
            for num in dq:
                mpp2[num] = grp

        ans = []
        for num in nums:
            resp_grp = mpp2[num]
            ans.append(mpp1[resp_grp].popleft())
        return ans
