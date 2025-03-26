#include <iostream>
#include <deque>
using namespace std;

char *find_comma(char *str)
{
	while (*str && *str != ',')
		str++;
	if (!*str)
		return NULL;
	return ++str;
}

void build_deq(char *str, deque<int> &deq)
{
	char *s = str + 1;
	int num;
	while(s)
	{
		if (*s >= '0' && *s <= '9')
		{
			num = atoi(s);
			deq.push_back(num);
		}
		s = find_comma(s);
	}
}

void print_deq(const std::deque<int>& deq, int flag)
{
	if (flag == 0)
		return;
	cout << '[';
	if (!deq.empty()) {
		if (flag > 0)
		{
			auto it = deq.begin();
			cout << *it;
			++it;
			for (; it != deq.end(); ++it)
				cout << ',' << *it;
		}
		else
		{
			auto it = deq.rbegin();
			cout << *it;
			++it;
			for (; it != deq.rend(); ++it)
				cout << ',' << *it;
		}
	}
	cout << "]\n";
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int t, n, flag = 1;
	string p, input;
	deque<int> deq;
	cin >> t;
	while (t--)
	{
		flag = 1;
		cin >> p >> n >> input;
		build_deq((char *)input.c_str(), deq);
		for (char c : p)
		{
			if (c == 'R')
				flag *= -1;
			else if (c == 'D')
			{
				if (deq.empty())
				{
					cout << "error\n";
					flag = 0;
					break;
				}
				if (flag > 0)
					deq.pop_front();
				else
					deq.pop_back();
			}
		}
		print_deq(deq, flag);
		deq.clear();
	}
}
