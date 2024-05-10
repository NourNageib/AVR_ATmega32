/*****************************************/
/* Name     : Nour Abdelaziz Mohamed     */
/* Date     : 25/11/2023                 */
/* Layer    : MCAL                       */
/* Driver   : DIO                        */
/*****************************************/


#ifndef AVR_REG_H_
#define AVR_REG_H_

/*PORT , DDR , PIN Registers addresses define*/

//PORTA Registers
#define MDIO_DDRA  (*((volatile uinit8_t*)0X3A))
#define MDIO_PORTA (*((volatile uinit8_t*)0X3B))
#define MDIO_PINA  (*((volatile uinit8_t*)0X39))

//PORTB Registers
#define MDIO_DDRB  (*((volatile uinit8_t*)0X37))
#define MDIO_PORTB (*((volatile uinit8_t*)0X38))
#define MDIO_PINB  (*((volatile uinit8_t*)0X36))

//PORTC Registers
#define MDIO_DDRC  (*((volatile uinit8_t*)0X34))
#define MDIO_PORTC (*((volatile uinit8_t*)0X35))
#define MDIO_PINC  (*((volatile uinit8_t*)0X33))

//PORTD Registers
#define MDIO_DDRD  (*((volatile uinit8_t*)0X31))
#define MDIO_PORTD (*((volatile uinit8_t*)0X32))
#define MDIO_PIND  (*((volatile uinit8_t*)0X30))

#define MDIO_SFIOR  (*(volatile uinit8_t*)0X50)







#endif