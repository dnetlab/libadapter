
#include <stdio.h>
#include "adapter.h"

/* JUST for BR500 */
int portMap[] = {0, 4, 3, 2, 1, 5, 6};

int getCpuPort(int phyPort)
{
    if(phyPort == 0 || phyPort == 5)
        return 0;
    else
        return 6;	
}

int phyPort_to_pannelPort_xlate(int phyPort)
{
    int i;

    for(i = 0; i < MAX_PHY_PORT; i ++)
    {
        if(portMap[i] == phyPort)
        {
            return i;
        }
    }

    return -1;
}

int pannelPort_to_phyPort_xlate(int pannelPort)
{
    if(pannelPort > MAX_PANNEL_PORT)
    {
        return -1;
    }
    
    return portMap[pannelPort];
}

