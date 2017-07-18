// һЩ���õġ����õĽӿ�

/*
 * ��ָ���Ĵ�����ָ��λ��1
 * @reg �Ĵ�����ַ
 * @bit ��Ҫ��1����һbit
 */
void reg_set_one_bit(volatile unsigned int *reg, unsigned int bit)
{
    unsigned int temp, mask;

    mask = 1 << bit;
    temp = *reg;
    temp |= mask;
    *reg = temp;

    return ;
}


/*
 * ��ָ���Ĵ�����ָ��λ����
 * @reg �Ĵ�����ַ
 * @bit ��Ҫ�������һbit
 */
void reg_clr_one_bit(volatile unsigned int *reg, unsigned int bit)
{
    unsigned int temp, mask;

    mask = 1 << bit;
    temp = *reg;
    temp &= ~mask;
    *reg = temp;

    return ;
}



/*
 * ��ȡָ���Ĵ�����ָ��λ��ֵ
 * @reg �Ĵ�����ַ
 * @bit ��Ҫ��ȡֵ����һbit
 * @ret ָ��λ��ֵ
 */
unsigned int reg_get_bit(volatile unsigned int *reg, unsigned int bit)
{
    unsigned int temp;

    temp = *reg;
    temp = (temp >> bit) & 1;

    return temp;
}


/*
 * ��Ĵ�����дһ��32bit������
 * @data ��д�������
 * @addr �Ĵ�����ַ
 */
void reg_write_32(unsigned int data, volatile unsigned int *addr)
{
    *addr = data;
}


/*
 * �ӼĴ�������һ��32bit����
 * @addr �Ĵ�����ַ
 * @ret ����������
 */
unsigned int reg_read_32(volatile unsigned int *addr)
{
    return (*addr);
}



