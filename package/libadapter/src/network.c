
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "nvram.h"
#include "adapter.h"

struct if_map {
    int idx;
    int type;
    char *device;
    char *name;
};

struct wan_type {
    int id;
    char *name;
};

static struct wan_type wan_types[] = {
    { .id = WAN_STATIC, .name = "static" },
    { .id = WAN_DHCP, .name = "dhcp" },
    { .id = WAN_PPPoE, .name = "pppoe" },
    { .id = WAN_PPPTP, .name = "ppptp" },
    { .id = WAN_L2TP, .name = "l2tp" },
    { .id = -1, .name = NULL },
};

static struct if_map lan_maps[MAX_LAN_NUM] = {
    { .idx = 1, .device = "br0", .name = "LAN1" },
    { .idx = 2, .device = "br1", .name = "LAN2" },
    { .idx = 3, .device = "br2", .name = "LAN3" },
    { .idx = 4, .device = "br3", .name = "LAN4" },
};

static struct if_map wan_maps[] = {
    { .idx = 1, .type = (WAN_STATIC | WAN_DHCP), .device = "brwan", .name = "WAN1" },
    { .idx = 1, .type = (WAN_PPPoE | WAN_PPPTP | WAN_L2TP), .device = "ppp0", .name = "WAN1" },
};

void get_lan_num(int *num)
{
    int val = 0;
    val = config_get_int("lan_num");
    *num = ((val > 0) ? val : 1);
}

int get_lan_idx(char *device)
{
    int i = 0;

    for(i = 0; i < MAX_LAN_NUM; i ++)
    {
        if(strcmp(device, lan_maps[i].device) == 0)
        {
            return lan_maps[i].idx;
        }
    }

    return -1;
}

char *get_lan_name(int lan_idx)
{
    int i = 0;

    for(i = 0; i < MAX_LAN_NUM; i ++)
    {
        if(lan_idx == lan_maps[i].idx)
        {
            return lan_maps[i].name;
        }
    }

    return NULL;
}

int lan_device_to_name(char *device, char *name, int len)
{
    int i = 0;
    
    for(i = 0; i < MAX_LAN_NUM; i ++)
    {
        if(strcmp(device, lan_maps[i].device) == 0)
        {
            strncpy(name, lan_maps[i].name, len - 1);
            return 0;
        }
    }
    
    return -1;
}

int udhcpd_hostlist_map(char *device, char *file, int len)
{
    int idx = 0;

    idx = get_lan_idx(device);
    if(idx > 0)
    {
        if(idx == 1)
        {
            return snprintf(file, len, "/tmp/udhcpd_hostlist");
        }
        else
        {
            return snprintf(file, len, "/tmp/udhcpd%d.hostlist", idx - 1);
        }
    }

    return -1;
}

/*
 * 注意格式为 x.x.x.x 1234
 */
int find_udhcpd_host_name(char *device, char *ip, char *host, int len)
{
    int ret = 0;
    char host_file[32] = {0};
    FILE *fp = NULL;
    char line[128] = {0};
    char str1[16], str2[33];

    ret = udhcpd_hostlist_map(device, host_file, sizeof(host_file));
    if(ret < 0)
    {
        return -1;
    }

    fp = fopen(host_file, "r");
    if(!fp)
    {
        return -1;
    }

    while(fgets(line, sizeof(line), fp) != NULL)
    {
        memset(str1, 0x0, sizeof(str1));
        memset(str2, 0x0, sizeof(str2));
        
        ret = sscanf(line, "%s %s", str1, str2);
        if(ret != 2)
        {
            continue;
        }

        if(strcmp(ip, str1) == 0)
        {
            strncpy(host, str2, len - 1);
            break;
        }
    }

    fclose(fp);

    return 0;
}
