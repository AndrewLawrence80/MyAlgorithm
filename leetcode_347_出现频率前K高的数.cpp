#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Cnt
{
public:
	int num;
	int freq;
	Cnt(int num, int freq)
	{
		this->num = num;
		this->freq = freq;
	}
};
class Cmp
{
public:
	bool operator()(Cnt &a, Cnt &b) { return a.freq > b.freq; }
};
int main()
{
	int n = 0;
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> input[i];
	}
	int k;
	cin >> k;
	unordered_map<int, int> freq;
	for (int i = 0; i < n; ++i)
	{
		freq[input[i]] += 1;
	}
	vector<Cnt> cntList;
	for (auto x = freq.begin(); x != freq.end(); ++x)
	{
		Cnt c((*x).first, (*x).second);
		cntList.push_back(c);
	}
	sort(cntList.begin(), cntList.end(), Cmp());
	vector<int> answer;
	for (int i = 0; i < k; ++i)
	{
		answer.push_back(cntList[i].num);
	}
	for (int x : answer)
	{
		cout << x << " ";
	}
	return 0;
}
