#pragma once

#ifdef MODULE_ARITHMETIC_MEAN_ENABLED

#ifdef __cplusplus

#include <stdint.h>

class arithmeticMean {
public:
	arithmeticMean () {}

	void postVal ( float val ) {
		this->valCounter++;
		if ( valCounter == 1 ) {					// Фиксируем первый пришедший элемент.
			this->value = val;
			return;
		}
		this->value = (this->value * (this->valCounter - 1) + val) / ((float)this->valCounter);
	}

	float getMean ( void ) {
		return this->value;
	}

	float getAndReset () {
		this->valCounter = 0;
		return this->value;
	}

	void reset ( void ) {
		valCounter = 0;
	}

	void resetAndPostVal ( float val ) {
		this->reset();
		this->postVal( val );
	}

	uint32_t getCounter () {
		return valCounter;
	}

private:
	float				value				= 0;
	uint32_t			valCounter			= 0;
};

#endif

#endif
