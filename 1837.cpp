#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

const int HOOK_NUM_MAX = 20;
const int WEIGHT_NUM_MAX = 20;
const int HOOK_MAX = 15;
const int WEIGHT_MAX = 25;
const int MOMENT_MAX = WEIGHT_MAX * WEIGHT_NUM_MAX * HOOK_MAX * 2; // 考虑到负钩子位置

int hookNum, weightNum;
int hooks[HOOK_NUM_MAX], weights[WEIGHT_NUM_MAX];
int possibilities[MOMENT_MAX * 2 + 1]; // 使用一维数组来存储可能的状态

int main() {
	scanf("%d %d", &hookNum, &weightNum);
	for (int h = 0; h < hookNum; h++) {
		scanf("%d", &hooks[h]);
	}
	for (int w = 0; w < weightNum; w++) {
		scanf("%d", &weights[w]);
	}

	// 初始化可能性数组
	possibilities[MOMENT_MAX] = 1; // 0力矩初始状态

	// 动态规划计算可能性
	for (int w = 0; w < weightNum; w++) {
		int nextPossibilities[MOMENT_MAX * 2 + 1] = { 0 }; // 存储下一状态的可能性
		for (int h = 0; h < hookNum; h++) {
			for (int moment = 0; moment <= MOMENT_MAX * 2; moment++) {
				if (possibilities[moment]) {
					int newMoment = moment + weights[w] * hooks[h];
					if (newMoment >= 0 && newMoment <= MOMENT_MAX * 2) {
						nextPossibilities[newMoment] += possibilities[moment];
					}
				}
			}
		}
		// 更新当前状态的可能性
		for (int moment = 0; moment <= MOMENT_MAX * 2; moment++) {
			possibilities[moment] = nextPossibilities[moment];
		}
	}

	// 输出达到平衡状态的方式数量
	printf("%d\n", possibilities[MOMENT_MAX]);
	return 0;
}