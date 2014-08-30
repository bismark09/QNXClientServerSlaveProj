#include <cstdlib>
#include <iostream>
#include <unistd.h>

#include <sys/neutrino.h>
#include <sys/netmgr.h>

#include <stdio.h>  //For cout cerr and so on
#include <errno.h>	//For errno
#include <string.h>  //For strerror

#include <iomanip>

#include "../ServerPrj/includes/CommonStructs.hpp"


int main(int argc, char *argv[]) {
	sleep(2); //Let server start and be prepared!
	FILE *fp;
	fp=fopen("serv.serv", "r");

	pid_t servPID;
	int servCHID;
	char dummy[100];
	fscanf(fp,"%s", &dummy);
	fscanf(fp,"%s", &dummy);
	fscanf(fp,"%s", &dummy);
	fscanf(fp,"%d", &servPID);
	fscanf(fp,"%s", &dummy);
	fscanf(fp,"%d", &servCHID);

	std::cout<<servPID<<servCHID<<std::endl;


	int coid=-1;
	if ((coid = ConnectAttach(0, servPID, servCHID,	NULL, NULL))==-1) {
		std::cerr << "[ERROR]: " << errno << "can not attach from client to server channel because of:"<< strerror(errno);
		return NULL;
	}

	TaskCommonStruct taskStruct;
	taskStruct.H=1;
	taskStruct.r=100;
	taskStruct.startZ=0;
	taskStruct.kvadrantX=+1;
	taskStruct.kvadrantY=-1;
	taskStruct.startX=0;
	taskStruct.startY=100;
	taskStruct.numberOfNeededPoints=5;
	//taskStruct.rcvid=-1;


	double buff[100];

	TaskResultCommonStruct taskResultStruct;
	taskResultStruct.taskResultPairOfDots=new TaskResultPairOfDots[taskStruct.numberOfNeededPoints];
	iov_t iovSend;
	iov_t iovReceive[2];

	SETIOV(&iovSend, &(taskStruct), sizeof(TaskCommonStruct));

	SETIOV(iovReceive+0, &(taskResultStruct.taskResultCommonStructHeader), sizeof(TaskResultCommonStructHeader));
	SETIOV(iovReceive+1, taskResultStruct.taskResultPairOfDots, taskStruct.numberOfNeededPoints*sizeof(TaskResultPairOfDots));

	MsgSendv(coid,&iovSend, 1, iovReceive, 2);



	const char separator    = ' ';
	const int numWidth      = 10;


	for(int i=0; i<taskStruct.numberOfNeededPoints; i++){
		std::cout<<"X: "<<taskResultStruct.taskResultPairOfDots[i].xResult<<std::endl;
		std::cout<<"Y: "<<taskResultStruct.taskResultPairOfDots[i].yResult<<std::endl;
		std::cout<<"Z: "<<taskResultStruct.taskResultPairOfDots[i].zResult<<std::endl;

	}

	delete[] taskResultStruct.taskResultPairOfDots;



	return EXIT_SUCCESS;
}
