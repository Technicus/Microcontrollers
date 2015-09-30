/* 
 * Interrupts.h
 * 
 * External interrupt control
 * 
 */

struct INTCON_{
	int RBIF:1;
	int INT0IF:1;
	int TMR0IF:1;
	int RBIE:1;
	int INT0IE:1;
	int TMR0IE:1;
	int PEIE:1;
	int GIE:1;
	};
struct INTCON_ *INTCON = REGISTER_INTCON;

struct INTCON_2{
	int RBIP:1;
	int UNIMPLEMENTED_0:1;
	int TMROIP:1;
	int UNIMPLEMENTED_1:1;
	int INTEDG2:1;
	int INTEDG1:1;
	int INTEDG0:1;
	int RBPU:1;
	};
struct INTCON_2 *INTCON2 = REGISTER_INTCON2;

struct INTCON_3{
	int INT1F:1;
	int INT2F:1;
	int UNIMPLEMENTED_0:1;
	int INT1E:1;
	int INT2E:1;
	int UNIMPLEMENTED_1:1;
	int INT1P:1;
	int INT2P:1;
	};
struct INTCON_3 *INTCON3 = REGISTER_INTCON3;
