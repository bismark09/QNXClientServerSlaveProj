

#ifndef PARSECONFIGFILE_HPP_
#define PARSECONFIGFILE_HPP_

#include <stdio.h>
#include <string>
#include <errno.h>
#include <iostream>
#include "Structs.hpp"

#define CONFIG_FILE_PATH "Server.cfg"



int ParseConfigFile(std::string pathToConfig, ServerConfigs *serverConfigs);



#endif /* PARSECONFIGFILE_HPP_ */
