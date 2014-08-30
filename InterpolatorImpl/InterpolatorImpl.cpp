#include "InterpolatorImpl.h"


InterpolatorImpl::InterpolatorImpl(){
};

InterpolatorImpl::InterpolatorImpl(double H, double r, double startZ,int kvadrantX, int kvadrantY, double startX, double startY) {
	this->H=H;
	this->r=r;
	U=0;

	this->kvadrantX=kvadrantX;
	this->kvadrantY=kvadrantY;

	X=startX;
	Y=startY;
	Z=startZ;
}


void InterpolatorImpl::setAllNewParametrs(double H, double r, double startZ,int kvadrantX, int kvadrantY, double startX, double startY) {
	this->H=H;
	this->r=r;
	U=0;

	this->kvadrantX=kvadrantX;
	this->kvadrantY=kvadrantY;

	X=startX;
	Y=startY;
	Z=startZ;
}



void InterpolatorImpl::getNextPoint(double *outX, double *outY, double *outZ) {

	double deltaX=(kvadrantX*H*Y)/r;
	double deltaY=(kvadrantY*H*X)/r;
	U=U+2*(X*deltaX+Y*deltaY)+deltaX*deltaX+deltaY*deltaY;
	X=X+deltaX;
	Y=Y+deltaY;
	Z=Z+H;

	double psiX=0;
	double psiY=0;

	if(abs(U)>H){
		double psiR=-U/r;
		psiX=(psiR*X)/r;
		psiY=(psiR*Y)/r;
		U=U+2*(X*psiX+Y*psiY)+psiX*psiX+psiY*psiY;
		X=X+psiX;
		Y=Y+psiY;
	}
	*outX=X;
	*outY=Y;
	*outZ=Z;
}




InterpolatorImpl::~InterpolatorImpl() {
}




