#ifndef __TEST_OP_ASM__HEADER__
#define __TEST_OP_ASM__HEADER__

#define declareASMOP2i2(opName, op, opcode)\
template<typename T>\
inline void asmI32test##opName##2i2(int n, T* a, T* b)\
{\
	__asmblock \
			__gcode_g2g(xor, gcx, gcx)\
			"1:"\
			LoadL4(0, gsi, gcx, 4, eax)\
			LoadL4(0, gdi, gcx, 4, edx)\
			__gcode_e2e(opcode, edx, eax)\
			__gcode_e2e(opcode, edx, eax)\
			StoreL4(0, gdi, gcx, 4, eax)\
			__gcode_i2g(add, 1 , gcx)\
			__gcode_g2g(cmp, gbx, gcx)\
			"jne 1b;"\
			:\
			:"S"(b), "D"(a), "b"(n)\
			:"%eax", "%ecx", "%edx"\
		 __asmblockEnd ;\
}

declareASMOP2i2(Add, +, add);

#define declareASMOP2i3(opName, op, opcode)\
template<typename T>\
inline void asmI32test##opName##2i3(int n, T* a, T* b)\
{\
	__asm__(\
			__gcode_g2g(xor, gcx, gcx)\
			"1:"\
			LoadL4(0, gsi, gcx, 4, eax)\
			LoadL4(0, gdi, gcx, 4, edx)\
			__gcode_e2e(opcode, edx, eax)\
			__gcode_e2e(opcode, edx, eax)\
			__gcode_e2e(opcode, edx, eax)\
			StoreL4(0, gdi, gcx, 4, eax)\
			__gcode_i2g(add, 1 , gcx)\
			__gcode_g2g(cmp, gbx, gcx)\
			"jne 1b;"\
			:\
			:"S"(b), "D"(a), "b"(n)\
			:"%eax", "%ecx", "%edx"\
		   );\
}

declareASMOP2i3(Add, +, add);


#endif
