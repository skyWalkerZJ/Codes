#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int findString(vector<string>& words, string s) {
		int left = 0, right = words.size() - 1;
		while (left <= right) {
			if (words[left].size() == 0) {
				left++;
				continue;
			}
			if (words[right].size() == 0) {
				right--;
				continue;
			}
			int mid = (right + left) / 2;
			while (words[mid].size() == 0) {
				mid++;
				if (mid == right) {
					right = (right + left) / 2;
					continue;
				}
			}
			if (words[mid] == s)
				return mid;
			else if (words[mid] > s) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return -1;
	}
};