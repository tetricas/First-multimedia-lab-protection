#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "Classes.h"

using namespace std;

int main()
{
    srand(time(NULL));
    MGame mgame(5, 4, 3 ,3);
    int n;
    cin>>n;
    while(n!= 10)
    {
        mgame.Turn();
        cin>>n;
    }

    return 0;
}
