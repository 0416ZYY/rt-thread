E-Mail : Archer Zhang <archer.zhang@wh-mx.com>

******************************
�ļ����У���Ӻ��޸�
******************************
[1] ��bspĿ¼�£����AE210PĿ¼������Andes AE210P EVB��N1068A������Ŀ¼��
[2] ��libcpuĿ¼�£����nds32Ŀ¼������Andes N10ϵ��Core����ϵĿ¼��
[3] ���ڱ�������ԭ���޸���finsh.h�ļ���Line��74��75������
	#if !(defined(__GNUC__) && defined(__x86_64__))
	//typedef unsigned int size_t; // ע�����typedef
	#include <stddef.h> // �������ͷ�ļ�����
	#include <string.h>
	#else
[4] ���ڴ���δʹ���жϽ��գ�����ʹ���˲�ѯ���գ������޸���shell.c�ļ�������
	a. Line��316��317
	//rt_device_set_rx_indicate(shell->device, finsh_rx_ind);
	//rt_device_open(shell->device, (RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_STREAM | RT_DEVICE_FLAG_INT_RX));
	rt_device_open(shell->device, (RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_STREAM));

	b. Line��326��ע�͸���
	// if (rt_sem_take(&shell->rx_sem, RT_WAITING_FOREVER) != RT_EOK) continue;

	c. Line��553�����CPUռ�õ��ͷ�

	rt_thread_delay(1); // ����rt-schedule();

******************************
���̹���
******************************
[1] �ù���ʹ��Makefile����Makefile���ļ�AE210P/Makefile��
      �������£�
	make APP=rtthread AE210P=1 USING_CLI=1 DEBUG=1 all
	make APP=rtthread AE210P=1 USING_CLI=1 DEBUG=1 clean

******************************
Tool Chain/IDE
******************************
[1] IDE��AndeSight_V300_STD

����һ������Eclipse��GNU��GDB�Ļ��������Ķ�Ӧ����/�����ı�׼�ĵ����ɡ�

���ڴ������̺͵��ԣ�����ġ�Andes���̴����͵���.docx����

******************************
����Ŀ��壨PCBA��
******************************
[1] AE210P EVB


