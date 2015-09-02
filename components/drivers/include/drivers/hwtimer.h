#ifndef __HWTIMER_H__
#define __HWTIMER_H__

#include <rtthread.h>
#include <rtdevice.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ��ʱ���������� */
typedef enum
{
    HWTIMER_CTRL_TIMEOUT_SET = 0x01, /* ���ó�ʱֵ */
    HWTIMER_CTRL_FREQ_SET,           /* ���ü���Ƶ�� */
    HWTIMER_CTRL_START,              /* ������ʱ�� */
    HWTIMER_CTRL_STOP,               /* ֹͣ��ʱ�� */
    HWTIMER_CTRL_INFO_GET,           /* ��ȡ��ʱ��������Ϣ */
    HWTIMER_CTRL_MODE_SET            /* ���ö�ʱģʽ */
} rt_hwtimer_ctrl_t;

/* ��ʱģʽ */
typedef enum
{
    HWTIMER_MODE_ONESHOT = 0x01,
    HWTIMER_MODE_PERIOD
} rt_hwtimer_mode_t;

/* ��ʱ������ֵ */
typedef struct rt_hwtimerval
{
    rt_int32_t sec;      /* �� */
    rt_int32_t usec;     /* ΢�� */
} rt_hwtimerval_t;

#define HWTIMER_CNTMODE_UP      0x01 /* ��ʱ������������ʽ */
#define HWTIMER_CNTMODE_DW      0x02 /* ��ʱ���ݼ�������ʽ */

struct rt_hwtimer_device;

struct rt_hwtimer_ops
{
    void (*init)(struct rt_hwtimer_device *timer);
    void (*deinit)(struct rt_hwtimer_device *timer);
    void (*start)(struct rt_hwtimer_device *timer, rt_hwtimer_mode_t mode);
    void (*stop)(struct rt_hwtimer_device *timer);
    rt_err_t (*timeout_set)(struct rt_hwtimer_device *timer, rt_uint32_t t);
    rt_uint32_t (*count_get)(struct rt_hwtimer_device *timer);
    rt_err_t (*control)(struct rt_hwtimer_device *timer, rt_uint32_t cmd, void *args);
};

/* ��ʱ����������(���ɶ�̬����) */
struct rt_hwtimer_info
{
    rt_int32_t maxfreq;    /* ��ʱ��֧�ֵ�������ʱ�� */
    rt_int32_t minfreq;    /* ��ʱ��֧�ֵ���С����ʱ�� */
    rt_uint32_t maxcnt;    /* ���������ʱֵ */
    rt_uint8_t  cntmode;   /* ����ģʽ(����/�ݼ�,Ӧ�ò�������Ĵ˲���) */
};

typedef struct rt_hwtimer_device
{
    struct rt_device parent;
    const struct rt_hwtimer_ops *ops;
    const struct rt_hwtimer_info *info;

    /* �����㲻�ù������²��� */
    rt_int32_t freq;                /* ����Ƶ�� */
    rt_int32_t overflow;            /* ������� */
    float period_sec;               /* �������(s) */
    rt_int32_t cycles;              /* ѭ������ */
    rt_int32_t reload;              /* ����cycles */
    rt_hwtimer_mode_t mode;         /* ��ʱģʽ */
} rt_hwtimer_t;

rt_err_t rt_device_hwtimer_register(rt_hwtimer_t *timer, const char *name, void *user_data);
void rt_device_hwtimer_isr(rt_hwtimer_t *timer);

#ifdef __cplusplus
}
#endif

#endif
