#include<Python.h>

long long fibonacci(n){
    
    if(n<2)
        return 1;
    else
        return fibonacci(n-2) + fibonacci(n-1);
}

static PyOnject* fibonacci_py(PyObject* self, PyObject* args){
	/*
	签名并不指定具体的参数列表，只是指定PyObject* args，他持有一个指向结构体的指针，结构体中包含参数的元祖
	参数列表的实际验证必须在函数体内部执行，正式Fibonacci（）所做的。
	*/
	PyObject *result = NULL;
	long n;

	if(PyArg_ParseTuple(args,"l",&n)){	// "l"字符串意味着希望args只包含一个长正型值
		result = Py_BuildValue("L",fibonacci(unsigned int)n));
	}
	return result;
}

static char Fibonacci_doc[] = "Fibonacci(n):Return nth Fibonacci sequence number computer recursively
";
static PyMethodDef Fibonacci_module_methods[] = {
	/*
	char* ml_name :方法的名称
	PyCFunction :这是C实现功能的函数的指针
	int ml_falgs :这包括表明调用约定或绑定约定的标志。后者仅适用于类方法的定义
	char* mi_doc :指向方法/函数的docsing 的指针
	始终以表示其结束的哨兵值{NULL,NULL,0,NULL}结束
	*/
	{"Fibonacci",(PyCFunction)fibonacci_py,
	METH_VARARGS, Fibonacci_docs
	},
	{NULL,NULL,0,NULL}
};

static struct PymoduleDef Fibonacci_module_definition = {
	/*
	
	
	*/

	PyModuleDef_HEAD_INIT,
	"Fibonacci",
	"Extension module that provides Fibonacci sequence funciton",
	-1,
	Fibonacci_module_methods
};

PyMODINIT_FUNC PyInit_Fibonacci(void){
	/*
	初始化函数
	*/
	Py_Initialize();

	return PyModule_Create(&Fibonacci_module_definition);
}