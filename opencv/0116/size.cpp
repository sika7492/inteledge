#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;
int main() {
	Size sz1, sz2(10, 20);			// sz1 = [0 x 0], sz2 = [10 x 20]
	sz1.width = 5; sz1.height = 10;	// sz1 = [5 x 10]

	Size sz3 = sz1 + sz2;	// sz3 = [15 x 30]
	Size sz4 = sz1 * 2;		// sz4 = [10 x 20]
	int area1 = sz1.area();
	int area2 = sz2.area();
	int area3 = sz3.area();
	int area4 = sz4.area();

	cout << "sz1: " << sz1 << "ÀÇ ³ÐÀÌ´Â"<<area1<<endl;
	cout << "sz2: " << sz2 << "ÀÇ ³ÐÀÌ´Â" << area2<< endl;
	cout << "sz3: " << sz3 << "ÀÇ ³ÐÀÌ´Â" << area3<< endl;
	cout << "sz4: " << sz4 << "ÀÇ ³ÐÀÌ´Â" << area4<< endl;


}