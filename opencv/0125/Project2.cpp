#include "opencv2/opencv.hpp"
#include <iostream>


using namespace std;
using namespace cv;
using namespace cv::dnn;	

//다운 받은 딥러닝 학습모델(모델파일,구성파일)을 불러온다;
const String model = "res10_300x300_ssd_iter_140000_fp16.caffemodel";
const String config = "deploy.prototxt";
//const String model =  "opencv_face_detector_uint8.pb";			//발표당시 빠짐 .pb		
//const String config ="opencv_face_detector.pbtxt";				//



int main() {
	
	VideoCapture cap(1, CAP_DSHOW);				// camera id=1, CAP_DSHOW값으로 원본 영상을 입력받는다.
	cap.set(CAP_PROP_FRAME_WIDTH, 1280);		//입력받은 영상의 해상도는 1280*720
	cap.set(CAP_PROP_FRAME_HEIGHT, 720);		

	if (!cap.isOpened()) {						//만약 카메라가 연결되어있지 않거나 camera_id가 잘못되었을 경우 예외처리
		cerr << "error: camera open failed" << endl;
		return -1;
	}//end of if


	Net net = readNet(model, config);				//모델파일과 구성파일을 이용 Net 객체 net에 생성
	
	if (net.empty())								//net 객체 생성에 실패하면 예외처리
	{
		cerr << "error: Net open failed" << endl;
	}//end of if
	Mat frame,dst;
	Mat bin;
	Mat dst_erode,dst_gray;
	while (true)
	{
		cap >> frame;							//입력받은 영상을 frame에 저장
		if (frame.empty())						//frame이 비어있다면 예외처리
			break;



		//frmae 영상을 이용하여 네트워크 입력 블롭을 설정하고 네트워크 실행결과를 rex 행령에 저장한다
		Mat blob = blobFromImage(frame, 1, Size(300, 300), Scalar(104, 117, 123));
		net.setInput(blob);
		Mat res = net.forward();
		
		//detect 행렬은 N*7크기의 2차원 행렬이고 0번과 1번열에 각각 0과1이 저장됨
		//2번 열에 confidence(얼굴 신뢰도)가 저장됨
		//3번에서 6번열은 좌측상단 꼭지점 좌표(x1,y1) 우측하단 꼭지점 좌표 (x2,y2)가 순서대로 저정됨
		Mat detect(res.size[2], res.size[3], CV_32FC1, res.ptr<float>());

		for (int i = 0; i < detect.rows; i++)
		{
			float confidence = detect.at<float>(i, 2);
			if (confidence < 0.5)										//신뢰도가 0.5이하라면 무시한다.
				break;

			int x1 = cvRound(detect.at<float>(i, 3) * frame.cols);		//얼굴 검출 영역의 (x1,y1),(x2,y2)를 계산한다.
			int y1 = cvRound(detect.at<float>(i, 4) * frame.rows);		
			int x2 = cvRound(detect.at<float>(i, 5) * frame.cols);
			int y2 = cvRound(detect.at<float>(i, 6) * frame.rows);

			//얼굴 검출 영역에 녹색 사각형을 출력한다
			rectangle(frame, Rect(Point(x1, y1), Point(x2, y2)), Scalar(0, 255, 0));

			//얼굴 검출 영역의 바로위에 얼굴 신뢰도값을 출력한다.
			String label = format("Face: %4.3f", confidence);
			putText(frame, label, Point(x1, y1 - 1), FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0, 255, 0));
			
			//만약 얼굴이 검출 되면 감지된 얼굴화면을 dst에 저장
			//dst를 그레이스케일로 변환 dst_gray에 저장
			//if (confidence >= 0.5) {
				dst = frame(Rect(Point(x1, y1), Point(x2, y2))).clone();
				
			//}



		}//end of for
		
		//dst _gray가 비어있지 않다면 모폴로지 열기연산을 하고 erode에 출력한다.
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
		

		if (waitKey(1) == 27)					//esc를 입력하면 종료한다.
			break;
	}//end of while

	return 0;

}//end of main


