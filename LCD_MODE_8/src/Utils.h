#ifndef UTILS_H_
#define UTLIS_H_

//shift right and shift left
#define Rotate_Right(reg,no)               reg=(reg<<(8*sizeof(reg)-(no)))|(reg>>(no))
#define Rotate_Left(reg,no)               reg=(reg<<(no))|(reg>>(8*sizeof(reg)-(no)))


// Bit Operation

#define Clr_Bit(reg,bit_no)               reg&=(~(1<<bit_no))
#define Set_Bit(reg,bit_no)               reg|=(1<<bit_no)
#define Toggle_Bit(reg,bit_no)            reg^=(1<<bit_no)
#define Assign_Bit(reg,bit_no,value)      do{if(value==0) (reg&=(~(1<<bit_no))) ; \
                                          if(value==1) (reg|=(1<<bit_no));} while(0)
											  //(reg&=(~(1<<bit_no)))
										  //(reg|=(value<<bit_no))

// nibble low operation

#define Clr_Nibble_Low(reg)               reg&=0b11110000
#define Set_Nibble_Low(reg)               reg|=0b00001111
#define Toggle_Nibble_Low(reg)            reg^=0b00001111
/*#define Assign_Nibble_Low(reg,value)      do{if(value==0) reg&=0b11110000 ; \
                                          if(value==1) reg|=0b00001111;} while(0)*/
#define Assign_Nibble_Low(reg,value)      reg=((reg&(0b11110000))|value)

// nibble high operation

#define Clr_Nibble_High(reg)               reg&=0b00001111
#define Set_Nibble_High(reg)               reg|=0b11110000
#define Toggle_Nibble_High(reg)            reg^=0b11110000
/*#define Assign_Nibble_High(reg,value)      do{if(value==0) reg&=0b00001111 ; \
                                           if(value==1) reg|=0b11110000;} while(0)*/
#define Assign_Nibble_High(reg,value)      reg=(((reg&(0b00001111)))|(value*16))
                                           //reg=(((reg&(0b00001111)))|(value<<4))


#define Get_Bit(reg,bit_no)				 (reg&(1<<bit_no))>>bit_no
                                         //reg=(reg>>bit_no) & 1
#define Get_Nibble_High(reg)			(reg&(0b11110000))>>4
#define Get_Nibble_Low(reg)				 reg&(0b00001111)


#endif
//****************************************************




