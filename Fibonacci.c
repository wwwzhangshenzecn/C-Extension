#include<Python.h>

long long fibonacci(n){
    
    if(n<2)
        return 1;
    else
        return fibonacci(n-2) + fibonacci(n-1);
}

static PyOnject* fibonacci_py(PyObject* self, PyObject* args){
	/*
	ǩ������ָ������Ĳ����б�ֻ��ָ��PyObject* args��������һ��ָ��ṹ���ָ�룬�ṹ���а���������Ԫ��
	�����б��ʵ����֤�����ں������ڲ�ִ�У���ʽFibonacci���������ġ�
	*/
	PyObject *result = NULL;
	long n;

	if(PyArg_ParseTuple(args,"l",&n)){	// "l"�ַ�����ζ��ϣ��argsֻ����һ��������ֵ
		result = Py_BuildValue("L",fibonacci(unsigned int)n));
	}
	return result;
}

static char Fibonacci_doc[] = "Fibonacci(n):Return nth Fibonacci sequence number computer recursively
";
static PyMethodDef Fibonacci_module_methods[] = {
	/*
	char* ml_name :����������
	PyCFunction :����Cʵ�ֹ��ܵĺ�����ָ��
	int ml_falgs :�������������Լ�����Լ���ı�־�����߽��������෽���Ķ���
	char* mi_doc :ָ�򷽷�/������docsing ��ָ��
	ʼ���Ա�ʾ��������ڱ�ֵ{NULL,NULL,0,NULL}����
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
	��ʼ������
	*/
	Py_Initialize();

	return PyModule_Create(&Fibonacci_module_definition);
}