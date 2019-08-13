#pragma once
#include "Vector.h"


namespace jlm
{
	template<typename T>
	class Sorter
	{
	public:
		static void qSort(Vector<T> &v)
		{
			qSort(v, 0, v.size() - 1);
		}

	private:
		static int partition(Vector<T> &v, const T &pivot, int left, int right)
		{
			while (left <= right)
			{
				while (v[left] < pivot)
					left++;

				while (v[right] > pivot)
					right--;

				if (left <= right)
				{
					swap(v, left, right);
					left++;
					right--;
				}
			}//end while

			return left;
		}

		static void qSort(Vector<T> &v, int left, int right)
		{
			if (left >= right)
				return;

			int index = 0;
			T pivot = v[(left + right) / 2];
			index = partition(v, pivot, left, right);
			qSort(v, left, index - 1);
			qSort(v, index, right);
		}

		static void swap(Vector<T> &v, int left, int right)
		{
			T temp = v[left];
			v[left] = v[right];
			v[right] = temp;
		}
	};


}