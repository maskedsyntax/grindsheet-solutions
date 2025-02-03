class Solution:

    # Function to return a list containing the union of the two arrays.
    def findUnion(self, a, b):
        i = 0
        j = 0
        ans = []

        while i < len(a) and j < len(b):
            if a[i] < b[j]:
                ans.append(a[i])
                while i + 1 < len(a) and a[i + 1] == a[i]:
                    i += 1
                else:
                    i += 1
            elif a[i] > b[j]:
                ans.append(b[j])
                while j + 1 < len(b) and b[j + 1] == b[j]:
                    j += 1
                else:
                    j += 1
            else:
                ans.append(a[i])
                while i + 1 < len(a) and a[i + 1] == a[i]:
                    i += 1
                else:
                    i += 1
                while j + 1 < len(b) and b[j + 1] == b[j]:
                    j += 1
                else:
                    j += 1

        while i < len(a):
            ans.append(a[i])
            while i + 1 < len(a) and a[i + 1] == a[i]:
                i += 1
            else:
                i += 1

        while j < len(b):
            ans.append(b[j])
            while j + 1 < len(b) and b[j + 1] == b[j]:
                j += 1
            else:
                j += 1

        return ans
