#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>

bool sortTest()
{
	std::vector<int> vector;
	vector.push_back(3);
	vector.push_back(1);
	vector.push_back(2);

 // need to sort the vector
 std::sort(vector.begin(), vector.end());

	return (1 == vector.at(0) && 2 == vector.at(1) && 3 == vector.at(2));
}

bool reverse (int i,int j)
{
	return (i>j);
}

bool reverseSortTest()
{
	std::vector<int> vector;
	vector.push_back(3);
	vector.push_back(1);
	vector.push_back(2);

	// need to sort the vector in descending order
	std::sort(vector.begin(), vector.end(), reverse);

	return (3 == vector.at(0) && 2 == vector.at(1) && 1 == vector.at(2));
}

bool bogoSortTest()
{
	std::vector<int> vector;
	vector.push_back(3);
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(4);

	int timeout = 0;
	while(!std::is_sorted(vector.begin(), vector.end()) && timeout++ < 1000000)
	{
		// shuffle the vector in a random order. If we keep trying we are bound
		// to get it sorted right???
		std::random_shuffle(vector.begin(), vector.end());
	}

	//QVERIFY(timeout < 1000000);
	return  (1 == vector.at(0) && 2 == vector.at(1) && 3 == vector.at(2) && 4 == vector.at(3));
}

bool findTest()
{
	std::vector<int> vector;
	vector.push_back(3);
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(4);

	// find1 looks to see if there is a 2 in the list
	// and find2 should check if there is a 5 in the list
	std::vector<int>::const_iterator find1 = std::find(vector.begin(), vector.end(), 2);
	std::vector<int>::const_iterator find2 = std::find(vector.begin(), vector.end(), 5 );

	return (vector.end() != find1 && 2 == *find1 && vector.end() == find2);
}

bool replaceTest()
{
	std::vector<int> vector;
	vector.push_back(1);
	vector.push_back(3);
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(2);
	vector.push_back(2);
	vector.push_back(4);

	// need to update find
	std::vector<int>::const_iterator find = std::find(vector.begin(), vector.end(), 2);
	while (vector.end() != find)
	{
		// repalce all 2s with 3s and then update find
		std::replace(vector.begin(), vector.end(), 2, 3);
		find = vector.end();
	}

	int numberOfThrees = std::count(vector.begin(), vector.end(), 3);

	return (6 == numberOfThrees && 9 == vector.size());
}

int main()
{
	int all = 0;
	if (sortTest()){all++;}
	else{std::cout<<"sortTest failed\n";}

	if(reverseSortTest()){all++;}
	else{std::cout<<"reverseSortTest failed\n";}

	if(bogoSortTest()){all++;}
	else{std::cout<<"bogoSortTest failed\n";}

	if(findTest()){all++;}
	else{std::cout<<"findTest failed\n";}

	if(replaceTest()){all++;}
	else{std::cout<<"replaceTest failed\n";}

	if(all == 5){std::cout<<"All Tests Passed! :)\n";}
}
