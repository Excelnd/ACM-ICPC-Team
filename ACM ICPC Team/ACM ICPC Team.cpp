// ACM ICPC Team.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int bitwiseOr(string &topic1, string &topic2) {
	string output;
	output.resize(topic1.size());
	for (int i = 0; i < topic1.size(); i++) {
		output[i] = topic1[i] == '1' || topic2[i] == '1' ? '1' : '0';
	}
	int c = 0;
	for (int i = 0; i < output.size(); i++) {
		if (output[i] == '1') c++;
	}
	return c;
}

int main()
{
	int n;
	int m;
	cin >> n >> m;
	vector<string> topic(n);
	for (int topic_i = 0; topic_i < n; topic_i++) {
		cin >> topic[topic_i];
	}

	vector<int> maxVec;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			maxVec.push_back(bitwiseOr(topic[i], topic[j]));
		}
	}

	sort(maxVec.begin(), maxVec.end(), greater<int>());
	for (int i = 1; i < maxVec.size(); i++) {
		if (maxVec[i] != maxVec[0]) {
			cout << maxVec[0] << endl << i << endl;
			break;
		}
	}

    return 0;
}

