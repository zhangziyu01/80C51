/**************************************************************************************
*		              LED��ˮ��ʵ��												  *
													https://github.com/zhangziyu01/80C51							  
***************************************************************************************/

#include "reg52.h"			 
#include<intrins.h>		

typedef unsigned int u16;	  
typedef unsigned char u8;

#define led P2	    

/*******************************************************************************
* �� �� ��         : delay
* ��������		   : ��ʱ������i=1ʱ����Լ��ʱ10us
*******************************************************************************/
void delay(u16 i)
{
	while(i--);	
}

void main()
{
	u8 i;
	led=0xfe;
	delay(50000); //��Լ��ʱ450ms	
	while(1)
	{	
/*		for(i=0;i<8;i++)
		{
			P2=~(0x01<<i);	 //��1����iλ��Ȼ�󽫽��ȡ����ֵ��P2��
			delay(50000); //��Լ��ʱ450ms
		}
*/		
		for(i=0;i<7;i++)	 //��led����һλ
		{
			led=_crol_(led,1);
			delay(50000); //��Լ��ʱ450ms	
		}
		for(i=0;i<7;i++)	//��led����һλ
		{
			led=_cror_(led,1);
			delay(50000); //��Լ��ʱ450ms	
		}	
	}		
}