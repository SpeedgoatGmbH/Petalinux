#ifndef _PE5_XU1_H
#define _PE5_XU1_H

/*M2M Write*/
#define FB_WR_RST_GPIO 97
#define FB_WR_ADDR a0310000
#define FB_WR_ADDR_MSB 0x0
#define FB_WR_ADDR_LSB 0xa0310000
#define FB_WR_SZ_MSB 0x0
#define FB_WR_SZ_LSB 0x10000
#define FB_WR_INT 89

/*M2M Read*/
#define FB_RD_RST_GPIO 93
#define FB_RD_ADDR a0300000
#define FB_RD_ADDR_MSB 0x0
#define FB_RD_ADDR_LSB 0xa0300000
#define FB_RD_SZ_MSB 0x0
#define FB_RD_SZ_LSB 0x10000
#define FB_RD_INT 90

/*Video Codec Unit*/
#define VCU_ENC_ADDR a0200000
#define VCU_ENC_ADDR_MSB 0x0
#define VCU_ENC_ADDR_LSB 0xa0200000
#define VCU_DEC_ADDR_MSB 0x0
#define VCU_DEC_ADDR_LSB 0xa0220000
#define VCU_SZ_MSB 0x0
#define VCU_SZ_LSB 0x10000
#define VCU_INT 91

/*Test Pattern Generator Video Timing Generation*/
#define TPG_VTC_ADDR a0120000
#define TPG_VTC_ADDR_MSB 0x0
#define TPG_VTC_ADDR_LSB 0xa0120000
#define TPG_VTC_SZ_MSB 0x0
#define TPG_VTC_SZ_LSB 0x10000

/*Test Pattern Generator*/
#define TPG_RST_GPIO 96
#define TPG_ADDR a0130000
#define TPG_ADDR_MSB 0x0
#define TPG_ADDR_LSB 0xa0130000
#define TPG_SZ_MSB 0x0
#define TPG_SZ_LSB 0x10000

/*Test Pattern Generator Frame Buffer*/
#define TPG_FB_WR_RST_GPIO 94
#define TPG_FB_WR_ADDR a0110000
#define TPG_FB_WR_ADDR_MSB 0x0
#define TPG_FB_WR_ADDR_LSB 0xa0110000
#define TPG_FB_WR_SZ_MSB 0x0
#define TPG_FB_WR_SZ_LSB 0x10000
#define TPG_FB_WR_INT 92


#endif