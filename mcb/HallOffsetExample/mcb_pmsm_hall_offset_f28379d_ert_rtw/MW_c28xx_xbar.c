#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "rtwtypes.h"
#include "mcb_pmsm_hall_offset_f28379d.h"
#include "mcb_pmsm_hall_offset_f28379d_private.h"
#include "MW_c28xGPIO.h"

void configureIXbar(void)
{
  /*--- Configuring GPIO set in Input Xbar---*/
  EALLOW;
  InputXbarRegs.INPUT7SELECT = 54;
  InputXbarRegs.INPUT8SELECT = 55;
  InputXbarRegs.INPUT9SELECT = 57;
  EDIS;
}
