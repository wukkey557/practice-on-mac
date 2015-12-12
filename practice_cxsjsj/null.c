-----------------------

?: #define TWENTY 20  ---->  #define OUTPUT_BUFSIZE 20

-----------------------

全局变量最好带注释,名字可以长一些,应带说明性,全局变量可以首字母大写:Global
局部变脸最好短一些

-----------------------

类内名字语义上不应重复:
?:
class UserQueue {
	int queueCapacity;
};

--->

class UserQueue {
	int capacity;
};

------------------------

返回布尔类型的函数名:
?: checkOctal(c) ----> isOctal(c)

------------------------

scanf的所有参数都在函数被调用前已经求好值了

------------------------

勿用gets(),用fgets

------------------------

switch case 掉下时应写注释: case '1': 
						  	xxx;
						  	/*fall through*/
						  case '2': 
						  	xxx; 
						  	break;

这种情况不用写注释: 	case '1':
				 	case '2':
				 	case '3': 
				 		xxx;
				 		break;
------------------------