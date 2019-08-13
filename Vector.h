#pragma once


namespace jlm
{
	template <typename T>
	class Vector
	{
	public:
		Vector()
			:a(nullptr), _size(0), allocated(false)
		{}
		Vector(const size_t &Size)
			:a(new T[Size]), _size(Size), allocated(true)
		{}
		~Vector()
		{
			if (allocated)
				delete[] a;
		}
		const size_t &size()
		{
			return _size;
		}

		void resize(size_t newSize)
		{
			if (newSize == 0)
			{
				if (allocated)
				{
					_size = 0;
					delete[] a;
					allocated = false;
				}

				return;
			}

			if (allocated)
			{
				//copying current array
				T * temp = new T[newSize];
				size_t smallSize = _size < newSize ? _size : newSize;
				for (unsigned int i = 0; i < smallSize; i++)
				{
					temp[i] = a[i];
				}

				delete[] a;

				a = temp;

				_size = newSize;
			}
			else
			{
				a = new T[newSize];
				_size = newSize;
				allocated = true;
			}
		}

		T &operator[](const size_t &index)
		{

			return a[index];
		}

		const T &operator[](const size_t &index) const
		{

			return a[index];
		}
	private:
		T * a;//the array
		size_t _size;
		bool allocated;



	};




}

