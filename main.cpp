#include <iostream>
#include <string>
#include "./src/utils/Utils.h"
#include "./include/mars-rover/MarsMission.h"

using namespace std;

int main (int argc, char *argv[]) {
  if (argc < 2){
    cout << "Usage example: marsrover \"5 5\\n1 2 N\\nLMLMLMLMM\\n3 3 E\\nMMRMMRMRRM\"" << endl;
    return 0;
  }

  cout << "Hello, Mars!" << endl << endl;
  string missionInput = Utils::StringUtils::replaceAll(string(argv[1]), std::string("\\n"), std::string("\n"));
  
  MarsMission *marsMission = new MarsMission(missionInput);
  marsMission->run();
  for (int i=0; i<marsMission->numRobots(); i++){
    if (marsMission->robot(i).controller().hasAnError())
      cout << "Rover error" << endl;
    else
      cout << marsMission->robot(i).controller().position() << endl;
  }
  
  cout << endl << "Mission Completed!" << endl;
  return 0;
}