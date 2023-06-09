#include <iostream>
using namespace std;
#include <stack>

stack<char> stc;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int result = 0;
	int r = 1;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(' || s[i] == '[')
		{
			stc.push(s[i]);

			if (s[i] == '(')
				r *= 2;
			if (s[i] == '[')
				r *= 3;
		}
		else if (s[i] == ')')
		{
			if (stc.empty() || stc.top() != '(')
			{
				cout << 0;
				return 0;
			}

			stc.pop();
			if (s[i - 1] == '(')
				result += r;
			r /= 2;
		}
		else if (s[i] == ']')
		{
			if (stc.empty() || stc.top() != '[')
			{
				cout << 0;
				return 0;
			}

			stc.pop();

			if (s[i - 1] == '[')
				result += r;
			r /= 3;
		}
	}

	if (!stc.empty())
	{
		cout << 0;
		return;
	}

	cout << result;

	return 0;
}
