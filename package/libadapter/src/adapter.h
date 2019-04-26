
#ifndef __ADAPTER_H_
#define __ADAPTER_H_

#define WAN_STATIC  (1 << 1)
#define WAN_DHCP    (1 << 2)
#define WAN_PPPoE   (1 << 3)
#define WAN_PPPTP   (1 << 4)
#define WAN_L2TP    (1 << 5)
#define WAN_WIFI_2G (1 << 6)
#define WAN_WIFI_5G (1 << 7)
#define WAN_USB_4G  (1 << 8)

#define MAX_LAN_NUM 4
#define MAX_WAN_NUM 4

/* -------- switch -------- */

#define MAX_PANNEL_PORT 5
#define MAX_PHY_PORT 7

int getCpuPort(int phyPort);
int phyPort_to_pannelPort_xlate(int phyPort);
int pannelPort_to_phyPort_xlate(int pannelPort);

/* -------- network -------- */
void get_lan_num(int *num);
int get_lan_idx(char *device);
char *get_lan_name(int lan_idx);
int lan_device_to_name(char *device, char *name, int len);
int find_udhcpd_host_name(char *device, char *ip, char *host, int len);

/* -------- nvram -------- */

#endif
