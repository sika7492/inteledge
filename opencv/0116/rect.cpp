#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {

	Rect rc1;					// rc1 = [0 x 0 from (0, 0)]
	Rect rc2(10, 10, 60, 40);	// rc2 = [60 x 40 from (10, 10)]

	Rect rc3 = rc1 + Size(50, 40);	// rc3 = [50 x 40 from (0, 0)]
	Rect rc4 = rc2 + Point(10, 10);	// rc4 = [60 x 40 from (20, 20)]

	Rect rc5 = rc3 & rc4;		// rc5 = [30 x 20 from (10, 10)]
	Rect rc6 = rc3 | rc4;		// rc6 = [80 x 60 from (0, 0)]
	int area1 = rc1.area();
	int area2 = rc2.area();
	int area3 = rc3.area();
	int area4 = rc4.area();
	int area5 = rc5.area();
	int area6 = rc6.area();


	cout << "rc1: " << rc1 <<"³ÐÀÌ´Â "<<area1<< endl;
	cout << "rc2: " << rc2 << "³ÐÀÌ´Â " << area2<< endl;
	cout << "rc3: " << rc3 << "³ÐÀÌ´Â " << area3 << endl;
	cout << "rc4: " << rc4 << "³ÐÀÌ´Â " << area4 << endl;
	cout << "rc5: " << rc5 << "³ÐÀÌ´Â " << area5<< endl;
	cout << "rc6: " << rc6 << "³ÐÀÌ´Â " << area6 << endl;
}