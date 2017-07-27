#include <string>
#include <vector>
#include <iostream>
#include <algorithm> 
#include <functional>
using namespace std;

bool cmp(const vector<int>& v1, const vector<int>& v2)
{
	if (v1[0] < v2[0])
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main(void)
{
	vector<string> lines = { "2016-09-15 20:59:57.421 0.351s", "2016-09-15 20:59:58.233 1.181s", "2016-09-15 20:59:58.299 0.8s", "2016-09-15 20:59:58.688 1.041s", "2016-09-15 20:59:59.591 1.412s", "2016-09-15 21:00:00.464 1.466s", "2016-09-15 21:00:00.741 1.581s", "2016-09-15 21:00:00.748 2.31s", "2016-09-15 21:00:00.966 0.381s", "2016-09-15 21:00:02.066 2.62s" };
	int answer = 0;
	int nCounter = 0;
	int nLine_size = lines.size();
	vector<vector<int> > InOut;

	InOut.resize(nLine_size * 2);

	for (int i = 0; i<nLine_size; i++)
	{
		int nHour = 0;
		int nMin = 0;
		int nSec = 0;
		int nMil = 0;
		int UseTime = 0;
		int nTime = 0;
		nHour = (lines[i][11] - '0') * 10 + lines[i][12] - '0';
		nMin = (lines[i][14] - '0') * 10 + lines[i][15] - '0';
		nSec = (lines[i][17] - '0') * 10 + lines[i][18] - '0';
		nMil = (lines[i][20] - '0') * 100 + (lines[i][21] - '0') * 10 + (lines[i][22] - '0');
		nTime = nHour * 60 * 60 * 1000 + nMin * 60 * 1000 + nSec * 1000 + nMil;

		if (lines[i][24] != 's')
		{
			UseTime += (lines[i][24] - '0') * 1000;
			if (lines[i][25] != 's')
			{
				if(lines[i][25] == '.')
				{
					if (lines[i][26] != 's')
					{
						UseTime += (lines[i][26] - '0') * 100;
						if (lines[i][27] != 's')
						{
							UseTime += (lines[i][27] - '0') * 10;
							if (lines[i][28] != 's')
							{
								UseTime += (lines[i][28] - '0');
							}
						}
					}
				}
			}
		}
		
		InOut[i * 2].resize(2, 0);
		InOut[i * 2+1].resize(2, 0);
		InOut[i * 2][0] = nTime - UseTime + 1 - 500;
		InOut[i * 2][1] = 0;
		InOut[i * 2 + 1][0] = nTime + 500;
		InOut[i * 2 + 1][1] = 1;
	}
	sort(InOut.begin(), InOut.end(), cmp);


	for (int i = 0; i<nLine_size * 2; i++)
	{
		if (InOut[i][1] == 0)
		{
			nCounter++;
		}
		if (InOut[i][1] == 1)
		{
			nCounter--;
		}
		if (answer < nCounter)
		{
			answer = nCounter;
		}
	}

	return answer;
}