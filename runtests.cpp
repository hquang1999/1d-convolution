//group: Nigel Damian, Hieu Quang

#include <iostream>
#include <vector>

template<typename T>
std::vector<T> xcorr(const std::vector<T>& a, const std::vector<T>& b)
{
	// --- ADDS ZEROES ---
	std::vector<int> NewA(b.size() * 2 + a.size() - 2);
        size_t j = (b.size() - 1);
 
        for(size_t n = 0; a.size() != n; n++, j++)
        {
               NewA[j] = a[n];
        }
	
	// --- CROSS CORRELATION ---
	std::vector<int> results(a.size() + b.size() - 1);	
	auto z = NewA.size() - b.size() + 1; //end size
	
	for (size_t n = 0; n != z; n++)
	{
		int total = 0;
		size_t i = 0;
		size_t begin = n;
		
		while (i != b.size()) // goes through the multiplication
		{
			total += (NewA[begin] * b[i]);
			i++;
			begin++;
		}
		
		results[n] = total;
	}	
	
	return results;
}

template<typename T>
std::vector<T> conv(const std::vector<T>& a, const std::vector<T>& b)
{	
	// --- REVERSE ---
	std::vector<int> rev(b.size()); 
	int front = 0; //front index
	int back = b.size() - 1; //back index
	
	while(back > -1)
	{
		rev[front] = b[back];
		front++;
		back--;
	}
	
	// --- ADDS ZEROES ---
	std::vector<int> NewA(b.size() * 2 + a.size() - 2);
        size_t j = (b.size() - 1);
 
        for(size_t n = 0; a.size() != n; n++, j++)
        {
               NewA[j] = a[n];
        }
	
	// --- CONVULUTION ---
	std::vector<int> results(a.size() + b.size() - 1);	
	auto z = NewA.size() - b.size() + 1; //end size
	
	for (size_t n = 0; n != z; n++)
	{
		int total = 0;
		size_t i = 0;
		size_t begin = n;
		
		while (i != rev.size())
		{
			total += (NewA[begin] * rev[i]);
			i++;
			begin++;
		}
		
		results[n] = total;
	}	
	
	return results;
}

int main()
{
	std::vector<int> a = {1,2,3,4,5};
	std::vector<int> b = {1,2,3,4,5};
	
	std::cout << "Vector A:" << std::endl;
	for(auto n : a)
	{
		std::cout << n << " ";
	}
	
	std::cout << std::endl;
	
	std::cout << "Vector B:" << std::endl;
	for(auto n : b)
	{
		std::cout << n << " ";
	}
	
	std::cout << std::endl;
	std::cout << std::endl;

// --------------------------------------------------------

	std::cout << "[CONVOLUTION]" << std::endl;
	
	std::vector<int> resultConv = conv(a,b);

	for(auto n : resultConv)
	{
		std::cout << n << " ";
	}
	
	std::cout << std::endl;	

// --------------------------------------------------------
	
	std::cout << "[CROSS CORRELATION]" << std::endl;
	
	std::vector<int> resultCross = xcorr(a,b);

	for(auto n : resultCross)
	{
		std::cout << n << " ";
	}

	std::cout << std::endl;	
	
	return 0;
}


