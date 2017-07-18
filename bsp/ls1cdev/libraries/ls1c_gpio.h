

#ifndef __OPENLOONGSON_GPIO_H
#define __OPENLOONGSON_GPIO_H



// ��о1c��gpio�ǰ���0,1,2,3,4...������˳���ŵģ�
// ���ڲ����Ĵ�����ʱ�����ǰ���ÿ32��һ�����ֵ�
// ��������������ԣ���ÿ���32��gpio����һ��"port"��ÿ��gpio��ÿ���е�������"pin"
// port = gpio / 32
// pin  = gpio % 32
// ����GPIO50��port=1,pin=18
#define GPIO_GET_PORT(gpio)                 ((gpio) / 32)
#define GPIO_GET_PIN(gpio)                  ((gpio) % 32)


// gpio�Ĺ���ģʽ--���롢���
typedef enum{
    gpio_mode_output = 0,       // ���
    gpio_mode_input = 1         // ����
}gpio_mode_t;


//  gpio�ߵ͵�ƽֵ
typedef enum{
    gpio_level_low = 0,         // �͵�ƽ
    gpio_level_high = 1         // �ߵ�ƽ
}gpio_level_t;




/*
 * ��ȡָ��gpio��CFG�Ĵ���
 * @gpio gpio���
 * @ret CFG�Ĵ���
 */
volatile unsigned int *gpio_get_cfg_reg(unsigned int gpio);

/*
 * gpio��ʼ��
 * @gpio gpio���ţ�ȡֵ��Χ[0, 127]
 * @mode gpio�Ĺ���ģʽ(���롢���)
 *
 * ��: ��gpio50��ʼ��Ϊ���
 * gpio_init(50, gpio_mode_output);
 */
void gpio_init(unsigned int gpio, gpio_mode_t mode);


/*
 * ��ָ��gpio����ߵ�ƽ��͵�ƽ
 * @gpio gpio���ţ�ȡֵ��Χ[0, 127]
 * @level ��ƽֵ
 *
 * ��: ��gpio50������͵�ƽ
 * gpio_set(50, gpio_level_low);
 */
void gpio_set(unsigned int gpio, gpio_level_t level);



/*
 * ��ȡָ��gpio���ŵ�ֵ
 * @gpio gpio���ţ�ȡֵ��Χ[0,127]
 *
 * ��: ��ȡgpio50�����ϵ�ֵ
 * gpio_level_t level;
 * level = gpio_get(50);
 */
unsigned int gpio_get(unsigned int gpio);





#endif

