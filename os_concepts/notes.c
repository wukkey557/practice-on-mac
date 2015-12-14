ax:累加寄存器
cx:计数寄存器
si:源变址寄存器
di:目的变址寄存器
ds:数据段寄存器
es:附加段寄存器
cs:代码段寄存器
rep:重复其后串操作指令,以cx的值为标准,重复前先判断cx是否为0,为0则停止
movw:传送一个字(2个字节)
jmpi:间接跳转
bx:基址寄存器,用于地址索引

引导扇区代码:

start:
	mov ax, #BOOTSEG  mov ds, ax	//BOOTSEG = 0x07c0
	mov ax, #INITSEG  mov es, ax	//INITSEG = 0x9000
	mov cx, #256
	sub si, si        sub di, di	//将0x07c0:0x0000处开始的512个字节移动到0x9000:0x0000处;0x07c0 << 4 == 0x7c00, 0x9000 << 4 == 0x90000
	rep movw	//以cx的值256为标准,每次传送一个字节,既传送512个字节
	jmpi go, INITSEG	//jmpi:段间跳转指令,即跳转到cs:ip地址,jmpi ip, cs
						//0x9000:go 就是程序移动到新地址后go代码地址
go: 
	mov ax, cs
	...			//为call做准备

load_setup:		//载入setup模块
	...
	mov cx, #0x0002            mov bx, #0x0200
	mov ax, #0x0200+SETUPLEN   int 0x13	 //ah->0x02->读磁盘, al->扇区数量->SETUPLEN=4; 0x13是bios读扇区中断, ch:柱面号, cl:开始扇区
										 //将setup模块(4个扇区)的代码读到bootseg上面
										 //es:bx就是内存地址,(0x9000 << 4) + 0x0200 == 0x90200
	...
	mov dx, 0x0000	//	dh:磁头号, dl:驱动器号

Ok_load_setup:		//载入setup之后
	...			mov ax, #0x0800	// ah=8获得磁盘参数
	int 0x13 	mov ch, 0x00	mov sectors, cx		// sectors: 要读取的磁道扇区数
	...		...			int 0x10	//读光标
	mov cx, #24		mov bx, 0x0007			//24为开机字符串字节数, 7为显示属性
	mov bp, #msg1		...			int 0x10	//int 0x10为: 显示字符, msg1(在bootsetc.s文件末尾): "welcome to..."
	call read_it	//仍用0x13中断, 读取磁盘system代码等模块
	jmpi 0, SETUPSEG	// bootsecion引导程序执行完毕,将控制权交给setup,指令指针跳转到0x90200:0x0000,执行setup.s

read_it:	//函数,system模块很大,要跨越磁道

boot工作就是:读setup, 读system




