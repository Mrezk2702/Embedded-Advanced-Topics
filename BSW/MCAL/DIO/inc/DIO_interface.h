/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC:DIO_INTERFACE             *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

typedef enum {
	DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD
} Port_t;

typedef enum {
	DIO_Pin0,
	DIO_Pin1,
	DIO_Pin2,
	DIO_Pin3,
	DIO_Pin4,
	DIO_Pin5,
	DIO_Pin6,
	DIO_Pin7
} Pin_t;

typedef enum {
	DIO_INPUT, DIO_OUTPUT,
} Dir_t;

#define DIO_HIGH 1
#define DIO_LOW  0

typedef enum {
	DIO_ok,
    DIO_SetErr,
	DIO_GetErr,
	DIO_DirErr
} status_t;
/**
*@brief  setting the port value
*@param  Mc desired port
*@retval Error Status
*/
status_t DIO_SetPortVal(Port_t Copy_Port, uint8 Copy_uint8Value);

/**
*@brief  setting the port value
*@param  Mc desired port,desired pin
*@retval Error Status
*/
status_t DIO_SetPinVal(Port_t Copy_Port, Pin_t Copy_Pin, uint8 Copy_uint8Value);


/**
*@brief  setting the port Direction
*@param  Mc desired port
*@retval Error Status
*/
status_t DIO_SetPortDir(Port_t Copy_Port, uint8 Copy_uint8Direction);


/**
*@brief  setting the pin Direction
*@param  Mc desired port,desired pin
*@retval Error Status
*/
status_t DIO_SetPinDir(Port_t Copy_Port, Pin_t Copy_Pin, Dir_t Copy_Direction);


/**
*@brief  Getting the pin value
*@param  Mc desired port,desired pin, pointer to receive the value
*@retval Error Status
*/
status_t DIO_GetPinVal(Port_t Copy_Port, Pin_t Copy_Pin, uint8* Copy_pvValue);

/**
*@brief  Getting the Port value
*@param  Mc desired port, pointer to receive the value
*@retval Error Status
*/
status_t DIO_GetPortVal(Port_t Copy_Port,uint8* Copy_pvValue);



#endif /* DIO_INTERFACE_H_ */
