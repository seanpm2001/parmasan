
#include <cstdio>
#include <signal.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include "tracer.hpp"

int main(int argc, char* argv[]) {

    if(argc < 2) {
        printf("Please, specify which program to trace\n");
        return 0;
    }

    FILE* result_file = fopen("./tracer-result.txt", "w");

    tracer t(result_file);
    t.trace(argv + 1);

    fclose(result_file);
    
    return 0;
}