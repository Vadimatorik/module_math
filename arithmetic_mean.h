#ifdef __cplusplus

#include <stdint.h>

class arithmetic_mean {
public:
    arithmetic_mean () {}

    void post_val ( float val ) {
        this->val_counter++;
        if ( val_counter == 1 ) {                    // Фиксируем первый пришедший элемент.
            this->value = val;
            return;
        }
        this->value = (this->value * (this->val_counter - 1) + val) / ((float)this->val_counter);
    }

    float get_mean ( void ) {
        return this->value;
    }

    float get_and_reset () {
        this->val_counter = 0;
        return this->value;
    }

    void reset ( void ) {
        val_counter = 0;
    }

    void reset_and_post_val ( float val ) {
        this->reset();
        this->post_val( val );
    }

    uint32_t get_counter () {
        return val_counter;
    }

private:
    float               value           = 0;
    uint32_t            val_counter     = 0;
};

#endif
