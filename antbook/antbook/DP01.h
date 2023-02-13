#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <math.h>
#include <conio.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

// �i�b�v�T�b�N���
#define MAX_N  4
#define MAX_W  5
class DP23
{
public:
	int N = 4; // �i���̌�
	int W = 5;//�d���̑��a���v�𒴂��Ȃ�
	int weight[MAX_N] = { 2,1,3,2};//�d��
	int value[MAX_N] = { 3,2,4,2 };

	int dp[MAX_N + 1][MAX_W + 1];

	// i : �i��index
	// j : �d��MAX
	int rec(int index, int jjj) {
		int res = 0;

		if (dp[index][jjj] >= 0) {
			return dp[index][jjj];//���ʂ��ė��p
		}

		if (index == N) {
			res = 0;
		}
		else if ( jjj < weight[index] ) {
			//����Ȃ�
			res = rec(index + 1, jjj);//���̕i���@i+1
		}else{ 
			//����ꍇ�A����Ɏ��̕���T���i�T���͍̂ċA�ŒT���j
			int ta = rec(index + 1, jjj);
			int tb = rec(index + 1, jjj - weight[index]) + value[index];
			res = max(ta, tb);
		}
		//dp[index][jjj] = res; // �L�^
		return dp[index][jjj] = res;
	}

	void solve()
	{
		memset(dp, -1, sizeof(dp));

		int ret = rec(0,W);
		std::cout << "--------------------\n";
		cout << "ans = " << ret << "\n";


	}

	void main() {

		solve();
	}
};

class DP23_zenka
{
public:


	int N = 4; // �i���̌�
	int W = 5;//�d���̑��a���v�𒴂��Ȃ�
	int weight[MAX_N] = { 2,1,3,2 };//�d��
	int value[MAX_N]  = { 3,2,4,2 };

	int dp[MAX_N + 1][MAX_W + 1];


	void solve()
	{
		memset(dp, 0, sizeof(dp)); //���̎��͂O�N���A

		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j <= W; j++) {
				if (j < weight[i]) {
					dp[i][j] = dp[i+1][j];
				}
				else {
					int ta = dp[i + 1][j];
					int tb = dp[i + 1][j - weight[i]] + value[i];

					dp[i][j] = max(ta, tb);
				}
			}
		}

		std::cout << "--------------------\n";
		int ans = dp[0][W];
		cout << "ans = " << ans << "\n";


	}

	void main() {

		solve();
	}
};

