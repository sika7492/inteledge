#include "opencv2/opencv.hpp"
#include <iostream>


using namespace std;
using namespace cv;
using namespace cv::dnn;	

//�ٿ� ���� ������ �н���(������,��������)�� �ҷ��´�;
const String model = "res10_300x300_ssd_iter_140000_fp16.caffemodel";
const String config = "deploy.prototxt";
//const String model =  "opencv_face_detector_uint8.pb";			//��ǥ��� ���� .pb		
//const String config ="opencv_face_detector.pbtxt";				//



int main() {
	
	VideoCapture cap(1, CAP_DSHOW);				// camera id=1, CAP_DSHOW������ ���� ������ �Է¹޴´�.
	cap.set(CAP_PROP_FRAME_WIDTH, 1280);		//�Է¹��� ������ �ػ󵵴� 1280*720
	cap.set(CAP_PROP_FRAME_HEIGHT, 720);		

	if (!cap.isOpened()) {						//���� ī�޶� ����Ǿ����� �ʰų� camera_id�� �߸��Ǿ��� ��� ����ó��
		cerr << "error: camera open failed" << endl;
		return -1;
	}//end of if


	Net net = readNet(model, config);				//�����ϰ� ���������� �̿� Net ��ü net�� ����
	
	if (net.empty())								//net ��ü ������ �����ϸ� ����ó��
	{
		cerr << "error: Net open failed" << endl;
	}//end of if
	Mat frame,dst;
	Mat bin;
	Mat dst_erode,dst_gray;
	while (true)
	{
		cap >> frame;							//�Է¹��� ������ frame�� ����
		if (frame.empty())						//frame�� ����ִٸ� ����ó��
			break;



		//frmae ������ �̿��Ͽ� ��Ʈ��ũ �Է� ����� �����ϰ� ��Ʈ��ũ �������� rex ��ɿ� �����Ѵ�
		Mat blob = blobFromImage(frame, 1, Size(300, 300), Scalar(104, 117, 123));
		net.setInput(blob);
		Mat res = net.forward();
		
		//detect ����� N*7ũ���� 2���� ����̰� 0���� 1������ ���� 0��1�� �����
		//2�� ���� confidence(�� �ŷڵ�)�� �����
		//3������ 6������ ������� ������ ��ǥ(x1,y1) �����ϴ� ������ ��ǥ (x2,y2)�� ������� ������
		Mat detect(res.size[2], res.size[3], CV_32FC1, res.ptr<float>());

		for (int i = 0; i < detect.rows; i++)
		{
			float confidence = detect.at<float>(i, 2);
			if (confidence < 0.5)										//�ŷڵ��� 0.5���϶�� �����Ѵ�.
				break;

			int x1 = cvRound(detect.at<float>(i, 3) * frame.cols);		//�� ���� ������ (x1,y1),(x2,y2)�� ����Ѵ�.
			int y1 = cvRound(detect.at<float>(i, 4) * frame.rows);		
			int x2 = cvRound(detect.at<float>(i, 5) * frame.cols);
			int y2 = cvRound(detect.at<float>(i, 6) * frame.rows);

			//�� ���� ������ ��� �簢���� ����Ѵ�
			rectangle(frame, Rect(Point(x1, y1), Point(x2, y2)), Scalar(0, 255, 0));

			//�� ���� ������ �ٷ����� �� �ŷڵ����� ����Ѵ�.
			String label = format("Face: %4.3f", confidence);
			putText(frame, label, Point(x1, y1 - 1), FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0, 255, 0));
			
			//���� ���� ���� �Ǹ� ������ ��ȭ���� dst�� ����
			//dst�� �׷��̽����Ϸ� ��ȯ dst_gray�� ����
			//if (confidence >= 0.5) {
				dst = frame(Rect(Point(x1, y1), Point(x2, y2))).clone();
				
			//}



		}//end of for
		
		//dst _gray�� ������� �ʴٸ� �������� ���⿬���� �ϰ� erode�� ����Ѵ�.
		if(!dst.empty())
		{
			cvtColor(dst, dst_gray, COLOR_BGR2GRAY);
			threshold(dst_gray, bin, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);
			if (bin.empty())
				break;
			
			erode(bin, dst_erode, Mat());
			imshow("erode", dst_erode);
		}
		imshow("frame", frame);	
		

		if (waitKey(1) == 27)					//esc�� �Է��ϸ� �����Ѵ�.
			break;
	}//end of while

	return 0;

}//end of main


