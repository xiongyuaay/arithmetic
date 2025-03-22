from typing import List

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        dict_p = dict()

        for ch in p:
            if ch not in dict_p:
                dict_p[ch] = 1
                continue
            dict_p[ch] += 1

        curr_dict = dict_p.copy()
        index_dict = dict()
        length = len(p)
        res = []

        l = 0
        for idx, ch in enumerate(s + " "):
            if idx - l == length:
                curr_dict[s[l]] += 1
                res.append(l)
                for i in range(l+1, idx):
                    if s[i] == s[l]:
                        index_dict[s[l]] = i
                        break
                l = l + 1
            if ch in curr_dict:
                if curr_dict[ch] == 0:
                    for i in range(l, index_dict[ch]):
                        curr_dict[s[i]] += 1

                    l = index_dict[ch] + 1
                    for i in range(l, idx+1):
                        if s[i] == ch:
                            index_dict[ch] = i
                            break
                else:
                    if curr_dict[ch] == dict_p[ch]:
                        curr_dict[ch] -= 1
                        index_dict[ch] = idx
                    else:
                        curr_dict[ch] -= 1
                        if index_dict[ch] < l:
                            for i in range(l, idx+1):
                                if s[i] == ch:
                                    index_dict[ch] = i
                                    break
            if ch not in curr_dict:
                l = idx + 1
                curr_dict = dict_p.copy()
        return res