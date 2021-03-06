#ifndef __MEMORY_H__
#define __MEMORY_H__

#ifdef __cplusplus
 extern "C" {
#endif


#define MEM_PARA_DATE                   0x20150926

#define MEM_PARA_TAG                    0x19890924
#define MEM_PARA_CRC                    0x00000000
#define MAX_PARA_NUM                    32u //32 * 4B = 128B
#define MEM_PARA_SIZE                  (sizeof(MEM_PARA)) //128B

#define MEM_PARA_TAG_INDEX              0u
#define MEM_PARA_CRC_INDEX              1u
#define MEM_PARA_DATE_INDEX             2u

#define SINGLE_PARA_SIZE                4u

#define CHECKSUM_MEM_PARA_SIZE         (MEM_PARA_SIZE - 2 * SINGLE_PARA_SIZE)

#define MEM_PARA_PAGE_ADDR             (0x08002C00ul) //Page 11
#define MEM_PARA_PAGE_SIZE             (1 * 1024u) //1KB
#define MEM_PARA_PROGRAM_TIMES         (MEM_PARA_PAGE_SIZE / MEM_PARA_SIZE) //1024 / 128 = 8

typedef struct
{
    unsigned int tag; //存储标签
    unsigned int crc; //校验和
    unsigned int date; //日期

    unsigned int mems_debounce_threshold;

    unsigned int mems_cal_state;
    unsigned int mems_cal[MAX_MEMS_CAL_GRPS][MAX_MEMS_CAL_ELEMS];

    unsigned int para_reserve[MAX_PARA_NUM - 15];
} MEM_PARA, *P_MEM_PARA;

extern MEM_PARA g_mem_para;

unsigned int mem_para_write(void);
void mem_para_read(void);
void mem_para_restore(void);
void MEM_Init(void);


#ifdef __cplusplus
}
#endif

#endif
