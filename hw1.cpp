#include <iostream>

void printmass(int *mass, int n)
{
	for (int i = 0; i < n; ++i)
	{
		std::cout << mass[i] << " ";
	}
	std::cout << std::endl;
}

void sorttwoarray(int *&mass1, int &n1, int *&mass2, int &n2)
{
	int *addarray = (n1 > n2) ? new int[n1] : new int[n2];

	int counter1 = 0;
	int counter2 = 0;

	bool cond = true;

	for (int i = 0; i < n1; ++i)
	{
		for (int j = 0; j < n2; ++j)
		{
			if (mass1[i] == mass2[j])
			{
				cond = true;

				for (int g = 0; g < counter1; ++g)
					if (mass1[i] == addarray[g])
						cond = false;

				if (cond)
				{
					addarray[counter1] = mass1[i];
					++counter1;
					break;
				}
			}
		}
	}

	int *outputarray1 = new int[counter1];
	for (int i = 0; i < counter1; ++i)
	{
		outputarray1[i] = addarray[i];
	}

	for (int i = 0; i < n1; ++i)
	{
		cond = true;

		for (int j = 0; j < counter1; ++j)
			if (mass1[i] == outputarray1[j])
				cond = false;

		for (int g = 0; g < counter2; ++g)
			if (mass1[i] == addarray[g])
				cond = false;

		if (cond)
		{
			addarray[counter2] = mass1[i];
			++counter2;
		}
	}

	for (int i = 0; i < n1; ++i)
	{
		cond = true;
		for (int j = 0; j < counter1; ++j)
		{
			if (mass2[i] == outputarray1[j])
				cond = false;
		}

		for (int g = 0; g < counter2; ++g)
		{
			if (mass2[i] == addarray[g])
				cond = false;

		}

		if (cond)
		{
			addarray[counter2] = mass2[i];
			++counter2;
		}
	}

	int *outputarray2 = new int[counter2];
	for (int i = 0; i < counter2; ++i)
	{
		outputarray2[i] = addarray[i];
	}


	delete[]addarray;
	delete[]mass1;
	delete[]mass2;

	mass1 = outputarray1;
	mass2 = outputarray2;
	n1 = counter1;
	n2 = counter2;
}

int main()
{
	int n1 = 7;
	int n2 = 7;

	int *array1 = new int[n1] {2, 3, 5, 6, 2, 1, 6};
	int *array2 = new int[n2] {9, 0, 1, 2, 5, 8, 3};

	printmass(array1, n1);
	printmass(array2, n2);

	sorttwoarray(array1, n1, array2, n2);

	printmass(array1, n1);
	printmass(array2, n2);

	delete[]array1;
	delete[]array2;

	return 0;
}
