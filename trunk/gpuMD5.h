#include <string>
#include <vector>

#include "cuda.h"

#include "constants.h"

void initialiseConstants(UINT*);
bool doHash(std::vector<std::string>&);
bool hashByBatch(std::vector<std::string>&, int);
