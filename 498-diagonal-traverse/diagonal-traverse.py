class Solution(object):
    def findDiagonalOrder(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: List[int]
        """
        m,n=len(mat),len(mat[0])
        ans=[]
        map=defaultdict(list)
        for i in range(m):
            for j in range(n):
                map[i+j].append(mat[i][j])
        for k in map.keys():
            if k%2==0:
                ans.extend(reversed(map[k]))
            else:
                ans.extend(map[k])
        return ans

        