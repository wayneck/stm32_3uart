/************************************************************************************
							本例程提供自以下店铺：
								Ilovemcu.taobao.com
								epic-mcu.taobao.com
							实验相关外围扩展模块均来自以上店铺
							作者：神秘藏宝室							
*************************************************************************************/
#include "stm32f10x.h"
#include "delay.h"
#include "HX711.h"
#include "usart.h"
#include "ds18b20.h"

int main(void)
{	
	u8 i;
	u8 len;
	u8 len3;
	u16 times=0;
	float t;
	 
	char nputCmd[11]="1234567890";
	delay_init();
	NVIC_Configuration(); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 //串口初始化为9600
	delay_ms(200); 
	uart2_init(115200);	 //串口初始化为9600
	delay_ms(2000); 
	uart3_init(115200);	 //串口初始化为9600
	//USART2->BRR=0x1d4c; //uart2_init(9600); 4800bps
	//USART2->BRR=0xea6;  //uart2_init(19200); 9600bps
	 printf("ggggggggggg \n");
	ds18b20_init();
	while(1)
	{
		/*
		if(USART2_RX_STA&0x8000)
		{					   
			len=USART2_RX_STA&0x3fff;//得到此次接收到的数据长度
			USART2_RX_BUF[len] = '\r';
			USART2_RX_BUF[len+1] = '\n';
			for(i=0;i<len+2;i++)
			{
				USART_SendData(USART1, USART2_RX_BUF[i]);//向bluetooth串口1发送数据
				while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//等待发送结束
			}
			for(i=0;i<len+2;i++)
			{
				USART_SendData(USART3, USART2_RX_BUF[i]);//向bluetooth串口1发送数据
				while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束
			}
			USART2_RX_STA=0;			
		}
		
     if(USART1_RX_STA&0x8000)
		{					   
			len=USART1_RX_STA&0x3fff;//得到此次接收到的数据长度		
			USART_RX_BUF[len] = '\r';
			USART_RX_BUF[len+1] = '\n';
			
			for(i=0;i<len+2;i++)
			{             
				USART_SendData(USART3, USART_RX_BUF[i]);//向串口1发送数据
				while(USART_GetFlagStatus(USART3,USART_FLAG_TC)!=SET);//等待发送结束			
			}
			USART1_RX_STA=0;
				
		}
		
		if(USART3_RX_STA&0x8000)
		{					   
			len3=USART3_RX_STA&0x3fff;//得到此次接收到的数据长度		
			USART3_RX_BUF[len3] = '\r';
			USART3_RX_BUF[len3+1] = '\n';

			for(i=0;i<len3+2;i++)
			{             
				USART_SendData(USART1, USART3_RX_BUF[i]);//向串口1发送数据
				while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//等待发送结束			
			}
			USART3_RX_STA=0;
				
		}*/
		//else
		{
			//printf(". \n");  
			delay_ms(1000);  
     // printf("eee");			
		 t = ds18b20_read();
     printf("%05.1f \n", t);
			//for(i=0;i<10;i++)
			//{
			//	USART_SendData(USART2,0x31);//向串口1发送数据
			//	while(USART_GetFlagStatus(USART2,USART_FLAG_TC)!=SET);//等待发送结束			
			//}
		}
	}
}






