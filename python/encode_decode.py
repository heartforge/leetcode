class Solution:

    def encode(self, strs: List[str]) -> str:
        result = ""
        delimiter = ":"
        for word in strs:
            size = len(word)
            result = result + str(size) + delimiter + word

        return result

    def decode(self, s: str) -> List[str]:
        result = []
        str_ind = 0
        delimiter = ":"

        if len(s) == 1:
            return [""]
        while str_ind < len(s) - 1:
            word_len = s.split(delimiter)[0]

            str_ind = str_ind + len(word_len) + 1
            word_len = int(word_len)

            result.append(s[str_ind : str_ind + word_len])
            str_ind += word_len
        return result
