class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        ROW_LEN = len(matrix[0]) - 1

        l_row = 0
        r_row = len(matrix) - 1

        while l_row <= r_row:
            m_row = (l_row + r_row) // 2
            if target > matrix[m_row][ROW_LEN]:
                l_row = m_row + 1
            elif target < matrix[m_row][0]:
                r_row = m_row - 1
            else:
                break

        m_row = (l_row + r_row) // 2
        l, r = 0, len(matrix[0]) - 1

        while l <= r:
            m = (l + r) // 2
            if target > matrix[m_row][m]:
                l = m + 1
            elif target < matrix[m_row][m]:
                r = m - 1
            else:
                return True

        return False
