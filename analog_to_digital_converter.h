
#define channel_3	0x03
#define channel_4	0x04
#define channel_5	0x05
#define channel_6	0x06

#define prescaler_2	0x00
#define prescaler_3	0x01
#define prescaler_4	0x02
#define prescaler_6	0x03
#define prescaler_8	0x04
#define prescaler_10	0x05
#define prescaler_12	0x06
#define prescaler_18	0x07

void adc_set_channel_and_prescaler(unsigned char channel_id,unsigned char prescaler_id)
{
	ADC_CSR = channel_id;
	ADC_CR1 = ( prescaler_id << 4 ) | 0x01;
	ADC_CR2 = ( 1 << ADC_CR2_ALIGN ); 
}

uint16_t read_adc_value()
{
	ADC_CR1 |= 0x01;
	while( !( ( ADC_CSR ) & ( 1 << ADC_CSR_EOC ) ) );
	ADC_CSR &= ~( 1 << ADC_CSR_EOC );
	return(ADC_DRL+(ADC_DRH<<8));
}