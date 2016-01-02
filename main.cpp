#include <iostream>
#include "Planning.h"

using namespace std;

int main() {
    Planning planning;

    planning.initTasks();

    planning.getCriticalPath();

    return 0;
}