#pragma once

#include <cstdlib>
#include <vector>

namespace algo { //	utile pour éviter les conflits de nom,
				 //	il y a de fortes probabilités qu'il existe déjà une fonction algo quelque part
				 //	donc en utilisant un namespace custom, on s'épargne des soucis

#pragma region Quick sorting algorithm
	#pragma region Swap

	template <typename T>
	void swap(T* a, T* b)
	{
		int temp;
		temp = *a;
		*a = *b;
		*b = temp;
	}

	template<>
	void swap<Character>(Character* a, Character* b)
	{
		Character temp;
		temp = *a;
		*a = *b;
		*b = temp;
	}

	#pragma endregion Swap

	#pragma region Partition
	//// Partitioning the array on the basis of values at high as pivot value.
	//int Partition(std::vector<int>& v, int low, int high)
	//{
	//	int pivot, index, i;
	//	index = low;
	//	pivot = high;

	//	// Getting index of the pivot.
	//	for (i = low; i < high; i++)
	//	{
	//		if (v[i] < v[pivot])
	//		{
	//			swap(&v[i], &v[index]);
	//			index++;
	//		}
	//	}
	//	// Swapping value at high and at the index obtained.
	//	swap(&v[pivot], &v[index]);

	//	return index;
	//}

	template <typename T>
	int Partition(std::vector<T>& v, int low, int high)
	{
		int pivot, index, i;
		index = low;
		pivot = high;

		// Getting index of the pivot.
		for (i = low; i < high; i++)
		{
			if (v[i] < v[pivot])
			{
				swap(&v[i], &v[index]);
				index++;
			}
		}
		// Swapping value at high and at the index obtained.
		swap(&v[pivot], &v[index]);

		return index;
	}

	template<>
	int Partition<Character>(std::vector<Character>& c, int low, int high)
	{
		int pivot, index, i;
		index = low;
		pivot = high;

		// Getting index of the pivot.
		for (i = low; i < high; i++)
		{
			if (c[i].GetInitiative() < c[pivot].GetInitiative())
			{
				swap(&c[i], &c[index]);
				index++;
			}
		}
		// Swapping value at high and at the index obtained.
		swap(&c[pivot], &c[index]);

		return index;
	}
	#pragma endregion Partition

	#pragma region RandomPivotPartition
	//// Random selection of pivot.
	//int RandomPivotPartition(std::vector<int>& v, int low, int high)
	//{
	//	int pvt, n, temp;
	//	n = rand();
	//	// Randomizing the pivot value in the given subpart of array.
	//	pvt = low + n % (high - low + 1);

	//	// Swapping pivot value from high, so pivot value will be taken as a pivot while partitioning.
	//	swap(&v[high], &v[pvt]);

	//	return Partition(v, low, high);
	//}

	template <typename T>
	int RandomPivotPartition(std::vector<T>& v, int low, int high)
	{
		int pvt, n, temp;
		n = rand();
		// Randomizing the pivot value in the given subpart of array.
		pvt = low + n % (high - low + 1);

		// Swapping pivot value from high, so pivot value will be taken as a pivot while partitioning.
		swap(&v[high], &v[pvt]);

		return Partition(v, low, high);
	}

	template <>
	int RandomPivotPartition<Character>(std::vector<Character>& c, int low, int high)
	{
		int pivot, n, temp;
		n = rand();
		// Randomizing the pivot value in the given subpart of array.
		pivot = low + n % (high - low + 1);

		// Swapping pivot value from high, so pivot value will be taken as a pivot while partitioning.
		swap(&c[high], &c[pivot]);

		return Partition(c, low, high);
	}
	#pragma endregion RandomPivotPartition

	#pragma region Quicksort
	//int QuickSort(std::vector<int>& v, int low, int high)
	//{
	//	int pindex;
	//	if (low < high)
	//	{
	//		// Partitioning array using randomized pivot.
	//		pindex = RandomPivotPartition(v, low, high);
	//		// Recursively implementing QuickSort.
	//		QuickSort(v, low, pindex - 1);
	//		QuickSort(v, pindex + 1, high);
	//	}
	//	return 0;
	//}

	template <typename T>
	int QuickSort(std::vector<T>& v, int low, int high)
	{
		int pindex;
		if (low < high)
		{
			// Partitioning array using randomized pivot.
			pindex = RandomPivotPartition(v, low, high);
			// Recursively implementing QuickSort.
			QuickSort(v, low, pindex - 1);
			QuickSort(v, pindex + 1, high);
		}
		return 0;
	}

	template <>
	int QuickSort<Character>(std::vector<Character>& c, int low, int high)
	{
		int pindex;
		if (low < high)
		{
			// Partitioning array using randomized pivot.
			pindex = RandomPivotPartition(c, low, high);
			// Recursively implementing QuickSort.
			QuickSort(c, low, pindex - 1);
			QuickSort(c, pindex + 1, high);
		}
		return 0;
	}
	#pragma endregion Quicksort

	//	Algo to use if you want to cin the values
	int SortingValuesToEnter() {
		int n, i, temp;

		std::cout << "\nEnter the number of data elements to be sorted: ";
		std::cin >> n;

		std::vector<int> vect;
		for (i = 0; i < n; i++)
		{
			std::cout << "Enter element " << i + 1 << ": ";
			std::cin >> temp; 
			vect.push_back(temp);
		}

		QuickSort(vect, 0, n - 1);

		// Printing the sorted data.
		std::cout << "\nSorted Data ";
		for (i = 0; i < n; i++)
			std::cout << "->" << vect[i];

		return 0;
	}

	#pragma region Sorting Algorithm Up
	void SortingAlgorithmUp(std::vector<int> vect) {
		int vSize = vect.size();

		QuickSort(vect, 0, vSize - 1);

		//std::cout << "\nSorted Data: ";
		//for (int i = 0; i < vSize; i++) {
		//	std::cout << " -> " << vect[i] << " | ";
		//}
	}
	#pragma endregion Sorting Algorithm Up

	#pragma region Sorting Algorithm Down
	//std::vector<int> SortingAlgorithmDown(std::vector<int> vect) {
	//	int vSize = vect.size();

	//	QuickSort(vect, 0, vSize - 1);

	//	std::cout << "\nSorted Data: ";
	//	for (int i = vSize - 1; i >= 0; i--) {
	//		std::cout << " -> " << vect[i];
	//	}

	//	return vect;
	//}

	template <typename T>
	std::vector<T> SortingAlgorithmDown(std::vector<T> vect) {
		int vSize = vect.size();

		QuickSort(vect, 0, vSize - 1);

		std::cout << "\nSorted Data: ";
		for (int i = vSize - 1; i >= 0; i--) {
			std::cout << " -> " << vect[i];
		}

		return vect;
	}

	template<>
	std::vector<Character> SortingAlgorithmDown(std::vector<Character> vect) {
		int vSize = vect.size();

		QuickSort(vect, 0, vSize - 1);

		//std::cout << "\n" << "-// " << "Sorted Data: ";
		//for (int i = vSize - 1; i >= 0; i--) {
		//	std::cout << " -> " << vect[i].GetName() << " : " << vect[i].GetInitiative();
		//}

		return vect;
	}
	#pragma endregion Sorting Algorithm Down

#pragma endregion
}
