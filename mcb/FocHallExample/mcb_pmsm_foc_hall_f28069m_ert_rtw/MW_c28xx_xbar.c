#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "rtwtypes.h"
#include "mcb_pmsm_foc_hall_f28069m.h"
#include "mcb_pmsm_foc_hall_f28069m_private.h"
#include "MW_c28xGPIO.h"

void configureIXbar(void)
{
  /*--- Configuring GPIO set in Input Xbar---*/
  EALLOW;
  InputXbarRegs.INPUT7SELECT = 24;
  InputXbarRegs.INPUT8SELECT = 25;
  InputXbarRegs.INPUT9SELECT = 26;
  EDIS;
}
