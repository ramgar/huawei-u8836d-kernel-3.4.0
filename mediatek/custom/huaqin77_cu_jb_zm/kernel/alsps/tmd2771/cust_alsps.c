#include <linux/types.h>
#include <mach/mt_pm_ldo.h>
#include <cust_alsps.h>

static struct alsps_hw cust_alsps_hw = {
    .i2c_num    = 0,
	.polling_mode_ps =0,
	.polling_mode_als =1,
    .power_id   = MT65XX_POWER_NONE,    /*LDO is not used*/
    .power_vol  = VOL_DEFAULT,          /*LDO is not used*/
    .i2c_addr   = {0x72, 0x48, 0x78, 0x00},
    /*Lenovo-sw chenlj2 add 2011-06-03,modify parameter below two lines*/
    .als_level  = { 0, 12, 16,  20, 24, 30 ,36,  40,  48 ,  100, 800, 2000, 5000, 10000, 65535},
    .als_value  = {10, 20,20,  45, 60, 80, 120, 140, 225, 320,  640,  2600,  6000, 9000,  10240, 10240},
    .ps_high_thd_val = 260,
    .ps_low_thd_val = 150,
    .ps_threshold = 900,
};
struct alsps_hw *get_cust_alsps_hw(void) {
    return &cust_alsps_hw;
}
int TMD2771_CMM_PPCOUNT_VALUE = 0x0E;
int ZOOM_TIME = 8;
int TMD2771_CMM_CONTROL_VALUE = 0xE0;
