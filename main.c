#include "uart.h"
#include "cmd.h"
#include "iic.h"
#include "key_irq.h"
#include "interrupt.h"


#define CMD_MAX_LEN 32

char cmd[CMD_MAX_LEN];
int main()
{
        cmd_t *cmd_ptr = 0;

	/*8n1 115200 ��ѯģʽ*/
	uart_init();
        led_init();
        iic2_init();
        key_irq_init();
        interrupt_init();
        enable_interrupts();
	
	while(1)
	{
            /*����������ʾ��*/
            uart_puts("\narmshell##");
            /*����PC���˵�����*/
            uart_gets(cmd, CMD_MAX_LEN);
            /*����ƥ��*/
            cmd_ptr = find_cmd(cmd);
            /*ִ���û�����*/
            if(cmd_ptr == 0)
            {
                uart_puts("\nunknown command!");
            }
            else
            {
                cmd_ptr->cmd_func();
            }

	}
	return 0;	
}






