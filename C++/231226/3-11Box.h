#pragma once
class Box
{
public:
	Box(int w, int h);
	void seFill(char f);
	void setSize(int w, int h);
	void draw();
	

private:
	int width, height;
	char fill;
};
