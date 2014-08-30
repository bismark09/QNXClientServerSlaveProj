#ifndef INTERPOLATORIMPL_H_
#define INTERPOLATORIMPL_H_
#include <vector>


#include <math.h>//For  sqrt

class InterpolatorImpl {
public:
	InterpolatorImpl();
	~InterpolatorImpl();
	InterpolatorImpl(double H, double r, double startZ,int kvadrantX, int kvadrantY, double startX, double startY);
	void setAllNewParametrs(double H, double r, double startZ,int kvadrantX, int kvadrantY, double startX, double startY);
	void getNextPoint(double *outX, double *outY, double *outZ);

private:
	int H;
	double r;
	double Z;
	int kvadrantX;
	int kvadrantY;
	double X;
	double Y;
	double U;

};

#endif
