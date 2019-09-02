#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main (int argc, char* argv[]) {
        int child;//child process running
        int counter;//counts as the child is completed
        int status;//exit status of the child processes
        int pid;//process id(pid) of running process
        int sleeptime;//time for each child to sleep
        int arg;//command argument index

        //check to make sure there are enough command line arguments
        //if there is not, the program exits

        if (argc < 4) {
                cout << "fewer than 3 command arguments given...now exiting" << endl
                << "extra arguments will be ignored..." << endl;
                exit(-1);
        }

        //this loop creates the children processes, that will run a total of 3 times
        for ( int i = 1; i < 4; ++i) {
                arg = 0;
                child = 1;
                cout << "*** ROUND: " << i << " ***" << endl;

        for (int j = 0; j < 3; ++j ) {//child is initialized above at 1 in the parent

                if(child > 0) {
                        arg++;
                        child = fork();
                }
        }
        // runs depending on parent or child
        switch(child) {
                case 0:
                        pid = getpid();
                        sleeptime = (pid % 10) * 3 + 5;
                        cout << "Process " << argv[arg] << " pid:" << pid << "started..." << endl;
                        sleep(sleeptime);
                        cout << "Process " << pid << "exiting after" << sleeptime << " seconds" << endl;
                        exit(0);
               case -1:
                        cout << "Error creating child" << endl;
                        break;
                default:
                        //parent process waits until children is completed
                        counter = 0;
                        while (counter < 3) {
                                pid = wait(&status);
                                cout << "Process " << pid << "exited with status: " << WEXITSTATUS(status) << endl;
                                ++counter;
                        }
                }
                cout << "*******************************************************" << endl;
                cout << endl;
        }
        return 0;
}
