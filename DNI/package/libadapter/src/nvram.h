
#ifndef __NVRAM_H_
#define __NVRAM_H_

/* nvram相关, 取自DNI libconfig.so
 *
 * 其他未知函数参数
 *      config_getall 获取某种name为name1，name2, ..., nameN的所有配置
 *      config_default 复位到出厂配置
 *      config_backup 备份当前配置
 *      config_restore 载入配置文件
 */

extern char *config_get(const char *name);
int config_get_int(const char *name);
char *config_get_ext(const char * prefix, int idx);
int config_get_int_ext(const char * prefix, int idx);
extern int config_set(const char *name, const char *value);
int config_set_int(const char *name, int value);
int config_set_ext(const char * prefix, int idx, char * value);
int config_set_int_ext(const char * prefix, int idx, int value);
extern int config_match(const char *name, char *match);
extern int config_inmatch(const char *name, char *invmatch);
extern int config_unset(const char *name);
int config_unset_ext(const char *prefix, int idx);
extern int config_commit(void);
extern int config_uncommit(void);


#endif
