
/*****************************************/
/* Name     : Nour Abdelaziz Mohamed     */
/* Date     : 25/11/2023                 */
/* Layer    : LIB                        */
/* Driver   : LIB "BIT_MATH "            */
/*****************************************/

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT)            (REG|=(1<<BIT))
#define CLR_BIT(REG,BIT)            (REG&=(~(1<<BIT)))
#define TGL_BIT(REG,BIT)            (REG^=(1<<BIT))
#define READ_BIT(REG,BIT)           ((REG>>BIT)&1)

#define SET_REG(REG)				(REG = 0XFF)
#define CLR_REG(REG)			    (REG = 0X00)
#define READ_REG(REG)				(REG = REG)


#define SET_HIGH_NIB(REG)			(REG |= 0XF0)
#define CLR_HIGH_NIB(REG)			(REG &= 0X0F)
//#define GET_HIGH_NIB(REG)
//#define TGL_HIGH_NIB(REG)

#define SET_LOW_NIB(REG)			(REG |= 0X0F)
#define CLR_LOW_NIB(REG)			(REG &= 0XF0)
#define WRITE_REG_VAL(REG , VALUE ) (REG |= VALUE)
//#define GET_LOW_NIB(REG)
//#define TGL_LOW_NIB(REG)

//#define ASSIGN_REG(REG,VALUE)
//#define ASSIGN_HIGH_NIB(REG,VALUE)
//#define ASSIGN_LOW_NIB(REG,VALUE)
//#define RSHFT_REG(REG, NO)
//#define LSHFT_REG(REG, NO)
//#define CRSHFT_REG(REG, NO)
//#define CLSHFT_REG(REG,NO)

/*Concatenation functions for port pins*/

#define CONCAT(b7,b6,b5,b4,b3,b2,b1,b0)    HELPER(b7,b6,b5,b4,b3,b2,b1,b0)
#define HELPER(b7,b6,b5,b4,b3,b2,b1,b0)    0b##b7##b6##b5##b4##b3##b2##b1##b0

#endif /* BIT_MATH_H_ */