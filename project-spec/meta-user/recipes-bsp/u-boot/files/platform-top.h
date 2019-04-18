/*
 * Below is adapted from the auto generated platform configuration.
 * We want to handle files differently to adapt to MW workflow
 */
#include <configs/platform-auto.h>
#include <configs/mw_xilinx_common.h>

/* Extra U-Boot Env settings */
#define CONFIG_EXTRA_ENV_SETTINGS \
	SERIAL_MULTI \ 
	CONSOLE_ARG \ 
	DFU_ALT_INFO_RAM \ 
	DFU_ALT_INFO_MMC \ 
	PSSERIAL0 \
  	"kernel_addr=0x10000000\0" \
	"initrd_addr=0x2000000\0" \
	"initrd_high=0x10000000\0" \
	"initrd_size=0x2000000\0" \
	"initrd_image=uramdisk.image.gz\0"	\
	"fdt_addr=23fff000\0" \
	"fdt_high=0x10000000\0" \
	"fdt_image=devicetree.dtb\0"	\
	"bitstream_addr=0x1000000\0"	\
	"bitstream_image=system.bit\0"	\
	"nc=setenv stdout nc;setenv stdin nc;\0" \ 
	"ethaddr=00:0a:35:00:22:01\0" \
	"bootenv=uEnv.txt\0" \ 
	"importbootenv=echo \"Importing environment from SD ...\"; " \ 
		"env import -t ${loadbootenv_addr} $filesize\0" \ 
	"loadbootenv=load mmc $sdbootdev:$partid ${loadbootenv_addr} ${bootenv}\0" \ 
	"sd_uEnvtxt_existence_test=test -e mmc $sdbootdev:$partid /uEnv.txt\0" \ 
	"uenvboot=" \
		"if run sd_uEnvtxt_existence_test; then " \
			"run loadbootenv; " \
			"echo Loaded environment from ${bootenv}; " \
			"run importbootenv; " \
		"fi; " \
		"if test -n $uenvcmd; then " \
			"echo Running uenvcmd ...; " \
			"run uenvcmd; " \
		"fi\0" \
    	"mmc_loadbit=echo Loading bitstream from SD/MMC/eMMC to RAM.. && " \
		"load mmc $sdbootdev:$partid ${bitstream_addr} ${bitstream_image} && " \
		"fpga loadb 0 ${bitstream_addr} ${filesize}\0" \
	"sd_bitstream_existence_test=test -e mmc $sdbootdev:$partid /${bitstream_image}\0" \
	"sd_boot_loadbit=" \
		"if run sd_bitstream_existence_test; then " \
			"run mmc_loadbit;" \
		"fi; \0" \    
    	ENV_CMD_INIT_ENV_ONCE \
	"sdboot=if mmc dev $sdbootdev; then " \
			"run uenv_init; " \
			"run uenvboot; " \
			"run sd_boot_loadbit; " \
			"echo Copying Linux from SD to RAM... && " \
			"load mmc $sdbootdev:$partid $kernel_addr Image && " \
			"load mmc $sdbootdev:$partid $fdt_addr $fdt_image && " \
			"if load mmc 0 ${initrd_addr} ${initrd_image}; then " \
				"booti ${kernel_addr} ${initrd_addr} ${fdt_addr}; " \
			"else " \
				"booti ${kernel_addr} - ${fdt_addr}; " \
			"fi &&" \
		"fi\0" \
	"autoload=no\0" \ 
	"sdbootdev=1\0" \ 
	"clobstart=0x10000000\0" \ 
	"netstart=0x10000000\0" \ 
	"dtbnetstart=0x23fff000\0" \ 
	"loadaddr=0x10000000\0" \ 
	"boot_img=BOOT.BIN\0" \ 
	"load_boot=tftpboot ${clobstart} ${boot_img}\0" \ 
	"update_boot=setenv img boot; setenv psize ${bootsize}; setenv installcmd \"install_boot\"; run load_boot ${installcmd}; setenv img; setenv psize; setenv installcmd\0" \ 
	"install_boot= fatwrite mmc ${sdbootdev} ${clobstart} ${boot_img} ${filesize}\0" \ 
	"bootenvsize=0x40000\0" \ 
	"bootenvstart=0x1e00000\0" \ 
	"eraseenv=sf probe 0 && sf erase ${bootenvstart} ${bootenvsize}\0" \ 
	"jffs2_img=rootfs.jffs2\0" \ 
	"load_jffs2=tftpboot ${clobstart} ${jffs2_img}\0" \ 
	"update_jffs2=setenv img jffs2; setenv psize ${jffs2size}; setenv installcmd \"install_jffs2\"; run load_jffs2 test_img; setenv img; setenv psize; setenv installcmd\0" \ 
	"sd_update_jffs2=echo Updating jffs2 from SD; fatload mmc ${sdbootdev}:1 ${clobstart} ${jffs2_img} && run install_jffs2\0" \ 
	"install_jffs2=sf probe 0 && sf erase ${jffs2start} ${jffs2size} && " \ 
		"sf write ${clobstart} ${jffs2start} ${filesize}\0" \ 
	"kernel_img=Image\0" \ 
	"load_kernel=tftpboot ${clobstart} ${kernel_img}\0" \ 
	"update_kernel=setenv img kernel; setenv psize ${kernelsize}; setenv installcmd \"install_kernel\"; run load_kernel ${installcmd}; setenv img; setenv psize; setenv installcmd\0" \ 
	"install_kernel=fatwrite mmc ${sdbootdev} ${clobstart} ${kernel_img} ${filesize}\0" \ 
	"cp_kernel2ram=fatload mmc ${sdbootdev} ${netstart} ${kernel_img}\0" \ 
	"dtb_img=system.dtb\0" \ 
	"load_dtb=tftpboot ${clobstart} ${dtb_img}\0" \ 
	"update_dtb=setenv img dtb; setenv psize ${dtbsize}; setenv installcmd \"install_dtb\"; run load_dtb ${installcmd}; setenv img; setenv psize; setenv installcmd\0" \ 
	"install_dtb=fatwrite mmc ${sdbootdev} ${clobstart} ${dtb_img} ${filesize}\0" \ 
	"cp_dtb2ram=fatload mmc ${sdbootdev}:1 ${dtbnetstart} ${dtb_img}\0" \ 
	"loadbootenv_addr=0x00100000\0" \ 
	"fault=echo ${img} image size is greater than allocated place - partition ${img} is NOT UPDATED\0" \ 
	"test_crc=if imi ${clobstart}; then run test_img; else echo ${img} Bad CRC - ${img} is NOT UPDATED; fi\0" \ 
	"test_img=setenv var \"if test ${filesize} -gt ${psize}\\; then run fault\\; else run ${installcmd}\\; fi\"; run var; setenv var\0" \ 
	"netboot=tftpboot ${netstart} ${kernel_img} && bootm\0" \ 
	"default_bootcmd=run uenvboot; run cp_kernel2ram && run cp_dtb2ram && booti ${netstart} - ${dtbnetstart}\0" \ 
""


#if !defined(CONFIG_ENV_IS_IN_FAT)
#define CONFIG_ENV_IS_NOWHERE	1
#endif

#define CONFIG_SYS_BOOTM_LEN 0xF000000

#define DFU_ALT_INFO_RAM \
        "dfu_ram_info=" \
        "setenv dfu_alt_info " \
        "image.ub ram $netstart 0x1e00000\0" \
        "dfu_ram=run dfu_ram_info && dfu 0 ram 0\0" \
        "thor_ram=run dfu_ram_info && thordown 0 ram 0\0"

#define DFU_ALT_INFO_MMC \
        "dfu_mmc_info=" \
        "set dfu_alt_info " \
        "${kernel_image} fat 0 1\\\\;" \
        "dfu_mmc=run dfu_mmc_info && dfu 0 mmc 0\0" \
        "thor_mmc=run dfu_mmc_info && thordown 0 mmc 0\0"

/*Required for uartless designs */
#ifndef CONFIG_BAUDRATE
#define CONFIG_BAUDRATE 115200
#ifdef CONFIG_DEBUG_UART
#undef CONFIG_DEBUG_UART
#endif
#endif

/*Define CONFIG_ZYNQMP_EEPROM here and its necessaries in u-boot menuconfig if you had EEPROM memory. */
#ifdef CONFIG_ZYNQMP_EEPROM
#define CONFIG_SYS_I2C_EEPROM_ADDR_LEN  1
#define CONFIG_CMD_EEPROM
#define CONFIG_ZYNQ_EEPROM_BUS          5
#define CONFIG_ZYNQ_GEM_EEPROM_ADDR     0x54
#define CONFIG_ZYNQ_GEM_I2C_MAC_OFFSET  0x20
#endif

