#include <iostream>
using namespace std;

int num1[] = { 0, 0, 0, 5, 0 };
int num2[] = { 0, 0, 0, 0, 0 };
int res[] = { 0, 0, 0, 5, 0 };

int main() {
	int res0, res1;
	for(int i = 0; i < 10; ++i) // num1[1]
		for(int j = 0; j < 10; ++j) // num2[1]
			for(int k = 0; k < 10; ++k) // num1[0]
				for(int l = 0; l < 10; ++l) { // num2[0] 
					
					res1 = i+j;
					res0 = res1/10 + k + l;
					res1 %= 10;
					
					if(res0 < 10) 
						for(int m = 0; m < 10; ++m)  // num1[2], res[2]
							for(int n = 0; n < 10; ++n)  // num2[4], res[4]
								cout << k << i << m << "50+"
									<< l << j << "00" << n 
									<< "\n------\n" << res0 << res1 << m << 5 << n << "\n\n";
					}
	
	return 0;
}
