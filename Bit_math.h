
// MATH.H

#define SET_BIT(var,bit_num) var|=(1<<bit_num)
#define CLEAR_BIT(var,bit_num) var&=~(1<<bit_num)
#define TOG_BIT(var,bit_num) var^=(1<<bit_num)
#define GET_BIT(var,bit_num) ((var>>bit_num)&1)
#define ASSIGN_BIT(var,bit_num,val) var=((var&(~(1<<bit_num)))|(val<<bit_num))