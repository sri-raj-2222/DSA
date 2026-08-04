class Solution:
    def solve(self,i,arr,nums,tar,ans):
        if(tar == 0):
            ans.append(arr[:])
            return
        if tar <= 0 or i == len(nums):
            return
        arr.append(nums[i])
        self.solve(i,arr,nums,tar-nums[i],ans)
        arr.pop()
        self.solve(i+1,arr,nums,tar,ans)

    def combinationSum(self, nums: List[int], tar: int) -> List[List[int]]:
        arr = []
        ans = []
        self.solve(0,arr,nums,tar,ans)
        return ans