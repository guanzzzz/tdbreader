namespace TDB {
       using namespace pf::materials;

       static void printerror(){
               cout << "Temperature, out of limit, thermodynamic calculation error!" << endl;
               SYS_PROGRAM_STOP;
       }
       static void printerror(double T) {
               cout << "Temperature, out of limit, thermodynamic calculation error!" << endl;
               SYS_PROGRAM_STOP;
       }
       const double R = 8.3144521;

       namespace ghser {
               static double GHSERAG (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T < 1234.93) {
                               val = -7209.512+118.202013*T-23.8463314*T*log(T)-.001790585*T*2-3.98587E-07*T*3-12011*T*pow(T,1)
                       }
                       else if (T >= 1234.93 && T <= 3000) {
                               val = -15095.252+190.266404*T-33.472*T*log(T)+1.411773E+29*T*pow(T,1)
                       }
                       return val;
               }
               static double GHSERBI (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T < 544.55) {
                               val = -7817.776+128.418925*T-28.4096529*T*log(T)+.012338888*T*2-8.381598E-06*T*3
                       }
                       else if (T >= 544.55 && T < 800) {
                               val = +30208.022-393.650351*T+51.8556592*T*log(T)-.075311163*T*2+1.3499885E-05*T*3-3616168*T*pow(T,1)+1.66145E+25*T*pow(T,2)
                       }
                       else if (T >= 800 && T < 1200) {
                               val = -11045.664+182.548971*T-35.9824*T*log(T)+.0074266*T*2-1.046E-06*T*3+1.66145E+25*T*pow(T,1)
                       }
                       else if (T >= 1200 && T <= 3000) {
                               val = -7581.312+124.77144*T-27.196*T*log(T)+1.66145E+25*T*pow(T,1)
                       }
                       return val;
               }
               static double GBIHEX (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 3000) {
                               val = +9900-11.8*T+GHSERBI#
                       }
                       return val;
               }
               static double GHSERSN (double T) {
                       double val = 0.0;
                       if (T < 100 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 100 && T < 250) {
                               val = -7958.517+122.765451*T-25.858*T*log(T)+5.1185E-04*T*2-3.192767E-06*T*3+18440*T*pow(T,1)
                       }
                       else if (T >= 250 && T < 505.08) {
                               val = -5855.135+65.443315*T-15.961*T*log(T)-.0188702*T*2+3.121167E-06*T*3-61960*T*pow(T,1)
                       }
                       else if (T >= 505.08 && T < 800) {
                               val = +2524.724+4.005269*T-8.2590486*T*log(T)-.016814429*T*2+2.623131E-06*T*3-1081244*T*pow(T,1)-1.2307E+25*T*pow(T,2)
                       }
                       else if (T >= 800 && T <= 3000) {
                               val = -8256.959+138.99688*T-28.4512*T*log(T)-1.2307E+25*T*pow(T,1)
                       }
                       return val;
               }
               static double GFCCSN (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T < 505.08) {
                               val = -345.135+56.983315*T-15.961*T*log(T)-.0188702*T*2+3.121167E-06*T*3-61960*T*pow(T,1)
                       }
                       else if (T >= 505.08 && T < 800) {
                               val = +8034.724-4.454731*T-8.2590486*T*log(T)-.016814429*T*2+2.623131E-06*T*3-1081244*T*pow(T,1)-1.2307E+25*T*pow(T,2)
                       }
                       else if (T >= 800 && T <= 3000) {
                               val = -2746.959+130.53688*T-28.4512*T*log(T)-1.2307E+25*T*pow(T,1)
                       }
                       return val;
               }
               static double UN_ASS (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 300) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 300) {
                               val = +0
                       }
                       return val;
               }
       }
       namespace SYS_AG_BI_SN {
               enum SUBLATTICES  _AG%_BI_SN_, _BI_SN_, _AG_BI_SN_, _AG_BI_SN%_, _AG_, _SN_, _BI_, _BI%_SN_, _VA_;
               
               /**********************************************************************
               PHASE AGSB_ORTHO
               **********************************************************************/
               static double G_AGSB_ORTHO_AG_AG_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 3000) {
                               val = +ghser::GHSERAG(T)#+5000
                       }
                       return val;
               }
               static double G_AGSB_ORTHO_AG_BI_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 3000) {
                               val = +.75*ghser::GHSERAG(T)#+.25*ghser::GHSERBI(T)#+5
                       }
                       return val;
               }
               static double G_AGSB_ORTHO_AG_SN_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = -11085.3+110.01471*T-23.18*T*log(T)-.00359*T*2+4389.5*T*pow(T,1)
                       }
                       return val;
               }
               static double G_AGSB_ORTHO_AG_AG_BI_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 3000) {
                               val = +0.0
                       }
                       return val;
               }
               static double G_AGSB_ORTHO_AG_AG_SN_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 3000) {
                               val = +0.0
                       }
                       return val;
               }
               static double G_AGSB_ORTHO_AG_BI_SN_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 3000) {
                               val = -500-.85*T
                       }
                       return val;
               }
               //---------------------------------------------------------------------
               //Gibbs Energy
               //---------------------------------------------------------------------
               static double G_AGSB_ORTHO(pf::SublatticeNode& y, double T, double P) {
                       double y1AG = y[_AG_][AG].value;
                       double y2AG = y[_AG_BI_SN_][AG].value;
                       double y2BI = y[_AG_BI_SN_][BI].value;
                       double y2SN = y[_AG_BI_SN_][SN].value;
                       double val = G_AGSB_ORTHO_AG_AG_0(T)*y1AG*y2AG+G_AGSB_ORTHO_AG_BI_0(T)*y1AG*y2BI+G_AGSB_ORTHO_AG_SN_0(T)*y1AG*y2SN+G_AGSB_ORTHO_AG_AG_BI_0(T)*y1AG*y2AG*y2BI+G_AGSB_ORTHO_AG_AG_SN_0(T)*y1AG*y2AG*y2SN+G_AGSB_ORTHO_AG_BI_SN_0(T)*y1AG*y2BI*y2SN+0.75*R*T*y1AG*log(y1AG)+0.25*R*T*(y2AG*log(y2AG)+y2BI*log(y2BI)+y2SN*log(y2SN))
                       return val;
               }
               //---------------------------------------------------------------------
               //A first order partial derivatives
               //---------------------------------------------------------------------
               static double dG_AGSB_ORTHO_dAG1(pf::SublatticeNode& y, double T, double P) { 
                       double y1AG = y[_AG_][AG].value;
                       double y2AG = y[_AG_BI_SN_][AG].value;
                       double y2BI = y[_AG_BI_SN_][BI].value;
                       double y2SN = y[_AG_BI_SN_][SN].value;
                       double val = G_AGSB_ORTHO_AG_AG_0(T)*y2AG*1+G_AGSB_ORTHO_AG_BI_0(T)*y2BI*1+G_AGSB_ORTHO_AG_SN_0(T)*y2SN*1+G_AGSB_ORTHO_AG_AG_BI_0(T)*y2AG*y2BI*1+G_AGSB_ORTHO_AG_AG_SN_0(T)*y2AG*y2SN*1+G_AGSB_ORTHO_AG_BI_SN_0(T)*y2BI*y2SN*1+1+log(y1AG)+0+0.75*R*T*(1+log(y1AG))+0.25*R*T*(0)
                       return val;
               } 
               static double dG_AGSB_ORTHO_dAG2(pf::SublatticeNode& y, double T, double P) { 
                       double y1AG = y[_AG_][AG].value;
                       double y2AG = y[_AG_BI_SN_][AG].value;
                       double y2BI = y[_AG_BI_SN_][BI].value;
                       double y2SN = y[_AG_BI_SN_][SN].value;
                       double val = G_AGSB_ORTHO_AG_AG_0(T)*y1AG*1+G_AGSB_ORTHO_AG_AG_BI_0(T)*y1AG*y2BI*1+G_AGSB_ORTHO_AG_AG_SN_0(T)*y1AG*y2SN*1+0+1+log(y2AG)+0.75*R*T*(0)+0.25*R*T*(1+log(y2AG))
                       return val;
               } 
               static double dG_AGSB_ORTHO_dBI2(pf::SublatticeNode& y, double T, double P) { 
                       double y1AG = y[_AG_][AG].value;
                       double y2AG = y[_AG_BI_SN_][AG].value;
                       double y2BI = y[_AG_BI_SN_][BI].value;
                       double y2SN = y[_AG_BI_SN_][SN].value;
                       double val = G_AGSB_ORTHO_AG_BI_0(T)*y1AG*1+G_AGSB_ORTHO_AG_AG_BI_0(T)*y1AG*y2AG*1+G_AGSB_ORTHO_AG_BI_SN_0(T)*y1AG*y2SN*1+0+1+log(y2BI)+0.75*R*T*(0)+0.25*R*T*(1+log(y2BI))
                       return val;
               } 
               static double dG_AGSB_ORTHO_dSN2(pf::SublatticeNode& y, double T, double P) { 
                       double y1AG = y[_AG_][AG].value;
                       double y2AG = y[_AG_BI_SN_][AG].value;
                       double y2BI = y[_AG_BI_SN_][BI].value;
                       double y2SN = y[_AG_BI_SN_][SN].value;
                       double val = G_AGSB_ORTHO_AG_SN_0(T)*y1AG*1+G_AGSB_ORTHO_AG_AG_SN_0(T)*y1AG*y2AG*1+G_AGSB_ORTHO_AG_BI_SN_0(T)*y1AG*y2BI*1+0+1+log(y2SN)+0.75*R*T*(0)+0.25*R*T*(1+log(y2SN))
                       return val;
               } 
               //---------------------------------------------------------------------
               //A Second order partial derivatives
               //---------------------------------------------------------------------
               static double dG_AGSB_ORTHO_dAGdAG((pf::SublatticeNode& y, double T, double P) { 
                       double y1AG = y[_AG_][AG].value;
                       double y2AG = y[_AG_BI_SN_][AG].value;
                       double y2BI = y[_AG_BI_SN_][BI].value;
                       double y2SN = y[_AG_BI_SN_][SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_AGSB_ORTHO_dAGdBI((pf::SublatticeNode& y, double T, double P) { 
                       double y1AG = y[_AG_][AG].value;
                       double y2AG = y[_AG_BI_SN_][AG].value;
                       double y2BI = y[_AG_BI_SN_][BI].value;
                       double y2SN = y[_AG_BI_SN_][SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_AGSB_ORTHO_dAGdSN((pf::SublatticeNode& y, double T, double P) { 
                       double y1AG = y[_AG_][AG].value;
                       double y2AG = y[_AG_BI_SN_][AG].value;
                       double y2BI = y[_AG_BI_SN_][BI].value;
                       double y2SN = y[_AG_BI_SN_][SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_AGSB_ORTHO_dAGdAG((pf::SublatticeNode& y, double T, double P) { 
                       double y1AG = y[_AG_][AG].value;
                       double y2AG = y[_AG_BI_SN_][AG].value;
                       double y2BI = y[_AG_BI_SN_][BI].value;
                       double y2SN = y[_AG_BI_SN_][SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_AGSB_ORTHO_dAGdBI((pf::SublatticeNode& y, double T, double P) { 
                       double y1AG = y[_AG_][AG].value;
                       double y2AG = y[_AG_BI_SN_][AG].value;
                       double y2BI = y[_AG_BI_SN_][BI].value;
                       double y2SN = y[_AG_BI_SN_][SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_AGSB_ORTHO_dAGdSN((pf::SublatticeNode& y, double T, double P) { 
                       double y1AG = y[_AG_][AG].value;
                       double y2AG = y[_AG_BI_SN_][AG].value;
                       double y2BI = y[_AG_BI_SN_][BI].value;
                       double y2SN = y[_AG_BI_SN_][SN].value;
                       double val = 0.0;
                       return val;
               } 

               /**********************************************************************
               PHASE AU2BI_C15
               **********************************************************************/
               static double G_AU2BI_C15_AG_BI_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = +2*ghser::GHSERAG(T)#+ghser::GHSERBI(T)
                       }
                       return val;
               }
               //---------------------------------------------------------------------
               //Gibbs Energy
               //---------------------------------------------------------------------
               static double G_AU2BI_C15(pf::SublatticeNode& y, double T, double P) {
                       double y1AG = y[_AG_][AG].value;
                       double y2BI = y[_BI_][BI].value;
                       double val = G_AU2BI_C15_AG_BI_0(T)*y1AG*y2BI+0.6666666666666666*R*T*y1AG*log(y1AG)+0.3333333333333333*R*T*y2BI*log(y2BI)
                       return val;
               }
               //---------------------------------------------------------------------
               //A first order partial derivatives
               //---------------------------------------------------------------------
               static double dG_AU2BI_C15_dAG1(pf::SublatticeNode& y, double T, double P) { 
                       double y1AG = y[_AG_][AG].value;
                       double y2BI = y[_BI_][BI].value;
                       double val = G_AU2BI_C15_AG_BI_0(T)*y2BI*1+1+log(y1AG)+0+0.6666666666666666*R*T*(1+log(y1AG))+0.3333333333333333*R*T*(0)
                       return val;
               } 
               static double dG_AU2BI_C15_dBI2(pf::SublatticeNode& y, double T, double P) { 
                       double y1AG = y[_AG_][AG].value;
                       double y2BI = y[_BI_][BI].value;
                       double val = G_AU2BI_C15_AG_BI_0(T)*y1AG*1+0+1+log(y2BI)+0.6666666666666666*R*T*(0)+0.3333333333333333*R*T*(1+log(y2BI))
                       return val;
               } 
               //---------------------------------------------------------------------
               //A Second order partial derivatives
               //---------------------------------------------------------------------
               static double dG_AU2BI_C15_dAGdBI((pf::SublatticeNode& y, double T, double P) { 
                       double y1AG = y[_AG_][AG].value;
                       double y2BI = y[_BI_][BI].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_AU2BI_C15_dAGdBI((pf::SublatticeNode& y, double T, double P) { 
                       double y1AG = y[_AG_][AG].value;
                       double y2BI = y[_BI_][BI].value;
                       double val = 0.0;
                       return val;
               } 

               /**********************************************************************
               PHASE AUSB2
               **********************************************************************/
               static double G_AUSB2_AG_BI_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = +0.0
                       }
                       return val;
               }
               //---------------------------------------------------------------------
               //Gibbs Energy
               //---------------------------------------------------------------------
               static double G_AUSB2(pf::SublatticeNode& y, double T, double P) {
                       double y1AG = y[_AG_][AG].value;
                       double y2BI = y[_BI_][BI].value;
                       double val = G_AUSB2_AG_BI_0(T)*y1AG*y2BI+0.333333*R*T*y1AG*log(y1AG)+0.666667*R*T*y2BI*log(y2BI)
                       return val;
               }
               //---------------------------------------------------------------------
               //A first order partial derivatives
               //---------------------------------------------------------------------
               static double dG_AUSB2_dAG1(pf::SublatticeNode& y, double T, double P) { 
                       double y1AG = y[_AG_][AG].value;
                       double y2BI = y[_BI_][BI].value;
                       double val = G_AUSB2_AG_BI_0(T)*y2BI*1+1+log(y1AG)+0+0.333333*R*T*(1+log(y1AG))+0.666667*R*T*(0)
                       return val;
               } 
               static double dG_AUSB2_dBI2(pf::SublatticeNode& y, double T, double P) { 
                       double y1AG = y[_AG_][AG].value;
                       double y2BI = y[_BI_][BI].value;
                       double val = G_AUSB2_AG_BI_0(T)*y1AG*1+0+1+log(y2BI)+0.333333*R*T*(0)+0.666667*R*T*(1+log(y2BI))
                       return val;
               } 
               //---------------------------------------------------------------------
               //A Second order partial derivatives
               //---------------------------------------------------------------------
               static double dG_AUSB2_dAGdBI((pf::SublatticeNode& y, double T, double P) { 
                       double y1AG = y[_AG_][AG].value;
                       double y2BI = y[_BI_][BI].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_AUSB2_dAGdBI((pf::SublatticeNode& y, double T, double P) { 
                       double y1AG = y[_AG_][AG].value;
                       double y2BI = y[_BI_][BI].value;
                       double val = 0.0;
                       return val;
               } 

               /**********************************************************************
               PHASE BCC_A2
               **********************************************************************/
               static double G_BCC_A2_AG_VA_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T < 1234.93) {
                               val = -3809.512+117.152013*T-23.8463314*T*log(T)-.001790585*T*2-3.98587E-07*T*3-12011*T*pow(T,1)
                       }
                       else if (T >= 1234.93 && T <= 3000) {
                               val = -11695.252+189.216404*T-33.472*T*log(T)+1.411773E+29*T*pow(T,1)
                       }
                       return val;
               }
               static double G_BCC_A2_BI_VA_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T < 544.55) {
                               val = +3479.224+114.518925*T-28.4096529*T*log(T)+.012338888*T*2-8.381598E-06*T*3
                       }
                       else if (T >= 544.55 && T < 800) {
                               val = +41505.022-407.550351*T+51.8556592*T*log(T)-.075311163*T*2+1.3499885E-05*T*3-3616168*T*pow(T,1)+1.66145E+25*T*pow(T,2)
                       }
                       else if (T >= 800 && T < 1200) {
                               val = +251.336+168.648971*T-35.9824*T*log(T)+.0074266*T*2-1.046E-06*T*3+1.66145E+25*T*pow(T,1)
                       }
                       else if (T >= 1200 && T <= 3000) {
                               val = +3715.688+110.87144*T-27.196*T*log(T)+1.66145E+25*T*pow(T,1)
                       }
                       return val;
               }
               static double G_BCC_A2_SN_VA_0 (double T) {
                       double val = 0.0;
                       if (T < 100 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 100 && T < 250) {
                               val = -3558.517+116.765451*T-25.858*T*log(T)+5.1185E-04*T*2-3.192767E-06*T*3+18440*T*pow(T,1)
                       }
                       else if (T >= 250 && T < 505.08) {
                               val = -1455.135+59.443315*T-15.961*T*log(T)-.0188702*T*2+3.121167E-06*T*3-61960*T*pow(T,1)
                       }
                       else if (T >= 505.08 && T < 800) {
                               val = +6924.724-1.994731*T-8.2590486*T*log(T)-.016814429*T*2+2.623131E-06*T*3-1081244*T*pow(T,1)-1.2307E+25*T*pow(T,2)
                       }
                       else if (T >= 800 && T <= 3000) {
                               val = -3856.959+132.99688*T-28.4512*T*log(T)-1.2307E+25*T*pow(T,1)
                       }
                       return val;
               }
               static double G_BCC_A2_AG_BI_VA_0 (double T) {
                       double val = 0.0;
                       if (T < 270 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 270 && T <= 3000) {
                               val = +25077.78-12.05475*T
                       }
                       return val;
               }
               static double G_BCC_A2_AG_SN_VA_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = +7000
                       }
                       return val;
               }
               static double G_BCC_A2_BI_SN_VA_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 1000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 1000) {
                               val = +2000
                       }
                       return val;
               }
               //---------------------------------------------------------------------
               //Gibbs Energy
               //---------------------------------------------------------------------
               static double G_BCC_A2(pf::ConNode& x, double T, double P) {
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_BCC_A2_AG_VA_0(T)*xAG+G_BCC_A2_BI_VA_0(T)*xBI+G_BCC_A2_SN_VA_0(T)*xSN+G_BCC_A2_AG_BI_VA_0(T)*xAG*xBI+G_BCC_A2_AG_SN_VA_0(T)*xAG*xSN+G_BCC_A2_BI_SN_VA_0(T)*xBI*xSN+R*T*(xAG*log(xAG)+xBI*log(xBI)+xSN*log(xSN))
                       return val;
               }
               //---------------------------------------------------------------------
               //A first order partial derivatives
               //---------------------------------------------------------------------
               static double dG_BCC_A2_d_AG(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_BCC_A2_AG_VA_0(T)*xAG+G_BCC_A2_BI_VA_0(T)*xBI+G_BCC_A2_SN_VA_0(T)*xSN+G_BCC_A2_AG_BI_VA_0(T)*xAG*xBI+G_BCC_A2_AG_SN_VA_0(T)*xAG*xSN+G_BCC_A2_BI_SN_VA_0(T)*xBI*xSN+G_BCC_A2_AG_VA_0(T)*1+G_BCC_A2_AG_BI_VA_0(T)*xAG*xBI+G_BCC_A2_AG_SN_VA_0(T)*xAG*xSN+R*T*(1+log(xAG))
                       return val;
               } 
               static double dG_BCC_A2_d_BI(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_BCC_A2_AG_VA_0(T)*xAG+G_BCC_A2_BI_VA_0(T)*xBI+G_BCC_A2_SN_VA_0(T)*xSN+G_BCC_A2_AG_BI_VA_0(T)*xAG*xBI+G_BCC_A2_AG_SN_VA_0(T)*xAG*xSN+G_BCC_A2_BI_SN_VA_0(T)*xBI*xSN+G_BCC_A2_AG_VA_0(T)*1+G_BCC_A2_AG_BI_VA_0(T)*xAG*xBI+G_BCC_A2_AG_SN_VA_0(T)*xAG*xSNG_BCC_A2_BI_VA_0(T)*1+G_BCC_A2_AG_BI_VA_0(T)*xAG*xBI+G_BCC_A2_BI_SN_VA_0(T)*xBI*xSN+R*T*(1+log(xBI))
                       return val;
               } 
               static double dG_BCC_A2_d_SN(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_BCC_A2_AG_VA_0(T)*xAG+G_BCC_A2_BI_VA_0(T)*xBI+G_BCC_A2_SN_VA_0(T)*xSN+G_BCC_A2_AG_BI_VA_0(T)*xAG*xBI+G_BCC_A2_AG_SN_VA_0(T)*xAG*xSN+G_BCC_A2_BI_SN_VA_0(T)*xBI*xSN+G_BCC_A2_AG_VA_0(T)*1+G_BCC_A2_AG_BI_VA_0(T)*xAG*xBI+G_BCC_A2_AG_SN_VA_0(T)*xAG*xSNG_BCC_A2_BI_VA_0(T)*1+G_BCC_A2_AG_BI_VA_0(T)*xAG*xBI+G_BCC_A2_BI_SN_VA_0(T)*xBI*xSNG_BCC_A2_SN_VA_0(T)*1+G_BCC_A2_AG_SN_VA_0(T)*xAG*xSN+G_BCC_A2_BI_SN_VA_0(T)*xBI*xSN+R*T*(1+log(xSN))
                       return val;
               } 
               //---------------------------------------------------------------------
               //A Second order partial derivatives
               //---------------------------------------------------------------------
               static double dG_BCC_A2_dAGdAG(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_BCC_A2_dAGdBI(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_BCC_A2_dAGdSN(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_BCC_A2_dBIdAG(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_BCC_A2_dBIdBI(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_BCC_A2_dBIdSN(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_BCC_A2_dSNdAG(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_BCC_A2_dSNdBI(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_BCC_A2_dSNdSN(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 

               /**********************************************************************
               PHASE BCC_B2
               **********************************************************************/
               static double G_BCC_B2_AG_VA_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = +0.0
                       }
                       return val;
               }
               //---------------------------------------------------------------------
               //Gibbs Energy
               //---------------------------------------------------------------------
               static double G_BCC_B2(pf::ConNode& x, double T, double P) {
                       double xAG = x[AG].value;
                       double val = G_BCC_B2_AG_VA_0(T)*xAG+R*T*(xAG*log(xAG))
                       return val;
               }
               //---------------------------------------------------------------------
               //A first order partial derivatives
               //---------------------------------------------------------------------
               static double dG_BCC_B2_d_AG(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double val = G_BCC_B2_AG_VA_0(T)*xAG+G_BCC_B2_AG_VA_0(T)*1+R*T*(1+log(xAG))
                       return val;
               } 
               //---------------------------------------------------------------------
               //A Second order partial derivatives
               //---------------------------------------------------------------------
               static double dG_BCC_B2_dAGdAG(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double val = 0.0;
                       return val;
               } 

               /**********************************************************************
               PHASE BCT_A5
               **********************************************************************/
               static double G_BCT_A5_AG_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T < 1234.93) {
                               val = -3025.412+118.202013*T-23.8463314*T*log(T)-.001790585*T*2-3.98587E-07*T*3-12011*T*pow(T,1)
                       }
                       else if (T >= 1234.93 && T <= 3000) {
                               val = -10911.152+190.266404*T-33.472*T*log(T)+1.411773E+29*T*pow(T,1)
                       }
                       return val;
               }
               static double G_BCT_A5_BI_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T < 544.55) {
                               val = -3633.706+128.418925*T-28.4096529*T*log(T)+.012338888*T*2-8.381598E-06*T*3
                       }
                       else if (T >= 544.55 && T < 800) {
                               val = +34392.092-393.650351*T+51.8556592*T*log(T)-.075311163*T*2+1.3499885E-05*T*3-3616168*T*pow(T,1)+1.66145E+25*T*pow(T,2)
                       }
                       else if (T >= 800 && T < 1200) {
                               val = -6861.594+182.548971*T-35.9824*T*log(T)+.0074266*T*2-1.046E-06*T*3+1.66145E+25*T*pow(T,1)
                       }
                       else if (T >= 1200 && T <= 3000) {
                               val = -3397.242+124.77144*T-27.196*T*log(T)+1.66145E+25*T*pow(T,1)
                       }
                       return val;
               }
               static double G_BCT_A5_SN_0 (double T) {
                       double val = 0.0;
                       if (T < 100 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 100 && T < 250) {
                               val = -7958.517+122.765451*T-25.858*T*log(T)+5.1185E-04*T*2-3.192767E-06*T*3+18440*T*pow(T,1)
                       }
                       else if (T >= 250 && T < 505.08) {
                               val = -5855.135+65.443315*T-15.961*T*log(T)-.0188702*T*2+3.121167E-06*T*3-61960*T*pow(T,1)
                       }
                       else if (T >= 505.08 && T < 800) {
                               val = +2524.724+4.005269*T-8.2590486*T*log(T)-.016814429*T*2+2.623131E-06*T*3-1081244*T*pow(T,1)-1.2307E+25*T*pow(T,2)
                       }
                       else if (T >= 800 && T <= 3000) {
                               val = -8256.959+138.99688*T-28.4512*T*log(T)-1.2307E+25*T*pow(T,1)
                       }
                       return val;
               }
               static double G_BCT_A5_AG_BI_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 1000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 1000) {
                               val = +25077.78-12.05475*T
                       }
                       return val;
               }
               static double G_BCT_A5_AG_SN_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = +18358.8
                       }
                       return val;
               }
               static double G_BCT_A5_BI_SN_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 3000) {
                               val = +3500-1.038*T
                       }
                       return val;
               }
               static double G_BCT_A5_BI_SN_1 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 3000) {
                               val = -3710
                       }
                       return val;
               }
               //---------------------------------------------------------------------
               //Gibbs Energy
               //---------------------------------------------------------------------
               static double G_BCT_A5(pf::ConNode& x, double T, double P) {
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_BCT_A5_AG_0(T)*xAG+G_BCT_A5_BI_0(T)*xBI+G_BCT_A5_SN_0(T)*xSN+G_BCT_A5_AG_BI_0(T)*xAG*xBI+G_BCT_A5_AG_SN_0(T)*xAG*xSN+G_BCT_A5_BI_SN_0(T)*xBI*xSN+G_BCT_A5_BI_SN_1(T)*(xBI-xSN)*xBI*xSN+R*T*(xAG*log(xAG)+xBI*log(xBI)+xSN*log(xSN))
                       return val;
               }
               //---------------------------------------------------------------------
               //A first order partial derivatives
               //---------------------------------------------------------------------
               static double dG_BCT_A5_d_AG(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_BCT_A5_AG_0(T)*xAG+G_BCT_A5_BI_0(T)*xBI+G_BCT_A5_SN_0(T)*xSN+G_BCT_A5_AG_BI_0(T)*xAG*xBI+G_BCT_A5_AG_SN_0(T)*xAG*xSN+G_BCT_A5_BI_SN_0(T)*xBI*xSN+G_BCT_A5_BI_SN_1(T)*(xBI-xSN)*xBI*xSN+G_BCT_A5_AG_0(T)*1+G_BCT_A5_AG_BI_0(T)*xAG*xBI+G_BCT_A5_AG_SN_0(T)*xAG*xSN+R*T*(1+log(xAG))
                       return val;
               } 
               static double dG_BCT_A5_d_BI(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_BCT_A5_AG_0(T)*xAG+G_BCT_A5_BI_0(T)*xBI+G_BCT_A5_SN_0(T)*xSN+G_BCT_A5_AG_BI_0(T)*xAG*xBI+G_BCT_A5_AG_SN_0(T)*xAG*xSN+G_BCT_A5_BI_SN_0(T)*xBI*xSN+G_BCT_A5_BI_SN_1(T)*(xBI-xSN)*xBI*xSN+G_BCT_A5_AG_0(T)*1+G_BCT_A5_AG_BI_0(T)*xAG*xBI+G_BCT_A5_AG_SN_0(T)*xAG*xSNG_BCT_A5_BI_0(T)*1+G_BCT_A5_AG_BI_0(T)*xAG*xBI+G_BCT_A5_BI_SN_0(T)*xBI*xSN+R*T*(1+log(xBI))
                       return val;
               } 
               static double dG_BCT_A5_d_SN(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_BCT_A5_AG_0(T)*xAG+G_BCT_A5_BI_0(T)*xBI+G_BCT_A5_SN_0(T)*xSN+G_BCT_A5_AG_BI_0(T)*xAG*xBI+G_BCT_A5_AG_SN_0(T)*xAG*xSN+G_BCT_A5_BI_SN_0(T)*xBI*xSN+G_BCT_A5_BI_SN_1(T)*(xBI-xSN)*xBI*xSN+G_BCT_A5_AG_0(T)*1+G_BCT_A5_AG_BI_0(T)*xAG*xBI+G_BCT_A5_AG_SN_0(T)*xAG*xSNG_BCT_A5_BI_0(T)*1+G_BCT_A5_AG_BI_0(T)*xAG*xBI+G_BCT_A5_BI_SN_0(T)*xBI*xSNG_BCT_A5_SN_0(T)*1+G_BCT_A5_AG_SN_0(T)*xAG*xSN+G_BCT_A5_BI_SN_0(T)*xBI*xSN+R*T*(1+log(xSN))
                       return val;
               } 
               //---------------------------------------------------------------------
               //A Second order partial derivatives
               //---------------------------------------------------------------------
               static double dG_BCT_A5_dAGdAG(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_BCT_A5_dAGdBI(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_BCT_A5_dAGdSN%(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_BCT_A5_dBIdAG(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_BCT_A5_dBIdBI(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_BCT_A5_dBIdSN%(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_BCT_A5_dSN%dAG(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_BCT_A5_dSN%dBI(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_BCT_A5_dSN%dSN%(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 

               /**********************************************************************
               PHASE BI3PD5
               **********************************************************************/
               static double G_BI3PD5_BI_VA_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 4000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 4000) {
                               val = +ghser::GHSERBI(T)#+31000
                       }
                       return val;
               }
               //---------------------------------------------------------------------
               //Gibbs Energy
               //---------------------------------------------------------------------
               static double G_BI3PD5(pf::ConNode& x, double T, double P) {
                       double xBI = x[BI].value;
                       double val = G_BI3PD5_BI_VA_0(T)*xBI+R*T*(xBI*log(xBI))
                       return val;
               }
               //---------------------------------------------------------------------
               //A first order partial derivatives
               //---------------------------------------------------------------------
               static double dG_BI3PD5_d_BI(pf::ConNode& x, double T, double P) { 
                       double xBI = x[BI].value;
                       double val = G_BI3PD5_BI_VA_0(T)*xBI+G_BI3PD5_BI_VA_0(T)*1+R*T*(1+log(xBI))
                       return val;
               } 
               //---------------------------------------------------------------------
               //A Second order partial derivatives
               //---------------------------------------------------------------------
               static double dG_BI3PD5_dBIdBI(pf::ConNode& x, double T, double P) { 
                       double xBI = x[BI].value;
                       double val = 0.0;
                       return val;
               } 

               /**********************************************************************
               PHASE BINI
               **********************************************************************/
               static double G_BINI_BI_VA_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 3000) {
                               val = -4983+15.252*T-2.0967E-06*T*3+.5*ghser::GBIHEX(T)
                       }
                       return val;
               }
               //---------------------------------------------------------------------
               //Gibbs Energy
               //---------------------------------------------------------------------
               static double G_BINI(pf::ConNode& x, double T, double P) {
                       double xBI = x[BI].value;
                       double val = G_BINI_BI_VA_0(T)*xBI+R*T*(xBI*log(xBI))
                       return val;
               }
               //---------------------------------------------------------------------
               //A first order partial derivatives
               //---------------------------------------------------------------------
               static double dG_BINI_d_BI(pf::ConNode& x, double T, double P) { 
                       double xBI = x[BI].value;
                       double val = G_BINI_BI_VA_0(T)*xBI+G_BINI_BI_VA_0(T)*1+R*T*(1+log(xBI))
                       return val;
               } 
               //---------------------------------------------------------------------
               //A Second order partial derivatives
               //---------------------------------------------------------------------
               static double dG_BINI_dBIdBI(pf::ConNode& x, double T, double P) { 
                       double xBI = x[BI].value;
                       double val = 0.0;
                       return val;
               } 

               /**********************************************************************
               PHASE CUB_A13
               **********************************************************************/
               static double G_CUB_A13_AG_VA_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T < 1234.93) {
                               val = -3809.512+117.152013*T-23.8463314*T*log(T)-.001790585*T*2-3.98587E-07*T*3-12011*T*pow(T,1)
                       }
                       else if (T >= 1234.93 && T <= 3000) {
                               val = -11695.252+189.216404*T-33.472*T*log(T)+1.411773E+29*T*pow(T,1)
                       }
                       return val;
               }
               //---------------------------------------------------------------------
               //Gibbs Energy
               //---------------------------------------------------------------------
               static double G_CUB_A13(pf::ConNode& x, double T, double P) {
                       double xAG = x[AG].value;
                       double val = G_CUB_A13_AG_VA_0(T)*xAG+R*T*(xAG*log(xAG))
                       return val;
               }
               //---------------------------------------------------------------------
               //A first order partial derivatives
               //---------------------------------------------------------------------
               static double dG_CUB_A13_d_AG(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double val = G_CUB_A13_AG_VA_0(T)*xAG+G_CUB_A13_AG_VA_0(T)*1+R*T*(1+log(xAG))
                       return val;
               } 
               //---------------------------------------------------------------------
               //A Second order partial derivatives
               //---------------------------------------------------------------------
               static double dG_CUB_A13_dAGdAG(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double val = 0.0;
                       return val;
               } 

               /**********************************************************************
               PHASE CUIN_GAMMA
               **********************************************************************/
               static double G_CUIN_GAMMA_AG_AG_SN_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = +0.0
                       }
                       return val;
               }
               //---------------------------------------------------------------------
               //Gibbs Energy
               //---------------------------------------------------------------------
               //---------------------------------------------------------------------
               //PHASE CUIN_GAMMA with sublattice3
               //---------------------------------------------------------------------






               /**********************************************************************
               PHASE DHCP
               **********************************************************************/
               static double G_DHCP_SN_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = +ghser::GHSERSN(T)#+3803.52-3.46*T
                       }
                       return val;
               }
               //---------------------------------------------------------------------
               //Gibbs Energy
               //---------------------------------------------------------------------
               static double G_DHCP(pf::ConNode& x, double T, double P) {
                       double xSN = x[SN].value;
                       double val = G_DHCP_SN_0(T)*xSN+R*T*(xSN*log(xSN))
                       return val;
               }
               //---------------------------------------------------------------------
               //A first order partial derivatives
               //---------------------------------------------------------------------
               static double dG_DHCP_d_SN(pf::ConNode& x, double T, double P) { 
                       double xSN = x[SN].value;
                       double val = G_DHCP_SN_0(T)*xSN+G_DHCP_SN_0(T)*1+R*T*(1+log(xSN))
                       return val;
               } 
               //---------------------------------------------------------------------
               //A Second order partial derivatives
               //---------------------------------------------------------------------
               static double dG_DHCP_dSNdSN(pf::ConNode& x, double T, double P) { 
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 

               /**********************************************************************
               PHASE DIAMOND_A4
               **********************************************************************/
               static double G_DIAMOND_A4_SN_0 (double T) {
                       double val = 0.0;
                       if (T < 100 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 100 && T < 298.15) {
                               val = -9579.608+114.007785*T-22.972*T*log(T)-.00813975*T*2+2.7288E-06*T*3+25615*T*pow(T,1)
                       }
                       else if (T >= 298.15 && T < 800) {
                               val = -9063.001+104.84654*T-21.5750771*T*log(T)-.008575282*T*2+1.784447E-06*T*3-2544*T*pow(T,1)
                       }
                       else if (T >= 800 && T <= 3000) {
                               val = -10909.351+147.396535*T-28.4512*T*log(T)
                       }
                       return val;
               }
               //---------------------------------------------------------------------
               //Gibbs Energy
               //---------------------------------------------------------------------
               static double G_DIAMOND_A4(pf::ConNode& x, double T, double P) {
                       double xSN = x[SN].value;
                       double val = G_DIAMOND_A4_SN_0(T)*xSN+R*T*(xSN*log(xSN))
                       return val;
               }
               //---------------------------------------------------------------------
               //A first order partial derivatives
               //---------------------------------------------------------------------
               static double dG_DIAMOND_A4_d_SN(pf::ConNode& x, double T, double P) { 
                       double xSN = x[SN].value;
                       double val = G_DIAMOND_A4_SN_0(T)*xSN+G_DIAMOND_A4_SN_0(T)*1+R*T*(1+log(xSN))
                       return val;
               } 
               //---------------------------------------------------------------------
               //A Second order partial derivatives
               //---------------------------------------------------------------------
               static double dG_DIAMOND_A4_dSNdSN(pf::ConNode& x, double T, double P) { 
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 

               /**********************************************************************
               PHASE FCC_A1
               **********************************************************************/
               static double G_FCC_A1_AG_VA_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T < 1234.93) {
                               val = -7209.512+118.202013*T-23.8463314*T*log(T)-.001790585*T*2-3.98587E-07*T*3-12011*T*pow(T,1)
                       }
                       else if (T >= 1234.93 && T <= 3000) {
                               val = -15095.252+190.266404*T-33.472*T*log(T)+1.411773E+29*T*pow(T,1)
                       }
                       return val;
               }
               static double G_FCC_A1_BI_VA_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T < 544.55) {
                               val = +2082.224+115.918925*T-28.4096529*T*log(T)+.012338888*T*2-8.381598E-06*T*3
                       }
                       else if (T >= 544.55 && T < 800) {
                               val = +40108.022-406.150351*T+51.8556592*T*log(T)-.075311163*T*2+1.3499885E-05*T*3-3616168*T*pow(T,1)+1.66145E+25*T*pow(T,2)
                       }
                       else if (T >= 800 && T < 1200) {
                               val = -1145.664+170.048971*T-35.9824*T*log(T)+.0074266*T*2-1.046E-06*T*3+1.66145E+25*T*pow(T,1)
                       }
                       else if (T >= 1200 && T <= 3000) {
                               val = +2318.688+112.27144*T-27.196*T*log(T)+1.66145E+25*T*pow(T,1)
                       }
                       return val;
               }
               static double G_FCC_A1_SN_VA_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T < 505.08) {
                               val = -345.135+56.983315*T-15.961*T*log(T)-.0188702*T*2+3.121167E-06*T*3-61960*T*pow(T,1)
                       }
                       else if (T >= 505.08 && T < 800) {
                               val = +8034.724-4.454731*T-8.2590486*T*log(T)-.016814429*T*2+2.623131E-06*T*3-1081244*T*pow(T,1)-1.2307E+25*T*pow(T,2)
                       }
                       else if (T >= 800 && T <= 3000) {
                               val = -2746.959+130.53688*T-28.4512*T*log(T)-1.2307E+25*T*pow(T,1)
                       }
                       return val;
               }
               static double G_FCC_A1_AG_BI_VA_0 (double T) {
                       double val = 0.0;
                       if (T < 270 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 270 && T <= 3000) {
                               val = +25077.78-12.05475*T
                       }
                       return val;
               }
               static double G_FCC_A1_AG_BI_SN_VA_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = +32000
                       }
                       return val;
               }
               static double G_FCC_A1_AG_SN_VA_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = +745.45+11.498027*T
                       }
                       return val;
               }
               static double G_FCC_A1_AG_SN_VA_1 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = -36541.5
                       }
                       return val;
               }
               static double G_FCC_A1_BI_SN_VA_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = +2000
                       }
                       return val;
               }
               //---------------------------------------------------------------------
               //Gibbs Energy
               //---------------------------------------------------------------------
               static double G_FCC_A1(pf::ConNode& x, double T, double P) {
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_FCC_A1_AG_VA_0(T)*xAG+G_FCC_A1_BI_VA_0(T)*xBI+G_FCC_A1_SN_VA_0(T)*xSN+G_FCC_A1_AG_BI_VA_0(T)*xAG*xBI+G_FCC_A1_AG_BI_SN_VA_0(T)*xAG*xBI*xSN+G_FCC_A1_AG_SN_VA_0(T)*xAG*xSN+G_FCC_A1_AG_SN_VA_1(T)*(xAG-xSN)*xAG*xSN+G_FCC_A1_BI_SN_VA_0(T)*xBI*xSN+R*T*(xAG*log(xAG)+xBI*log(xBI)+xSN*log(xSN))
                       return val;
               }
               //---------------------------------------------------------------------
               //A first order partial derivatives
               //---------------------------------------------------------------------
               static double dG_FCC_A1_d_AG(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_FCC_A1_AG_VA_0(T)*xAG+G_FCC_A1_BI_VA_0(T)*xBI+G_FCC_A1_SN_VA_0(T)*xSN+G_FCC_A1_AG_BI_VA_0(T)*xAG*xBI+G_FCC_A1_AG_BI_SN_VA_0(T)*xAG*xBI*xSN+G_FCC_A1_AG_SN_VA_0(T)*xAG*xSN+G_FCC_A1_AG_SN_VA_1(T)*(xAG-xSN)*xAG*xSN+G_FCC_A1_BI_SN_VA_0(T)*xBI*xSN+G_FCC_A1_AG_VA_0(T)*1+G_FCC_A1_AG_BI_VA_0(T)*xAG*xBI+G_FCC_A1_AG_BI_SN_VA_0(T)*xAG*xBI*xSN+G_FCC_A1_AG_SN_VA_0(T)*xAG*xSN+R*T*(1+log(xAG))
                       return val;
               } 
               static double dG_FCC_A1_d_BI(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_FCC_A1_AG_VA_0(T)*xAG+G_FCC_A1_BI_VA_0(T)*xBI+G_FCC_A1_SN_VA_0(T)*xSN+G_FCC_A1_AG_BI_VA_0(T)*xAG*xBI+G_FCC_A1_AG_BI_SN_VA_0(T)*xAG*xBI*xSN+G_FCC_A1_AG_SN_VA_0(T)*xAG*xSN+G_FCC_A1_AG_SN_VA_1(T)*(xAG-xSN)*xAG*xSN+G_FCC_A1_BI_SN_VA_0(T)*xBI*xSN+G_FCC_A1_AG_VA_0(T)*1+G_FCC_A1_AG_BI_VA_0(T)*xAG*xBI+G_FCC_A1_AG_BI_SN_VA_0(T)*xAG*xBI*xSN+G_FCC_A1_AG_SN_VA_0(T)*xAG*xSNG_FCC_A1_BI_VA_0(T)*1+G_FCC_A1_AG_BI_VA_0(T)*xAG*xBI+G_FCC_A1_AG_BI_SN_VA_0(T)*xAG*xBI*xSN+G_FCC_A1_BI_SN_VA_0(T)*xBI*xSN+R*T*(1+log(xBI))
                       return val;
               } 
               static double dG_FCC_A1_d_SN(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_FCC_A1_AG_VA_0(T)*xAG+G_FCC_A1_BI_VA_0(T)*xBI+G_FCC_A1_SN_VA_0(T)*xSN+G_FCC_A1_AG_BI_VA_0(T)*xAG*xBI+G_FCC_A1_AG_BI_SN_VA_0(T)*xAG*xBI*xSN+G_FCC_A1_AG_SN_VA_0(T)*xAG*xSN+G_FCC_A1_AG_SN_VA_1(T)*(xAG-xSN)*xAG*xSN+G_FCC_A1_BI_SN_VA_0(T)*xBI*xSN+G_FCC_A1_AG_VA_0(T)*1+G_FCC_A1_AG_BI_VA_0(T)*xAG*xBI+G_FCC_A1_AG_BI_SN_VA_0(T)*xAG*xBI*xSN+G_FCC_A1_AG_SN_VA_0(T)*xAG*xSNG_FCC_A1_BI_VA_0(T)*1+G_FCC_A1_AG_BI_VA_0(T)*xAG*xBI+G_FCC_A1_AG_BI_SN_VA_0(T)*xAG*xBI*xSN+G_FCC_A1_BI_SN_VA_0(T)*xBI*xSNG_FCC_A1_SN_VA_0(T)*1+G_FCC_A1_AG_BI_SN_VA_0(T)*xAG*xBI*xSN+G_FCC_A1_AG_SN_VA_0(T)*xAG*xSN+G_FCC_A1_BI_SN_VA_0(T)*xBI*xSN+R*T*(1+log(xSN))
                       return val;
               } 
               //---------------------------------------------------------------------
               //A Second order partial derivatives
               //---------------------------------------------------------------------
               static double dG_FCC_A1_dAG%dAG%(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_FCC_A1_dAG%dBI(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_FCC_A1_dAG%dSN(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_FCC_A1_dBIdAG%(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_FCC_A1_dBIdBI(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_FCC_A1_dBIdSN(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_FCC_A1_dSNdAG%(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_FCC_A1_dSNdBI(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_FCC_A1_dSNdSN(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 

               /**********************************************************************
               PHASE HCP_A3
               **********************************************************************/
               static double G_HCP_A3_AG_VA_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T < 1234.93) {
                               val = -6909.512+118.502013*T-23.8463314*T*log(T)-.001790585*T*2-3.98587E-07*T*3-12011*T*pow(T,1)
                       }
                       else if (T >= 1234.93 && T <= 3000) {
                               val = -14795.252+190.566404*T-33.472*T*log(T)+1.411773E+29*T*pow(T,1)
                       }
                       return val;
               }
               static double G_HCP_A3_BI_VA_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T < 544.55) {
                               val = +2082.224+116.618925*T-28.4096529*T*log(T)+.012338888*T*2-8.381598E-06*T*3
                       }
                       else if (T >= 544.55 && T < 800) {
                               val = +40108.022-405.450351*T+51.8556592*T*log(T)-.075311163*T*2+1.3499885E-05*T*3-3616168*T*pow(T,1)+1.66145E+25*T*pow(T,2)
                       }
                       else if (T >= 800 && T < 1200) {
                               val = -1145.664+170.748971*T-35.9824*T*log(T)+.0074266*T*2-1.046E-06*T*3+1.66145E+25*T*pow(T,1)
                       }
                       else if (T >= 1200 && T <= 3000) {
                               val = +2318.688+112.97144*T-27.196*T*log(T)+1.66145E+25*T*pow(T,1)
                       }
                       return val;
               }
               static double G_HCP_A3_SN_VA_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T < 505.08) {
                               val = -1955.135+57.797315*T-15.961*T*log(T)-.0188702*T*2+3.121167E-06*T*3-61960*T*pow(T,1)
                       }
                       else if (T >= 505.08 && T < 800) {
                               val = +6424.724-3.640731*T-8.2590486*T*log(T)-.016814429*T*2+2.623131E-06*T*3-1081244*T*pow(T,1)-1.2307E+25*T*pow(T,2)
                       }
                       else if (T >= 800 && T <= 3000) {
                               val = -4356.959+131.35088*T-28.4512*T*log(T)-1.2307E+25*T*pow(T,1)
                       }
                       return val;
               }
               static double G_HCP_A3_AG_BI_VA_0 (double T) {
                       double val = 0.0;
                       if (T < 270 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 270 && T <= 3000) {
                               val = +25077.78-12.05475*T
                       }
                       return val;
               }
               static double G_HCP_A3_AG_BI_SN_VA_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = +10000
                       }
                       return val;
               }
               static double G_HCP_A3_AG_SN_VA_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = +1046.1+10.23693*T
                       }
                       return val;
               }
               static double G_HCP_A3_AG_SN_VA_1 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = -40505.5
                       }
                       return val;
               }
               static double G_HCP_A3_BI_SN_VA_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = +2000
                       }
                       return val;
               }
               //---------------------------------------------------------------------
               //Gibbs Energy
               //---------------------------------------------------------------------
               static double G_HCP_A3(pf::ConNode& x, double T, double P) {
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_HCP_A3_AG_VA_0(T)*xAG+G_HCP_A3_BI_VA_0(T)*xBI+G_HCP_A3_SN_VA_0(T)*xSN+G_HCP_A3_AG_BI_VA_0(T)*xAG*xBI+G_HCP_A3_AG_BI_SN_VA_0(T)*xAG*xBI*xSN+G_HCP_A3_AG_SN_VA_0(T)*xAG*xSN+G_HCP_A3_AG_SN_VA_1(T)*(xAG-xSN)*xAG*xSN+G_HCP_A3_BI_SN_VA_0(T)*xBI*xSN+R*T*(xAG*log(xAG)+xBI*log(xBI)+xSN*log(xSN))
                       return val;
               }
               //---------------------------------------------------------------------
               //A first order partial derivatives
               //---------------------------------------------------------------------
               static double dG_HCP_A3_d_AG(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_HCP_A3_AG_VA_0(T)*xAG+G_HCP_A3_BI_VA_0(T)*xBI+G_HCP_A3_SN_VA_0(T)*xSN+G_HCP_A3_AG_BI_VA_0(T)*xAG*xBI+G_HCP_A3_AG_BI_SN_VA_0(T)*xAG*xBI*xSN+G_HCP_A3_AG_SN_VA_0(T)*xAG*xSN+G_HCP_A3_AG_SN_VA_1(T)*(xAG-xSN)*xAG*xSN+G_HCP_A3_BI_SN_VA_0(T)*xBI*xSN+G_HCP_A3_AG_VA_0(T)*1+G_HCP_A3_AG_BI_VA_0(T)*xAG*xBI+G_HCP_A3_AG_BI_SN_VA_0(T)*xAG*xBI*xSN+G_HCP_A3_AG_SN_VA_0(T)*xAG*xSN+R*T*(1+log(xAG))
                       return val;
               } 
               static double dG_HCP_A3_d_BI(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_HCP_A3_AG_VA_0(T)*xAG+G_HCP_A3_BI_VA_0(T)*xBI+G_HCP_A3_SN_VA_0(T)*xSN+G_HCP_A3_AG_BI_VA_0(T)*xAG*xBI+G_HCP_A3_AG_BI_SN_VA_0(T)*xAG*xBI*xSN+G_HCP_A3_AG_SN_VA_0(T)*xAG*xSN+G_HCP_A3_AG_SN_VA_1(T)*(xAG-xSN)*xAG*xSN+G_HCP_A3_BI_SN_VA_0(T)*xBI*xSN+G_HCP_A3_AG_VA_0(T)*1+G_HCP_A3_AG_BI_VA_0(T)*xAG*xBI+G_HCP_A3_AG_BI_SN_VA_0(T)*xAG*xBI*xSN+G_HCP_A3_AG_SN_VA_0(T)*xAG*xSNG_HCP_A3_BI_VA_0(T)*1+G_HCP_A3_AG_BI_VA_0(T)*xAG*xBI+G_HCP_A3_AG_BI_SN_VA_0(T)*xAG*xBI*xSN+G_HCP_A3_BI_SN_VA_0(T)*xBI*xSN+R*T*(1+log(xBI))
                       return val;
               } 
               static double dG_HCP_A3_d_SN(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_HCP_A3_AG_VA_0(T)*xAG+G_HCP_A3_BI_VA_0(T)*xBI+G_HCP_A3_SN_VA_0(T)*xSN+G_HCP_A3_AG_BI_VA_0(T)*xAG*xBI+G_HCP_A3_AG_BI_SN_VA_0(T)*xAG*xBI*xSN+G_HCP_A3_AG_SN_VA_0(T)*xAG*xSN+G_HCP_A3_AG_SN_VA_1(T)*(xAG-xSN)*xAG*xSN+G_HCP_A3_BI_SN_VA_0(T)*xBI*xSN+G_HCP_A3_AG_VA_0(T)*1+G_HCP_A3_AG_BI_VA_0(T)*xAG*xBI+G_HCP_A3_AG_BI_SN_VA_0(T)*xAG*xBI*xSN+G_HCP_A3_AG_SN_VA_0(T)*xAG*xSNG_HCP_A3_BI_VA_0(T)*1+G_HCP_A3_AG_BI_VA_0(T)*xAG*xBI+G_HCP_A3_AG_BI_SN_VA_0(T)*xAG*xBI*xSN+G_HCP_A3_BI_SN_VA_0(T)*xBI*xSNG_HCP_A3_SN_VA_0(T)*1+G_HCP_A3_AG_BI_SN_VA_0(T)*xAG*xBI*xSN+G_HCP_A3_AG_SN_VA_0(T)*xAG*xSN+G_HCP_A3_BI_SN_VA_0(T)*xBI*xSN+R*T*(1+log(xSN))
                       return val;
               } 
               //---------------------------------------------------------------------
               //A Second order partial derivatives
               //---------------------------------------------------------------------
               static double dG_HCP_A3_dAGdAG(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_HCP_A3_dAGdBI(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_HCP_A3_dAGdSN(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_HCP_A3_dBIdAG(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_HCP_A3_dBIdBI(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_HCP_A3_dBIdSN(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_HCP_A3_dSNdAG(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_HCP_A3_dSNdBI(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_HCP_A3_dSNdSN(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 

               /**********************************************************************
               PHASE HCP_ZN
               **********************************************************************/
               static double G_HCP_ZN_AG_VA_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T < 1234.93) {
                               val = -6809.512+118.502013*T-23.8463314*T*log(T)-.001790585*T*2-3.98587E-07*T*3-12011*T*pow(T,1)
                       }
                       else if (T >= 1234.93 && T <= 3000) {
                               val = -14695.252+190.566404*T-33.472*T*log(T)+1.411773E+29*T*pow(T,1)
                       }
                       return val;
               }
               static double G_HCP_ZN_BI_VA_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 3000) {
                               val = +9901-11.8*T+ghser::GHSERBI(T)
                       }
                       return val;
               }
               static double G_HCP_ZN_SN_VA_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T < 505.08) {
                               val = -1855.135+57.797315*T-15.961*T*log(T)-.0188702*T*2+3.121167E-06*T*3-61960*T*pow(T,1)
                       }
                       else if (T >= 505.08 && T < 800) {
                               val = +6524.724-3.640731*T-8.2590486*T*log(T)-.016814429*T*2+2.623131E-06*T*3-1081244*T*pow(T,1)-1.2307E+25*T*pow(T,2)
                       }
                       else if (T >= 800 && T <= 3000) {
                               val = -4256.959+131.35088*T-28.4512*T*log(T)-1.2307E+25*T*pow(T,1)
                       }
                       return val;
               }
               static double G_HCP_ZN_AG_BI_VA_0 (double T) {
                       double val = 0.0;
                       if (T < 270 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 270 && T <= 3000) {
                               val = +25077.78-12.05475*T
                       }
                       return val;
               }
               static double G_HCP_ZN_AG_SN_VA_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = +10000
                       }
                       return val;
               }
               static double G_HCP_ZN_BI_SN_VA_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = +2000
                       }
                       return val;
               }
               //---------------------------------------------------------------------
               //Gibbs Energy
               //---------------------------------------------------------------------
               static double G_HCP_ZN(pf::ConNode& x, double T, double P) {
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_HCP_ZN_AG_VA_0(T)*xAG+G_HCP_ZN_BI_VA_0(T)*xBI+G_HCP_ZN_SN_VA_0(T)*xSN+G_HCP_ZN_AG_BI_VA_0(T)*xAG*xBI+G_HCP_ZN_AG_SN_VA_0(T)*xAG*xSN+G_HCP_ZN_BI_SN_VA_0(T)*xBI*xSN+R*T*(xAG*log(xAG)+xBI*log(xBI)+xSN*log(xSN))
                       return val;
               }
               //---------------------------------------------------------------------
               //A first order partial derivatives
               //---------------------------------------------------------------------
               static double dG_HCP_ZN_d_AG(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_HCP_ZN_AG_VA_0(T)*xAG+G_HCP_ZN_BI_VA_0(T)*xBI+G_HCP_ZN_SN_VA_0(T)*xSN+G_HCP_ZN_AG_BI_VA_0(T)*xAG*xBI+G_HCP_ZN_AG_SN_VA_0(T)*xAG*xSN+G_HCP_ZN_BI_SN_VA_0(T)*xBI*xSN+G_HCP_ZN_AG_VA_0(T)*1+G_HCP_ZN_AG_BI_VA_0(T)*xAG*xBI+G_HCP_ZN_AG_SN_VA_0(T)*xAG*xSN+R*T*(1+log(xAG))
                       return val;
               } 
               static double dG_HCP_ZN_d_BI(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_HCP_ZN_AG_VA_0(T)*xAG+G_HCP_ZN_BI_VA_0(T)*xBI+G_HCP_ZN_SN_VA_0(T)*xSN+G_HCP_ZN_AG_BI_VA_0(T)*xAG*xBI+G_HCP_ZN_AG_SN_VA_0(T)*xAG*xSN+G_HCP_ZN_BI_SN_VA_0(T)*xBI*xSN+G_HCP_ZN_AG_VA_0(T)*1+G_HCP_ZN_AG_BI_VA_0(T)*xAG*xBI+G_HCP_ZN_AG_SN_VA_0(T)*xAG*xSNG_HCP_ZN_BI_VA_0(T)*1+G_HCP_ZN_AG_BI_VA_0(T)*xAG*xBI+G_HCP_ZN_BI_SN_VA_0(T)*xBI*xSN+R*T*(1+log(xBI))
                       return val;
               } 
               static double dG_HCP_ZN_d_SN(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_HCP_ZN_AG_VA_0(T)*xAG+G_HCP_ZN_BI_VA_0(T)*xBI+G_HCP_ZN_SN_VA_0(T)*xSN+G_HCP_ZN_AG_BI_VA_0(T)*xAG*xBI+G_HCP_ZN_AG_SN_VA_0(T)*xAG*xSN+G_HCP_ZN_BI_SN_VA_0(T)*xBI*xSN+G_HCP_ZN_AG_VA_0(T)*1+G_HCP_ZN_AG_BI_VA_0(T)*xAG*xBI+G_HCP_ZN_AG_SN_VA_0(T)*xAG*xSNG_HCP_ZN_BI_VA_0(T)*1+G_HCP_ZN_AG_BI_VA_0(T)*xAG*xBI+G_HCP_ZN_BI_SN_VA_0(T)*xBI*xSNG_HCP_ZN_SN_VA_0(T)*1+G_HCP_ZN_AG_SN_VA_0(T)*xAG*xSN+G_HCP_ZN_BI_SN_VA_0(T)*xBI*xSN+R*T*(1+log(xSN))
                       return val;
               } 
               //---------------------------------------------------------------------
               //A Second order partial derivatives
               //---------------------------------------------------------------------
               static double dG_HCP_ZN_dAGdAG(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_HCP_ZN_dAGdBI(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_HCP_ZN_dAGdSN(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_HCP_ZN_dBIdAG(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_HCP_ZN_dBIdBI(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_HCP_ZN_dBIdSN(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_HCP_ZN_dSNdAG(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_HCP_ZN_dSNdBI(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_HCP_ZN_dSNdSN(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 

               /**********************************************************************
               PHASE INSN_GAMMA
               **********************************************************************/
               static double G_INSN_GAMMA_SN_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 3000) {
                               val = +625.49-1.13503*T+ghser::GHSERSN(T)
                       }
                       return val;
               }
               //---------------------------------------------------------------------
               //Gibbs Energy
               //---------------------------------------------------------------------
               static double G_INSN_GAMMA(pf::ConNode& x, double T, double P) {
                       double xSN = x[SN].value;
                       double val = G_INSN_GAMMA_SN_0(T)*xSN+R*T*(xSN*log(xSN))
                       return val;
               }
               //---------------------------------------------------------------------
               //A first order partial derivatives
               //---------------------------------------------------------------------
               static double dG_INSN_GAMMA_d_SN(pf::ConNode& x, double T, double P) { 
                       double xSN = x[SN].value;
                       double val = G_INSN_GAMMA_SN_0(T)*xSN+G_INSN_GAMMA_SN_0(T)*1+R*T*(1+log(xSN))
                       return val;
               } 
               //---------------------------------------------------------------------
               //A Second order partial derivatives
               //---------------------------------------------------------------------
               static double dG_INSN_GAMMA_dSNdSN(pf::ConNode& x, double T, double P) { 
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 

               /**********************************************************************
               PHASE LIQUID
               **********************************************************************/
               static double G_LIQUID_AG_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T < 1234.93) {
                               val = +3815.564+109.310993*T-23.8463314*T*log(T)-.001790585*T*2-3.98587E-07*T*3-12011*T*pow(T,1)-1.033905E-20*T*7
                       }
                       else if (T >= 1234.93 && T <= 3000) {
                               val = -3587.111+180.964656*T-33.472*T*log(T)
                       }
                       return val;
               }
               static double G_LIQUID_BI_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T < 544.55) {
                               val = +3428.29+107.782416*T-28.4096529*T*log(T)+.012338888*T*2-8.381598E-06*T*3-5.9549E-19*T*7
                       }
                       else if (T >= 544.55 && T < 800) {
                               val = +41544.282-414.460769*T+51.8556592*T*log(T)-.075311163*T*2+1.3499885E-05*T*3-3616168*T*pow(T,1)
                       }
                       else if (T >= 800 && T < 1200) {
                               val = +290.595+161.738553*T-35.9824*T*log(T)+.0074266*T*2-1.046E-06*T*3
                       }
                       else if (T >= 1200 && T <= 3000) {
                               val = +3754.947+103.961021*T-27.196*T*log(T)
                       }
                       return val;
               }
               static double G_LIQUID_SN_0 (double T) {
                       double val = 0.0;
                       if (T < 100 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 100 && T < 250) {
                               val = -855.425+108.677684*T-25.858*T*log(T)+5.1185E-04*T*2-3.192767E-06*T*3+18440*T*pow(T,1)+1.47031E-18*T*7
                       }
                       else if (T >= 250 && T < 505.08) {
                               val = +1247.957+51.355548*T-15.961*T*log(T)-.0188702*T*2+3.121167E-06*T*3-61960*T*pow(T,1)+1.47031E-18*T*7
                       }
                       else if (T >= 505.08 && T < 800) {
                               val = +9496.31-9.809114*T-8.2590486*T*log(T)-.016814429*T*2+2.623131E-06*T*3-1081244*T*pow(T,1)
                       }
                       else if (T >= 800 && T <= 3000) {
                               val = -1285.372+125.182498*T-28.4512*T*log(T)
                       }
                       return val;
               }
               static double G_LIQUID_AG_BI_0 (double T) {
                       double val = 0.0;
                       if (T < 270 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 270 && T <= 3000) {
                               val = +3340.81+39.16749*T-5.969876*T*log(T)
                       }
                       return val;
               }
               static double G_LIQUID_AG_BI_1 (double T) {
                       double val = 0.0;
                       if (T < 270 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 270 && T <= 3000) {
                               val = -5485.45-1.07133*T
                       }
                       return val;
               }
               static double G_LIQUID_AG_BI_2 (double T) {
                       double val = 0.0;
                       if (T < 270 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 270 && T <= 3000) {
                               val = -3055.34+1.77449*T
                       }
                       return val;
               }
               static double G_LIQUID_AG_BI_SN_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 3000) {
                               val = +7183.67+63.4075*T
                       }
                       return val;
               }
               static double G_LIQUID_AG_BI_SN_1 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 3000) {
                               val = +16258.99-8.978544*T
                       }
                       return val;
               }
               static double G_LIQUID_AG_BI_SN_2 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 3000) {
                               val = -1059.71-22*T
                       }
                       return val;
               }
               static double G_LIQUID_AG_SN_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = -3177.49-10.16124*T+.380505*T*log(T)
                       }
                       return val;
               }
               static double G_LIQUID_AG_SN_1 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = -16782.28+2.06521*T+.437477*T*log(T)
                       }
                       return val;
               }
               static double G_LIQUID_AG_SN_2 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = +3190.34-107.09456*T+13.954838*T*log(T)
                       }
                       return val;
               }
               static double G_LIQUID_BI_SN_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 3000) {
                               val = +500+1.5*T
                       }
                       return val;
               }
               static double G_LIQUID_BI_SN_1 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 3000) {
                               val = -100-.135*T
                       }
                       return val;
               }
               //---------------------------------------------------------------------
               //Gibbs Energy
               //---------------------------------------------------------------------
               static double G_LIQUID(pf::ConNode& x, double T, double P) {
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_LIQUID_AG_0(T)*xAG+G_LIQUID_BI_0(T)*xBI+G_LIQUID_SN_0(T)*xSN+G_LIQUID_AG_BI_0(T)*xAG*xBI+G_LIQUID_AG_BI_1(T)*(xAG-xBI)*xAG*xBI+G_LIQUID_AG_BI_2(T)*(xAG-xBI)*xAG*xBI*(xAG-xBI)*xAG*xBI+G_LIQUID_AG_BI_SN_0(T)*xAG*xBI*xSN+G_LIQUID_AG_BI_SN_1(T)*(xAG-xBI-xSN)*xAG*xBI*xSN+G_LIQUID_AG_BI_SN_2(T)*(xAG-xBI-xSN)*xAG*xBI*xSN*(xAG-xBI-xSN)*xAG*xBI*xSN+G_LIQUID_AG_SN_0(T)*xAG*xSN+G_LIQUID_AG_SN_1(T)*(xAG-xSN)*xAG*xSN+G_LIQUID_AG_SN_2(T)*(xAG-xSN)*xAG*xSN*(xAG-xSN)*xAG*xSN+G_LIQUID_BI_SN_0(T)*xBI*xSN+G_LIQUID_BI_SN_1(T)*(xBI-xSN)*xBI*xSN+R*T*(xAG*log(xAG)+xBI*log(xBI)+xSN*log(xSN))
                       return val;
               }
               //---------------------------------------------------------------------
               //A first order partial derivatives
               //---------------------------------------------------------------------
               static double dG_LIQUID_d_AG(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_LIQUID_AG_0(T)*xAG+G_LIQUID_BI_0(T)*xBI+G_LIQUID_SN_0(T)*xSN+G_LIQUID_AG_BI_0(T)*xAG*xBI+G_LIQUID_AG_BI_1(T)*(xAG-xBI)*xAG*xBI+G_LIQUID_AG_BI_2(T)*(xAG-xBI)*xAG*xBI+G_LIQUID_AG_BI_2(T)*(xAG-xBI)*xAG*xBI*(xAG-xBI)*xAG*xBI+G_LIQUID_AG_BI_SN_0(T)*xAG*xBI*xSN+G_LIQUID_AG_BI_SN_1(T)*(xAG-xBI-xSN)*xAG*xBI*xSN+G_LIQUID_AG_BI_SN_2(T)*(xAG-xBI-xSN)*xAG*xBI*xSN+G_LIQUID_AG_BI_SN_2(T)*(xAG-xBI-xSN)*xAG*xBI*xSN*(xAG-xBI-xSN)*xAG*xBI*xSN+G_LIQUID_AG_SN_0(T)*xAG*xSN+G_LIQUID_AG_SN_1(T)*(xAG-xSN)*xAG*xSN+G_LIQUID_AG_SN_2(T)*(xAG-xSN)*xAG*xSN+G_LIQUID_AG_SN_2(T)*(xAG-xSN)*xAG*xSN*(xAG-xSN)*xAG*xSN+G_LIQUID_BI_SN_0(T)*xBI*xSN+G_LIQUID_BI_SN_1(T)*(xBI-xSN)*xBI*xSN+G_LIQUID_AG_0(T)*1+G_LIQUID_AG_BI_0(T)*xAG*xBI+G_LIQUID_AG_BI_2(T)*(2*xAG-xBI)*xAG*xBI*+G_LIQUID_AG_BI_SN_0(T)*xAG*xBI*xSN+G_LIQUID_AG_BI_SN_2(T)*(2*xAG-xBI-xSN)*xAG*xBI*xSN*+G_LIQUID_AG_SN_0(T)*xAG*xSN+G_LIQUID_AG_SN_2(T)*(2*xAG-xSN)*xAG*xSN*+R*T*(1+log(xAG))
                       return val;
               } 
               static double dG_LIQUID_d_BI(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_LIQUID_AG_0(T)*xAG+G_LIQUID_BI_0(T)*xBI+G_LIQUID_SN_0(T)*xSN+G_LIQUID_AG_BI_0(T)*xAG*xBI+G_LIQUID_AG_BI_1(T)*(xAG-xBI)*xAG*xBI+G_LIQUID_AG_BI_2(T)*(xAG-xBI)*xAG*xBI+G_LIQUID_AG_BI_2(T)*(xAG-xBI)*xAG*xBI*(xAG-xBI)*xAG*xBI+G_LIQUID_AG_BI_SN_0(T)*xAG*xBI*xSN+G_LIQUID_AG_BI_SN_1(T)*(xAG-xBI-xSN)*xAG*xBI*xSN+G_LIQUID_AG_BI_SN_2(T)*(xAG-xBI-xSN)*xAG*xBI*xSN+G_LIQUID_AG_BI_SN_2(T)*(xAG-xBI-xSN)*xAG*xBI*xSN*(xAG-xBI-xSN)*xAG*xBI*xSN+G_LIQUID_AG_SN_0(T)*xAG*xSN+G_LIQUID_AG_SN_1(T)*(xAG-xSN)*xAG*xSN+G_LIQUID_AG_SN_2(T)*(xAG-xSN)*xAG*xSN+G_LIQUID_AG_SN_2(T)*(xAG-xSN)*xAG*xSN*(xAG-xSN)*xAG*xSN+G_LIQUID_BI_SN_0(T)*xBI*xSN+G_LIQUID_BI_SN_1(T)*(xBI-xSN)*xBI*xSN+G_LIQUID_AG_0(T)*1+G_LIQUID_AG_BI_0(T)*xAG*xBI+G_LIQUID_AG_BI_2(T)*(2*xAG-xBI)*xAG*xBI*+G_LIQUID_AG_BI_SN_0(T)*xAG*xBI*xSN+G_LIQUID_AG_BI_SN_2(T)*(2*xAG-xBI-xSN)*xAG*xBI*xSN*+G_LIQUID_AG_SN_0(T)*xAG*xSN+G_LIQUID_AG_SN_2(T)*(2*xAG-xSN)*xAG*xSN*G_LIQUID_BI_0(T)*1+G_LIQUID_AG_BI_0(T)*xAG*xBI+G_LIQUID_AG_BI_2(T)*(xAG-2*xBI)*xAG*xBI*+G_LIQUID_AG_BI_SN_0(T)*xAG*xBI*xSN+G_LIQUID_AG_BI_SN_2(T)*(xAG-2*xBI-xSN)*xAG*xBI*xSN*+G_LIQUID_BI_SN_0(T)*xBI*xSN+R*T*(1+log(xBI))
                       return val;
               } 
               static double dG_LIQUID_d_SN(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_LIQUID_AG_0(T)*xAG+G_LIQUID_BI_0(T)*xBI+G_LIQUID_SN_0(T)*xSN+G_LIQUID_AG_BI_0(T)*xAG*xBI+G_LIQUID_AG_BI_1(T)*(xAG-xBI)*xAG*xBI+G_LIQUID_AG_BI_2(T)*(xAG-xBI)*xAG*xBI+G_LIQUID_AG_BI_2(T)*(xAG-xBI)*xAG*xBI*(xAG-xBI)*xAG*xBI+G_LIQUID_AG_BI_SN_0(T)*xAG*xBI*xSN+G_LIQUID_AG_BI_SN_1(T)*(xAG-xBI-xSN)*xAG*xBI*xSN+G_LIQUID_AG_BI_SN_2(T)*(xAG-xBI-xSN)*xAG*xBI*xSN+G_LIQUID_AG_BI_SN_2(T)*(xAG-xBI-xSN)*xAG*xBI*xSN*(xAG-xBI-xSN)*xAG*xBI*xSN+G_LIQUID_AG_SN_0(T)*xAG*xSN+G_LIQUID_AG_SN_1(T)*(xAG-xSN)*xAG*xSN+G_LIQUID_AG_SN_2(T)*(xAG-xSN)*xAG*xSN+G_LIQUID_AG_SN_2(T)*(xAG-xSN)*xAG*xSN*(xAG-xSN)*xAG*xSN+G_LIQUID_BI_SN_0(T)*xBI*xSN+G_LIQUID_BI_SN_1(T)*(xBI-xSN)*xBI*xSN+G_LIQUID_AG_0(T)*1+G_LIQUID_AG_BI_0(T)*xAG*xBI+G_LIQUID_AG_BI_2(T)*(2*xAG-xBI)*xAG*xBI*+G_LIQUID_AG_BI_SN_0(T)*xAG*xBI*xSN+G_LIQUID_AG_BI_SN_2(T)*(2*xAG-xBI-xSN)*xAG*xBI*xSN*+G_LIQUID_AG_SN_0(T)*xAG*xSN+G_LIQUID_AG_SN_2(T)*(2*xAG-xSN)*xAG*xSN*G_LIQUID_BI_0(T)*1+G_LIQUID_AG_BI_0(T)*xAG*xBI+G_LIQUID_AG_BI_2(T)*(xAG-2*xBI)*xAG*xBI*+G_LIQUID_AG_BI_SN_0(T)*xAG*xBI*xSN+G_LIQUID_AG_BI_SN_2(T)*(xAG-2*xBI-xSN)*xAG*xBI*xSN*+G_LIQUID_BI_SN_0(T)*xBI*xSNG_LIQUID_SN_0(T)*1+G_LIQUID_AG_BI_SN_0(T)*xAG*xBI*xSN+G_LIQUID_AG_BI_SN_2(T)*(xAG-xBI-2*xSN)*xAG*xBI*xSN*+G_LIQUID_AG_SN_0(T)*xAG*xSN+G_LIQUID_AG_SN_2(T)*(xAG-2*xSN)*xAG*xSN*+G_LIQUID_BI_SN_0(T)*xBI*xSN+R*T*(1+log(xSN))
                       return val;
               } 
               //---------------------------------------------------------------------
               //A Second order partial derivatives
               //---------------------------------------------------------------------
               static double dG_LIQUID_dAGdAG(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_LIQUID_dAGdBI(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_LIQUID_dAGdSN(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_LIQUID_dBIdAG(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_LIQUID_dBIdBI(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_LIQUID_dBIdSN(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_LIQUID_dSNdAG(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_LIQUID_dSNdBI(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_LIQUID_dSNdSN(pf::ConNode& x, double T, double P) { 
                       double xAG = x[AG].value;
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 

               /**********************************************************************
               PHASE PD20SN13
               **********************************************************************/
               static double G_PD20SN13_SN_SN_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 4000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 4000) {
                               val = +ghser::GHSERSN(T)#+5000
                       }
                       return val;
               }
               //---------------------------------------------------------------------
               //Gibbs Energy
               //---------------------------------------------------------------------
               static double G_PD20SN13(pf::SublatticeNode& y, double T, double P) {
                       double y1SN = y[_SN_][SN].value;
                       double y2SN = y[_SN_][SN].value;
                       double val = G_PD20SN13_SN_SN_0(T)*y1SN*y2SN+0.6*R*T*y1SN*log(y1SN)+0.4*R*T*y2SN*log(y2SN)
                       return val;
               }
               //---------------------------------------------------------------------
               //A first order partial derivatives
               //---------------------------------------------------------------------
               static double dG_PD20SN13_dSN1(pf::SublatticeNode& y, double T, double P) { 
                       double y1SN = y[_SN_][SN].value;
                       double y2SN = y[_SN_][SN].value;
                       double val = G_PD20SN13_SN_SN_0(T)*y2SN*1+1+log(y1SN)+0+0.6*R*T*(1+log(y1SN))+0.4*R*T*(0)
                       return val;
               } 
               static double dG_PD20SN13_dSN2(pf::SublatticeNode& y, double T, double P) { 
                       double y1SN = y[_SN_][SN].value;
                       double y2SN = y[_SN_][SN].value;
                       double val = G_PD20SN13_SN_SN_0(T)*y1SN*1+0+1+log(y2SN)+0.6*R*T*(0)+0.4*R*T*(1+log(y2SN))
                       return val;
               } 
               //---------------------------------------------------------------------
               //A Second order partial derivatives
               //---------------------------------------------------------------------
               static double dG_PD20SN13_dSNdSN((pf::SublatticeNode& y, double T, double P) { 
                       double y1SN = y[_SN_][SN].value;
                       double y2SN = y[_SN_][SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_PD20SN13_dSNdSN((pf::SublatticeNode& y, double T, double P) { 
                       double y1SN = y[_SN_][SN].value;
                       double y2SN = y[_SN_][SN].value;
                       double val = 0.0;
                       return val;
               } 

               /**********************************************************************
               PHASE PD3SN
               **********************************************************************/
               static double G_PD3SN_SN_SN_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = +ghser::GFCCSN(T)
                       }
                       return val;
               }
               //---------------------------------------------------------------------
               //Gibbs Energy
               //---------------------------------------------------------------------
               static double G_PD3SN(pf::SublatticeNode& y, double T, double P) {
                       double y1SN = y[_SN_][SN].value;
                       double y2SN = y[_SN_][SN].value;
                       double val = G_PD3SN_SN_SN_0(T)*y1SN*y2SN+0.75*R*T*y1SN*log(y1SN)+0.25*R*T*y2SN*log(y2SN)
                       return val;
               }
               //---------------------------------------------------------------------
               //A first order partial derivatives
               //---------------------------------------------------------------------
               static double dG_PD3SN_dSN1(pf::SublatticeNode& y, double T, double P) { 
                       double y1SN = y[_SN_][SN].value;
                       double y2SN = y[_SN_][SN].value;
                       double val = G_PD3SN_SN_SN_0(T)*y2SN*1+1+log(y1SN)+0+0.75*R*T*(1+log(y1SN))+0.25*R*T*(0)
                       return val;
               } 
               static double dG_PD3SN_dSN2(pf::SublatticeNode& y, double T, double P) { 
                       double y1SN = y[_SN_][SN].value;
                       double y2SN = y[_SN_][SN].value;
                       double val = G_PD3SN_SN_SN_0(T)*y1SN*1+0+1+log(y2SN)+0.75*R*T*(0)+0.25*R*T*(1+log(y2SN))
                       return val;
               } 
               //---------------------------------------------------------------------
               //A Second order partial derivatives
               //---------------------------------------------------------------------
               static double dG_PD3SN_dSNdSN((pf::SublatticeNode& y, double T, double P) { 
                       double y1SN = y[_SN_][SN].value;
                       double y2SN = y[_SN_][SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_PD3SN_dSNdSN((pf::SublatticeNode& y, double T, double P) { 
                       double y1SN = y[_SN_][SN].value;
                       double y2SN = y[_SN_][SN].value;
                       double val = 0.0;
                       return val;
               } 

               /**********************************************************************
               PHASE PDSN
               **********************************************************************/
               static double G_PDSN_VA_SN_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = +.5*ghser::GHSERSN(T)#+15000
                       }
                       return val;
               }
               //---------------------------------------------------------------------
               //Gibbs Energy
               //---------------------------------------------------------------------
               static double G_PDSN(pf::ConNode& x, double T, double P) {
                       double xSN = x[SN].value;
                       double val = G_PDSN_VA_SN_0(T)*xSN+R*T*(xSN*log(xSN))
                       return val;
               }
               //---------------------------------------------------------------------
               //A first order partial derivatives
               //---------------------------------------------------------------------
               static double dG_PDSN_d_SN(pf::ConNode& x, double T, double P) { 
                       double xSN = x[SN].value;
                       double val = G_PDSN_VA_SN_0(T)*xSN+G_PDSN_VA_SN_0(T)*1+R*T*(1+log(xSN))
                       return val;
               } 
               //---------------------------------------------------------------------
               //A Second order partial derivatives
               //---------------------------------------------------------------------
               static double dG_PDSN_dSNdSN(pf::ConNode& x, double T, double P) { 
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 

               /**********************************************************************
               PHASE PDSN2
               **********************************************************************/
               static double G_PDSN2_SN_SN_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = +ghser::GHSERSN(T)#+5000
                       }
                       return val;
               }
               //---------------------------------------------------------------------
               //Gibbs Energy
               //---------------------------------------------------------------------
               static double G_PDSN2(pf::SublatticeNode& y, double T, double P) {
                       double y1SN = y[_SN_][SN].value;
                       double y2SN = y[_SN_][SN].value;
                       double val = G_PDSN2_SN_SN_0(T)*y1SN*y2SN+0.333*R*T*y1SN*log(y1SN)+0.667*R*T*y2SN*log(y2SN)
                       return val;
               }
               //---------------------------------------------------------------------
               //A first order partial derivatives
               //---------------------------------------------------------------------
               static double dG_PDSN2_dSN1(pf::SublatticeNode& y, double T, double P) { 
                       double y1SN = y[_SN_][SN].value;
                       double y2SN = y[_SN_][SN].value;
                       double val = G_PDSN2_SN_SN_0(T)*y2SN*1+1+log(y1SN)+0+0.333*R*T*(1+log(y1SN))+0.667*R*T*(0)
                       return val;
               } 
               static double dG_PDSN2_dSN2(pf::SublatticeNode& y, double T, double P) { 
                       double y1SN = y[_SN_][SN].value;
                       double y2SN = y[_SN_][SN].value;
                       double val = G_PDSN2_SN_SN_0(T)*y1SN*1+0+1+log(y2SN)+0.333*R*T*(0)+0.667*R*T*(1+log(y2SN))
                       return val;
               } 
               //---------------------------------------------------------------------
               //A Second order partial derivatives
               //---------------------------------------------------------------------
               static double dG_PDSN2_dSNdSN((pf::SublatticeNode& y, double T, double P) { 
                       double y1SN = y[_SN_][SN].value;
                       double y2SN = y[_SN_][SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_PDSN2_dSNdSN((pf::SublatticeNode& y, double T, double P) { 
                       double y1SN = y[_SN_][SN].value;
                       double y2SN = y[_SN_][SN].value;
                       double val = 0.0;
                       return val;
               } 

               /**********************************************************************
               PHASE RHOMBO_A7
               **********************************************************************/
               static double G_RHOMBO_A7_BI_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T < 544.55) {
                               val = -7817.776+128.418925*T-28.4096529*T*log(T)+.012338888*T*2-8.381598E-06*T*3
                       }
                       else if (T >= 544.55 && T < 800) {
                               val = +30208.022-393.650351*T+51.8556592*T*log(T)-.075311163*T*2+1.3499885E-05*T*3-3616168*T*pow(T,1)+1.66145E+25*T*pow(T,2)
                       }
                       else if (T >= 800 && T < 1200) {
                               val = -11045.664+182.548971*T-35.9824*T*log(T)+.0074266*T*2-1.046E-06*T*3+1.66145E+25*T*pow(T,1)
                       }
                       else if (T >= 1200 && T <= 3000) {
                               val = -7581.312+124.77144*T-27.196*T*log(T)+1.66145E+25*T*pow(T,1)
                       }
                       return val;
               }
               static double G_RHOMBO_A7_SN_0 (double T) {
                       double val = 0.0;
                       if (T < 100 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 100 && T < 250) {
                               val = -5923.517+122.765451*T-25.858*T*log(T)+5.1185E-04*T*2-3.192767E-06*T*3+18440*T*pow(T,1)
                       }
                       else if (T >= 250 && T < 505.08) {
                               val = -3820.135+65.443315*T-15.961*T*log(T)-.0188702*T*2+3.121167E-06*T*3-61960*T*pow(T,1)
                       }
                       else if (T >= 505.08 && T < 800) {
                               val = +4559.724+4.005269*T-8.2590486*T*log(T)-.016814429*T*2+2.623131E-06*T*3-1081244*T*pow(T,1)-1.2307E+25*T*pow(T,2)
                       }
                       else if (T >= 800 && T <= 3000) {
                               val = -6221.959+138.99688*T-28.4512*T*log(T)-1.2307E+25*T*pow(T,1)
                       }
                       return val;
               }
               static double G_RHOMBO_A7_BI_SN_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 3000) {
                               val = +19720-22.6*T
                       }
                       return val;
               }
               static double G_RHOMBO_A7_BI_SN_1 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 3000) {
                               val = -5760+13.834*T
                       }
                       return val;
               }
               //---------------------------------------------------------------------
               //Gibbs Energy
               //---------------------------------------------------------------------
               static double G_RHOMBO_A7(pf::ConNode& x, double T, double P) {
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_RHOMBO_A7_BI_0(T)*xBI+G_RHOMBO_A7_SN_0(T)*xSN+G_RHOMBO_A7_BI_SN_0(T)*xBI*xSN+G_RHOMBO_A7_BI_SN_1(T)*(xBI-xSN)*xBI*xSN+R*T*(xBI*log(xBI)+xSN*log(xSN))
                       return val;
               }
               //---------------------------------------------------------------------
               //A first order partial derivatives
               //---------------------------------------------------------------------
               static double dG_RHOMBO_A7_d_BI(pf::ConNode& x, double T, double P) { 
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_RHOMBO_A7_BI_0(T)*xBI+G_RHOMBO_A7_SN_0(T)*xSN+G_RHOMBO_A7_BI_SN_0(T)*xBI*xSN+G_RHOMBO_A7_BI_SN_1(T)*(xBI-xSN)*xBI*xSN+G_RHOMBO_A7_BI_0(T)*1+G_RHOMBO_A7_BI_SN_0(T)*xBI*xSN+R*T*(1+log(xBI))
                       return val;
               } 
               static double dG_RHOMBO_A7_d_SN(pf::ConNode& x, double T, double P) { 
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_RHOMBO_A7_BI_0(T)*xBI+G_RHOMBO_A7_SN_0(T)*xSN+G_RHOMBO_A7_BI_SN_0(T)*xBI*xSN+G_RHOMBO_A7_BI_SN_1(T)*(xBI-xSN)*xBI*xSN+G_RHOMBO_A7_BI_0(T)*1+G_RHOMBO_A7_BI_SN_0(T)*xBI*xSNG_RHOMBO_A7_SN_0(T)*1+G_RHOMBO_A7_BI_SN_0(T)*xBI*xSN+R*T*(1+log(xSN))
                       return val;
               } 
               //---------------------------------------------------------------------
               //A Second order partial derivatives
               //---------------------------------------------------------------------
               static double dG_RHOMBO_A7_dBI%dBI%(pf::ConNode& x, double T, double P) { 
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_RHOMBO_A7_dBI%dSN(pf::ConNode& x, double T, double P) { 
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_RHOMBO_A7_dSNdBI%(pf::ConNode& x, double T, double P) { 
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_RHOMBO_A7_dSNdSN(pf::ConNode& x, double T, double P) { 
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 

               /**********************************************************************
               PHASE SBSN
               **********************************************************************/
               static double G_SBSN_BI_BI_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = +2*ghser::GHSERBI(T)#+53000
                       }
                       return val;
               }
               static double G_SBSN_SN_BI_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = +ghser::GHSERSN(T)#+ghser::GHSERBI(T)#+11680-12*T
                       }
                       return val;
               }
               static double G_SBSN_BI_SN_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = +ghser::GHSERBI(T)#+ghser::GHSERSN(T)#+11680-12*T
                       }
                       return val;
               }
               static double G_SBSN_SN_SN_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = +2*ghser::GHSERSN(T)#+7463.66
                       }
                       return val;
               }
               static double G_SBSN_BI_SN_BI_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = +0.0
                       }
                       return val;
               }
               static double G_SBSN_BI_BI_SN_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = +0.0
                       }
                       return val;
               }
               static double G_SBSN_SN_BI_SN_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = +0.0
                       }
                       return val;
               }
               static double G_SBSN_BI_SN_SN_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 6000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 6000) {
                               val = +0.0
                       }
                       return val;
               }
               //---------------------------------------------------------------------
               //Gibbs Energy
               //---------------------------------------------------------------------
               static double G_SBSN(pf::SublatticeNode& y, double T, double P) {
                       double y1BI = y[_BI_SN_][BI].value;
                       double y1SN = y[_BI_SN_][SN].value;
                       double y2BI = y[_BI_SN_][BI].value;
                       double y2SN = y[_BI_SN_][SN].value;
                       double val = G_SBSN_BI_BI_0(T)*y1BI*y2BI+G_SBSN_SN_BI_0(T)*y1SN*y2BI+G_SBSN_BI_SN_0(T)*y1BI*y2SN+G_SBSN_SN_SN_0(T)*y1SN*y2SN+G_SBSN_BI_SN_BI_0(T)*y1BI*y1SN*y2BI+G_SBSN_BI_BI_SN_0(T)*y1BI*y2BI*y2SN+G_SBSN_SN_BI_SN_0(T)*y1SN*y2BI*y2SN+G_SBSN_BI_SN_SN_0(T)*y1BI*y1SN*y2SN+0.5*R*T*(y1BI*log(y1BI)+y1SN*log(y1SN))+0.5*R*T*(y2BI*log(y2BI)+y2SN*log(y2SN))
                       return val;
               }
               //---------------------------------------------------------------------
               //A first order partial derivatives
               //---------------------------------------------------------------------
               static double dG_SBSN_dBI1(pf::SublatticeNode& y, double T, double P) { 
                       double y1BI = y[_BI_SN_][BI].value;
                       double y1SN = y[_BI_SN_][SN].value;
                       double y2BI = y[_BI_SN_][BI].value;
                       double y2SN = y[_BI_SN_][SN].value;
                       double val = G_SBSN_BI_BI_0(T)*y2BI*1+G_SBSN_BI_SN_0(T)*y2SN*1+G_SBSN_BI_SN_BI_0(T)*y1SN*y2BI*1+G_SBSN_BI_BI_SN_0(T)*y2BI*y2SN*1+G_SBSN_BI_SN_SN_0(T)*y1SN*y2SN*1+1+log(y1BI)+0+0.5*R*T*(1+log(y1BI))+0.5*R*T*(0)
                       return val;
               } 
               static double dG_SBSN_dSN1(pf::SublatticeNode& y, double T, double P) { 
                       double y1BI = y[_BI_SN_][BI].value;
                       double y1SN = y[_BI_SN_][SN].value;
                       double y2BI = y[_BI_SN_][BI].value;
                       double y2SN = y[_BI_SN_][SN].value;
                       double val = G_SBSN_SN_BI_0(T)*y2BI*1+G_SBSN_SN_SN_0(T)*y2SN*1+G_SBSN_BI_SN_BI_0(T)*y1BI*y2BI*1+G_SBSN_SN_BI_SN_0(T)*y2BI*y2SN*1+G_SBSN_BI_SN_SN_0(T)*y1BI*y2SN*1+1+log(y1SN)+0+0.5*R*T*(1+log(y1SN))+0.5*R*T*(0)
                       return val;
               } 
               static double dG_SBSN_dBI2(pf::SublatticeNode& y, double T, double P) { 
                       double y1BI = y[_BI_SN_][BI].value;
                       double y1SN = y[_BI_SN_][SN].value;
                       double y2BI = y[_BI_SN_][BI].value;
                       double y2SN = y[_BI_SN_][SN].value;
                       double val = G_SBSN_BI_BI_0(T)*y1BI*1+G_SBSN_SN_BI_0(T)*y1SN*1+G_SBSN_BI_SN_BI_0(T)*y1BI*y1SN*1+G_SBSN_BI_BI_SN_0(T)*y1BI*y2SN*1+G_SBSN_SN_BI_SN_0(T)*y1SN*y2SN*1+0+1+log(y2BI)+0.5*R*T*(0)+0.5*R*T*(1+log(y2BI))
                       return val;
               } 
               static double dG_SBSN_dSN2(pf::SublatticeNode& y, double T, double P) { 
                       double y1BI = y[_BI_SN_][BI].value;
                       double y1SN = y[_BI_SN_][SN].value;
                       double y2BI = y[_BI_SN_][BI].value;
                       double y2SN = y[_BI_SN_][SN].value;
                       double val = G_SBSN_BI_SN_0(T)*y1BI*1+G_SBSN_SN_SN_0(T)*y1SN*1+G_SBSN_BI_BI_SN_0(T)*y1BI*y2BI*1+G_SBSN_SN_BI_SN_0(T)*y1SN*y2BI*1+G_SBSN_BI_SN_SN_0(T)*y1BI*y1SN*1+0+1+log(y2SN)+0.5*R*T*(0)+0.5*R*T*(1+log(y2SN))
                       return val;
               } 
               //---------------------------------------------------------------------
               //A Second order partial derivatives
               //---------------------------------------------------------------------
               static double dG_SBSN_dBIdBI((pf::SublatticeNode& y, double T, double P) { 
                       double y1BI = y[_BI_SN_][BI].value;
                       double y1SN = y[_BI_SN_][SN].value;
                       double y2BI = y[_BI_SN_][BI].value;
                       double y2SN = y[_BI_SN_][SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_SBSN_dBIdSN((pf::SublatticeNode& y, double T, double P) { 
                       double y1BI = y[_BI_SN_][BI].value;
                       double y1SN = y[_BI_SN_][SN].value;
                       double y2BI = y[_BI_SN_][BI].value;
                       double y2SN = y[_BI_SN_][SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_SBSN_dSNdBI((pf::SublatticeNode& y, double T, double P) { 
                       double y1BI = y[_BI_SN_][BI].value;
                       double y1SN = y[_BI_SN_][SN].value;
                       double y2BI = y[_BI_SN_][BI].value;
                       double y2SN = y[_BI_SN_][SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_SBSN_dSNdSN((pf::SublatticeNode& y, double T, double P) { 
                       double y1BI = y[_BI_SN_][BI].value;
                       double y1SN = y[_BI_SN_][SN].value;
                       double y2BI = y[_BI_SN_][BI].value;
                       double y2SN = y[_BI_SN_][SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_SBSN_dBIdBI((pf::SublatticeNode& y, double T, double P) { 
                       double y1BI = y[_BI_SN_][BI].value;
                       double y1SN = y[_BI_SN_][SN].value;
                       double y2BI = y[_BI_SN_][BI].value;
                       double y2SN = y[_BI_SN_][SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_SBSN_dBIdSN((pf::SublatticeNode& y, double T, double P) { 
                       double y1BI = y[_BI_SN_][BI].value;
                       double y1SN = y[_BI_SN_][SN].value;
                       double y2BI = y[_BI_SN_][BI].value;
                       double y2SN = y[_BI_SN_][SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_SBSN_dSNdBI((pf::SublatticeNode& y, double T, double P) { 
                       double y1BI = y[_BI_SN_][BI].value;
                       double y1SN = y[_BI_SN_][SN].value;
                       double y2BI = y[_BI_SN_][BI].value;
                       double y2SN = y[_BI_SN_][SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_SBSN_dSNdSN((pf::SublatticeNode& y, double T, double P) { 
                       double y1BI = y[_BI_SN_][BI].value;
                       double y1SN = y[_BI_SN_][SN].value;
                       double y2BI = y[_BI_SN_][BI].value;
                       double y2SN = y[_BI_SN_][SN].value;
                       double val = 0.0;
                       return val;
               } 

               /**********************************************************************
               PHASE TETRAG_A6
               **********************************************************************/
               static double G_TETRAG_A6_BI_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T < 544.55) {
                               val = -3633.706+128.418925*T-28.4096529*T*log(T)+.012338888*T*2-8.381598E-06*T*3
                       }
                       else if (T >= 544.55 && T < 800) {
                               val = +34392.092-393.650351*T+51.8556592*T*log(T)-.075311163*T*2+1.3499885E-05*T*3-3616168*T*pow(T,1)+1.66145E+25*T*pow(T,2)
                       }
                       else if (T >= 800 && T < 1200) {
                               val = -6861.594+182.548971*T-35.9824*T*log(T)+.0074266*T*2-1.046E-06*T*3+1.66145E+25*T*pow(T,1)
                       }
                       else if (T >= 1200 && T <= 3000) {
                               val = -3397.242+124.77144*T-27.196*T*log(T)+1.66145E+25*T*pow(T,1)
                       }
                       return val;
               }
               static double G_TETRAG_A6_SN_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T < 505.08) {
                               val = -468.135+57.181195*T-15.961*T*log(T)-.0188702*T*2+3.121167E-06*T*3-61960*T*pow(T,1)
                       }
                       else if (T >= 505.08 && T < 800) {
                               val = +7911.724-4.256851*T-8.2590486*T*log(T)-.016814429*T*2+2.623131E-06*T*3-1081244*T*pow(T,1)-1.2307E+25*T*pow(T,2)
                       }
                       else if (T >= 800 && T <= 3000) {
                               val = -2869.959+130.73476*T-28.4512*T*log(T)-1.2307E+25*T*pow(T,1)
                       }
                       return val;
               }
               static double G_TETRAG_A6_BI_SN_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 4000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 4000) {
                               val = +4000
                       }
                       return val;
               }
               //---------------------------------------------------------------------
               //Gibbs Energy
               //---------------------------------------------------------------------
               static double G_TETRAG_A6(pf::ConNode& x, double T, double P) {
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_TETRAG_A6_BI_0(T)*xBI+G_TETRAG_A6_SN_0(T)*xSN+G_TETRAG_A6_BI_SN_0(T)*xBI*xSN+R*T*(xBI*log(xBI)+xSN*log(xSN))
                       return val;
               }
               //---------------------------------------------------------------------
               //A first order partial derivatives
               //---------------------------------------------------------------------
               static double dG_TETRAG_A6_d_BI(pf::ConNode& x, double T, double P) { 
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_TETRAG_A6_BI_0(T)*xBI+G_TETRAG_A6_SN_0(T)*xSN+G_TETRAG_A6_BI_SN_0(T)*xBI*xSN+G_TETRAG_A6_BI_0(T)*1+G_TETRAG_A6_BI_SN_0(T)*xBI*xSN+R*T*(1+log(xBI))
                       return val;
               } 
               static double dG_TETRAG_A6_d_SN(pf::ConNode& x, double T, double P) { 
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_TETRAG_A6_BI_0(T)*xBI+G_TETRAG_A6_SN_0(T)*xSN+G_TETRAG_A6_BI_SN_0(T)*xBI*xSN+G_TETRAG_A6_BI_0(T)*1+G_TETRAG_A6_BI_SN_0(T)*xBI*xSNG_TETRAG_A6_SN_0(T)*1+G_TETRAG_A6_BI_SN_0(T)*xBI*xSN+R*T*(1+log(xSN))
                       return val;
               } 
               //---------------------------------------------------------------------
               //A Second order partial derivatives
               //---------------------------------------------------------------------
               static double dG_TETRAG_A6_dBIdBI(pf::ConNode& x, double T, double P) { 
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_TETRAG_A6_dBIdSN(pf::ConNode& x, double T, double P) { 
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_TETRAG_A6_dSNdBI(pf::ConNode& x, double T, double P) { 
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_TETRAG_A6_dSNdSN(pf::ConNode& x, double T, double P) { 
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 

               /**********************************************************************
               PHASE TET_ALPHA1
               **********************************************************************/
               static double G_TET_ALPHA1_BI_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T < 544.55) {
                               val = -3583.776+128.418925*T-28.4096529*T*log(T)+.012338888*T*2-8.381598E-06*T*3
                       }
                       else if (T >= 544.55 && T < 800) {
                               val = +34442.022-393.650351*T+51.8556592*T*log(T)-.075311163*T*2+1.3499885E-05*T*3-3616168*T*pow(T,1)+1.66145E+25*T*pow(T,2)
                       }
                       else if (T >= 800 && T < 1200) {
                               val = -6811.664+182.548971*T-35.9824*T*log(T)+.0074266*T*2-1.046E-06*T*3+1.66145E+25*T*pow(T,1)
                       }
                       else if (T >= 1200 && T <= 3000) {
                               val = -3347.312+124.77144*T-27.196*T*log(T)+1.66145E+25*T*pow(T,1)
                       }
                       return val;
               }
               static double G_TET_ALPHA1_SN_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 3000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 3000) {
                               val = +5510-8.46*T+ghser::GHSERSN(T)
                       }
                       return val;
               }
               static double G_TET_ALPHA1_BI_SN_0 (double T) {
                       double val = 0.0;
                       if (T < 298.15 || T > 4000) {
                               printerror();
                       }
                       else if (T >= 298.15 && T <= 4000) {
                               val = +2000
                       }
                       return val;
               }
               //---------------------------------------------------------------------
               //Gibbs Energy
               //---------------------------------------------------------------------
               static double G_TET_ALPHA1(pf::ConNode& x, double T, double P) {
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_TET_ALPHA1_BI_0(T)*xBI+G_TET_ALPHA1_SN_0(T)*xSN+G_TET_ALPHA1_BI_SN_0(T)*xBI*xSN+R*T*(xBI*log(xBI)+xSN*log(xSN))
                       return val;
               }
               //---------------------------------------------------------------------
               //A first order partial derivatives
               //---------------------------------------------------------------------
               static double dG_TET_ALPHA1_d_BI(pf::ConNode& x, double T, double P) { 
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_TET_ALPHA1_BI_0(T)*xBI+G_TET_ALPHA1_SN_0(T)*xSN+G_TET_ALPHA1_BI_SN_0(T)*xBI*xSN+G_TET_ALPHA1_BI_0(T)*1+G_TET_ALPHA1_BI_SN_0(T)*xBI*xSN+R*T*(1+log(xBI))
                       return val;
               } 
               static double dG_TET_ALPHA1_d_SN(pf::ConNode& x, double T, double P) { 
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = G_TET_ALPHA1_BI_0(T)*xBI+G_TET_ALPHA1_SN_0(T)*xSN+G_TET_ALPHA1_BI_SN_0(T)*xBI*xSN+G_TET_ALPHA1_BI_0(T)*1+G_TET_ALPHA1_BI_SN_0(T)*xBI*xSNG_TET_ALPHA1_SN_0(T)*1+G_TET_ALPHA1_BI_SN_0(T)*xBI*xSN+R*T*(1+log(xSN))
                       return val;
               } 
               //---------------------------------------------------------------------
               //A Second order partial derivatives
               //---------------------------------------------------------------------
               static double dG_TET_ALPHA1_dBIdBI(pf::ConNode& x, double T, double P) { 
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_TET_ALPHA1_dBIdSN(pf::ConNode& x, double T, double P) { 
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_TET_ALPHA1_dSNdBI(pf::ConNode& x, double T, double P) { 
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
               static double dG_TET_ALPHA1_dSNdSN(pf::ConNode& x, double T, double P) { 
                       double xBI = x[BI].value;
                       double xSN = x[SN].value;
                       double val = 0.0;
                       return val;
               } 
       }
}