
#pragma once

namespace jlm
{
	template <typename T>
	class SmartPointer;

	template <typename T>
	class Allocated
	{
	public:
		Allocated(const T&Value, bool DynamicallyAllocated)
			:value(Value),dynamicallyAllocated(DynamicallyAllocated),
			ownerCount(1)
		{
			
		}

		Allocated( bool DynamicallyAllocated)
			:dynamicallyAllocated(DynamicallyAllocated),ownerCount(1)
		{
		}

		~Allocated()
		{
		}

		void addOwner()
		{
			ownerCount++;
		}

		void removeOwner()
		{
			ownerCount--;
			if (ownerCount == 0 && dynamicallyAllocated)
			{
				delete this;
			}
		}

		friend class SmartPointer<T>;
	private:
		T value;
		int ownerCount;
		bool dynamicallyAllocated;
	};


	template < typename T >
	class SmartPointer
	{
	public:
		SmartPointer()
		{
			memoryAllocated = false;
			pointer = nullptr;
		}
		SmartPointer(const T &copied)
		{
			memoryAllocated = true;
			pointer = new Allocated<T>(copied, true);
		}

		SmartPointer(const SmartPointer<T> &copied)
		{
			memoryAllocated = copied.memoryAllocated;
			if (memoryAllocated)
			{
				this->pointer = copied.pointer;
				this->pointer->addOwner();
			}
		}

		~SmartPointer()
		{
			if (memoryAllocated)
				this->pointer->removeOwner();
		}

		SmartPointer<T> &operator=(const SmartPointer<T> &copied)
		{
			if (memoryAllocated)
			{
				this->pointer->removeOwner();
			}
			this->memoryAllocated = copied.memoryAllocated;
			this->pointer = copied.pointer;
			if (copied.memoryAllocated)
			{
				this->pointer->addOwner();
			}

			return *this;
		}

		T & operator*()
		{
			return pointer->value;
		}

		const T & operator*() const
		{
			return pointer->value;
		}

		T &operator->()
		{
			return pointer->value;
		}

		const T & operator->() const
		{
			return pointer->value;
		}
	private:
		Allocated<T> * pointer;
		bool memoryAllocated;

	};




}