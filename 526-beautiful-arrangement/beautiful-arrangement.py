class Solution:
    def __init__(self):
        self.ans = 0
    def solve(self,n,arr,nums,vis,j):
        if len(arr) == n:
            self.ans+=1
            return

        for i in range(n):
            if vis[i] == 0 and (nums[i] % j ==  0 or j % nums[i] == 0):
                vis[i] = 1
                arr.append(nums[i])
                self.solve(n,arr,nums,vis,j+1)
                arr.pop()
                vis[i] = 0

    def countArrangement(self, n: int) -> int:
        self.ans = 0
        vis = [0] * n
        nums = [0] * n
        arr = []
        for i in range(n):
            nums[i] = i+1
        j=1
        self.solve(n,arr,nums,vis,j)
        return self.ans