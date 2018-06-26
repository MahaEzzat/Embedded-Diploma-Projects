/*
 * DIO_Private.h
 *
 *  Created on: Jun 17, 2018
 *      Author: Maha
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#define DDRA *((volatile u8*)(0x3A))
#define PORTA *((volatile u8*)(0x3B))
#define PINA *((volatile u8*)(0x39))

#define DDRB *((volatile u8*)(0x37))
#define PORTB *((volatile u8*)(0x38))
#define PINB *((volatile u8*)(0x36))

#define DDRC *((volatile u8*)(0x34))
#define PORTC *((volatile u8*)(0x35))
#define PINC *((volatile u8*)(0x33))

#define DDRD *((volatile u8*)(0x31))
#define PORTD *((volatile u8*)(0x32))
#define PIND *((volatile u8*)(0x30))

#define PortA 0
#define PortB 1
#define PortC 2
#define PortD 3

#define Pin0 0
#define Pin1 1
#define Pin2 2
#define Pin3 3
#define Pin4 4
#define Pin5 5
#define Pin6 6
#define Pin7 7

#define Output 1
#define Input 0
#define Zero_Volt 0
#define Five_Volt 1

#endif /* DIO_PRIVATE_H_ */
