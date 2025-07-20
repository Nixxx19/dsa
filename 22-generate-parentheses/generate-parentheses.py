class Solution(object):
    def generateParenthesis(self, n):
        def backtrack(current_string='', open_count=0, close_count=0):
            if len(current_string) == 2 * n:
                result.append(current_string)
                return
            if open_count < n:
                backtrack(current_string + '(', open_count + 1, close_count)
            if close_count < open_count:
                backtrack(current_string + ')', open_count, close_count + 1)

        result = []
        backtrack()
        return result
