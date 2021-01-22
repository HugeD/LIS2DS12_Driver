#include "LIS2DS12_CFn.h"

/* ʹ�÷��� */
//	int16_t data[3] = {0};
//	LIS2DS12_CFn_IsDeviceReady(&hi2c2);
//	LIS2DS12_CFn_Initialize(&hi2c2);
//	LIS2DS12_CFn_Data_Collection(&hi2c2, data);
//	printf("x = %.4f\r\ny = %.4f\r\nz = %.4f\r\n",data[0]/1000.0,data[1]/1000.0,data[2]/1000.0);



/* Ӳ����� */
status_t LIS2DS12_CFn_IsDeviceReady(void *handle)
{
	u8_t wai;
	u8_t stat = MEMS_ERROR;
	stat = !HAL_I2C_IsDeviceReady(handle, LIS2DS12_ACC_I2C_ADDRESS_HIGH, 10, 100);
	if(MEMS_SUCCESS != stat)
	{
		printf("Ӳ������\r\n");
		return MEMS_ERROR;
	}
	stat = LIS2DS12_ACC_ReadReg(handle, LIS2DS12_ACC_WHO_AM_I_REG, &wai, 1);
	if(MEMS_SUCCESS != stat)
	{
		printf("������ʧ��\r\n");
		return MEMS_ERROR;
	}
	if(LIS2DS12_ACC_WHO_AM_I != wai)
	{
		printf("�������ͺŲ�ƥ��\r\n");
		return MEMS_ERROR;
	}
	return MEMS_SUCCESS;
}

/* Ӳ����ʼ�� */
status_t LIS2DS12_CFn_Initialize(void *handle)
{
	u8_t stat = MEMS_ERROR;
	//CTRL1 ��ʼ��
	stat = LIS2DS12_ACC_W_BDU(handle, LIS2DS12_ACC_BDU_OFF);	//BDU
	stat &= LIS2DS12_ACC_W_HF_ODR(handle, LIS2DS12_ACC_HF_ODR_ON);	//HF_ODR
	stat &= LIS2DS12_ACC_W_FullScale(handle, LIS2DS12_ACC_FS_16G);	//FS
	stat &= LIS2DS12_ACC_W_ODR(handle, LIS2DS12_ACC_ODR_HR_14bit_800Hz);	//ODR
	if(MEMS_SUCCESS != stat)
	{
		printf("CTRL1 ��ʼ��ʧ��\r\n");
		return MEMS_ERROR;
	}
			
	//CTRL2 ��ʼ��
	stat &= LIS2DS12_ACC_W_I2C_DISABLE(handle, LIS2DS12_ACC_I2C_DISABLE_OFF);	//I2C_DISABLE
	if(MEMS_SUCCESS != stat)
	{
		printf("CTRL2 ��ʼ��ʧ��\r\n");
		return MEMS_ERROR;
	}
	return MEMS_SUCCESS;
}

/* �ɼ����ٶ����� */
status_t LIS2DS12_CFn_Data_Collection(void *handle, i16_t *buff)
{
	u8_t stat = MEMS_ERROR;
	LIS2DS12_ACC_DRDY_t drdy = LIS2DS12_ACC_DRDY_EV_OFF;
	
	while(LIS2DS12_ACC_DRDY_EV_ON == drdy)
		printf("׼��������\r\n");
	
	stat = LIS2DS12_ACC_Get_Acceleration(handle, buff);
	
	if(MEMS_SUCCESS != stat)
	{
		printf("���ݲɼ�ʧ��\r\n");
		return MEMS_ERROR;
	}
	return MEMS_SUCCESS;
}


