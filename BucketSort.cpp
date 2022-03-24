#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Entry
{
	int key;
	string value;
};

vector<Entry> bucketSort(vector<Entry> v)
{
	vector<vector<Entry>> buckets;
	
	for(int i = 0; i < v.size(); i++)
	{
		vector<Entry> e;
		buckets.push_back(e);
	}
	
	while(v.empty() == false)
	{
		int k = v.back().key;
		buckets[k].push_back(v.back());
		v.pop_back();
	}
	for(int i = 0; i<buckets.size(); i++)
	{
		for(int j = 0; j < buckets[i].size(); j++)
		{
			v.push_back(buckets[i][j]);
		}
	}
	return v;
}
int main()
{
	vector<Entry> en;
	Entry e;
	e.key = 4;
	e.value = "four";
	en.push_back(e);
	
	e.key = 1;
	e.value = "one";
	en.push_back(e);
	
	e.key = 3;
	e.value = "three";
	en.push_back(e);
	
	e.key = 2;
	e.value = "two";
	en.push_back(e);
	
	e.key = 0;
	e.value = "zero";
	en.push_back(e);	
	
	en = bucketSort(en);
	
	for(int i = 0; i < en.size(); i++)
	{
		cout << en[i].key << endl;
	}	
	return EXIT_SUCCESS;
}
