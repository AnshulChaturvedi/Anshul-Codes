class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        ans = []
        n = len(A)
        setA, setB = set(), set()
        cnt = 0
        for i in range(n):
            setA.add(A[i])
            setB.add(B[i])
            if A[i] in setB:
                cnt += 1
            if B[i] in setA:
                cnt += 1
            if A[i] == B[i]:
                cnt -= 1
            ans.append(cnt)
            
        return ans