#include<iostream>
using namespace std;

class SampleClass {
	private:
		int var;
	public:
		SampleClass(int val) {
			var = val;
		}
			
		int getVarValue(void) {
			return var;
		}
};

int main(void) {
	SampleClass obj(10);
	cout<<"Value is = "<<obj.getVarValue()<<endl;
	return(0);
}
