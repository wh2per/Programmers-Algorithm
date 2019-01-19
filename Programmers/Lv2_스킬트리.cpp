#include <string>
#include <vector>

using namespace std;

int solution58(string skill, vector<string> skill_trees) {
	int answer = 0;
	vector<bool> check(26);

	for (int i = 0; i < skill.length(); i++)
		check[skill[i] - 65] = true;

	for (int i = 0; i < skill_trees.size(); i++) {
		int index = 0;
		int j;
		for (j = 0; j < skill_trees[i].length(); j++) {
			if (check[skill_trees[i][j] - 65]) {
				if (skill[index] == skill_trees[i][j])
					index++;
				else
					break;
			}
		}
		if (j == skill_trees[i].length())
			answer++;
	}
	return answer;
}
