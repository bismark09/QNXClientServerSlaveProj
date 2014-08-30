
#include <ParseConfigFile.hpp>


/*-----------------------------------------------------------------------*/
int ParseConfigFile(std::string pathToConfig, ServerConfigs *serverConfigs){
	if(pathToConfig.length()==0){
		pathToConfig=std::string(CONFIG_FILE_PATH);
	}
	std::cout<<"Path to file: "<<pathToConfig.c_str()<<std::endl;
	FILE *filePointer = NULL;
	filePointer = fopen((pathToConfig.c_str()), "r");

	if (filePointer == NULL) {
		perror("[ERROR]: Can not open file");
		return -1;
	}


	int scanned=0;
	do{
		scanned=0;

		scanned=scanned+fscanf(filePointer, "QUANTUM_NANOSEC: %llu\n\t", &(serverConfigs->quantumNanosec));
		scanned=scanned+fscanf(filePointer, "TIMEOUT_NANOSEC: %llu\n\t", &(serverConfigs->timeoutNanosec));

		scanned=scanned+fscanf(filePointer, "TIMER_EXCEEDED_PERIOD: %llu\n\t", &(serverConfigs->timerExceededPeriod));

		scanned=scanned+fscanf(filePointer, "NUMBER_OF_SLAVES: %i\n\t", &(serverConfigs->numberOfSlaves));
		scanned=scanned+fscanf(filePointer, "MAX_TASK_QUEUE_SIZE: %i\n\t",  &(serverConfigs->maxTaskQueueSize));
		scanned=scanned+fscanf(filePointer, "SERVER_INFO_FILE_NAME: %s\n\t",  serverConfigs->severInfoFileName);
	}
	while(scanned>0);
	fclose(filePointer);
	return 0;
}
/*-----------------------------------------------------------------------*/
