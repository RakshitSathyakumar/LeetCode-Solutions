class Solution:
    def convertToTitle(self, n: int) -> str:
        ans = ""
        while n:
            res = (n + 25) % 26
            ch = chr(res + ord('A'))
            ans += ch
            n = (n - 1) // 26
        ans = ans[::-1]
        return ans