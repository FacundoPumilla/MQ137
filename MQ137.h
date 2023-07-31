#ifndef MQ137_h
#define MQ137_h

#include "Arduino.h"

// AIR_CLEAR es la constante del aire limpio 
#define AIR_CLEAR 3.6

// RL es la resistencia colocada entre GND y Aout
#define MQ137_RL 47

// Cantidad de muestras en la obtencion de Ro
#define MQ137_CICLE_TEST 500

// Alimentacion del sensor MQ137
#define MQ137_VCC_BOARD_IN 5.0

// Maximo valor en entrada analogica
#define MQ137_MAX_ADC_VALUE 1023

/**
 * @brief Pendiente de la linea de NH3
*/
#define MQ137_SLOPE_NH3 -0.243
// slope = [log(y2) - log(y1)] / [log(x2) - log(x1)]
// slope = log(0.8/1) / log(100/40)
// slope = -0.243

/**
 * @brief Valor de punto de intercepcion 
*/
#define MQ137_MIDPOINT_NH3 0.323
// b = log(y) - m*log(x)
// b = log(0.75) - (-0.243)*log(70)
// b = 0.323

/**
 * @brief Construct a new MQ137::MQ137 object
 * 
 * @param mq137_pin entrada analogica de sensor MQ137
 * @param mq137_debug si true muestra valores de variables afectadas (false default)
 * @param _ro Constante R0
 */
class MQ137
{
    public:
        MQ137(uint8_t mq_pin, float _r0, bool mq137_debug);
        float getRo();
        float getPPM();
        void begin();
        float get_MQ137_R0();
    private:
        uint8_t MQ137_PIN;
        float MQ137_R0;
        bool mq137_debug;
        void mq137DebugPrint();
};

#endif

